//=============================================================================
// Atcmaker - copies a precompiled ATTRIBUTE_TABLE (atc.p3d) for Simpsons Hit & Run.
//
//
// Usage:
//   1) Pipeline / simple use:
//        atcmaker atc.p3d
//      - Looks for a file named \"source_atc.p3d\" next to atcmaker.exe and
//        copies it to \"atc.p3d\" in the current directory.
//
//   2) Explicit source and destination:
//        atcmaker src_atc.p3d dest_atc.p3d
//
//   3) Option form (copy):
//        atcmaker -src path_to_precompiled_atc.p3d -out atc.p3d
//
//   4) Dump table to CSV:
//        atcmaker -dumpcsv table.csv
//           (uses source_atc.p3d next to atcmaker.exe)
//        or
//        atcmaker src_atc.p3d -dumpcsv table.csv
//        or
//        atcmaker -src src_atc.p3d -dumpcsv table.csv
//
//=============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <float.h>

static int copyFile(const char* src, const char* dst)
{
    FILE* in = fopen(src, "rb");
    if (!in)
    {
        fprintf(stderr, "atcmaker: cannot open source '%s'\n", src);
        return 1;
    }

    FILE* out = fopen(dst, "wb");
    if (!out)
    {
        fprintf(stderr, "atcmaker: cannot create '%s'\n", dst);
        fclose(in);
        return 1;
    }

    char buffer[64 * 1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), in)) > 0)
    {
        if (fwrite(buffer, 1, n, out) != n)
        {
            fprintf(stderr, "atcmaker: write error to '%s'\n", dst);
            fclose(in);
            fclose(out);
            return 1;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}

static void getDefaultSourcePath(char* out, size_t outSize)
{
    out[0] = '\0';
    char exePath[MAX_PATH];
    DWORD len = GetModuleFileNameA(NULL, exePath, MAX_PATH);
    if (len == 0 || len >= MAX_PATH)
    {
        return;
    }

    char* lastSlash = strrchr(exePath, '\\');
    if (!lastSlash)
    {
        return;
    }
    *(lastSlash + 1) = '\0';

    snprintf(out, outSize, "%ssource_atc.p3d", exePath);
}

static int readU16(FILE* f, unsigned short* v)
{
    int b0 = fgetc(f);
    int b1 = fgetc(f);
    if (b0 == EOF || b1 == EOF) return 0;
    *v = (unsigned short)((b0 & 0xFF) | ((b1 & 0xFF) << 8));
    return 1;
}

static int readU32(FILE* f, unsigned int* v)
{
    int b0 = fgetc(f);
    int b1 = fgetc(f);
    int b2 = fgetc(f);
    int b3 = fgetc(f);
    if (b0 == EOF || b1 == EOF || b2 == EOF || b3 == EOF) return 0;
    *v = (unsigned int)((b0 & 0xFF) |
                        ((b1 & 0xFF) << 8) |
                        ((b2 & 0xFF) << 16) |
                        ((b3 & 0xFF) << 24));
    return 1;
}

static int readFloatLE(FILE* f, float* out)
{
    unsigned int u;
    if (!readU32(f, &u)) return 0;
    memcpy(out, &u, sizeof(u));
    return 1;
}

static int readPString(FILE* f, char* buf, size_t bufSize)
{
    int c = fgetc(f);
    if (c == EOF) return 0;
    unsigned int len = (unsigned char)c;
    if (len == 0)
    {
        if (bufSize > 0) buf[0] = '\0';
        return 1;
    }
    unsigned int toRead = len;
    if (toRead >= bufSize) toRead = (unsigned int)(bufSize - 1);
    if (toRead > 0)
    {
        if (fread(buf, 1, toRead, f) != toRead) return 0;
        buf[toRead] = '\0';
    }
    unsigned int skip = len - toRead;
    while (skip--)
    {
        if (fgetc(f) == EOF) return 0;
    }
    return 1;
}

static void csvEscape(const char* in, FILE* out)
{
    fputc('"', out);
    for (const char* p = in; *p; ++p)
    {
        if (*p == '"')
        {
            fputc('"', out);
            fputc('"', out);
        }
        else
        {
            fputc(*p, out);
        }
    }
    fputc('"', out);
}

static char* getNextCSVField(char** linePtr)
{
    if (!linePtr || !*linePtr) return NULL;
    
    char* start = *linePtr;
    char* result = NULL;
    
    while (*start && (*start == ' ' || *start == '\t')) start++;
    
    if (*start == '\0' || *start == '\n' || *start == '\r') {
        *linePtr = start;
        return NULL;
    }
    
    char* end = start;
    
    if (*start == '"') {
        start++;
        end = start;
        
        while (*end) {
            if (*end == '"') {
                if (*(end + 1) == '"') {
                    end += 2;
                } else {
                    break;
                }
            } else {
                end++;
            }
        }
        
        size_t len = end - start;
        result = (char*)malloc(len + 1);
        if (result) {
            strncpy(result, start, len);
            result[len] = '\0';
            
            char* src = result;
            char* dst = result;
            while (*src) {
                if (*src == '"' && *(src + 1) == '"') {
                    src++;
                }
                *dst++ = *src++;
            }
            *dst = '\0';
        }
        
        if (*end == '"') end++;
        while (*end && (*end == ',' || *end == ' ' || *end == '\t')) end++;
        
    } else {
        while (*end && *end != ',' && *end != '\n' && *end != '\r') end++;
        
        size_t len = end - start;
        result = (char*)malloc(len + 1);
        if (result) {
            strncpy(result, start, len);
            result[len] = '\0';
            
            char* trim = result + len - 1;
            while (trim >= result && (*trim == ' ' || *trim == '\t')) {
                *trim = '\0';
                trim--;
            }
        }
        
        while (*end && (*end == ',' || *end == ' ' || *end == '\t')) end++;
    }
    
    *linePtr = end;
    return result;
}

static float parseFloat(const char* str)
{
    if (!str || !*str) return 0.0f;
    
    if (strcmp(str, "") == 0) return 0.0f;
    
    char* endptr;
    double value = strtod(str, &endptr);
    
    if (endptr == str) {
        return 0.0f;
    }
    
    if (value > FLT_MAX) return FLT_MAX;
    if (value < -FLT_MAX) return -FLT_MAX;
    if (value > 0 && value < FLT_MIN) return 0.0f;
    if (value < 0 && value > -FLT_MIN) return 0.0f;
    
    return (float)value;
}

static const unsigned int ATTR_ID_FULL = 0x03000602u;
static const unsigned int PURE3D_CHUNK_ID = 0x000003F0u;

typedef enum {
    TABLE_ATTRIBUTE,
    TABLE_PURE3D,
    TABLE_UNKNOWN
} TableType;

typedef struct {
    const char* name;
    unsigned int id;
    const char* csvHeaders;
} TableInfo;

static const TableInfo knownTables[] = {
    {"ATTRIBUTE_TABLE", ATTR_ID_FULL, "RowIndex,Sound,Particle,Animation,Friction,Mass,Elasticity"},
    {"PURE3D_TABLE", PURE3D_CHUNK_ID, "Index,Data1,Data2,Data3,Data4"},
    {NULL, 0, NULL}
};

static int tryDumpTable(FILE* in, int idSize, const char* srcPath, FILE* csv, TableType tableType)
{
    const TableInfo* tableInfo = &knownTables[tableType];
    unsigned int targetId = tableInfo->id;
    unsigned short targetId16 = (unsigned short)(targetId & 0xFFFFu);

    if (fseek(in, 0, SEEK_SET) != 0)
        return 0;

    while (1)
    {
        long chunkStart = ftell(in);
        if (chunkStart < 0)
            return 0;

        unsigned int id32 = 0;
        unsigned short id16 = 0;

        if (idSize == 4)
        {
            if (!readU32(in, &id32))
                break;
        }
        else
        {
            if (!readU16(in, &id16))
                break;
        }

        unsigned int length = 0;
        if (!readU32(in, &length))
            break;

        if (length == 0)
            return 0;

        int isMatch = 0;
        if (idSize == 4)
        {
            if (id32 == targetId) isMatch = 1;
        }
        else
        {
            if (id16 == targetId16) isMatch = 1;
        }

        if (isMatch)
        {
            if (tableType == TABLE_ATTRIBUTE)
            {
                unsigned int numRows = 0;
                if (!readU32(in, &numRows))
                {
                    fprintf(stderr, "atcmaker: failed reading numRows from '%s'\n", srcPath);
                    return 0;
                }

                fprintf(csv, "%s\n", tableInfo->csvHeaders);

                for (unsigned int i = 0; i < numRows; ++i)
                {
                    char sound[256], particle[256], animation[256];
                    float friction = 0.0f, mass = 0.0f, elasticity = 0.0f;

                    if (!readPString(in, sound, sizeof(sound)) ||
                        !readPString(in, particle, sizeof(particle)) ||
                        !readPString(in, animation, sizeof(animation)) ||
                        !readFloatLE(in, &friction) ||
                        !readFloatLE(in, &mass) ||
                        !readFloatLE(in, &elasticity))
                    {
                        fprintf(stderr, "atcmaker: truncated %s in '%s' (row %u) - dumping %u available rows\n",
                                tableInfo->name, srcPath, i, i);
                        break; // Exit loop but don't fail - we have useful data
                    }

                    fprintf(csv, "%u,", i);
                    csvEscape(sound, csv);
                    fputc(',', csv);
                    csvEscape(particle, csv);
                    fputc(',', csv);
                    csvEscape(animation, csv);
                    fprintf(csv, ",%g,%g,%g\n", friction, mass, elasticity);
                }
            }
            else if (tableType == TABLE_PURE3D)
            {
                fprintf(csv, "%s\n", tableInfo->csvHeaders);
                fprintf(csv, "0,Unknown structure for chunk ID 0x%08X\n", targetId);
            }

            return 1;
        }

        if (fseek(in, chunkStart + (long)length, SEEK_SET) != 0)
            break;
    }

    return 0;
}

static int dumpTableToCsv(const char* srcPath, const char* csvPath, TableType tableType)
{
    FILE* in = fopen(srcPath, "rb");
    if (!in)
    {
        fprintf(stderr, "atcmaker: cannot open source '%s' for CSV dump\n", srcPath);
        return 1;
    }

    FILE* csv = fopen(csvPath, "w");
    if (!csv)
    {
        fprintf(stderr, "atcmaker: cannot create CSV '%s'\n", csvPath);
        fclose(in);
        return 1;
    }

    int ok = 0;
    if (tryDumpTable(in, 4, srcPath, csv, tableType))
    {
        ok = 1;
    }
    else
    {
        if (tryDumpTable(in, 2, srcPath, csv, tableType))
        {
            ok = 1;
        }
    }

    fclose(in);
    fclose(csv);

    if (!ok)
    {
        fprintf(stderr, "atcmaker: could not locate %s in '%s'\n", knownTables[tableType].name, srcPath);
        // Remove empty CSV.
        remove(csvPath);
        return 1;
    }

    printf("atcmaker: dumped %s from '%s' to '%s'\n", knownTables[tableType].name, srcPath, csvPath);
    return 0;
}

static int dumpAllTablesToCsv(const char* srcPath, const char* baseCsvPath)
{
    int foundAny = 0;
    
    for (int tableType = 0; tableType < TABLE_UNKNOWN; ++tableType)
    {
        char csvPath[MAX_PATH];
        snprintf(csvPath, sizeof(csvPath), "%s_%s.csv", baseCsvPath, knownTables[tableType].name);
        
        if (dumpTableToCsv(srcPath, csvPath, (TableType)tableType) == 0)
        {
            foundAny = 1;
        }
    }
    
    return foundAny ? 0 : 1;
}

static int processP3DFile(const char* srcPath, const char* outputDir, int dumpAll)
{
    char baseName[MAX_PATH];
    const char* fileName = strrchr(srcPath, '\\');
    if (!fileName) fileName = strrchr(srcPath, '/');
    if (!fileName) fileName = srcPath;
    else fileName++;
    
    strncpy(baseName, fileName, sizeof(baseName) - 1);
    baseName[sizeof(baseName) - 1] = '\0';
    char* dot = strrchr(baseName, '.');
    if (dot) *dot = '\0';
    
    char csvPath[MAX_PATH];
    if (outputDir && outputDir[0] != '\0')
    {
        snprintf(csvPath, sizeof(csvPath), "%s\\%s", outputDir, baseName);
    }
    else
    {
        strncpy(csvPath, baseName, sizeof(csvPath) - 1);
        csvPath[sizeof(csvPath) - 1] = '\0';
    }
    
    if (dumpAll)
    {
        return dumpAllTablesToCsv(srcPath, csvPath);
    }
    else
    {
        char fullCsvPath[MAX_PATH];
        snprintf(fullCsvPath, sizeof(fullCsvPath), "%s.csv", csvPath);
        return dumpTableToCsv(srcPath, fullCsvPath, TABLE_ATTRIBUTE);
    }
}

static int processDirectoryRecursive(const char* dirPath, const char* outputDir, int dumpAll, int* totalProcessed, int* totalSuccess)
{
    char searchPattern[MAX_PATH];
    snprintf(searchPattern, sizeof(searchPattern), "%s\\*", dirPath);
    
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPattern, &findData);
    
    if (hFind == INVALID_HANDLE_VALUE)
    {
        return 0;
    }
    
    do
    {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (strcmp(findData.cFileName, ".") != 0 && strcmp(findData.cFileName, "..") != 0)
            {
                char subDirPath[MAX_PATH];
                snprintf(subDirPath, sizeof(subDirPath), "%s\\%s", dirPath, findData.cFileName);
                
                processDirectoryRecursive(subDirPath, outputDir, dumpAll, totalProcessed, totalSuccess);
            }
        }
        else
        {
            const char* ext = strrchr(findData.cFileName, '.');
            if (ext && _stricmp(ext, ".p3d") == 0)
            {
                char fullPath[MAX_PATH];
                snprintf(fullPath, sizeof(fullPath), "%s\\%s", dirPath, findData.cFileName);
                
                printf("\nProcessing: %s\n", fullPath);
                if (processP3DFile(fullPath, outputDir, dumpAll) == 0)
                {
                    (*totalSuccess)++;
                }
                (*totalProcessed)++;
            }
        }
    } while (FindNextFileA(hFind, &findData));
    
    FindClose(hFind);
    return 0;
}

static int processDirectory(const char* dirPath, const char* outputDir, int dumpAll)
{
    int processedCount = 0;
    int successCount = 0;
    
    printf("Scanning directory: %s\n", dirPath);
    printf("Including subdirectories...\n");
    
    processDirectoryRecursive(dirPath, outputDir, dumpAll, &processedCount, &successCount);
    
    printf("\n=== Summary ===\n");
    printf("Processed %d P3D files, successfully dumped %d files\n", processedCount, successCount);
    
    return (successCount > 0) ? 0 : 1;
}

static void writeU32(FILE* f, unsigned int value)
{
    fputc(value & 0xFF, f);
    fputc((value >> 8) & 0xFF, f);
    fputc((value >> 16) & 0xFF, f);
    fputc((value >> 24) & 0xFF, f);
}

static int rebuildP3DFromCSV(const char* csvPath, const char* outputPath)
{
    FILE* csv = fopen(csvPath, "r");
    if (!csv)
    {
        fprintf(stderr, "atcmaker: cannot open CSV '%s' for reading\n", csvPath);
        return 1;
    }

    FILE* out = fopen(outputPath, "wb");
    if (!out)
    {
        fprintf(stderr, "atcmaker: cannot create P3D '%s'\n", outputPath);
        fclose(csv);
        return 1;
    }

    char line[2048];
    int rowCount = 0;
    
    if (!fgets(line, sizeof(line), csv))
    {
        fprintf(stderr, "atcmaker: CSV file '%s' is empty or missing header\n", csvPath);
        fclose(csv);
        fclose(out);
        return 1;
    }
    
    if (strstr(line, "RowIndex,Sound,Particle,Animation,Friction,Mass,Elasticity") == NULL)
    {
        fprintf(stderr, "atcmaker: CSV file '%s' has invalid header format\n", csvPath);
        fclose(csv);
        fclose(out);
        return 1;
    }
    
    while (fgets(line, sizeof(line), csv))
    {
        if (strlen(line) > 1)
        {
            rowCount++;
        }
    }
    
    if (rowCount == 0)
    {
        fprintf(stderr, "atcmaker: CSV file '%s' contains no data rows\n", csvPath);
        fclose(csv);
        fclose(out);
        return 1;
    }
    
    printf("atcmaker: rebuilding P3D from %d data rows\n", rowCount);
    
    fseek(csv, 0, SEEK_SET);
    if (!fgets(line, sizeof(line), csv)) // Skip header again
    {
        fprintf(stderr, "atcmaker: error reading CSV header\n");
        fclose(csv);
        fclose(out);
        return 1;
    }

    fwrite("P3D", 3, 1, out);
    
    unsigned int totalLengthPos = ftell(out);
    writeU32(out, 0);
    
    writeU32(out, 0x00092100); // 21 09 00 00
    writeU32(out, 0x03000600); // 02 06 00 03
    writeU32(out, 0x00091500); // 15 09 00 00
    writeU32(out, 0x00091500); // 15 09 00 00
    writeU32(out, 0x0000003F); // 3F 00 00 00
    
    fwrite("\x04\x57\x54\x46", 4, 1, out); // Length 4 + "WTF"
    fwrite("\x04\x57\x54\x46", 4, 1, out); // Length 4 + "WTF"
    fwrite("\x04\x57\x54\x46", 4, 1, out); // Length 4 + "WTF"
    fwrite("\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 10, 1, out);
    
    unsigned int chunkHeaderPos = ftell(out);
    writeU32(out, 0x03000602); // ATTRIBUTE_TABLE chunk ID
    unsigned int chunkLengthPos = ftell(out);
    writeU32(out, 0);
    writeU32(out, rowCount);
    
    int rowsWritten = 0;
    while (fgets(line, sizeof(line), csv) && rowsWritten < rowCount)
    {
        if (strlen(line) <= 1) continue;
        
        char* newline = strchr(line, '\n');
        if (newline) *newline = '\0';
        newline = strchr(line, '\r');
        if (newline) *newline = '\0';
        
        char* linePtr = line;
        char* fieldStr = getNextCSVField(&linePtr);
        if (!fieldStr) continue;
        int rowIndex = atoi(fieldStr);
        free(fieldStr);
        
        char* sound = getNextCSVField(&linePtr);
        if (!sound) sound = strdup("");
        
        char* particle = getNextCSVField(&linePtr);
        if (!particle) particle = strdup("");
        
        char* animation = getNextCSVField(&linePtr);
        if (!animation) animation = strdup("");
        
        fieldStr = getNextCSVField(&linePtr);
        float friction = fieldStr ? parseFloat(fieldStr) : 0.0f;
        if (fieldStr) free(fieldStr);
        
        fieldStr = getNextCSVField(&linePtr);
        float mass = fieldStr ? parseFloat(fieldStr) : 0.0f;
        if (fieldStr) free(fieldStr);
        
        fieldStr = getNextCSVField(&linePtr);
        float elasticity = fieldStr ? parseFloat(fieldStr) : 0.0f;
        if (fieldStr) free(fieldStr);
        
        size_t soundLen = strlen(sound);
        if (soundLen > 255) soundLen = 255; // Limit to 255 for length byte
        fputc((unsigned char)soundLen, out);
        if (soundLen > 0) {
            fwrite(sound, 1, soundLen, out);
        }
        
        size_t particleLen = strlen(particle);
        if (particleLen > 255) particleLen = 255;
        fputc((unsigned char)particleLen, out);
        if (particleLen > 0) {
            fwrite(particle, 1, particleLen, out);
        }
        
        size_t animLen = strlen(animation);
        if (animLen > 255) animLen = 255;
        fputc((unsigned char)animLen, out);
        if (animLen > 0) {
            fwrite(animation, 1, animLen, out);
        }
        
        fwrite(&friction, 4, 1, out);
        fwrite(&mass, 4, 1, out);
        fwrite(&elasticity, 4, 1, out);
        
        free(sound);
        free(particle);
        free(animation);
        
        rowsWritten++;
        
        if (rowsWritten % 100 == 0) {
            printf("atcmaker: processed %d/%d rows\n", rowsWritten, rowCount);
        }
    }
    
    if (rowsWritten != rowCount) {
        fprintf(stderr, "atcmaker: warning - processed %d rows but expected %d\n", rowsWritten, rowCount);
    }
    
    unsigned int currentPos = ftell(out);
    if (currentPos == 0xFFFFFFFF) {
        fprintf(stderr, "atcmaker: error getting file position\n");
        fclose(csv);
        fclose(out);
        return 1;
    }
    
    unsigned int chunkLength = currentPos - chunkHeaderPos - 8; // Exclude chunk ID and length fields
    unsigned int totalLength = currentPos - 4; // Exclude P3D signature
    
    if (fseek(out, chunkLengthPos, SEEK_SET) != 0) {
        fprintf(stderr, "atcmaker: error seeking to chunk length position\n");
        fclose(csv);
        fclose(out);
        return 1;
    }
    writeU32(out, chunkLength);
    
    if (fseek(out, totalLengthPos, SEEK_SET) != 0) {
        fprintf(stderr, "atcmaker: error seeking to total length position\n");
        fclose(csv);
        fclose(out);
        return 1;
    }
    writeU32(out, totalLength);
    
    fclose(csv);
    fclose(out);
    
    printf("atcmaker: successfully rebuilt P3D from CSV '%s' to '%s' (%d rows, %u bytes)\n", 
           csvPath, outputPath, rowsWritten, totalLength + 4);
    return 0;
}

static void printUsage()
{
    fprintf(stderr,
        "Usage:\n"
        "  atcmaker atc.p3d\n"
        "    Copies source_atc.p3d (next to atcmaker.exe) to atc.p3d.\n"
        "    If table.csv exists next to atcmaker.exe, rebuilds atc.p3d from CSV.\n"
        "\n"
        "  atcmaker src_atc.p3d dest_atc.p3d\n"
        "    Copies src_atc.p3d to dest_atc.p3d.\n"
        "\n"
        "  atcmaker -src path_to_precompiled_atc.p3d -out atc.p3d\n"
        "    Copies from explicit source to explicit destination.\n"
        "\n"
        "  atcmaker -dumpcsv table.csv\n"
        "    Dumps ATTRIBUTE_TABLE from source_atc.p3d (next to exe) to CSV.\n"
        "  atcmaker src_atc.p3d -dumpcsv table.csv\n"
        "    Dumps from explicit source P3D to CSV.\n"
        "\n"
        "  atcmaker -dumpcsv table.csv -all\n"
        "    Dumps ALL known tables from source_atc.p3d to multiple CSV files.\n"
        "  atcmaker src_atc.p3d -dumpcsv table.csv -all\n"
        "    Dumps ALL known tables from explicit source to multiple CSV files.\n"
        "\n"
        "  atcmaker -folder path_to_p3d_directory [-outdir output_directory] [-all]\n"
        "    Processes ALL P3D files in directory (including subdirectories).\n"
        "    Use -all to dump all table types.\n"
        "\n"
        "CSV Rebuild Feature:\n"
        "  Place table.csv next to atcmaker.exe and run: atcmaker atc.p3d\n"
        "  The tool will automatically rebuild atc.p3d from the CSV data.\n"
        "\n"
        "Examples:\n"
        "  atcmaker -folder \"C:\\\\game\\\\art\" -outdir \"csv_output\" -all\n"
        "    Processes all P3D files and dumps all table types to csv_output folder.\n"
        "  atcmaker -folder \".\\\\data\" -dumpcsv\n"
        "    Processes all P3D files in current directory, dumps ATTRIBUTE_TABLE only.\n"
        "  atcmaker atc.p3d  (with table.csv present)\n"
        "    Rebuilds atc.p3d from table.csv data.\n"
        "  atcmaker atc.p3d  (pipeline usage)\n"
        "    Copies source_atc.p3d to atc.p3d for the current build.\n"
    );
}

int main(int argc, char* argv[])
{
    const char* srcPath = NULL;
    const char* dstPath = NULL;
    const char* csvPath = NULL;
    const char* folderPath = NULL;
    const char* outputDir = NULL;

    int dumpAll = 0;
    const char* firstPositional = NULL;

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-src") == 0 && i + 1 < argc)
        {
            srcPath = argv[++i];
        }
        else if (strcmp(argv[i], "-out") == 0 && i + 1 < argc)
        {
            dstPath = argv[++i];
        }
        else if (strcmp(argv[i], "-dumpcsv") == 0 && i + 1 < argc)
        {
            csvPath = argv[++i];
        }
        else if (strcmp(argv[i], "-folder") == 0 && i + 1 < argc)
        {
            folderPath = argv[++i];
        }
        else if (strcmp(argv[i], "-outdir") == 0 && i + 1 < argc)
        {
            outputDir = argv[++i];
        }
        else if (strcmp(argv[i], "-all") == 0)
        {
            dumpAll = 1;
        }
        else if (argv[i][0] != '-')
        {
            if (!firstPositional)
            {
                firstPositional = argv[i];
            }
            else if (!dstPath)
            {
                if (!srcPath)
                    srcPath = firstPositional;
                dstPath = argv[i];
            }
        }
    }

    if (folderPath)
    {
        return processDirectory(folderPath, outputDir ? outputDir : ".", dumpAll);
    }

    if (csvPath)
    {
        if (!srcPath)
        {
            if (firstPositional)
            {
                srcPath = firstPositional;
            }
            else
            {
                static char defaultSrc[MAX_PATH];
                getDefaultSourcePath(defaultSrc, sizeof(defaultSrc));
                srcPath = defaultSrc;
            }
        }

        if (!srcPath)
        {
            printUsage();
            fprintf(stderr, "atcmaker: missing source ATTRIBUTE_TABLE file for CSV dump\n");
            return 1;
        }

        if (dumpAll)
        {
            return dumpAllTablesToCsv(srcPath, csvPath);
        }
        else
        {
            return dumpTableToCsv(srcPath, csvPath, TABLE_ATTRIBUTE);
        }
    }

    if (!dstPath && firstPositional && !srcPath)
    {
        dstPath = firstPositional;
        
        char csvPath[MAX_PATH];
        char exeDir[MAX_PATH];
        DWORD len = GetModuleFileNameA(NULL, exeDir, MAX_PATH);
        if (len > 0 && len < MAX_PATH)
        {
            char* lastSlash = strrchr(exeDir, '\\');
            if (lastSlash)
            {
                *(lastSlash + 1) = '\0';
                snprintf(csvPath, sizeof(csvPath), "%stable.csv", exeDir);
                
                FILE* csvTest = fopen(csvPath, "r");
                if (csvTest)
                {
                    fclose(csvTest);
                    printf("atcmaker: found table.csv, rebuilding P3D from CSV data\n");
                    return rebuildP3DFromCSV(csvPath, dstPath);
                }
            }
        }
        
        static char defaultSrc[MAX_PATH];
        getDefaultSourcePath(defaultSrc, sizeof(defaultSrc));
        srcPath = defaultSrc;
    }

    if (!dstPath || !srcPath)
    {
        printUsage();
        fprintf(stderr, "atcmaker: missing %s\n",
                !srcPath ? "source ATTRIBUTE_TABLE file (precompiled atc.p3d)" :
                           "destination path");
        return 1;
    }

    int result = copyFile(srcPath, dstPath);
    if (result == 0)
    {
        printf("atcmaker: copied '%s' -> '%s'\n", srcPath, dstPath);
    }
    return result;
}
