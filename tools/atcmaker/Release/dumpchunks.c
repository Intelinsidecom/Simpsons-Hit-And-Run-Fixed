#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int readU32(FILE* f)
{
    int b0 = fgetc(f);
    int b1 = fgetc(f);
    int b2 = fgetc(f);
    int b3 = fgetc(f);
    if (b0 == EOF || b1 == EOF || b2 == EOF || b3 == EOF) return 0;
    return (unsigned int)((b0 & 0xFF) |
                        ((b1 & 0xFF) << 8) |
                        ((b2 & 0xFF) << 16) |
                        ((b3 & 0xFF) << 24));
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <file.p3d>\n", argv[0]);
        return 1;
    }
    
    FILE* f = fopen(argv[1], "rb");
    if (!f) {
        printf("Cannot open %s\n", argv[1]);
        return 1;
    }
    
    // Read P3D signature
    char sig[4];
    fread(sig, 1, 3, f);
    sig[3] = '\0';
    printf("Signature: %s\n", sig);
    
    // Read total length
    unsigned int totalLen = readU32(f);
    printf("Total length: %u (0x%08X)\n", totalLen, totalLen);
    
    // Read unknown field
    unsigned int unknown1 = readU32(f);
    printf("Unknown field 1: 0x%08X\n", unknown1);
    
    // Read unknown byte
    int unknownByte = fgetc(f);
    printf("Unknown byte: 0x%02X\n", unknownByte);
    
    // Read chunk header
    unsigned int chunkId = readU32(f);
    printf("Chunk ID: 0x%08X\n", chunkId);
    
    unsigned int chunkLen = readU32(f);
    printf("Chunk length: %u (0x%08X)\n", chunkLen, chunkLen);
    
    // Read row count
    unsigned int rowCount = readU32(f);
    printf("Row count: %u\n", rowCount);
    
    printf("File position after headers: %ld\n", ftell(f));
    printf("Expected end position: %ld\n", 12 + 8 + chunkLen);
    
    fclose(f);
    return 0;
}
