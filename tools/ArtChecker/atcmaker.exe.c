typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
float10
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned int    uint3;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned short    word;
typedef struct _s_HandlerType _s_HandlerType, *P_s_HandlerType;

typedef struct _s_HandlerType HandlerType;

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

typedef int ptrdiff_t;

struct TypeDescriptor {
    void *pVFTable;
    void *spare;
    char name[0];
};

struct _s_HandlerType {
    uint adjectives;
    struct TypeDescriptor *pType;
    ptrdiff_t dispCatchObj;
    void *addressOfHandler;
};

typedef struct _s_UnwindMapEntry _s_UnwindMapEntry, *P_s_UnwindMapEntry;

typedef struct _s_UnwindMapEntry UnwindMapEntry;

typedef int __ehstate_t;

struct _s_UnwindMapEntry {
    __ehstate_t toState;
    void (*action)(void);
};

typedef struct _s_TryBlockMapEntry _s_TryBlockMapEntry, *P_s_TryBlockMapEntry;

struct _s_TryBlockMapEntry {
    __ehstate_t tryLow;
    __ehstate_t tryHigh;
    __ehstate_t catchHigh;
    int nCatches;
    HandlerType *pHandlerArray;
};

typedef struct _s_TryBlockMapEntry TryBlockMapEntry;

typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef struct _s_FuncInfo _s_FuncInfo, *P_s_FuncInfo;

typedef struct _s_FuncInfo FuncInfo;

struct _s_FuncInfo {
    uint magicNumber_and_bbtFlags;
    __ehstate_t maxState;
    UnwindMapEntry *pUnwindMap;
    uint nTryBlocks;
    TryBlockMapEntry *pTryBlockMap;
    uint nIPMapEntries;
    void *pIPToStateMap;
};

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT CONTEXT;

typedef ulong DWORD;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

typedef uchar BYTE;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef void *PVOID;

typedef ulong ULONG_PTR;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

typedef CONTEXT *PCONTEXT;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef struct _iobuf FILE;

typedef void (*PMFN)(void *);

typedef struct _s_CatchableType _s_CatchableType, *P_s_CatchableType;


// WARNING! conflicting data type names: /ehdata.h/TypeDescriptor - /TypeDescriptor

typedef struct PMD PMD, *PPMD;

struct PMD {
    ptrdiff_t mdisp;
    ptrdiff_t pdisp;
    ptrdiff_t vdisp;
};

struct _s_CatchableType {
    uint properties;
    struct TypeDescriptor *pType;
    struct PMD thisDisplacement;
    int sizeOrOffset;
    PMFN copyFunction;
};

typedef struct _s_CatchableType CatchableType;

typedef struct _s_CatchableTypeArray _s_CatchableTypeArray, *P_s_CatchableTypeArray;

typedef struct _s_CatchableTypeArray CatchableTypeArray;

struct _s_CatchableTypeArray {
    int nCatchableTypes;
    CatchableType *arrayOfCatchableTypes[0];
};

typedef struct _s_ThrowInfo _s_ThrowInfo, *P_s_ThrowInfo;

typedef struct _s_ThrowInfo ThrowInfo;

struct _s_ThrowInfo {
    uint attributes;
    PMFN pmfnUnwind;
    int (*pForwardCompat)(void);
    CatchableTypeArray *pCatchableTypeArray;
};

typedef struct type_info type_info, *Ptype_info;

struct type_info { // PlaceHolder Structure
};

typedef struct allocator<char> allocator<char>, *Pallocator<char>;

struct allocator<char> { // PlaceHolder Structure
};

typedef struct strstreambuf strstreambuf, *Pstrstreambuf;

struct strstreambuf { // PlaceHolder Structure
};

typedef struct basic_streambuf<char,struct_std::char_traits<char>_> basic_streambuf<char,struct_std::char_traits<char>_>, *Pbasic_streambuf<char,struct_std::char_traits<char>_>;

struct basic_streambuf<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_istream<char,struct_std::char_traits<char>_> basic_istream<char,struct_std::char_traits<char>_>, *Pbasic_istream<char,struct_std::char_traits<char>_>;

struct basic_istream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_ostream<char,struct_std::char_traits<char>_> basic_ostream<char,struct_std::char_traits<char>_>, *Pbasic_ostream<char,struct_std::char_traits<char>_>;

struct basic_ostream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_iostream<char,struct_std::char_traits<char>_> basic_iostream<char,struct_std::char_traits<char>_>, *Pbasic_iostream<char,struct_std::char_traits<char>_>;

struct basic_iostream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>, *Pbasic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>;

struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> { // PlaceHolder Structure
};

typedef struct fpos<int> fpos<int>, *Pfpos<int>;

struct fpos<int> { // PlaceHolder Structure
};

typedef struct locale locale, *Plocale;

struct locale { // PlaceHolder Structure
};

typedef struct strstream strstream, *Pstrstream;

struct strstream { // PlaceHolder Structure
};

typedef struct ios_base ios_base, *Pios_base;

struct ios_base { // PlaceHolder Structure
};

typedef struct basic_ios<char,struct_std::char_traits<char>_> basic_ios<char,struct_std::char_traits<char>_>, *Pbasic_ios<char,struct_std::char_traits<char>_>;

struct basic_ios<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct _Lockit _Lockit, *P_Lockit;

struct _Lockit { // PlaceHolder Structure
};

typedef struct _Winit _Winit, *P_Winit;

struct _Winit { // PlaceHolder Structure
};

typedef struct _Locimp _Locimp, *P_Locimp;

struct _Locimp { // PlaceHolder Structure
};

typedef struct Init Init, *PInit;

struct Init { // PlaceHolder Structure
};

typedef enum seekdir {
} seekdir;

typedef int (*_onexit_t)(void);

typedef uint size_t;

typedef struct _startupinfo _startupinfo, *P_startupinfo;

struct _startupinfo {
    int newmode;
};



undefined LAB_0042eefb;
void *ExceptionList;
undefined1 DAT_004399b0;
undefined LAB_0042ef37;
string s_Error_opening_file:_%s_for_Write_004399b4;
undefined *PTR_cout_00430068;
undefined *PTR_cerr_00430060;
undefined *PTR__C_0043005c;
undefined *PTR_`vftable'_0043004c;
undefined LAB_0042f078;
undefined *PTR_FUN_00430230;
undefined *PTR_LAB_0043023c;
pointer PTR_LAB_0043024c;
undefined *PTR_LAB_00430254;
pointer PTR_LAB_00430264;
string s_Usage:_atcmaker_<filename>_004399f4;
string s_Cant_connection_to_art_db_00439a1c;
undefined DAT_00439a38;
undefined DAT_00439a3c;
string s_Elasticity:_00439a40;
string s_Friction:_00439a50;
string s_Mass:_00439a5c;
string s_Animation:_00439a64;
string s_Particle:_00439a70;
string s_Sound:_00439a7c;
string s_elasticity_00439a84;
string s_friction_00439a90;
undefined DAT_00439a9c;
string s_animation_00439aa4;
string s_particle_00439ab0;
string s_sound_00439abc;
string s_No_Enteries_in_physprops_table_00439ac4;
string s_SELECT_*_FROM_physprops_00439ae8;
string s_Connection_to_Artdb_established_p_00439b00;
string s_srr2test_00439b30;
string s_radit_00439b3c;
undefined DAT_00439b44;
string s_custom47_00439b4c;
undefined LAB_00401ab3;
string s_Error:_00439a14;
undefined DAT_0044345d;
undefined LAB_00401b80;
undefined DAT_0044345c;
undefined LAB_00401bc0;
undefined *PTR_npos_00430080;
int DAT_00443480;
void *DAT_0044347c;
undefined LAB_0042f0bd;
int *DAT_0044347c;
undefined4 *DAT_0044347c;
undefined LAB_0042f0e1;
undefined DAT_004366d4;
string s_Row_not_initialized_00439b58;
undefined1 DAT_00443484;
undefined LAB_0042f12e;
pointer PTR_LAB_0043026c;
undefined LAB_0042f162;
string s_Bad_row_00439b6c;
string s_Results_not_fetched_00439b74;
undefined LAB_0042f1db;
string s_ROW_or_RES_is_NULL_00439b88;
undefined LAB_0042f21d;
undefined LAB_0042f239;
undefined *PTR_`vftable'_004300bc;
undefined LAB_0042f2aa;
pointer PTR_LAB_00430274;
pointer PTR_LAB_00430278;
pointer PTR_LAB_0043027c;
undefined DAT_00430280;
undefined DAT_00430288;
undefined *PTR__Global_004300f8;
undefined LAB_0042f2c9;
undefined *PTR_FUN_00430290;
undefined LAB_0042f2f5;
undefined LAB_0042f31c;
undefined LAB_0042f342;
undefined LAB_0042f363;
undefined LAB_0042f379;
undefined DAT_00436998;
TypeDescriptor TypeDescriptor_00439bc0;
undefined LAB_0042f3a1;
undefined LAB_0042f3c1;
undefined LAB_0042f3e1;
undefined LAB_0042f412;
undefined1 DAT_00443489;
undefined LAB_00405070;
undefined1 DAT_00443488;
undefined LAB_004050b0;
char DAT_0044348f;
undefined1 DAT_00439bcc;
undefined DAT_0044348d;
undefined LAB_00405360;
undefined DAT_0044348c;
undefined LAB_004053a0;
undefined LAB_0042f431;
undefined LAB_0042f472;
undefined LAB_0042f48c;
undefined LAB_0042f4c7;
undefined DAT_00443491;
undefined LAB_00405ad0;
undefined DAT_00443490;
undefined LAB_00405b10;
undefined LAB_0042f526;
undefined DAT_00436bb4;
string s_Not_enough_parameters_to_fill_th_00439bf0;
string s_ERROR_00439c1c;
undefined LAB_0042f539;
undefined LAB_0042f559;
undefined LAB_0042f578;
undefined LAB_0042f599;
undefined DAT_00443495;
undefined LAB_00406ff0;
undefined DAT_00443494;
undefined LAB_00407030;
undefined DAT_00443499;
undefined LAB_004073e0;
undefined DAT_00443498;
undefined LAB_00407420;
undefined DAT_004434b1;
undefined LAB_00407520;
undefined DAT_004434b0;
undefined LAB_00407560;
undefined DAT_004434a0;
undefined LAB_00407d20;
int *DAT_004437a8;
int DAT_004437a4;
undefined4 *DAT_004437a8;
undefined LAB_0042f5b8;
TypeDescriptor RTTI_Type_Descriptor;
undefined DAT_004434bc;
undefined DAT_004434c0;
int DAT_004437a8;
string s_%*s_Elasticity_=_%f_0043a4e0;
string s_%*s_Mass_=_%f_0043a4f8;
string s_%*s_Friction_=_%f_0043a510;
string s_%*s_Animation_=_"%s"_0043a528;
string s_%*s_Particle_=_"%s"_0043a540;
string s_%*s_Sound_=_"%s"_0043a558;
string s_%*s%d_0043a570;
string s_%*s_float_%12f_#_Elasticity_0043a578;
string s_%*s_float_%12f_#_Mass_0043a598;
string s_%*s_float_%12f_#_Friction_0043a5b0;
string s_%*s_pstring_"%s"_#_Animation_0043a5cc;
string s_%*s_pstring_"%s"_#_Particle_0043a5ec;
string s_%*s_pstring_"%s"_#_Sound_0043a60c;
undefined4 DAT_0043a638;
string s_Elasticity_=_%f,_0043a63c;
string s_Mass_=_%f,_0043a650;
string s_Friction_=_%f,_0043a65c;
string s_Animation_=_%s,_0043a66c;
string s_Particle_=_%s,_0043a680;
string s_Sound_=_%s,_0043a690;
undefined LAB_0042f5d8;
undefined *PTR_FUN_004302d4;
undefined LAB_0042f5f8;
undefined LAB_0042f618;
undefined FUN_00408be0;
int DAT_0043a4dc;
undefined LAB_0042f638;
undefined LAB_0042f65b;
undefined *PTR_FUN_00430338;
undefined LAB_0042f67b;
undefined DAT_0043a7e0;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043a7e4;
undefined *PTR_DAT_0043a7c0;
string s_len+pad_<_256_0043a81c;
string s_(unsigned_int)((unsigned_short)_i_0043a82c;
undefined LAB_0042f698;
undefined *PTR_FUN_00430360;
undefined1 DAT_0043a894;
undefined1 DAT_0043a898;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043a8a0;
undefined LAB_0042f6b8;
undefined LAB_0042f6d8;
undefined *PTR_FUN_00430428;
undefined DAT_004437d0;
undefined LAB_0040a520;
undefined *PTR_FUN_00430434;
undefined LAB_0042f6fb;
undefined LAB_0042f718;
string s_%*sendchunk_0043a73c;
string s_%*s_endrepeat_0043a95c;
string s_%*s_0x%02x_0043a96c;
string s_%*s_repeat_1_byte_#_unknown_chun_0043a97c;
string s_%*schunk_0x%04x_0043a9a4;
string s_index<subcount_0043a9c4;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043a9d4;
int DAT_004439f8;
undefined4 DAT_004437d8;
uint DAT_004439f8;
string s_index_!=_0x7fffffff_0043aa10;
string s_FindPriority(addID)_==_0x7ffffff_0043aa24;
string s_(usedChunkPriorities_+_1)_<_maxC_0043aa48;
undefined DAT_004437d4;
pointer PTR_FUN_004304a8;
undefined LAB_0042f738;
pointer PTR_FUN_004304b0;
undefined LAB_0042f758;
undefined LAB_0042f778;
undefined *PTR_FUN_004304b8;
string s_offset_>=_position_0043aae4;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043aaf8;
undefined *PTR_LAB_00430504;
string s_?at<=oldCount_0043abe7;
string s_at==0_0043abf8;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043ac00;
string s_strlen(c)>2_0043affc;
string s_D:\SRR2\depot\game\libs\pure3d\t_0043b008;
undefined4 DAT_00430980;
string s_Italic_0043e928;
undefined1 DAT_0043e930;
string s_Bold_Italic_0043e938;
string s_Regular_0043e944;
undefined DAT_004309c8;
undefined DAT_00430998;
undefined DAT_004309ac;
int DAT_004433c0;
undefined *PTR_DAT_004431b4;
string s_pshinter_0043eb78;
string s_.notdef_0043eb68;
string s_%!FontType_0043eb9c;
string s_%!PS-AdobeFont-1_0043eba8;
undefined DAT_00430ac8;
pointer PTR_s_version_00430ad8;
string s_version_0043eb3c;
string s_known_0043ebbc;
string s_FontDirectory_0043ebc4;
undefined FUN_004156e0;
undefined DAT_0043ec08;
undefined DAT_004170a0;
undefined LAB_004170d0;
undefined LAB_004170e0;
undefined LAB_00417150;
undefined LAB_00417450;
undefined *PTR_FUN_004310a4;
undefined DAT_00431110;
undefined DAT_00431164;
undefined4 DAT_004311d0;
undefined UNK_00431253;
undefined DAT_004312f4;
undefined LAB_0041dd70;
undefined LAB_0041ddc0;
undefined LAB_0041e010;
undefined LAB_0041e030;
undefined LAB_0041e040;
undefined FUN_0041deb0;
undefined FUN_0041e0b0;
undefined FUN_0041edb0;
undefined FUN_0041f190;
undefined *PTR_s_.notdef_004313c0;
undefined2 DAT_00432658;
undefined FUN_0041faa0;
undefined *PTR_FUN_00433330;
undefined LAB_00420850;
undefined LAB_004216e0;
string s_psnames_0043eb94;
undefined FUN_00421640;
undefined DAT_00433400;
string s_CHARSET_ENCODING_0044188c;
string s_CHARSET_REGISTRY_004418a0;
string s_RESOLUTION_Y_004418b4;
string s_RESOLUTION_X_004418c4;
string s_POINT_SIZE_004418d4;
string s_PIXEL_SIZE_004418e0;
string s_FAMILY_NAME_004418ec;
string s_WEIGHT_NAME_004418f8;
string s_SLANT_00441904;
undefined DAT_00433500;
undefined DAT_00433510;
undefined DAT_00433584;
undefined DAT_00433598;
undefined DAT_00433528;
undefined DAT_00433548;
undefined DAT_00433568;
undefined DAT_004335ac;
undefined DAT_004335e0;
string s_StartData_004419f8;
string s_%!PS-Adobe-3.0_Resource-CIDFont_00441a04;
pointer PTR_s_CIDFontName_00433680;
string s_CIDFontName_004419ec;
string s_%ADOBeginFontDict_00441a24;
string s_postscript_name_0043e900;
undefined LAB_00424210;
undefined LAB_004242c0;
string s_name_index_0043e8e8;
string s_glyph_name_0043e8f4;
undefined DAT_00434b10;
undefined4 DAT_00434340;
undefined4 DAT_00434510;
undefined4 DAT_00434660;
undefined4 DAT_00434710;
undefined4 DAT_00434910;
undefined DAT_00433d70;
undefined4 DAT_00434b28;
undefined UNK_00434b93;
undefined DAT_00434b94;
undefined FUN_00429a70;
pointer PTR_DAT_00441a48;
undefined *PTR_s_xzroesc_00441a50;
undefined DAT_00434bc8;
undefined DAT_00435be0;
undefined DAT_00435ce0;
undefined DAT_00435de0;
undefined1 DAT_004356d4;
undefined DAT_00435598;
undefined DAT_00435610;
undefined DAT_00435bdf;
undefined DAT_00435ee0;
undefined DAT_00435f58;
undefined DAT_0042de10;
undefined DAT_004361f0;
undefined DAT_00436200;
undefined4 DAT_004550d0;
undefined DAT_004550cc;
undefined4 DAT_00454eb0;
undefined4 DAT_00454eac;
undefined *PTR__adjust_fdiv_004301e0;
undefined DAT_004550c8;
int DAT_004431b0;
int DAT_00454ea8;
int DAT_00454ea4;
undefined LAB_0042de46;
undefined DAT_00436218;
undefined DAT_00439000;
undefined DAT_004399a4;
undefined DAT_004399a8;
undefined DAT_004399ac;
undefined4 UNK_ffffffcc;
undefined4 UNK_fffff5e4;

undefined4 * __fastcall FUN_00401000(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042eefb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x30);
  local_4 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_00409230(puVar2);
  }
  local_4 = 0xffffffff;
  *param_1 = puVar2;
  puVar2 = operator_new(0x1c24);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 300;
    puVar2 = puVar2 + 1;
  }
  param_1[2] = puVar2;
  uVar6 = 0;
  do {
    pvVar3 = operator_new(0x1e);
    *(void **)(uVar6 + param_1[2]) = pvVar3;
    pvVar3 = operator_new(0x1e);
    *(void **)(uVar6 + 4 + param_1[2]) = pvVar3;
    pvVar3 = operator_new(0x1e);
    uVar7 = uVar6 + 0x18;
    *(void **)(uVar6 + 8 + param_1[2]) = pvVar3;
    uVar6 = uVar7;
  } while (uVar7 < 0x1c20);
  pcVar4 = &DAT_004399b0;
  pcVar5 = *(char **)param_1[2];
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar4 = &DAT_004399b0;
  pcVar5 = *(char **)(param_1[2] + 4);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar4 = &DAT_004399b0;
  pcVar5 = *(char **)(param_1[2] + 8);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1[2] + 0xc) = 0;
  *(undefined4 *)(param_1[2] + 0x10) = 0;
  *(undefined4 *)(param_1[2] + 0x14) = 0;
  param_1[1] = 1;
  ExceptionList = local_c;
  return param_1;
}



void __fastcall FUN_00401110(int *param_1)

{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
  }
  return;
}



undefined4 __thiscall
FUN_00401120(void *this,char *param_1,char *param_2,char *param_3,uint param_4,uint param_5,
            uint param_6)

{
  char cVar1;
  char *pcVar2;
  
  if (*(int *)((int)this + 4) < 300) {
    pcVar2 = *(char **)(*(int *)((int)this + 8) + *(int *)((int)this + 4) * 0x18);
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = *(char **)(*(int *)((int)this + 8) + 4 + *(int *)((int)this + 4) * 0x18);
    do {
      cVar1 = *param_2;
      param_2 = param_2 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = *(char **)(*(int *)((int)this + 8) + 8 + *(int *)((int)this + 4) * 0x18);
    do {
      cVar1 = *param_3;
      param_3 = param_3 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    *(float *)(*(int *)((int)this + 8) + 0xc + *(int *)((int)this + 4) * 0x18) = (float)param_4;
    *(float *)(*(int *)((int)this + 8) + 0x10 + *(int *)((int)this + 4) * 0x18) = (float)param_5;
    *(float *)(*(int *)((int)this + 8) + 0x14 + *(int *)((int)this + 4) * 0x18) = (float)param_6;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    return 0;
  }
  return 1;
}



undefined4 __thiscall FUN_00401200(void *this,char *param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  int *this_00;
  int *piVar3;
  undefined3 extraout_var;
  undefined1 local_11c [264];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042ef37;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00409a90(*(void **)this,*(int *)((int)this + 8),*(int *)((int)this + 4));
  FUN_00409a80(*(void **)this,*(undefined4 *)((int)this + 4));
  pvVar2 = operator_new(0x28);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    this_00 = (int *)0x0;
  }
  else {
    this_00 = (int *)FUN_0040a550(pvVar2,0xff443350);
  }
  local_4 = 0xffffffff;
  FUN_0040abe0(this_00,*(int *)this,0);
  pvVar2 = operator_new(0x10);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_0040a130(pvVar2,param_1,1);
  }
  local_4 = 0xffffffff;
  FUN_00409c20(local_11c,piVar3,2,1);
  local_4 = 2;
  uVar1 = FUN_00409e00((int)local_11c);
  if (CONCAT31(extraout_var,uVar1) == 0) {
    printf(s_Error_opening_file___s_for_Write_004399b4,param_1);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  (**(code **)(*this_00 + 4))(local_11c);
  (**(code **)*this_00)(1);
  pvStack_c = (void *)0xffffffff;
  FUN_00409c50((undefined4 *)&stack0xfffffedc);
  ExceptionList = pvStack_14;
  return 0;
}



undefined4 __cdecl FUN_00401450(int param_1,int param_2)

{
  code cVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  basic_ostream<> *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  code *pcVar11;
  float10 fVar12;
  float10 fVar13;
  char local_904 [1000];
  undefined1 local_51c [8];
  undefined1 local_514 [496];
  undefined1 local_324;
  undefined1 local_323;
  undefined1 local_322;
  basic_iostream<> local_31c [8];
  basic_ostream<> local_314 [160];
  undefined1 local_274 [8];
  code *local_26c [13];
  undefined4 local_238 [4];
  basic_string<> local_228 [20];
  undefined4 local_214 [4];
  basic_string<> local_204 [20];
  undefined4 local_1f0 [4];
  basic_string<> local_1e0 [20];
  undefined4 local_1cc [4];
  basic_string<> local_1bc [20];
  undefined4 local_1a8 [4];
  basic_string<> local_198 [20];
  undefined4 local_184 [4];
  basic_string<> local_174 [20];
  undefined4 local_160 [4];
  basic_string<> local_150 [20];
  undefined1 local_13c [32];
  undefined1 local_11c [32];
  undefined1 local_fc [48];
  undefined ***local_cc;
  undefined **local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined **local_98;
  undefined **local_94;
  undefined1 local_90 [16];
  undefined1 local_80 [21];
  undefined1 local_6b;
  int local_68 [3];
  char *local_5c;
  undefined **local_58;
  undefined **local_54;
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  int local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  float local_28;
  int local_24;
  undefined ***local_20;
  undefined1 local_1a;
  undefined1 local_19;
  float local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0042f078;
  local_10 = ExceptionList;
  local_14 = &stack0xfffff6f0;
  local_58 = &PTR_LAB_00430264;
  local_54 = &PTR_LAB_00430254;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00401c80(local_50,&local_19);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00401c80(local_40,&local_1a);
  local_58 = &PTR_LAB_0043024c;
  local_54 = &PTR_LAB_0043023c;
  local_8 = 2;
  FUN_00403020(&local_c4);
  local_c8 = &PTR_FUN_00430230;
  local_8._0_1_ = 3;
  FUN_00401000(local_68);
  local_8._0_1_ = 4;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 4;
  if (param_1 != 2) {
    local_8._0_1_ = uVar2;
    printf(s_Usage__atcmaker_<filename>_004399f4);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  local_51c[0] = 1;
  local_5c = *(char **)(param_2 + 4);
  local_324 = 0;
  local_323 = 1;
  local_322 = 0;
  mysql_init(local_514);
  local_8._0_1_ = 6;
  FUN_00403dc0(local_51c,local_31c);
  local_8._0_1_ = 7;
  cVar3 = FUN_00404c90(local_51c,s_srr2test_00439b30,s_radit_00439b3c,&DAT_00439b44,
                       s_custom47_00439b4c);
  if (cVar3 == '\x01') {
    std::operator<<((basic_ostream<> *)cout_exref,s_Connection_to_Artdb_established_p_00439b00);
    sprintf(local_904,s_SELECT___FROM_physprops_00439ae8);
    std::operator<<(local_314,local_904);
    puVar4 = FUN_00403af0(local_31c,&local_98);
    local_8._0_1_ = 8;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = puVar4 + 1;
    }
    FUN_004058a0(&local_c4,puVar4);
    puVar4[1] = 0;
    local_8 = CONCAT31(local_8._1_3_,7);
    local_98 = &PTR_FUN_00430230;
    FUN_004056f0((int *)&local_94);
    iVar5 = mysql_num_rows(local_c0);
    if (iVar5 == 0) {
      std::operator<<((basic_ostream<> *)cerr_exref,s_No_Enteries_in_physprops_table_00439ac4);
                    // WARNING: Subroutine does not return
      exit(1);
    }
    local_20 = &local_c8;
    local_24 = 0;
    while( true ) {
      iVar5 = (*(code *)*local_c8)();
      if ((local_20 != &local_c8) || (local_24 == iVar5)) break;
      iVar5 = FUN_00402140(&local_24,&local_98);
      local_8._0_1_ = 9;
      FUN_00401d00(local_50,iVar5 + 8);
      FUN_00401f90(local_40,iVar5 + 0x18);
      local_30 = *(int *)(iVar5 + 0x28);
      local_2c = *(undefined1 *)(iVar5 + 0x2c);
      local_2b = *(undefined1 *)(iVar5 + 0x2d);
      local_98 = &PTR_LAB_0043024c;
      local_94 = &PTR_LAB_0043023c;
      local_8._0_1_ = 0xc;
      FUN_00401f10((int)local_90);
      FUN_004020e0((int)local_80);
      local_6b = 0;
      local_8._0_1_ = 0xb;
      FUN_00404610((int)local_80);
      local_8._0_1_ = 10;
      FUN_00401ca0((int)local_90);
      local_cc = &local_94;
      local_8 = CONCAT31(local_8._1_3_,7);
      local_94 = &PTR_LAB_00430254;
      puVar4 = FUN_004042d0(&local_58,local_160,s_sound_00439abc);
      pcVar10 = (code *)puVar4[5];
      if ((code *)puVar4[5] == (code *)0x0) {
        pcVar10 = _C_exref;
      }
      pcVar11 = (code *)local_fc;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        *pcVar11 = cVar1;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != (code)0x0);
      std::basic_string<>::_Tidy(local_150,true);
      puVar4 = FUN_004042d0(&local_58,local_238,s_particle_00439ab0);
      pcVar10 = (code *)puVar4[5];
      if ((code *)puVar4[5] == (code *)0x0) {
        pcVar10 = _C_exref;
      }
      pcVar11 = (code *)local_13c;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        *pcVar11 = cVar1;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != (code)0x0);
      std::basic_string<>::_Tidy(local_228,true);
      puVar4 = FUN_004042d0(&local_58,local_184,s_animation_00439aa4);
      pcVar10 = (code *)puVar4[5];
      if ((code *)puVar4[5] == (code *)0x0) {
        pcVar10 = _C_exref;
      }
      pcVar11 = (code *)local_11c;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        *pcVar11 = cVar1;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != (code)0x0);
      std::basic_string<>::_Tidy(local_174,true);
      puVar4 = FUN_004042d0(&local_58,local_1cc,&DAT_00439a9c);
      local_8._0_1_ = 0xd;
      fVar12 = FUN_00404630(puVar4);
      local_8._0_1_ = 7;
      local_18 = (float)fVar12;
      std::basic_string<>::_Tidy(local_1bc,true);
      puVar4 = FUN_004042d0(&local_58,local_1a8,s_friction_00439a90);
      local_8._0_1_ = 0xe;
      fVar13 = FUN_00404630(puVar4);
      local_28 = (float)fVar13;
      local_8._0_1_ = 7;
      local_18 = local_28;
      std::basic_string<>::_Tidy(local_198,true);
      puVar4 = FUN_004042d0(&local_58,local_214,s_elasticity_00439a84);
      local_8._0_1_ = 0xf;
      fVar13 = FUN_00404630(puVar4);
      local_8 = CONCAT31(local_8._1_3_,7);
      local_18 = (float)fVar13;
      std::basic_string<>::_Tidy(local_204,true);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Sound__00439a7c);
      std::operator<<(pbVar6,local_fc);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Particle__00439a70);
      std::operator<<(pbVar6,local_13c);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Animation__00439a64);
      std::operator<<(pbVar6,local_11c);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Mass__00439a5c);
      std::basic_ostream<>::operator<<(pbVar6,(float)fVar12);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Friction__00439a50);
      std::basic_ostream<>::operator<<(pbVar6,local_28);
      pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,s_Elasticity__00439a40);
      pbVar6 = std::basic_ostream<>::operator<<(pbVar6,(float)fVar13);
      std::endl(pbVar6);
      uVar7 = ftol();
      uVar8 = ftol();
      uVar9 = ftol();
      FUN_00401120(local_68,local_fc,local_13c,local_11c,uVar9,uVar8,uVar7);
      uVar7 = 0;
      while( true ) {
        uVar8 = FUN_00405770(local_30);
        if (uVar8 <= uVar7) break;
        puVar4 = FUN_00402c10(&local_58,local_1f0,uVar7);
        local_8._0_1_ = 0x10;
        pbVar6 = std::operator<<((basic_ostream<> *)cout_exref,&DAT_00439a3c);
        pbVar6 = FUN_004051e0(pbVar6,puVar4);
        std::operator<<(pbVar6,&DAT_00439a38);
        local_8 = CONCAT31(local_8._1_3_,7);
        std::basic_string<>::_Tidy(local_1e0,true);
        uVar7 = uVar7 + 1;
      }
      std::endl((basic_ostream<> *)cout_exref);
      local_24 = local_24 + 1;
    }
    local_8._0_1_ = 6;
    FUN_00402330((int)local_274);
    local_26c[0] = _vftable__exref;
    std::ios_base::~ios_base((ios_base *)local_26c);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_00404b70((int)local_51c);
    local_8 = 4;
    FUN_00401200(local_68,local_5c);
    local_8._0_1_ = 3;
    FUN_00401110(local_68);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_c8 = &PTR_FUN_00430230;
    FUN_004056f0(&local_c4);
    local_8 = 0xffffffff;
    FUN_00402d50(&local_54);
    ExceptionList = local_10;
    return 0;
  }
  std::operator<<((basic_ostream<> *)cerr_exref,s_Cant_connection_to_art_db_00439a1c);
                    // WARNING: Subroutine does not return
  exit(1);
}



undefined1 * Catch_00401a6c(void)

{
  code *pcVar1;
  basic_ostream<> *pbVar2;
  int unaff_EBP;
  basic_string<> *pbVar3;
  
  pcVar1 = cerr_exref;
  pbVar3 = (basic_string<> *)(unaff_EBP + -0xd8);
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  pbVar2 = std::operator<<((basic_ostream<> *)pcVar1,s_Error__00439a14);
  pbVar2 = std::operator<<(pbVar2,pbVar3);
  std::endl(pbVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  std::basic_string<>::_Tidy((basic_string<> *)(unaff_EBP + -0xd8),true);
  return &LAB_00401ab3;
}



void FUN_00401b60(void)

{
                    // WARNING: Could not recover jumptable at 0x00401b65. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_0044345d);
  return;
}



void FUN_00401b70(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00401b80);
  return;
}



void FUN_00401ba0(void)

{
                    // WARNING: Could not recover jumptable at 0x00401ba5. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_0044345c);
  return;
}



void FUN_00401bb0(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00401bc0);
  return;
}



void __thiscall FUN_00401c80(void *this,undefined1 *param_1)

{
  *(undefined1 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  return;
}



void __fastcall FUN_00401ca0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 8);
  for (iVar4 = *(int *)(param_1 + 4); iVar4 != iVar2; iVar4 = iVar4 + 0x10) {
    iVar3 = *(int *)(iVar4 + 4);
    if (iVar3 != 0) {
      cVar1 = *(char *)(iVar3 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_0042da40((char *)(iVar3 + -1));
      }
      else {
        *(char *)(iVar3 + -1) = cVar1 + -1;
      }
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  FUN_0042da40(*(void **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



int __thiscall FUN_00401d00(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  basic_string<> *pbVar3;
  uint uVar4;
  basic_string<> *pbVar5;
  basic_string<> *pbVar6;
  
  if (this != (void *)param_1) {
    pbVar5 = *(basic_string<> **)(param_1 + 4);
    if (pbVar5 == (basic_string<> *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(int *)(param_1 + 8) - (int)pbVar5 >> 4;
    }
    pbVar6 = *(basic_string<> **)((int)this + 4);
    if (pbVar6 == (basic_string<> *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(int *)((int)this + 8) - (int)pbVar6 >> 4;
    }
    if (uVar4 <= uVar1) {
      pbVar3 = *(basic_string<> **)(param_1 + 8);
      for (; pbVar5 != pbVar3; pbVar5 = pbVar5 + 0x10) {
        std::basic_string<>::assign(pbVar6,pbVar5,0,*(uint *)npos_exref);
        pbVar6 = pbVar6 + 0x10;
      }
      pbVar5 = *(basic_string<> **)((int)this + 8);
      for (; pbVar6 != pbVar5; pbVar6 = pbVar6 + 0x10) {
        FUN_00404b10(pbVar6,0);
      }
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
        return (int)this;
      }
      *(int *)((int)this + 8) =
           (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4) * 0x10 + *(int *)((int)this + 4);
      return (int)this;
    }
    if (pbVar5 == (basic_string<> *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(int *)(param_1 + 8) - (int)pbVar5 >> 4;
    }
    if (pbVar6 == (basic_string<> *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(int *)((int)this + 0xc) - (int)pbVar6 >> 4;
    }
    if (uVar4 <= uVar1) {
      if (pbVar6 == (basic_string<> *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)((int)this + 8) - (int)pbVar6 >> 4;
      }
      pbVar3 = pbVar5 + iVar2 * 0x10;
      for (; pbVar5 != pbVar3; pbVar5 = pbVar5 + 0x10) {
        std::basic_string<>::assign(pbVar6,pbVar5,0,*(uint *)npos_exref);
        pbVar6 = pbVar6 + 0x10;
      }
      pbVar5 = *(basic_string<> **)(param_1 + 8);
      pbVar6 = *(basic_string<> **)((int)this + 8);
      for (; pbVar3 != pbVar5; pbVar3 = pbVar3 + 0x10) {
        FUN_004047e0(pbVar6,pbVar3);
        pbVar6 = pbVar6 + 0x10;
      }
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
        return (int)this;
      }
      *(int *)((int)this + 8) =
           (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4) * 0x10 + *(int *)((int)this + 4);
      return (int)this;
    }
    pbVar5 = *(basic_string<> **)((int)this + 8);
    for (; pbVar6 != pbVar5; pbVar6 = pbVar6 + 0x10) {
      std::basic_string<>::_Tidy(pbVar6,true);
    }
    FUN_0042da40(*(void **)((int)this + 4));
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    pbVar3 = operator_new(iVar2 << 4);
    *(basic_string<> **)((int)this + 4) = pbVar3;
    pbVar5 = *(basic_string<> **)(param_1 + 8);
    for (pbVar6 = *(basic_string<> **)(param_1 + 4); pbVar6 != pbVar5; pbVar6 = pbVar6 + 0x10) {
      FUN_004047e0(pbVar3,pbVar6);
      pbVar3 = pbVar3 + 0x10;
    }
    *(basic_string<> **)((int)this + 8) = pbVar3;
    *(basic_string<> **)((int)this + 0xc) = pbVar3;
  }
  return (int)this;
}



// WARNING: Removing unreachable block (ram,0x00401f22)

void __fastcall FUN_00401f10(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar3 = *(int **)(param_1 + 4);
  piVar4 = *(int **)(param_1 + 8);
  if (piVar3 != piVar4) {
    piVar6 = piVar3 + 1;
    do {
      iVar5 = *piVar6;
      if (iVar5 != 0) {
        cVar2 = *(char *)(iVar5 + -1);
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_0042da40((char *)(iVar5 + -1));
        }
        else {
          *(char *)(iVar5 + -1) = cVar2 + -1;
        }
      }
      *piVar6 = 0;
      piVar6[1] = 0;
      piVar6[2] = 0;
      piVar1 = piVar6 + 3;
      piVar6 = piVar6 + 4;
    } while (piVar1 != piVar4);
  }
  *(int **)(param_1 + 8) = piVar3;
  return;
}



int __thiscall FUN_00401f90(void *this,int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  if (this != (void *)param_1) {
    puVar1 = *(undefined1 **)(param_1 + 4);
    if (puVar1 == (undefined1 *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(int *)(param_1 + 8) - (int)puVar1;
    }
    puVar5 = *(undefined1 **)((int)this + 4);
    if (puVar5 == (undefined1 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)((int)this + 8) - (int)puVar5;
    }
    if (uVar6 <= uVar2) {
      puVar4 = *(undefined1 **)(param_1 + 8);
      for (; puVar1 != puVar4; puVar1 = puVar1 + 1) {
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 1;
      }
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
        return (int)this;
      }
      *(int *)((int)this + 8) =
           *(int *)((int)this + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4));
      return (int)this;
    }
    if (puVar1 == (undefined1 *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(int *)(param_1 + 8) - (int)puVar1;
    }
    if (puVar5 == (undefined1 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)((int)this + 0xc) - (int)puVar5;
    }
    if (uVar6 <= uVar2) {
      if (puVar5 == (undefined1 *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)((int)this + 8) - (int)puVar5;
      }
      puVar4 = puVar1 + iVar3;
      for (; puVar1 != puVar4; puVar1 = puVar1 + 1) {
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 1;
      }
      puVar1 = *(undefined1 **)(param_1 + 8);
      puVar5 = *(undefined1 **)((int)this + 8);
      for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {
        if (puVar5 != (undefined1 *)0x0) {
          *puVar5 = *puVar4;
        }
        puVar5 = puVar5 + 1;
      }
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
        return (int)this;
      }
      *(int *)((int)this + 8) =
           *(int *)((int)this + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4));
      return (int)this;
    }
    FUN_0042da40(puVar5);
    if (*(int *)(param_1 + 4) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    }
    if ((int)uVar6 < 0) {
      uVar6 = 0;
    }
    puVar4 = operator_new(uVar6);
    *(undefined1 **)((int)this + 4) = puVar4;
    puVar1 = *(undefined1 **)(param_1 + 8);
    for (puVar5 = *(undefined1 **)(param_1 + 4); puVar5 != puVar1; puVar5 = puVar5 + 1) {
      if (puVar4 != (undefined1 *)0x0) {
        *puVar4 = *puVar5;
      }
      puVar4 = puVar4 + 1;
    }
    *(undefined1 **)((int)this + 8) = puVar4;
    *(undefined1 **)((int)this + 0xc) = puVar4;
  }
  return (int)this;
}



// WARNING: Removing unreachable block (ram,0x004020f0)

void __fastcall FUN_004020e0(int param_1)

{
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  return;
}



void __fastcall FUN_00402100(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00430254;
  return;
}



undefined4 __thiscall FUN_00402140(void *this,undefined4 param_1)

{
  (**(code **)(**(int **)((int)this + 4) + 4))(param_1,*(undefined4 *)this);
  return param_1;
}



basic_string<> * __thiscall FUN_004021a0(void *this,basic_string<> *param_1,int *param_2)

{
  int *piVar1;
  basic_string<> *pbVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  basic_string<> *pbVar6;
  bool bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  basic_string<> *pbVar13;
  code *pcVar14;
  basic_string<> *this_00;
  
  piVar4 = *(int **)((int)this + 8);
  this_00 = param_1;
  if (param_2 != piVar4) {
    iVar12 = (int)param_1 - (int)param_2;
    piVar11 = param_2 + 1;
    do {
      uVar9 = piVar11[1];
      uVar5 = *(uint *)npos_exref;
      uVar10 = uVar9;
      if (uVar5 < uVar9) {
        uVar10 = uVar5;
      }
      if (this_00 == (basic_string<> *)(piVar11 + -1)) {
        std::basic_string<>::erase(this_00,uVar10,uVar5);
        std::basic_string<>::erase(this_00,0,0);
      }
      else {
        if ((uVar10 != 0) && (uVar10 == uVar9)) {
          pcVar8 = (code *)*piVar11;
          if ((code *)*piVar11 == (code *)0x0) {
            pcVar8 = _C_exref;
          }
          if ((byte)pcVar8[-1] < 0xfe) {
            std::basic_string<>::_Tidy(this_00,true);
            pcVar8 = (code *)*piVar11;
            if ((code *)*piVar11 == (code *)0x0) {
              pcVar8 = _C_exref;
            }
            *(code **)(iVar12 + (int)piVar11) = pcVar8;
            *(int *)(iVar12 + 4 + (int)piVar11) = piVar11[1];
            *(int *)(iVar12 + 8 + (int)piVar11) = piVar11[2];
            pcVar8[-1] = (code)((char)pcVar8[-1] + '\x01');
            goto LAB_00402298;
          }
        }
        bVar7 = std::basic_string<>::_Grow(this_00,uVar10,true);
        if (bVar7) {
          pcVar8 = (code *)*piVar11;
          if ((code *)*piVar11 == (code *)0x0) {
            pcVar8 = _C_exref;
          }
          pcVar14 = *(code **)(iVar12 + (int)piVar11);
          for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar14 = pcVar14 + 4;
          }
          for (uVar9 = uVar10 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar14 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar14 = pcVar14 + 1;
          }
          std::basic_string<>::_Eos(this_00,uVar10);
        }
      }
LAB_00402298:
      this_00 = this_00 + 0x10;
      piVar1 = piVar11 + 3;
      piVar11 = piVar11 + 4;
    } while (piVar1 != piVar4);
  }
  pbVar6 = *(basic_string<> **)((int)this + 8);
  if (this_00 != pbVar6) {
    pbVar13 = this_00 + 4;
    do {
      iVar12 = *(int *)pbVar13;
      if (iVar12 != 0) {
        cVar3 = *(char *)(iVar12 + -1);
        if ((cVar3 == '\0') || (cVar3 == -1)) {
          FUN_0042da40((char *)(iVar12 + -1));
        }
        else {
          *(char *)(iVar12 + -1) = cVar3 + -1;
        }
      }
      *(int *)pbVar13 = 0;
      *(int *)(pbVar13 + 4) = 0;
      *(int *)(pbVar13 + 8) = 0;
      pbVar2 = pbVar13 + 0xc;
      pbVar13 = pbVar13 + 0x10;
    } while (pbVar2 != pbVar6);
  }
  *(basic_string<> **)((int)this + 8) = this_00;
  return param_1;
}



void __fastcall FUN_00402330(int param_1)

{
  basic_string<> *pbVar1;
  void *pvVar2;
  void **ppvVar3;
  basic_string<> *pbVar4;
  void *pvVar5;
  _Lockit local_14 [4];
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0042f0bd;
  pbVar1 = *(basic_string<> **)(param_1 + -0xc);
  pbVar4 = *(basic_string<> **)(param_1 + -0x10);
  local_4 = 3;
  ppvVar3 = &local_c;
  local_10 = param_1;
  local_c = ExceptionList;
  for (; ExceptionList = ppvVar3, pbVar4 != pbVar1; pbVar4 = pbVar4 + 0x14) {
    std::basic_string<>::_Tidy(pbVar4,true);
    ppvVar3 = ExceptionList;
  }
  FUN_0042da40(*(void **)(param_1 + -0x10));
  *(undefined4 *)(param_1 + -0x10) = 0;
  *(undefined4 *)(param_1 + -0xc) = 0;
  *(undefined4 *)(param_1 + -8) = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004024d0((void *)(param_1 + -0x24),(undefined4 *)local_14,(int *)**(int **)(param_1 + -0x20),
               *(int **)(param_1 + -0x20));
  FUN_0042da40(*(void **)(param_1 + -0x20));
  *(undefined4 *)(param_1 + -0x20) = 0;
  *(undefined4 *)(param_1 + -0x18) = 0;
  std::_Lockit::_Lockit(local_14);
  pvVar2 = DAT_0044347c;
  DAT_00443480 = DAT_00443480 + -1;
  pvVar5 = (void *)0x0;
  if (DAT_00443480 == 0) {
    DAT_0044347c = (void *)0x0;
    pvVar5 = pvVar2;
  }
  std::_Lockit::~_Lockit(local_14);
  if (pvVar5 != (void *)0x0) {
    FUN_0042da40(pvVar5);
  }
  pbVar1 = *(basic_string<> **)(param_1 + -0x2c);
  pbVar4 = *(basic_string<> **)(param_1 + -0x30);
  local_4._0_1_ = 1;
  for (; pbVar4 != pbVar1; pbVar4 = pbVar4 + 0x10) {
    std::basic_string<>::_Tidy(pbVar4,true);
  }
  FUN_0042da40(*(void **)(param_1 + -0x30));
  *(undefined4 *)(param_1 + -0x30) = 0;
  *(undefined4 *)(param_1 + -0x2c) = 0;
  *(undefined4 *)(param_1 + -0x28) = 0;
  pbVar1 = *(basic_string<> **)(param_1 + -0x3c);
  pbVar4 = *(basic_string<> **)(param_1 + -0x40);
  local_4 = (uint)local_4._1_3_ << 8;
  for (; pbVar4 != pbVar1; pbVar4 = pbVar4 + 0x14) {
    std::basic_string<>::_Tidy(pbVar4,true);
  }
  FUN_0042da40(*(void **)(param_1 + -0x40));
  *(undefined4 *)(param_1 + -0x40) = 0;
  *(undefined4 *)(param_1 + -0x3c) = 0;
  *(undefined4 *)(param_1 + -0x38) = 0;
  local_4 = 0xffffffff;
  std::strstream::~strstream((strstream *)(param_1 + -0x4c));
  ExceptionList = local_c;
  return;
}



void __fastcall FUN_00402490(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_004025b0(iVar2);
  }
  FUN_0042da40(*(void **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



void __thiscall FUN_004024d0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = param_3;
  if (((*(int *)((int)this + 0xc) != 0) &&
      (piVar1 = *(int **)((int)this + 4), param_2 == (int *)*piVar1)) && (param_3 == piVar1)) {
    piVar2 = (int *)piVar1[1];
    if ((int *)piVar1[1] != DAT_0044347c) {
      do {
        FUN_00402a30((int *)piVar2[2]);
        piVar1 = (int *)*piVar2;
        FUN_004025b0((int)(piVar2 + 3));
        FUN_0042da40(piVar2);
        piVar2 = piVar1;
      } while (piVar1 != DAT_0044347c);
    }
    *(int **)(*(int *)((int)this + 4) + 4) = DAT_0044347c;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *param_1 = **(undefined4 **)((int)this + 4);
    return;
  }
  do {
    if (param_2 == piVar2) {
      *param_1 = param_2;
      return;
    }
    if ((int *)param_2[2] == DAT_0044347c) {
      piVar1 = (int *)param_2[1];
      piVar3 = param_2;
      if (param_2 == (int *)piVar1[2]) {
        do {
          piVar3 = piVar1;
          piVar1 = (int *)piVar3[1];
        } while (piVar3 == (int *)piVar1[2]);
      }
      if ((int *)piVar3[2] != piVar1) goto LAB_00402586;
    }
    else {
      piVar1 = (int *)FUN_00402a80((int *)param_2[2]);
LAB_00402586:
      piVar3 = piVar1;
    }
    FUN_004025f0(this,&param_3,param_2);
    param_2 = piVar3;
  } while( true );
}



void __fastcall FUN_004025b0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



void __thiscall FUN_004025f0(void *this,undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *local_c;
  _Lockit local_4 [4];
  
  piVar4 = param_2;
  FUN_00402aa0((int *)&param_2);
  piVar9 = (int *)*piVar4;
  piVar7 = piVar4 + 2;
  local_c = piVar4;
  piVar8 = piVar7;
  if (piVar9 == DAT_0044347c) {
    piVar9 = (int *)*piVar7;
  }
  else {
    piVar2 = (int *)*piVar7;
    if (piVar2 != DAT_0044347c) {
      local_c = piVar2;
      for (piVar8 = (int *)*piVar2; piVar8 != DAT_0044347c; piVar8 = (int *)*piVar8) {
        local_c = piVar8;
      }
      piVar9 = (int *)local_c[2];
      piVar8 = local_c + 2;
    }
  }
  piVar2 = local_c;
  std::_Lockit::_Lockit(local_4);
  if (local_c == piVar4) {
    piVar9[1] = local_c[1];
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar4) {
      *(int **)(*(int *)((int)this + 4) + 4) = piVar9;
    }
    else {
      piVar8 = (int *)piVar4[1];
      if ((int *)*piVar8 == piVar4) {
        *piVar8 = (int)piVar9;
      }
      else {
        piVar8[2] = (int)piVar9;
      }
    }
    piVar8 = *(int **)((int)this + 4);
    if ((int *)*piVar8 == piVar4) {
      if ((int *)*piVar7 == DAT_0044347c) {
        *piVar8 = piVar4[1];
      }
      else {
        piVar2 = (int *)*piVar9;
        piVar7 = piVar9;
        while (piVar6 = piVar2, piVar6 != DAT_0044347c) {
          piVar7 = piVar6;
          piVar2 = (int *)*piVar6;
        }
        *piVar8 = (int)piVar7;
      }
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar4) {
      if ((int *)*piVar4 == DAT_0044347c) {
        piVar7 = (int *)piVar4[1];
      }
      else {
        piVar8 = (int *)piVar9[2];
        piVar7 = piVar9;
        while (piVar4 = piVar8, piVar4 != DAT_0044347c) {
          piVar7 = piVar4;
          piVar8 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar7;
    }
  }
  else {
    *(int **)(*piVar4 + 4) = local_c;
    *local_c = *piVar4;
    if (local_c == (int *)*piVar7) {
      piVar9[1] = (int)local_c;
    }
    else {
      piVar9[1] = local_c[1];
      *(int **)local_c[1] = piVar9;
      *piVar8 = *piVar7;
      *(int **)(*piVar7 + 4) = local_c;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar4) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_c;
    }
    else {
      piVar7 = (int *)piVar4[1];
      if ((int *)*piVar7 == piVar4) {
        *piVar7 = (int)local_c;
      }
      else {
        piVar7[2] = (int)local_c;
      }
    }
    local_c = piVar4;
    piVar2[1] = piVar4[1];
    iVar3 = piVar2[8];
    piVar2[8] = piVar4[8];
    piVar4[8] = iVar3;
  }
  if (local_c[8] == 1) {
    if (piVar9 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        if (piVar9[8] != 1) break;
        piVar7 = *(int **)piVar9[1];
        if (piVar9 == piVar7) {
          piVar7 = (int *)((undefined4 *)piVar9[1])[2];
          if (piVar7[8] == 0) {
            piVar7[8] = 1;
            *(undefined4 *)(piVar9[1] + 0x20) = 0;
            iVar3 = piVar9[1];
            piVar7 = *(int **)(iVar3 + 8);
            *(int *)(iVar3 + 8) = *piVar7;
            if ((int *)*piVar7 != DAT_0044347c) {
              ((int *)*piVar7)[1] = iVar3;
            }
            piVar7[1] = *(int *)(iVar3 + 4);
            if (iVar3 == *(int *)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
            }
            else {
              piVar8 = *(int **)(iVar3 + 4);
              if (iVar3 == *piVar8) {
                *piVar8 = (int)piVar7;
              }
              else {
                piVar8[2] = (int)piVar7;
              }
            }
            *piVar7 = iVar3;
            *(int **)(iVar3 + 4) = piVar7;
            piVar7 = *(int **)(piVar9[1] + 8);
          }
          if ((*(int *)(*piVar7 + 0x20) != 1) || (*(int *)(piVar7[2] + 0x20) != 1)) {
            if (*(int *)(piVar7[2] + 0x20) == 1) {
              *(undefined4 *)(*piVar7 + 0x20) = 1;
              iVar3 = *piVar7;
              piVar7[8] = 0;
              *piVar7 = *(int *)(iVar3 + 8);
              if (*(int **)(iVar3 + 8) != DAT_0044347c) {
                (*(int **)(iVar3 + 8))[1] = (int)piVar7;
              }
              *(int *)(iVar3 + 4) = piVar7[1];
              if (piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) {
                *(int *)(*(int *)((int)this + 4) + 4) = iVar3;
              }
              else {
                piVar8 = (int *)piVar7[1];
                if (piVar7 == (int *)piVar8[2]) {
                  piVar8[2] = iVar3;
                }
                else {
                  *piVar8 = iVar3;
                }
              }
              *(int **)(iVar3 + 8) = piVar7;
              piVar7[1] = iVar3;
              piVar7 = *(int **)(piVar9[1] + 8);
            }
            piVar7[8] = *(int *)(piVar9[1] + 0x20);
            *(undefined4 *)(piVar9[1] + 0x20) = 1;
            *(undefined4 *)(piVar7[2] + 0x20) = 1;
            piVar7 = (int *)piVar9[1];
            piVar8 = (int *)piVar7[2];
            piVar7[2] = *piVar8;
            if ((int *)*piVar8 != DAT_0044347c) {
              ((int *)*piVar8)[1] = (int)piVar7;
            }
            piVar8[1] = piVar7[1];
            if (piVar7 == (int *)*(int *)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar8;
              *piVar8 = (int)piVar7;
            }
            else {
              piVar4 = (int *)piVar7[1];
              if (piVar7 == (int *)*piVar4) {
                *piVar4 = (int)piVar8;
                *piVar8 = (int)piVar7;
              }
              else {
                piVar4[2] = (int)piVar8;
                *piVar8 = (int)piVar7;
              }
            }
LAB_004029c0:
            piVar7[1] = (int)piVar8;
            break;
          }
        }
        else {
          if (piVar7[8] == 0) {
            piVar7[8] = 1;
            *(undefined4 *)(piVar9[1] + 0x20) = 0;
            piVar7 = (int *)piVar9[1];
            iVar3 = *piVar7;
            *piVar7 = *(int *)(iVar3 + 8);
            if (*(int **)(iVar3 + 8) != DAT_0044347c) {
              (*(int **)(iVar3 + 8))[1] = (int)piVar7;
            }
            *(int *)(iVar3 + 4) = piVar7[1];
            if (piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int *)(*(int *)((int)this + 4) + 4) = iVar3;
            }
            else {
              piVar8 = (int *)piVar7[1];
              if (piVar7 == (int *)piVar8[2]) {
                piVar8[2] = iVar3;
              }
              else {
                *piVar8 = iVar3;
              }
            }
            *(int **)(iVar3 + 8) = piVar7;
            piVar7[1] = iVar3;
            piVar7 = *(int **)piVar9[1];
          }
          if ((*(int *)(piVar7[2] + 0x20) != 1) || (*(int *)(*piVar7 + 0x20) != 1)) {
            if (*(int *)(*piVar7 + 0x20) == 1) {
              *(undefined4 *)(piVar7[2] + 0x20) = 1;
              piVar8 = (int *)piVar7[2];
              piVar7[8] = 0;
              piVar7[2] = *piVar8;
              if ((int *)*piVar8 != DAT_0044347c) {
                ((int *)*piVar8)[1] = (int)piVar7;
              }
              piVar8[1] = piVar7[1];
              if (piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) {
                *(int **)(*(int *)((int)this + 4) + 4) = piVar8;
              }
              else {
                piVar4 = (int *)piVar7[1];
                if (piVar7 == (int *)*piVar4) {
                  *piVar4 = (int)piVar8;
                }
                else {
                  piVar4[2] = (int)piVar8;
                }
              }
              *piVar8 = (int)piVar7;
              piVar7[1] = (int)piVar8;
              piVar7 = *(int **)piVar9[1];
            }
            piVar7[8] = *(int *)(piVar9[1] + 0x20);
            *(undefined4 *)(piVar9[1] + 0x20) = 1;
            *(undefined4 *)(*piVar7 + 0x20) = 1;
            piVar7 = (int *)piVar9[1];
            piVar8 = (int *)*piVar7;
            *piVar7 = piVar8[2];
            if ((int *)piVar8[2] != DAT_0044347c) {
              ((int *)piVar8[2])[1] = (int)piVar7;
            }
            piVar8[1] = piVar7[1];
            if (piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar8;
            }
            else {
              puVar5 = (undefined4 *)piVar7[1];
              if (piVar7 == (int *)puVar5[2]) {
                puVar5[2] = piVar8;
              }
              else {
                *puVar5 = piVar8;
              }
            }
            piVar8[2] = (int)piVar7;
            goto LAB_004029c0;
          }
        }
        piVar7[8] = 0;
        piVar9 = (int *)piVar9[1];
      } while (piVar9 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    piVar9[8] = 1;
  }
  std::_Lockit::~_Lockit(local_4);
  iVar3 = local_c[4];
  if (iVar3 != 0) {
    cVar1 = *(char *)(iVar3 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar3 + -1));
    }
    else {
      *(char *)(iVar3 + -1) = cVar1 + -1;
    }
  }
  local_c[4] = 0;
  local_c[5] = 0;
  local_c[6] = 0;
  FUN_0042da40(local_c);
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  *param_1 = param_2;
  return;
}



void FUN_00402a30(int *param_1)

{
  int *piVar1;
  
  if (param_1 != DAT_0044347c) {
    do {
      FUN_00402a30((int *)param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_004025b0((int)(param_1 + 3));
      FUN_0042da40(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_0044347c);
  }
  return;
}



void __cdecl FUN_00402a80(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)*param_1; puVar1 != DAT_0044347c; puVar1 = (undefined4 *)*puVar1) {
  }
  return;
}



void __fastcall FUN_00402aa0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(*param_1 + 8);
  if (puVar1 == DAT_0044347c) {
    iVar3 = *(int *)(*param_1 + 4);
    if (*param_1 == *(int *)(iVar3 + 8)) {
      do {
        *param_1 = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
      } while (*param_1 == *(int *)(iVar3 + 8));
    }
    if (*(int *)(*param_1 + 8) != iVar3) {
      *param_1 = iVar3;
    }
    return;
  }
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != DAT_0044347c; puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_1 = (int)puVar1;
  return;
}



void __fastcall FUN_00402af0(void *param_1)

{
  int *piVar1;
  int *piVar2;
  int *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)((int)param_1 + 4);
  local_c = (int *)*piVar1;
  piVar2 = local_c;
  if (*(int *)((int)param_1 + 0xc) == 0) {
    while (local_c = piVar2, piVar2 != piVar1) {
      FUN_00402aa0((int *)&local_c);
      FUN_004025f0(param_1,&local_4,piVar2);
      piVar2 = local_c;
    }
  }
  else {
    piVar2 = (int *)piVar1[1];
    if ((int *)piVar1[1] != DAT_0044347c) {
      do {
        FUN_00402a30((int *)piVar2[2]);
        piVar1 = (int *)*piVar2;
        FUN_00404af0(piVar2 + 3,0);
        FUN_0042da40(piVar2);
        piVar2 = piVar1;
      } while (piVar1 != DAT_0044347c);
    }
    *(int **)(*(int *)((int)param_1 + 4) + 4) = DAT_0044347c;
    *(undefined4 *)((int)param_1 + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
    *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
    FUN_00402be0(param_1,&local_8);
  }
  FUN_0042da40(*(void **)((int)param_1 + 4));
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 0xc) = 0;
  std::_Lockit::_Lockit((_Lockit *)&local_c);
  piVar1 = DAT_0044347c;
  DAT_00443480 = DAT_00443480 + -1;
  piVar2 = (int *)0x0;
  if (DAT_00443480 == 0) {
    DAT_0044347c = (int *)0x0;
    piVar2 = piVar1;
  }
  std::_Lockit::~_Lockit((_Lockit *)&local_c);
  if (piVar2 != (int *)0x0) {
    FUN_0042da40(piVar2);
  }
  return;
}



void __thiscall FUN_00402be0(void *this,undefined4 *param_1)

{
  *param_1 = **(undefined4 **)((int)this + 4);
  return;
}



undefined4 * __thiscall FUN_00402c10(void *this,undefined4 *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  basic_string<> local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  basic_string<> local_2c [16];
  basic_string<> local_1c [8];
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f0e1;
  local_c = ExceptionList;
  if (*(char *)((int)this + 0x2d) != '\0') {
    ExceptionList = &local_c;
    (**(code **)(*(int *)this + 4))(param_1,param_2);
    ExceptionList = pvStack_14;
    return param_1;
  }
  if (*(char *)((int)this + 0x2c) == '\0') {
    *param_1 = &DAT_00443484;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    *(basic_string<> *)(param_1 + 4) = param_1._0_1_;
    return param_1;
  }
  local_3c[0] = param_1._0_1_;
  uVar2 = 0xffffffff;
  pcVar3 = s_Row_not_initialized_00439b58;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  ExceptionList = &local_c;
  std::basic_string<>::assign(local_3c,s_Row_not_initialized_00439b58,~uVar2 - 1);
  local_2c[0] = local_3c[0];
  local_4 = 0;
  std::basic_string<>::_Tidy(local_2c,false);
  std::basic_string<>::assign(local_2c,local_3c,0,*(uint *)npos_exref);
  local_4 = 0xffffffff;
  std::basic_string<>::_Tidy(local_3c,true);
  local_4 = 1;
  local_1c[0] = local_2c[0];
  std::basic_string<>::_Tidy(local_1c,false);
  std::basic_string<>::assign(local_1c,local_2c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_004366d4);
}



// WARNING: Removing unreachable block (ram,0x00402d91)
// WARNING: Removing unreachable block (ram,0x00402dd6)

void __fastcall FUN_00402d50(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  basic_string<> *pbVar3;
  void *this;
  basic_string<> *this_00;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_0042f12e;
  ExceptionList = &local_c;
  param_1[-1] = &PTR_LAB_0043024c;
  *param_1 = &PTR_LAB_0043023c;
  pvVar1 = (void *)param_1[2];
  local_4 = 2;
  pvVar2 = (void *)param_1[3];
  for (this = pvVar1; this != pvVar2; this = (void *)((int)this + 0x10)) {
    FUN_00404b10(this,0);
  }
  param_1[3] = pvVar1;
  param_1[7] = param_1[6];
  *(undefined1 *)((int)param_1 + 0x29) = 0;
  FUN_0042da40((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  pbVar3 = (basic_string<> *)param_1[3];
  this_00 = (basic_string<> *)param_1[2];
  local_4 = local_4 & 0xffffff00;
  for (; this_00 != pbVar3; this_00 = this_00 + 0x10) {
    std::basic_string<>::_Tidy(this_00,true);
  }
  FUN_0042da40((void *)param_1[2]);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined ***)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)param_1) = &PTR_LAB_00430254;
  ExceptionList = local_c;
  return;
}



undefined4 * __thiscall FUN_00402e60(void *this,byte param_1)

{
  FUN_00402d50(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40((void *)((int)this + -4));
  }
  return (undefined4 *)((int)this + -4);
}



basic_string<> * __thiscall FUN_00402e90(void *this,basic_string<> *param_1)

{
  bool bVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  void *_Dst;
  uint uVar5;
  code *pcVar6;
  
  *(basic_string<> *)this = *param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  uVar5 = *(uint *)npos_exref;
  uVar2 = *(uint *)(param_1 + 8);
  uVar4 = uVar2;
  if (uVar5 < uVar2) {
    uVar4 = uVar5;
  }
  if (this == param_1) {
    if (uVar4 != 0) {
      std::_Xran();
    }
    std::basic_string<>::_Split(this);
    uVar2 = *(int *)((int)this + 8) - uVar4;
    if (uVar2 < uVar5) {
      uVar5 = uVar2;
    }
    if (uVar5 != 0) {
      _Dst = (void *)(uVar4 + *(int *)((int)this + 4));
      memmove(_Dst,(void *)((int)_Dst + uVar5),uVar2 - uVar5);
      uVar5 = *(int *)((int)this + 8) - uVar5;
      bVar1 = std::basic_string<>::_Grow(this,uVar5,false);
      if (bVar1) {
        std::basic_string<>::_Eos(this,uVar5);
      }
    }
    std::basic_string<>::_Split(this);
    return this;
  }
  if ((uVar4 != 0) && (uVar4 == uVar2)) {
    pcVar3 = *(code **)(param_1 + 4);
    if (*(code **)(param_1 + 4) == (code *)0x0) {
      pcVar3 = _C_exref;
    }
    if ((byte)pcVar3[-1] < 0xfe) {
      std::basic_string<>::_Tidy(this,true);
      pcVar3 = *(code **)(param_1 + 4);
      if (*(code **)(param_1 + 4) == (code *)0x0) {
        pcVar3 = _C_exref;
      }
      *(code **)((int)this + 4) = pcVar3;
      *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
      pcVar3[-1] = (code)((char)pcVar3[-1] + '\x01');
      return this;
    }
  }
  bVar1 = std::basic_string<>::_Grow(this,uVar4,true);
  if (bVar1) {
    pcVar3 = *(code **)(param_1 + 4);
    if (*(code **)(param_1 + 4) == (code *)0x0) {
      pcVar3 = _C_exref;
    }
    pcVar6 = *(code **)((int)this + 4);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar6 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar6 = pcVar6 + 1;
    }
    *(uint *)((int)this + 8) = uVar4;
    *(undefined1 *)(uVar4 + *(int *)((int)this + 4)) = 0;
  }
  return this;
}



void __fastcall FUN_00402fc0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



void __fastcall FUN_00403020(undefined4 *param_1)

{
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = param_1;
  param_1[5] = &PTR_LAB_0043026c;
  *(undefined1 *)(param_1 + 7) = local_1;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  return;
}



void __fastcall FUN_00403060(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430230;
  FUN_004056f0(param_1 + 1);
  return;
}



void __fastcall FUN_00403070(int param_1)

{
  mysql_num_rows(*(undefined4 *)(param_1 + 8));
  return;
}



undefined4 * __thiscall FUN_00403080(void *this,undefined4 *param_1,undefined4 param_2)

{
  mysql_data_seek(*(undefined4 *)((int)this + 8),param_2,0);
  FUN_004030c0(this,param_1);
  return param_1;
}



undefined4 * __thiscall FUN_004030c0(void *this,undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 extraout_ECX;
  char *pcVar8;
  basic_string<> local_3c [4];
  char *local_38;
  basic_string<> local_2c [16];
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f162;
  local_c = ExceptionList;
  if (*(int *)((int)this + 8) == 0) {
    ExceptionList = &local_c;
    if (*(char *)((int)this + 0xc) != '\0') {
      local_3c[0] = param_1._0_1_;
      ExceptionList = &local_c;
      std::basic_string<>::_Tidy(local_3c,false);
      uVar6 = 0xffffffff;
      pcVar8 = s_Results_not_fetched_00439b74;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6 - 1;
      bVar3 = std::basic_string<>::_Grow(local_3c,uVar6,true);
      if (bVar3) {
        pcVar8 = s_Results_not_fetched_00439b74;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)local_38 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          local_38 = local_38 + 4;
        }
        for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *local_38 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          local_38 = local_38 + 1;
        }
        std::basic_string<>::_Eos(local_3c,uVar6);
      }
      local_4 = 0;
      local_2c[0] = local_3c[0];
      std::basic_string<>::_Tidy(local_2c,false);
      std::basic_string<>::assign(local_2c,local_3c,0,*(uint *)npos_exref);
      local_4 = 0xffffffff;
      std::basic_string<>::_Tidy(local_3c,true);
      local_1c[0] = local_2c[0];
      local_4 = 1;
      std::basic_string<>::_Tidy(local_1c,false);
      std::basic_string<>::assign(local_1c,local_2c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_004366d4);
    }
  }
  else {
    ExceptionList = &local_c;
    piVar4 = (int *)mysql_fetch_row(*(int *)((int)this + 8));
    iVar5 = mysql_fetch_lengths(*(undefined4 *)((int)this + 8));
    puVar2 = param_1;
    if ((piVar4 != (int *)0x0) && (iVar5 != 0)) {
      FUN_004032f0(param_1,piVar4,(int)this + 4,iVar5,
                   CONCAT31((int3)((uint)extraout_ECX >> 8),*(undefined1 *)((int)this + 0xc)));
      ExceptionList = local_c;
      return puVar2;
    }
    if (*(char *)((int)this + 0xc) != '\0') {
      local_2c[0] = param_1._0_1_;
      std::basic_string<>::_Tidy(local_2c,false);
      uVar6 = 0xffffffff;
      pcVar8 = s_Bad_row_00439b6c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      std::basic_string<>::assign(local_2c,s_Bad_row_00439b6c,~uVar6 - 1);
      local_4 = 2;
      std::basic_string<>::basic_string<>(local_1c,local_2c);
      local_4 = 0xffffffff;
      std::basic_string<>::_Tidy(local_2c,true);
      local_4 = 3;
      std::basic_string<>::basic_string<>(local_3c,local_1c);
                    // WARNING: Subroutine does not return
      _CxxThrowException(local_3c,(ThrowInfo *)&DAT_004366d4);
    }
  }
  puVar2 = param_1;
  *param_1 = &PTR_LAB_00430264;
  param_1[1] = &PTR_LAB_00430254;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  *(basic_string<> *)(param_1 + 2) = param_1._0_1_;
  FUN_00401c80(param_1 + 6,(undefined1 *)&param_1);
  *puVar2 = &PTR_LAB_0043024c;
  puVar2[1] = &PTR_LAB_0043023c;
  ExceptionList = local_c;
  return puVar2;
}



undefined4 * __thiscall FUN_004032f0(void *this,int *param_1,uint param_2,int param_3,uint param_4)

{
  basic_string<> *this_00;
  basic_string<> *this_01;
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  basic_string<> local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  basic_string<> local_2c [16];
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f1db;
  local_c = ExceptionList;
  bVar3 = false;
  bVar2 = false;
  ExceptionList = &local_c;
  *(undefined ***)((int)this + 4) = &PTR_LAB_00430254;
  this_00 = (basic_string<> *)((int)this + 8);
  *this_00 = param_4._0_1_;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  this_01 = (basic_string<> *)((int)this + 0x18);
  *this_01 = param_4._0_1_;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  *(uint *)((int)this + 0x28) = param_2;
  *(basic_string<> *)((int)this + 0x2c) = param_4._0_1_;
  *(undefined1 *)((int)this + 0x2d) = 0;
  *(undefined ***)this = &PTR_LAB_0043024c;
  *(undefined ***)((int)this + 4) = &PTR_LAB_0043023c;
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if (param_4._0_1_ != (basic_string<>)0x0) {
      local_1c[0] = param_4._0_1_;
      std::basic_string<>::_Tidy(local_1c,false);
      uVar5 = 0xffffffff;
      pcVar6 = s_ROW_or_RES_is_NULL_00439b88;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      std::basic_string<>::assign(local_1c,s_ROW_or_RES_is_NULL_00439b88,~uVar5 - 1);
      local_4._0_1_ = 3;
      std::basic_string<>::basic_string<>(local_2c,local_1c);
      local_4._0_1_ = 2;
      std::basic_string<>::_Tidy(local_1c,true);
      local_4 = CONCAT31(local_4._1_3_,4);
      std::basic_string<>::basic_string<>(local_3c,local_2c);
                    // WARNING: Subroutine does not return
      _CxxThrowException(local_3c,(ThrowInfo *)&DAT_004366d4);
    }
  }
  else {
    FUN_004021a0(this_00,*(basic_string<> **)((int)this + 0xc),*(int **)((int)this + 0x10));
    FUN_00403aa0(this_01,*(undefined1 **)((int)this + 0x1c),*(undefined1 **)((int)this + 0x20));
    *(undefined1 *)((int)this + 0x2d) = 1;
    param_2 = 0;
    iVar4 = FUN_00405770(*(int *)((int)this + 0x28));
    if (iVar4 != 0) {
      iVar4 = param_3 - (int)param_1;
      do {
        local_3c[0] = param_4._0_1_;
        std::basic_string<>::_Tidy(local_3c,false);
        local_4._0_1_ = 5;
        pcVar6 = (char *)*param_1;
        if (pcVar6 == (char *)0x0) {
          local_2c[0] = param_4._0_1_;
          std::basic_string<>::_Tidy(local_2c,false);
          uVar5 = 0xffffffff;
          pcVar6 = &DAT_00443484;
          do {
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          std::basic_string<>::assign(local_2c,&DAT_00443484,~uVar5 - 1);
          bVar2 = true;
          local_4 = 7;
          std::basic_string<>::assign(local_3c,local_2c,0,*(uint *)npos_exref);
        }
        else {
          param_4 = *(uint *)(iVar4 + (int)param_1);
          local_1c[0] = param_4._0_1_;
          std::basic_string<>::_Tidy(local_1c,false);
          std::basic_string<>::assign(local_1c,pcVar6,param_4);
          bVar3 = true;
          local_4 = CONCAT31(local_4._1_3_,6);
          std::basic_string<>::assign(local_3c,local_1c,0,*(uint *)npos_exref);
        }
        local_4 = 6;
        if (bVar2) {
          bVar2 = false;
          std::basic_string<>::_Tidy(local_2c,true);
        }
        local_4 = 5;
        if (bVar3) {
          bVar3 = false;
          std::basic_string<>::_Tidy(local_1c,true);
        }
        FUN_00403620(this_00,*(basic_string<> **)((int)this + 0x10),1,local_3c);
        param_4 = CONCAT31(param_4._1_3_,*param_1 == 0);
        FUN_004038d0(this_01,*(undefined1 **)((int)this + 0x20),1,(undefined1 *)&param_4);
        local_4._0_1_ = 2;
        if (local_38 != 0) {
          cVar1 = *(char *)(local_38 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_0042da40((char *)(local_38 + -1));
          }
          else {
            *(char *)(local_38 + -1) = cVar1 + -1;
          }
        }
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
        uVar5 = FUN_00405770(*(int *)((int)this + 0x28));
      } while (param_2 < uVar5);
    }
  }
  ExceptionList = local_c;
  return this;
}



void __thiscall
FUN_00403620(void *this,basic_string<> *param_1,uint param_2,basic_string<> *param_3)

{
  basic_string<> *pbVar1;
  uint uVar2;
  int iVar3;
  basic_string<> *pbVar4;
  int iVar5;
  basic_string<> *pbVar6;
  basic_string<> *pbVar7;
  
  pbVar6 = *(basic_string<> **)((int)this + 8);
  if (param_2 <= (uint)(*(int *)((int)this + 0xc) - (int)pbVar6 >> 4)) {
    if (param_2 <= (uint)((int)pbVar6 - (int)param_1 >> 4)) {
      if (param_2 != 0) {
        pbVar7 = pbVar6;
        for (pbVar4 = pbVar6 + param_2 * -0x10; pbVar4 != pbVar6; pbVar4 = pbVar4 + 0x10) {
          FUN_004047e0(pbVar7,pbVar4);
          pbVar7 = pbVar7 + 0x10;
        }
        pbVar6 = *(basic_string<> **)((int)this + 8);
        pbVar7 = pbVar6 + param_2 * -0x10;
        while (param_1 != pbVar7) {
          pbVar7 = pbVar7 + -0x10;
          pbVar6 = pbVar6 + -0x10;
          std::basic_string<>::assign(pbVar6,pbVar7,0,*(uint *)npos_exref);
        }
        pbVar6 = param_1 + param_2 * 0x10;
        for (; param_1 != pbVar6; param_1 = param_1 + 0x10) {
          std::basic_string<>::assign(param_1,param_3,0,*(uint *)npos_exref);
        }
        *(int *)((int)this + 8) = *(int *)((int)this + 8) + param_2 * 0x10;
      }
      return;
    }
    for (pbVar7 = param_1; pbVar7 != pbVar6; pbVar7 = pbVar7 + 0x10) {
      FUN_004047e0(pbVar7 + param_2 * 0x10,pbVar7);
    }
    pbVar6 = *(basic_string<> **)((int)this + 8);
    for (iVar5 = param_2 - ((int)pbVar6 - (int)param_1 >> 4); iVar5 != 0; iVar5 = iVar5 + -1) {
      FUN_004047e0(pbVar6,param_3);
      pbVar6 = pbVar6 + 0x10;
    }
    pbVar6 = *(basic_string<> **)((int)this + 8);
    for (; param_1 != pbVar6; param_1 = param_1 + 0x10) {
      std::basic_string<>::assign(param_1,param_3,0,*(uint *)npos_exref);
    }
    *(uint *)((int)this + 8) = *(int *)((int)this + 8) + param_2 * 0x10;
    return;
  }
  iVar5 = *(int *)((int)this + 4);
  if ((iVar5 == 0) || (uVar2 = (int)pbVar6 - iVar5 >> 4, uVar2 <= param_2)) {
    uVar2 = param_2;
  }
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (int)pbVar6 - iVar5 >> 4;
  }
  iVar5 = uVar2 + iVar5;
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = 0;
  }
  pbVar4 = operator_new(iVar3 << 4);
  pbVar7 = pbVar4;
  for (pbVar6 = *(basic_string<> **)((int)this + 4); uVar2 = param_2, pbVar1 = pbVar7,
      pbVar6 != param_1; pbVar6 = pbVar6 + 0x10) {
    FUN_004047e0(pbVar7,pbVar6);
    pbVar7 = pbVar7 + 0x10;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    FUN_004047e0(pbVar1,param_3);
    pbVar1 = pbVar1 + 0x10;
  }
  pbVar6 = *(basic_string<> **)((int)this + 8);
  if (param_1 != pbVar6) {
    iVar3 = param_2 * 0x10 - (int)param_1;
    do {
      FUN_004047e0(param_1 + (int)(pbVar7 + iVar3),param_1);
      param_1 = param_1 + 0x10;
    } while (param_1 != pbVar6);
  }
  pbVar6 = *(basic_string<> **)((int)this + 8);
  for (pbVar7 = *(basic_string<> **)((int)this + 4); pbVar7 != pbVar6; pbVar7 = pbVar7 + 0x10) {
    std::basic_string<>::_Tidy(pbVar7,true);
  }
  FUN_0042da40(*(void **)((int)this + 4));
  iVar3 = *(int *)((int)this + 4);
  *(basic_string<> **)((int)this + 0xc) = pbVar4 + iVar5 * 0x10;
  if (iVar3 != 0) {
    *(basic_string<> **)((int)this + 4) = pbVar4;
    *(basic_string<> **)((int)this + 8) =
         pbVar4 + ((*(int *)((int)this + 8) - iVar3 >> 4) + param_2) * 0x10;
    return;
  }
  *(basic_string<> **)((int)this + 4) = pbVar4;
  *(basic_string<> **)((int)this + 8) = pbVar4 + param_2 * 0x10;
  return;
}



void __thiscall FUN_004038d0(void *this,undefined1 *param_1,uint param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  puVar6 = *(undefined1 **)((int)this + 8);
  if (param_2 <= (uint)(*(int *)((int)this + 0xc) - (int)puVar6)) {
    if ((uint)((int)puVar6 - (int)param_1) < param_2) {
      puVar7 = param_1 + param_2;
      if (param_1 != puVar6) {
        puVar5 = puVar7 + -param_2;
        do {
          if (puVar7 != (undefined1 *)0x0) {
            *puVar7 = *puVar5;
          }
          puVar7 = puVar7 + 1;
          puVar5 = puVar5 + 1;
        } while (puVar5 != puVar6);
      }
      puVar6 = *(undefined1 **)((int)this + 8);
      for (puVar7 = param_1 + (param_2 - (int)puVar6); puVar7 != (undefined1 *)0x0;
          puVar7 = puVar7 + -1) {
        if (puVar6 != (undefined1 *)0x0) {
          *puVar6 = *param_3;
        }
        puVar6 = puVar6 + 1;
      }
      puVar6 = *(undefined1 **)((int)this + 8);
      for (; param_1 != puVar6; param_1 = param_1 + 1) {
        *param_1 = *param_3;
      }
    }
    else {
      if (param_2 == 0) {
        return;
      }
      puVar7 = puVar6;
      for (puVar5 = puVar6 + -param_2; puVar5 != puVar6; puVar5 = puVar5 + 1) {
        if (puVar7 != (undefined1 *)0x0) {
          *puVar7 = *puVar5;
        }
        puVar7 = puVar7 + 1;
      }
      puVar6 = *(undefined1 **)((int)this + 8);
      for (puVar7 = puVar6 + -param_2; param_1 != puVar7; puVar7 = puVar7 + -1) {
        puVar6 = puVar6 + -1;
        *puVar6 = puVar7[-1];
      }
      puVar6 = param_1 + param_2;
      for (; param_1 != puVar6; param_1 = param_1 + 1) {
        *param_1 = *param_3;
      }
    }
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + param_2;
    return;
  }
  iVar2 = *(int *)((int)this + 4);
  if ((iVar2 == 0) || (uVar3 = (int)puVar6 - iVar2, (uint)((int)puVar6 - iVar2) <= param_2)) {
    uVar3 = param_2;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)puVar6 - iVar2;
  }
  uVar3 = iVar2 + uVar3;
  uVar4 = uVar3;
  if ((int)uVar3 < 0) {
    uVar4 = 0;
  }
  puVar5 = operator_new(uVar4);
  puVar7 = puVar5;
  for (puVar6 = *(undefined1 **)((int)this + 4); uVar4 = param_2, puVar1 = puVar7, puVar6 != param_1
      ; puVar6 = puVar6 + 1) {
    if (puVar7 != (undefined1 *)0x0) {
      *puVar7 = *puVar6;
    }
    puVar7 = puVar7 + 1;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = *param_3;
    }
    puVar1 = puVar1 + 1;
  }
  puVar1 = *(undefined1 **)((int)this + 8);
  puVar6 = puVar7 + param_2;
  if (param_1 != puVar1) {
    puVar7 = param_1 + (int)(puVar6 + (-param_2 - (int)puVar7));
    do {
      if (puVar6 != (undefined1 *)0x0) {
        *puVar6 = *puVar7;
      }
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (puVar7 != puVar1);
  }
  FUN_0042da40(*(void **)((int)this + 4));
  *(undefined1 **)((int)this + 0xc) = puVar5 + uVar3;
  iVar2 = *(int *)((int)this + 4);
  if (iVar2 != 0) {
    *(undefined1 **)((int)this + 4) = puVar5;
    *(undefined1 **)((int)this + 8) = puVar5 + param_2 + (*(int *)((int)this + 8) - iVar2);
    return;
  }
  *(undefined1 **)((int)this + 4) = puVar5;
  *(undefined1 **)((int)this + 8) = puVar5 + param_2;
  return;
}



undefined1 * __thiscall FUN_00403aa0(void *this,undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = *(undefined1 **)((int)this + 8);
  puVar2 = param_1;
  for (; param_2 != puVar1; param_2 = param_2 + 1) {
    *puVar2 = *param_2;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 **)((int)this + 8) = puVar2;
  return param_1;
}



undefined4 * __thiscall FUN_00403ad0(void *this,byte param_1)

{
  FUN_00403060(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_00403af0(void *this,undefined4 *param_1)

{
  FUN_00403ce0(this,param_1,(char *)((int)this + 0x94));
  return param_1;
}



void __fastcall FUN_00403b20(int param_1)

{
  FUN_00403b40(param_1 + 0xb0);
                    // WARNING: Could not recover jumptable at 0x00403b31. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_ios<>::~basic_ios<>((basic_ios<> *)(param_1 + 0xb0));
  return;
}



void __fastcall FUN_00403b40(int param_1)

{
  void *pvVar1;
  basic_string<> *pbVar2;
  void **ppvVar3;
  void *pvVar4;
  basic_string<> *pbVar5;
  _Lockit local_14 [4];
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0042f21d;
  local_10 = param_1 + -8;
  pvVar1 = *(void **)(param_1 + -0x14);
  pvVar4 = *(void **)(param_1 + -0x18);
  local_4 = 3;
  ppvVar3 = &local_c;
  local_c = ExceptionList;
  for (; ExceptionList = ppvVar3, pvVar4 != pvVar1; pvVar4 = (void *)((int)pvVar4 + 0x14)) {
    FUN_00404af0(pvVar4,0);
    ppvVar3 = ExceptionList;
  }
  FUN_0042da40(*(void **)(param_1 + -0x18));
  *(undefined4 *)(param_1 + -0x18) = 0;
  *(undefined4 *)(param_1 + -0x14) = 0;
  *(undefined4 *)(param_1 + -0x10) = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004024d0((void *)(param_1 + -0x2c),(undefined4 *)local_14,(int *)**(int **)(param_1 + -0x28),
               *(int **)(param_1 + -0x28));
  FUN_0042da40(*(void **)(param_1 + -0x28));
  *(undefined4 *)(param_1 + -0x28) = 0;
  *(undefined4 *)(param_1 + -0x20) = 0;
  std::_Lockit::_Lockit(local_14);
  pvVar1 = DAT_0044347c;
  DAT_00443480 = DAT_00443480 + -1;
  pvVar4 = (void *)0x0;
  if (DAT_00443480 == 0) {
    DAT_0044347c = (void *)0x0;
    pvVar4 = pvVar1;
  }
  std::_Lockit::~_Lockit(local_14);
  if (pvVar4 != (void *)0x0) {
    FUN_0042da40(pvVar4);
  }
  pbVar2 = *(basic_string<> **)(param_1 + -0x34);
  pbVar5 = *(basic_string<> **)(param_1 + -0x38);
  local_4._0_1_ = 1;
  for (; pbVar5 != pbVar2; pbVar5 = pbVar5 + 0x10) {
    std::basic_string<>::_Tidy(pbVar5,true);
  }
  FUN_0042da40(*(void **)(param_1 + -0x38));
  *(undefined4 *)(param_1 + -0x38) = 0;
  *(undefined4 *)(param_1 + -0x34) = 0;
  *(undefined4 *)(param_1 + -0x30) = 0;
  pbVar2 = *(basic_string<> **)(param_1 + -0x44);
  pbVar5 = *(basic_string<> **)(param_1 + -0x48);
  local_4 = (uint)local_4._1_3_ << 8;
  for (; pbVar5 != pbVar2; pbVar5 = pbVar5 + 0x14) {
    std::basic_string<>::_Tidy(pbVar5,true);
  }
  FUN_0042da40(*(void **)(param_1 + -0x48));
  *(undefined4 *)(param_1 + -0x48) = 0;
  *(undefined4 *)(param_1 + -0x44) = 0;
  *(undefined4 *)(param_1 + -0x40) = 0;
  local_4 = 0xffffffff;
  std::strstream::~strstream((strstream *)(param_1 + -0x54));
  ExceptionList = local_c;
  return;
}



void __thiscall FUN_00403cb0(void *this,undefined4 param_1)

{
  mysql_field_seek(*(undefined4 *)(*(int *)((int)this + 4) + 4),param_1);
  mysql_fetch_field();
  return;
}



undefined4 * __thiscall FUN_00403ce0(void *this,undefined4 *param_1,char *param_2)

{
  char cVar1;
  basic_string<> *pbVar2;
  int iVar3;
  basic_string<> local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f239;
  local_c = ExceptionList;
  if (*(int *)((int)this + 0x68) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)((int)this + 0x6c) - *(int *)((int)this + 0x68)) / 0x14;
  }
  ExceptionList = &local_c;
  pbVar2 = FUN_00406450(this,local_1c,param_2,(uint)(iVar3 == 0));
  local_4 = 0;
  FUN_00403d90(*(void **)((int)this + 0xa8),param_1,(int)pbVar2);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}



undefined4 * __thiscall FUN_00403d90(void *this,undefined4 *param_1,int param_2)

{
  FUN_00404e00(this,param_1,param_2,*(allocator<char> *)this);
  return param_1;
}



basic_iostream<> * __thiscall FUN_00403dc0(void *this,basic_iostream<> *param_1)

{
  basic_iostream<> bVar1;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f2aa;
  local_c = ExceptionList;
  bVar1 = *(basic_iostream<> *)this;
  local_10 = 2;
  ExceptionList = &local_c;
  *(undefined **)param_1 = &DAT_00430288;
  *(undefined **)(param_1 + 8) = &DAT_00430280;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(code **)(param_1 + 0xb0) = _vftable__exref;
  *(code **)(param_1 + 0xb0) = _vftable__exref;
  local_4 = 0;
  std::basic_iostream<>::basic_iostream<>(param_1,(basic_streambuf<> *)(param_1 + 0xc));
  local_4 = 3;
  FUN_00403fd0((basic_streambuf<> *)(param_1 + 0xc),0);
  *(undefined ***)(param_1 + *(int *)(*(int *)param_1 + 4)) = &PTR_LAB_0043027c;
  param_1[0x5c] = (basic_iostream<>)0x0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  param_1[100] = param_1._0_1_;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  param_1[0x74] = param_1._0_1_;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  local_4._0_1_ = 6;
  local_4._1_3_ = 0;
  FUN_00403f00(param_1 + 0x84,&local_12,0,&local_13);
  local_4 = CONCAT31(local_4._1_3_,7);
  FUN_00401c80(param_1 + 0x94,&local_11);
  *(basic_iostream<> **)(param_1 + 0xa4) = param_1;
  *(undefined ***)(param_1 + *(int *)(*(int *)param_1 + 4)) = &PTR_LAB_00430278;
  *(undefined ***)(param_1 + *(int *)(*(int *)param_1 + 4)) = &PTR_LAB_00430274;
  *(void **)(param_1 + 0xa8) = this;
  param_1[0xac] = bVar1;
  *(undefined4 *)(param_1 + 0x60) = 0;
  param_1[0x5c] = (basic_iostream<>)0x1;
  ExceptionList = local_c;
  return param_1;
}



undefined1 * __thiscall
FUN_00403f00(void *this,undefined1 *param_1,undefined1 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  
  *(undefined1 *)this = *param_3;
  uVar1 = *param_1;
  *(undefined1 *)((int)this + 8) = param_2;
  *(undefined1 *)((int)this + 1) = uVar1;
  FUN_00403f30((int)this);
  return this;
}



void __fastcall FUN_00403f30(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int local_4;
  
  local_4 = param_1;
  puVar1 = operator_new(0x24);
  puVar1[1] = 0;
  puVar1[8] = 1;
  std::_Lockit::_Lockit((_Lockit *)&local_4);
  if (DAT_0044347c == (undefined4 *)0x0) {
    DAT_0044347c = puVar1;
    *puVar1 = 0;
    puVar1 = (undefined4 *)0x0;
    DAT_0044347c[2] = 0;
  }
  DAT_00443480 = DAT_00443480 + 1;
  std::_Lockit::~_Lockit((_Lockit *)&local_4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0042da40(puVar1);
  }
  puVar1 = DAT_0044347c;
  pvVar2 = operator_new(0x24);
  *(undefined4 **)((int)pvVar2 + 4) = puVar1;
  *(undefined4 *)((int)pvVar2 + 0x20) = 0;
  *(void **)(param_1 + 4) = pvVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  return;
}



strstreambuf * __thiscall FUN_00403fd0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  _Locimp *p_Var3;
  _Lockit local_18 [4];
  _Lockit local_14 [4];
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f2c9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = this;
  p_Var3 = std::locale::_Init();
  *(_Locimp **)((int)this + 0x34) = p_Var3;
  std::_Lockit::_Lockit(local_14);
  iVar1 = *(int *)_Global_exref;
  std::_Lockit::_Lockit(local_18);
  iVar2 = *(int *)(iVar1 + 4);
  if (iVar2 != -1) {
    *(int *)(iVar1 + 4) = iVar2 + 1;
  }
  std::_Lockit::~_Lockit(local_18);
  std::_Lockit::~_Lockit(local_14);
  *(int *)((int)this + 0xc) = (int)this + 4;
  *(int *)((int)this + 0x1c) = (int)this + 0x14;
  *(int *)((int)this + 0x20) = (int)this + 0x18;
  *(undefined4 **)((int)this + 0x10) = (undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x2c) = (int)this + 0x24;
  *(int *)((int)this + 0x30) = (int)this + 0x28;
  *(undefined4 *)((int)this + 8) = 0;
  **(undefined4 **)((int)this + 0x20) = 0;
  **(undefined4 **)((int)this + 0x30) = 0;
  **(undefined4 **)((int)this + 0xc) = 0;
  **(undefined4 **)((int)this + 0x1c) = 0;
  **(undefined4 **)((int)this + 0x2c) = 0;
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_00430290;
  std::strstreambuf::_Init(this,param_1,(char *)0x0,(char *)0x0,0);
  ExceptionList = local_c;
  return this;
}



strstreambuf * __thiscall FUN_004040c0(void *this,byte param_1)

{
  std::strstreambuf::~strstreambuf(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_004041a0(void *this,undefined4 *param_1,int param_2)

{
  char cVar1;
  basic_string<> bVar2;
  int iVar3;
  basic_string<> *this_00;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_28 [8];
  undefined1 local_20;
  basic_string<> local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f2f5;
  local_c = ExceptionList;
  bVar2 = *(basic_string<> *)(*(int *)((int)this + 0x1c) + param_2);
  ExceptionList = &local_c;
  iVar3 = thunk_FUN_00404580(*(void **)((int)this + 0x28),param_2);
  FUN_004042c0(local_28,iVar3);
  this_00 = (basic_string<> *)FUN_004042b0((void *)((int)this + 8),param_2);
  pcVar4 = std::basic_string<>::c_str(this_00);
  *param_1 = pcVar4;
  *(undefined1 *)(param_1 + 3) = local_20;
  *(basic_string<> *)(param_1 + 4) = bVar2;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(basic_string<> *)(param_1 + 8) = bVar2;
  uVar5 = 0xffffffff;
  local_4 = 0;
  pcVar6 = pcVar4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_1c[0] = bVar2;
  std::basic_string<>::assign(local_1c,pcVar4,~uVar5 - 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  std::basic_string<>::assign((basic_string<> *)(param_1 + 4),local_1c,0,*(uint *)npos_exref);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}



int __thiscall FUN_004042b0(void *this,int param_1)

{
  return param_1 * 0x10 + *(int *)((int)this + 4);
}



void __thiscall FUN_004042c0(void *this,int param_1)

{
  *(undefined1 *)((int)this + 8) = *(undefined1 *)(param_1 + 8);
  return;
}



undefined4 * __thiscall FUN_004042d0(void *this,undefined4 *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  basic_string<> bVar8;
  int iVar9;
  basic_string<> local_1c [4];
  char *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  pcVar4 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f31c;
  local_c = ExceptionList;
  local_1c[0] = param_2._0_1_;
  uVar5 = 0xffffffff;
  pcVar7 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  iVar9 = 0x404329;
  ExceptionList = &local_c;
  bVar3 = std::basic_string<>::_Grow(local_1c,uVar5,true);
  if (bVar3) {
    pcVar7 = local_18;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar7 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar7 = pcVar7 + 1;
    }
    std::basic_string<>::_Eos(local_1c,uVar5);
  }
  local_4 = 0;
  iVar2 = *(int *)((int)this + 0x28);
  if (*(int *)(iVar2 + 0xc) == 0) {
    pcVar4 = operator_new(0x10);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = (char *)0x0;
    }
    else {
      param_2 = pcVar4;
      FUN_00401c80(pcVar4,(undefined1 *)&param_2);
      local_4 = CONCAT31(local_4._1_3_,2);
      FUN_00406dc0(pcVar4,iVar2);
    }
    local_4 = local_4 & 0xffffff00;
    *(char **)(iVar2 + 0xc) = pcVar4;
  }
  param_2 = &stack0xffffffbc;
  bVar8 = local_1c[0];
  std::basic_string<>::_Tidy((basic_string<> *)&stack0xffffffbc,false);
  std::basic_string<>::assign((basic_string<> *)&stack0xffffffbc,local_1c,0,*(uint *)npos_exref);
  iVar9 = FUN_00404420(*(int *)(iVar2 + 0xc),bVar8,iVar9);
  FUN_00402c10(this,param_1,iVar9);
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40(local_18 + -1);
    }
    else {
      local_18[-1] = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}



int __thiscall FUN_00404420(int param_1,basic_string<> param_2,int param_3)

{
  code cVar1;
  char cVar2;
  basic_string<> *pbVar3;
  bool bVar4;
  code *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  basic_string<> *pbVar9;
  basic_string<> local_1c [4];
  int local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f342;
  local_c = ExceptionList;
  local_4 = 0;
  local_1c[0] = param_2;
  ExceptionList = &local_c;
  std::basic_string<>::_Tidy(local_1c,false);
  std::basic_string<>::assign(local_1c,&param_2,0,*(uint *)npos_exref);
  uVar8 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (local_14 != 0) {
    do {
      pcVar5 = _C_exref;
      if (local_18 != 0) {
        std::basic_string<>::_Freeze(local_1c);
        pcVar5 = (code *)(local_18 + uVar8);
      }
      cVar1 = *pcVar5;
      pcVar6 = std::basic_string<>::operator[](local_1c,uVar8);
      iVar7 = tolower((int)(char)cVar1);
      *pcVar6 = (char)iVar7;
      uVar8 = uVar8 + 1;
    } while (uVar8 < local_14);
  }
  pbVar3 = *(basic_string<> **)(param_1 + 8);
  pbVar9 = *(basic_string<> **)(param_1 + 4);
  while ((pbVar9 != pbVar3 && (bVar4 = std::operator==(pbVar9,local_1c), !bVar4))) {
    pbVar9 = pbVar9 + 0x10;
  }
  iVar7 = *(int *)(param_1 + 4);
  if (local_18 != 0) {
    cVar2 = *(char *)(local_18 + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_0042da40((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar2 + -1;
    }
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_3 != 0) {
    cVar2 = *(char *)(param_3 + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_0042da40((char *)(param_3 + -1));
    }
    else {
      *(char *)(param_3 + -1) = cVar2 + -1;
    }
  }
  ExceptionList = local_c;
  return (int)pbVar9 - iVar7 >> 4;
}



int __thiscall thunk_FUN_00404580(void *this,int param_1)

{
  undefined1 *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0042f363;
  pvStack_c = ExceptionList;
  if (*(int *)((int)this + 0x10) == 0) {
    ExceptionList = &pvStack_c;
    this_00 = operator_new(0x10);
    if (this_00 == (undefined1 *)0x0) {
      this_00 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(this_00 + 4) = 0;
      *this_00 = (undefined1)param_1;
      *(undefined4 *)(this_00 + 8) = 0;
      *(undefined4 *)(this_00 + 0xc) = 0;
      uStack_4 = 1;
      FUN_00407060(this_00,(int)this);
    }
    *(undefined1 **)((int)this + 0x10) = this_00;
  }
  ExceptionList = pvStack_c;
  return *(int *)(*(int *)((int)this + 0x10) + 4) + param_1 * 0xc;
}



int __thiscall FUN_00404580(void *this,int param_1)

{
  undefined1 *this_00;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f363;
  local_c = ExceptionList;
  if (*(int *)((int)this + 0x10) == 0) {
    ExceptionList = &local_c;
    this_00 = operator_new(0x10);
    if (this_00 == (undefined1 *)0x0) {
      this_00 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(this_00 + 4) = 0;
      *this_00 = (undefined1)param_1;
      *(undefined4 *)(this_00 + 8) = 0;
      *(undefined4 *)(this_00 + 0xc) = 0;
      local_4 = 1;
      FUN_00407060(this_00,(int)this);
    }
    *(undefined1 **)((int)this + 0x10) = this_00;
  }
  ExceptionList = local_c;
  return *(int *)(*(int *)((int)this + 0x10) + 4) + param_1 * 0xc;
}



void __fastcall FUN_00404610(int param_1)

{
  FUN_0042da40(*(void **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



float10 __fastcall FUN_00404630(undefined4 *param_1)

{
  char cVar1;
  code cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  double dVar10;
  code *local_44;
  uint local_40;
  float local_3c;
  basic_string<> local_38 [4];
  code *local_34;
  uint local_30;
  char *local_28;
  basic_string<> local_24 [4];
  char *local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f379;
  local_c = ExceptionList;
  local_38[0] = *(basic_string<> *)(param_1 + 4);
  ExceptionList = &local_c;
  std::basic_string<>::_Tidy(local_38,false);
  std::basic_string<>::assign(local_38,(basic_string<> *)(param_1 + 4),0,*(uint *)npos_exref);
  uVar7 = 0;
  local_4 = 0;
  local_40 = local_30;
  if (local_30 != 0) {
    do {
      pcVar4 = _C_exref;
      if (local_34 != (code *)0x0) {
        std::basic_string<>::_Freeze(local_38);
        pcVar4 = local_34 + uVar7;
        local_40 = local_30;
      }
      if (*pcVar4 == (code)0x20) {
        std::basic_string<>::erase(local_38,uVar7,1);
        uVar7 = uVar7 - 1;
        local_40 = local_30;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_40);
  }
  pcVar4 = local_34;
  if (local_34 == (code *)0x0) {
    pcVar4 = _C_exref;
  }
  local_44 = pcVar4;
  dVar10 = strtod((char *)pcVar4,(char **)&local_44);
  local_3c = (float)dVar10;
  if (*local_44 == (code)0x2e) {
    local_44 = local_44 + 1;
    cVar2 = *local_44;
    while (cVar2 == (code)0x30) {
      local_44 = local_44 + 1;
      cVar2 = *local_44;
    }
  }
  if (*local_44 == (code)0x0) {
    if (local_34 != (code *)0x0) {
      cVar2 = local_34[-1];
      if ((cVar2 == (code)0x0) || (cVar2 == (code)0xff)) {
        FUN_0042da40(local_34 + -1);
      }
      else {
        local_34[-1] = (code)((char)cVar2 + -1);
      }
    }
    ExceptionList = local_c;
    return (float10)local_3c;
  }
  pcVar8 = (char *)*param_1;
  iVar5 = (int)local_44 - (int)pcVar4;
  local_28 = type_info::name((type_info *)&TypeDescriptor_00439bc0);
  uVar7 = 0xffffffff;
  local_20 = (char *)0x0;
  local_1c = 0;
  local_18 = 0;
  pcVar9 = pcVar8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7 - 1;
  bVar3 = std::basic_string<>::_Grow(local_24,uVar7,true);
  if (bVar3) {
    pcVar9 = local_20;
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    local_20[uVar7] = '\0';
    local_1c = uVar7;
  }
  local_10 = local_40;
  local_14 = iVar5;
                    // WARNING: Subroutine does not return
  _CxxThrowException(&local_28,(ThrowInfo *)&DAT_00436998);
}



void __cdecl FUN_004047e0(basic_string<> *param_1,basic_string<> *param_2)

{
  basic_string<> bVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f3a1;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (basic_string<> *)0x0) {
    bVar1 = *param_2;
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 4) = 0;
    *param_1 = bVar1;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar6 = *(uint *)npos_exref;
    uVar4 = *(uint *)(param_2 + 8);
    uVar7 = uVar4;
    if (uVar6 < uVar4) {
      uVar7 = uVar6;
    }
    if (param_1 == param_2) {
      if (uVar7 != 0) {
        std::_Xran();
      }
      std::basic_string<>::_Split(param_1);
      uVar4 = *(int *)(param_1 + 8) - uVar7;
      if (uVar4 < uVar6) {
        uVar6 = uVar4;
      }
      if (uVar6 != 0) {
        memmove((void *)(uVar7 + *(int *)(param_1 + 4)),
                (void *)((int)(uVar7 + *(int *)(param_1 + 4)) + uVar6),uVar4 - uVar6);
        iVar2 = *(int *)(param_1 + 8);
        bVar3 = std::basic_string<>::_Grow(param_1,iVar2 - uVar6,false);
        if (bVar3) {
          std::basic_string<>::_Eos(param_1,iVar2 - uVar6);
        }
      }
      std::basic_string<>::_Split(param_1);
      ExceptionList = local_c;
      return;
    }
    if ((uVar7 != 0) && (uVar7 == uVar4)) {
      pcVar5 = *(code **)(param_2 + 4);
      if (*(code **)(param_2 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      if ((byte)pcVar5[-1] < 0xfe) {
        std::basic_string<>::_Tidy(param_1,true);
        pcVar5 = *(code **)(param_2 + 4);
        if (*(code **)(param_2 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        *(code **)(param_1 + 4) = pcVar5;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
        ExceptionList = local_c;
        return;
      }
    }
    bVar3 = std::basic_string<>::_Grow(param_1,uVar7,true);
    if (bVar3) {
      pcVar5 = *(code **)(param_2 + 4);
      if (*(code **)(param_2 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      pcVar8 = *(code **)(param_1 + 4);
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
      }
      *(uint *)(param_1 + 8) = uVar7;
      *(undefined1 *)(uVar7 + *(int *)(param_1 + 4)) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}



void FUN_00404950(void)

{
  return;
}



void __fastcall FUN_00404960(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



void * __thiscall FUN_00404af0(void *this,byte param_1)

{
  FUN_004025b0((int)this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void * __thiscall FUN_00404b10(void *this,byte param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 4);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void __fastcall FUN_00404b70(int param_1)

{
  mysql_close(param_1 + 8);
  return;
}



void __thiscall FUN_00404b80(void *this,undefined4 param_1)

{
  char cVar1;
  int iVar2;
  basic_string<> local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  basic_string<> local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f3c1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = mysql_select_db((int)this + 8,param_1);
  if ((*(char *)this != '\0') && (iVar2 != 0)) {
    FUN_00405100(this,local_3c);
    local_4 = 0;
    local_1c[0] = local_3c[0];
    std::basic_string<>::_Tidy(local_1c,false);
    std::basic_string<>::assign(local_1c,local_3c,0,*(uint *)npos_exref);
    if (local_38 != 0) {
      cVar1 = *(char *)(local_38 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_0042da40((char *)(local_38 + -1));
      }
      else {
        *(char *)(local_38 + -1) = cVar1 + -1;
      }
    }
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c[0] = local_1c[0];
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_4 = 1;
    std::basic_string<>::assign(local_2c,local_1c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
    _CxxThrowException(local_2c,(ThrowInfo *)&DAT_004366d4);
  }
  ExceptionList = local_c;
  return;
}



char __thiscall
FUN_00404c90(void *this,char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  basic_string<> local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  basic_string<> local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f3e1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)((int)this + 0x1f9) = 1;
  iVar3 = mysql_connect((int)this + 8,param_2,param_3,param_4);
  *(undefined1 *)((int)this + 0x1f9) = 0;
  if (iVar3 == 0) {
    if (*(char *)this != '\0') {
      FUN_00405100(this,local_3c);
      local_4 = 0;
      local_1c[0] = local_3c[0];
      std::basic_string<>::_Tidy(local_1c,false);
      std::basic_string<>::assign(local_1c,local_3c,0,*(uint *)npos_exref);
      if (local_38 != 0) {
        cVar1 = *(char *)(local_38 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_0042da40((char *)(local_38 + -1));
        }
        else {
          *(char *)(local_38 + -1) = cVar1 + -1;
        }
      }
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c[0] = local_1c[0];
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_4 = 1;
      std::basic_string<>::assign(local_2c,local_1c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
      _CxxThrowException(local_2c,(ThrowInfo *)&DAT_004366d4);
    }
    *(undefined1 *)((int)this + 0x1f8) = 0;
    *(undefined1 *)((int)this + 0x1fa) = 0;
  }
  else {
    *(undefined1 *)((int)this + 0x1f8) = 1;
    *(undefined1 *)((int)this + 0x1fa) = 1;
  }
  if (*(char *)((int)this + 0x1fa) == '\0') {
    ExceptionList = local_c;
    return '\0';
  }
  if (*param_1 != '\0') {
    uVar2 = FUN_00404b80(this,param_1);
    *(undefined1 *)((int)this + 0x1fa) = uVar2;
  }
  ExceptionList = local_c;
  return *(char *)((int)this + 0x1fa);
}



undefined4 * __thiscall
FUN_00404e00(void *param_1,undefined4 *param_2,int param_3,allocator<char> param_4)

{
  code *pcVar1;
  int iVar2;
  basic_string<> local_3c [16];
  basic_string<> local_2c [16];
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f412;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)((int)param_1 + 0x1fa) = 0;
  if (*(char *)((int)param_1 + 0x1f9) == '\0') {
    *(undefined1 *)((int)param_1 + 0x1f9) = 1;
    pcVar1 = *(code **)(param_3 + 4);
    if (*(code **)(param_3 + 4) == (code *)0x0) {
      pcVar1 = _C_exref;
    }
    iVar2 = mysql_query((int)param_1 + 8,pcVar1);
    *(bool *)((int)param_1 + 0x1fa) = iVar2 == 0;
    *(undefined1 *)((int)param_1 + 0x1f9) = 0;
    if (iVar2 != 0) {
      if (param_4 != (allocator<char>)0x0) {
        FUN_00405100(param_1,local_1c);
        local_4 = 2;
        local_3c[0] = local_1c[0];
        std::basic_string<>::_Tidy(local_3c,false);
        std::basic_string<>::assign(local_3c,local_1c,0,*(uint *)npos_exref);
        local_4 = 0xffffffff;
        std::basic_string<>::_Tidy(local_1c,true);
        local_2c[0] = local_3c[0];
        local_4 = 3;
        std::basic_string<>::_Tidy(local_2c,false);
        std::basic_string<>::assign(local_2c,local_3c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
        _CxxThrowException(local_2c,(ThrowInfo *)&DAT_004366d4);
      }
      param_2[1] = 0;
      param_2[2] = 0;
      *(undefined1 *)(param_2 + 3) = 0;
      *(undefined1 *)((int)param_2 + 0xd) = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      FUN_004050e0(param_2 + 6,param_2 + 1);
      std::basic_string<>::basic_string<>((basic_string<> *)(param_2 + 8),&param_4);
      *param_2 = &PTR_FUN_00430230;
      ExceptionList = local_c;
      return param_2;
    }
    iVar2 = mysql_store_result((int)param_1 + 8);
    FUN_00405540(param_2 + 1,iVar2,0,(basic_string<>)0x0);
    param_2[1] = 0;
  }
  else {
    if (param_4 != (allocator<char>)0x0) {
      FUN_00405100(param_1,local_2c);
      local_3c[0] = local_2c[0];
      local_4 = 0;
      std::basic_string<>::_Tidy(local_3c,false);
      std::basic_string<>::assign(local_3c,local_2c,0,*(uint *)npos_exref);
      local_4 = 0xffffffff;
      std::basic_string<>::_Tidy(local_2c,true);
      local_4 = 1;
      local_1c[0] = local_3c[0];
      std::basic_string<>::_Tidy(local_1c,false);
      std::basic_string<>::assign(local_1c,local_3c,0,*(uint *)npos_exref);
                    // WARNING: Subroutine does not return
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_004366d4);
    }
    FUN_00403020(param_2 + 1);
  }
  *param_2 = &PTR_FUN_00430230;
  ExceptionList = local_c;
  return param_2;
}



void FUN_00405050(void)

{
                    // WARNING: Could not recover jumptable at 0x00405055. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_00443489);
  return;
}



void FUN_00405060(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00405070);
  return;
}



void FUN_00405090(void)

{
                    // WARNING: Could not recover jumptable at 0x00405095. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_00443488);
  return;
}



void FUN_004050a0(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_004050b0);
  return;
}



void __thiscall FUN_004050e0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = &PTR_LAB_0043026c;
  return;
}



basic_string<> * __thiscall FUN_00405100(void *this,basic_string<> *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  pcVar3 = (char *)mysql_error((int)this + 8);
  *param_1 = param_1._0_1_;
  uVar4 = 0xffffffff;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  pcVar6 = pcVar3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  if (0xfffffffd < uVar4) {
    std::_Xlen();
  }
  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar4 == 0) {
      std::basic_string<>::_Tidy(param_1,true);
      return param_1;
    }
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (uVar4 <= *(uint *)(param_1 + 0xc))) goto LAB_004051ab;
    std::basic_string<>::_Tidy(param_1,true);
  }
  else if (uVar4 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    std::basic_string<>::_Tidy(param_1,false);
    return param_1;
  }
  std::basic_string<>::_Copy(param_1,uVar4);
LAB_004051ab:
  pcVar6 = *(char **)(param_1 + 4);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *(uint *)(param_1 + 8) = uVar4;
  *(undefined1 *)(uVar4 + *(int *)(param_1 + 4)) = 0;
  return param_1;
}



basic_ostream<> * __cdecl FUN_004051e0(basic_ostream<> *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  basic_ostream<> *pbVar8;
  char *pcVar9;
  basic_string<> *pbVar10;
  char *pcVar11;
  
  if (((DAT_0044348f != '\0') ||
      (*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x28) ==
       *(int *)(cout_exref + *(int *)(*(int *)cout_exref + 4) + 0x28))) ||
     (*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x28) ==
      *(int *)(cerr_exref + *(int *)(*(int *)cerr_exref + 4) + 0x28))) {
    pbVar8 = std::operator<<(param_1,(basic_string<> *)(param_2 + 4));
    return pbVar8;
  }
  puVar1 = param_2 + 1;
  bVar4 = FUN_004080f0((int)puVar1);
  if (!bVar4) {
    uVar7 = FUN_00407fa0((int)puVar1);
    pbVar10 = (basic_string<> *)(param_2 + 4);
    if ((char)uVar7 == '\0') {
      std::operator<<(param_1,pbVar10);
      return param_1;
    }
    pcVar11 = &DAT_00439bcc;
    pbVar8 = std::operator<<(param_1,&DAT_00439bcc);
    pbVar8 = std::operator<<(pbVar8,pbVar10);
    std::operator<<(pbVar8,pcVar11);
    return param_1;
  }
  iVar5 = 0;
  cVar2 = *(char *)*param_2;
  while (cVar2 != '\0') {
    iVar3 = iVar5 + 1;
    iVar5 = iVar5 + 1;
    cVar2 = ((char *)*param_2)[iVar3];
  }
  pcVar6 = operator_new(iVar5 * 2 + 1);
  pcVar11 = (char *)*param_2;
  iVar5 = 0;
  cVar2 = *pcVar11;
  while (cVar2 != '\0') {
    iVar3 = iVar5 + 1;
    iVar5 = iVar5 + 1;
    cVar2 = pcVar11[iVar3];
  }
  mysql_escape_string(pcVar6,pcVar11,iVar5);
  uVar7 = FUN_00407fa0((int)puVar1);
  if ((char)uVar7 == '\0') {
    std::operator<<(param_1,pcVar6);
    FUN_0042da40(pcVar6);
    return param_1;
  }
  pcVar9 = &DAT_00439bcc;
  pcVar11 = pcVar6;
  pbVar8 = std::operator<<(param_1,&DAT_00439bcc);
  pbVar8 = std::operator<<(pbVar8,pcVar11);
  std::operator<<(pbVar8,pcVar9);
  FUN_0042da40(pcVar6);
  return param_1;
}



void FUN_00405340(void)

{
                    // WARNING: Could not recover jumptable at 0x00405345. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_0044348d);
  return;
}



void FUN_00405350(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00405360);
  return;
}



void FUN_00405380(void)

{
                    // WARNING: Could not recover jumptable at 0x00405385. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_0044348c);
  return;
}



void FUN_00405390(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_004053a0);
  return;
}



void __cdecl FUN_004053d0(basic_string<> *param_1,basic_string<> *param_2)

{
  basic_string<> bVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f431;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 == (basic_string<> *)0x0) {
    return;
  }
  bVar1 = *param_2;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = bVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar4 = *(uint *)(param_2 + 8);
  uVar7 = *(uint *)npos_exref;
  uVar6 = uVar4;
  if (uVar7 < uVar4) {
    uVar6 = uVar7;
  }
  if (param_1 == param_2) {
    if (uVar6 != 0) {
      std::_Xran();
    }
    std::basic_string<>::_Split(param_1);
    uVar4 = *(int *)(param_1 + 8) - uVar6;
    if (uVar4 < uVar7) {
      uVar7 = uVar4;
    }
    if (uVar7 != 0) {
      memmove((void *)(uVar6 + *(int *)(param_1 + 4)),
              (void *)(uVar7 + (int)(uVar6 + *(int *)(param_1 + 4))),uVar4 - uVar7);
      iVar2 = *(int *)(param_1 + 8);
      bVar3 = std::basic_string<>::_Grow(param_1,iVar2 - uVar7,false);
      if (bVar3) {
        std::basic_string<>::_Eos(param_1,iVar2 - uVar7);
      }
    }
    std::basic_string<>::_Split(param_1);
  }
  else {
    if ((uVar6 != 0) && (uVar6 == uVar4)) {
      pcVar5 = *(code **)(param_2 + 4);
      if (*(code **)(param_2 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      if ((byte)pcVar5[-1] < 0xfe) {
        std::basic_string<>::_Tidy(param_1,true);
        pcVar5 = *(code **)(param_2 + 4);
        if (*(code **)(param_2 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        *(code **)(param_1 + 4) = pcVar5;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
        goto LAB_00405510;
      }
    }
    bVar3 = std::basic_string<>::_Grow(param_1,uVar6,true);
    if (bVar3) {
      pcVar5 = _C_exref;
      if (*(code **)(param_2 + 4) != (code *)0x0) {
        pcVar5 = *(code **)(param_2 + 4);
      }
      pcVar8 = *(code **)(param_1 + 4);
      for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
      }
      std::basic_string<>::_Eos(param_1,uVar6);
    }
  }
LAB_00405510:
  param_1[0x10] = param_2[0x10];
  param_1[0x11] = param_2[0x11];
  param_1[0x12] = param_2[0x12];
  ExceptionList = local_c;
  return;
}



undefined4 * __thiscall
FUN_00405540(undefined4 *param_1,int param_2,undefined4 param_3,basic_string<> param_4)

{
  basic_string<> *this;
  char cVar1;
  void *pvVar2;
  basic_string<> *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  pvVar2 = ExceptionList;
  puStack_8 = &LAB_0042f472;
  local_c = ExceptionList;
  this = (basic_string<> *)(param_1 + 7);
  ExceptionList = &local_c;
  *param_1 = param_3;
  *(basic_string<> *)(param_1 + 2) = param_4;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[6] = param_1;
  param_1[5] = &PTR_LAB_0043026c;
  *this = param_4;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  local_4 = 0;
  if (param_2 == 0) {
    param_1[1] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    ExceptionList = pvVar2;
    return param_1;
  }
  param_1[1] = param_2;
  pbVar3 = operator_new(0x10);
  if (pbVar3 == (basic_string<> *)0x0) {
    pbVar3 = (basic_string<> *)0x0;
  }
  else {
    param_4 = SUB41(pbVar3,0);
    *(undefined4 *)(pbVar3 + 4) = 0;
    *pbVar3 = param_4;
    *(undefined4 *)(pbVar3 + 8) = 0;
    *(undefined4 *)(pbVar3 + 0xc) = 0;
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_00406dc0(pbVar3,(int)param_1);
  }
  local_4 = local_4 & 0xffffff00;
  param_1[3] = pbVar3;
  if (pbVar3 != (basic_string<> *)0x0) {
    pbVar3 = operator_new(0x10);
    if (pbVar3 == (basic_string<> *)0x0) {
      pbVar3 = (basic_string<> *)0x0;
    }
    else {
      param_4 = SUB41(pbVar3,0);
      *(undefined4 *)(pbVar3 + 4) = 0;
      *pbVar3 = param_4;
      *(undefined4 *)(pbVar3 + 8) = 0;
      *(undefined4 *)(pbVar3 + 0xc) = 0;
      local_4 = CONCAT31(local_4._1_3_,4);
      FUN_00407060(pbVar3,(int)param_1);
    }
    local_4 = local_4 & 0xffffff00;
    param_1[4] = pbVar3;
  }
  iVar4 = (**(code **)(param_1[5] + 4))(0);
  pcVar7 = *(char **)(iVar4 + 4);
  uVar5 = 0xffffffff;
  pcVar8 = pcVar7;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  if (0xfffffffd < uVar5) {
    std::_Xlen();
  }
  iVar4 = param_1[8];
  if (((iVar4 == 0) || (cVar1 = *(char *)(iVar4 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar5 == 0) {
      std::basic_string<>::_Tidy(this,true);
      goto LAB_004056d2;
    }
    if ((0x1f < (uint)param_1[10]) || ((uint)param_1[10] < uVar5)) {
      std::basic_string<>::_Tidy(this,true);
      goto LAB_004056a4;
    }
  }
  else {
    if (uVar5 == 0) {
      *(char *)(iVar4 + -1) = cVar1 + -1;
      std::basic_string<>::_Tidy(this,false);
      goto LAB_004056d2;
    }
LAB_004056a4:
    std::basic_string<>::_Copy(this,uVar5);
  }
  pcVar8 = (char *)param_1[8];
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  param_1[9] = uVar5;
  *(undefined1 *)(uVar5 + param_1[8]) = 0;
LAB_004056d2:
  *(undefined1 *)((int)param_1 + 9) = 1;
  ExceptionList = local_c;
  return param_1;
}



void __fastcall FUN_004056f0(int *param_1)

{
  char cVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f48c;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (*param_1 != 0) {
    ExceptionList = &local_c;
    *(undefined1 *)(*param_1 + 0x1f9) = 0;
  }
  FUN_00405780((int)param_1);
  iVar2 = param_1[8];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_0042da40((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  ExceptionList = local_c;
  return;
}



void __fastcall FUN_00405770(int param_1)

{
  mysql_num_fields(*(undefined4 *)(param_1 + 4));
  return;
}



void __fastcall FUN_00405780(int param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  basic_string<> *this;
  char *pcVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 4) != 0) {
    mysql_free_result(*(int *)(param_1 + 4));
  }
  pvVar2 = *(void **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 4) = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00401ca0((int)pvVar2);
    FUN_0042da40(pvVar2);
  }
  pvVar2 = *(void **)(param_1 + 0x10);
  if (pvVar2 != (void *)0x0) {
    FUN_00404610((int)pvVar2);
    FUN_0042da40(pvVar2);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  pcVar3 = *(char **)(param_1 + 0x20);
  this = (basic_string<> *)(param_1 + 0x1c);
  uVar7 = *(uint *)npos_exref;
  if (((pcVar3 != (char *)0x0) && (cVar1 = pcVar3[-1], cVar1 != '\0')) && (cVar1 != -1)) {
    pcVar3[-1] = cVar1 + -1;
    uVar5 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    pcVar6 = pcVar3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<>::assign(this,pcVar3,~uVar5 - 1);
  }
  uVar5 = *(uint *)(param_1 + 0x24);
  if (uVar5 < uVar7) {
    uVar7 = uVar5;
  }
  if (uVar7 == 0) {
    return;
  }
  memmove(*(void **)(param_1 + 0x20),(void *)((int)*(void **)(param_1 + 0x20) + uVar7),uVar5 - uVar7
         );
  uVar7 = *(int *)(param_1 + 0x24) - uVar7;
  if (0xfffffffd < uVar7) {
    std::_Xlen();
  }
  puVar4 = *(undefined1 **)(param_1 + 0x20);
  if (((puVar4 == (undefined1 *)0x0) || (cVar1 = puVar4[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar7 == 0) {
      if (puVar4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
      *puVar4 = 0;
      return;
    }
    if (uVar7 <= *(uint *)(param_1 + 0x28)) goto LAB_00405887;
  }
  else if (uVar7 == 0) {
    puVar4[-1] = cVar1 + -1;
    std::basic_string<>::_Tidy(this,false);
    return;
  }
  std::basic_string<>::_Copy(this,uVar7);
LAB_00405887:
  *(uint *)(param_1 + 0x24) = uVar7;
  *(undefined1 *)(uVar7 + *(int *)(param_1 + 0x20)) = 0;
  return;
}



void __thiscall FUN_004058a0(void *this,undefined4 *param_1)

{
  undefined1 *puVar1;
  basic_string<> *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  basic_string<> *this_00;
  void *pvVar7;
  int iVar8;
  basic_string<> *pbVar9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f4c7;
  local_c = ExceptionList;
  if (param_1[1] != 0) {
    ExceptionList = &local_c;
    if (*(char *)((int)this + 9) != '\0') {
      ExceptionList = &local_c;
      FUN_00405780((int)this);
    }
    *(undefined1 *)((int)this + 8) = *(undefined1 *)(param_1 + 2);
    *(undefined4 *)((int)this + 4) = param_1[1];
    *(undefined4 *)((int)this + 0x18) = param_1[6];
    if (param_1[3] == 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    else {
      puVar5 = operator_new(0x10);
      local_4 = 0;
      if (puVar5 == (undefined1 *)0x0) {
        local_4 = 0xffffffff;
        *(undefined4 *)((int)this + 0xc) = 0;
      }
      else {
        puVar1 = (undefined1 *)param_1[3];
        *puVar5 = *puVar1;
        if (*(int *)(puVar1 + 4) == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(puVar1 + 8) - *(int *)(puVar1 + 4) >> 4;
        }
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        this_00 = operator_new(iVar6 << 4);
        *(basic_string<> **)(puVar5 + 4) = this_00;
        pbVar2 = *(basic_string<> **)(puVar1 + 8);
        for (pbVar9 = *(basic_string<> **)(puVar1 + 4); pbVar9 != pbVar2; pbVar9 = pbVar9 + 0x10) {
          uVar4 = (uint)local_4 >> 8;
          local_4 = CONCAT31((int3)uVar4,1);
          if (this_00 != (basic_string<> *)0x0) {
            *this_00 = *pbVar9;
            std::basic_string<>::_Tidy(this_00,false);
            std::basic_string<>::assign(this_00,pbVar9,0,*(uint *)npos_exref);
          }
          this_00 = this_00 + 0x10;
        }
        *(basic_string<> **)(puVar5 + 8) = this_00;
        *(basic_string<> **)(puVar5 + 0xc) = this_00;
        *(undefined1 **)((int)this + 0xc) = puVar5;
        local_4 = 0xffffffff;
      }
    }
    puVar5 = (undefined1 *)0x0;
    if (param_1[4] != 0) {
      puVar5 = operator_new(0x10);
      local_4 = 2;
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = (undefined1 *)0x0;
      }
      else {
        puVar1 = (undefined1 *)param_1[4];
        *puVar5 = *puVar1;
        iVar6 = 0;
        if (*(int *)(puVar1 + 4) != 0) {
          iVar6 = (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4)) / 0xc;
        }
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        pvVar7 = operator_new(iVar6 * 0xc);
        *(void **)(puVar5 + 4) = pvVar7;
        iVar6 = *(int *)(puVar1 + 8);
        for (iVar8 = *(int *)(puVar1 + 4); iVar8 != iVar6; iVar8 = iVar8 + 0xc) {
          if (pvVar7 != (void *)0x0) {
            *(undefined1 *)((int)pvVar7 + 8) = *(undefined1 *)(iVar8 + 8);
          }
          pvVar7 = (void *)((int)pvVar7 + 0xc);
        }
        *(void **)(puVar5 + 8) = pvVar7;
        *(void **)(puVar5 + 0xc) = pvVar7;
      }
    }
    *(undefined1 **)((int)this + 0x10) = puVar5;
    uVar3 = *param_1;
    *(undefined1 *)((int)this + 9) = 1;
    *(undefined4 *)this = uVar3;
    ExceptionList = local_c;
    return;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  return;
}



void FUN_00405ab0(void)

{
                    // WARNING: Could not recover jumptable at 0x00405ab5. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_00443491);
  return;
}



void FUN_00405ac0(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00405ad0);
  return;
}



void FUN_00405af0(void)

{
                    // WARNING: Could not recover jumptable at 0x00405af5. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_00443490);
  return;
}



void FUN_00405b00(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00405b10);
  return;
}



void mysql_num_rows(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b40. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_num_rows();
  return;
}



void mysql_init(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b46. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_init();
  return;
}



void mysql_data_seek(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b4c. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_data_seek();
  return;
}



void mysql_fetch_lengths(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b52. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_fetch_lengths();
  return;
}



void mysql_fetch_row(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b58. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_fetch_row();
  return;
}



void mysql_fetch_field(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b5e. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_fetch_field();
  return;
}



void mysql_field_seek(void)

{
                    // WARNING: Could not recover jumptable at 0x00405b64. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_field_seek();
  return;
}



// WARNING: Removing unreachable block (ram,0x00405bca)
// WARNING: Removing unreachable block (ram,0x00405c08)

void __fastcall FUN_00405b70(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_18 [24];
  
  if ((*(byte *)(*(int *)(*param_1 + 4) + 4 + (int)param_1) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1) + 0x20))(local_18,0,0,1);
  }
  if ((*(byte *)(*(int *)(param_1[2] + 4) + 0xc + (int)param_1) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(param_1[2] + 4) + 0x30 + (int)param_1) + 0x20))(local_18,0,0,2)
    ;
  }
  iVar2 = param_1[0x1b];
  iVar1 = param_1[0x1a];
  for (iVar3 = iVar1; iVar3 != iVar2; iVar3 = iVar3 + 0x14) {
    FUN_004025b0(iVar3);
  }
  param_1[0x1b] = iVar1;
  iVar2 = param_1[0x27];
  iVar1 = param_1[0x26];
  for (iVar3 = iVar1; iVar3 != iVar2; iVar3 = iVar3 + 0x14) {
    FUN_004025b0(iVar3);
  }
  param_1[0x27] = iVar1;
  std::ios_base::clear
            ((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),
             (-(uint)(*(int *)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1) != 0) & 0xfffffffc) + 4
             ,false);
  return;
}



basic_string<> * __cdecl FUN_00405c60(char param_1,basic_string<> *param_2,basic_string<> param_3)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  char *pcVar4;
  code *pcVar5;
  basic_string<> *pbVar6;
  basic_string<> *pbVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 *puVar11;
  char *pcVar12;
  undefined4 *puVar13;
  char local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  basic_string<> local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f526;
  local_c = ExceptionList;
  if (param_2[0x12] != (basic_string<>)0x0) {
    return param_2;
  }
  if (param_1 != 'r') {
    if (param_1 == 'q') {
      if (param_2[0x10] != (basic_string<>)0x0) goto LAB_00405cbd;
    }
    else if ((param_1 == 'R') || ((param_1 == 'Q' && (param_2[0x10] != (basic_string<>)0x0)))) {
      ExceptionList = &local_c;
      pbVar6 = operator_new(0x14);
      bVar3 = pbVar6 == (basic_string<> *)0x0;
      local_4 = 1;
      if (bVar3) {
        pbVar6 = (basic_string<> *)0x0;
      }
      else {
        pcVar4 = (char *)std::operator+(local_2c,(basic_string<> *)&DAT_00439bcc);
        local_4 = CONCAT31(local_4._1_3_,2);
        pbVar7 = (basic_string<> *)std::operator+(local_1c,pcVar4);
        local_4 = 3;
        *pbVar6 = *pbVar7;
        std::basic_string<>::_Tidy(pbVar6,false);
        std::basic_string<>::assign(pbVar6,pbVar7,0,*(uint *)npos_exref);
        pbVar6[0x10] = (basic_string<>)0x1;
        pbVar6[0x12] = (basic_string<>)0x0;
        pbVar6[0x11] = (basic_string<>)0x0;
      }
      local_4 = 4;
      if (!bVar3) {
        std::basic_string<>::_Tidy(local_1c,true);
      }
      local_4 = 0xffffffff;
      if (!bVar3) {
        if (local_28 != 0) {
          cVar1 = *(char *)(local_28 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_0042da40((char *)(local_28 + -1));
          }
          else {
            *(char *)(local_28 + -1) = cVar1 + -1;
          }
        }
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
      }
      if (param_3 != (basic_string<>)0x0) {
        std::basic_string<>::assign(param_2,pbVar6,0,*(uint *)npos_exref);
        param_2[0x10] = pbVar6[0x10];
        param_2[0x11] = pbVar6[0x11];
        param_2[0x12] = (basic_string<>)0x1;
        ExceptionList = local_c;
        return param_2;
      }
      ExceptionList = local_c;
      return pbVar6;
    }
    if (param_3 != (basic_string<>)0x0) {
      param_2[0x12] = (basic_string<>)0x1;
    }
    return param_2;
  }
LAB_00405cbd:
  ExceptionList = &local_c;
  pcVar4 = operator_new(*(int *)(param_2 + 8) * 2 + 1);
  pcVar5 = *(code **)(param_2 + 4);
  if (*(code **)(param_2 + 4) == (code *)0x0) {
    pcVar5 = _C_exref;
  }
  mysql_escape_string(pcVar4,pcVar5,*(undefined4 *)(param_2 + 8));
  pbVar6 = operator_new(0x14);
  local_4 = 0;
  if (pbVar6 == (basic_string<> *)0x0) {
    pbVar6 = (basic_string<> *)0x0;
  }
  else {
    *pbVar6 = param_3;
    std::basic_string<>::_Tidy(pbVar6,false);
    uVar8 = 0xffffffff;
    pcVar10 = &DAT_00439bcc;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    std::basic_string<>::assign(pbVar6,&DAT_00439bcc,~uVar8 - 1);
    pbVar6[0x10] = (basic_string<>)0x1;
    pbVar6[0x12] = (basic_string<>)0x0;
    pbVar6[0x11] = (basic_string<>)0x0;
  }
  uVar8 = 0xffffffff;
  local_4 = 0xffffffff;
  pcVar10 = pcVar4;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8 - 1;
  if ((uint)(*(int *)npos_exref - *(int *)(pbVar6 + 8)) <= uVar8) {
    std::_Xlen();
  }
  if (uVar8 != 0) {
    iVar2 = *(int *)(pbVar6 + 8);
    bVar3 = std::basic_string<>::_Grow(pbVar6,iVar2 + uVar8,false);
    if (bVar3) {
      pcVar10 = pcVar4;
      pcVar12 = (char *)(*(int *)(pbVar6 + 4) + *(int *)(pbVar6 + 8));
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar12 = pcVar12 + 4;
      }
      for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar12 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      }
      std::basic_string<>::_Eos(pbVar6,iVar2 + uVar8);
    }
  }
  uVar8 = 0xffffffff;
  pcVar10 = &DAT_00439bcc;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8 - 1;
  if ((uint)(*(int *)npos_exref - *(int *)(pbVar6 + 8)) <= uVar8) {
    std::_Xlen();
  }
  if (uVar8 != 0) {
    iVar2 = *(int *)(pbVar6 + 8);
    bVar3 = std::basic_string<>::_Grow(pbVar6,iVar2 + uVar8,false);
    if (bVar3) {
      puVar11 = (undefined4 *)&DAT_00439bcc;
      puVar13 = (undefined4 *)(*(int *)(pbVar6 + 4) + *(int *)(pbVar6 + 8));
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      std::basic_string<>::_Eos(pbVar6,iVar2 + uVar8);
    }
  }
  FUN_0042da40(pcVar4);
  if (param_3 != (basic_string<>)0x0) {
    std::basic_string<>::assign(param_2,pbVar6,0,*(uint *)npos_exref);
    param_2[0x10] = pbVar6[0x10];
    param_2[0x11] = pbVar6[0x11];
    param_2[0x12] = (basic_string<>)0x1;
    ExceptionList = local_c;
    return param_2;
  }
  ExceptionList = local_c;
  return pbVar6;
}



basic_string<> * __thiscall FUN_00406000(void *this,basic_string<> *param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  void *_Dst;
  uint uVar7;
  code *pcVar8;
  
  uVar7 = *(uint *)npos_exref;
  uVar4 = *(uint *)(param_1 + 8);
  uVar6 = uVar4;
  if (uVar7 < uVar4) {
    uVar6 = uVar7;
  }
  if (this == param_1) {
    if (*(uint *)((int)this + 8) < uVar6) {
      std::_Xran();
    }
    std::basic_string<>::_Split(this);
    uVar4 = *(int *)((int)this + 8) - uVar6;
    if (uVar4 < uVar7) {
      uVar7 = uVar4;
    }
    if (uVar7 != 0) {
      _Dst = (void *)(uVar6 + *(int *)((int)this + 4));
      memmove(_Dst,(void *)((int)_Dst + uVar7),uVar4 - uVar7);
      uVar7 = *(int *)((int)this + 8) - uVar7;
      bVar3 = std::basic_string<>::_Grow(this,uVar7,false);
      if (bVar3) {
        std::basic_string<>::_Eos(this,uVar7);
      }
    }
    std::basic_string<>::_Split(this);
  }
  else {
    if ((uVar6 != 0) && (uVar6 == uVar4)) {
      pcVar5 = *(code **)(param_1 + 4);
      if (*(code **)(param_1 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      if ((byte)pcVar5[-1] < 0xfe) {
        iVar2 = *(int *)((int)this + 4);
        if (iVar2 != 0) {
          cVar1 = *(char *)(iVar2 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_0042da40((char *)(iVar2 + -1));
          }
          else {
            *(char *)(iVar2 + -1) = cVar1 + -1;
          }
        }
        *(undefined4 *)((int)this + 4) = 0;
        *(undefined4 *)((int)this + 8) = 0;
        *(undefined4 *)((int)this + 0xc) = 0;
        pcVar5 = *(code **)(param_1 + 4);
        if (*(code **)(param_1 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        *(code **)((int)this + 4) = pcVar5;
        *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
        pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
        goto LAB_0040612d;
      }
    }
    bVar3 = std::basic_string<>::_Grow(this,uVar6,true);
    if (bVar3) {
      pcVar5 = *(code **)(param_1 + 4);
      if (*(code **)(param_1 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      pcVar8 = *(code **)((int)this + 4);
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
      }
      *(uint *)((int)this + 8) = uVar6;
      *(undefined1 *)(uVar6 + *(int *)((int)this + 4)) = 0;
    }
  }
LAB_0040612d:
  *(basic_string<> *)((int)this + 0x10) = param_1[0x10];
  *(basic_string<> *)((int)this + 0x11) = param_1[0x11];
  *(basic_string<> *)((int)this + 0x12) = param_1[0x12];
  return this;
}



void __thiscall FUN_00406150(void *this,char *param_1)

{
  basic_string<> *pbVar1;
  basic_string<> *pbVar2;
  int iVar3;
  uint uVar4;
  basic_string<> *pbVar5;
  char *this_00;
  basic_string<> bVar6;
  undefined1 local_18 [24];
  
  if ((*(byte *)(*(int *)(*(int *)this + 4) + 4 + (int)this) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x28 + (int)this) + 0x20))(local_18,0,0,1);
  }
  iVar3 = *(int *)(*(int *)((int)this + 8) + 4);
  if ((*(byte *)(iVar3 + 0xc + (int)this) & 6) == 0) {
    (**(code **)(**(int **)(iVar3 + 0x30 + (int)this) + 0x20))(local_18,0,0,2);
  }
  pbVar5 = *(basic_string<> **)((int)this + 0x68);
  if (pbVar5 != *(basic_string<> **)((int)this + 0x6c)) {
    do {
      std::operator<<((basic_ostream<> *)((int)this + 8),pbVar5);
      if (pbVar5[0x11] != (basic_string<>)0xff) {
        if (*(int *)(param_1 + 4) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
        }
        uVar4 = (uint)(char)pbVar5[0x11];
        this_00 = param_1;
        if (iVar3 <= (int)uVar4) {
          if (*(int *)((int)this + 0x98) == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = (*(int *)((int)this + 0x9c) - *(int *)((int)this + 0x98)) / 0x14;
          }
          this_00 = (char *)((int)this + 0x94);
          if (iVar3 <= (int)uVar4) {
            std::operator<<((basic_ostream<> *)((int)this + 8),s_ERROR_00439c1c);
            param_1 = s_Not_enough_parameters_to_fill_th_00439bf0;
                    // WARNING: Subroutine does not return
            _CxxThrowException(&param_1,(ThrowInfo *)&DAT_00436bb4);
          }
        }
        bVar6 = (basic_string<>)(*(int *)(this_00 + 0x10) != 0);
        pbVar1 = (basic_string<> *)FUN_00406600(this_00,uVar4);
        pbVar1 = FUN_00405c60((char)pbVar5[0x10],pbVar1,bVar6);
        std::operator<<((basic_ostream<> *)((int)this + 8),pbVar1);
        pbVar2 = (basic_string<> *)FUN_00406600(this_00,uVar4);
        if ((pbVar1 != pbVar2) && (pbVar1 != (basic_string<> *)0x0)) {
          FUN_004025b0((int)pbVar1);
          FUN_0042da40(pbVar1);
        }
      }
      pbVar5 = pbVar5 + 0x14;
    } while (pbVar5 != *(basic_string<> **)((int)this + 0x6c));
  }
  return;
}



basic_string<> * __thiscall FUN_004062c0(void *this,basic_string<> *param_1,char *param_2)

{
  basic_ostream<> *pbVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  basic_string<> abStack_4c [4];
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 local_3c [24];
  undefined1 local_24 [24];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0042f539;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(int *)((int)this + 0x68) != 0) &&
     (ExceptionList = &pvStack_c,
     (*(int *)((int)this + 0x6c) - *(int *)((int)this + 0x68)) / 0x14 != 0)) {
    ExceptionList = &pvStack_c;
    FUN_00406150(this,param_2);
  }
  pbVar1 = (basic_ostream<> *)((int)this + 8);
  std::ends(pbVar1);
  iVar3 = **(int **)((int)this + 0x2c);
  if (iVar3 != 0) {
    iVar3 = iVar3 - **(int **)((int)this + 0x1c);
  }
  pcVar4 = operator_new(iVar3 + 1U);
  std::basic_istream<>::get(this,pcVar4,iVar3 + 1U,'\0');
  if ((*(uint *)(*(int *)(*(int *)this + 4) + 4 + (int)this) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x28 + (int)this) + 0x20))(local_3c,0,0,1);
  }
  if ((*(uint *)(pbVar1 + *(int *)(*(int *)pbVar1 + 4) + 4) & 6) == 0) {
    (**(code **)(**(int **)(pbVar1 + *(int *)(*(int *)pbVar1 + 4) + 0x28) + 0x20))
              (local_24,0xffffffff,1,2);
  }
  abStack_4c[0] = param_2._0_1_;
  uVar5 = 0xffffffff;
  iStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  pcVar6 = pcVar4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  std::basic_string<>::assign(abStack_4c,pcVar4,~uVar5 - 1);
  uStack_4 = 0;
  FUN_0042da40(pcVar4);
  *param_1 = abStack_4c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  std::basic_string<>::assign(param_1,abStack_4c,0,*(uint *)npos_exref);
  if (iStack_48 != 0) {
    cVar2 = *(char *)(iStack_48 + -1);
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      *(char *)(iStack_48 + -1) = cVar2 + -1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    FUN_0042da40((char *)(iStack_48 + -1));
  }
  ExceptionList = pvStack_c;
  return param_1;
}



basic_string<> * __thiscall
FUN_00406450(void *this,basic_string<> *param_1,char *param_2,int param_3)

{
  code cVar1;
  bool bVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  basic_string<> local_1c [4];
  code *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f559;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004062c0(this,local_1c,param_2);
  local_4 = 0;
  if (param_3 == 1) {
    FUN_00405b70(this);
  }
  *param_1 = local_1c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar4 = *(uint *)npos_exref;
  uVar5 = local_14;
  if (uVar4 < local_14) {
    uVar5 = uVar4;
  }
  if (param_1 == local_1c) {
    std::basic_string<>::erase(param_1,uVar5,uVar4);
    std::basic_string<>::erase(param_1,0,0);
  }
  else {
    if ((uVar5 != 0) && (uVar5 == local_14)) {
      pcVar3 = local_18;
      if (local_18 == (code *)0x0) {
        pcVar3 = _C_exref;
      }
      if ((byte)pcVar3[-1] < 0xfe) {
        std::basic_string<>::_Tidy(param_1,true);
        pcVar3 = local_18;
        if (local_18 == (code *)0x0) {
          pcVar3 = _C_exref;
        }
        *(code **)(param_1 + 4) = pcVar3;
        *(uint *)(param_1 + 8) = local_14;
        *(undefined4 *)(param_1 + 0xc) = local_10;
        pcVar3[-1] = (code)((char)pcVar3[-1] + '\x01');
        goto LAB_00406569;
      }
    }
    bVar2 = std::basic_string<>::_Grow(param_1,uVar5,true);
    if (bVar2) {
      pcVar3 = local_18;
      if (local_18 == (code *)0x0) {
        pcVar3 = _C_exref;
      }
      pcVar6 = *(code **)(param_1 + 4);
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar6 = pcVar6 + 1;
      }
      std::basic_string<>::_Eos(param_1,uVar5);
    }
  }
LAB_00406569:
  if (local_18 != (code *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 == (code)0x0) || (cVar1 == (code)0xff)) {
      FUN_0042da40(local_18 + -1);
    }
    else {
      local_18[-1] = (code)((char)cVar1 + -1);
    }
  }
  ExceptionList = local_c;
  return param_1;
}



int __fastcall FUN_004065b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
}



int __fastcall FUN_004065e0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
}



// WARNING: Removing unreachable block (ram,0x00406836)

int __thiscall FUN_00406600(void *this,uint param_1)

{
  char cVar1;
  basic_string<> *pbVar2;
  bool bVar3;
  int iVar4;
  basic_string<> *pbVar5;
  basic_string<> *pbVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  basic_string<> local_20 [4];
  undefined4 *local_1c;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f578;
  local_c = ExceptionList;
  if ((*(int *)((int)this + 4) == 0) ||
     ((uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0x14) <= param_1)) {
    local_20[0] = param_1._0_1_;
    ExceptionList = &local_c;
    std::basic_string<>::_Tidy(local_20,false);
    uVar7 = 0xffffffff;
    pcVar11 = &DAT_00443484;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7 - 1;
    bVar3 = std::basic_string<>::_Grow(local_20,uVar7,true);
    if (bVar3) {
      puVar10 = (undefined4 *)&DAT_00443484;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *local_1c = *puVar10;
        puVar10 = puVar10 + 1;
        local_1c = local_1c + 1;
      }
      for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)local_1c = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        local_1c = (undefined4 *)((int)local_1c + 1);
      }
      std::basic_string<>::_Eos(local_20,uVar7);
    }
    local_10 = 1;
    local_e = 0;
    local_f = 0;
    iVar4 = *(int *)((int)this + 4);
    local_4 = 0;
    if (iVar4 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = (*(int *)((int)this + 8) - iVar4) / 0x14;
    }
    pbVar2 = *(basic_string<> **)((int)this + 8);
    uVar7 = (param_1 - iVar9) + 1;
    if ((uint)((*(int *)((int)this + 0xc) - (int)pbVar2) / 0x14) < uVar7) {
      uVar8 = uVar7;
      if ((iVar4 != 0) && (uVar7 < (uint)(((int)pbVar2 - iVar4) / 0x14))) {
        uVar8 = FUN_004065b0((int)this);
      }
      iVar9 = FUN_004065b0((int)this);
      iVar9 = iVar9 + uVar8;
      iVar4 = iVar9;
      if (iVar9 < 0) {
        iVar4 = 0;
      }
      pbVar5 = operator_new(iVar4 * 0x14);
      pbVar6 = FUN_004068e0(*(basic_string<> **)((int)this + 4),pbVar2,pbVar5);
      FUN_00406920(pbVar6,uVar7,local_20);
      FUN_004068e0(pbVar2,*(basic_string<> **)((int)this + 8),pbVar6 + uVar7 * 0x14);
      FUN_004068b0(*(int *)((int)this + 4),*(int *)((int)this + 8));
      FUN_0042da40(*(void **)((int)this + 4));
      *(basic_string<> **)((int)this + 0xc) = pbVar5 + iVar9 * 0x14;
      iVar4 = FUN_004065b0((int)this);
      *(basic_string<> **)((int)this + 4) = pbVar5;
      *(basic_string<> **)((int)this + 8) = pbVar5 + (iVar4 + uVar7) * 0x14;
    }
    else if (uVar7 != 0) {
      FUN_004068e0(pbVar2,pbVar2,pbVar2 + uVar7 * 0x14);
      FUN_00406920(*(basic_string<> **)((int)this + 8),
                   uVar7 - ((int)*(basic_string<> **)((int)this + 8) - (int)pbVar2) / 0x14,local_20)
      ;
      FUN_004069a0(pbVar2,*(basic_string<> **)((int)this + 8),local_20);
      *(uint *)((int)this + 8) = *(int *)((int)this + 8) + uVar7 * 0x14;
    }
    local_4 = 0xffffffff;
    std::basic_string<>::_Tidy(local_20,true);
  }
  ExceptionList = local_c;
  return *(int *)((int)this + 4) + param_1 * 0x14;
}



void FUN_004068b0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    FUN_004025b0(param_1);
  }
  return;
}



basic_string<> *
FUN_004068e0(basic_string<> *param_1,basic_string<> *param_2,basic_string<> *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_004053d0(param_3,param_1);
    param_1 = param_1 + 0x14;
    param_3 = param_3 + 0x14;
  } while (param_1 != param_2);
  return param_3;
}



void FUN_00406920(basic_string<> *param_1,int param_2,basic_string<> *param_3)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004053d0(param_1,param_3);
    param_1 = param_1 + 0x14;
  }
  return;
}



void FUN_00406950(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 != 0) {
      cVar1 = *(char *)(iVar2 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_0042da40((char *)(iVar2 + -1));
      }
      else {
        *(char *)(iVar2 + -1) = cVar1 + -1;
      }
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}



void __cdecl FUN_004069a0(basic_string<> *param_1,basic_string<> *param_2,basic_string<> *param_3)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  
  do {
    if (param_1 == param_2) {
      return;
    }
    uVar6 = *(uint *)npos_exref;
    uVar4 = *(uint *)(param_3 + 8);
    uVar7 = uVar4;
    if (uVar6 < uVar4) {
      uVar7 = uVar6;
    }
    if (param_1 == param_3) {
      if (*(uint *)(param_1 + 8) < uVar7) {
        std::_Xran();
      }
      std::basic_string<>::_Split(param_1);
      uVar4 = *(int *)(param_1 + 8) - uVar7;
      if (uVar4 < uVar6) {
        uVar6 = uVar4;
      }
      if (uVar6 != 0) {
        memmove((void *)(uVar7 + *(int *)(param_1 + 4)),
                (void *)((int)(uVar7 + *(int *)(param_1 + 4)) + uVar6),uVar4 - uVar6);
        iVar2 = *(int *)(param_1 + 8);
        bVar3 = std::basic_string<>::_Grow(param_1,iVar2 - uVar6,false);
        if (bVar3) {
          std::basic_string<>::_Eos(param_1,iVar2 - uVar6);
        }
      }
      std::basic_string<>::_Split(param_1);
    }
    else {
      if ((uVar7 != 0) && (uVar7 == uVar4)) {
        pcVar5 = *(code **)(param_3 + 4);
        if (*(code **)(param_3 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        if ((byte)pcVar5[-1] < 0xfe) {
          iVar2 = *(int *)(param_1 + 4);
          if (iVar2 != 0) {
            cVar1 = *(char *)(iVar2 + -1);
            if ((cVar1 == '\0') || (cVar1 == -1)) {
              FUN_0042da40((char *)(iVar2 + -1));
            }
            else {
              *(char *)(iVar2 + -1) = cVar1 + -1;
            }
          }
          *(undefined4 *)(param_1 + 4) = 0;
          *(undefined4 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0xc) = 0;
          pcVar5 = *(code **)(param_3 + 4);
          if (*(code **)(param_3 + 4) == (code *)0x0) {
            pcVar5 = _C_exref;
          }
          *(code **)(param_1 + 4) = pcVar5;
          *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
          *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
          pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
          goto LAB_00406ada;
        }
      }
      bVar3 = std::basic_string<>::_Grow(param_1,uVar7,true);
      if (bVar3) {
        pcVar5 = *(code **)(param_3 + 4);
        if (*(code **)(param_3 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        pcVar8 = *(code **)(param_1 + 4);
        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar8 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar8 = pcVar8 + 1;
        }
        *(uint *)(param_1 + 8) = uVar7;
        *(undefined1 *)(uVar7 + *(int *)(param_1 + 4)) = 0;
      }
    }
LAB_00406ada:
    param_1[0x10] = param_3[0x10];
    param_1[0x11] = param_3[0x11];
    param_1[0x12] = param_3[0x12];
    param_1 = param_1 + 0x14;
  } while( true );
}



basic_string<> * __cdecl
FUN_00406b00(basic_string<> *param_1,basic_string<> *param_2,basic_string<> *param_3)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  basic_string<> *this;
  basic_string<> *pbVar8;
  code *pcVar9;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    pbVar8 = param_2 + -0x14;
    this = param_3 + -0x14;
    uVar6 = *(uint *)npos_exref;
    uVar4 = *(uint *)(param_2 + -0xc);
    uVar7 = uVar4;
    if (uVar6 < uVar4) {
      uVar7 = uVar6;
    }
    if (this == pbVar8) {
      if (*(uint *)(param_3 + -0xc) < uVar7) {
        std::_Xran();
      }
      std::basic_string<>::_Split(this);
      uVar4 = *(int *)(param_3 + -0xc) - uVar7;
      if (uVar4 < uVar6) {
        uVar6 = uVar4;
      }
      if (uVar6 != 0) {
        memmove((void *)(uVar7 + *(int *)(param_3 + -0x10)),
                (void *)((int)(uVar7 + *(int *)(param_3 + -0x10)) + uVar6),uVar4 - uVar6);
        iVar2 = *(int *)(param_3 + -0xc);
        bVar3 = std::basic_string<>::_Grow(this,iVar2 - uVar6,false);
        if (bVar3) {
          std::basic_string<>::_Eos(this,iVar2 - uVar6);
        }
      }
      std::basic_string<>::_Split(this);
    }
    else {
      if ((uVar7 != 0) && (uVar7 == uVar4)) {
        pcVar5 = *(code **)(param_2 + -0x10);
        if (*(code **)(param_2 + -0x10) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        if ((byte)pcVar5[-1] < 0xfe) {
          iVar2 = *(int *)(param_3 + -0x10);
          if (iVar2 != 0) {
            cVar1 = *(char *)(iVar2 + -1);
            if ((cVar1 == '\0') || (cVar1 == -1)) {
              FUN_0042da40((char *)(iVar2 + -1));
            }
            else {
              *(char *)(iVar2 + -1) = cVar1 + -1;
            }
          }
          *(undefined4 *)(param_3 + -0x10) = 0;
          *(undefined4 *)(param_3 + -0xc) = 0;
          *(undefined4 *)(param_3 + -8) = 0;
          pcVar5 = *(code **)(param_2 + -0x10);
          if (*(code **)(param_2 + -0x10) == (code *)0x0) {
            pcVar5 = _C_exref;
          }
          *(code **)(param_3 + -0x10) = pcVar5;
          *(undefined4 *)(param_3 + -0xc) = *(undefined4 *)(param_2 + -0xc);
          *(undefined4 *)(param_3 + -8) = *(undefined4 *)(param_2 + -8);
          pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
          goto LAB_00406c44;
        }
      }
      bVar3 = std::basic_string<>::_Grow(this,uVar7,true);
      if (bVar3) {
        pcVar5 = *(code **)(param_2 + -0x10);
        if (*(code **)(param_2 + -0x10) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        pcVar9 = *(code **)(param_3 + -0x10);
        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar9 = pcVar9 + 1;
        }
        *(uint *)(param_3 + -0xc) = uVar7;
        *(undefined1 *)(uVar7 + *(int *)(param_3 + -0x10)) = 0;
      }
    }
LAB_00406c44:
    param_3[-4] = param_2[-4];
    param_3[-3] = param_2[-3];
    param_3[-2] = param_2[-2];
    param_3 = this;
    param_2 = pbVar8;
    if (pbVar8 == param_1) {
      return this;
    }
  } while( true );
}



basic_string<> * __thiscall FUN_00406c70(void *this,basic_string<> *param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  void *_Dst;
  uint uVar7;
  code *pcVar8;
  
  uVar7 = *(uint *)npos_exref;
  uVar4 = *(uint *)(param_1 + 8);
  uVar6 = uVar4;
  if (uVar7 < uVar4) {
    uVar6 = uVar7;
  }
  if (this == param_1) {
    if (*(uint *)((int)this + 8) < uVar6) {
      std::_Xran();
    }
    std::basic_string<>::_Split(this);
    uVar4 = *(int *)((int)this + 8) - uVar6;
    if (uVar4 < uVar7) {
      uVar7 = uVar4;
    }
    if (uVar7 != 0) {
      _Dst = (void *)(uVar6 + *(int *)((int)this + 4));
      memmove(_Dst,(void *)((int)_Dst + uVar7),uVar4 - uVar7);
      uVar7 = *(int *)((int)this + 8) - uVar7;
      bVar3 = std::basic_string<>::_Grow(this,uVar7,false);
      if (bVar3) {
        std::basic_string<>::_Eos(this,uVar7);
      }
    }
    std::basic_string<>::_Split(this);
  }
  else {
    if ((uVar6 != 0) && (uVar6 == uVar4)) {
      pcVar5 = *(code **)(param_1 + 4);
      if (*(code **)(param_1 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      if ((byte)pcVar5[-1] < 0xfe) {
        iVar2 = *(int *)((int)this + 4);
        if (iVar2 != 0) {
          cVar1 = *(char *)(iVar2 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_0042da40((char *)(iVar2 + -1));
          }
          else {
            *(char *)(iVar2 + -1) = cVar1 + -1;
          }
        }
        *(undefined4 *)((int)this + 4) = 0;
        *(undefined4 *)((int)this + 8) = 0;
        *(undefined4 *)((int)this + 0xc) = 0;
        pcVar5 = *(code **)(param_1 + 4);
        if (*(code **)(param_1 + 4) == (code *)0x0) {
          pcVar5 = _C_exref;
        }
        *(code **)((int)this + 4) = pcVar5;
        *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
        pcVar5[-1] = (code)((char)pcVar5[-1] + '\x01');
        goto LAB_00406d9d;
      }
    }
    bVar3 = std::basic_string<>::_Grow(this,uVar6,true);
    if (bVar3) {
      pcVar5 = *(code **)(param_1 + 4);
      if (*(code **)(param_1 + 4) == (code *)0x0) {
        pcVar5 = _C_exref;
      }
      pcVar8 = *(code **)((int)this + 4);
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
      }
      *(uint *)((int)this + 8) = uVar6;
      *(undefined1 *)(uVar6 + *(int *)((int)this + 4)) = 0;
    }
  }
LAB_00406d9d:
  *(basic_string<> *)((int)this + 0x10) = param_1[0x10];
  *(basic_string<> *)((int)this + 0x11) = param_1[0x11];
  return this;
}



void __thiscall FUN_00406dc0(void *this,int param_1)

{
  char cVar1;
  code cVar2;
  basic_string<> *pbVar3;
  uint uVar4;
  uint uVar5;
  basic_string<> *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char *pcVar10;
  basic_string<> *pbVar11;
  basic_string<> *pbVar12;
  char **ppcVar13;
  int local_48;
  undefined **local_44;
  undefined4 local_40;
  basic_string<> local_3c [4];
  int local_38;
  uint local_34;
  undefined4 local_30;
  char *local_2c [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f599;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar4 = FUN_00405770(param_1);
  if (*(int *)((int)this + 4) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)((int)this + 0xc) - *(int *)((int)this + 4) >> 4;
  }
  if (uVar5 < uVar4) {
    uVar5 = uVar4;
    if ((int)uVar4 < 0) {
      uVar5 = 0;
    }
    pbVar6 = operator_new(uVar5 << 4);
    pbVar3 = *(basic_string<> **)((int)this + 8);
    pbVar12 = pbVar6;
    for (pbVar11 = *(basic_string<> **)((int)this + 4); pbVar11 != pbVar3; pbVar11 = pbVar11 + 0x10)
    {
      FUN_004047e0(pbVar12,pbVar11);
      pbVar12 = pbVar12 + 0x10;
    }
    FUN_00406950(*(int *)((int)this + 4),*(int *)((int)this + 8));
    FUN_0042da40(*(void **)((int)this + 4));
    *(basic_string<> **)((int)this + 0xc) = pbVar6 + uVar4 * 0x10;
    iVar7 = FUN_004065e0((int)this);
    *(basic_string<> **)((int)this + 4) = pbVar6;
    *(basic_string<> **)((int)this + 8) = pbVar6 + iVar7 * 0x10;
  }
  local_48 = 0;
  if (0 < (int)uVar4) {
    do {
      local_44 = &PTR_LAB_0043026c;
      local_40 = *(undefined4 *)(param_1 + 0x18);
      puVar8 = (undefined4 *)FUN_00403cb0(&local_44,local_48);
      ppcVar13 = local_2c;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppcVar13 = (char *)*puVar8;
        puVar8 = puVar8 + 1;
        ppcVar13 = ppcVar13 + 1;
      }
      local_3c[0] = param_1._0_1_;
      uVar5 = 0xffffffff;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      pcVar10 = local_2c[0];
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      std::basic_string<>::assign(local_3c,local_2c[0],~uVar5 - 1);
      uVar5 = 0;
      local_4 = 0;
      if (local_34 != 0) {
        do {
          pcVar9 = _C_exref;
          if (local_38 != 0) {
            std::basic_string<>::_Freeze(local_3c);
            pcVar9 = (code *)(local_38 + uVar5);
          }
          cVar2 = *pcVar9;
          pcVar10 = std::basic_string<>::operator[](local_3c,uVar5);
          iVar7 = tolower((int)(char)cVar2);
          *pcVar10 = (char)iVar7;
          uVar5 = uVar5 + 1;
        } while (uVar5 < local_34);
      }
      FUN_00403620(this,*(basic_string<> **)((int)this + 8),1,local_3c);
      local_4 = 0xffffffff;
      if (local_38 != 0) {
        cVar1 = *(char *)(local_38 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_0042da40((char *)(local_38 + -1));
        }
        else {
          *(char *)(local_38 + -1) = cVar1 + -1;
        }
      }
      local_48 = local_48 + 1;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
    } while (local_48 < (int)uVar4);
  }
  ExceptionList = local_c;
  return;
}



void FUN_00406fd0(void)

{
                    // WARNING: Could not recover jumptable at 0x00406fd5. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_00443495);
  return;
}



void FUN_00406fe0(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00406ff0);
  return;
}



void FUN_00407010(void)

{
                    // WARNING: Could not recover jumptable at 0x00407015. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_00443494);
  return;
}



void FUN_00407020(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00407030);
  return;
}



// WARNING: Removing unreachable block (ram,0x004072be)

void __thiscall FUN_00407060(void *this,int param_1)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int local_18;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  uVar1 = FUN_00405770(param_1);
  if (*(int *)((int)this + 4) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)((int)this + 0xc) - *(int *)((int)this + 4)) / 0xc;
  }
  if (uVar4 < uVar1) {
    uVar4 = uVar1;
    if ((int)uVar1 < 0) {
      uVar4 = 0;
    }
    pvVar2 = operator_new(uVar4 * 0xc);
    iVar5 = *(int *)((int)this + 8);
    pvVar6 = pvVar2;
    for (iVar7 = *(int *)((int)this + 4); iVar7 != iVar5; iVar7 = iVar7 + 0xc) {
      FUN_004074a0((int)pvVar6,iVar7);
      pvVar6 = (void *)((int)pvVar6 + 0xc);
    }
    FUN_0042da40(*(void **)((int)this + 4));
    *(void **)((int)this + 0xc) = (void *)((int)pvVar2 + uVar1 * 0xc);
    if (*(int *)((int)this + 4) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0xc;
    }
    *(void **)((int)this + 4) = pvVar2;
    *(void **)((int)this + 8) = (void *)((int)pvVar2 + iVar5 * 0xc);
  }
  local_18 = 0;
  if (0 < (int)uVar1) {
    do {
      iVar5 = (**(code **)(*(int *)(param_1 + 0x14) + 4))(local_18);
      iVar7 = FUN_00407f50(*(int *)(iVar5 + 0xc),(byte)(*(uint *)(iVar5 + 0x18) >> 5) & 1,
                           ~*(byte *)(iVar5 + 0x18) & 1);
      uStack_4 = (undefined1)iVar7;
      uStack_c = *(undefined4 *)(iVar5 + 0x10);
      uStack_8 = *(undefined4 *)(iVar5 + 0x14);
      iVar5 = *(int *)((int)this + 8);
      iVar3 = *(int *)((int)this + 0xc) - iVar5;
      iVar7 = iVar3 >> 0x1f;
      if (iVar3 / 0xc + iVar7 == iVar7) {
        uVar4 = FUN_00407310((int)this);
        if (uVar4 < 2) {
          iVar7 = 1;
        }
        else {
          iVar7 = FUN_00407310((int)this);
        }
        iVar3 = FUN_00407310((int)this);
        iVar3 = iVar3 + iVar7;
        iVar7 = iVar3;
        if (iVar3 < 0) {
          iVar7 = 0;
        }
        pvVar6 = operator_new(iVar7 * 0xc);
        iVar7 = FUN_00407340(*(int *)((int)this + 4),iVar5,(int)pvVar6);
        FUN_00407380(iVar7,1,(int)&uStack_c);
        FUN_00407340(iVar5,*(int *)((int)this + 8),iVar7 + 0xc);
        FUN_00407330();
        FUN_0042da40(*(void **)((int)this + 4));
        *(void **)((int)this + 0xc) = (void *)((int)pvVar6 + iVar3 * 0xc);
        iVar5 = FUN_00407310((int)this);
        *(void **)((int)this + 4) = pvVar6;
        *(void **)((int)this + 8) = (void *)((int)pvVar6 + (iVar5 + 1) * 0xc);
      }
      else {
        FUN_00407340(iVar5,iVar5,iVar5 + 0xc);
        FUN_00407380(*(int *)((int)this + 8),1 - (*(int *)((int)this + 8) - iVar5) / 0xc,
                     (int)&uStack_c);
        FUN_00407450(iVar5,*(int *)((int)this + 8),(int)&uStack_c);
        *(int *)((int)this + 8) = *(int *)((int)this + 8) + 0xc;
      }
      local_18 = local_18 + 1;
    } while (local_18 < (int)uVar1);
  }
  return;
}



int __fastcall FUN_00407310(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
}



void FUN_00407330(void)

{
  return;
}



int FUN_00407340(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_004074a0(param_3,param_1);
    param_1 = param_1 + 0xc;
    param_3 = param_3 + 0xc;
  } while (param_1 != param_2);
  return param_3;
}



void FUN_00407380(int param_1,int param_2,int param_3)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004074a0(param_1,param_3);
    param_1 = param_1 + 0xc;
  }
  return;
}



void FUN_004073c0(void)

{
                    // WARNING: Could not recover jumptable at 0x004073c5. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_00443499);
  return;
}



void FUN_004073d0(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_004073e0);
  return;
}



void FUN_00407400(void)

{
                    // WARNING: Could not recover jumptable at 0x00407405. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_00443498);
  return;
}



void FUN_00407410(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00407420);
  return;
}



void __cdecl FUN_00407450(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_3 + 8);
  }
  return;
}



void __cdecl FUN_00407470(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_2 = param_2 + -0xc) {
    *(undefined1 *)(param_3 + -4) = *(undefined1 *)(param_2 + -4);
    param_3 = param_3 + -0xc;
  }
  return;
}



void __cdecl FUN_004074a0(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  }
  return;
}



void mysql_connect(void)

{
                    // WARNING: Could not recover jumptable at 0x004074c0. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_connect();
  return;
}



void mysql_close(void)

{
                    // WARNING: Could not recover jumptable at 0x004074c6. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_close();
  return;
}



void mysql_select_db(void)

{
                    // WARNING: Could not recover jumptable at 0x004074cc. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_select_db();
  return;
}



void mysql_query(void)

{
                    // WARNING: Could not recover jumptable at 0x004074d2. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_query();
  return;
}



void mysql_store_result(void)

{
                    // WARNING: Could not recover jumptable at 0x004074d8. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_store_result();
  return;
}



void mysql_error(void)

{
                    // WARNING: Could not recover jumptable at 0x004074de. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_error();
  return;
}



void mysql_escape_string(void)

{
                    // WARNING: Could not recover jumptable at 0x004074e4. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_escape_string();
  return;
}



void FUN_00407500(void)

{
                    // WARNING: Could not recover jumptable at 0x00407505. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ios_base::Init::Init((Init *)&DAT_004434b1);
  return;
}



void FUN_00407510(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00407520);
  return;
}



void FUN_00407540(void)

{
                    // WARNING: Could not recover jumptable at 0x00407545. Too many branches
                    // WARNING: Treating indirect jump as call
  std::_Winit::_Winit((_Winit *)&DAT_004434b0);
  return;
}



void FUN_00407550(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00407560);
  return;
}



void __thiscall
FUN_00407cc0(void *this,undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined1 *)((int)this + 8) = param_3;
  *(undefined1 *)((int)this + 9) = param_4;
  return;
}



void FUN_00407cf0(void)

{
  FUN_00407e30(&DAT_004434a0,0x4434b8,0x3e);
  return;
}



void FUN_00407d10(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_00407d20);
  return;
}



void __fastcall FUN_00407d40(void *param_1)

{
  int *piVar1;
  int *piVar2;
  int *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)((int)param_1 + 4);
  local_c = (int *)*piVar1;
  piVar2 = local_c;
  if (*(int *)((int)param_1 + 0xc) == 0) {
    while (local_c = piVar2, piVar2 != piVar1) {
      FUN_00408b60((int *)&local_c);
      FUN_00408360(param_1,&local_4,piVar2);
      piVar2 = local_c;
    }
  }
  else {
    piVar2 = (int *)piVar1[1];
    if ((int *)piVar1[1] != DAT_004437a8) {
      do {
        FUN_00408770((int *)piVar2[2]);
        piVar1 = (int *)*piVar2;
        FUN_0042da40(piVar2);
        piVar2 = piVar1;
      } while (piVar1 != DAT_004437a8);
    }
    *(int **)(*(int *)((int)param_1 + 4) + 4) = DAT_004437a8;
    *(undefined4 *)((int)param_1 + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
    *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
    FUN_00402be0(param_1,&local_8);
  }
  FUN_0042da40(*(void **)((int)param_1 + 4));
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 0xc) = 0;
  std::_Lockit::_Lockit((_Lockit *)&local_c);
  piVar1 = DAT_004437a8;
  DAT_004437a4 = DAT_004437a4 + -1;
  piVar2 = (int *)0x0;
  if (DAT_004437a4 == 0) {
    DAT_004437a8 = (int *)0x0;
    piVar2 = piVar1;
  }
  std::_Lockit::~_Lockit((_Lockit *)&local_c);
  if (piVar2 != (int *)0x0) {
    FUN_0042da40(piVar2);
  }
  return;
}



undefined1 * __thiscall FUN_00407e30(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  _Lockit local_24 [4];
  void *local_20;
  int local_1c;
  undefined1 local_18;
  int local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f5b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)this = (undefined1)param_2;
  *(undefined1 *)((int)this + 1) = (undefined1)param_2;
  *(undefined1 *)((int)this + 8) = 0;
  local_20 = this;
  puVar1 = operator_new(0x18);
  iVar3 = 0;
  puVar1[1] = 0;
  puVar1[5] = 1;
  std::_Lockit::_Lockit(local_24);
  if (DAT_004437a8 == (undefined4 *)0x0) {
    DAT_004437a8 = puVar1;
    *puVar1 = 0;
    puVar1 = (undefined4 *)0x0;
    DAT_004437a8[2] = 0;
  }
  DAT_004437a4 = DAT_004437a4 + 1;
  std::_Lockit::~_Lockit(local_24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0042da40(puVar1);
  }
  puVar1 = DAT_004437a8;
  pvVar2 = operator_new(0x18);
  *(undefined4 **)((int)pvVar2 + 4) = puVar1;
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  *(void **)((int)this + 4) = pvVar2;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
  local_4 = 0;
  if (param_2 != 0) {
    piVar4 = (int *)(param_1 + 4);
    do {
      if (*(char *)((int)piVar4 + 5) != '\0') {
        local_1c = *piVar4;
        local_18 = 0;
        FUN_00408110(this,local_14,&local_1c);
        *(char *)(local_14[0] + 0x10) = (char)iVar3;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 3;
    } while (iVar3 != param_2);
  }
  ExceptionList = local_c;
  return this;
}



int __cdecl FUN_00407f50(int param_1,char param_2,char param_3)

{
  if (param_3 == '\0') {
    if (param_2 != '\0') {
      return param_1 + 0x15;
    }
    if (199 < param_1) {
      param_1 = param_1 + -0xea;
    }
    return param_1;
  }
  if (param_2 != '\0') {
    return param_1 + 0x34;
  }
  if (param_1 < 200) {
    return param_1 + 0x1f;
  }
  return param_1 + -0xcb;
}



undefined4 __fastcall FUN_00407fa0(int param_1)

{
  int iVar1;
  
  iVar1 = type_info::operator==
                    (*(type_info **)
                      (&DAT_004434bc +
                      (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] * 0xc),
                     (type_info *)&std::basic_string<>::RTTI_Type_Descriptor);
  if (iVar1 == 0) {
    iVar1 = type_info::operator==
                      (*(type_info **)
                        (&DAT_004434bc +
                        (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] * 0xc),
                       (type_info *)&MysqlDate::RTTI_Type_Descriptor);
    if (iVar1 == 0) {
      iVar1 = type_info::operator==
                        (*(type_info **)
                          (&DAT_004434bc +
                          (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] * 0xc),
                         (type_info *)&MysqlTime::RTTI_Type_Descriptor);
      if (iVar1 == 0) {
        iVar1 = type_info::operator==
                          (*(type_info **)
                            (&DAT_004434bc +
                            (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] * 0xc),
                           (type_info *)&MysqlDateTime::RTTI_Type_Descriptor);
        if (iVar1 == 0) {
          iVar1 = type_info::operator==
                            (*(type_info **)
                              (&DAT_004434bc +
                              (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] * 0xc)
                             ,(type_info *)&std::basic_string<>::RTTI_Type_Descriptor);
          if (iVar1 == 0) {
            iVar1 = type_info::operator==
                              (*(type_info **)
                                (&DAT_004434bc +
                                (uint)(byte)(&DAT_004434c0)[(uint)*(byte *)(param_1 + 8) * 0xc] *
                                0xc),(type_info *)&MysqlSet<>::RTTI_Type_Descriptor);
            if (iVar1 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



bool __fastcall FUN_004080f0(int param_1)

{
  int iVar1;
  
  iVar1 = type_info::operator==
                    (*(type_info **)(&DAT_004434bc + (uint)*(byte *)(param_1 + 8) * 0xc),
                     (type_info *)&std::basic_string<>::RTTI_Type_Descriptor);
  return iVar1 != 0;
}



void __thiscall FUN_00408110(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int *local_4;
  
  piVar1 = param_2;
  piVar5 = *(int **)((int)this + 4);
  bVar7 = true;
  piVar6 = (int *)piVar5[1];
  local_4 = this;
  if (piVar6 != DAT_004437a8) {
    do {
      piVar5 = piVar6;
      iVar3 = type_info::before((type_info *)*piVar1,(type_info *)piVar5[3]);
      bVar7 = iVar3 != 0;
      if (bVar7) {
        piVar6 = (int *)*piVar5;
      }
      else {
        piVar6 = (int *)piVar5[2];
      }
    } while (piVar6 != DAT_004437a8);
  }
  if (*(char *)((int)this + 8) != '\0') {
    param_2 = (int *)FUN_00408ae0(piVar5,0);
    *param_2 = (int)DAT_004437a8;
    param_2[2] = (int)DAT_004437a8;
    FUN_00408bb0(param_2 + 3,piVar1);
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    if (((piVar5 == *(int **)((int)this + 4)) || (piVar6 != DAT_004437a8)) ||
       (iVar3 = type_info::before((type_info *)*piVar1,(type_info *)piVar5[3]), iVar3 != 0)) {
      *piVar5 = (int)param_2;
      piVar6 = *(int **)((int)this + 4);
      if (piVar5 == piVar6) {
        piVar6[1] = (int)param_2;
        *(int **)(*(int *)((int)this + 4) + 8) = param_2;
      }
      else if (piVar5 == (int *)*piVar6) {
        *piVar6 = (int)param_2;
      }
    }
    else {
      piVar5[2] = (int)param_2;
      if (piVar5 == *(int **)(*(int *)((int)this + 4) + 8)) {
        *(int **)(*(int *)((int)this + 4) + 8) = param_2;
      }
    }
    piVar6 = param_2;
    piVar5 = param_2;
    if (param_2 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        piVar1 = (int *)piVar5[1];
        if (piVar1[5] != 0) break;
        piVar2 = *(int **)piVar1[1];
        if (piVar1 == piVar2) {
          iVar3 = ((undefined4 *)piVar1[1])[2];
          if (*(int *)(iVar3 + 0x14) == 0) {
            piVar1[5] = 1;
            *(undefined4 *)(iVar3 + 0x14) = 1;
            *(undefined4 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
            piVar5 = *(int **)(piVar5[1] + 4);
          }
          else {
            if (piVar5 == (int *)piVar1[2]) {
              FUN_00408a20(this,(int)piVar1);
              piVar5 = piVar1;
            }
            *(undefined4 *)(piVar5[1] + 0x14) = 1;
            *(undefined4 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
            FUN_00408a80(this,*(int **)(piVar5[1] + 4));
          }
        }
        else if (piVar2[5] == 0) {
          piVar1[5] = 1;
          piVar2[5] = 1;
          *(undefined4 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
          piVar5 = *(int **)(piVar5[1] + 4);
        }
        else {
          if (piVar5 == (int *)*piVar1) {
            FUN_00408a80(this,piVar1);
            piVar5 = piVar1;
          }
          *(undefined4 *)(piVar5[1] + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
          FUN_00408a20(this,*(int *)(piVar5[1] + 4));
        }
      } while (piVar5 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x14) = 1;
    *param_1 = piVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  local_4 = piVar5;
  if (bVar7) {
    if (piVar5 == (int *)**(int **)((int)this + 4)) goto LAB_00408321;
    FUN_00408b00((int *)&local_4);
  }
  iVar3 = type_info::before((type_info *)local_4[3],(type_info *)*piVar1);
  if (iVar3 == 0) {
    *param_1 = local_4;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_00408321:
  puVar4 = (undefined4 *)FUN_004087b0(this,&param_2,(int)piVar6,piVar5,piVar1);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



void __thiscall FUN_00408360(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *local_c;
  _Lockit local_4 [4];
  
  piVar3 = param_2;
  FUN_00408b60((int *)&param_2);
  piVar8 = (int *)*piVar3;
  piVar6 = piVar3 + 2;
  local_c = piVar3;
  piVar7 = piVar6;
  if (piVar8 == DAT_004437a8) {
    piVar8 = (int *)*piVar6;
  }
  else {
    piVar1 = (int *)*piVar6;
    if (piVar1 != DAT_004437a8) {
      local_c = piVar1;
      for (piVar7 = (int *)*piVar1; piVar7 != DAT_004437a8; piVar7 = (int *)*piVar7) {
        local_c = piVar7;
      }
      piVar8 = (int *)local_c[2];
      piVar7 = local_c + 2;
    }
  }
  piVar1 = local_c;
  std::_Lockit::_Lockit(local_4);
  if (local_c == piVar3) {
    piVar8[1] = local_c[1];
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar3) {
      *(int **)(*(int *)((int)this + 4) + 4) = piVar8;
    }
    else {
      piVar7 = (int *)piVar3[1];
      if ((int *)*piVar7 == piVar3) {
        *piVar7 = (int)piVar8;
      }
      else {
        piVar7[2] = (int)piVar8;
      }
    }
    piVar7 = *(int **)((int)this + 4);
    if ((int *)*piVar7 == piVar3) {
      if ((int *)*piVar6 == DAT_004437a8) {
        *piVar7 = piVar3[1];
      }
      else {
        piVar1 = (int *)*piVar8;
        piVar6 = piVar8;
        while (piVar5 = piVar1, piVar5 != DAT_004437a8) {
          piVar6 = piVar5;
          piVar1 = (int *)*piVar5;
        }
        *piVar7 = (int)piVar6;
      }
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar3) {
      if ((int *)*piVar3 == DAT_004437a8) {
        piVar6 = (int *)piVar3[1];
      }
      else {
        piVar7 = (int *)piVar8[2];
        piVar6 = piVar8;
        while (piVar3 = piVar7, piVar3 != DAT_004437a8) {
          piVar6 = piVar3;
          piVar7 = (int *)piVar3[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  else {
    *(int **)(*piVar3 + 4) = local_c;
    *local_c = *piVar3;
    if (local_c == (int *)*piVar6) {
      piVar8[1] = (int)local_c;
    }
    else {
      piVar8[1] = local_c[1];
      *(int **)local_c[1] = piVar8;
      *piVar7 = *piVar6;
      *(int **)(*piVar6 + 4) = local_c;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar3) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_c;
    }
    else {
      piVar6 = (int *)piVar3[1];
      if ((int *)*piVar6 == piVar3) {
        *piVar6 = (int)local_c;
      }
      else {
        piVar6[2] = (int)local_c;
      }
    }
    local_c = piVar3;
    piVar1[1] = piVar3[1];
    iVar2 = piVar1[5];
    piVar1[5] = piVar3[5];
    piVar3[5] = iVar2;
  }
  if (local_c[5] == 1) {
    if (piVar8 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        if (piVar8[5] != 1) break;
        piVar6 = *(int **)piVar8[1];
        if (piVar8 == piVar6) {
          piVar6 = (int *)((undefined4 *)piVar8[1])[2];
          if (piVar6[5] == 0) {
            piVar6[5] = 1;
            *(undefined4 *)(piVar8[1] + 0x14) = 0;
            iVar2 = piVar8[1];
            piVar6 = *(int **)(iVar2 + 8);
            *(int *)(iVar2 + 8) = *piVar6;
            if ((int *)*piVar6 != DAT_004437a8) {
              ((int *)*piVar6)[1] = iVar2;
            }
            piVar6[1] = *(int *)(iVar2 + 4);
            if (iVar2 == *(int *)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
            }
            else {
              piVar7 = *(int **)(iVar2 + 4);
              if (iVar2 == *piVar7) {
                *piVar7 = (int)piVar6;
              }
              else {
                piVar7[2] = (int)piVar6;
              }
            }
            *piVar6 = iVar2;
            *(int **)(iVar2 + 4) = piVar6;
            piVar6 = *(int **)(piVar8[1] + 8);
          }
          if ((*(int *)(*piVar6 + 0x14) != 1) || (*(int *)(piVar6[2] + 0x14) != 1)) {
            if (*(int *)(piVar6[2] + 0x14) == 1) {
              *(undefined4 *)(*piVar6 + 0x14) = 1;
              iVar2 = *piVar6;
              piVar6[5] = 0;
              *piVar6 = *(int *)(iVar2 + 8);
              if (*(int **)(iVar2 + 8) != DAT_004437a8) {
                (*(int **)(iVar2 + 8))[1] = (int)piVar6;
              }
              *(int *)(iVar2 + 4) = piVar6[1];
              if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
                *(int *)(*(int *)((int)this + 4) + 4) = iVar2;
              }
              else {
                piVar7 = (int *)piVar6[1];
                if (piVar6 == (int *)piVar7[2]) {
                  piVar7[2] = iVar2;
                }
                else {
                  *piVar7 = iVar2;
                }
              }
              *(int **)(iVar2 + 8) = piVar6;
              piVar6[1] = iVar2;
              piVar6 = *(int **)(piVar8[1] + 8);
            }
            piVar6[5] = *(int *)(piVar8[1] + 0x14);
            *(undefined4 *)(piVar8[1] + 0x14) = 1;
            *(undefined4 *)(piVar6[2] + 0x14) = 1;
            piVar6 = (int *)piVar8[1];
            piVar7 = (int *)piVar6[2];
            piVar6[2] = *piVar7;
            if ((int *)*piVar7 != DAT_004437a8) {
              ((int *)*piVar7)[1] = (int)piVar6;
            }
            piVar7[1] = piVar6[1];
            if (piVar6 == (int *)*(int *)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
              *piVar7 = (int)piVar6;
            }
            else {
              piVar3 = (int *)piVar6[1];
              if (piVar6 == (int *)*piVar3) {
                *piVar3 = (int)piVar7;
                *piVar7 = (int)piVar6;
              }
              else {
                piVar3[2] = (int)piVar7;
                *piVar7 = (int)piVar6;
              }
            }
LAB_00408730:
            piVar6[1] = (int)piVar7;
            break;
          }
        }
        else {
          if (piVar6[5] == 0) {
            piVar6[5] = 1;
            *(undefined4 *)(piVar8[1] + 0x14) = 0;
            piVar6 = (int *)piVar8[1];
            iVar2 = *piVar6;
            *piVar6 = *(int *)(iVar2 + 8);
            if (*(int **)(iVar2 + 8) != DAT_004437a8) {
              (*(int **)(iVar2 + 8))[1] = (int)piVar6;
            }
            *(int *)(iVar2 + 4) = piVar6[1];
            if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int *)(*(int *)((int)this + 4) + 4) = iVar2;
            }
            else {
              piVar7 = (int *)piVar6[1];
              if (piVar6 == (int *)piVar7[2]) {
                piVar7[2] = iVar2;
              }
              else {
                *piVar7 = iVar2;
              }
            }
            *(int **)(iVar2 + 8) = piVar6;
            piVar6[1] = iVar2;
            piVar6 = *(int **)piVar8[1];
          }
          if ((*(int *)(piVar6[2] + 0x14) != 1) || (*(int *)(*piVar6 + 0x14) != 1)) {
            if (*(int *)(*piVar6 + 0x14) == 1) {
              *(undefined4 *)(piVar6[2] + 0x14) = 1;
              piVar7 = (int *)piVar6[2];
              piVar6[5] = 0;
              piVar6[2] = *piVar7;
              if ((int *)*piVar7 != DAT_004437a8) {
                ((int *)*piVar7)[1] = (int)piVar6;
              }
              piVar7[1] = piVar6[1];
              if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
                *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
              }
              else {
                piVar3 = (int *)piVar6[1];
                if (piVar6 == (int *)*piVar3) {
                  *piVar3 = (int)piVar7;
                }
                else {
                  piVar3[2] = (int)piVar7;
                }
              }
              *piVar7 = (int)piVar6;
              piVar6[1] = (int)piVar7;
              piVar6 = *(int **)piVar8[1];
            }
            piVar6[5] = *(int *)(piVar8[1] + 0x14);
            *(undefined4 *)(piVar8[1] + 0x14) = 1;
            *(undefined4 *)(*piVar6 + 0x14) = 1;
            piVar6 = (int *)piVar8[1];
            piVar7 = (int *)*piVar6;
            *piVar6 = piVar7[2];
            if ((int *)piVar7[2] != DAT_004437a8) {
              ((int *)piVar7[2])[1] = (int)piVar6;
            }
            piVar7[1] = piVar6[1];
            if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
            }
            else {
              puVar4 = (undefined4 *)piVar6[1];
              if (piVar6 == (int *)puVar4[2]) {
                puVar4[2] = piVar7;
              }
              else {
                *puVar4 = piVar7;
              }
            }
            piVar7[2] = (int)piVar6;
            goto LAB_00408730;
          }
        }
        piVar6[5] = 0;
        piVar8 = (int *)piVar8[1];
      } while (piVar8 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    piVar8[5] = 1;
  }
  std::_Lockit::~_Lockit(local_4);
  FUN_0042da40(local_c);
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  *param_1 = param_2;
  return;
}



void FUN_00408770(int *param_1)

{
  int *piVar1;
  
  if (param_1 != DAT_004437a8) {
    do {
      FUN_00408770((int *)param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_0042da40(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_004437a8);
  }
  return;
}



void __thiscall
FUN_004087b0(void *this,undefined4 *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar2 = operator_new(0x18);
  piVar2[1] = (int)param_3;
  piVar2[5] = 0;
  *piVar2 = DAT_004437a8;
  piVar2[2] = DAT_004437a8;
  FUN_00408bb0(piVar2 + 3,param_4);
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  if ((param_3 != *(int **)((int)this + 4)) && (param_2 == DAT_004437a8)) {
    iVar3 = type_info::before((type_info *)*param_4,(type_info *)param_3[3]);
    if (iVar3 == 0) {
      param_3[2] = (int)piVar2;
      if (param_3 == *(int **)(*(int *)((int)this + 4) + 8)) {
        *(int **)(*(int *)((int)this + 4) + 8) = piVar2;
      }
      goto LAB_00408845;
    }
  }
  *param_3 = (int)piVar2;
  piVar4 = *(int **)((int)this + 4);
  if (param_3 == piVar4) {
    piVar4[1] = (int)piVar2;
    *(int **)(*(int *)((int)this + 4) + 8) = piVar2;
  }
  else if (param_3 == (int *)*piVar4) {
    *piVar4 = (int)piVar2;
  }
LAB_00408845:
  piVar4 = piVar2;
  if (piVar2 != *(int **)(*(int *)((int)this + 4) + 4)) {
    do {
      piVar5 = (int *)piVar4[1];
      if (piVar5[5] != 0) break;
      piVar6 = *(int **)piVar5[1];
      if (piVar5 == piVar6) {
        iVar3 = ((undefined4 *)piVar5[1])[2];
        if (*(int *)(iVar3 + 0x14) == 0) {
          piVar5[5] = 1;
          *(undefined4 *)(iVar3 + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar4[1] + 4) + 0x14) = 0;
          piVar4 = *(int **)(piVar4[1] + 4);
        }
        else {
          if (piVar4 == (int *)piVar5[2]) {
            piVar4 = (int *)piVar5[2];
            piVar5[2] = *piVar4;
            if (*piVar4 != DAT_004437a8) {
              *(int **)(*piVar4 + 4) = piVar5;
            }
            piVar4[1] = piVar5[1];
            if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int **)(*(int *)((int)this + 4) + 4) = piVar4;
            }
            else {
              piVar6 = (int *)piVar5[1];
              if (piVar5 == (int *)*piVar6) {
                *piVar6 = (int)piVar4;
              }
              else {
                piVar6[2] = (int)piVar4;
              }
            }
            *piVar4 = (int)piVar5;
            piVar5[1] = (int)piVar4;
            piVar4 = piVar5;
          }
          *(undefined4 *)(piVar4[1] + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar4[1] + 4) + 0x14) = 0;
          piVar5 = *(int **)(piVar4[1] + 4);
          piVar6 = (int *)*piVar5;
          *piVar5 = piVar6[2];
          if (piVar6[2] != DAT_004437a8) {
            *(int **)(piVar6[2] + 4) = piVar5;
          }
          piVar6[1] = piVar5[1];
          if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
            piVar6[2] = (int)piVar5;
          }
          else {
            piVar1 = (int *)piVar5[1];
            if (piVar5 == (int *)piVar1[2]) {
              piVar1[2] = (int)piVar6;
              piVar6[2] = (int)piVar5;
            }
            else {
              *piVar1 = (int)piVar6;
              piVar6[2] = (int)piVar5;
            }
          }
LAB_004089f3:
          piVar5[1] = (int)piVar6;
        }
      }
      else {
        if (piVar6[5] != 0) {
          if (piVar4 == (int *)*piVar5) {
            iVar3 = *piVar5;
            *piVar5 = *(int *)(iVar3 + 8);
            if (*(int *)(iVar3 + 8) != DAT_004437a8) {
              *(int **)(*(int *)(iVar3 + 8) + 4) = piVar5;
            }
            *(int *)(iVar3 + 4) = piVar5[1];
            if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
              *(int *)(*(int *)((int)this + 4) + 4) = iVar3;
            }
            else {
              piVar4 = (int *)piVar5[1];
              if (piVar5 == (int *)piVar4[2]) {
                piVar4[2] = iVar3;
              }
              else {
                *piVar4 = iVar3;
              }
            }
            *(int **)(iVar3 + 8) = piVar5;
            piVar5[1] = iVar3;
            piVar4 = piVar5;
          }
          *(undefined4 *)(piVar4[1] + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar4[1] + 4) + 0x14) = 0;
          piVar5 = *(int **)(piVar4[1] + 4);
          piVar6 = (int *)piVar5[2];
          piVar5[2] = *piVar6;
          if (*piVar6 != DAT_004437a8) {
            *(int **)(*piVar6 + 4) = piVar5;
          }
          piVar6[1] = piVar5[1];
          if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
          }
          else {
            piVar1 = (int *)piVar5[1];
            if (piVar5 == (int *)*piVar1) {
              *piVar1 = (int)piVar6;
            }
            else {
              piVar1[2] = (int)piVar6;
            }
          }
          *piVar6 = (int)piVar5;
          goto LAB_004089f3;
        }
        piVar5[5] = 1;
        piVar6[5] = 1;
        *(undefined4 *)(*(int *)(piVar4[1] + 4) + 0x14) = 0;
        piVar4 = *(int **)(piVar4[1] + 4);
      }
    } while (piVar4 != *(int **)(*(int *)((int)this + 4) + 4));
  }
  *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x14) = 1;
  *param_1 = piVar2;
  return;
}



void __thiscall FUN_00408a20(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*piVar1 != DAT_004437a8) {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 4) + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



void __thiscall FUN_00408a80(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(int *)(iVar1 + 8) != DAT_004437a8) {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 4) + 4)) {
    *(int *)(*(int *)((int)this + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



void FUN_00408ae0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x18);
  *(undefined4 *)((int)pvVar1 + 4) = param_1;
  *(undefined4 *)((int)pvVar1 + 0x14) = param_2;
  return;
}



void __fastcall FUN_00408b00(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if ((piVar3[5] == 0) && (*(int **)(piVar3[1] + 4) == piVar3)) {
    *param_1 = piVar3[2];
    return;
  }
  iVar1 = *piVar3;
  if (iVar1 == DAT_004437a8) {
    piVar3 = (int *)piVar3[1];
    if (*param_1 == *piVar3) {
      do {
        *param_1 = (int)piVar3;
        piVar3 = (int *)piVar3[1];
      } while (*param_1 == *piVar3);
    }
    *param_1 = (int)piVar3;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 8); iVar2 != DAT_004437a8; iVar2 = *(int *)(iVar2 + 8)) {
    iVar1 = iVar2;
  }
  *param_1 = iVar1;
  return;
}



void __fastcall FUN_00408b60(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(*param_1 + 8);
  if (puVar1 == DAT_004437a8) {
    iVar3 = *(int *)(*param_1 + 4);
    if (*param_1 == *(int *)(iVar3 + 8)) {
      do {
        *param_1 = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
      } while (*param_1 == *(int *)(iVar3 + 8));
    }
    if (*(int *)(*param_1 + 8) != iVar3) {
      *param_1 = iVar3;
    }
    return;
  }
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != DAT_004437a8; puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_1 = (int)puVar1;
  return;
}



void __cdecl FUN_00408bb0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
  }
  return;
}



void mysql_num_fields(void)

{
                    // WARNING: Could not recover jumptable at 0x00408bd0. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_num_fields();
  return;
}



void mysql_free_result(void)

{
                    // WARNING: Could not recover jumptable at 0x00408bd6. Too many branches
                    // WARNING: Treating indirect jump as call
  mysql_free_result();
  return;
}



void __fastcall FUN_00408be0(undefined4 *param_1)

{
  thunk_FUN_0042da40((void *)*param_1);
  thunk_FUN_0042da40((void *)param_1[1]);
  thunk_FUN_0042da40((void *)param_1[2]);
  return;
}



void __thiscall FUN_00408c10(void *this,void *param_1)

{
  FUN_00409ee0(param_1,*(char **)this);
  FUN_00409ee0(param_1,*(char **)((int)this + 4));
  FUN_00409ee0(param_1,*(char **)((int)this + 8));
  FUN_00409f70(param_1,*(uint *)((int)this + 0xc));
  FUN_00409f70(param_1,*(uint *)((int)this + 0x10));
  FUN_00409f70(param_1,*(uint *)((int)this + 0x14));
  return;
}



void __thiscall FUN_00408c60(void *this,undefined4 param_1,undefined4 param_2)

{
  printf(s___s_d_0043a570,param_2,&DAT_00443484,param_1);
  printf(s___s_Sound_____s__0043a558,param_2,&DAT_00443484,*(undefined4 *)this);
  printf(s___s_Particle_____s__0043a540,param_2,&DAT_00443484,*(undefined4 *)((int)this + 4));
  printf(s___s_Animation_____s__0043a528,param_2,&DAT_00443484,*(undefined4 *)((int)this + 8));
  printf(s___s_Friction____f_0043a510,param_2,&DAT_00443484,(double)*(float *)((int)this + 0xc));
  printf(s___s_Mass____f_0043a4f8,param_2,&DAT_00443484,(double)*(float *)((int)this + 0x10));
  printf(s___s_Elasticity____f_0043a4e0,param_2,&DAT_00443484,(double)*(float *)((int)this + 0x14));
  return;
}



void __thiscall FUN_00408d10(void *this,undefined4 param_1,undefined4 param_2)

{
  printf(s___s_pstring___s____Sound_0043a60c,param_2,&DAT_00443484,*(undefined4 *)this);
  printf(s___s_pstring___s____Particle_0043a5ec,param_2,&DAT_00443484,*(undefined4 *)((int)this + 4)
        );
  printf(s___s_pstring___s____Animation_0043a5cc,param_2,&DAT_00443484,
         *(undefined4 *)((int)this + 8));
  printf(s___s_float__12f___Friction_0043a5b0,param_2,&DAT_00443484,
         (double)*(float *)((int)this + 0xc));
  printf(s___s_float__12f___Mass_0043a598,param_2,&DAT_00443484,(double)*(float *)((int)this + 0x10)
        );
  printf(s___s_float__12f___Elasticity_0043a578,param_2,&DAT_00443484,
         (double)*(float *)((int)this + 0x14));
  return;
}



undefined4 FUN_00408da0(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int extraout_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iStack00000004;
  char *in_stack_0001000c;
  int in_stack_00010010;
  
  FUN_0042dd40();
  *in_stack_0001000c = '\0';
  bVar3 = false;
  sprintf(&stack0x00000008,s_Sound____s__0043a690);
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iStack00000004 = ~uVar4 - 1;
  if (in_stack_00010010 < iStack00000004) {
    bVar3 = true;
    iVar5 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; iVar5 = iStack00000004, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  sprintf(&stack0x00000008,s_Particle____s__0043a680);
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iStack00000004 = (~uVar4 - 1) + iVar5;
  if (in_stack_00010010 < iStack00000004) {
    bVar3 = true;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; iVar5 = iStack00000004, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  sprintf(&stack0x00000008,s_Animation____s__0043a66c);
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iStack00000004 = (~uVar4 - 1) + iVar5;
  if (in_stack_00010010 < iStack00000004) {
    bVar3 = true;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; iVar5 = iStack00000004, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  sprintf(&stack0x00000008,s_Friction____f__0043a65c,(double)*(float *)(extraout_ECX + 0xc));
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iStack00000004 = (~uVar4 - 1) + iVar5;
  if (in_stack_00010010 < iStack00000004) {
    bVar3 = true;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; iVar5 = iStack00000004, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  sprintf(&stack0x00000008,s_Mass____f__0043a650,(double)*(float *)(extraout_ECX + 0x10));
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iStack00000004 = (~uVar4 - 1) + iVar5;
  if (in_stack_00010010 < iStack00000004) {
    bVar3 = true;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; iVar5 = iStack00000004, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  sprintf(&stack0x00000008,s_Elasticity____f__0043a63c,(double)*(float *)(extraout_ECX + 0x14));
  uVar4 = 0xffffffff;
  pcVar7 = &stack0x00000008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iVar1 = (~uVar4 - 1) + iVar5;
  if (iVar1 <= in_stack_00010010) {
    uVar4 = 0xffffffff;
    pcVar7 = &stack0x00000008;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar7 = in_stack_0001000c;
    do {
      pcVar8 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar5 = iVar1;
    if (!bVar3) {
      in_stack_00010010 = 0;
      if (2 < iVar1) {
        if (in_stack_0001000c[iVar1 + -2] != ',') {
          return 1;
        }
        in_stack_0001000c[iVar1 + -2] = '\0';
        return 1;
      }
      goto LAB_00409070;
    }
  }
  if (iVar5 + 3 <= in_stack_00010010) {
    iVar5 = -1;
    in_stack_00010010 = 0;
    do {
      pcVar7 = in_stack_0001000c;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar7 = in_stack_0001000c + 1;
      cVar2 = *in_stack_0001000c;
      in_stack_0001000c = pcVar7;
    } while (cVar2 != '\0');
    *(undefined4 *)(pcVar7 + -1) = DAT_0043a638;
  }
LAB_00409070:
  return CONCAT31((int3)((uint)in_stack_00010010 >> 8),1);
}



undefined1 FUN_004090a0(void)

{
  return 0;
}



undefined1 FUN_004090b0(void)

{
  return 0;
}



undefined4 * __thiscall FUN_004090c0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0040aeb0((char *)*param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = FUN_0040aeb0((char *)param_1[1]);
  *(undefined4 *)((int)this + 4) = uVar1;
  uVar1 = FUN_0040aeb0((char *)param_1[2]);
  *(undefined4 *)((int)this + 8) = uVar1;
  *(undefined4 *)((int)this + 0xc) = param_1[3];
  *(undefined4 *)((int)this + 0x10) = param_1[4];
  *(undefined4 *)((int)this + 0x14) = param_1[5];
  return this;
}



undefined4 __thiscall FUN_00409110(void *this,undefined4 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)*param_1;
  pbVar2 = *(byte **)this;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_00409148:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040914d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_00409148;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040914d:
  if (iVar3 != 0) {
    return 0;
  }
  pbVar4 = (byte *)param_1[1];
  pbVar2 = *(byte **)((int)this + 4);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_00409188:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040918d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_00409188;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040918d:
  if (iVar3 != 0) {
    return 0;
  }
  pbVar4 = (byte *)param_1[2];
  pbVar2 = *(byte **)((int)this + 8);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004091c8:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004091cd;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004091c8;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004091cd:
  if (iVar3 != 0) {
    return 0;
  }
  if (*(float *)((int)this + 0xc) != (float)param_1[3]) {
    return 0;
  }
  if (*(float *)((int)this + 0x10) != (float)param_1[4]) {
    return 0;
  }
  if (*(float *)((int)this + 0x14) != (float)param_1[5]) {
    return 0;
  }
  return 1;
}



undefined4 * __fastcall FUN_00409230(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f5d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040a550(param_1,0xff443350);
  local_4 = 0;
  *param_1 = &PTR_FUN_004302d4;
  FUN_00409380((int)param_1);
  ExceptionList = local_c;
  return param_1;
}



undefined4 * __thiscall FUN_00409290(void *this,byte param_1)

{
  FUN_00409310(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_004092b0(void *this,void *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f5f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040a550(this,0xff443350);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_004302d4;
  FUN_00409380((int)this);
  FUN_00409410(this,param_1);
  ExceptionList = local_c;
  return this;
}



void __fastcall FUN_00409310(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f618;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_004302d4;
  iVar1 = param_1[0xb];
  local_4 = 0;
  if (iVar1 != 0) {
    FUN_0042dac0(iVar1,0x18,*(int *)(iVar1 + -4),FUN_00408be0);
    FUN_0042da40((void *)(iVar1 + -4));
  }
  local_4 = 0xffffffff;
  FUN_0040a770(param_1);
  ExceptionList = local_c;
  return;
}



void __fastcall FUN_00409380(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x3000602;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (DAT_0043a4dc == -1) {
    DAT_0043a4dc = FUN_0040ac80(0x3000602);
  }
  return;
}



int __fastcall FUN_004093b0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0xc;
  if (0 < *(int *)((int)param_1 + 0x28)) {
    iVar3 = *(int *)((int)param_1 + 0x28) * 0x18 + 0xc;
  }
  iVar4 = 0;
  iVar1 = FUN_0040a270((int)param_1);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_0040ab40(param_1,iVar4);
      iVar1 = (**(code **)(*(int *)*puVar2 + 0x4c))();
      iVar3 = iVar3 + iVar1;
      iVar4 = iVar4 + 1;
      iVar1 = FUN_0040a270((int)param_1);
    } while (iVar4 < iVar1);
  }
  return iVar3;
}



void * __thiscall FUN_00409410(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (*(int *)((int)this + 4) == *(int *)((int)param_1 + 4)) {
    puVar1 = *(undefined4 **)((int)this + 0x2c);
    *(undefined4 *)((int)this + 0x28) = *(undefined4 *)((int)param_1 + 0x28);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00408be0(puVar1);
      FUN_0042da40(puVar1);
    }
    puVar1 = operator_new(*(int *)((int)this + 0x28) * 0x18 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = *(undefined4 *)((int)this + 0x28);
      puVar1 = puVar1 + 1;
    }
    *(undefined4 **)((int)this + 0x2c) = puVar1;
    uVar3 = 0;
    if (*(int *)((int)this + 0x28) != 0) {
      iVar4 = 0;
      do {
        FUN_004090c0((void *)(*(int *)((int)this + 0x2c) + iVar4),
                     (undefined4 *)(*(int *)((int)param_1 + 0x2c) + iVar4));
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x18;
      } while (uVar3 < *(uint *)((int)this + 0x28));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)this + 8)) {
      do {
        FUN_0040ab80(this,iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)this + 8));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)param_1 + 8)) {
      do {
        puVar1 = (undefined4 *)FUN_0040ab40(param_1,iVar4);
        uVar5 = 1;
        iVar2 = (**(code **)(*(int *)*puVar1 + 0x40))();
        FUN_0040abe0(this,iVar2,uVar5);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)param_1 + 8));
    }
  }
  return this;
}



void __thiscall FUN_004095e0(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28 [7];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f638;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040b090(local_28,param_1,*(undefined4 *)((int)this + 4));
  iVar2 = 0;
  local_4 = 0;
  FUN_0040a000(param_1,*(uint *)((int)this + 0x28));
  uVar3 = 0;
  if (*(int *)((int)this + 0x28) != 0) {
    do {
      FUN_00408c10((void *)(*(int *)((int)this + 0x2c) + iVar2),param_1);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (uVar3 < *(uint *)((int)this + 0x28));
  }
  FUN_0040b1b0((int)local_28);
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
      puVar1 = (undefined4 *)FUN_0040ab40(this,iVar2);
      (**(code **)(*(int *)*puVar1 + 4))(param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  local_4 = 0xffffffff;
  FUN_0040b0f0(local_28);
  ExceptionList = pvStack_c;
  return;
}



undefined4 * __fastcall FUN_00409a20(void *param_1)

{
  void *this;
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f65b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = operator_new(0x30);
  local_4 = 0;
  if (this != (void *)0x0) {
    puVar1 = FUN_004092b0(this,param_1);
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}



void __thiscall FUN_00409a80(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x28) = param_1;
  return;
}



void __thiscall FUN_00409a90(void *this,int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *this_00;
  
  iVar1 = *(int *)((int)this + 0x2c);
  if (iVar1 != 0) {
    FUN_0042dac0(iVar1,0x18,*(int *)(iVar1 + -4),FUN_00408be0);
    FUN_0042da40((void *)(iVar1 + -4));
  }
  piVar2 = operator_new(param_2 * 0x18 + 4);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = param_2;
    piVar2 = piVar2 + 1;
  }
  if (0 < param_2) {
    this_00 = piVar2;
    do {
      FUN_004090c0(this_00,(undefined4 *)((param_1 - (int)piVar2) + (int)this_00));
      this_00 = this_00 + 6;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    *(int **)((int)this + 0x2c) = piVar2;
    return;
  }
  *(int **)((int)this + 0x2c) = piVar2;
  return;
}



undefined4 * __thiscall FUN_00409c00(void *this,byte param_1)

{
  FUN_00409c50(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_00409c20(void *this,int *param_1,int param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_FUN_00430338;
  FUN_00409c60(this,param_1,param_2,param_3);
  return this;
}



void __fastcall FUN_00409c50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430338;
  FUN_00409da0((int)param_1);
  return;
}



void __thiscall FUN_00409c60(void *this,int *param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  pvVar1 = ExceptionList;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0042f67b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(int **)((int)this + 8) = param_1;
  if (param_2 != 4) {
    *(int *)((int)this + 4) = param_2;
    ExceptionList = pvVar1;
    return;
  }
  cVar3 = (**(code **)(*param_1 + 0x14))();
  if (cVar3 != '\0') {
    uVar4 = (**(code **)(*piVar2 + 4))();
    (**(code **)(*piVar2 + 0xc))(&param_1,4);
    (**(code **)(*piVar2 + 8))(uVar4);
    if ((int)param_1 < 0x50334500) {
      if (param_1 == (int *)0x503344ff) {
        *(undefined4 *)((int)this + 4) = 3;
        ExceptionList = local_c;
        return;
      }
      if (param_1 == (int *)0xff443350) goto LAB_00409d65;
      if (param_1 != (int *)0x5033445a) goto LAB_00409d41;
      *(undefined4 *)((int)this + 4) = 3;
    }
    else {
      if (param_1 != (int *)0x5a443350) {
LAB_00409d41:
        *(undefined4 *)((int)this + 4) = 0;
        ExceptionList = local_c;
        return;
      }
      *(undefined4 *)((int)this + 4) = 2;
    }
    param_1 = operator_new(0x1014);
    uStack_4 = 0;
    if (param_1 == (int *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = FUN_0040b280(param_1,piVar2);
    }
    *(undefined4 **)((int)this + 8) = puVar5;
    ExceptionList = local_c;
    return;
  }
LAB_00409d65:
  *(undefined4 *)((int)this + 4) = 2;
  ExceptionList = local_c;
  return;
}



void __fastcall FUN_00409da0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (((puVar1 != (undefined4 *)0x0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



undefined1 __fastcall FUN_00409e00(int param_1)

{
  undefined1 uVar1;
  
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
  return uVar1;
}



undefined4 __fastcall FUN_00409e40(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    return 2;
  }
  if ((1 < iVar1) && (iVar1 < 4)) {
    return 4;
  }
  assert(&DAT_0043a7e0,s_D__SRR2_depot_game_libs_pure3d_t_0043a7e4,0xdf);
  return 0;
}



undefined4 __fastcall FUN_00409e80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if ((1 < iVar1) && (iVar1 < 4)) {
      return 4;
    }
    assert(&DAT_0043a7e0,s_D__SRR2_depot_game_libs_pure3d_t_0043a7e4,0xf3);
  }
  return 0;
}



undefined4 __thiscall FUN_00409ee0(void *this,char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_1 == (char *)0x0) {
    param_1 = PTR_DAT_0043a7c0;
  }
  uVar2 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = ~uVar2 - 1;
  uVar2 = -iVar3 & 3;
  if (0xff < (int)(uVar2 + iVar3)) {
    assert(s_len_pad_<_256_0043a81c,s_D__SRR2_depot_game_libs_pure3d_t_0043a7e4,0x10b);
  }
  FUN_0040a0e0((int)this);
  (**(code **)(*(int *)this + 0x20))(param_1,iVar3);
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    FUN_0040a0e0((int)this);
  }
  return 1;
}



undefined1 __thiscall FUN_00409f70(void *this,uint param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  
  if ((*(int *)((int)this + 4) == 1) || (pvVar2 = this, *(int *)((int)this + 4) == 3)) {
    param_1 = (param_1 & 0xff00 | param_1 << 0x10 | param_1 >> 0x10 & 0xff) << 8 | param_1 >> 0x18;
    pvVar2 = (void *)param_1;
  }
  uVar1 = (**(code **)(**(int **)((int)this + 8) + 0x18))(&param_1,4,pvVar2);
  return uVar1;
}



undefined1 __thiscall FUN_00409fd0(void *this,uint param_1)

{
  undefined1 uVar1;
  
  if ((*(int *)((int)this + 4) == 1) || (*(int *)((int)this + 4) == 3)) {
    param_1 = (uint)CONCAT11((char)param_1,(char)(param_1 >> 8));
  }
  uVar1 = (**(code **)(**(int **)((int)this + 8) + 0x18))(&param_1,2);
  return uVar1;
}



undefined1 __thiscall FUN_0040a000(void *this,uint param_1)

{
  undefined1 uVar1;
  
  if ((*(int *)((int)this + 4) == 1) || (*(int *)((int)this + 4) == 3)) {
    param_1 = (param_1 & 0xff00 | param_1 << 0x10 | param_1 >> 0x10 & 0xff) << 8 | param_1 >> 0x18;
  }
  uVar1 = (**(code **)(**(int **)((int)this + 8) + 0x18))(&param_1,4);
  return uVar1;
}



undefined1 __thiscall FUN_0040a050(void *this,uint param_1)

{
  undefined1 uVar1;
  
  switch(*(undefined4 *)((int)this + 4)) {
  case 0:
  case 1:
    break;
  case 2:
  case 3:
    uVar1 = FUN_0040a000(this,param_1);
    return uVar1;
  default:
    assert(&DAT_0043a7e0,s_D__SRR2_depot_game_libs_pure3d_t_0043a7e4,0x15b);
    return 0;
  }
  if ((param_1 & 0xffff) != param_1) {
    assert(s__unsigned_int___unsigned_short__i_0043a82c,s_D__SRR2_depot_game_libs_pure3d_t_0043a7e4,
           0x153);
  }
  uVar1 = FUN_00409fd0(this,param_1);
  return uVar1;
}



undefined1 __fastcall FUN_0040a0e0(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))(&stack0x00000004,1);
  return uVar1;
}



undefined4 * __thiscall FUN_0040a110(void *this,byte param_1)

{
  FUN_0040a1f0(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_0040a130(void *this,char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  char local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f698;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined ***)this = &PTR_FUN_00430360;
  if (param_2 == 0) {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_0043a894)[iVar2];
      local_18[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  else if (param_2 == 1) {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_0043a898)[iVar2];
      local_18[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    assert(&DAT_0043a7e0,s_D__SRR2_depot_game_libs_pure3d_t_0043a8a0,0x26);
  }
  if (param_1 != (char *)0x0) {
    pFVar3 = fopen(param_1,local_18);
    *(FILE **)((int)this + 0xc) = pFVar3;
    uVar4 = FUN_0040aeb0(param_1);
    *(undefined4 *)((int)this + 4) = uVar4;
  }
  *(undefined4 *)((int)this + 8) = 0;
  ExceptionList = local_c;
  return this;
}



void __fastcall FUN_0040a1f0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f6b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00430360;
  local_4 = 0;
  if ((FILE *)param_1[3] != (FILE *)0x0) {
    fclose((FILE *)param_1[3]);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    thunk_FUN_0042da40((void *)param_1[1]);
  }
  local_4 = 0xffffffff;
  FUN_0040b8a0(param_1);
  ExceptionList = local_c;
  return;
}



undefined4 __fastcall FUN_0040a270(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



void __fastcall FUN_0040a450(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f6d8;
  local_c = ExceptionList;
  local_4 = 0;
  piVar1 = param_1 + 1;
  iVar4 = 8;
  iVar5 = 0;
  ExceptionList = &local_c;
  while( true ) {
    piVar2 = (int *)*piVar1;
    if (piVar2 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar2;
    }
    if (iVar3 <= iVar5) break;
    if ((piVar2 == (int *)0x0) || (*piVar2 <= iVar5)) {
      FUN_0040b9b0(piVar1,iVar5 + 1,4);
    }
    FUN_0042da40(*(void **)(iVar4 + *piVar1));
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 4;
  }
  *param_1 = &PTR_FUN_00430428;
  if ((void *)*piVar1 != (void *)0x0) {
    free((void *)*piVar1);
    *piVar1 = 0;
  }
  ExceptionList = local_c;
  return;
}



void FUN_0040a500(void)

{
  FUN_0040a540((undefined4 *)&DAT_004437d0);
  return;
}



void FUN_0040a510(void)

{
  FUN_0042dc0e((_onexit_t)&LAB_0040a520);
  return;
}



void __fastcall FUN_0040a540(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_00430428;
  return;
}



void __thiscall FUN_0040a550(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = &PTR_FUN_00430434;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  return;
}



undefined4 * __thiscall FUN_0040a590(void *this,byte param_1)

{
  FUN_0040a770(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_0040a5b0(void *this,void *param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  *(undefined ***)this = &PTR_FUN_00430434;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  sVar1 = *(size_t *)((int)param_1 + 0x14);
  *(size_t *)((int)this + 0x14) = sVar1;
  if (*(int *)((int)param_1 + 0x10) == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  else {
    puVar2 = malloc(sVar1);
    uVar6 = *(uint *)((int)this + 0x14);
    *(undefined4 **)((int)this + 0x10) = puVar2;
    puVar4 = *(undefined4 **)((int)param_1 + 0x10);
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  sVar1 = *(size_t *)((int)param_1 + 0x1c);
  *(size_t *)((int)this + 0x1c) = sVar1;
  if (*(int *)((int)param_1 + 0x18) == 0) {
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  else {
    puVar2 = malloc(sVar1);
    uVar6 = *(uint *)((int)this + 0x1c);
    *(undefined4 **)((int)this + 0x18) = puVar2;
    puVar4 = *(undefined4 **)((int)param_1 + 0x18);
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  iVar7 = 0;
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)param_1 + 0x20);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)((int)param_1 + 4);
  iVar3 = FUN_0040a270((int)param_1);
  if (0 < iVar3) {
    do {
      puVar4 = (undefined4 *)FUN_0040ab40(param_1,iVar7);
      uVar8 = 1;
      iVar3 = (**(code **)(*(int *)*puVar4 + 0x40))();
      FUN_0040abe0(this,iVar3,uVar8);
      iVar7 = iVar7 + 1;
      iVar3 = FUN_0040a270((int)param_1);
    } while (iVar7 < iVar3);
  }
  return this;
}



undefined4 * __fastcall FUN_0040a680(void *param_1)

{
  void *this;
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f6fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = operator_new(0x28);
  local_4 = 0;
  if (this != (void *)0x0) {
    puVar1 = FUN_0040a5b0(this,param_1);
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}



void __fastcall FUN_0040a770(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_00430434;
  if ((param_1[2] != 0) && (iVar2 = 0, 0 < (int)param_1[2])) {
    do {
      if ((*(int *)(param_1[9] + 4 + iVar2 * 8) != 0) &&
         (puVar1 = *(undefined4 **)(param_1[9] + iVar2 * 8), puVar1 != (undefined4 *)0x0)) {
        (**(code **)*puVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[2]);
  }
  if ((void *)param_1[9] != (void *)0x0) {
    FUN_0042da40((void *)param_1[9]);
  }
  if ((void *)param_1[4] != (void *)0x0) {
    free((void *)param_1[4]);
  }
  if ((void *)param_1[6] != (void *)0x0) {
    free((void *)param_1[6]);
  }
  return;
}



void __thiscall FUN_0040a7e0(void *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (*(int *)((int)this + 0xc) <= param_1) {
    iVar3 = *(int *)((int)this + 0xc) * 2;
    if (iVar3 < param_1) {
      *(int *)((int)this + 0xc) = param_1;
    }
    else {
      *(int *)((int)this + 0xc) = iVar3;
    }
    pvVar2 = operator_new(*(int *)((int)this + 0xc) << 3);
    if (*(int *)((int)this + 0x24) != 0) {
      iVar3 = 0;
      if (0 < *(int *)((int)this + 8)) {
        do {
          iVar1 = *(int *)((int)this + 0x24);
          *(undefined4 *)((int)pvVar2 + iVar3 * 8) = *(undefined4 *)(iVar1 + iVar3 * 8);
          *(undefined4 *)((int)pvVar2 + iVar3 * 8 + 4) = *(undefined4 *)(iVar1 + 4 + iVar3 * 8);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)((int)this + 8));
      }
      FUN_0042da40(*(void **)((int)this + 0x24));
    }
    *(void **)((int)this + 0x24) = pvVar2;
  }
  return;
}



void __thiscall FUN_0040a850(void *this,int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_28 [7];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f718;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040b090(local_28,param_1,*(undefined4 *)((int)this + 4));
  iVar2 = 0;
  local_4 = 0;
  if (*(int *)((int)this + 0x14) != 0) {
    (**(code **)(*param_1 + 0x20))(*(undefined4 *)((int)this + 0x10),*(int *)((int)this + 0x14));
  }
  FUN_0040b1b0((int)local_28);
  if (0 < *(int *)((int)this + 8)) {
    do {
      puVar1 = (undefined4 *)FUN_0040ab40(this,iVar2);
      (**(code **)(*(int *)*puVar1 + 4))(param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  local_4 = 0xffffffff;
  FUN_0040b0f0(local_28);
  ExceptionList = pvStack_c;
  return;
}



void __thiscall FUN_0040a8f0(void *this,int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar1 = FUN_0040ac30((int)this);
  uVar2 = FUN_0040ac20((int)this);
  (**(code **)(iVar4 + 0x20))(uVar2,uVar1);
  if ((*(int *)((int)this + 8) != 0) && (iVar4 = 0, 0 < *(int *)((int)this + 8))) {
    do {
      puVar3 = (undefined4 *)FUN_0040ab40(this,iVar4);
      (**(code **)(*(int *)*puVar3 + 8))(param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 8));
  }
  return;
}



void __thiscall FUN_0040a9e0(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  printf(s___schunk_0x_04x_0043a9a4,param_1,&DAT_00443484,*(undefined4 *)((int)this + 4));
  if (*(int *)((int)this + 0x14) != 0) {
    printf(s___s_repeat_1_byte___unknown_chun_0043a97c,param_1,&DAT_00443484);
    iVar2 = 0;
    if (0 < *(int *)((int)this + 0x14)) {
      do {
        printf(s___s_0x_02x_0043a96c,param_1,&DAT_00443484,
               (int)*(char *)(iVar2 + *(int *)((int)this + 0x10)));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)((int)this + 0x14));
    }
    printf(s___s_endrepeat_0043a95c,param_1,&DAT_00443484);
  }
  if ((*(int *)((int)this + 8) != 0) && (iVar2 = 0, 0 < *(int *)((int)this + 8))) {
    do {
      puVar1 = (undefined4 *)FUN_0040ab40(this,iVar2);
      (**(code **)(*(int *)*puVar1 + 0x10))(param_1 + 2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  printf(s___sendchunk_0043a73c,param_1,&DAT_00443484);
  return;
}



int __fastcall FUN_0040ab00(void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040ab10(param_1);
  return iVar1 + *(int *)((int)param_1 + 0x14);
}



int __fastcall FUN_0040ab10(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  if (0 < *(int *)((int)param_1 + 8)) {
    do {
      puVar1 = (undefined4 *)FUN_0040ab40(param_1,iVar4);
      iVar2 = (**(code **)(*(int *)*puVar1 + 0x4c))();
      iVar3 = iVar3 + iVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)param_1 + 8));
  }
  return iVar3;
}



int __thiscall FUN_0040ab40(void *this,int param_1)

{
  if (*(int *)((int)this + 8) <= param_1) {
    assert(s_index<subcount_0043a9c4,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,400);
  }
  return *(int *)((int)this + 0x24) + param_1 * 8;
}



void __thiscall FUN_0040ab80(void *this,int param_1)

{
  int iVar1;
  
  if (*(int *)((int)this + 8) <= param_1) {
    assert(s_index<subcount_0043a9c4,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,0x1ae);
  }
  if (param_1 < *(int *)((int)this + 8) + -1) {
    do {
      iVar1 = *(int *)((int)this + 0x24);
      *(undefined4 *)(iVar1 + param_1 * 8) = *(undefined4 *)(iVar1 + 8 + param_1 * 8);
      *(undefined4 *)(iVar1 + 4 + param_1 * 8) = *(undefined4 *)(iVar1 + 0xc + param_1 * 8);
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)((int)this + 8) + -1);
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  return;
}



void __thiscall FUN_0040abe0(void *this,int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_0040a7e0(this,*(int *)((int)this + 8) + 1);
    *(int *)(*(int *)((int)this + 0x24) + *(int *)((int)this + 8) * 8) = param_1;
    *(undefined4 *)(*(int *)((int)this + 0x24) + 4 + *(int *)((int)this + 8) * 8) = param_2;
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  }
  return;
}



undefined4 __fastcall FUN_0040ac20(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



undefined4 __fastcall FUN_0040ac30(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}



int __cdecl FUN_0040ac80(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_004439f8) {
    do {
      if (param_1 == (&DAT_004437d8)[iVar1]) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_004439f8);
  }
  return 0x7fffffff;
}



void __cdecl FUN_0040acb0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (0x7f < DAT_004439f8 + 1) {
    assert(s__usedChunkPriorities___1__<_maxC_0043aa48,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,
           0x2df);
  }
  iVar1 = FUN_0040ac80(param_1);
  if (iVar1 != 0x7fffffff) {
    assert(s_FindPriority_addID_____0x7ffffff_0043aa24,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,
           0x2e0);
  }
  switch(param_2) {
  case 0:
    param_3 = 0;
    break;
  case 1:
    param_3 = FUN_0040ac80(param_3);
    if (param_3 == 0x7fffffff) {
      assert(s_index____0x7fffffff_0043aa10,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,0x2ec);
    }
    break;
  case 2:
    iVar1 = FUN_0040ac80(param_3);
    param_3 = iVar1 + 1;
    if (param_3 == 0x7fffffff) {
      assert(s_index____0x7fffffff_0043aa10,s_D__SRR2_depot_game_libs_pure3d_t_0043a9d4,0x2f0);
    }
    break;
  case 3:
    param_3 = DAT_004439f8;
  }
  for (uVar2 = DAT_004439f8; param_3 < uVar2; uVar2 = uVar2 - 1) {
    (&DAT_004437d8)[uVar2] = *(undefined4 *)(&DAT_004437d4 + uVar2 * 4);
  }
  (&DAT_004437d8)[param_3] = param_1;
  DAT_004439f8 = DAT_004439f8 + 1;
  return;
}



void __fastcall FUN_0040ade0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430428;
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



undefined4 * __thiscall FUN_0040ae70(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_00430428;
  if (*(void **)((int)this + 4) != (void *)0x0) {
    free(*(void **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void __cdecl FUN_0040aeb0(char *param_1)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pvVar2 = operator_new(~uVar3);
    iVar4 = (int)pvVar2 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[iVar4] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  return;
}



void __cdecl thunk_FUN_0042da40(void *param_1)

{
  free(param_1);
  return;
}



void __thiscall FUN_0040b010(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = param_1;
  *(undefined ***)this = &PTR_FUN_004304a8;
  return;
}



undefined4 * __thiscall FUN_0040b030(void *this,byte param_1)

{
  FUN_0040b050(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void __fastcall FUN_0040b050(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_004304a8;
  return;
}



void __thiscall FUN_0040b060(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  return;
}



undefined4 * __thiscall FUN_0040b070(void *this,byte param_1)

{
  FUN_0040b0f0(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



undefined4 * __thiscall FUN_0040b090(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_EDX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0042f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b010(this,0);
  *(undefined4 *)((int)this + 0x18) = extraout_EDX;
  *(undefined ***)this = &PTR_FUN_004304b0;
  local_4 = extraout_EDX;
  FUN_0040b060(this,param_1);
  FUN_0040b150(this,param_2);
  ExceptionList = local_c;
  return this;
}



void __fastcall FUN_0040b0f0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f758;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_004304b0;
  local_4 = 0;
  if (param_1[3] == 0) {
    FUN_0040b1b0((int)param_1);
  }
  if (param_1[2] == 0) {
    FUN_0040b210((int)param_1);
  }
  FUN_0040b050(param_1);
  ExceptionList = local_c;
  return;
}



void __thiscall FUN_0040b150(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(undefined4 *)((int)this + 4) = param_1;
    uVar1 = (**(code **)(**(int **)((int)this + 0x14) + 0x18))();
    *(undefined4 *)((int)this + 0x10) = uVar1;
    FUN_0040a050(*(void **)((int)this + 0x14),*(uint *)((int)this + 4));
    iVar2 = FUN_00409e80(*(int *)((int)this + 0x14));
    if (iVar2 != 0) {
      FUN_0040a000(*(void **)((int)this + 0x14),0);
    }
    FUN_0040a000(*(void **)((int)this + 0x14),0);
    *(undefined4 *)((int)this + 0x18) = 1;
  }
  return;
}



void __fastcall FUN_0040b1b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar1 = FUN_00409e80(*(int *)(param_1 + 0x14));
    if (iVar1 != 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))();
      *(int *)(param_1 + 0xc) = iVar2 - *(int *)(param_1 + 0x10);
      iVar1 = **(int **)(param_1 + 0x14);
      iVar3 = FUN_00409e40((int)*(int **)(param_1 + 0x14));
      (**(code **)(iVar1 + 0x14))(iVar3 + *(int *)(param_1 + 0x10));
      FUN_0040a000(*(void **)(param_1 + 0x14),*(uint *)(param_1 + 0xc));
      (**(code **)(**(int **)(param_1 + 0x14) + 0x14))(iVar2);
    }
  }
  return;
}



void __fastcall FUN_0040b210(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))();
    *(int *)(param_1 + 8) = iVar2 - *(int *)(param_1 + 0x10);
    iVar1 = **(int **)(param_1 + 0x14);
    iVar3 = FUN_00409e80((int)*(int **)(param_1 + 0x14));
    iVar4 = FUN_00409e40(*(int *)(param_1 + 0x14));
    (**(code **)(iVar1 + 0x14))(iVar3 + iVar4 + *(int *)(param_1 + 0x10));
    FUN_0040a000(*(void **)(param_1 + 0x14),*(uint *)(param_1 + 8));
    (**(code **)(**(int **)(param_1 + 0x14) + 0x14))(iVar2);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}



undefined4 * __thiscall FUN_0040b280(void *this,int *param_1)

{
  int **ppiVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0042f778;
  pvStack_c = ExceptionList;
  ppiVar1 = &param_1;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *(int **)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined ***)this = &PTR_FUN_004304b8;
  (**(code **)(*param_1 + 0xc))(ppiVar1,4);
  (**(code **)(**(int **)((int)this + 4) + 0xc))((int)this + 0xc,4);
  FUN_0040b4a0((int)this);
  ExceptionList = ppiVar1;
  return this;
}



undefined4 * __thiscall FUN_0040b2f0(void *this,byte param_1)

{
  FUN_0040b310(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void __fastcall FUN_0040b310(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_004304b8;
  FUN_0040b8a0(param_1);
  return;
}



undefined4 __thiscall FUN_0040b320(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1;
  if (param_1 < *(int *)((int)this + 8)) {
    assert(s_offset_>__position_0043aae4,s_D__SRR2_depot_game_libs_pure3d_t_0043aaf8,0x2a);
  }
  iVar2 = iVar1 - *(int *)((int)this + 8);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      iVar2 = (**(code **)(*(int *)this + 0xc))(&param_1,1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1 - *(int *)((int)this + 8));
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



void __fastcall FUN_0040b4a0(int param_1)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 local_8 [8];
  
  puVar2 = local_8;
  (**(code **)(**(int **)(param_1 + 4) + 0xc))(puVar2,4);
  (**(code **)(**(int **)(param_1 + 4) + 0xc))();
  pbVar1 = operator_new((uint)puVar2);
  (**(code **)(**(int **)(param_1 + 4) + 0xc))(pbVar1,puVar2);
  FUN_0040cc20(pbVar1,&stack0xfffffff4,(byte *)(param_1 + 0x14),4);
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_0042da40(pbVar1);
  return;
}



void __thiscall
FUN_0040b5f0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 8) = param_3;
  *(undefined4 *)((int)this + 0xc) = param_4;
  *(undefined4 *)((int)this + 0x10) = param_5;
  *(undefined4 *)((int)this + 0x14) = param_6;
  *(undefined4 *)((int)this + 0x18) = param_7;
  *(undefined4 *)((int)this + 0x1c) = param_8;
  *(undefined4 *)((int)this + 0x20) = param_9;
  *(undefined4 *)((int)this + 0x24) = param_10;
  *(undefined4 *)((int)this + 0x28) = param_11;
  *(undefined4 *)((int)this + 0x2c) = param_12;
  *(undefined4 *)((int)this + 0x30) = param_13;
  *(undefined4 *)((int)this + 0x34) = param_14;
  *(undefined4 *)((int)this + 0x38) = param_15;
  *(undefined4 *)((int)this + 0x3c) = param_16;
  return;
}



void __fastcall FUN_0040b8a0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00430504;
  return;
}



undefined4 __cdecl FUN_0040b8b0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_0040b8f0(param_1,param_2,param_3);
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar1[1] = param_2;
  iVar2 = *piVar1;
  if (param_2 <= *piVar1) {
    iVar2 = param_2;
  }
  *piVar1 = iVar2;
  return 1;
}



void __cdecl FUN_0040b8f0(undefined4 *param_1,int param_2,int param_3)

{
  void *_Memory;
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  _Memory = (void *)*param_1;
  if (param_2 == 0) {
    if (_Memory != (void *)0x0) {
      free(_Memory);
      *param_1 = 0;
    }
  }
  else if (_Memory != (void *)0x0) {
    uVar3 = param_2 * param_3 + 8;
    puVar2 = malloc(uVar3);
    puVar1 = puVar2;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar1 = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
    iVar4 = ((undefined4 *)*param_1)[1];
    if (param_2 <= iVar4) {
      iVar4 = param_2;
    }
    uVar5 = iVar4 * param_3 + 8;
    puVar1 = (undefined4 *)*param_1;
    puVar6 = puVar2;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar1;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    free((void *)*param_1);
    *param_1 = puVar2;
    return;
  }
  uVar5 = param_2 * param_3 + 8;
  puVar1 = malloc(uVar5);
  *param_1 = puVar1;
  *puVar1 = 0;
  puVar1 = (undefined4 *)*param_1;
  for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return;
}



void __cdecl FUN_0040b9b0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (param_2 == 0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = 0;
      return;
    }
  }
  else {
    if ((piVar1 != (int *)0x0) && (param_2 <= piVar1[1])) {
      *piVar1 = param_2;
      return;
    }
    FUN_0040b8b0(param_1,param_2,param_3);
    *(int *)*param_1 = param_2;
  }
  return;
}



int __cdecl FUN_0040b9f0(int *param_1,int param_2,int param_3,void *param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)*param_1;
  if (param_3 != 0) {
    if (piVar2 == (int *)0x0) {
      if (param_2 != 0) {
        assert(s_at__0_0043abf8,s_D__SRR2_depot_game_libs_pure3d_t_0043ac00,0x46);
      }
      iVar3 = 0;
      FUN_0040b8f0(param_1,param_3 + param_6,param_5);
      piVar2 = (int *)*param_1;
      piVar2[1] = param_3 + param_6;
    }
    else {
      iVar3 = *piVar2;
      if (piVar2[1] < param_3 + iVar3) {
        if (iVar3 < param_2) {
          assert(s__at<_oldCount_0043abe7 + 1,s_D__SRR2_depot_game_libs_pure3d_t_0043ac00,0x50);
        }
        iVar1 = (*piVar2 + param_3) * 2;
        FUN_0040b8f0(param_1,iVar1,param_5);
        piVar2 = (int *)*param_1;
        piVar2[1] = iVar1;
      }
      else if (iVar3 < param_2) {
        assert(s__at<_oldCount_0043abe7 + 1,s_D__SRR2_depot_game_libs_pure3d_t_0043ac00,0x59);
      }
    }
    if (param_2 < iVar3) {
      memmove((void *)((param_3 + param_2) * param_5 + 8 + (int)piVar2),
              (void *)(param_2 * param_5 + 8 + (int)piVar2),(iVar3 - param_2) * param_5);
    }
    memmove((void *)(param_2 * param_5 + 8 + (int)piVar2),param_4,param_3 * param_5);
    *piVar2 = *piVar2 + param_3;
    return param_2;
  }
  return param_2;
}



uint * __thiscall FUN_0040cbc0(void *this,char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  *(undefined4 *)this = 0;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 < 3) {
    assert(s_strlen_c_>2_0043affc,s_D__SRR2_depot_game_libs_pure3d_t_0043b008,10);
  }
  *(int *)this = (((int)param_1[3] << 8 | (int)param_1[2]) << 8 | (int)param_1[1]) << 8 |
                 (int)*param_1;
  return this;
}



void __cdecl FUN_0040cc20(byte *param_1,undefined4 param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  if (param_4 != 0) {
    uVar2 = 0;
    do {
      bVar1 = *param_1;
      uVar3 = (uint)bVar1;
      param_1 = param_1 + 1;
      if (uVar3 < 0x10) {
        pbVar4 = param_3;
        if (uVar3 == 0) {
          iVar5 = 0;
          if (*param_1 == 0) {
            iVar5 = 0;
            do {
              pbVar4 = param_1 + 1;
              iVar5 = iVar5 + 0xff;
              param_1 = param_1 + 1;
            } while (*pbVar4 == 0);
          }
          uVar3 = iVar5 + (uint)*param_1;
          *param_3 = param_1[1];
          param_3[1] = param_1[2];
          param_3[2] = param_1[3];
          param_3[3] = param_1[4];
          param_3[4] = param_1[5];
          param_3[5] = param_1[6];
          param_3[6] = param_1[7];
          param_3[7] = param_1[8];
          param_3[8] = param_1[9];
          param_3[9] = param_1[10];
          param_3[10] = param_1[0xb];
          param_3[0xb] = param_1[0xc];
          param_3[0xc] = param_1[0xd];
          param_3[0xd] = param_1[0xe];
          param_3[0xe] = param_1[0xf];
          param_1 = param_1 + 0x10;
          uVar2 = uVar2 + 0xf;
          pbVar4 = param_3 + 0xf;
        }
        do {
          param_3 = pbVar4 + 1;
          *pbVar4 = *param_1;
          param_1 = param_1 + 1;
          uVar2 = uVar2 + 1;
          uVar3 = uVar3 - 1;
          pbVar4 = param_3;
        } while (uVar3 != 0);
      }
      else {
        uVar3 = uVar3 & 0xf;
        if ((bVar1 & 0xf) == 0) {
          iVar5 = 0xf;
          if (*param_1 == 0) {
            iVar5 = 0xf;
            do {
              pbVar4 = param_1 + 1;
              iVar5 = iVar5 + 0xff;
              param_1 = param_1 + 1;
            } while (*pbVar4 == 0);
          }
          uVar3 = iVar5 + (uint)*param_1;
          param_1 = param_1 + 1;
        }
        iVar5 = (int)uVar3 >> 2;
        pbVar4 = param_3 + -((uint)*param_1 << 4 | (uint)(bVar1 >> 4));
        param_1 = param_1 + 1;
        iVar6 = uVar3 + iVar5 * -4;
        do {
          *param_3 = *pbVar4;
          param_3[1] = pbVar4[1];
          param_3[2] = pbVar4[2];
          param_3[3] = pbVar4[3];
          param_3 = param_3 + 4;
          pbVar4 = pbVar4 + 4;
          uVar2 = uVar2 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        if (iVar6 != 0) {
          uVar2 = uVar2 + iVar6;
          do {
            *param_3 = *pbVar4;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    } while (uVar2 < param_4);
  }
  return;
}



void __cdecl FUN_004109d0(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar5 = uVar1;
  if (uVar1 <= uVar2) {
    uVar5 = uVar2;
  }
  uVar3 = param_1[1];
  uVar4 = param_2[1];
  *param_3 = uVar2 + uVar1;
  param_3[1] = (uVar2 + uVar1 < uVar5) + uVar3 + uVar4;
  return;
}



uint __cdecl FUN_00410a10(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint local_10;
  uint local_c;
  uint local_8 [2];
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == param_3) {
    return param_1;
  }
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  uVar2 = param_1 ^ param_2;
  if ((int)param_2 < 0) {
    param_2 = -param_2;
  }
  uVar2 = uVar2 ^ param_3;
  if ((int)param_3 < 0) {
    param_3 = -param_3;
  }
  if ((((int)uVar1 < 0xb505) && ((int)param_2 < 0xb505)) && ((int)param_3 < 0x2afe0)) {
    if (0 < (int)param_3) {
      uVar1 = (int)(uVar1 * param_2 + ((int)param_3 >> 1)) / (int)param_3;
      goto LAB_00410ac0;
    }
  }
  else if (0 < (int)param_3) {
    FUN_00410ad0(uVar1,param_2,&local_10);
    local_8[1] = 0;
    local_8[0] = (int)param_3 >> 1;
    FUN_004109d0(&local_10,local_8,&local_10);
    uVar1 = FUN_00410b40(local_c,local_10,param_3);
    goto LAB_00410ac0;
  }
  uVar1 = 0x7fffffff;
LAB_00410ac0:
  if ((int)uVar2 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



void __cdecl FUN_00410ad0(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0xffff) * (param_1 >> 0x10);
  uVar1 = (param_2 >> 0x10) * (param_1 & 0xffff) + uVar3;
  uVar2 = (param_2 & 0xffff) * (param_1 & 0xffff) + uVar1 * 0x10000;
  *param_3 = uVar2;
  param_3[1] = (uint)(uVar2 < uVar1 * 0x10000) +
               (uint)(uVar1 < uVar3) * 0x10000 + (param_2 >> 0x10) * (param_1 >> 0x10) +
               (uVar1 >> 0x10);
  return;
}



uint __cdecl FUN_00410b40(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_3 <= param_1) {
    return 0x7fffffff;
  }
  iVar2 = 0x20;
  do {
    param_1 = param_1 * 2 | param_2 >> 0x1f;
    uVar1 = uVar1 << 1;
    if (param_3 <= param_1) {
      param_1 = param_1 - param_3;
      uVar1 = uVar1 | 1;
    }
    param_2 = param_2 << 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}



uint __cdecl FUN_00410b80(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (param_2 != 0x10000)) {
    uVar1 = param_1;
    if ((int)param_1 < 0) {
      uVar1 = -param_1;
    }
    uVar2 = param_1 ^ param_2;
    if ((int)param_2 < 0) {
      param_2 = -param_2;
    }
    if ((uVar1 < 0x801) && (param_2 < 0x100001)) {
      param_1 = uVar1 * param_2 + 0x8000 >> 0x10;
    }
    else {
      param_1 = ((param_2 & 0xffff) * (uVar1 & 0xffff) + 0x8000 >> 0x10) +
                (param_2 >> 0x10) * (uVar1 & 0xffff) + (uVar1 >> 0x10) * param_2;
    }
    if ((int)uVar2 < 0) {
      param_1 = -param_1;
    }
  }
  return param_1;
}



uint __cdecl FUN_00410c00(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_10;
  uint local_c;
  uint local_8 [2];
  
  local_10 = param_1;
  if ((int)param_1 < 0) {
    local_10 = -param_1;
  }
  uVar2 = param_1 ^ param_2;
  if ((int)param_2 < 0) {
    param_2 = -param_2;
  }
  if (param_2 == 0) {
    uVar1 = 0x7fffffff;
  }
  else {
    local_c = (int)local_10 >> 0x10;
    local_10 = local_10 * 0x10000;
    local_8[0] = (int)param_2 >> 1;
    if (local_c == 0) {
      uVar1 = (local_8[0] + local_10) / param_2;
    }
    else {
      local_8[1] = 0;
      FUN_004109d0(&local_10,local_8,&local_10);
      uVar1 = FUN_00410b40(local_c,local_10,param_2);
    }
  }
  if ((int)uVar2 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



undefined4 __cdecl FUN_00410c90(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((int)param_2 < 1) {
    *param_3 = 0;
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(param_1 + 4))(param_1,param_2);
  *param_3 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x40;
  }
  for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return 0;
}



undefined4 __cdecl FUN_00410ce0(int param_1,int param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*param_4 == 0) {
    uVar1 = FUN_00410c90(param_1,param_3,param_4);
    return uVar1;
  }
  if ((int)param_3 < 1) {
    FUN_00410d70(param_1,param_4);
    return 0;
  }
  iVar2 = (**(code **)(param_1 + 0xc))(param_1,param_2,param_3,*param_4);
  if (iVar2 == 0) {
    return 0x40;
  }
  if (param_2 < (int)param_3) {
    puVar4 = (undefined4 *)(iVar2 + param_2);
    for (uVar3 = param_3 - param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = param_3 - param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  *param_4 = iVar2;
  return 0;
}



void __cdecl FUN_00410d70(int param_1,int *param_2)

{
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    (**(code **)(param_1 + 8))(param_1,*param_2);
    *param_2 = 0;
  }
  return;
}



void __cdecl FUN_00410da0(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1;
  iVar2 = FUN_00410c90((int)param_1,0x58,&param_1);
  if (iVar2 == 0) {
    *param_1 = (int)piVar1;
    *param_2 = (int)param_1;
  }
  return;
}



void __cdecl FUN_00410dd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined2 *)(param_1 + 0x16) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x14);
  puVar3 = (undefined4 *)(param_1 + 0x34);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



void __cdecl FUN_00410e00(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_00410d70(iVar1,param_1 + 6);
  FUN_00410d70(iVar1,param_1 + 7);
  FUN_00410d70(iVar1,param_1 + 8);
  FUN_00410d70(iVar1,param_1 + 0xc);
  FUN_00410d70(iVar1,param_1 + 0xb);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_00410dd0((int)param_1);
  return;
}



void __cdecl FUN_00410e60(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    FUN_00410e00(param_1);
    FUN_00410d70(iVar1,(int *)&param_1);
  }
  return;
}



int __cdecl FUN_00410e90(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00410c90(*param_1,param_1[1] << 3,param_1 + 0xc);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 4) = 1;
    FUN_00410ed0((int)param_1);
  }
  return iVar1;
}



void __cdecl FUN_00410ed0(int param_1)

{
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x18) + *(short *)(param_1 + 0x16) * 8;
  *(int *)(param_1 + 0x3c) = (int)*(short *)(param_1 + 0x16) + *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x20) + *(short *)(param_1 + 0x14) * 2;
  if (*(char *)(param_1 + 0x10) != '\0') {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x30) + *(short *)(param_1 + 0x16) * 8;
  }
  return;
}



int __cdecl FUN_00410f10(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_1;
  uVar2 = param_1[1];
  uVar4 = (int)*(short *)((int)param_1 + 0x16) + param_2 + *(short *)((int)param_1 + 0x36);
  if (uVar2 < uVar4) {
    uVar4 = uVar4 + 7 & 0xfffffff8;
    iVar1 = FUN_00410ce0(iVar3,uVar2 << 3,uVar4 * 8,param_1 + 6);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_00410ce0(iVar3,uVar2,uVar4,param_1 + 7);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (((char)param_1[4] != '\0') &&
       (iVar1 = FUN_00410ce0(iVar3,uVar2 << 3,uVar4 * 8,param_1 + 0xc), iVar1 != 0)) {
      return iVar1;
    }
    param_1[1] = uVar4;
  }
  uVar2 = (int)(short)param_1[5] + param_3 + (short)param_1[0xd];
  if ((uint)param_1[2] < uVar2) {
    uVar2 = uVar2 + 3 & 0xfffffffc;
    iVar3 = FUN_00410ce0(iVar3,param_1[2] * 2,uVar2 * 2,param_1 + 8);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1[2] = uVar2;
  }
  FUN_00410ed0((int)param_1);
  return 0;
}



int __cdecl FUN_00410ff0(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[0x12] + param_1[10] + param_2;
  iVar1 = 0;
  if ((uint)param_1[3] < uVar2) {
    uVar2 = uVar2 + 1 & 0xfffffffe;
    iVar1 = FUN_00410ce0(*param_1,param_1[3] << 5,uVar2 << 5,param_1 + 0xb);
    if (iVar1 == 0) {
      param_1[3] = uVar2;
      FUN_00411050((int)param_1);
    }
  }
  return iVar1;
}



void __cdecl FUN_00411050(int param_1)

{
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x28) * 0x20 + *(int *)(param_1 + 0x2c);
  return;
}



void __cdecl FUN_00411070(int param_1)

{
  *(undefined2 *)(param_1 + 0x36) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  FUN_00410ed0(param_1);
  FUN_00411050(param_1);
  return;
}



void __cdecl FUN_004110a0(int param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  
  sVar2 = *(short *)(param_1 + 0x16);
  sVar3 = *(short *)(param_1 + 0x34);
  *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x36) + sVar2;
  *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + *(short *)(param_1 + 0x34);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x48);
  uVar4 = 0;
  if ((int)sVar3 != 0) {
    do {
      psVar1 = (short *)(*(int *)(param_1 + 0x40) + uVar4 * 2);
      *psVar1 = *psVar1 + sVar2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(int)sVar3);
  }
  FUN_00411070(param_1);
  return;
}



int __cdecl FUN_004110f0(int *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  sVar1 = *(short *)(param_2 + 0x14);
  sVar2 = *(short *)(param_2 + 0x16);
  uVar7 = (uint)sVar2;
  iVar3 = FUN_00410f10(param_1,uVar7,(int)sVar1);
  if (iVar3 == 0) {
    puVar8 = *(undefined4 **)(param_2 + 0x18);
    puVar9 = (undefined4 *)param_1[6];
    for (uVar4 = uVar7 * 8 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar8 = *(undefined4 **)(param_2 + 0x1c);
    puVar9 = (undefined4 *)param_1[7];
    for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    uVar4 = sVar1 * 2;
    puVar8 = *(undefined4 **)(param_2 + 0x20);
    puVar9 = (undefined4 *)param_1[8];
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    if (((char)param_1[4] != '\0') && (*(char *)(param_2 + 0x10) != '\0')) {
      puVar8 = *(undefined4 **)(param_2 + 0x30);
      puVar9 = (undefined4 *)param_1[0xc];
      for (uVar7 = uVar7 * 8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
    }
    *(short *)((int)param_1 + 0x16) = sVar2;
    *(short *)(param_1 + 5) = sVar1;
    FUN_00410ed0((int)param_1);
  }
  return iVar3;
}



int __cdecl FUN_004111c0(int param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x58) == 0)) ||
     (iVar2 = *(int *)(param_1 + 0x54), iVar2 == 0)) {
    return 0x23;
  }
  if (*(uint *)(param_1 + 0x10) <= param_2) {
    return 6;
  }
  FUN_004113b0(iVar2);
  puVar3 = *(undefined4 **)(param_1 + 0x60);
  if ((param_3 & 0x400) != 0) {
    param_3 = param_3 & 0xfffffffb | 0x803;
  }
  piVar4 = *(int **)(puVar3[1] + 0x5c);
  if ((((piVar4 == (int *)0x0) || ((param_3 & 3) != 0)) ||
      ((uVar7 = *(uint *)*puVar3, (uVar7 & 0x100) == 0 || ((uVar7 & 0x200) != 0)))) ||
     (((uVar7 & 0x400) != 0 && ((param_3 & 0x20) == 0)))) {
    iVar5 = (**(code **)(puVar3[5] + 0x50))(iVar2,*(undefined4 *)(param_1 + 0x58),param_2,param_3);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar6 = FUN_00412410((short *)(iVar2 + 0x6c));
    iVar5 = 0;
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  else if ((((*(byte *)(param_1 + 8) & 2) == 0) ||
           (iVar5 = (**(code **)(puVar3[5] + 0x50))
                              (iVar2,*(undefined4 *)(param_1 + 0x58),param_2,param_3 | 0x4000),
           iVar5 != 0)) || (iVar5 = 0, *(int *)(iVar2 + 0x48) != 0x62697473)) {
    iVar5 = (**(code **)(*(int *)(*piVar4 + 0x14) + 4))
                      (piVar4,iVar2,*(undefined4 *)(param_1 + 0x58),param_2,param_3);
  }
  if ((param_3 & 0x10) == 0) {
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar2 + 0x28);
    *(undefined4 *)(iVar2 + 0x44) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x34);
  }
  if ((param_3 & 0x2000) == 0) {
    iVar6 = *(int *)(param_1 + 0x58);
    uVar1 = *(ushort *)(param_1 + 0x44);
    uVar7 = FUN_00410a10(*(uint *)(iVar2 + 0x38),(uint)*(ushort *)(iVar6 + 0xc) << 0x10,(uint)uVar1)
    ;
    *(uint *)(iVar2 + 0x38) = uVar7;
    uVar7 = FUN_00410a10(*(uint *)(iVar2 + 0x3c),(uint)*(ushort *)(iVar6 + 0xe) << 0x10,(uint)uVar1)
    ;
    *(uint *)(iVar2 + 0x3c) = uVar7;
  }
  if (((param_3 & 0x800) == 0) && (iVar6 = *(int *)(param_1 + 0x80), *(int *)(iVar6 + 0x1c) != 0)) {
    iVar8 = FUN_00411540(iVar2);
    if (iVar8 != 0) {
      iVar5 = (**(code **)(*(int *)(iVar8 + 0x14) + 0x2c))(iVar8,iVar2,iVar6 + 4,iVar6 + 0x14);
    }
    FUN_00412650((uint *)(iVar2 + 0x40),(uint *)(iVar6 + 4));
  }
  if (((iVar5 == 0) && (*(int *)(iVar2 + 0x48) != 0x62697473)) &&
     ((*(int *)(iVar2 + 0x48) != 0x636f6d70 && ((param_3 & 4) != 0)))) {
    iVar5 = FUN_004116c0(iVar2,param_3 >> 0xc & 1);
  }
  return iVar5;
}



void __cdecl FUN_004113b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
    FUN_00410d70(*(int *)(*(int *)(param_1 + 4) + 100),(int *)(param_1 + 0x58));
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffe;
  }
  puVar2 = (undefined4 *)(param_1 + 0x18);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x4c);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



undefined4 __cdecl FUN_00411430(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    return 0x23;
  }
  piVar2 = *(int **)(param_1 + 0x28);
  if (piVar2 == (int *)0x0) {
    return 0x26;
  }
  piVar1 = piVar2 + *(int *)(param_1 + 0x24);
  while( true ) {
    if (piVar1 <= piVar2) {
      return 6;
    }
    if (*(int *)(*piVar2 + 4) == param_2) break;
    piVar2 = piVar2 + 1;
  }
  *(int *)(param_1 + 0x5c) = *piVar2;
  return 0;
}



undefined4 __cdecl FUN_00411480(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    return 0x23;
  }
  piVar2 = *(int **)(param_1 + 0x28);
  if (piVar2 == (int *)0x0) {
    return 0x26;
  }
  piVar1 = piVar2 + *(int *)(param_1 + 0x24);
  while( true ) {
    if (piVar1 <= piVar2) {
      return 6;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 1;
  }
  *(int *)(param_1 + 0x5c) = *piVar2;
  return 0;
}



undefined4 __cdecl FUN_004114d0(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x5c) != 0)) {
                    // WARNING: Could not recover jumptable at 0x004114eb. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0x14) + 0x54))();
    return uVar1;
  }
  return 0;
}



int __cdecl FUN_004114f0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = iVar1;
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x50);
    if (param_3 != (int *)0x0) {
      if (*param_3 != 0) {
        iVar3 = *(int *)(*param_3 + 4);
      }
      *param_3 = 0;
    }
    if (iVar3 != 0) {
      while (iVar2 = *(int *)(iVar3 + 8), *(int *)(iVar2 + 0x18) != param_2) {
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          return iVar1;
        }
      }
      if (param_3 != (int *)0x0) {
        *param_3 = iVar3;
      }
    }
  }
  return iVar2;
}



void __cdecl FUN_00411540(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 4);
  iVar2 = *(int *)(iVar1 + 0x58);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) != *(int *)(param_1 + 0x48))) {
    FUN_004114f0(iVar1,*(int *)(param_1 + 0x48),(int *)0x0);
  }
  return;
}



int __cdecl FUN_00411570(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0x21;
  }
  if (param_2 != 0) {
    piVar2 = (int *)FUN_00411f10((int *)(param_1 + 0x50),param_2);
    if (piVar2 == (int *)0x0) {
      return 6;
    }
    FUN_00411f30((int *)(param_1 + 0x50),piVar2);
    if (*(int *)(param_2 + 0x18) == 0x6f75746c) {
      *(int *)(param_1 + 0x58) = param_2;
    }
    if (param_3 != 0) {
      pcVar1 = *(code **)(*(int *)(param_2 + 0x14) + 0x34);
      do {
        iVar3 = (*pcVar1)(param_2,*param_4,param_4[1]);
        if (iVar3 != 0) {
          return iVar3;
        }
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    return 0;
  }
  return 6;
}



int __cdecl FUN_00411600(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar3 = *(int *)(param_2 + 0x48);
  iVar2 = 0;
  if (iVar3 != 0x62697473) {
    local_4 = 0;
    bVar1 = false;
    if (iVar3 == 0x6f75746c) {
      local_4 = *(int *)(param_1 + 0x50);
      iVar3 = *(int *)(param_1 + 0x58);
    }
    else {
      iVar3 = FUN_004114f0(param_1,iVar3,&local_4);
    }
    iVar2 = 7;
    if (iVar3 != 0) {
      while (iVar2 = (**(code **)(iVar3 + 0x44))(iVar3,param_2,param_3,0), iVar2 != 0) {
        if ((char)iVar2 != '\x13') {
          return iVar2;
        }
        iVar3 = FUN_004114f0(param_1,*(int *)(param_2 + 0x48),&local_4);
        bVar1 = true;
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      iVar2 = 0;
      if (bVar1) {
        FUN_00411570(param_1,iVar3,0,(undefined4 *)0x0);
      }
    }
  }
  return iVar2;
}



int __cdecl FUN_004116c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 6;
  }
  iVar1 = FUN_00411600(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 4),param_1,param_2);
  return iVar1;
}



undefined4 __cdecl FUN_004116f0(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    return 0;
  }
  puVar6 = (undefined4 *)(param_1 + 0x10);
  puVar1 = puVar6 + *(int *)(param_1 + 0xc);
  if (puVar1 <= puVar6) {
    return 0;
  }
  do {
    pbVar3 = *(byte **)(*(int *)*puVar6 + 8);
    pbVar5 = param_2;
    do {
      bVar2 = *pbVar3;
      bVar7 = bVar2 < *pbVar5;
      if (bVar2 != *pbVar5) {
LAB_00411745:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0041174a;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar7 = bVar2 < pbVar5[1];
      if (bVar2 != pbVar5[1]) goto LAB_00411745;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_0041174a:
    if (iVar4 == 0) {
      return *puVar6;
    }
    puVar6 = puVar6 + 1;
    if (puVar1 <= puVar6) {
      return 0;
    }
  } while( true );
}



undefined4 __cdecl FUN_00411770(int param_1,byte *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004116f0(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    return *(undefined4 *)(*piVar1 + 0x14);
  }
  return 0;
}



byte __cdecl FUN_00411790(int param_1,uint param_2)

{
  int iVar1;
  
  *(uint *)(param_1 + 8) = param_2;
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x14))(param_1,param_2,0,0);
    return -(iVar1 != 0) & 0x55;
  }
  return -(*(uint *)(param_1 + 4) < param_2) & 0x55;
}



void __cdecl FUN_004117c0(int param_1,int param_2)

{
  FUN_00411790(param_1,*(int *)(param_1 + 8) + param_2);
  return;
}



undefined4 __cdecl FUN_004117e0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



void __cdecl FUN_004117f0(int *param_1,undefined4 *param_2,uint param_3)

{
  FUN_00411810(param_1,param_1[2],param_2,param_3);
  return;
}



undefined4 __cdecl FUN_00411810(int *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_4;
  
  local_4 = 0;
  if (param_2 < (uint)param_1[1]) {
    if ((code *)param_1[5] == (code *)0x0) {
      uVar1 = param_1[1] - param_2;
      if (param_4 < uVar1) {
        uVar1 = param_4;
      }
      puVar3 = (undefined4 *)(*param_1 + param_2);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_3 = *puVar3;
        puVar3 = puVar3 + 1;
        param_3 = param_3 + 1;
      }
      for (uVar2 = uVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        param_3 = (undefined4 *)((int)param_3 + 1);
      }
    }
    else {
      uVar1 = (*(code *)param_1[5])(param_1,param_2,param_3,param_4);
    }
    param_1[2] = uVar1 + param_2;
    if (uVar1 < param_4) {
      local_4 = 0x55;
    }
    return local_4;
  }
  return 0x55;
}



void __cdecl FUN_004118a0(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_00411900(param_1,param_2);
  if (iVar1 == 0) {
    *param_3 = param_1[8];
    param_1[8] = 0;
    param_1[9] = 0;
  }
  return;
}



void __cdecl FUN_004118d0(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00410d70(*(int *)(param_1 + 0x1c),param_2);
    *param_2 = 0;
    return;
  }
  *param_2 = 0;
  return;
}



int __cdecl FUN_00411900(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[5] != 0) {
    iVar1 = param_1[7];
    iVar2 = FUN_00410c90(iVar1,param_2,param_1);
    if (iVar2 == 0) {
      uVar3 = (*(code *)param_1[5])(param_1,param_1[2],*param_1,param_2);
      if (uVar3 < param_2) {
        FUN_00410d70(iVar1,param_1);
        iVar2 = 0x55;
      }
      param_1[8] = *param_1;
      param_1[9] = *param_1 + param_2;
      param_1[2] = param_1[2] + uVar3;
    }
    return iVar2;
  }
  uVar3 = param_1[2];
  if (uVar3 < (uint)param_1[1]) {
    if (uVar3 + param_2 <= (uint)param_1[1]) {
      param_1[8] = uVar3 + *param_1;
      param_1[9] = uVar3 + *param_1 + param_2;
      param_1[2] = uVar3 + param_2;
      return 0;
    }
  }
  return 0x55;
}



void __cdecl FUN_004119a0(int *param_1)

{
  if (param_1[5] != 0) {
    FUN_00410d70(param_1[7],param_1);
  }
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}



undefined1 __cdecl FUN_004119d0(int param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 0x20);
  uVar2 = 0;
  if (puVar1 < *(undefined1 **)(param_1 + 0x24)) {
    uVar2 = *puVar1;
    *(undefined1 **)(param_1 + 0x20) = puVar1 + 1;
  }
  return uVar2;
}



undefined2 __cdecl FUN_004119f0(int param_1)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  puVar1 = *(undefined1 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if (puVar1 + 1 < *(undefined1 **)(param_1 + 0x24)) {
    puVar3 = puVar1 + 2;
    uVar2 = CONCAT11(*puVar1,puVar1[1]);
  }
  *(undefined1 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}



undefined2 __cdecl FUN_00411a20(int param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  
  puVar1 = *(undefined2 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if ((int)puVar1 + 1U < *(uint *)(param_1 + 0x24)) {
    puVar3 = puVar1 + 1;
    uVar2 = *puVar1;
  }
  *(undefined2 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}



undefined4 __cdecl FUN_00411a50(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar1 = *(undefined1 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if (puVar1 + 3 < *(undefined1 **)(param_1 + 0x24)) {
    puVar3 = puVar1 + 4;
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
  }
  *(undefined1 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}



undefined4 __cdecl FUN_00411a90(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if ((int)puVar1 + 3U < *(uint *)(param_1 + 0x24)) {
    puVar3 = puVar1 + 1;
    uVar2 = *puVar1;
  }
  *(undefined4 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}



uint __thiscall FUN_00411ad0(uint3 param_1,int *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uStack_4;
  
  *param_3 = 0;
  uStack_4 = (uint)param_1;
  if ((code *)param_2[5] == (code *)0x0) {
    uVar2 = param_2[2];
    if (uVar2 < (uint)param_2[1]) {
      uVar1 = *(undefined1 *)(uVar2 + *param_2);
      param_2[2] = param_2[2] + 1;
      return CONCAT31((int3)(uVar2 >> 8),uVar1);
    }
  }
  else {
    uVar2 = (*(code *)param_2[5])(param_2,param_2[2],(int)&uStack_4 + 3,1);
    if (uVar2 == 1) {
      param_2[2] = param_2[2] + 1;
      return uStack_4 >> 0x18;
    }
  }
  *param_3 = 0x55;
  return uVar2 & 0xffffff00;
}



uint __cdecl FUN_00411b40(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 **ppuVar4;
  
  puVar2 = param_2;
  uVar3 = 0;
  *param_2 = 0;
  iVar1 = param_1[2];
  if ((uint)param_1[1] <= iVar1 + 1U) {
LAB_00411b9a:
    *puVar2 = 0x55;
    return uVar3 & 0xffff0000;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    ppuVar4 = (undefined4 **)(*param_1 + iVar1);
    if (ppuVar4 == (undefined4 **)0x0) goto LAB_00411b8d;
  }
  else {
    uVar3 = (*(code *)param_1[5])(param_1,iVar1,&param_2,2);
    if (uVar3 != 2) goto LAB_00411b9a;
    ppuVar4 = &param_2;
  }
  uVar3 = (uint)CONCAT11(*(undefined1 *)ppuVar4,*(undefined1 *)((int)ppuVar4 + 1));
LAB_00411b8d:
  param_1[2] = param_1[2] + 2;
  return uVar3;
}



uint __cdecl FUN_00411bb0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 **ppuVar4;
  
  puVar2 = param_2;
  uVar3 = 0;
  *param_2 = 0;
  iVar1 = param_1[2];
  if ((uint)param_1[1] <= iVar1 + 1U) {
LAB_00411c0a:
    *puVar2 = 0x55;
    return uVar3 & 0xffff0000;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    ppuVar4 = (undefined4 **)(*param_1 + iVar1);
    if (ppuVar4 == (undefined4 **)0x0) goto LAB_00411bfd;
  }
  else {
    uVar3 = (*(code *)param_1[5])(param_1,iVar1,&param_2,2);
    if (uVar3 != 2) goto LAB_00411c0a;
    ppuVar4 = &param_2;
  }
  uVar3 = (uint)*(ushort *)ppuVar4;
LAB_00411bfd:
  param_1[2] = param_1[2] + 2;
  return uVar3;
}



undefined4 __cdecl FUN_00411c20(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 **ppuVar4;
  
  puVar1 = param_2;
  uVar2 = 0;
  *param_2 = 0;
  iVar3 = param_1[2];
  if ((uint)param_1[1] <= iVar3 + 3U) {
LAB_00411c90:
    *puVar1 = 0x55;
    return 0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    ppuVar4 = (undefined4 **)(*param_1 + iVar3);
    if (ppuVar4 == (undefined4 **)0x0) goto LAB_00411c83;
  }
  else {
    iVar3 = (*(code *)param_1[5])(param_1,iVar3,&param_2,4);
    if (iVar3 != 4) goto LAB_00411c90;
    ppuVar4 = &param_2;
  }
  uVar2 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)ppuVar4,*(undefined1 *)((int)ppuVar4 + 1)),
                            *(undefined1 *)((int)ppuVar4 + 2)),*(undefined1 *)((int)ppuVar4 + 3));
LAB_00411c83:
  param_1[2] = param_1[2] + 4;
  return uVar2;
}



undefined4 * __cdecl FUN_00411ca0(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 **ppuVar4;
  
  puVar1 = param_2;
  puVar2 = (undefined4 *)0x0;
  *param_2 = 0;
  iVar3 = param_1[2];
  if ((uint)param_1[1] <= iVar3 + 3U) {
LAB_00411d11:
    *puVar1 = 0x55;
    return (undefined4 *)0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    ppuVar4 = (undefined4 **)(*param_1 + iVar3);
    if (ppuVar4 == (undefined4 **)0x0) goto LAB_00411d04;
  }
  else {
    iVar3 = (*(code *)param_1[5])(param_1,iVar3,&param_2,4);
    if (iVar3 != 4) goto LAB_00411d11;
    ppuVar4 = &param_2;
  }
  puVar2 = *ppuVar4;
LAB_00411d04:
  param_1[2] = param_1[2] + 4;
  return puVar2;
}



int __cdecl FUN_00411d20(int *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  int *piVar5;
  sbyte sVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  
  piVar5 = param_1;
  puVar9 = (uint *)(param_1 + 8);
  bVar4 = false;
  if (param_2 == (byte *)0x0) {
    return 6;
  }
  param_1 = (int *)0x0;
  puVar9 = (uint *)*puVar9;
LAB_00411d45:
  do {
    bVar1 = *param_2;
    switch(bVar1) {
    case 4:
      param_1 = (int *)FUN_00411900(piVar5,(uint)*(ushort *)(param_2 + 2));
      if (param_1 != (int *)0x0) goto LAB_00411ea1;
      puVar9 = (uint *)piVar5[8];
      bVar4 = true;
      param_2 = param_2 + 4;
      goto LAB_00411d45;
    default:
      piVar5[8] = (int)puVar9;
LAB_00411ea1:
      if (bVar4) {
        FUN_004119a0(piVar5);
      }
      return (int)param_1;
    case 8:
    case 9:
      uVar7 = (uint)(byte)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      sVar6 = 0x18;
      break;
    case 0xc:
    case 0xd:
      sVar6 = 0x10;
      uVar7 = (uint)CONCAT11((byte)*puVar9,*(byte *)((int)puVar9 + 1));
      puVar9 = (uint *)((int)puVar9 + 2);
      break;
    case 0xe:
    case 0xf:
      sVar6 = 0x10;
      uVar7 = (uint)(ushort)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 2);
      break;
    case 0x10:
    case 0x11:
      uVar7 = CONCAT31(CONCAT21(CONCAT11((byte)*puVar9,*(byte *)((int)puVar9 + 1)),
                                *(byte *)((int)puVar9 + 2)),*(byte *)((int)puVar9 + 3));
      sVar6 = 0;
      puVar9 = puVar9 + 1;
      break;
    case 0x12:
    case 0x13:
      uVar7 = *puVar9;
      sVar6 = 0;
      puVar9 = puVar9 + 1;
      break;
    case 0x14:
    case 0x15:
      bVar2 = *(byte *)((int)puVar9 + 2);
      bVar3 = (byte)*puVar9;
      goto LAB_00411e4d;
    case 0x16:
    case 0x17:
      bVar2 = (byte)*puVar9;
      bVar3 = *(byte *)((int)puVar9 + 2);
LAB_00411e4d:
      uVar7 = (uint)CONCAT21(CONCAT11(bVar3,*(byte *)((int)puVar9 + 1)),bVar2);
      sVar6 = 8;
      puVar9 = (uint *)((int)puVar9 + 3);
      break;
    case 0x18:
    case 0x19:
      bVar2 = param_2[1];
      puVar8 = (uint *)((uint)bVar2 + (int)puVar9);
      if (puVar8 <= (uint *)piVar5[9]) goto code_r0x00411d9f;
      param_1 = (int *)0x55;
      goto LAB_00411ea1;
    }
    if ((bVar1 & 1) != 0) {
      uVar7 = (int)(uVar7 << sVar6) >> sVar6;
    }
    puVar8 = (uint *)((uint)*(ushort *)(param_2 + 2) + param_3);
    if (param_2[1] == 1) {
      *(char *)puVar8 = (char)uVar7;
      param_2 = param_2 + 4;
    }
    else if (param_2[1] == 2) {
      *(short *)puVar8 = (short)uVar7;
      param_2 = param_2 + 4;
    }
    else {
      *puVar8 = uVar7;
      param_2 = param_2 + 4;
    }
  } while( true );
code_r0x00411d9f:
  if (bVar1 == 0x18) {
    puVar10 = (uint *)((uint)*(ushort *)(param_2 + 2) + param_3);
    for (uVar7 = (uint)(bVar2 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar7 = bVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(byte *)puVar10 = (byte)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar10 = (uint *)((int)puVar10 + 1);
    }
  }
  param_2 = param_2 + 4;
  puVar9 = puVar8;
  goto LAB_00411d45;
}



int __cdecl FUN_00411f10(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}



void __cdecl FUN_00411f30(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = iVar1;
      *param_2 = 0;
      param_2[1] = *param_1;
      *(int **)*param_1 = param_2;
      *param_1 = (int)param_2;
      return;
    }
    param_1[1] = iVar1;
    *param_2 = 0;
    param_2[1] = *param_1;
    *(int **)*param_1 = param_2;
    *param_1 = (int)param_2;
  }
  return;
}



int __cdecl FUN_00411f80(short *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *local_5c;
  int local_58;
  int local_54;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if ((param_1 == (short *)0x0) || (param_2 == (undefined4 *)0x0)) {
    return 6;
  }
  uVar1 = param_2[4];
  iVar2 = param_2[5];
  local_58 = 0;
  local_54 = 0;
  if (*param_1 < 1) {
    return 0;
  }
  do {
    iVar5 = (int)*(short *)(*(int *)(param_1 + 6) + local_54 * 2);
    piVar8 = (int *)(*(int *)(param_1 + 2) + local_58 * 8);
    local_5c = (int *)(*(int *)(param_1 + 2) + iVar5 * 8);
    bVar4 = (byte)uVar1;
    local_34 = (local_5c[1] << (bVar4 & 0x1f)) - iVar2;
    local_3c = (piVar8[1] << (bVar4 & 0x1f)) - iVar2;
    local_40 = (*piVar8 << (bVar4 & 0x1f)) - iVar2;
    pbVar6 = (byte *)(*(int *)(param_1 + 4) + local_58);
    local_38 = (*local_5c << (bVar4 & 0x1f)) - iVar2;
    if ((*pbVar6 & 3) == 2) {
      return 0x14;
    }
    local_48 = local_40;
    local_44 = local_3c;
    if ((*pbVar6 & 3) == 0) {
      if ((*(byte *)(*(int *)(param_1 + 4) + iVar5) & 3) == 1) {
        local_5c = local_5c + -2;
        local_48 = local_38;
        local_44 = local_34;
      }
      else {
        local_48 = (local_40 + local_38) / 2;
        local_44 = (local_3c + local_34) / 2;
      }
      piVar8 = piVar8 + -2;
      pbVar6 = pbVar6 + -1;
    }
    iVar3 = (*(code *)*param_2)(&local_48,param_3);
    while( true ) {
      while( true ) {
        while( true ) {
          if (iVar3 != 0) {
            return iVar3;
          }
          if (local_5c <= piVar8) {
            iVar3 = (*(code *)param_2[1])(&local_48,param_3);
            goto LAB_004120ce;
          }
          piVar10 = piVar8 + 2;
          pbVar7 = pbVar6 + 1;
          if ((*pbVar7 & 3) != 0) break;
          local_40 = (*piVar10 << (bVar4 & 0x1f)) - iVar2;
          local_3c = (piVar8[3] << (bVar4 & 0x1f)) - iVar2;
          while( true ) {
            if (local_5c <= piVar10) {
              iVar3 = (*(code *)param_2[2])(&local_40,&local_48,param_3);
              goto LAB_004120ce;
            }
            pbVar7 = pbVar7 + 1;
            iStack_30 = (piVar10[2] << (bVar4 & 0x1f)) - iVar2;
            iStack_2c = (piVar10[3] << (bVar4 & 0x1f)) - iVar2;
            if ((*pbVar7 & 3) == 1) break;
            if ((*pbVar7 & 3) != 0) {
              return 0x14;
            }
            iStack_8 = (iStack_30 + local_40) / 2;
            iStack_4 = (local_3c + iStack_2c) / 2;
            iVar3 = (*(code *)param_2[2])(&local_40,&iStack_8,param_3);
            if (iVar3 != 0) {
              return iVar3;
            }
            local_3c = iStack_2c;
            local_40 = iStack_30;
            piVar10 = piVar10 + 2;
          }
          iVar3 = (*(code *)param_2[2])(&local_40,&iStack_30,param_3);
          pbVar6 = pbVar7;
          piVar8 = piVar10 + 2;
        }
        if ((*pbVar7 & 3) != 1) break;
        iStack_10 = (*piVar10 << (bVar4 & 0x1f)) - iVar2;
        iStack_c = (piVar8[3] << (bVar4 & 0x1f)) - iVar2;
        iVar3 = (*(code *)param_2[1])(&iStack_10,param_3);
        pbVar6 = pbVar7;
        piVar8 = piVar10;
      }
      if (local_5c < piVar8 + 4) {
        return 0x14;
      }
      if ((pbVar6[2] & 3) != 2) {
        return 0x14;
      }
      piVar9 = piVar8 + 6;
      iStack_20 = (*piVar10 << (bVar4 & 0x1f)) - iVar2;
      iStack_1c = (piVar8[3] << (bVar4 & 0x1f)) - iVar2;
      iStack_28 = (piVar8[4] << (bVar4 & 0x1f)) - iVar2;
      iStack_24 = (piVar8[5] << (bVar4 & 0x1f)) - iVar2;
      if (local_5c < piVar9) break;
      iStack_18 = (*piVar9 << (bVar4 & 0x1f)) - iVar2;
      iStack_14 = (piVar8[7] << (bVar4 & 0x1f)) - iVar2;
      iVar3 = (*(code *)param_2[3])(&iStack_20,&iStack_28,&iStack_18,param_3);
      pbVar6 = pbVar6 + 3;
      piVar8 = piVar9;
    }
    iVar3 = (*(code *)param_2[3])(&iStack_20,&iStack_28,&local_48,param_3);
LAB_004120ce:
    if (iVar3 != 0) {
      return iVar3;
    }
    local_58 = iVar5 + 1;
    local_54 = local_54 + 1;
    if (*param_1 <= local_54) {
      return 0;
    }
  } while( true );
}



int __cdecl FUN_00412330(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_4 != (undefined4 *)0x0) && (param_1 != 0)) {
    puVar2 = &DAT_00430980;
    puVar3 = param_4;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = FUN_00410c90(param_1,param_2 * 8,param_4 + 1);
    if (iVar1 == 0) {
      iVar1 = FUN_00410c90(param_1,param_2,param_4 + 2);
      if (iVar1 == 0) {
        iVar1 = FUN_00410c90(param_1,param_3 * 2,param_4 + 3);
        if (iVar1 == 0) {
          *(undefined2 *)param_4 = (undefined2)param_3;
          *(short *)((int)param_4 + 2) = (short)param_2;
          param_4[4] = param_4[4] | 1;
          return 0;
        }
      }
    }
    param_4[4] = param_4[4] | 1;
    FUN_00412500(param_1,param_4);
    return iVar1;
  }
  return 6;
}



int __cdecl FUN_004123f0(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x21;
  }
  iVar1 = FUN_00412330(*param_1,param_2,param_3,param_4);
  return iVar1;
}



undefined4 __cdecl FUN_00412410(short *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  if (param_1 != (short *)0x0) {
    iVar4 = (int)param_1[1];
    iVar5 = (int)*param_1;
    if (iVar4 == 0) {
      if (iVar5 == 0) {
        return 0;
      }
    }
    else if ((0 < iVar4) && (0 < iVar5)) {
      iVar1 = -1;
      iVar2 = 0;
      if (0 < iVar5) {
        psVar6 = *(short **)(param_1 + 6);
        iVar3 = -1;
        do {
          iVar1 = (int)*psVar6;
          if (iVar1 <= iVar3) {
            return 6;
          }
          if (iVar4 <= iVar1) {
            return 6;
          }
          iVar2 = iVar2 + 1;
          psVar6 = psVar6 + 1;
          iVar3 = iVar1;
        } while (iVar2 < iVar5);
      }
      if (iVar1 == iVar4 + -1) {
        return 0;
      }
    }
  }
  return 6;
}



undefined4 __cdecl FUN_00412470(short *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((((param_1 != (short *)0x0) && (param_2 != (short *)0x0)) && (param_1[1] == param_2[1])) &&
     (*param_1 == *param_2)) {
    puVar4 = *(undefined4 **)(param_1 + 2);
    puVar5 = *(undefined4 **)(param_2 + 2);
    for (uVar2 = (uint)((int)param_1[1] << 3) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    sVar1 = param_1[1];
    puVar4 = *(undefined4 **)(param_1 + 4);
    puVar5 = *(undefined4 **)(param_2 + 4);
    for (uVar2 = (uint)(int)sVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = (int)sVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    sVar1 = *param_1;
    puVar4 = *(undefined4 **)(param_1 + 6);
    puVar5 = *(undefined4 **)(param_2 + 6);
    for (uVar2 = (uint)((int)sVar1 << 1) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = (int)sVar1 << 1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(uint *)(param_2 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe | *(uint *)(param_2 + 8) & 1;
    return 0;
  }
  return 6;
}



undefined4 __cdecl FUN_00412500(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    if ((*(byte *)(param_2 + 4) & 1) != 0) {
      FUN_00410d70(param_1,param_2 + 1);
      FUN_00410d70(param_1,param_2 + 2);
      FUN_00410d70(param_1,param_2 + 3);
    }
    puVar2 = &DAT_00430980;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    return 0;
  }
  return 6;
}



undefined4 __cdecl FUN_00412550(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x21;
  }
  uVar1 = FUN_00412500(*param_1,param_2);
  return uVar1;
}



void __cdecl FUN_00412570(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    if (*(short *)(param_1 + 2) == 0) {
      param_2[1] = 0;
      param_2[2] = 0;
      *param_2 = 0;
      param_2[3] = 0;
      return;
    }
    piVar1 = *(int **)(param_1 + 4);
    iVar6 = *piVar1;
    iVar8 = piVar1[1];
    iVar7 = iVar6;
    iVar3 = iVar8;
    piVar5 = piVar1;
    while (piVar4 = piVar5 + 2, piVar4 < piVar1 + *(short *)(param_1 + 2) * 2) {
      iVar2 = *piVar4;
      if (iVar2 < iVar6) {
        iVar6 = iVar2;
      }
      if (iVar7 < iVar2) {
        iVar7 = iVar2;
      }
      iVar2 = piVar5[3];
      if (iVar2 < iVar8) {
        iVar8 = iVar2;
      }
      piVar5 = piVar4;
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
    }
    param_2[1] = iVar8;
    param_2[2] = iVar7;
    *param_2 = iVar6;
    param_2[3] = iVar3;
  }
  return;
}



void __cdecl FUN_00412600(int param_1,int param_2,int param_3)

{
  int *piVar1;
  ushort uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  uVar2 = 0;
  if (0 < *(short *)(param_1 + 2)) {
    do {
      *piVar1 = *piVar1 + param_2;
      piVar1[1] = piVar1[1] + param_3;
      piVar1 = piVar1 + 2;
      uVar2 = uVar2 + 1;
    } while ((int)(uint)uVar2 < (int)*(short *)(param_1 + 2));
  }
  return;
}



void __cdecl FUN_00412650(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 != (uint *)0x0) && (param_2 != (uint *)0x0)) {
    uVar3 = param_1[1];
    uVar1 = FUN_00410b80(*param_1,param_2[2]);
    uVar2 = FUN_00410b80(uVar3,param_2[3]);
    uVar3 = FUN_00410b80(uVar3,param_2[1]);
    uVar4 = FUN_00410b80(*param_1,*param_2);
    *param_1 = uVar3 + uVar4;
    param_1[1] = uVar1 + uVar2;
  }
  return;
}



void __cdecl FUN_004126b0(int param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 4);
  puVar1 = puVar2 + *(short *)(param_1 + 2) * 2;
  for (; puVar2 < puVar1; puVar2 = puVar2 + 2) {
    FUN_00412650(puVar2,param_2);
  }
  return;
}



void __cdecl FUN_004126f0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 100);
  FUN_00412720(param_1);
  FUN_00410d70(iVar1,(int *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



void __cdecl FUN_00412720(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 100);
  iVar2 = *(int *)(param_1 + 0x68);
  uVar3 = *(uint *)(param_1 + 0x88);
  uVar4 = *(int *)(param_1 + 0x84) * 0xa0 + uVar3;
  for (; uVar3 < uVar4; uVar3 = uVar3 + 0xa0) {
    FUN_00412790(uVar3,iVar2);
  }
  FUN_00410d70(iVar1,(int *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x84) = 0;
  return;
}



void __cdecl FUN_00412790(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x98) != 0) {
    FUN_004118d0(param_2,(int *)(param_1 + 0x98));
  }
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(int *)(param_1 + 0x98) = 0;
  return;
}



int __cdecl FUN_004127d0(int *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  
  iVar2 = param_2[0x19];
  iVar7 = FUN_00412a20((int)param_2);
  if (iVar7 != 0) {
    iVar7 = FUN_00410c90(iVar2,0xa0,param_2 + 0x22);
    if (iVar7 != 0) {
      return iVar7;
    }
    puVar3 = (uint *)param_2[0x22];
    param_2[0x21] = 1;
    *puVar3 = 0;
    puVar3[0x27] = param_1[1];
    iVar7 = FUN_00412990(puVar3,param_1);
    if (iVar7 != 0) goto LAB_00412977;
  }
  iVar4 = param_2[0x21];
  puVar5 = (undefined2 *)param_2[0x22];
  *param_2 = 1;
  param_2[2] = 0x12;
  if (puVar5[0x34] == puVar5[0x35]) {
    param_2[2] = 0x16;
  }
  if (*(char *)(puVar5 + 0x2d) != '\0') {
    param_2[3] = param_2[3] | 1;
  }
  if (799 < (ushort)puVar5[0x2f]) {
    param_2[3] = param_2[3] | 2;
  }
  iVar7 = FUN_00410c90(iVar2,iVar4 * 4,param_2 + 8);
  if (iVar7 == 0) {
    puVar9 = (undefined2 *)param_2[8];
    param_2[7] = param_2[0x21];
    if (puVar5 < puVar5 + iVar4 * 0x50) {
      puVar8 = puVar5 + 0x32;
      do {
        puVar9[1] = puVar8[-1];
        *puVar9 = *puVar8;
        puVar1 = puVar8 + 0x1e;
        puVar9 = puVar9 + 2;
        puVar8 = puVar8 + 0x50;
      } while (puVar1 < puVar5 + iVar4 * 0x50);
    }
    param_2[9] = 1;
    *(undefined2 *)((int)param_2 + 0x9a) = 1;
    param_2[0x24] = param_2;
    param_2[0x23] = param_2 + 0x24;
    param_2[0x17] = param_2 + 0x24;
    param_2[10] = param_2 + 0x23;
    param_2[0x25] = 0x756e6963;
    *(undefined2 *)(param_2 + 0x26) = 3;
    param_2[4] = ((uint)*(byte *)((int)puVar5 + 0x6d) - (uint)*(byte *)(puVar5 + 0x36)) + 1;
    uVar6 = param_2[3];
    param_2[5] = *(int *)(puVar5 + 0x4c) + *(int *)(puVar5 + 0x3c);
    param_2[6] = s_Regular_0043e944;
    if ((uVar6 & 2) == 0) {
      if ((uVar6 & 1) == 0) {
        return 0;
      }
      param_2[6] = s_Italic_0043e928;
      return 0;
    }
    if ((uVar6 & 1) != 0) {
      param_2[6] = s_Bold_Italic_0043e938;
      return iVar7;
    }
    param_2[6] = &DAT_0043e930;
    return iVar7;
  }
LAB_00412977:
  FUN_004126f0((int)param_2);
  return iVar7;
}



int __cdecl FUN_00412990(uint *param_1,int *param_2)

{
  short sVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  
  bVar2 = FUN_00411790((int)param_2,*param_1);
  iVar3 = CONCAT31(extraout_var,bVar2);
  if (iVar3 == 0) {
    iVar3 = FUN_00411d20(param_2,&DAT_004309c8,(int)(param_1 + 2));
    if (iVar3 == 0) {
      sVar1 = (short)param_1[2];
      if ((sVar1 != 0x200) && (sVar1 != 0x300)) {
        return 2;
      }
      if ((param_1[0x13] & 1) != 0) {
        return 2;
      }
      if (*(short *)((int)param_1 + 0x62) == 0) {
        *(short *)((int)param_1 + 0x62) = (short)param_1[0x19];
      }
      bVar2 = FUN_00411790((int)param_2,*param_1);
      iVar3 = CONCAT31(extraout_var_00,bVar2);
      if (iVar3 == 0) {
        iVar3 = FUN_004118a0(param_2,param_1[3],(int *)(param_1 + 0x26));
      }
    }
  }
  return iVar3;
}



int __cdecl FUN_00412a20(int param_1)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  undefined3 extraout_var;
  int iVar8;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined2 extraout_var_03;
  undefined3 extraout_var_02;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  short local_1c;
  ushort local_1a;
  int local_18;
  uint *local_14;
  uint local_10;
  uint local_c;
  short local_8;
  ushort local_6;
  ushort local_4;
  
  local_18 = *(int *)(param_1 + 100);
  piVar1 = *(int **)(param_1 + 0x68);
  uVar13 = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  bVar3 = FUN_00411790((int)piVar1,0);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    return CONCAT31(extraout_var,bVar3);
  }
  iVar8 = FUN_00411d20(piVar1,&DAT_00430998,(int)&local_1c);
  if (iVar8 != 0) {
    return iVar8;
  }
  iVar8 = 2;
  if (local_1c == 0x5a4d) {
    bVar3 = FUN_00411790((int)piVar1,(uint)local_1a);
    if (CONCAT31(extraout_var_00,bVar3) != 0) {
      return CONCAT31(extraout_var_00,bVar3);
    }
    iVar8 = FUN_00411d20(piVar1,&DAT_004309ac,(int)&local_8);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = 2;
    if (local_8 == 0x454e) {
      bVar3 = FUN_00411790((int)piVar1,(uint)local_6 + (uint)local_1a);
      if (CONCAT31(extraout_var_01,bVar3) != 0) {
        return CONCAT31(extraout_var_01,bVar3);
      }
      iVar8 = FUN_00411900(piVar1,(uint)local_4 - (uint)local_6);
      if (iVar8 != 0) {
        return iVar8;
      }
      uVar4 = FUN_00411a20((int)piVar1);
      local_10 = CONCAT22(extraout_var_03,uVar4);
      sVar5 = FUN_00411a20((int)piVar1);
      uVar7 = 0;
      if (sVar5 != 0) {
        uVar7 = 0;
        do {
          uVar6 = FUN_00411a20((int)piVar1);
          if (sVar5 == -0x7ff8) {
            iVar8 = FUN_004117e0((int)piVar1);
            uVar13 = iVar8 + 4 + (piVar1[8] - piVar1[9]);
            uVar7 = uVar6;
            break;
          }
          piVar1[8] = piVar1[8] + (uint)uVar6 * 0xc + 4;
          sVar5 = FUN_00411a20((int)piVar1);
        } while (sVar5 != 0);
      }
      FUN_004119a0(piVar1);
      if ((uVar7 == 0) || (uVar13 == 0)) {
        return 2;
      }
      bVar3 = FUN_00411790((int)piVar1,uVar13);
      if (CONCAT31(extraout_var_02,bVar3) != 0) {
        return CONCAT31(extraout_var_02,bVar3);
      }
      uVar9 = (uint)uVar7;
      local_14 = (uint *)(param_1 + 0x88);
      uVar13 = uVar9 * 0xa0;
      local_c = uVar13;
      iVar8 = FUN_00410c90(local_18,uVar13,local_14);
      if (iVar8 != 0) {
        return iVar8;
      }
      *(uint *)(param_1 + 0x84) = uVar9;
      iVar8 = FUN_00411900(piVar1,uVar9 * 0xc);
      uVar2 = local_10;
      if (iVar8 != 0) {
        return iVar8;
      }
      piVar10 = (int *)*local_14;
      local_14 = (uint *)(piVar10 + uVar9 * 0x28);
      if (piVar10 < local_14) {
        uVar9 = local_10 & 0xffff;
        do {
          uVar7 = FUN_00411a20((int)piVar1);
          *piVar10 = (uint)uVar7 << ((byte)uVar2 & 0x1f);
          uVar7 = FUN_00411a20((int)piVar1);
          piVar10[1] = uVar9;
          piVar11 = piVar10 + 0x28;
          piVar10[0x27] = (uint)uVar7 << ((byte)uVar2 & 0x1f);
          piVar1[8] = piVar1[8] + 8;
          piVar10 = piVar11;
          uVar13 = local_c;
        } while (piVar11 < local_14);
      }
      FUN_004119a0(piVar1);
      puVar12 = *(uint **)(param_1 + 0x88);
      puVar14 = (uint *)(uVar13 + (int)puVar12);
      if (puVar14 <= puVar12) {
        return 0;
      }
      while (iVar8 = FUN_00412990(puVar12,piVar1), iVar8 == 0) {
        puVar12 = puVar12 + 0x28;
        if (puVar14 <= puVar12) {
          return 0;
        }
      }
    }
  }
  FUN_00412720(param_1);
  return iVar8;
}



int __cdecl FUN_00412ff0(uint *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  puVar5 = param_1;
  puVar1 = (uint *)param_1[0x84];
  uVar2 = param_1[0x19];
  param_1 = puVar1;
  if (puVar1 == (uint *)0x0) {
    iVar6 = FUN_00410c90(uVar2,0x11c,&param_1);
    if (iVar6 != 0) {
      return iVar6;
    }
    puVar5[0x84] = (uint)param_1;
  }
  uVar3 = param_2;
  if (param_2 != 0) {
    if (*param_1 == 0) {
      iVar6 = FUN_00410c90(uVar2,param_2 << 5,param_1 + 0x25);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = FUN_00410c90(uVar2,uVar3 * 0xc0,param_1 + 0x36);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = FUN_00410c90(uVar2,uVar3 * 8,param_1 + 0x22);
      if (iVar6 != 0) {
        return iVar6;
      }
      param_1[0x23] = param_1[0x22] + uVar3 * 4;
      param_1[0x24] = (uint)(puVar5 + 0x21);
      param_1[0x35] = (uint)(puVar5 + 0x29);
      if (1 < uVar3) {
        iVar7 = 0xdc;
        iVar6 = uVar3 - 1;
        do {
          *(int *)(iVar7 + (int)param_1) = *(int *)(iVar7 + -4 + (int)param_1) + 0xc0;
          *(int *)(iVar7 + -0x44 + (int)param_1) = *(int *)(iVar7 + -0x48 + (int)param_1) + 0x20;
          iVar7 = iVar7 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *param_1 = uVar3;
    }
    else if (*param_1 != param_2) {
      return -1;
    }
  }
  iVar6 = 0;
  if (param_3 != 0) {
    if ((param_1[1] != 0) && (param_1[1] != param_3)) {
      return -1;
    }
    param_1[1] = param_3;
  }
  uVar3 = *param_1;
  uVar4 = param_1[1];
  if ((((uVar3 != 0) && (uVar4 != 0)) && (param_1[6] == 0)) &&
     ((iVar6 = FUN_00410c90(uVar2,uVar3 * uVar4 * 4,param_1 + 6), iVar6 == 0 && (1 < uVar3)))) {
    iVar8 = 0x1c;
    iVar7 = uVar3 - 1;
    iVar9 = uVar4 * 4;
    do {
      *(uint *)(iVar8 + (int)param_1) = param_1[6] + iVar9;
      iVar8 = iVar8 + 4;
      iVar9 = iVar9 + uVar4 * 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return iVar6;
}



undefined4 __cdecl FUN_00413640(byte param_1)

{
  uint uVar1;
  
  if (DAT_004433c0 < 2) {
    uVar1 = *(ushort *)(PTR_DAT_004431b4 + (uint)param_1 * 2) & 0x107;
  }
  else {
    uVar1 = _isctype((uint)param_1,0x107);
  }
  if ((((uVar1 == 0) && (param_1 != 0x2e)) && (param_1 != 0x5f)) &&
     ((param_1 != 0x2d && (param_1 != 0x2b)))) {
    return 0;
  }
  return 1;
}



void __cdecl FUN_004140f0(int *param_1)

{
  int iVar1;
  
  if (param_1[10] != 0) {
    iVar1 = FUN_00414120(param_1);
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(param_1[10]);
    }
    param_1[10] = 0;
  }
  return;
}



undefined4 __cdecl FUN_00414120(int *param_1)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(*param_1 + 0x214);
  iVar2 = FUN_004116f0(*(int *)(*(int *)(*param_1 + 0x60) + 4),(byte *)s_pshinter_0043eb78);
  if (((iVar2 != 0) && (puVar1 != (undefined4 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)*puVar1, UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x00414154. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (*UNRECOVERED_JUMPTABLE)();
    return uVar3;
  }
  return 0;
}



int __cdecl FUN_00414160(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = param_1;
  puVar2 = (undefined4 *)FUN_00414120(param_1);
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
    iVar3 = (*(code *)*puVar2)(*(undefined4 *)(iVar3 + 100),iVar3 + 0xa4,&param_1);
    if (iVar3 == 0) {
      piVar1[10] = (int)param_1;
      return 0;
    }
  }
  return iVar3;
}



undefined4 __cdecl FUN_004141a0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00414120(param_1);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(iVar1 + 4))(param_1[10],param_1[4],param_1[5],0,0);
    return uVar2;
  }
  return 0;
}



void __cdecl FUN_00414230(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 100);
    FUN_00414350(param_1);
    *(undefined4 *)(param_1 + 0x210) = 0;
    FUN_00410d70(iVar1,(int *)(param_1 + 0x84));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x88));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x8c));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x90));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x94));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x1a4));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x1a0));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x19c));
    FUN_00410d70(iVar1,(int *)(param_1 + 400));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x194));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x180));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x184));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x188));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x178));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x17c));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x164));
    if (*(undefined4 **)(param_1 + 0x1e4) != (undefined4 *)0x0) {
      FUN_00415ad0(iVar1,*(undefined4 **)(param_1 + 0x1e4));
    }
    FUN_00410d70(iVar1,(int *)(param_1 + 0x20c));
    *(undefined4 *)(param_1 + 0x208) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}



void __cdecl FUN_00414350(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 100);
  puVar5 = *(uint **)(param_1 + 0x210);
  if (puVar5 != (uint *)0x0) {
    uVar4 = *puVar5;
    uVar6 = puVar5[1];
    FUN_00410d70(iVar1,(int *)(puVar5 + 6));
    if (1 < uVar4) {
      puVar2 = puVar5 + 7;
      uVar3 = uVar4;
      while (uVar3 = uVar3 - 1, uVar3 != 0) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
    }
    FUN_00410d70(iVar1,(int *)(puVar5 + 0x36));
    FUN_00410d70(iVar1,(int *)(puVar5 + 0x25));
    if (uVar4 != 0) {
      puVar2 = puVar5 + 0x24;
      do {
        puVar2[0x11] = 0;
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    FUN_00410d70(iVar1,(int *)(puVar5 + 0x22));
    puVar5[0x23] = 0;
    if (uVar6 != 0) {
      puVar2 = puVar5 + 2;
      uVar4 = uVar6;
      do {
        FUN_00410d70(iVar1,(int *)puVar2);
        puVar2 = puVar2 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      if (uVar6 != 0) {
        puVar5 = puVar5 + 0x16;
        do {
          FUN_00410d70(iVar1,(int *)(puVar5 + 1));
          *(undefined1 *)puVar5 = 0;
          puVar5 = puVar5 + 3;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
    FUN_00410d70(iVar1,(int *)(param_1 + 0x210));
  }
  return;
}



int __cdecl FUN_00414750(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  int local_188;
  undefined4 *local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_170 [18];
  byte *local_128;
  int local_124;
  byte *local_120;
  int local_11c;
  undefined4 local_114;
  int local_100;
  int local_f8;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_c0;
  undefined4 local_a4;
  int local_98;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_3c;
  undefined4 local_38;
  int local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar4 = *(int *)(param_1 + 0x1e0);
  FUN_00415140(local_170);
  *(undefined4 *)(param_1 + 0xa8) = 4;
  local_178 = FUN_00414a20(local_170,*(int **)(param_1 + 0x68),*(int *)(param_1 + 100),iVar4);
  if ((((local_178 == 0) &&
       (local_178 = FUN_00414ef0(param_1,local_170,local_128,local_124), local_178 == 0)) &&
      (local_178 = FUN_00414bf0(local_170,iVar4), local_178 == 0)) &&
     (local_178 = FUN_00414ef0(param_1,local_170,local_120,local_11c), local_178 == 0)) {
    *(undefined4 *)(param_1 + 0x198) = local_dc;
    if (local_2c != 0) {
      *(undefined4 *)(param_1 + 0x18c) = local_3c;
      local_2c = 0;
      *(undefined4 *)(param_1 + 0x180) = local_38;
      *(undefined4 *)(param_1 + 400) = local_20;
      *(undefined4 *)(param_1 + 0x194) = local_1c;
    }
    if (local_98 == 0) {
      local_178 = 3;
    }
    *(undefined4 *)(param_1 + 0x1a4) = local_88;
    *(undefined4 *)(param_1 + 0x184) = local_a4;
    *(undefined4 *)(param_1 + 0x1a0) = local_8c;
    local_98 = 0;
    *(undefined4 *)(param_1 + 0x188) = local_d8;
    *(undefined4 *)(param_1 + 0x19c) = local_c0;
    local_d8 = 0;
    local_c0 = 0;
    if (*(int *)(param_1 + 0x168) == 1) {
      iVar4 = 0;
      local_180 = 32000;
      local_188 = -32000;
      if (0 < local_100) {
LAB_004148e5:
        *(undefined2 *)(*(int *)(param_1 + 0x178) + iVar4 * 2) = 0;
        *(char **)(*(int *)(param_1 + 0x17c) + iVar4 * 4) = s__notdef_0043eb68;
        pbVar6 = *(byte **)(local_f8 + iVar4 * 4);
        if ((pbVar6 != (byte *)0x0) && (local_17c = 0, 0 < *(int *)(param_1 + 0x198))) {
          local_184 = *(undefined4 **)(param_1 + 0x19c);
          do {
            pbVar7 = (byte *)*local_184;
            pbVar2 = pbVar6;
            pbVar5 = pbVar7;
            do {
              bVar1 = *pbVar2;
              bVar8 = bVar1 < *pbVar5;
              if (bVar1 != *pbVar5) {
LAB_00414964:
                iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_00414969;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar2[1];
              bVar8 = bVar1 < pbVar5[1];
              if (bVar1 != pbVar5[1]) goto LAB_00414964;
              pbVar2 = pbVar2 + 2;
              pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_00414969:
            if (iVar3 == 0) {
              *(undefined2 *)(*(int *)(param_1 + 0x178) + iVar4 * 2) = (undefined2)local_17c;
              *(byte **)(*(int *)(param_1 + 0x17c) + iVar4 * 4) = pbVar7;
              iVar3 = 8;
              bVar8 = true;
              pbVar6 = (byte *)s__notdef_0043eb68;
              goto code_r0x004149b3;
            }
            local_17c = local_17c + 1;
            local_184 = local_184 + 1;
          } while (local_17c < *(int *)(param_1 + 0x198));
        }
        goto LAB_004149cb;
      }
LAB_004149df:
      *(int *)(param_1 + 0x170) = local_180;
      *(int *)(param_1 + 0x174) = local_188;
      *(undefined4 *)(param_1 + 0x16c) = local_114;
    }
  }
  FUN_00415180((int)local_170);
  return local_178;
  while( true ) {
    iVar3 = iVar3 + -1;
    bVar8 = *pbVar6 == *pbVar7;
    pbVar6 = pbVar6 + 1;
    pbVar7 = pbVar7 + 1;
    if (!bVar8) break;
code_r0x004149b3:
    if (iVar3 == 0) break;
  }
  if (!bVar8) {
    if (iVar4 < local_180) {
      local_180 = iVar4;
    }
    if (local_188 < iVar4) {
      local_188 = iVar4;
    }
  }
LAB_004149cb:
  iVar4 = iVar4 + 1;
  if (local_100 <= iVar4) goto LAB_004149df;
  goto LAB_004148e5;
}



int __cdecl FUN_00414a20(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  byte bVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  
  piVar2 = param_1;
  (*(code *)**(undefined4 **)(param_4 + 4))(param_1,0,0,param_3);
  piVar3 = param_2;
  piVar1 = piVar2 + 0x12;
  piVar2[0x11] = (int)param_2;
  piVar2[0x13] = 0;
  *piVar1 = 0;
  piVar2[0x15] = 0;
  piVar2[0x14] = 0;
  *(undefined1 *)(piVar2 + 0x16) = 0;
  *(undefined1 *)((int)piVar2 + 0x59) = 0;
  *(undefined1 *)((int)piVar2 + 0x5a) = 0;
  bVar4 = FUN_00411790((int)param_2,0);
  iVar5 = CONCAT31(extraout_var,bVar4);
  if ((iVar5 == 0) && (iVar5 = FUN_00414b90(piVar3,(short *)&param_4,&param_1), iVar5 == 0)) {
    if ((short)param_4 == -0x7fff) {
      *(undefined1 *)(piVar2 + 0x16) = 1;
    }
    else {
      bVar4 = FUN_00411790((int)piVar3,0);
      iVar5 = CONCAT31(extraout_var_00,bVar4);
      if (iVar5 != 0) goto LAB_00414b6a;
      param_1 = (int *)piVar3[1];
    }
    if (piVar3[5] == 0) {
      *piVar1 = piVar3[2] + *piVar3;
      piVar2[0x13] = (int)param_1;
      *(undefined1 *)((int)piVar2 + 0x59) = 1;
      iVar5 = FUN_004117c0((int)piVar3,(int)param_1);
      if (iVar5 != 0) goto LAB_00414b6a;
    }
    else {
      iVar5 = FUN_00410c90(param_3,(uint)param_1,piVar1);
      if ((iVar5 != 0) ||
         (iVar5 = FUN_004117f0(piVar3,(undefined4 *)*piVar1,(uint)param_1), iVar5 != 0))
      goto LAB_00414b6a;
      piVar2[0x13] = (int)param_1;
    }
    if ((0x10 < (int)param_1) &&
       ((iVar5 = strncmp((char *)*piVar1,s___PS_AdobeFont_1_0043eba8,0x10), iVar5 == 0 ||
        (iVar5 = strncmp((char *)*piVar1,s___FontType_0043eb9c,10), iVar5 == 0)))) {
      iVar5 = *piVar1;
      piVar2[2] = piVar2[0x13] + iVar5;
      piVar2[1] = iVar5;
      *piVar2 = iVar5;
      return 0;
    }
    iVar5 = 2;
  }
LAB_00414b6a:
  if (*(char *)((int)piVar2 + 0x59) == '\0') {
    FUN_00410d70(param_3,piVar1);
  }
  return iVar5;
}



void __cdecl FUN_00414b90(int *param_1,short *param_2,undefined4 *param_3)

{
  int iVar1;
  short local_8 [2];
  undefined4 local_4;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = FUN_00411d20(param_1,&DAT_00430ac8,(int)local_8);
  if ((iVar1 == 0) && ((local_8[0] == -0x7fff || (local_8[0] == -0x7ffe)))) {
    *param_2 = local_8[0];
    *param_3 = local_4;
  }
  return;
}



int __cdecl FUN_00414bf0(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  byte *pbVar11;
  int *piVar12;
  int *piVar13;
  byte *local_8;
  uint local_4;
  
  piVar2 = param_1;
  local_4 = param_1[4];
  piVar12 = (int *)param_1[0x11];
  if ((char)param_1[0x16] == '\0') {
    piVar13 = (int *)param_1[0x12];
    piVar12 = (int *)(param_1[0x13] + (int)piVar13);
    piVar9 = piVar13;
    do {
      if ((((((char)*piVar9 == 'e') && ((int *)((int)piVar9 + 9U) < piVar12)) &&
           (*(char *)((int)piVar9 + 1) == 'e')) &&
          ((*(char *)((int)piVar9 + 2) == 'x' && (*(char *)((int)piVar9 + 3) == 'e')))) &&
         ((char)piVar9[1] == 'c')) {
        piVar10 = (int *)((int)piVar9 + 6);
        if (*(char *)((int)piVar9 + 6) == '\n') {
          piVar10 = (int *)((int)piVar9 + 7);
        }
        pbVar11 = (byte *)((param_1[0x13] - (int)piVar10) + (int)piVar13);
        local_8 = pbVar11;
        if (*(char *)((int)param_1 + 0x59) == '\0') {
          param_1[0x14] = (int)piVar13;
          *(undefined1 *)((int)param_1 + 0x5a) = 1;
          param_1[0x12] = 0;
          param_1[0x13] = 0;
          param_1 = piVar12;
        }
        else {
          piVar13 = param_1 + 0x14;
          param_1 = piVar12;
          iVar5 = FUN_00410c90(local_4,(uint)(pbVar11 + 1),piVar13);
          if (iVar5 != 0) {
            return iVar5;
          }
        }
        piVar2[0x15] = (int)pbVar11;
        uVar4 = FUN_00414ec0(*(char *)((int)piVar10 + 3));
        uVar6 = FUN_00414ec0(*(char *)((int)piVar10 + 2));
        uVar7 = FUN_00414ec0((char)*piVar10);
        uVar8 = FUN_00414ec0(*(char *)((int)piVar10 + 1));
        if ((int)(uVar4 | uVar6 | uVar7 | uVar8) < 0) {
          piVar12 = (int *)piVar2[0x14];
          for (uVar4 = (uint)local_8 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *piVar12 = *piVar10;
            piVar10 = piVar10 + 1;
            piVar12 = piVar12 + 1;
          }
          for (uVar4 = (uint)local_8 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(char *)piVar12 = (char)*piVar10;
            piVar10 = (int *)((int)piVar10 + 1);
            piVar12 = (int *)((int)piVar12 + 1);
          }
          goto LAB_00414e84;
        }
        local_8 = (byte *)piVar2[0x14];
        piVar12 = piVar10;
        if (param_1 <= piVar10) goto LAB_00414e73;
        goto LAB_00414e20;
      }
      piVar9 = (int *)((int)piVar9 + 1);
    } while (piVar9 < piVar12);
  }
  else {
    uVar4 = FUN_004117e0((int)piVar12);
    piVar2[0x15] = 0;
    iVar5 = FUN_00414b90(piVar12,(short *)&param_1,&local_8);
    if (iVar5 != 0) {
      return iVar5;
    }
    while ((short)param_1 == -0x7ffe) {
      piVar2[0x15] = (int)(local_8 + piVar2[0x15]);
      iVar5 = FUN_004117c0((int)piVar12,(int)local_8);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = FUN_00414b90(piVar12,(short *)&param_1,&local_8);
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    if (piVar2[0x15] != 0) {
      bVar3 = FUN_00411790((int)piVar12,uVar4);
      if (CONCAT31(extraout_var,bVar3) != 0) {
        return CONCAT31(extraout_var,bVar3);
      }
      iVar5 = FUN_00410c90(local_4,piVar2[0x15],piVar2 + 0x14);
      if (iVar5 != 0) {
        return iVar5;
      }
      piVar2[0x15] = 0;
      iVar5 = FUN_00414b90(piVar12,(short *)&param_1,&local_8);
      pbVar11 = local_8;
      while ((local_8 = pbVar11, iVar5 == 0 && ((short)param_1 == -0x7ffe))) {
        iVar5 = FUN_004117f0(piVar12,(undefined4 *)(piVar2[0x15] + piVar2[0x14]),(uint)pbVar11);
        if (iVar5 != 0) {
          return iVar5;
        }
        piVar2[0x15] = (int)(pbVar11 + piVar2[0x15]);
        iVar5 = FUN_00414b90(piVar12,(short *)&param_1,&local_8);
        pbVar11 = local_8;
      }
      goto LAB_00414e84;
    }
  }
  return 3;
LAB_00414e20:
  do {
    piVar13 = (int *)((int)piVar12 + 1);
    cVar1 = (char)*piVar10;
    if ((cVar1 != '\r') && (cVar1 != '\n')) {
      local_4 = FUN_00414ec0(cVar1);
      if (((int)local_4 < 0) || (param_1 <= piVar13)) break;
      uVar4 = FUN_00414ec0(*(char *)piVar13);
      *local_8 = (byte)uVar4 | (char)local_4 << 4;
      piVar10 = (int *)((int)piVar10 + 1);
      piVar13 = (int *)((int)piVar12 + 2);
      local_8 = local_8 + 1;
    }
    piVar10 = (int *)((int)piVar10 + 1);
    piVar12 = piVar13;
  } while (piVar10 < param_1);
LAB_00414e73:
  piVar2[0x15] = (int)local_8 - piVar2[0x14];
  *local_8 = 0;
LAB_00414e84:
  (**(code **)(param_2 + 0x10))(piVar2[0x14],piVar2[0x15],0xd971);
  iVar5 = piVar2[0x14];
  piVar2[1] = iVar5;
  *piVar2 = iVar5;
  piVar2[2] = piVar2[0x15] + iVar5;
  return 0;
}



uint __cdecl FUN_00414ec0(char param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  uVar1 = iVar2 - 0x30;
  if (9 < uVar1) {
    if (iVar2 - 0x61U < 6) {
      return iVar2 - 0x57;
    }
    if (iVar2 - 0x41U < 6) {
      return iVar2 - 0x37;
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



int __cdecl FUN_00414ef0(int param_1,undefined4 *param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined **ppuVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 local_c [8];
  int iStack_4;
  
  pbVar1 = param_3 + param_4;
  *param_2 = param_3;
  param_2[2] = pbVar1;
  param_2[3] = 0;
  do {
    if (pbVar1 <= param_3) {
      return param_2[3];
    }
    if (((*param_3 == 0x46) && (param_3 + 0x19 < pbVar1)) &&
       (iVar3 = strncmp((char *)param_3,s_FontDirectory_0043ebc4,0xd), iVar3 == 0)) {
      pbVar9 = param_3 + 0xd;
      for (pbVar10 = pbVar9; pbVar10 < pbVar1; pbVar10 = pbVar10 + 1) {
        if ((*pbVar10 == 0x6b) || (iVar3 = strncmp((char *)pbVar10,s_known_0043ebbc,5), iVar3 == 0))
        {
          if (pbVar10 < pbVar1) {
            *param_2 = pbVar10 + 5;
            (*(code *)param_2[0xd])(param_2,local_c);
            if (iStack_4 == 3) {
              pbVar9 = (byte *)*param_2;
            }
          }
          break;
        }
      }
    }
    else {
      pbVar9 = param_3;
      if ((*param_3 == 0x2f) && (param_3 + 2 < pbVar1)) {
        pbVar9 = param_3 + 1;
        pbVar10 = pbVar9;
        while ((pbVar10 < pbVar1 && (iVar3 = FUN_00413640(*pbVar10), iVar3 != 0))) {
          pbVar10 = pbVar10 + 1;
        }
        iVar3 = (int)pbVar10 - (int)pbVar9;
        if ((0 < iVar3) && (iVar3 < 0x16)) {
          pcVar7 = s_version_0043eb3c;
          ppuVar8 = &PTR_s_version_00430ad8;
          do {
            if (*pbVar9 == *pcVar7) {
              uVar5 = 0xffffffff;
              pbVar4 = (byte *)pcVar7;
              do {
                if (uVar5 == 0) break;
                uVar5 = uVar5 - 1;
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
              } while (bVar2 != 0);
              if (iVar3 == ~uVar5 - 1) {
                if (1 < iVar3) {
                  pbVar4 = param_3 + 2;
                  iVar6 = 1;
                  while (*pbVar4 == pbVar4[(int)pcVar7 - (int)pbVar9]) {
                    iVar6 = iVar6 + 1;
                    pbVar4 = pbVar4 + 1;
                    if (iVar3 <= iVar6) goto LAB_0041502d;
                  }
                  if (iVar6 < iVar3) goto LAB_00415077;
                }
LAB_0041502d:
                *param_2 = pbVar10;
                (*(code *)param_2[7])(param_2);
                iVar3 = FUN_00415090(param_1,(int)param_2,(int)ppuVar8);
                param_2[3] = iVar3;
                if (iVar3 != 0) {
                  return iVar3;
                }
                pbVar9 = (byte *)*param_2;
                break;
              }
            }
LAB_00415077:
            pcVar7 = ppuVar8[8];
            ppuVar8 = ppuVar8 + 8;
          } while ((byte *)pcVar7 != (byte *)0x0);
        }
      }
    }
    param_3 = pbVar9 + 1;
  } while( true );
}



undefined4 __cdecl FUN_00415090(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  iVar3 = param_2;
  puVar1 = *(undefined4 **)(param_1 + 0x210);
  iVar2 = *(int *)(param_3 + 8);
  if (iVar2 == 7) {
    (**(code **)(param_3 + 0xc))(param_1,param_2);
    return *(undefined4 *)(iVar3 + 0xc);
  }
  if (*(int *)(param_3 + 4) == 2) {
    param_1 = param_1 + 0x84;
    uVar5 = 0;
    piVar4 = &param_1;
    if (puVar1 == (undefined4 *)0x0) goto LAB_0041510c;
    piVar4 = puVar1 + 0x24;
  }
  else {
    if (*(int *)(param_3 + 4) != 3) {
      param_1 = param_1 + 0x84;
      piVar4 = &param_1;
      uVar5 = 0;
      goto LAB_0041510c;
    }
    param_1 = param_1 + 0xa4;
    uVar5 = 0;
    piVar4 = &param_1;
    if (puVar1 == (undefined4 *)0x0) goto LAB_0041510c;
    piVar4 = puVar1 + 0x35;
  }
  uVar5 = *puVar1;
LAB_0041510c:
  if ((iVar2 != 5) && (iVar2 != 6)) {
    uVar5 = (**(code **)(param_2 + 0x3c))(param_2,param_3,piVar4,uVar5,0);
    return uVar5;
  }
  uVar5 = (**(code **)(param_2 + 0x40))(param_2,param_3,piVar4,uVar5,0);
  return uVar5;
}



void __cdecl FUN_00415140(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x5c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x25] = 0;
  param_1[0x17] = 0;
  param_1[0x1b] = 0;
  param_1[0x36] = 0;
  param_1[0x29] = 0;
  param_1[0x51] = 0;
  param_1[0x43] = 0;
  *(undefined1 *)(param_1 + 0x5b) = 0;
  return;
}



void __cdecl FUN_00415180(int param_1)

{
  if (*(code **)(param_1 + 0x90) != (code *)0x0) {
    (**(code **)(param_1 + 0x90))(param_1 + 0x60);
  }
  if (*(code **)(param_1 + 0xfc) != (code *)0x0) {
    (**(code **)(param_1 + 0xfc))(param_1 + 0xcc);
  }
  if (*(code **)(param_1 + 200) != (code *)0x0) {
    (**(code **)(param_1 + 200))(param_1 + 0x98);
  }
  if (*(code **)(param_1 + 0x130) != (code *)0x0) {
    (**(code **)(param_1 + 0x130))(param_1 + 0x100);
  }
  if (*(code **)(param_1 + 0x168) != (code *)0x0) {
    (**(code **)(param_1 + 0x168))(param_1 + 0x138);
  }
  FUN_00415200(param_1);
  return;
}



void __cdecl FUN_00415200(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  FUN_00410d70(iVar1,(int *)(param_1 + 0x50));
  if (*(char *)(param_1 + 0x59) == '\0') {
    FUN_00410d70(iVar1,(int *)(param_1 + 0x48));
  }
  (**(code **)(param_1 + 0x18))(param_1);
  return;
}



undefined4 __cdecl FUN_00415360(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(param_1 + 0x210);
  uVar2 = 6;
  if ((puVar1 != (uint *)0x0) && (puVar1[1] == param_2)) {
    uVar5 = 0;
    if (*puVar1 != 0) {
      do {
        uVar6 = 0;
        uVar3 = 0x10000;
        if (puVar1[1] != 0) {
          do {
            uVar4 = *(uint *)(param_3 + uVar6 * 4);
            if ((int)uVar4 < 0) {
              uVar4 = 0;
            }
            else if (0x10000 < (int)uVar4) {
              uVar4 = 0x10000;
            }
            if ((uVar5 & 1 << ((byte)uVar6 & 0x1f)) == 0) {
              uVar4 = 0x10000 - uVar4;
            }
            uVar3 = FUN_00410b80(uVar3,uVar4);
            uVar6 = uVar6 + 1;
          } while (uVar6 < puVar1[1]);
        }
        *(uint *)(puVar1[0x22] + uVar5 * 4) = uVar3;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



int __cdecl FUN_00415620(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 local_5e0 [56];
  undefined4 uStack_5a8;
  undefined1 uStack_58f;
  undefined1 uStack_588;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  
  iVar1 = *(int *)(param_1 + 0x1e0);
  *param_2 = 0;
  iVar1 = (*(code *)**(undefined4 **)(iVar1 + 0xc))
                    (local_5e0,param_1,0,0,*(undefined4 *)(param_1 + 0x19c),
                     *(undefined4 *)(param_1 + 0x210),0,FUN_004156e0);
  if (iVar1 == 0) {
    uStack_78 = *(undefined4 *)(param_1 + 0x18c);
    uStack_70 = *(undefined4 *)(param_1 + 0x194);
    uStack_58f = 0;
    uStack_74 = *(undefined4 *)(param_1 + 400);
    iVar1 = 0;
    uStack_588 = 1;
    if (0 < *(int *)(param_1 + 0x198)) {
      do {
        FUN_004156e0((int)local_5e0,iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x198));
    }
    *param_2 = uStack_5a8;
    iVar1 = 0;
  }
  return iVar1;
}



void __cdecl FUN_004156e0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x574) = *(undefined4 *)(iVar1 + 0x1ac);
  *(undefined4 *)(param_1 + 0x578) = *(undefined4 *)(iVar1 + 0x1b0);
  *(undefined4 *)(param_1 + 0x57c) = *(undefined4 *)(iVar1 + 0x1b4);
  *(undefined4 *)(param_1 + 0x580) = *(undefined4 *)(iVar1 + 0x1b8);
  *(undefined4 *)(param_1 + 0x584) = *(undefined4 *)(iVar1 + 0x1bc);
  *(undefined4 *)(param_1 + 0x588) = *(undefined4 *)(iVar1 + 0x1c0);
  (**(code **)(param_1 + 0x5dc))
            (param_1,*(undefined4 *)(*(int *)(iVar1 + 0x1a0) + param_2 * 4),
             *(undefined4 *)(*(int *)(iVar1 + 0x1a4) + param_2 * 4));
  return;
}



void __cdecl FUN_00415ad0(int param_1,undefined4 *param_2)

{
  FUN_00410d70(param_1,param_2 + 1);
  *param_2 = 0;
  FUN_00410d70(param_1,(int *)&param_2);
  return;
}



int __cdecl FUN_00415cb0(undefined4 *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  byte local_40 [64];
  
  iVar7 = 0;
  for (pbVar8 = (byte *)*param_1;
      ((((bVar1 = *pbVar8, bVar1 == 0x20 || (bVar1 == 9)) || (bVar1 == 0x3a)) || (bVar1 == 0x3b)) &&
      (pbVar8 < param_2)); pbVar8 = pbVar8 + 1) {
  }
  *param_1 = pbVar8;
  while( true ) {
    if (DAT_004433c0 < 2) {
      uVar2 = *(ushort *)(PTR_DAT_004431b4 + (uint)*pbVar8 * 2) & 0x107;
    }
    else {
      uVar2 = _isctype((uint)*pbVar8,0x107);
    }
    if ((((uVar2 == 0) && (*pbVar8 != 0x5f)) && (*pbVar8 != 0x2e)) || (param_2 <= pbVar8)) break;
    pbVar8 = pbVar8 + 1;
  }
  uVar2 = (int)pbVar8 - (int)*param_1;
  if ((0 < (int)uVar2) && ((int)uVar2 < 0x40)) {
    pbVar3 = (byte *)*param_1;
    pbVar9 = local_40;
    for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pbVar9 = *(undefined4 *)pbVar3;
      pbVar3 = pbVar3 + 4;
      pbVar9 = pbVar9 + 4;
    }
    for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pbVar9 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      pbVar9 = pbVar9 + 1;
    }
    local_40[uVar2] = 0;
    if (0 < *(int *)(param_3 + 0x114)) {
      puVar6 = *(undefined4 **)(param_3 + 0x118);
      iVar7 = 0;
      do {
        pbVar3 = (byte *)*puVar6;
        if ((pbVar3 != (byte *)0x0) && (*pbVar3 == local_40[0])) {
          pbVar9 = local_40;
          do {
            bVar1 = *pbVar3;
            bVar10 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_00415dab:
              iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
              goto LAB_00415db0;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar10 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_00415dab;
            pbVar3 = pbVar3 + 2;
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_00415db0:
          if (iVar4 == 0) break;
        }
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 1;
        if (*(int *)(param_3 + 0x114) <= iVar7) {
          *param_1 = pbVar8;
          return 0;
        }
      } while( true );
    }
  }
  *param_1 = pbVar8;
  return iVar7;
}



int __cdecl FUN_00415df0(undefined4 *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = (byte *)*param_1;
  iVar4 = 0;
  iVar2 = 1;
  if (pbVar3 < param_2) {
    while( true ) {
      if (DAT_004433c0 < 2) {
        uVar1 = (byte)PTR_DAT_004431b4[(uint)*pbVar3 * 2] & 4;
      }
      else {
        uVar1 = _isctype((uint)*pbVar3,4);
      }
      if (uVar1 != 0) break;
      iVar2 = 1;
      if (*pbVar3 == 0x2d) {
        iVar2 = -1;
      }
      pbVar3 = pbVar3 + 1;
      if (param_2 <= pbVar3) {
        *param_1 = pbVar3;
        return 0;
      }
    }
    for (; pbVar3 < param_2; pbVar3 = pbVar3 + 1) {
      if (DAT_004433c0 < 2) {
        uVar1 = (byte)PTR_DAT_004431b4[(uint)*pbVar3 * 2] & 4;
      }
      else {
        uVar1 = _isctype((uint)*pbVar3,4);
      }
      if (uVar1 == 0) break;
      iVar4 = (*pbVar3 - 0x30) + iVar4 * 10;
    }
  }
  *param_1 = pbVar3;
  return iVar2 * iVar4;
}



int __cdecl FUN_00415eb0(int *param_1,int *param_2)

{
  return (*param_1 << 0x10 | param_1[1]) - (*param_2 << 0x10 | param_2[1]);
}



void __cdecl FUN_00415ee0(int *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = param_1[1];
  uVar4 = *param_1 * 0x10 + -0x10 + uVar5;
  uVar6 = param_2 << 0x10 | param_3;
  if (uVar5 <= uVar4) {
    do {
      iVar1 = (((int)(uVar4 - uVar5) >> 4) - ((int)(uVar4 - uVar5) >> 0x1f) >> 1) * 0x10;
      iVar2 = iVar1 + uVar5;
      uVar3 = *(uint *)(iVar1 + 4 + uVar5) | *(int *)(iVar1 + uVar5) << 0x10;
      if (uVar3 == uVar6) {
        *param_4 = *(undefined4 *)(iVar2 + 8);
        param_4[1] = *(undefined4 *)(iVar2 + 0xc);
        return;
      }
      if (uVar3 < uVar6) {
        uVar5 = iVar2 + 0x10;
      }
      else {
        uVar4 = iVar2 - 0x10;
      }
    } while (uVar5 <= uVar4);
  }
  *param_4 = 0;
  param_4[1] = 0;
  return;
}



void __cdecl FUN_00415f60(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0xb0) & 8) == 0) {
    uVar3 = (param_2 * param_4 + 0x24U) / 0x48;
    uVar4 = (param_3 * param_5 + 0x24U) / 0x48;
    uVar2 = FUN_00410c00(uVar3,(uint)*(ushort *)(iVar1 + 0x44));
    param_1[4] = uVar2;
    uVar2 = FUN_00410c00(uVar4,(uint)*(ushort *)(iVar1 + 0x44));
    *(short *)((int)param_1 + 0xe) = (short)((int)uVar4 >> 6);
    *(short *)(param_1 + 3) = (short)((int)uVar3 >> 6);
    param_1[5] = uVar2;
  }
  *(undefined1 *)(param_1 + 0x14) = 0;
  param_1[0x15] = 0xffff;
  FUN_004176d0(param_1);
  return;
}



uint __cdecl FUN_00416010(int param_1,int *param_2,ushort param_3,uint param_4)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0x25;
  }
  if (param_2 == (int *)0x0) {
    param_4 = param_4 | 3;
  }
  if ((param_4 & 1) != 0) {
    uVar1 = FUN_004160d0(0,param_1,param_3,param_4);
    return uVar1;
  }
  if (param_2 != (int *)0x0) {
    if (*param_2 != *(int *)(param_1 + 4)) {
      return 0x23;
    }
    if (((char)param_2[0x14] == '\0') && (uVar1 = FUN_004176d0(param_2), uVar1 != 0)) {
      return uVar1;
    }
  }
  uVar1 = FUN_004160d0((int)param_2,param_1,param_3,param_4);
  return uVar1;
}



undefined4 __cdecl FUN_00416090(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_004116f0(*(int *)(param_1 + 4),&DAT_0043ec08);
  if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 0x14) != 0)) {
    uVar2 = (**(code **)(*(int *)(*piVar1 + 0x14) + 0x10))(param_1,param_2);
    return uVar2;
  }
  return 0;
}



int __cdecl FUN_004160d0(int param_1,int param_2,ushort param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  byte local_a8;
  byte bStack_a7;
  char cStack_a6;
  char cStack_a5;
  uint uStack_a4;
  int aiStack_a0 [4];
  uint uStack_90;
  int iStack_88;
  undefined4 uStack_4c;
  undefined1 auStack_48 [28];
  undefined1 auStack_2c [44];
  
  iVar3 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(iVar3 + 0x210);
  iVar1 = *(int *)(iVar3 + 0x68);
  if (((param_1 == 0) || ((param_4 & 1) != 0)) || ((param_4 & 0x400) != 0)) {
    param_4 = param_4 | 0xb;
    param_1 = 0;
  }
  *(undefined4 *)(param_2 + 0x80) = 0;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x54) != 0xffff)) &&
     ((*(int *)(iVar2 + 0x5c) != 0 &&
      (((param_4 & 8) == 0 &&
       (iVar2 = (**(code **)(iVar2 + 0x60))
                          (iVar3,*(int *)(param_1 + 0x54),param_3,param_4,iVar1,param_2 + 0x4c,
                           &local_a8), iVar2 == 0)))))) {
    *(uint *)(param_2 + 0x1c) = (uint)local_a8 << 6;
    *(undefined2 *)(param_2 + 0x6e) = 0;
    *(undefined2 *)(param_2 + 0x6c) = 0;
    *(uint *)(param_2 + 0x18) = (uint)bStack_a7 << 6;
    *(int *)(param_2 + 0x20) = (int)cStack_a6 << 6;
    *(int *)(param_2 + 0x24) = (int)cStack_a5 << 6;
    *(uint *)(param_2 + 0x28) = (uStack_a4 & 0xff) << 6;
    iVar2 = (int)(char)(uStack_a4 >> 8);
    *(int *)(param_2 + 0x2c) = iVar2 << 6;
    iVar3 = (int)(char)(uStack_a4 >> 0x10);
    *(uint *)(param_2 + 0x34) = (uStack_a4 >> 0x18) << 6;
    *(int *)(param_2 + 0x30) = iVar3 << 6;
    *(undefined4 *)(param_2 + 0x48) = 0x62697473;
    if ((param_4 & 0x10) == 0) {
      *(int *)(param_2 + 100) = (int)cStack_a6;
      *(int *)(param_2 + 0x68) = (int)cStack_a5;
      return 0;
    }
    *(int *)(param_2 + 100) = iVar2;
    *(int *)(param_2 + 0x68) = iVar3;
    return 0;
  }
  if ((param_4 & 0x4000) == 0) {
    iVar2 = (**(code **)(iVar3 + 0x1f8))(iVar3,0x676c7966,iVar1,0);
    if (iVar2 == 0) {
      piVar4 = aiStack_a0;
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      iVar2 = *(int *)(*(int *)(iVar3 + 0x60) + 0x24);
      aiStack_a0[3] = iVar2;
      FUN_00410dd0(iVar2);
      FUN_00416320((int)auStack_2c,(short *)(iVar2 + 0x14),0,0);
      FUN_00416320((int)auStack_48,(short *)(iVar2 + 0x14),0,0);
      *(undefined4 *)(param_2 + 0x7c) = 0;
      if ((param_1 != 0) && (*(ushort *)(param_1 + 0xe) < 0x18)) {
        *(undefined4 *)(param_2 + 0x7c) = 0x100;
      }
      uStack_90 = param_4;
      aiStack_a0[1] = param_1;
      aiStack_a0[2] = param_2;
      aiStack_a0[0] = iVar3;
      iStack_88 = iVar1;
      uStack_4c = FUN_004117e0(iVar1);
      *(undefined4 *)(param_2 + 0x48) = 0x6f75746c;
      *(undefined4 *)(param_2 + 0x80) = 0;
      iVar2 = FUN_00416380(aiStack_a0,(uint)param_3);
      if (iVar2 == 0) {
        FUN_004169e0(aiStack_a0,(uint)param_3);
      }
    }
    return iVar2;
  }
  return 6;
}



void __cdecl FUN_00416320(int param_1,short *param_2,int param_3,int param_4)

{
  *(short *)(param_1 + 8) = param_2[1] - (short)param_3;
  *(short *)(param_1 + 10) = *param_2 - (short)param_4;
  *(int *)(param_1 + 0xc) = *(int *)(param_2 + 0xe) + param_3 * 8;
  *(int *)(param_1 + 0x10) = *(int *)(param_2 + 2) + param_3 * 8;
  *(int *)(param_1 + 0x14) = *(int *)(param_2 + 4) + param_3;
  *(int *)(param_1 + 0x18) = *(int *)(param_2 + 6) + param_4 * 2;
  return;
}



int __cdecl FUN_00416380(int *param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint local_38;
  uint local_24;
  int iStack_1c;
  
  uVar10 = param_2;
  piVar9 = param_1;
  iVar4 = *param_1;
  piVar5 = (int *)param_1[3];
  if (*(uint *)(iVar4 + 0x10) <= param_2) {
    return 0x10;
  }
  local_38 = 0x10000;
  local_24 = 0x10000;
  param_1[5] = param_2;
  if ((param_1[4] & 1U) == 0) {
    local_38 = *(uint *)(param_1[1] + 0x10);
    local_24 = *(uint *)(param_1[1] + 0x14);
  }
  FUN_004167b0(iVar4,param_2,~(byte)((uint)param_1[4] >> 9) & 1,(undefined2 *)&param_1,
               (undefined2 *)&param_2);
  piVar9[0xd] = (int)(short)param_1;
  uVar14 = param_2 & 0xffff;
  piVar9[0xe] = uVar14;
  if ((char)piVar9[0x10] == '\0') {
    *(undefined1 *)(piVar9 + 0x10) = 1;
    piVar9[0xf] = uVar14;
  }
  iVar15 = *(int *)(*(int *)(iVar4 + 0x284) + uVar10 * 4);
  if ((*(ushort *)(iVar4 + 0x280) - 1 <= uVar10) ||
     (iVar12 = *(int *)(*(int *)(iVar4 + 0x284) + 4 + uVar10 * 4) - iVar15, iVar12 == 0)) {
    piVar9[9] = 0;
    piVar9[0xb] = 0;
    piVar9[10] = 0;
    piVar9[0xc] = 0;
    piVar9[0x11] = 0;
    piVar9[0x13] = uVar14;
    if ((*(byte *)(piVar9 + 4) & 1) == 0) {
      uVar10 = FUN_00410b80(uVar14,local_38);
      piVar9[0x13] = uVar10;
    }
    return 0;
  }
  piVar9[7] = iVar12;
  param_1 = (int *)(**(code **)(iVar4 + 0x1fc))(piVar9,uVar10,iVar15 + piVar9[0x15],iVar12);
  if (param_1 == (int *)0x0) {
    param_1 = (int *)(**(code **)(iVar4 + 0x200))(piVar9);
    if (param_1 == (int *)0x0) {
      iVar15 = piVar9[8];
      uVar10 = piVar9[9] - piVar9[0xd];
      piVar9[0x12] = 0;
      piVar9[0x14] = 0;
      piVar9[0x11] = uVar10;
      piVar9[0x13] = piVar9[0xe] + uVar10;
      if ((*(byte *)(piVar9 + 4) & 1) == 0) {
        uVar10 = FUN_00410b80(uVar10,local_38);
        piVar9[0x11] = uVar10;
        uVar10 = FUN_00410b80(piVar9[0x13],local_38);
        piVar9[0x13] = uVar10;
      }
      if ((short)iVar15 < 0) {
        sVar3 = *(short *)((int)piVar5 + 0x16);
        iVar15 = piVar9[2];
        param_1 = (int *)(**(code **)(iVar4 + 0x208))(piVar9);
        if (param_1 == (int *)0x0) {
          (**(code **)(iVar4 + 0x20c))(piVar9);
          if ((piVar9[4] & 0x400U) != 0) {
            FUN_004110a0((int)piVar5);
            *(int *)(iVar15 + 0x80) = piVar5[10];
            *(undefined4 *)(iVar15 + 0x48) = 0x636f6d70;
            *(int *)(iVar15 + 0x84) = piVar5[0xb];
            return (int)param_1;
          }
          iVar4 = piVar5[0x12];
          iVar15 = piVar5[10];
          FUN_004110a0((int)piVar5);
          iStack_1c = 0;
          if (iVar4 < 1) {
            return (int)param_1;
          }
          iVar15 = iVar15 << 5;
          do {
            iVar12 = piVar9[0x11];
            iVar6 = piVar9[0x12];
            uVar10 = (uint)*(short *)((int)piVar5 + 0x16);
            iVar7 = piVar9[0x13];
            iVar8 = piVar9[0x14];
            iVar11 = FUN_00416380(piVar9,*(uint *)(piVar5[0xb] + iVar15));
            if (iVar11 != 0) {
              return iVar11;
            }
            iVar11 = piVar5[0xb] + iVar15;
            if ((*(byte *)(iVar11 + 5) & 2) == 0) {
              piVar9[0x11] = iVar12;
              piVar9[0x12] = iVar6;
              piVar9[0x13] = iVar7;
              piVar9[0x14] = iVar8;
            }
            param_2 = (int)*(short *)((int)piVar5 + 0x16) - uVar10;
            param_1 = (int *)0x0;
            if ((*(byte *)(iVar11 + 4) & 200) != 0) {
              puVar17 = (uint *)(piVar5[6] + uVar10 * 8);
              puVar16 = (uint *)(piVar5[0xc] + uVar10 * 8);
              puVar1 = puVar17 + param_2 * 2;
              if (puVar17 < puVar1) {
                do {
                  FUN_00412650(puVar17,(uint *)(iVar11 + 0x10));
                  FUN_00412650(puVar16,(uint *)(iVar11 + 0x10));
                  puVar17 = puVar17 + 2;
                  puVar16 = puVar16 + 2;
                } while (puVar17 < puVar1);
              }
            }
            uVar14 = *(uint *)(iVar11 + 0xc);
            if ((*(byte *)(iVar11 + 4) & 2) == 0) {
              uVar13 = *(int *)(iVar11 + 8) + (int)sVar3;
              if ((uVar10 <= uVar13) || (param_2 <= uVar14)) {
                return 0x15;
              }
              iVar12 = piVar5[6];
              piVar2 = (int *)(iVar12 + (uVar14 + uVar10 + (int)sVar3) * 8);
              uVar18 = *(int *)(iVar12 + uVar13 * 8) - *piVar2;
              uVar14 = *(int *)(iVar12 + 4 + uVar13 * 8) - piVar2[1];
            }
            else {
              uVar18 = *(uint *)(iVar11 + 8);
              if ((*(byte *)(piVar9 + 4) & 1) == 0) {
                uVar18 = FUN_00410b80(uVar18,local_38);
                uVar14 = FUN_00410b80(uVar14,local_24);
                if ((*(byte *)(iVar11 + 4) & 4) != 0) {
                  uVar18 = uVar18 + 0x20 & 0xffffffc0;
                  uVar14 = uVar14 + 0x20 & 0xffffffc0;
                }
              }
            }
            if (uVar14 != 0 || uVar18 != 0) {
              FUN_00416850(param_2,piVar5[6] + uVar10 * 8,uVar18,uVar14);
              FUN_00416850(param_2,piVar5[0xc] + uVar10 * 8,uVar18,uVar14);
            }
            iStack_1c = iStack_1c + 1;
            iVar15 = iVar15 + 0x20;
          } while (iStack_1c < iVar4);
          return (int)param_1;
        }
      }
      else {
        param_1 = (int *)FUN_00410f10(piVar5,0,(int)(short)iVar15);
        if (((param_1 == (int *)0x0) &&
            (param_1 = (int *)(**(code **)(iVar4 + 0x204))(piVar9), param_1 == (int *)0x0)) &&
           (param_1 = (int *)FUN_00416890((int)piVar9), param_1 == (int *)0x0)) {
          FUN_004110a0((int)piVar5);
        }
      }
    }
    (**(code **)(iVar4 + 0x20c))(piVar9);
  }
  return (int)param_1;
}



void __cdecl
FUN_004167b0(int param_1,uint param_2,char param_3,undefined2 *param_4,undefined2 *param_5)

{
  FUN_00416800(param_1 + 0xd8,param_2,param_4,param_5);
  if ((param_3 != '\0') && (*(int *)(param_1 + 0x1dc) != 0)) {
    *param_5 = *(undefined2 *)(param_1 + 0xe2);
  }
  return;
}



void __cdecl FUN_00416800(int param_1,uint param_2,undefined2 *param_3,undefined2 *param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x22);
  if (param_2 < uVar2) {
    iVar1 = *(int *)(param_1 + 0x24);
    *param_3 = *(undefined2 *)(iVar1 + 2 + param_2 * 4);
    *param_4 = *(undefined2 *)(iVar1 + param_2 * 4);
    return;
  }
  *param_3 = *(undefined2 *)(*(int *)(param_1 + 0x28) + (param_2 - uVar2) * 2);
  *param_4 = *(undefined2 *)(*(int *)(param_1 + 0x24) + -4 + uVar2 * 4);
  return;
}



void __cdecl FUN_00416850(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  
  if ((param_3 != 0) && (uVar1 = 0, param_1 != 0)) {
    do {
      piVar2 = (int *)(param_2 + uVar1 * 8);
      *piVar2 = *piVar2 + param_3;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_1);
  }
  if ((param_4 != 0) && (param_1 != 0)) {
    piVar2 = (int *)(param_2 + 4);
    do {
      *piVar2 = *piVar2 + param_4;
      piVar2 = piVar2 + 2;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return;
}



undefined4 __cdecl FUN_00416890(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  iVar7 = *(int *)(param_1 + 0xc);
  iVar8 = (int)*(short *)(iVar7 + 0x36);
  piVar1 = (int *)(*(int *)(iVar7 + 0x38) + iVar8 * 8);
  *piVar1 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x34);
  piVar1[1] = 0;
  iVar3 = *(int *)(param_1 + 0x38);
  piVar1[3] = 0;
  piVar1[2] = iVar3 + *piVar1;
  *(undefined1 *)(*(int *)(iVar7 + 0x3c) + iVar8) = 0;
  *(undefined1 *)(*(int *)(iVar7 + 0x3c) + 1 + iVar8) = 0;
  uVar9 = iVar8 + 2;
  FUN_00416320(param_1 + 0x74,(short *)(iVar7 + 0x34),0,0);
  if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
    puVar10 = *(uint **)(param_1 + 0x84);
    uVar4 = *(uint *)(*(int *)(param_1 + 4) + 0x14);
    uVar6 = *(uint *)(*(int *)(param_1 + 4) + 0x10);
    puVar2 = puVar10 + uVar9 * 2;
    for (; puVar10 < puVar2; puVar10 = puVar10 + 2) {
      uVar5 = FUN_00410b80(*puVar10,uVar6);
      *puVar10 = uVar5;
      uVar5 = FUN_00410b80(puVar10[1],uVar4);
      puVar10[1] = uVar5;
    }
  }
  uVar4 = uVar9 * 8;
  puVar11 = *(undefined4 **)(param_1 + 0x84);
  puVar12 = *(undefined4 **)(param_1 + 0x80);
  for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x80) + -0x10 + uVar9 * 8);
    FUN_00416850(uVar9,*(int *)(param_1 + 0x80),(iVar7 + 0x20U & 0xffffffc0) - iVar7,0);
    puVar11 = *(undefined4 **)(param_1 + 0x80);
    puVar12 = *(undefined4 **)(param_1 + 0x84);
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    *(uint *)(*(int *)(param_1 + 0x84) + -8 + uVar4) =
         *(int *)(*(int *)(param_1 + 0x84) + -8 + uVar4) + 0x20U & 0xffffffc0;
  }
  if (*(char *)(param_1 + 0x41) == '\0') {
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(*(int *)(param_1 + 0x84) + -0x10 + uVar9 * 8);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(*(int *)(param_1 + 0x84) + -0xc + uVar9 * 8);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x84) + -8 + uVar4);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(*(int *)(param_1 + 0x84) + -4 + uVar4);
  }
  return 0;
}



void __cdecl FUN_004169e0(int *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  ushort uVar11;
  undefined4 *puVar12;
  uint local_1c;
  short local_18 [2];
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  piVar4 = param_1;
  uVar5 = param_1[4];
  iVar7 = *param_1;
  local_14 = param_1[1];
  iVar2 = param_1[2];
  param_1 = (int *)0x10000;
  if ((uVar5 & 1) == 0) {
    param_1 = *(int **)(local_14 + 0x14);
  }
  if (*(int *)(iVar2 + 0x48) == 0x636f6d70) {
    local_10 = piVar4[9];
    local_c = piVar4[10];
    local_8 = piVar4[0xb];
    local_4 = piVar4[0xc];
  }
  else {
    *(uint *)(iVar2 + 0x7c) = *(uint *)(iVar2 + 0x7c) & 0xfffffdff;
    FUN_004110f0((int *)**(undefined4 **)(iVar2 + 0x94),piVar4[3]);
    puVar10 = (undefined4 *)(**(int **)(iVar2 + 0x94) + 0x14);
    puVar12 = (undefined4 *)(iVar2 + 0x6c);
    for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    FUN_00412600(iVar2 + 0x6c,-piVar4[0x11],0);
    FUN_00412570(iVar2 + 0x6c,(int *)&local_10);
    uVar5 = piVar4[4];
    if ((uVar5 & 2) == 0) {
      local_c = local_c & 0xffffffc0;
      local_8 = local_8 + 0x3f & 0xffffffc0;
      local_10 = local_10 & 0xffffffc0;
      local_4 = local_4 + 0x3f & 0xffffffc0;
    }
  }
  uVar9 = piVar4[0xf];
  if ((*(int *)(iVar7 + 0x1dc) != 0) && ((uVar5 & 0x200) == 0)) {
    uVar9 = (uint)*(ushort *)(iVar7 + 0xe2);
  }
  *(uint *)(iVar2 + 0x38) = uVar9;
  *(uint *)(iVar2 + 0x20) = local_10;
  *(uint *)(iVar2 + 0x24) = local_4;
  iVar8 = piVar4[0x13];
  iVar3 = piVar4[0x11];
  *(int *)(iVar2 + 0x28) = iVar8 - iVar3;
  if ((*(byte *)(piVar4 + 4) & 2) == 0) {
    *(uint *)(iVar2 + 0x28) = (iVar8 - iVar3) + 0x20U & 0xffffffc0;
  }
  if ((*(char *)(iVar7 + 0x128) == '\0') || (*(short *)(iVar7 + 0x14e) == 0)) {
    if (*(short *)(iVar7 + 0x16c) == -1) {
      uVar1 = *(ushort *)(iVar7 + 0xe0);
      uVar11 = *(short *)(iVar7 + 0xde) + *(short *)(iVar7 + 0xdc);
    }
    else {
      uVar1 = *(ushort *)(iVar7 + 0x1b6);
      uVar11 = *(short *)(iVar7 + 0x1b2) - *(short *)(iVar7 + 0x1b4);
    }
    local_18[0] = (short)uVar1 / 2;
    local_1c = (uint)uVar11 + (uint)uVar1;
  }
  else {
    FUN_00416800(iVar7 + 300,param_2,local_18,(undefined2 *)&local_1c);
  }
  if ((*(byte *)(piVar4 + 4) & 1) == 0) {
    uVar5 = FUN_00410b80((int)local_18[0] + piVar4[0xc],(uint)param_1);
    uVar5 = uVar5 - local_4;
    uVar9 = FUN_00410b80(local_1c & 0xffff,(uint)param_1);
  }
  else {
    uVar9 = local_1c & 0xffff;
    uVar5 = (piVar4[0xc] + (int)local_18[0]) - local_4;
  }
  *(uint *)(iVar2 + 0x3c) = local_1c & 0xffff;
  uVar6 = (int)(local_10 - local_8) / 2;
  if ((*(byte *)(piVar4 + 4) & 2) == 0) {
    uVar6 = uVar6 & 0xffffffc0;
    uVar5 = uVar5 + 0x3f & 0xffffffc0;
    uVar9 = uVar9 + 0x20 & 0xffffffc0;
  }
  *(uint *)(iVar2 + 0x2c) = uVar6;
  *(uint *)(iVar2 + 0x30) = uVar5;
  *(uint *)(iVar2 + 0x34) = uVar9;
  if ((((*(int *)(iVar7 + 0x1dc) == 0) && (local_14 != 0)) && ((*(byte *)(piVar4 + 4) & 2) == 0)) &&
     (iVar7 = FUN_00416c70(iVar7,*(ushort *)(local_14 + 0xc)), iVar7 != 0)) {
    *(uint *)(iVar2 + 0x28) = (uint)*(byte *)(iVar7 + param_2) << 6;
  }
  *(uint *)(iVar2 + 0x18) = local_8 - local_10;
  *(uint *)(iVar2 + 0x1c) = local_4 - local_c;
  return;
}



undefined4 __cdecl FUN_00416c70(int param_1,ushort param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (0 < *(short *)(param_1 + 0x21a)) {
    uVar1 = 0;
    do {
      if (*(byte *)(*(int *)(param_1 + 0x21c) + uVar1 * 8) == param_2) {
        return *(undefined4 *)(*(int *)(param_1 + 0x21c) + 4 + (uint)uVar2 * 8);
      }
      uVar2 = uVar2 + 1;
      uVar1 = (uint)uVar2;
    } while ((int)uVar1 < (int)*(short *)(param_1 + 0x21a));
  }
  return 0;
}



int __cdecl
FUN_00416cc0(int *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  
  iVar2 = FUN_00411770(*(int *)(*(int *)(param_2 + 0x60) + 4),&DAT_0043ec08);
  if (iVar2 == 0) {
    return 2;
  }
  bVar1 = FUN_00411790((int)param_1,0);
  iVar3 = CONCAT31(extraout_var,bVar1);
  if ((iVar3 == 0) &&
     (iVar3 = (**(code **)(iVar2 + 4))(param_1,param_2,param_3,param_4,param_5), iVar3 == 0)) {
    if ((*(int *)(param_2 + 0x94) != 0x10000) && (*(int *)(param_2 + 0x94) != 0x74727565)) {
      return 2;
    }
    if (param_3 < 0) {
      return 0;
    }
    iVar3 = (**(code **)(iVar2 + 8))(param_1,param_2,param_3,param_4,param_5);
    if (iVar3 == 0) {
      if ((*(byte *)(param_2 + 8) & 1) != 0) {
        iVar2 = FUN_00416dc0(param_2,param_1);
        if (((iVar2 == 0) && (iVar2 = FUN_00416f00(param_2,param_1), iVar2 == 0)) &&
           (iVar2 = FUN_00416fb0(param_2,param_1), iVar2 == 0)) {
          FUN_00417060(param_2);
          return 0;
        }
        iVar3 = 1;
      }
      FUN_00417060(param_2);
    }
  }
  return iVar3;
}



int __cdecl FUN_00416dc0(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  short sVar4;
  int *piVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int *piVar11;
  
  piVar5 = param_2;
  sVar4 = *(short *)(param_1 + 0xd2);
  iVar8 = param_2[7];
  iVar7 = (**(code **)(param_1 + 0x1f8))(param_1,0x6c6f6361,param_2,&param_2);
  if (iVar7 != 0) {
    return 0x90;
  }
  puVar1 = (uint *)(param_1 + 0x284);
  if (sVar4 == 0) {
    *(short *)(param_1 + 0x280) = (short)((uint)param_2 >> 1);
    iVar8 = FUN_00410c90(iVar8,((uint)param_2 >> 1 & 0xffff) << 2,puVar1);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = FUN_00411900(piVar5,(uint)*(ushort *)(param_1 + 0x280) << 1);
    if (iVar8 != 0) {
      return iVar8;
    }
    piVar11 = (int *)*puVar1;
    piVar3 = piVar11 + *(ushort *)(param_1 + 0x280);
    for (; piVar11 < piVar3; piVar11 = piVar11 + 1) {
      uVar6 = FUN_004119f0((int)piVar5);
      *piVar11 = (uint)uVar6 << 1;
    }
  }
  else {
    *(short *)(param_1 + 0x280) = (short)((uint)param_2 >> 2);
    iVar8 = FUN_00410c90(iVar8,((uint)param_2 >> 2 & 0xffff) << 2,puVar1);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = FUN_00411900(piVar5,(uint)*(ushort *)(param_1 + 0x280) << 2);
    if (iVar8 != 0) {
      return iVar8;
    }
    puVar10 = (undefined4 *)*puVar1;
    puVar2 = puVar10 + *(ushort *)(param_1 + 0x280);
    if (puVar10 < puVar2) {
      do {
        uVar9 = FUN_00411a50((int)piVar5);
        *puVar10 = uVar9;
        puVar10 = puVar10 + 1;
      } while (puVar10 < puVar2);
      FUN_004119a0(piVar5);
      return 0;
    }
  }
  FUN_004119a0(piVar5);
  return 0;
}



int __cdecl FUN_00416f00(int param_1,int *param_2)

{
  undefined2 *puVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  
  piVar2 = param_2;
  iVar5 = param_2[7];
  iVar4 = (**(code **)(param_1 + 0x1f8))(param_1,0x63767420,param_2,&param_2);
  if (iVar4 != 0) {
    *(undefined4 *)(param_1 + 0x298) = 0;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    return 0;
  }
  *(uint *)(param_1 + 0x298) = (uint)param_2 >> 1;
  iVar5 = FUN_00410c90(iVar5,((uint)param_2 >> 1) * 2,(uint *)(param_1 + 0x29c));
  if ((iVar5 == 0) && (iVar5 = FUN_00411900(piVar2,*(int *)(param_1 + 0x298) << 1), iVar5 == 0)) {
    puVar6 = *(undefined2 **)(param_1 + 0x29c);
    puVar1 = puVar6 + *(int *)(param_1 + 0x298);
    for (; puVar6 < puVar1; puVar6 = puVar6 + 1) {
      uVar3 = FUN_004119f0((int)piVar2);
      *puVar6 = uVar3;
    }
    FUN_004119a0(piVar2);
  }
  return iVar5;
}



int __cdecl FUN_00416fb0(uint param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_2;
  uVar1 = param_1;
  iVar3 = (**(code **)(param_1 + 0x1f8))(param_1,0x6670676d,param_2,&param_1);
  if (iVar3 == 0) {
    *(uint *)(uVar1 + 0x288) = param_1;
    iVar3 = FUN_004118a0(piVar2,param_1,(int *)(uVar1 + 0x28c));
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    *(undefined4 *)(uVar1 + 0x28c) = 0;
    *(undefined4 *)(uVar1 + 0x288) = 0;
  }
  iVar3 = (**(code **)(uVar1 + 0x1f8))(uVar1,0x70726570,piVar2,&param_1);
  if (iVar3 == 0) {
    *(uint *)(uVar1 + 0x290) = param_1;
    iVar3 = FUN_004118a0(piVar2,param_1,(int *)(uVar1 + 0x294));
    return iVar3;
  }
  *(undefined4 *)(uVar1 + 0x294) = 0;
  *(undefined4 *)(uVar1 + 0x290) = 0;
  return 0;
}



void __cdecl FUN_00417060(int param_1)

{
  *(undefined **)(param_1 + 0x1fc) = &DAT_004170a0;
  *(undefined1 **)(param_1 + 0x200) = &LAB_004170e0;
  *(undefined1 **)(param_1 + 0x204) = &LAB_00417150;
  *(undefined1 **)(param_1 + 0x208) = &LAB_00417450;
  *(undefined1 **)(param_1 + 0x20c) = &LAB_004170d0;
  return;
}



void __cdecl FUN_00417620(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x68);
  iVar2 = *(int *)(param_1 + 0x210);
  iVar3 = *(int *)(param_1 + 100);
  if (*(code **)(param_1 + 0x2b4) != (code *)0x0) {
    (**(code **)(param_1 + 0x2b4))(*(undefined4 *)(param_1 + 0x2b0));
  }
  if (iVar2 != 0) {
    (**(code **)(iVar2 + 0xc))(param_1);
  }
  FUN_00410d70(iVar3,(int *)(param_1 + 0x284));
  *(undefined2 *)(param_1 + 0x280) = 0;
  FUN_00410d70(iVar3,(int *)(param_1 + 0x29c));
  *(undefined4 *)(param_1 + 0x298) = 0;
  FUN_004118d0(iVar1,(int *)(param_1 + 0x28c));
  FUN_004118d0(iVar1,(int *)(param_1 + 0x294));
  *(undefined4 *)(param_1 + 0x288) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  return;
}



uint __cdecl FUN_004176d0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = *param_1;
  if ((((*(byte *)(iVar1 + 8) & 1) == 0) || ((char)param_1[0x14] != '\0')) ||
     (uVar2 = FUN_00417740(param_1), uVar2 == 0)) {
    uVar2 = 0;
    if ((*(byte *)(iVar1 + 8) & 2) != 0) {
      if (param_1[0x15] == 0xffff) {
        uVar2 = FUN_00417850(param_1);
      }
      if ((uVar2 == 0) && ((*(byte *)(iVar1 + 8) & 1) == 0)) {
        piVar4 = param_1 + 0x16;
        piVar5 = param_1 + 3;
        for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
      }
    }
    uVar2 = uVar2 & ~-(uint)((*(byte *)(iVar1 + 8) & 1) != 0);
  }
  return uVar2;
}



undefined4 __cdecl FUN_00417740(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((char)param_1[0x14] != '\0') {
    return 0;
  }
  iVar1 = *param_1;
  if ((*(ushort *)(param_1 + 3) != 0) && (*(ushort *)((int)param_1 + 0xe) != 0)) {
    if (*(ushort *)(param_1 + 3) < *(ushort *)((int)param_1 + 0xe)) {
      param_1[0xf] = param_1[5];
      *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_1 + 0xe);
      uVar2 = FUN_00410a10((uint)*(ushort *)(param_1 + 3),0x10000,
                           (uint)*(ushort *)((int)param_1 + 0xe));
      param_1[0xb] = uVar2;
      param_1[0xc] = 0x10000;
    }
    else {
      param_1[0xf] = param_1[4];
      *(short *)(param_1 + 0xd) = (short)param_1[3];
      param_1[0xb] = 0x10000;
      uVar2 = FUN_00410a10((uint)*(ushort *)((int)param_1 + 0xe),0x10000,
                           (uint)*(ushort *)(param_1 + 3));
      param_1[0xc] = uVar2;
    }
    uVar2 = FUN_00410b80((int)*(short *)(iVar1 + 0x46),param_1[5]);
    param_1[6] = uVar2 + 0x20 & 0xffffffc0;
    uVar2 = FUN_00410b80((int)*(short *)(iVar1 + 0x48),param_1[5]);
    param_1[7] = uVar2 + 0x20 & 0xffffffc0;
    uVar2 = FUN_00410b80((int)*(short *)(iVar1 + 0x4a),param_1[5]);
    param_1[8] = uVar2 + 0x20 & 0xffffffc0;
    uVar2 = FUN_00410b80((int)*(short *)(iVar1 + 0x4c),param_1[4]);
    param_1[9] = uVar2 + 0x20 & 0xffffffc0;
    param_1[0x15] = 0xffff;
    *(undefined1 *)(param_1 + 0x14) = 1;
    return 0;
  }
  return 0x97;
}



int __cdecl FUN_00417850(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = param_1;
  if (param_1[0x15] != 0xffff) {
    return 0;
  }
  iVar4 = *param_1;
  iVar3 = (**(code **)(*(int *)(iVar4 + 0x210) + 0x58))
                    (iVar4,(short)param_1[3],*(undefined2 *)((int)param_1 + 0xe),&param_1);
  if (iVar3 == 0) {
    iVar4 = (int)param_1 * 0x30 + *(int *)(iVar4 + 0x264);
    *(short *)(piVar2 + 0x16) = (short)piVar2[3];
    *(undefined2 *)((int)piVar2 + 0x5a) = *(undefined2 *)((int)piVar2 + 0xe);
    piVar2[0x19] = (int)*(char *)(iVar4 + 0x10) << 6;
    cVar1 = *(char *)(iVar4 + 0x11);
    piVar2[0x1a] = cVar1 * 0x40;
    piVar2[0x1b] = piVar2[0x19] + cVar1 * -0x40;
    piVar2[0x1c] = ((int)*(char *)(iVar4 + 0x17) + (int)*(char *)(iVar4 + 0x16) +
                   (uint)*(byte *)(iVar4 + 0x12)) * 0x40;
    piVar2[0x15] = (int)param_1;
    return 0;
  }
  piVar2[0x15] = 0xffff;
  *(undefined2 *)(piVar2 + 0x16) = 0;
  *(undefined2 *)((int)piVar2 + 0x5a) = 0;
  piVar2[0x19] = 0;
  piVar2[0x1a] = 0;
  piVar2[0x1b] = 0;
  piVar2[0x1c] = 0;
  return iVar3;
}



undefined4 __cdecl FUN_00417920(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00417960(param_2);
  iVar1 = param_1[1];
  iVar2 = *param_1;
  FUN_004179c0(param_2,(iVar2 << 2) >> 8,(iVar1 << 2) >> 8);
  param_2[0xf] = iVar1 << 2;
  param_2[0xe] = iVar2 << 2;
  return 0;
}



void __cdecl FUN_00417960(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[9] == 0) && (param_1[7] != 0 || param_1[8] != 0)) {
    iVar1 = param_1[2];
    if (param_1[1] <= iVar1) {
                    // WARNING: Subroutine does not return
      longjmp(param_1 + 0x13b,1);
    }
    piVar2 = (int *)(iVar1 * 0x10 + *param_1);
    param_1[2] = iVar1 + 1;
    *piVar2 = param_1[10] - param_1[3];
    piVar2[1] = param_1[0xb] - param_1[5];
    piVar2[3] = param_1[7];
    piVar2[2] = param_1[8];
  }
  return;
}



void FUN_004179c0(int *param_1,int param_2,int param_3)

{
  if (param_2 < param_1[3]) {
    param_2 = param_1[3] + -1;
  }
  param_1[0x10] = param_3 << 8;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = param_2;
  param_1[0xb] = param_3;
  param_1[9] = 0;
  FUN_00417a10(param_1,param_2,param_3);
  return;
}



void __cdecl FUN_00417a10(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int local_4;
  
  bVar1 = false;
  local_4 = 1;
  if (((param_3 < param_1[5]) || (param_1[6] <= param_3)) || (param_1[4] <= param_2)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
    if (param_2 < param_1[3]) {
      param_2 = param_1[3] + -1;
    }
    if ((param_2 == param_1[10]) && (param_3 == param_1[0xb])) {
      local_4 = param_1[9];
    }
    else {
      bVar1 = true;
    }
  }
  if ((param_1[9] != iVar2) || (bVar1)) {
    FUN_00417960(param_1);
  }
  if (local_4 != 0) {
    param_1[7] = 0;
    param_1[8] = 0;
  }
  param_1[10] = param_2;
  param_1[9] = iVar2;
  param_1[0xb] = param_3;
  return;
}



void __cdecl FUN_00417ad0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_24;
  int local_20;
  int *local_18;
  int local_10;
  
  piVar1 = param_1;
  piVar5 = (int *)(param_3 >> 8);
  iVar4 = param_1[0xf] - param_1[0x10];
  iVar3 = param_1[0xe];
  piVar6 = (int *)(param_1[0x10] >> 8);
  iVar7 = param_3 - param_1[0xf];
  param_1 = piVar6;
  local_18 = piVar5;
  if ((int)piVar5 < (int)piVar6) {
    param_1 = piVar5;
    local_18 = piVar6;
  }
  if (((int)param_1 < piVar1[6]) && (piVar1[5] <= (int)local_18)) {
    if (piVar6 == piVar5) {
      local_24 = piVar1[0xe];
    }
    else {
      local_20 = 0x100;
      local_18 = (int *)0x1;
      iVar2 = 0x100 - iVar4;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
        local_20 = 0;
        local_18 = (int *)0xffffffff;
        iVar2 = iVar4;
      }
      iVar2 = iVar2 * (param_2 - iVar3);
      local_24 = iVar2 / iVar7;
      param_1 = (int *)(iVar2 % iVar7);
      if ((int)param_1 < 0) {
        local_24 = local_24 + -1;
        param_1 = (int *)((int)param_1 + iVar7);
      }
      local_24 = local_24 + piVar1[0xe];
      FUN_00417cc0(piVar1,(int)piVar6,piVar1[0xe],iVar4,local_24,local_20);
      piVar6 = (int *)((int)piVar6 + (int)local_18);
      FUN_00417a10(piVar1,local_24 >> 8,(int)piVar6);
      if (piVar6 != piVar5) {
        local_10 = (param_2 - iVar3) * 0x100;
        iVar3 = local_10 / iVar7;
        local_10 = local_10 % iVar7;
        if (local_10 < 0) {
          iVar3 = iVar3 + -1;
          local_10 = local_10 + iVar7;
        }
        param_1 = (int *)((int)param_1 - iVar7);
        do {
          param_1 = (int *)((int)param_1 + local_10);
          iVar4 = iVar3;
          if (-1 < (int)param_1) {
            param_1 = (int *)((int)param_1 - iVar7);
            iVar4 = iVar3 + 1;
          }
          iVar4 = local_24 + iVar4;
          FUN_00417cc0(piVar1,(int)piVar6,local_24,0x100 - local_20,iVar4,local_20);
          piVar6 = (int *)((int)piVar6 + (int)local_18);
          FUN_00417a10(piVar1,iVar4 >> 8,(int)piVar6);
          local_24 = iVar4;
        } while (piVar6 != piVar5);
      }
      iVar4 = 0x100 - local_20;
    }
    FUN_00417cc0(piVar1,(int)piVar6,local_24,iVar4,param_2,param_3 + (int)piVar5 * -0x100);
  }
  piVar1[0xe] = param_2;
  piVar1[0xf] = param_3;
  piVar1[0x10] = (int)piVar5 * 0x100;
  return;
}



void __cdecl FUN_00417cc0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = param_4;
  piVar2 = param_1;
  iVar11 = param_3 >> 8;
  iVar9 = param_5 - param_3;
  iVar6 = param_3 + iVar11 * -0x100;
  iVar8 = param_5 >> 8;
  iVar3 = param_5 + iVar8 * -0x100;
  if (param_4 == param_6) {
    FUN_00417a10(param_1,iVar8,param_2);
    return;
  }
  iVar7 = param_6 - param_4;
  if (iVar11 != iVar8) {
    param_4 = 0x100;
    param_3 = 1;
    iVar1 = 0x100 - iVar6;
    if (iVar9 < 0) {
      param_4 = 0;
      param_3 = -1;
      iVar9 = -iVar9;
      iVar1 = iVar6;
    }
    iVar4 = (iVar1 * iVar7) / iVar9;
    param_5 = (iVar1 * iVar7) % iVar9;
    if (param_5 < 0) {
      iVar4 = iVar4 + -1;
      param_5 = param_5 + iVar9;
    }
    param_1[7] = param_1[7] + (param_4 + iVar6) * iVar4;
    param_1[8] = param_1[8] + iVar4;
    iVar11 = iVar11 + param_3;
    FUN_00417a10(param_1,iVar11,param_2);
    iVar10 = iVar10 + iVar4;
    if (iVar11 != iVar8) {
      iVar6 = (param_6 - iVar10) * 0x100;
      param_1 = (int *)(iVar6 / iVar9);
      iVar6 = iVar6 % iVar9;
      if (iVar6 < 0) {
        param_1 = (int *)((int)param_1 + -1);
        iVar6 = iVar6 + iVar9;
      }
      param_5 = param_5 - iVar9;
      do {
        param_5 = param_5 + iVar6;
        piVar5 = param_1;
        if (-1 < param_5) {
          param_5 = param_5 - iVar9;
          piVar5 = (int *)((int)param_1 + 1);
        }
        piVar2[7] = piVar2[7] + (int)piVar5 * 0x100;
        piVar2[8] = piVar2[8] + (int)piVar5;
        iVar11 = iVar11 + param_3;
        iVar10 = iVar10 + (int)piVar5;
        FUN_00417a10(piVar2,iVar11,param_2);
      } while (iVar11 != iVar8);
    }
    piVar2[7] = piVar2[7] + ((iVar3 - param_4) + 0x100) * (param_6 - iVar10);
    piVar2[8] = piVar2[8] + (param_6 - iVar10);
    return;
  }
  param_1[7] = param_1[7] + (iVar3 + iVar6) * iVar7;
  param_1[8] = param_1[8] + iVar7;
  return;
}



void __cdecl FUN_00417eb0(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  piVar1 = param_1;
  iVar2 = (param_1[0xe] >> 2) + *param_2 * -2 + *param_3;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar3 = (param_1[0xf] >> 2) + param_2[1] * -2 + param_3[1];
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar2 < iVar3) {
    iVar2 = iVar3;
  }
  iVar2 = iVar2 / param_1[0x138];
  iVar3 = 1;
  if (0 < iVar2) {
    do {
      iVar2 = iVar2 >> 2;
      iVar3 = iVar3 + 1;
    } while (0 < iVar2);
    if (1 < iVar3) {
      param_1[0xd3] = iVar3;
      piVar7 = param_1 + 0x11;
      *piVar7 = *param_3 << 2;
      param_1[0x12] = param_3[1] << 2;
      param_1[0x13] = *param_2 << 2;
      param_1[0x14] = param_2[1] << 2;
      param_1[0x15] = param_1[0xe];
      piVar5 = param_1 + 0xf;
      param_1 = (int *)0x0;
      piVar1[0x16] = *piVar5;
      do {
        iVar2 = piVar1[(int)param_1 + 0xd3];
        if (iVar2 < 2) {
LAB_00418008:
          iVar2 = piVar7[1];
          iVar3 = *piVar7;
          iVar4 = piVar1[0xf] + piVar7[3] * 2 + iVar2;
          iVar6 = iVar3 + piVar7[2] * 2 + piVar1[0xe];
          FUN_00417ad0(piVar1,(int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2,
                       (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2);
          FUN_00417ad0(piVar1,iVar3,iVar2);
          piVar5 = (int *)((int)param_1 + -1);
          piVar7 = piVar7 + -4;
        }
        else {
          iVar3 = piVar7[1];
          iVar4 = piVar7[3];
          iVar6 = iVar3;
          if (iVar4 < iVar3) {
            iVar6 = iVar4;
          }
          if (iVar3 < iVar4) {
            iVar3 = iVar4;
          }
          iVar4 = piVar7[5];
          if (iVar4 < iVar6) {
            iVar6 = iVar4;
          }
          if (iVar3 < iVar4) {
            iVar3 = iVar4;
          }
          if ((piVar1[6] <= iVar6 >> 8) || (iVar3 < 0)) goto LAB_00418008;
          FUN_0041edb0(piVar7);
          piVar7 = piVar7 + 4;
          piVar5 = (int *)((int)param_1 + 1);
          iVar2 = iVar2 + -1;
          piVar1[(int)param_1 + 0xd3] = iVar2;
          piVar1[(int)(param_1 + 0x35)] = iVar2;
        }
        param_1 = piVar5;
        if ((int)piVar5 < 0) {
          return;
        }
      } while( true );
    }
  }
  iVar4 = param_3[1] * 4;
  iVar2 = param_1[0xf] + param_2[1] * 8 + iVar4;
  iVar6 = *param_3 * 4;
  iVar3 = param_1[0xe] + *param_2 * 8 + iVar6;
  FUN_00417ad0(param_1,(int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2,
               (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
  FUN_00417ad0(param_1,iVar6,iVar4);
  return;
}



void __cdecl FUN_00418090(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  iVar1 = *param_4;
  iVar3 = *param_2;
  iVar2 = iVar1 + iVar3 * -2 + (param_1[0xe] >> 2);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar4 = param_4[1];
  iVar5 = iVar4 + param_2[1] * -2 + (param_1[0xf] >> 2);
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  if (iVar2 < iVar5) {
    iVar2 = iVar5;
  }
  iVar5 = iVar1 + (iVar3 + *param_3) * -3 + (param_1[0xe] >> 2);
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  iVar6 = iVar4 + (iVar3 + param_3[1]) * -3 + (param_1[0xf] >> 2);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if (iVar5 < iVar6) {
    iVar5 = iVar6;
  }
  iVar2 = iVar2 / param_1[0x139];
  iVar6 = 1;
  for (iVar5 = iVar5 / param_1[0x138]; (0 < iVar2 || (0 < iVar5)); iVar5 = iVar5 >> 3) {
    iVar2 = iVar2 >> 2;
    iVar6 = iVar6 + 1;
  }
  if (iVar6 < 2) {
    iVar2 = param_1[0xf] + (param_3[1] + param_2[1]) * 0xc + iVar4 * 4;
    iVar3 = param_1[0xe] + (iVar3 + *param_3) * 0xc + iVar1 * 4;
    FUN_00417ad0(param_1,(int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3,
                 (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
    FUN_00417ad0(param_1,iVar1 * 4,iVar4 * 4);
    return;
  }
  piVar8 = param_1 + 0x11;
  *piVar8 = iVar1 * 4;
  param_1[0x12] = param_4[1] << 2;
  param_1[0x13] = *param_3 << 2;
  param_1[0x14] = param_3[1] << 2;
  param_1[0x15] = *param_2 << 2;
  param_1[0x16] = param_2[1] << 2;
  param_1[0x17] = param_1[0xe];
  param_1[0x18] = param_1[0xf];
  param_3 = (int *)0x0;
  param_1[0xd3] = iVar6;
  do {
    iVar1 = param_1[(int)param_3 + 0xd3];
    if (iVar1 < 2) {
LAB_00418291:
      iVar1 = piVar8[1];
      iVar3 = *piVar8;
      iVar2 = (piVar8[5] + piVar8[3]) * 3 + param_1[0xf] + iVar1;
      iVar4 = iVar3 + (piVar8[4] + piVar8[2]) * 3 + param_1[0xe];
      FUN_00417ad0(param_1,(int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3,
                   (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
      FUN_00417ad0(param_1,iVar3,iVar1);
      piVar7 = (int *)((int)param_3 + -1);
      piVar8 = piVar8 + -6;
    }
    else {
      iVar3 = piVar8[1];
      iVar2 = piVar8[3];
      iVar4 = iVar3;
      if (iVar2 < iVar3) {
        iVar4 = iVar2;
      }
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
      iVar2 = piVar8[5];
      if (iVar2 < iVar4) {
        iVar4 = iVar2;
      }
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
      iVar2 = piVar8[7];
      if (iVar2 < iVar4) {
        iVar4 = iVar2;
      }
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
      if ((param_1[6] <= iVar4 >> 8) || (iVar3 < 0)) goto LAB_00418291;
      FUN_00418300(piVar8);
      piVar8 = piVar8 + 6;
      piVar7 = (int *)((int)param_3 + 1);
      iVar1 = iVar1 + -1;
      param_1[(int)param_3 + 0xd3] = iVar1;
      param_1[(int)(param_3 + 0x35)] = iVar1;
    }
    param_3 = piVar7;
    if ((int)piVar7 < 0) {
      return;
    }
  } while( true );
}



void __cdecl FUN_00418300(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1[0xc] = param_1[6];
  iVar3 = (*param_1 + param_1[2]) / 2;
  iVar2 = (param_1[2] + param_1[4]) / 2;
  param_1[2] = iVar3;
  iVar4 = (param_1[6] + param_1[4]) / 2;
  iVar1 = (iVar4 + iVar2) / 2;
  param_1[8] = iVar1;
  iVar2 = (iVar3 + iVar2) / 2;
  param_1[6] = (iVar1 + iVar2) / 2;
  param_1[10] = iVar4;
  param_1[4] = iVar2;
  param_1[0xd] = param_1[7];
  iVar3 = (param_1[1] + param_1[3]) / 2;
  iVar2 = (param_1[3] + param_1[5]) / 2;
  iVar4 = (param_1[7] + param_1[5]) / 2;
  param_1[3] = iVar3;
  iVar1 = (iVar4 + iVar2) / 2;
  iVar2 = (iVar3 + iVar2) / 2;
  param_1[9] = iVar1;
  param_1[0xb] = iVar4;
  param_1[5] = iVar2;
  param_1[7] = (iVar1 + iVar2) / 2;
  return;
}



int __cdecl FUN_00418f30(int *param_1)

{
  int iVar1;
  
  iVar1 = setjmp3(param_1 + 0x13b,0);
  if (iVar1 == 0) {
    iVar1 = FUN_00411f80((short *)(param_1 + 0xf3),&PTR_FUN_004310a4,param_1);
    FUN_00417960(param_1);
    return iVar1;
  }
  return -4;
}



int * __cdecl FUN_004192f0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x9c);
  piVar2 = piVar1 + (uint)*(ushort *)(param_1 + 0x98) * 4;
  while( true ) {
    if (piVar2 <= piVar1) {
      return (int *)0x0;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 4;
  }
  return piVar1;
}



void __cdecl FUN_00419690(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x1f8))(param_1,param_3,param_2,0);
  if (iVar1 == 0) {
    FUN_00411d20(param_2,&DAT_00431110,param_1 + 0xa0);
  }
  return;
}



int __cdecl FUN_00419b10(int *param_1,int *param_2,char param_3)

{
  ushort uVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  uint local_c;
  uint *puStack_8;
  int local_4;
  
  piVar2 = param_1;
  local_4 = param_2[7];
  if (param_3 == '\0') {
    iVar4 = (*(code *)param_1[0x7e])(param_1,0x686d7478,param_2,&local_c);
    if (iVar4 != 0) {
      return 0x93;
    }
    uVar1 = *(ushort *)((int)param_1 + 0xfa);
    puStack_8 = (uint *)(param_1 + 0x3f);
    param_1 = param_1 + 0x40;
  }
  else {
    iVar4 = (*(code *)param_1[0x7e])(param_1,0x766d7478,param_2,&local_c);
    if (iVar4 != 0) {
      *(undefined2 *)((int)param_1 + 0x14e) = 0;
      return 0;
    }
    uVar1 = *(ushort *)((int)param_1 + 0x14e);
    puStack_8 = (uint *)(param_1 + 0x54);
    param_1 = param_1 + 0x55;
  }
  iVar4 = local_4;
  uVar5 = (uint)uVar1;
  uVar9 = *(ushort *)(piVar2 + 0x42) - uVar5;
  uVar8 = local_c + uVar5 * -4 >> 1;
  if ((int)uVar9 < 0) {
    return (-(uint)(param_3 != '\0') & 3) + 0x95;
  }
  iVar6 = FUN_00410c90(local_4,uVar5 * 4,puStack_8);
  if (iVar6 == 0) {
    iVar6 = FUN_00410c90(iVar4,uVar9 * 2,param_1);
    if ((iVar6 == 0) && (local_4 = FUN_00411900(param_2,local_c), iVar6 = local_4, local_4 == 0)) {
      puVar10 = (undefined2 *)*puStack_8;
      puVar11 = puVar10 + uVar5 * 2;
      for (; puVar10 < puVar11; puVar10 = puVar10 + 2) {
        uVar3 = FUN_004119f0((int)param_2);
        *puVar10 = uVar3;
        uVar3 = FUN_004119f0((int)param_2);
        puVar10[1] = uVar3;
      }
      puVar12 = (undefined4 *)*param_1;
      uVar5 = uVar9;
      if ((int)uVar8 <= (int)uVar9) {
        uVar5 = uVar8;
      }
      puVar7 = (undefined4 *)((int)puVar12 + uVar5 * 2);
      for (; puVar12 < puVar7; puVar12 = (undefined4 *)((int)puVar12 + 2)) {
        uVar3 = FUN_004119f0((int)param_2);
        *(undefined2 *)puVar12 = uVar3;
      }
      if (((int)uVar8 < (int)uVar9) && (uVar8 != 0)) {
        uVar3 = *(undefined2 *)(*param_1 + -2 + uVar8 * 2);
        puVar7 = (undefined4 *)(*param_1 + uVar9 * 2);
        if (puVar12 < puVar7) {
          uVar5 = ((uint)((int)puVar7 + (-1 - (int)puVar12)) >> 1) + 1;
          for (uVar8 = uVar5 >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar12 = CONCAT22(uVar3,uVar3);
            puVar12 = puVar12 + 1;
          }
          for (uVar5 = (uint)((uVar5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined2 *)puVar12 = uVar3;
            puVar12 = (undefined4 *)((int)puVar12 + 2);
          }
        }
      }
      FUN_004119a0(param_2);
      iVar6 = local_4;
    }
  }
  return iVar6;
}



void __cdecl FUN_00419f30(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 8);
  FUN_00410d70(iVar1,(int *)(param_1 + 0x164));
  FUN_00410d70(iVar1,(int *)(param_1 + 0x168));
  *(undefined2 *)(param_1 + 0x15e) = 0;
  *(undefined2 *)(param_1 + 0x15c) = 0;
  *(undefined2 *)(param_1 + 0x160) = 0;
  return;
}



int __cdecl FUN_0041a680(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x1f8))(param_1,0x706f7374,param_2,0);
  if (iVar1 != 0) {
    return 0x94;
  }
  iVar1 = FUN_00411d20(param_2,&DAT_00431164,param_1 + 0x1d0);
  return iVar1;
}



uint __cdecl FUN_0041aa00(undefined2 *param_1,undefined2 *param_2)

{
  if (CONCAT22(*param_1,param_1[1]) < CONCAT22(*param_2,param_2[1])) {
    return 0xffffffff;
  }
  return (uint)(CONCAT22(*param_2,param_2[1]) < CONCAT22(*param_1,param_1[1]));
}



void __cdecl FUN_0041abc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 8);
    iVar2 = 0;
    if (0 < *(short *)(param_1 + 0x21a)) {
      do {
        FUN_00410d70(iVar1,(int *)(*(int *)(param_1 + 0x21c) + 4 + iVar2 * 8));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(short *)(param_1 + 0x21a));
    }
    FUN_00410d70(iVar1,(int *)(param_1 + 0x21c));
    *(undefined2 *)(param_1 + 0x21a) = 0;
  }
  return;
}



undefined4 __cdecl FUN_0041b400(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 8);
    switch(*(undefined2 *)(param_2 + 4)) {
    case 0:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x18));
      *(undefined1 *)(param_2 + 0xc) = 0;
      return 0;
    case 2:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x18));
      FUN_00410d70(iVar1,(int *)(param_2 + 0x1c));
      FUN_00410d70(iVar1,(int *)(param_2 + 0x20));
      *(undefined1 *)(param_2 + 0xc) = 0;
      return 0;
    case 4:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x20));
      FUN_00410d70(iVar1,(int *)(param_2 + 0x24));
      *(undefined2 *)(param_2 + 0x18) = 0;
      *(undefined1 *)(param_2 + 0xc) = 0;
      return 0;
    case 6:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x1c));
      *(undefined2 *)(param_2 + 0x1a) = 0;
      *(undefined1 *)(param_2 + 0xc) = 0;
      return 0;
    case 8:
    case 0xc:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x1c));
      *(undefined4 *)(param_2 + 0x18) = 0;
      *(undefined1 *)(param_2 + 0xc) = 0;
      return 0;
    case 10:
      FUN_00410d70(iVar1,(int *)(param_2 + 0x20));
      *(undefined4 *)(param_2 + 0x1c) = 0;
    }
    *(undefined1 *)(param_2 + 0xc) = 0;
  }
  return 0;
}



uint __cdecl FUN_0041b5c0(int param_1,uint param_2)

{
  ushort *puVar1;
  short sVar2;
  ushort *puVar3;
  uint uVar4;
  
  puVar3 = *(ushort **)(param_1 + 0x2c);
  uVar4 = (uint)(*(ushort *)(param_1 + 0x18) >> 1);
  if ((uint)*puVar3 - (uint)puVar3[1] <= param_2 - puVar3[1]) {
    puVar3 = *(ushort **)(param_1 + 0x20);
    puVar1 = puVar3 + uVar4 * 4;
    while( true ) {
      if (puVar1 <= puVar3) {
        return 0;
      }
      if ((param_2 <= *puVar3) && (puVar3[1] <= param_2)) break;
      puVar3 = puVar3 + 4;
    }
    *(ushort **)(param_1 + 0x2c) = puVar3;
  }
  if (puVar3[3] != 0) {
    uVar4 = (((((int)puVar3 - *(int *)(param_1 + 0x20) >> 3) - (uint)puVar3[1]) +
             (uint)(puVar3[3] >> 1)) - uVar4) + param_2;
    if ((uVar4 < *(ushort *)(param_1 + 0x28)) &&
       (sVar2 = *(short *)(*(int *)(param_1 + 0x24) + uVar4 * 2), sVar2 != 0)) {
      return (uint)(ushort)(puVar3[2] + sVar2);
    }
    return 0;
  }
  return (int)(short)puVar3[2] + param_2 & 0xffff;
}



undefined4 * __cdecl FUN_0041bbf0(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  psVar6 = *(short **)(param_1 + 0x164);
  uVar4 = 0;
  if (*(ushort *)(param_1 + 0x15e) != 0) {
    do {
      if (psVar6[3] == (short)param_2) {
        sVar1 = *psVar6;
        if ((((sVar1 == 3) && ((ushort)psVar6[1] < 2)) && ((psVar6[2] & 0x3ffU) == 9)) ||
           (sVar1 == 0)) {
          uVar3 = (uint)((ushort)psVar6[4] >> 1);
          iVar2 = FUN_00410c90(*(int *)(param_1 + 100),uVar3 + 1,&param_2);
          if (iVar2 != 0) {
            return (undefined4 *)0x0;
          }
          uVar5 = 0;
          if (uVar3 != 0) {
            uVar5 = 0;
            do {
              *(undefined1 *)(uVar5 + (int)param_2) =
                   *(undefined1 *)(*(int *)(psVar6 + 6) + 1 + uVar5 * 2);
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar3);
            *(undefined1 *)((int)param_2 + uVar3) = 0;
            return param_2;
          }
          goto LAB_0041bcd5;
        }
        if ((sVar1 == 1) && (psVar6[2] == 0)) {
          uVar4 = psVar6[4];
          uVar5 = (uint)uVar4;
          iVar2 = FUN_00410c90(*(int *)(param_1 + 100),uVar5 + 1,&param_2);
          if (iVar2 != 0) {
            return (undefined4 *)0x0;
          }
          puVar7 = *(undefined4 **)(psVar6 + 6);
          puVar8 = param_2;
          for (uVar3 = (uint)(uVar4 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
LAB_0041bcd5:
          *(undefined1 *)((int)param_2 + uVar5) = 0;
          return param_2;
        }
      }
      uVar4 = uVar4 + 1;
      psVar6 = psVar6 + 8;
    } while (uVar4 < *(ushort *)(param_1 + 0x15e));
  }
  return (undefined4 *)0x0;
}



int __cdecl FUN_0041bcf0(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = &DAT_004311d0;
  while ((*piVar1 != param_1 || ((piVar1[1] != param_2 && (piVar1[1] != -1))))) {
    piVar1 = piVar1 + 3;
    if (&UNK_00431253 < piVar1) {
      return 0;
    }
  }
  return piVar1[2];
}



void __cdecl FUN_0041bd30(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x210);
  uVar4 = 0;
  iVar2 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    if (*(code **)(iVar1 + 0x6c) != (code *)0x0) {
      (**(code **)(iVar1 + 0x6c))(param_1);
    }
    if (*(code **)(iVar1 + 100) != (code *)0x0) {
      (**(code **)(iVar1 + 100))(param_1);
    }
  }
  FUN_00410d70(iVar2,(int *)(param_1 + 0x2a8));
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  FUN_00410d70(iVar2,(int *)(param_1 + 0x90));
  *(undefined4 *)(param_1 + 0x8c) = 0;
  FUN_00410d70(iVar2,(int *)(param_1 + 0x9c));
  *(undefined2 *)(param_1 + 0x98) = 0;
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x28) != 0)) && (0 < *(int *)(param_1 + 0x1f0))) {
    uVar3 = 0;
    do {
      (**(code **)(iVar1 + 0x74))(param_1,uVar3 * 0x40 + 0xc + *(int *)(param_1 + 500));
      uVar4 = uVar4 + 1;
      uVar3 = uVar4 & 0xffff;
    } while ((int)uVar3 < *(int *)(param_1 + 0x1f0));
  }
  FUN_00410d70(iVar2,(int *)(param_1 + 500));
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  FUN_00410d70(iVar2,(int *)(param_1 + 0x28));
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  FUN_00410d70(iVar2,(int *)(param_1 + 0xfc));
  FUN_00410d70(iVar2,(int *)(param_1 + 0x100));
  if (*(char *)(param_1 + 0x128) != '\0') {
    FUN_00410d70(iVar2,(int *)(param_1 + 0x150));
    FUN_00410d70(iVar2,(int *)(param_1 + 0x154));
    *(undefined1 *)(param_1 + 0x128) = 0;
  }
  FUN_00410d70(iVar2,(int *)(param_1 + 0x224));
  *(undefined2 *)(param_1 + 0x222) = 0;
  (**(code **)(iVar1 + 0x3c))(param_1);
  (**(code **)(iVar1 + 0x44))(param_1);
  FUN_00410d70(iVar2,(int *)(param_1 + 0x14));
  FUN_00410d70(iVar2,(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00410d70(iVar2,(int *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x210) = 0;
  return;
}



int * __cdecl FUN_0041c590(ushort *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = param_2[7];
  uVar1 = param_1[2];
  switch(uVar1) {
  case 1:
  case 3:
    *(uint *)(param_1 + 0xc) = ((uint)param_1[1] - (uint)*param_1) + 1;
    uVar7 = ((uint)param_1[1] - (uint)*param_1) + 2;
    piVar5 = (int *)FUN_00410c90(iVar2,uVar7 * 4,(undefined4 *)(param_1 + 0xe));
    if ((piVar5 == (int *)0x0) &&
       (piVar5 = (int *)FUN_00411900(param_2,((uint)(uVar1 == 1) * 2 + 2) * uVar7),
       piVar5 == (int *)0x0)) {
      uVar6 = 0;
      if (uVar7 != 0) {
        do {
          if (uVar1 == 1) {
            uVar4 = FUN_00411a50((int)param_2);
          }
          else {
            uVar3 = FUN_004119f0((int)param_2);
            uVar4 = (uint)uVar3;
          }
          *(uint *)(*(int *)(param_1 + 0xe) + uVar6 * 4) = *(int *)(param_1 + 4) + uVar4;
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar7);
      }
      FUN_004119a0(param_2);
      return (int *)0x0;
    }
    break;
  case 2:
    piVar5 = FUN_0041c6d0((int)param_1,param_2);
    return piVar5;
  case 4:
    piVar5 = FUN_0041c710((int)param_1,param_2,'\x01');
    return piVar5;
  case 5:
    piVar5 = FUN_0041c6d0((int)param_1,param_2);
    if ((piVar5 == (int *)0x0) &&
       (piVar5 = FUN_0041c710((int)param_1,param_2,'\0'), piVar5 == (int *)0x0)) {
      return (int *)0x0;
    }
    return (int *)0x1;
  default:
    piVar5 = (int *)0x3;
  }
  return piVar5;
}



int * __cdecl FUN_0041c6d0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = param_2;
  uVar2 = FUN_00411c20(param_2,&param_2);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  if (param_2 == (int *)0x0) {
    iVar3 = FUN_00411d20(piVar1,&DAT_004312f4,param_1 + 0x10);
    param_2 = (int *)(uint)(iVar3 != 0);
  }
  return param_2;
}



int * __cdecl FUN_0041c710(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  
  piVar2 = param_2;
  iVar1 = param_2[7];
  uVar5 = FUN_00411c20(param_2,&param_2);
  if (param_2 == (int *)0x0) {
    *(uint *)(param_1 + 0x18) = uVar5;
    if (param_3 == '\0') {
      uVar7 = uVar5 * 2;
    }
    else {
      uVar7 = uVar5 * 4;
      piVar6 = (int *)FUN_00410c90(iVar1,uVar7,(undefined4 *)(param_1 + 0x1c));
      if (piVar6 != (int *)0x0) {
        return piVar6;
      }
      param_2 = (int *)0x0;
    }
    param_2 = (int *)FUN_00410c90(iVar1,uVar5 * 2,(undefined4 *)(param_1 + 0x20));
    if ((param_2 == (int *)0x0) &&
       (param_2 = (int *)FUN_00411900(piVar2,uVar7), param_2 == (int *)0x0)) {
      uVar7 = 0;
      if (uVar5 != 0) {
        do {
          uVar3 = FUN_004119f0((int)piVar2);
          *(undefined2 *)(*(int *)(param_1 + 0x20) + uVar7 * 2) = uVar3;
          if (param_3 != '\0') {
            uVar4 = FUN_004119f0((int)piVar2);
            *(uint *)(*(int *)(param_1 + 0x1c) + uVar7 * 4) = (uint)uVar4 + *(int *)(param_1 + 8);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar5);
      }
      FUN_004119a0(piVar2);
    }
  }
  return param_2;
}



undefined4 __cdecl
FUN_0041ca50(int param_1,uint param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
            int *param_6)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 0x264) != 0) && (param_3 < *(int *)(param_1 + 0x260))) {
    piVar2 = (int *)(param_3 * 0x30 + *(int *)(param_1 + 0x264));
    iVar1 = FUN_0041cac0(param_2,piVar2,param_4,param_6);
    if (iVar1 == 0) {
      *param_5 = piVar2;
      return 0;
    }
  }
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  return 6;
}



undefined4 __cdecl FUN_0041cac0(uint param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  
  if ((*(ushort *)(param_2 + 10) <= param_1) && (param_1 <= *(ushort *)((int)param_2 + 0x2a))) {
    puVar1 = (ushort *)param_2[1];
    puVar4 = puVar1 + *param_2 * 0x14;
    if (puVar1 != (ushort *)0x0) {
      for (; puVar1 < puVar4; puVar1 = puVar1 + 0x14) {
        if ((*puVar1 <= param_1) && (param_1 <= puVar1[1])) {
          uVar2 = (short)param_1 - *puVar1;
          switch(puVar1[2]) {
          case 1:
          case 3:
            *param_4 = *(int *)(*(int *)(puVar1 + 0xe) + (uint)uVar2 * 4);
            *param_3 = puVar1;
            return 0;
          case 2:
            uVar3 = (uint)uVar2;
            goto LAB_0041cb5f;
          case 4:
          case 5:
            uVar3 = 0;
            if (*(uint *)(puVar1 + 0xc) != 0) {
              puVar4 = *(ushort **)(puVar1 + 0x10);
              do {
                if (*puVar4 == param_1) {
                  if (puVar1[2] == 4) {
                    *param_4 = *(int *)(*(int *)(puVar1 + 0xe) + uVar3 * 4);
                    *param_3 = puVar1;
                    return 0;
                  }
LAB_0041cb5f:
                  *param_4 = *(int *)(puVar1 + 6) * uVar3 + *(int *)(puVar1 + 4);
                  *param_3 = puVar1;
                  return 0;
                }
                uVar3 = uVar3 + 1;
                puVar4 = puVar4 + 1;
              } while (uVar3 < *(uint *)(puVar1 + 0xc));
            }
          }
          break;
        }
      }
    }
  }
  *param_3 = 0;
  *param_4 = 0;
  return 6;
}



void __cdecl FUN_0041cbd0(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  byte *pbVar13;
  
  piVar2 = param_1;
  iVar11 = *param_1;
  pcVar3 = (char *)param_1[3];
  iVar1 = param_1[2];
  iVar10 = 0;
  if (iVar11 < 1) {
LAB_0041cc23:
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = 0;
    *(undefined1 *)((int)param_1 + 0x12) = 1;
    return;
  }
  do {
    pcVar12 = pcVar3 + iVar1;
    for (; pcVar3 < pcVar12; pcVar3 = pcVar3 + 1) {
      if (*pcVar3 != '\0') {
        if (iVar11 <= iVar10) goto LAB_0041cc23;
        if (0 < iVar10) {
          iVar11 = iVar11 - iVar10;
          memmove((void *)param_1[3],(void *)(iVar10 * iVar1 + param_1[3]),iVar11 * iVar1);
          cVar8 = (char)iVar10;
          *param_2 = *param_2 - cVar8;
          param_2[3] = param_2[3] - cVar8;
          param_2[6] = param_2[6] - cVar8;
          *param_1 = *param_1 - iVar10;
        }
        pcVar3 = (char *)((iVar11 + -1) * iVar1 + param_1[3]);
        param_1 = (int *)0x0;
        if (iVar11 < 1) goto LAB_0041ccd5;
        pcVar12 = pcVar3 + iVar1;
        pcVar4 = pcVar3;
        goto joined_r0x0041cca4;
      }
    }
    iVar10 = iVar10 + 1;
    pcVar3 = pcVar12;
    if (iVar11 <= iVar10) {
      param_1[1] = 0;
      *param_1 = 0;
      param_1[2] = 0;
      *(undefined1 *)((int)param_1 + 0x12) = 1;
      return;
    }
  } while( true );
joined_r0x0041cca4:
  if (pcVar3 < pcVar12) {
    if (*pcVar3 != '\0') goto LAB_0041ccc1;
    pcVar3 = pcVar3 + 1;
    goto joined_r0x0041cca4;
  }
  pcVar3 = pcVar4 + -iVar1;
  pcVar12 = pcVar12 + -iVar1;
  param_1 = (int *)((int)param_1 + 1);
  pcVar4 = pcVar3;
  if (iVar11 <= (int)param_1) {
LAB_0041ccc1:
    if (0 < (int)param_1) {
      *param_2 = *param_2 - (char)param_1;
      iVar11 = iVar11 - (int)param_1;
      *piVar2 = *piVar2 - (int)param_1;
    }
LAB_0041ccd5:
    iVar11 = iVar1 * iVar11;
    do {
      pbVar13 = (byte *)piVar2[3];
      for (pbVar5 = pbVar13; pbVar5 < pbVar13 + iVar11; pbVar5 = pbVar5 + iVar1) {
        if ((*pbVar5 & 0x80) != 0) goto LAB_0041cd72;
      }
      pbVar5 = pbVar13 + iVar11;
      for (; pbVar13 < pbVar5; pbVar13 = pbVar13 + iVar1) {
        bVar7 = *pbVar13 << 1;
        pbVar6 = pbVar13;
        if (8 < piVar2[1]) {
          iVar10 = (piVar2[1] - 9U >> 3) + 1;
          do {
            bVar9 = pbVar6[1] >> 7 | bVar7;
            bVar7 = pbVar6[1] << 1;
            *pbVar6 = bVar9;
            pbVar6 = pbVar6 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        *pbVar6 = bVar7;
      }
      piVar2[1] = piVar2[1] + -1;
      param_2[5] = param_2[5] + '\x01';
      param_2[2] = param_2[2] + '\x01';
      param_2[1] = param_2[1] + -1;
    } while (0 < piVar2[1]);
LAB_0041cd72:
    iVar10 = piVar2[1];
    do {
      iVar10 = iVar10 + -1;
      pbVar13 = (byte *)((iVar10 >> 3) + piVar2[3]);
      pbVar5 = pbVar13 + iVar11;
      for (; pbVar13 < pbVar5; pbVar13 = pbVar13 + iVar1) {
        if ((*pbVar13 & (byte)(0x80 >> ((byte)iVar10 & 7))) != 0) {
          return;
        }
      }
      piVar2[1] = iVar10;
      param_2[1] = param_2[1] + -1;
      iVar10 = piVar2[1];
    } while (0 < iVar10);
    return;
  }
  goto joined_r0x0041cca4;
}



int __cdecl
FUN_0041cdd0(int *param_1,int param_2,int param_3,uint param_4,uint *param_5,int param_6,int param_7
            ,int *param_8,byte *param_9)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined3 extraout_var;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  undefined1 *puVar11;
  char *pcVar12;
  byte local_8 [8];
  
  piVar2 = param_8;
  iVar8 = param_8[7];
  bVar4 = FUN_00411790((int)param_8,param_3 + param_4);
  pbVar9 = param_9;
  param_8 = (int *)CONCAT31(extraout_var,bVar4);
  if (param_8 != (int *)0x0) {
    return (int)param_8;
  }
  param_8 = (int *)FUN_0041d0b0(piVar2,param_2,(undefined4 *)param_9);
  puVar1 = param_5;
  if (param_8 != (int *)0x0) {
    return (int)param_8;
  }
  if (param_5[3] == 0) {
    param_5[1] = (uint)pbVar9[1];
    *param_5 = (uint)*pbVar9;
    switch(*(undefined1 *)((int)param_1 + 0x2e)) {
    case 1:
      *(undefined1 *)((int)param_5 + 0x12) = 1;
      uVar10 = (int)(param_5[1] + 7) >> 3;
      break;
    case 2:
      *(undefined1 *)((int)param_5 + 0x12) = 3;
      uVar10 = (int)(param_5[1] + 3) >> 2;
      break;
    default:
      goto switchD_0041ce4d_caseD_3;
    case 4:
      *(undefined1 *)((int)param_5 + 0x12) = 4;
      uVar10 = (int)(param_5[1] + 1) >> 1;
      break;
    case 8:
      uVar10 = param_5[1];
      *(undefined1 *)((int)param_5 + 0x12) = 2;
    }
    param_5[2] = uVar10;
    if (*param_5 * param_5[2] == 0) {
      return 0;
    }
    iVar7 = FUN_00410c90(iVar8,*param_5 * param_5[2],param_5 + 3);
    if (iVar7 != 0) {
      return iVar7;
    }
  }
  param_8 = (int *)0x0;
  switch(*(undefined2 *)(param_2 + 6)) {
  case 1:
  case 2:
  case 5:
  case 6:
  case 7:
    iVar8 = FUN_0041d200(puVar1,param_6,param_7,(uint)*(byte *)((int)param_1 + 0x2e),
                         *(undefined2 *)(param_2 + 6),pbVar9,piVar2);
    return iVar8;
  default:
switchD_0041ce4d_caseD_3:
    param_8 = (int *)0x3;
    break;
  case 8:
    FUN_004117c0((int)piVar2,1);
  case 9:
    pbVar9 = (byte *)FUN_00411b40(piVar2,&param_8);
    if (param_8 == (int *)0x0) {
      param_4 = (uint)pbVar9 & 0xffff;
      uVar10 = param_4 * 4;
      param_9 = pbVar9;
      param_8 = (int *)FUN_00410c90(iVar8,uVar10,&param_2);
      if (param_8 == (int *)0x0) {
        param_8 = (int *)FUN_00411900(piVar2,uVar10);
        if (param_8 == (int *)0x0) {
          if ((short)pbVar9 != 0) {
            puVar11 = (undefined1 *)(param_2 + 3);
            do {
              uVar6 = FUN_004119f0((int)piVar2);
              *(undefined2 *)(puVar11 + -3) = uVar6;
              uVar5 = FUN_004119d0((int)piVar2);
              puVar11[-1] = uVar5;
              uVar5 = FUN_004119d0((int)piVar2);
              *puVar11 = uVar5;
              puVar11 = puVar11 + 4;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            param_4 = 0;
            pbVar9 = param_9;
          }
          FUN_004119a0(piVar2);
          param_4 = (uint)pbVar9;
          if ((short)pbVar9 != 0) {
            pcVar12 = (char *)(param_2 + 2);
            piVar3 = param_8;
            do {
              param_8 = piVar3;
              param_8 = (int *)FUN_0041cac0((uint)*(ushort *)(pcVar12 + -2),param_1,&param_5,
                                            (int *)&param_9);
              if ((param_8 != (int *)0x0) ||
                 (param_8 = (int *)FUN_0041cdd0(param_1,(int)param_5,param_3,(uint)param_9,puVar1,
                                                *pcVar12 + param_6,pcVar12[1] + param_7,piVar2,
                                                local_8), param_8 != (int *)0x0)) break;
              param_4 = param_4 + 0xffff;
              pcVar12 = pcVar12 + 4;
              piVar3 = (int *)0x0;
            } while ((short)param_4 != 0);
          }
        }
        FUN_00410d70(iVar8,&param_2);
        return (int)param_8;
      }
    }
  }
  return (int)param_8;
}



int __cdecl FUN_0041d0b0(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 local_24 [8];
  byte local_1c [28];
  
  iVar1 = 0;
  switch(*(undefined2 *)(param_2 + 6)) {
  case 1:
  case 2:
  case 8:
    local_1c[0xc] = 9;
    local_1c[0x10] = 9;
    local_1c[4] = 8;
    local_1c[8] = 8;
    local_1c[0x14] = 8;
    local_1c[5] = 1;
    local_1c[9] = 1;
    local_1c[10] = 1;
    local_1c[0xb] = 0;
    local_1c[0xd] = 1;
    local_1c[0x11] = 1;
    local_1c[0x15] = 1;
    local_1c[0] = 4;
    local_1c[1] = 0;
    local_1c[2] = 5;
    local_1c[3] = 0;
    local_1c[6] = 0;
    local_1c[7] = 0;
    local_1c[0xe] = 2;
    local_1c[0xf] = 0;
    local_1c[0x12] = 3;
    local_1c[0x13] = 0;
    local_1c[0x16] = 4;
    local_1c[0x17] = 0;
    local_1c[0x18] = 0;
    local_1c[0x19] = 0;
    local_1c[0x1a] = 0;
    local_1c[0x1b] = 0;
    iVar1 = FUN_00411d20(param_1,local_1c,(int)local_24);
    if (iVar1 == 0) {
      *(char *)((int)param_3 + 1) = (char)local_24._1_4_;
      *(char *)((int)param_3 + 2) = SUB41(local_24._1_4_,1);
      *(char *)((int)param_3 + 3) = SUB41(local_24._1_4_,2);
      *(char *)(param_3 + 1) = SUB41(local_24._1_4_,3);
      *(undefined1 *)((int)param_3 + 5) = 0;
      *(undefined1 *)((int)param_3 + 6) = 0;
      *(undefined1 *)((int)param_3 + 7) = 0;
      *(undefined1 *)param_3 = local_24[0];
      return 0;
    }
    break;
  default:
    if ((*(short *)(param_2 + 4) != 2) && (*(short *)(param_2 + 4) != 5)) {
      return 3;
    }
    *param_3 = *(undefined4 *)(param_2 + 0x10);
    param_3[1] = *(undefined4 *)(param_2 + 0x14);
    break;
  case 6:
  case 7:
  case 9:
    iVar1 = FUN_00411d20(param_1,&DAT_004312f4,(int)param_3);
    return iVar1;
  }
  return iVar1;
}



int __cdecl
FUN_0041d200(uint *param_1,int param_2,int param_3,int param_4,undefined2 param_5,byte *param_6,
            int *param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = param_2;
  if ((((param_2 < 0) || (uVar2 = (uint)param_6[1], (int)param_1[1] < (int)(uVar2 + param_2))) ||
      (param_3 < 0)) || (uVar3 = (uint)*param_6, (int)*param_1 < (int)(uVar3 + param_3))) {
    iVar4 = 6;
  }
  else {
    param_2._0_1_ = '\0';
    switch(param_5) {
    case 1:
    case 6:
      if (param_4 == 1) {
        uVar3 = ((int)(uVar2 + 7) >> 3) * uVar3;
        param_2._0_1_ = '\x01';
      }
      else if (param_4 == 2) {
        uVar3 = ((int)(uVar2 + 3) >> 2) * uVar3;
        param_2._0_1_ = '\x01';
      }
      else if (param_4 == 4) {
        uVar3 = ((int)(uVar2 + 1) >> 1) * uVar3;
        param_2._0_1_ = '\x01';
      }
      else {
        uVar3 = uVar2 * uVar3;
        param_2._0_1_ = '\x01';
      }
      break;
    case 2:
    case 5:
    case 7:
      uVar3 = (int)(uVar2 * param_4 * uVar3 + 7) >> 3;
      break;
    default:
      return 3;
    }
    iVar4 = FUN_00411900(param_7,uVar3);
    if (iVar4 == 0) {
      FUN_0041d340(param_1,(byte *)param_7[8],uVar2 * param_4,(char)param_2,iVar1 * param_4,param_3)
      ;
      FUN_004119a0(param_7);
      return 0;
    }
  }
  return iVar4;
}



void __cdecl
FUN_0041d340(uint *param_1,byte *param_2,int param_3,char param_4,uint param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte *local_c;
  uint local_4;
  
  uVar2 = param_5;
  uVar1 = param_1[2];
  uVar10 = param_1[3];
  if ((int)uVar1 < 0) {
    uVar10 = uVar10 - (*param_1 - 1) * uVar1;
  }
  uVar11 = *param_1;
  local_c = (byte *)(((int)param_5 >> 3) + uVar10 + uVar1 * param_6);
  uVar10 = 0;
  uVar9 = 0;
  param_5 = 0;
  if (0 < (int)uVar11) {
    bVar4 = (byte)uVar2 & 7;
    bVar6 = 8 - bVar4;
    param_6 = (int)bVar6;
    local_4 = uVar11;
    do {
      pbVar5 = local_c;
      iVar12 = param_3;
      if (7 < param_3) {
        uVar11 = 8 - uVar9;
        uVar8 = uVar1;
        iVar3 = param_3 + -8;
        do {
          iVar12 = iVar3;
          if (uVar9 < 8) {
            uVar9 = uVar9 + 8;
            uVar10 = uVar10 | CONCAT22((short)(uVar8 >> 0x10),(ushort)*param_2) <<
                              ((byte)uVar11 & 0x1f);
            param_2 = param_2 + 1;
            uVar11 = uVar11 - 8;
            param_5 = uVar10;
          }
          bVar7 = (byte)(uVar10 >> 8);
          if ((uVar2 & 7) == 0) {
            *pbVar5 = *pbVar5 | bVar7;
          }
          else {
            *pbVar5 = *pbVar5 | bVar7 >> bVar4;
            pbVar5[1] = pbVar5[1] | bVar7 << (bVar6 & 0x1f);
            uVar10 = param_5;
          }
          uVar8 = 0;
          uVar10 = (uVar10 & 0xff) << 8;
          pbVar5 = pbVar5 + 1;
          uVar9 = uVar9 - 8;
          uVar11 = uVar11 + 8;
          iVar3 = iVar12 + -8;
          param_5 = uVar10;
        } while (-1 < iVar12 + -8);
      }
      if (0 < iVar12) {
        if ((int)uVar9 < iVar12) {
          uVar11 = CONCAT22((short)(uVar11 >> 0x10),(ushort)*param_2) << (8U - (char)uVar9 & 0x1f);
          uVar10 = uVar10 | uVar11;
          param_2 = param_2 + 1;
          uVar9 = uVar9 + 8;
          param_5 = uVar10;
        }
        bVar7 = ~(byte)(0xff >> ((byte)iVar12 & 0x1f)) & (byte)(uVar10 >> 8);
        *pbVar5 = *pbVar5 | bVar7 >> bVar4;
        if (param_6 < iVar12) {
          pbVar5[1] = pbVar5[1] | bVar7 << (bVar6 & 0x1f);
        }
        uVar10 = param_5 << ((byte)iVar12 & 0x1f);
        uVar9 = uVar9 - iVar12;
        param_5 = uVar10;
      }
      if (param_4 != '\0') {
        uVar10 = 0;
        param_5 = 0;
        uVar9 = 0;
      }
      local_c = local_c + uVar1;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  return;
}



void __cdecl FUN_0041d4c0(int param_1)

{
  int iVar1;
  ushort uVar2;
  
  iVar1 = *(int *)(param_1 + 100);
  if (*(char *)(param_1 + 0x270) != '\0') {
    if (*(int *)(param_1 + 0x1d0) == 0x20000) {
      FUN_00410d70(iVar1,(int *)(param_1 + 0x278));
      uVar2 = 0;
      *(undefined2 *)(param_1 + 0x274) = 0;
      if (*(short *)(param_1 + 0x276) != 0) {
        do {
          FUN_00410d70(iVar1,(int *)(*(int *)(param_1 + 0x27c) + (uint)uVar2 * 4));
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(ushort *)(param_1 + 0x276));
      }
      FUN_00410d70(iVar1,(int *)(param_1 + 0x27c));
      *(undefined2 *)(param_1 + 0x276) = 0;
    }
    else if (*(int *)(param_1 + 0x1d0) == 0x28000) {
      FUN_00410d70(iVar1,(int *)(param_1 + 0x278));
      *(undefined2 *)(param_1 + 0x274) = 0;
      *(undefined1 *)(param_1 + 0x270) = 0;
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x270) = 0;
  return;
}



undefined4 __cdecl FUN_0041d580(int param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    return 0x23;
  }
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    iVar2 = *(int *)(param_1 + 0x214);
    if (iVar2 == 0) {
      return 7;
    }
    uVar4 = (**(code **)(iVar2 + 0xc))(0);
    *param_3 = uVar4;
    iVar3 = *(int *)(param_1 + 0x1d0);
    if (iVar3 == 0x10000) {
      if (param_2 < 0x102) {
        uVar4 = (**(code **)(iVar2 + 0xc))(param_2);
        *param_3 = uVar4;
      }
    }
    else if (iVar3 == 0x20000) {
      if ((*(char *)(param_1 + 0x270) == '\0') &&
         (piVar5 = FUN_0041d6c0(param_1), piVar5 != (int *)0x0)) {
        return 0;
      }
      if (param_2 < *(ushort *)(param_1 + 0x274)) {
        uVar1 = *(ushort *)(*(int *)(param_1 + 0x278) + param_2 * 2);
        if (0x101 < uVar1) {
          *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x27c) + -0x408 + (uint)uVar1 * 4);
          return 0;
        }
        uVar4 = (**(code **)(iVar2 + 0xc))(uVar1);
        *param_3 = uVar4;
        return 0;
      }
    }
    else if (iVar3 == 0x28000) {
      if ((*(char *)(param_1 + 0x270) == '\0') &&
         (piVar5 = FUN_0041d6c0(param_1), piVar5 != (int *)0x0)) {
        return 0;
      }
      if (param_2 < *(ushort *)(param_1 + 0x274)) {
        uVar4 = (**(code **)(iVar2 + 0xc))
                          (param_2 + (int)*(char *)(*(int *)(param_1 + 0x278) + param_2));
        *param_3 = uVar4;
        return 0;
      }
    }
    return 0;
  }
  return 0x10;
}



int * __cdecl FUN_0041d6c0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x68);
  piVar2 = (int *)(**(code **)(param_1 + 0x1f8))(param_1,0x706f7374,piVar3,0);
  if (piVar2 == (int *)0x0) {
    iVar1 = *(int *)(param_1 + 0x1d0);
    piVar2 = (int *)FUN_004117c0((int)piVar3,0x20);
    if (piVar2 == (int *)0x0) {
      if (iVar1 != 0x20000) {
        if (iVar1 != 0x28000) {
          *(undefined1 *)(param_1 + 0x270) = 1;
          return (int *)0x3;
        }
        piVar3 = FUN_0041d950(param_1,piVar3);
        *(undefined1 *)(param_1 + 0x270) = 1;
        return piVar3;
      }
      piVar2 = (int *)FUN_0041d740(param_1,piVar3);
      *(undefined1 *)(param_1 + 0x270) = 1;
    }
  }
  return piVar2;
}



int __cdecl FUN_0041d740(int param_1,int *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  uint local_4;
  uint uVar5;
  
  iVar8 = param_2[7];
  local_10 = 0;
  local_14 = 0;
  local_c = iVar8;
  uVar2 = FUN_00411b40(param_2,&local_18);
  uVar2 = uVar2 & 0xffff;
  if (local_18 == 0) {
    if (*(int *)(param_1 + 0x10) < (int)uVar2) {
      return 3;
    }
    local_8 = uVar2;
    local_18 = FUN_00410c90(iVar8,uVar2 * 2,&local_10);
    if ((local_18 == 0) && (local_18 = FUN_00411900(param_2,uVar2 * 2), local_18 == 0)) {
      iVar7 = 0;
      local_18 = 0;
      if (uVar2 != 0) {
        do {
          uVar1 = FUN_004119f0((int)param_2);
          *(undefined2 *)(local_10 + iVar7 * 2) = uVar1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)uVar2);
      }
      FUN_004119a0(param_2);
      uVar5 = 0;
      uVar4 = 0;
      iVar7 = 0;
      if (uVar2 != 0) {
        do {
          uVar3 = (uint)*(ushort *)(local_10 + iVar7 * 2);
          if ((0x101 < uVar3) && (uVar3 = uVar3 - 0x101, (int)(uVar5 & 0xffff) < (int)uVar3)) {
            uVar5 = uVar3;
          }
          uVar4 = (ushort)uVar5;
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)uVar2);
      }
      local_4 = (uint)uVar4;
      local_18 = FUN_00410c90(iVar8,local_4 << 2,&local_14);
      if (local_18 == 0) {
        uVar6 = 0;
        if (uVar4 != 0) {
          do {
            uVar2 = FUN_00411ad0((uint3)&local_18,param_2,&local_18);
            uVar2 = uVar2 & 0xff;
            if (local_18 != 0) {
LAB_0041d8fc:
              iVar7 = 0;
              uVar2 = local_4;
              do {
                FUN_00410d70(local_c,(int *)(iVar7 + local_14));
                iVar7 = iVar7 + 4;
                uVar2 = uVar2 - 1;
                iVar8 = local_c;
              } while (uVar2 != 0);
              goto LAB_0041d921;
            }
            iVar8 = (uint)uVar6 * 4;
            local_18 = FUN_00410c90(local_c,uVar2 + 1,(undefined4 *)(iVar8 + local_14));
            if ((local_18 != 0) ||
               (local_18 = FUN_004117f0(param_2,*(undefined4 **)(iVar8 + local_14),uVar2),
               local_18 != 0)) goto LAB_0041d8fc;
            uVar6 = uVar6 + 1;
            *(undefined1 *)(uVar2 + *(int *)(iVar8 + local_14)) = 0;
            uVar2 = local_8;
          } while (uVar6 < uVar4);
        }
        *(short *)(param_1 + 0x274) = (short)uVar2;
        *(ushort *)(param_1 + 0x276) = uVar4;
        *(int *)(param_1 + 0x278) = local_10;
        *(int *)(param_1 + 0x27c) = local_14;
        return 0;
      }
    }
LAB_0041d921:
    FUN_00410d70(iVar8,&local_14);
    FUN_00410d70(iVar8,&local_10);
  }
  return local_18;
}



int * __cdecl FUN_0041d950(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *local_4;
  
  piVar2 = param_2;
  iVar1 = param_2[7];
  local_4 = (undefined4 *)0x0;
  uVar3 = FUN_00411b40(param_2,&param_2);
  uVar6 = uVar3 & 0xffff;
  if (param_2 == (int *)0x0) {
    if (((int)uVar6 <= *(int *)(param_1 + 0x10)) && (uVar6 < 0x103)) {
      param_2 = (int *)FUN_00410c90(iVar1,uVar6,&local_4);
      if (param_2 == (int *)0x0) {
        param_2 = (int *)FUN_004117f0(piVar2,local_4,uVar6);
        if (param_2 == (int *)0x0) {
          if (uVar6 != 0) {
            iVar4 = 0;
            do {
              iVar5 = *(char *)(iVar4 + (int)local_4) + iVar4;
              if ((iVar5 < 0) || ((int)uVar6 < iVar5)) {
                param_2 = (int *)0x3;
                goto LAB_0041d9fe;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)uVar6);
          }
          *(short *)(param_1 + 0x274) = (short)uVar3;
          *(undefined4 **)(param_1 + 0x278) = local_4;
          return (int *)0x0;
        }
      }
LAB_0041d9fe:
      FUN_00410d70(iVar1,(int *)&local_4);
      return param_2;
    }
    param_2 = (int *)0x3;
  }
  return param_2;
}



int __cdecl FUN_0041da30(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_2;
  *param_2 = 0;
  iVar2 = FUN_00410c90(param_1,0x80c,&param_2);
  if (iVar2 == 0) {
    param_2[0x202] = param_1;
    FUN_0041da80((int)param_2);
    *puVar1 = param_2;
  }
  return iVar2;
}



void __cdecl FUN_0041da80(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = (uint *)(param_1 + 0x408);
  do {
    uVar1 = (uVar2 >> 1 & 0x55) + (uVar2 & 0x55);
    *puVar3 = (((uVar1 & 0xc0) << 2 | uVar1 & 0x30) << 2 | uVar1 & 0xc) << 2 | uVar1 & 3;
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 0x100);
  return;
}



int __cdecl FUN_0041dc10(int *param_1)

{
  int iVar1;
  
  FUN_0041dd10(param_1,param_1[0x25] & 0x100);
  param_1[7] = param_1[4];
  *(byte *)((int)param_1 + 0xb9) = ~(byte)((uint)param_1[0x25] >> 9) & 1;
  *(undefined1 *)(param_1 + 0x2e) = 2;
  param_1[0x2a] = (int)&LAB_0041dd70;
  param_1[0x2b] = (int)&LAB_0041ddc0;
  param_1[0x2c] = (int)FUN_0041deb0;
  param_1[0x2d] = (int)&LAB_0041e010;
  param_1[0x101] = 0;
  *(undefined2 *)(param_1 + 0xf1) = 0;
  *(short *)((int)param_1 + 0x3c6) = (short)param_1[0x1b] + -1;
  *(short *)(param_1 + 0xf) = (short)param_1[0x1c];
  param_1[0x10] = param_1[0x1e];
  iVar1 = FUN_0041e210(param_1,'\0');
  if (iVar1 == 0) {
    if ((*(char *)((int)param_1 + 0xb9) != '\0') && ((char)param_1[0x2e] != '\0')) {
      param_1[0x2a] = (int)&LAB_0041e030;
      param_1[0x2b] = (int)&LAB_0041e040;
      param_1[0x2c] = (int)FUN_0041e0b0;
      param_1[0x2d] = (int)&LAB_0041e030;
      param_1[0x101] = 0;
      *(undefined2 *)(param_1 + 0xf1) = 0;
      *(short *)((int)param_1 + 0x3c6) = (short)param_1[0x1c] + -1;
      iVar1 = FUN_0041e210(param_1,'\x01');
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



void __cdecl FUN_0041dd10(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    *param_1 = 6;
    param_1[5] = 0x20;
    param_1[6] = 2;
  }
  else {
    *param_1 = 10;
    param_1[5] = 0x80;
    param_1[6] = 0x18;
  }
  iVar1 = 1 << ((byte)*param_1 & 0x1f);
  param_1[4] = *param_1 + -6;
  param_1[1] = iVar1;
  param_1[3] = -iVar1;
  param_1[2] = iVar1 / 2;
  return;
}



void __cdecl
FUN_0041deb0(undefined4 *param_1,short param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  iVar2 = param_1[1];
  uVar6 = -iVar2;
  uVar1 = iVar2 + -1 + param_3 & uVar6;
  uVar4 = uVar6 & param_4;
  if ((int)uVar4 < (int)uVar1) {
    if (uVar1 != iVar2 + uVar4) {
      return;
    }
    switch(*(undefined1 *)(param_1 + 0x2e)) {
    case 2:
    case 5:
      if ((*(int *)(param_5 + 0x1c) == param_6) && (*(int *)(param_5 + 0x10) < 1)) {
        return;
      }
      if ((*(int *)(param_6 + 0x1c) == param_5) && (*(int *)(param_5 + 0x14) == (int)param_2)) {
        return;
      }
      iVar2 = (int)uVar1 >> ((byte)*param_1 & 0x1f);
      if (((-1 < iVar2) && (iVar2 < (int)(uint)*(ushort *)(param_1 + 0xf))) &&
         ((*(byte *)((int)(short)(iVar2 >> 3) + param_1[0x26] + param_1[0x10]) &
          (byte)(0x80 >> ((byte)iVar2 & 7))) != 0)) {
        return;
      }
      if (*(char *)(param_1 + 0x2e) != '\x02') {
        uVar1 = (int)(param_3 + 1 + param_4) / 2 + -1 + param_1[1];
        goto LAB_0041df95;
      }
    case 1:
      uVar1 = uVar4;
      break;
    default:
      goto switchD_0041def5_caseD_3;
    case 4:
      uVar1 = (int)(param_3 + 1 + param_4) / 2 + -1 + iVar2;
LAB_0041df95:
      uVar1 = uVar1 & uVar6;
    }
  }
  iVar2 = (int)uVar1 >> ((byte)*param_1 & 0x1f);
  if ((-1 < iVar2) && (iVar2 < (int)(uint)*(ushort *)(param_1 + 0xf))) {
    sVar3 = (short)(iVar2 >> 3);
    if (sVar3 < *(short *)((int)param_1 + 0xa2)) {
      *(short *)((int)param_1 + 0xa2) = sVar3;
    }
    if (*(short *)(param_1 + 0x29) < sVar3) {
      *(short *)(param_1 + 0x29) = sVar3;
    }
    pbVar5 = (byte *)((int)sVar3 + param_1[0x26] + param_1[0x10]);
    *pbVar5 = *pbVar5 | (byte)(0x80 >> ((byte)iVar2 & 7));
  }
switchD_0041def5_caseD_3:
  return;
}



void __cdecl
FUN_0041e0b0(undefined4 *param_1,short param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  iVar3 = param_1[1];
  uVar5 = -iVar3;
  uVar1 = iVar3 + -1 + param_3 & uVar5;
  uVar4 = uVar5 & param_4;
  if ((int)uVar4 < (int)uVar1) {
    if (uVar1 != iVar3 + uVar4) {
      return;
    }
    switch(*(undefined1 *)(param_1 + 0x2e)) {
    case 2:
    case 5:
      if ((*(int *)(param_5 + 0x1c) == param_6) && (*(int *)(param_5 + 0x10) < 1)) {
        return;
      }
      if ((*(int *)(param_6 + 0x1c) == param_5) && (*(int *)(param_5 + 0x14) == (int)param_2)) {
        return;
      }
      iVar2 = (int)uVar1 >> ((byte)*param_1 & 0x1f);
      iVar3 = param_1[0x1d];
      pbVar6 = (byte *)((((int)param_2 >> 3) - iVar3 * iVar2) + param_1[0x10]);
      if (0 < iVar3) {
        pbVar6 = pbVar6 + (param_1[0x1b] + -1) * iVar3;
      }
      if (((-1 < iVar2) && (iVar2 < (int)param_1[0x1b])) &&
         ((*pbVar6 & (byte)(0x80 >> ((byte)param_2 & 7))) != 0)) {
        return;
      }
      if (*(char *)(param_1 + 0x2e) != '\x02') {
        uVar1 = (int)(param_3 + 1 + param_4) / 2 + -1 + param_1[1];
        goto LAB_0041e1ab;
      }
    case 1:
      uVar1 = uVar4;
      break;
    default:
      goto switchD_0041e0f5_caseD_3;
    case 4:
      uVar1 = (int)(param_3 + 1 + param_4) / 2 + -1 + iVar3;
LAB_0041e1ab:
      uVar1 = uVar1 & uVar5;
    }
  }
  iVar3 = (int)uVar1 >> ((byte)*param_1 & 0x1f);
  if ((-1 < iVar3) && (iVar3 < (int)param_1[0x1b])) {
    iVar2 = param_1[0x1d];
    pbVar6 = (byte *)((((int)param_2 >> 3) - iVar2 * iVar3) + param_1[0x10]);
    if (0 < iVar2) {
      pbVar6 = pbVar6 + (param_1[0x1b] + -1) * iVar2;
    }
    *pbVar6 = *pbVar6 | (byte)(0x80 >> ((byte)param_2 & 7));
  }
switchD_0041e0f5_caseD_3:
  return;
}



int __cdecl FUN_0041e210(int *param_1,char param_2)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = param_1[0x101];
  do {
    if (iVar4 < 0) {
      return 0;
    }
    param_1[0x15] = (int)*(short *)((int)param_1 + iVar4 * 4 + 0x3c6) * param_1[1];
    param_1[0x14] = (int)(short)param_1[iVar4 + 0xf1] * param_1[1];
    param_1[0xb] = param_1[8];
    param_1[0xc] = 0;
    bVar2 = FUN_0041e320(param_1,(int)param_2);
    if (bVar2) {
      if (param_1[0xc] != 0x62) {
        return 1;
      }
      iVar4 = param_1[0x101];
      param_1[0xc] = 0;
      sVar1 = *(short *)((int)param_1 + iVar4 * 4 + 0x3c6);
      if ((6 < iVar4) ||
         (sVar3 = (short)(((int)sVar1 + (int)(short)param_1[iVar4 + 0xf1]) / 2),
         sVar3 < (short)param_1[iVar4 + 0xf1])) {
        param_1[0x101] = 0;
        param_1[0xc] = 0x14;
        return 0x14;
      }
      *(short *)(param_1 + iVar4 + 0xf2) = sVar3;
      *(short *)((int)param_1 + param_1[0x101] * 4 + 0x3ca) = sVar1;
      *(short *)((int)param_1 + param_1[0x101] * 4 + 0x3c6) = sVar3 + -1;
      iVar4 = param_1[0x101] + 1;
    }
    else {
      if ((param_1[0x18] != 0) && (uVar5 = FUN_0041f220(param_1), (char)uVar5 != '\0')) {
        return param_1[0xc];
      }
      iVar4 = param_1[0x101] + -1;
    }
    param_1[0x101] = iVar4;
  } while( true );
}



bool __cdecl FUN_0041e320(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  param_1[10] = param_1[9] + -0x20;
  iVar4 = param_1[0xb];
  param_1[0x18] = 0;
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  param_1[0xd] = 0;
  param_1[0x17] = iVar4;
  *(int *)(iVar4 + 8) = iVar4;
  uVar5 = 0;
  iVar4 = 0;
  *(undefined2 *)(param_1 + 0x16) = 0;
  if (0 < (short)param_1[0x21]) {
    do {
      param_1[0x1a] = 0;
      param_1[0x19] = 0;
      uVar3 = FUN_0041e5d0(param_1,uVar5,(uint)*(ushort *)(param_1[0x24] + iVar4 * 2),param_2);
      if ((char)uVar3 != '\0') {
        return true;
      }
      uVar1 = param_1[0x13];
      uVar5 = (int)*(short *)(param_1[0x24] + iVar4 * 2) + 1;
      if (((((uVar1 & param_1[1] - 1U) == 0) && (param_1[0x14] <= (int)uVar1)) &&
          ((int)uVar1 <= param_1[0x15])) &&
         ((param_1[0x19] != 0 && (*(int *)(param_1[0x19] + 0xc) == *(int *)(param_1[0x17] + 0xc)))))
      {
        param_1[0xb] = param_1[0xb] + -4;
      }
      iVar2 = param_1[0x17];
      uVar3 = FUN_0041e420((int)param_1);
      if ((char)uVar3 != '\0') {
        return true;
      }
      if (param_1[0x19] != 0) {
        *(int *)(iVar2 + 0x1c) = param_1[0x19];
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)param_1[0x21]);
  }
  uVar5 = FUN_0041e490((int)param_1);
  if ((char)uVar5 != '\0') {
    return true;
  }
  return (bool)('\x01' - ((uint)param_1[0xb] < (uint)param_1[10]));
}



undefined4 __cdecl FUN_0041e420(int param_1)

{
  int iVar1;
  uint3 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  iVar3 = *(int *)(param_1 + 0x2c) - *(int *)(iVar1 + 8) >> 2;
  uVar2 = (uint3)((uint)param_1 >> 8);
  if (iVar3 < 0) {
    *(undefined4 *)(param_1 + 0x30) = 99;
    return CONCAT31(uVar2,1);
  }
  if (0 < iVar3) {
    *(int *)(iVar1 + 0x10) = iVar3;
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x20;
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x10) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 8) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x5c);
    *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + 1;
  }
  if (*(uint *)(param_1 + 0x28) <= *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x30) = 0x62;
    return CONCAT31(uVar2,1);
  }
  *(undefined1 *)(param_1 + 0x5b) = 0;
  return (uint)uVar2 << 8;
}



uint __cdecl FUN_0041e490(int param_1)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = *(ushort *)(param_1 + 0x58);
  if (uVar3 < 2) {
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x60);
    if (uVar3 != 0) {
      while( true ) {
        if (uVar3 < 2) {
          *(undefined4 *)(iVar4 + 4) = 0;
        }
        else {
          *(int *)(iVar4 + 4) = *(int *)(iVar4 + 8) + *(int *)(iVar4 + 0x10) * 4;
        }
        if (*(int *)(iVar4 + 0xc) == -1) {
          iVar5 = *(int *)(iVar4 + 0x14);
          iVar1 = (iVar5 - *(int *)(iVar4 + 0x10)) + 1;
          *(int *)(iVar4 + 0x14) = iVar1;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + *(int *)(iVar4 + 0x10) * 4 + -4;
        }
        else {
          iVar1 = *(int *)(iVar4 + 0x14);
          iVar5 = *(int *)(iVar4 + 0x10) + -1 + iVar1;
        }
        uVar2 = FUN_0041e550(param_1,iVar1);
        if ((char)uVar2 != '\0') break;
        uVar2 = FUN_0041e550(param_1,iVar5 + 1);
        if ((char)uVar2 != '\0') break;
        iVar4 = *(int *)(iVar4 + 4);
        uVar3 = uVar3 - 1;
        if (uVar3 == 0) {
          return uVar2;
        }
      }
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}



uint __cdecl FUN_0041e550(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  iVar2 = *(int *)(param_1 + 0x24) + uVar1 * -4;
  do {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 0) goto LAB_0041e590;
  } while (param_2 < *(int *)(iVar2 + uVar1 * 4));
  if (-1 < (int)uVar1) {
    iVar3 = param_2;
    if (param_2 <= *(int *)(iVar2 + uVar1 * 4)) goto LAB_0041e5bd;
    do {
      uVar1 = uVar1 - 1;
      param_2 = *(int *)(iVar2 + 4 + uVar1 * 4);
      *(int *)(iVar2 + 4 + uVar1 * 4) = iVar3;
      iVar3 = param_2;
    } while (-1 < (int)uVar1);
  }
LAB_0041e590:
  uVar1 = *(uint *)(param_1 + 0x28);
  if (uVar1 <= *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x30) = 0x62;
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  iVar2 = *(int *)(param_1 + 0x34) + 1;
  *(uint *)(param_1 + 0x28) = uVar1 - 4;
  uVar1 = iVar2 * 4;
  *(int *)(param_1 + 0x34) = iVar2;
  *(int *)(*(int *)(param_1 + 0x24) + iVar2 * -4) = param_2;
LAB_0041e5bd:
  return uVar1 & 0xffffff00;
}



undefined4 __cdecl FUN_0041e5d0(int *param_1,uint param_2,uint param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  int *piVar17;
  int local_18;
  uint local_10;
  uint local_c;
  int local_8;
  
  piVar2 = param_1;
  iVar14 = param_1[0x22];
  piVar17 = (int *)(iVar14 + (param_3 & 0xffff) * 8);
  uVar7 = param_2 & 0xffff;
  piVar16 = (int *)(iVar14 + uVar7 * 8);
  iVar5 = param_1[2];
  bVar6 = (byte)param_1[7];
  uVar15 = (*(int *)(iVar14 + uVar7 * 8) << (bVar6 & 0x1f)) - iVar5;
  local_c = (*(int *)(iVar14 + 4 + uVar7 * 8) << (bVar6 & 0x1f)) - iVar5;
  uVar8 = (*piVar17 << (bVar6 & 0x1f)) - iVar5;
  uVar13 = (piVar17[1] << (bVar6 & 0x1f)) - iVar5;
  uVar7 = uVar8;
  local_10 = uVar15;
  if (param_4 != 0) {
    uVar7 = uVar13;
    uVar13 = uVar8;
    local_10 = local_c;
    local_c = uVar15;
  }
  piVar1 = param_1 + 0x23;
  pbVar10 = (byte *)(*piVar1 + (param_2 & 0xffff));
  piVar4 = (int *)(*pbVar10 & 3);
  if (piVar4 == (int *)0x2) {
LAB_0041e8fa:
    piVar2[0xc] = 0x14;
    return CONCAT31((int3)((uint)piVar4 >> 8),1);
  }
  param_1 = piVar17;
  if ((*pbVar10 & 3) == 0) {
    if ((*(byte *)(*piVar1 + (param_3 & 0xffff)) & 3) == 1) {
      param_1 = piVar17 + -2;
      local_10 = uVar7;
      local_c = uVar13;
    }
    else {
      local_10 = (int)(uVar7 + local_10) / 2;
      local_c = (int)(local_c + uVar13) / 2;
    }
    piVar16 = piVar16 + -2;
    pbVar10 = pbVar10 + -1;
  }
  piVar2[0x12] = local_10;
  piVar2[0x13] = local_c;
  do {
    if (param_1 <= piVar16) {
      uVar7 = FUN_0041e930(piVar2,local_10,local_c);
      cVar3 = (char)uVar7;
joined_r0x0041e8ee:
      if (cVar3 == '\0') {
        return uVar7 & 0xffffff00;
      }
      break;
    }
    piVar17 = piVar16 + 2;
    param_2 = (uint)(pbVar10 + 1);
    if ((*(byte *)param_2 & 3) == 0) {
      iVar14 = (*piVar17 << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
      iVar5 = (piVar16[3] << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
      local_8 = iVar5;
      if (param_4 == 0) goto LAB_0041e7f6;
      while( true ) {
        iVar5 = iVar14;
        iVar14 = local_8;
LAB_0041e7f6:
        local_8 = iVar14;
        if (param_1 <= piVar17) {
          uVar7 = FUN_0041ec80(piVar2,local_8,iVar5,local_10,local_c);
          goto LAB_0041e8ec;
        }
        piVar16 = piVar17 + 3;
        piVar17 = piVar17 + 2;
        param_2 = param_2 + 1;
        piVar4 = (int *)(*(byte *)param_2 & 3);
        iVar12 = (*piVar17 << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
        iVar14 = (*piVar16 << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
        iVar11 = iVar12;
        if (param_4 != 0) {
          iVar11 = iVar14;
          iVar14 = iVar12;
        }
        if (piVar4 == (int *)0x1) break;
        if ((*(byte *)param_2 & 3) != 0) goto LAB_0041e8fa;
        uVar7 = FUN_0041ec80(piVar2,local_8,iVar5,(iVar11 + local_8) / 2,(iVar5 + iVar14) / 2);
        local_8 = iVar11;
        if ((char)uVar7 != '\0') goto LAB_0041e8c7;
      }
      uVar7 = FUN_0041ec80(piVar2,local_8,iVar5,iVar11,iVar14);
LAB_0041e89e:
      cVar3 = (char)uVar7;
      piVar16 = piVar17;
      pbVar10 = (byte *)param_2;
    }
    else {
      if ((*(byte *)param_2 & 3) != 1) {
        piVar4 = param_1;
        if ((piVar16 + 4 <= param_1) &&
           (piVar4 = (int *)(CONCAT31((int3)((uint)param_1 >> 8),pbVar10[2]) & 0xffffff03),
           (char)piVar4 == '\x02')) {
          iVar14 = piVar2[2];
          piVar17 = piVar16 + 6;
          bVar6 = (byte)piVar2[7];
          param_2 = (uint)(pbVar10 + 3);
          uVar13 = (piVar16[4] << (bVar6 & 0x1f)) - iVar14;
          param_3 = (piVar16[5] << (bVar6 & 0x1f)) - iVar14;
          iVar9 = (piVar16[2] << (bVar6 & 0x1f)) - iVar14;
          iVar11 = (piVar16[3] << (bVar6 & 0x1f)) - iVar14;
          local_18 = (*piVar17 << (bVar6 & 0x1f)) - iVar14;
          iVar14 = (piVar16[7] << (bVar6 & 0x1f)) - iVar14;
          uVar7 = uVar13;
          iVar5 = iVar9;
          iVar12 = iVar14;
          if (param_4 != 0) {
            uVar7 = param_3;
            iVar5 = iVar11;
            iVar11 = iVar9;
            iVar12 = local_18;
            param_3 = uVar13;
            local_18 = iVar14;
          }
          if (param_1 < piVar17) {
            uVar7 = FUN_0041f030(piVar2,iVar5,iVar11,uVar7,param_3,local_10,local_c);
LAB_0041e8ec:
            cVar3 = (char)uVar7;
            goto joined_r0x0041e8ee;
          }
          uVar7 = FUN_0041f030(piVar2,iVar5,iVar11,uVar7,param_3,local_18,iVar12);
          goto LAB_0041e89e;
        }
        goto LAB_0041e8fa;
      }
      uVar8 = (*piVar17 << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
      uVar13 = (piVar16[3] << ((byte)piVar2[7] & 0x1f)) - piVar2[2];
      uVar7 = uVar8;
      if (param_4 != 0) {
        uVar7 = uVar13;
        uVar13 = uVar8;
      }
      uVar7 = FUN_0041e930(piVar2,uVar7,uVar13);
      cVar3 = (char)uVar7;
      piVar16 = piVar17;
      pbVar10 = (byte *)param_2;
    }
  } while (cVar3 == '\0');
LAB_0041e8c7:
  return CONCAT31((int3)(uVar7 >> 8),1);
}



undefined4 __cdecl FUN_0041e930(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1[0x1a];
  if (iVar3 == 0) {
    if ((int)param_1[0x13] < (int)param_3) goto LAB_0041e95b;
    if ((int)param_1[0x13] <= (int)param_3) goto LAB_0041e993;
    iVar3 = 2;
  }
  else if (iVar3 == 1) {
    if ((int)param_1[0x13] <= (int)param_3) goto LAB_0041e993;
    uVar1 = FUN_0041e420((int)param_1);
    if ((char)uVar1 != '\0') goto LAB_0041e96a;
    iVar3 = 2;
  }
  else {
    if ((iVar3 != 2) || ((int)param_3 <= (int)param_1[0x13])) goto LAB_0041e993;
    uVar1 = FUN_0041e420((int)param_1);
    if ((char)uVar1 != '\0') goto LAB_0041e96a;
LAB_0041e95b:
    iVar3 = 1;
  }
  uVar1 = FUN_0041ea00((int)param_1,iVar3);
  if ((char)uVar1 != '\0') {
LAB_0041e96a:
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
LAB_0041e993:
  if (param_1[0x1a] == 1) {
    uVar2 = FUN_0041eaa0(param_1,param_1[0x12],param_1[0x13],param_2,param_3,param_1[0x14],
                         param_1[0x15]);
    if ((char)uVar2 != '\0') {
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  }
  else {
    uVar2 = param_1[0x1a] - 2;
    if (uVar2 == 0) {
      uVar2 = FUN_0041ec20(param_1,param_1[0x12],param_1[0x13],param_2,param_3,param_1[0x14],
                           param_1[0x15]);
      if ((char)uVar2 != '\0') {
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
    }
  }
  param_1[0x13] = param_3;
  param_1[0x12] = param_2;
  return uVar2 & 0xffffff00;
}



undefined4 __cdecl FUN_0041ea00(int param_1,int param_2)

{
  int iVar1;
  uint3 uVar2;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x5c) = iVar1;
    *(int *)(param_1 + 0x60) = iVar1;
    *(int *)(param_1 + 0x2c) = iVar1 + 0x20;
  }
  uVar2 = (uint3)((uint)param_1 >> 8);
  if (*(uint *)(param_1 + 0x28) <= *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x30) = 0x62;
    return CONCAT31(uVar2,1);
  }
  if (param_2 == 1) {
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0xc) = 1;
  }
  else {
    if (param_2 != 2) {
      *(undefined4 *)(param_1 + 0x30) = 0x14;
      return CONCAT31(uVar2,1);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0xc) = 0xffffffff;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 8) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x1c) = 0;
  if (*(int *)(param_1 + 100) == 0) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x5c);
  }
  *(int *)(param_1 + 0x68) = param_2;
  *(undefined1 *)(param_1 + 0x5a) = 1;
  *(undefined1 *)(param_1 + 0x5b) = 0;
  return (uint)uVar2 << 8;
}



uint __cdecl
FUN_0041eaa0(undefined4 *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
            int param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  puVar1 = param_1;
  uVar4 = param_4 - param_2;
  uVar10 = param_5 - param_3;
  if (((0 < (int)uVar10) && (param_6 <= (int)param_5)) && ((int)param_3 <= param_7)) {
    if ((int)param_3 < param_6) {
      uVar2 = FUN_00410a10(uVar4,param_6 - param_3,uVar10);
      param_2 = param_2 + uVar2;
      bVar3 = (byte)*param_1;
      iVar7 = param_6 >> (bVar3 & 0x1f);
      uVar2 = 0;
    }
    else {
      bVar3 = (byte)*param_1;
      iVar7 = (int)param_3 >> (bVar3 & 0x1f);
      uVar2 = param_1[1] - 1 & param_3;
    }
    if (param_7 < (int)param_5) {
      iVar8 = param_7 >> (bVar3 & 0x1f);
      uVar5 = 0;
    }
    else {
      iVar8 = (int)param_5 >> (bVar3 & 0x1f);
      uVar5 = param_1[1] - 1 & param_5;
    }
    if ((int)uVar2 < 1) {
      if (*(char *)((int)param_1 + 0x5b) != '\0') {
        param_1[0xb] = param_1[0xb] + -4;
        *(undefined1 *)((int)param_1 + 0x5b) = 0;
      }
    }
    else {
      param_3 = param_5;
      if (iVar7 == iVar8) goto LAB_0041ec0e;
      param_2 = param_2 + (int)((param_1[1] - uVar2) * uVar4) / (int)uVar10;
      iVar7 = iVar7 + 1;
    }
    *(bool *)((int)param_1 + 0x5b) = uVar5 == 0;
    if (*(char *)((int)param_1 + 0x5a) != '\0') {
      *(int *)(param_1[0x17] + 0x14) = iVar7;
      *(undefined1 *)((int)param_1 + 0x5a) = 0;
    }
    piVar6 = (int *)param_1[0xb];
    puVar9 = (undefined4 *)((iVar8 - iVar7) + 1);
    if ((int *)param_1[10] <= piVar6 + (int)puVar9) {
      param_1[0xc] = 0x62;
      return CONCAT31((int3)((uint)param_1[10] >> 8),1);
    }
    if ((int)uVar4 < 1) {
      iVar7 = param_1[1] * uVar4;
      param_4 = -1;
      iVar8 = -iVar7;
    }
    else {
      iVar8 = param_1[1] * uVar4;
      param_4 = 1;
      iVar7 = iVar8;
    }
    param_3 = -uVar10;
    param_1 = puVar9;
    if (0 < (int)puVar9) {
      do {
        *piVar6 = param_2;
        param_2 = param_2 + iVar7 / (int)uVar10;
        piVar6 = piVar6 + 1;
        param_3 = param_3 + iVar8 % (int)uVar10;
        if (-1 < (int)param_3) {
          param_3 = param_3 - uVar10;
          param_2 = param_2 + param_4;
        }
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
    }
    puVar1[0xb] = piVar6;
  }
LAB_0041ec0e:
  return param_3 & 0xffffff00;
}



void __cdecl
FUN_0041ec20(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0x5a);
  FUN_0041eaa0(param_1,param_2,-param_3,param_4,-param_5,-param_7,-param_6);
  if ((cVar1 != '\0') && (*(char *)((int)param_1 + 0x5a) == '\0')) {
    *(int *)(param_1[0x17] + 0x14) = -*(int *)(param_1[0x17] + 0x14);
  }
  return;
}



uint __cdecl
FUN_0041ec80(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  param_1[0xe] = param_1 + 0x2f;
  param_1[0x33] = param_1[0x12];
  *(undefined4 *)(param_1[0xe] + 0x14) = param_1[0x13];
  *(undefined4 *)(param_1[0xe] + 8) = param_2;
  *(undefined4 *)(param_1[0xe] + 0xc) = param_3;
  *(undefined4 *)param_1[0xe] = param_4;
  *(undefined4 *)(param_1[0xe] + 4) = param_5;
  do {
    piVar5 = (int *)param_1[0xe];
    iVar8 = piVar5[5];
    iVar1 = piVar5[1];
    iVar2 = *piVar5;
    iVar6 = iVar1;
    iVar7 = iVar8;
    if (iVar8 <= iVar1) {
      iVar6 = iVar8;
      iVar7 = iVar1;
    }
    if ((piVar5[3] < iVar6) || (iVar7 < piVar5[3])) {
      FUN_0041edb0(piVar5);
      piVar5 = (int *)(param_1[0xe] + 0x10);
LAB_0041ed86:
      param_1[0xe] = piVar5;
    }
    else {
      if (iVar8 == iVar1) {
        piVar5 = piVar5 + -4;
        goto LAB_0041ed86;
      }
      iVar8 = (iVar1 <= iVar8) + 1;
      if ((param_1[0x1a] != iVar8) &&
         (((param_1[0x1a] != 0 && (uVar4 = FUN_0041e420((int)param_1), (char)uVar4 != '\0')) ||
          (uVar4 = FUN_0041ea00((int)param_1,iVar8), (char)uVar4 != '\0')))) {
LAB_0041ed52:
        return CONCAT31((int3)(uVar4 >> 8),1);
      }
      if (iVar8 == 1) {
        uVar4 = FUN_0041ee10(param_1,2,FUN_0041edb0,param_1[0x14],param_1[0x15]);
        cVar3 = (char)uVar4;
      }
      else {
        uVar4 = FUN_0041efb0(param_1,2,FUN_0041edb0,param_1[0x14],param_1[0x15]);
        cVar3 = (char)uVar4;
      }
      if (cVar3 != '\0') goto LAB_0041ed52;
    }
    if ((undefined4 *)param_1[0xe] < param_1 + 0x2f) {
      param_1[0x13] = iVar1;
      param_1[0x12] = iVar2;
      return (uint)(param_1 + 0x2f) & 0xffffff00;
    }
  } while( true );
}



void __cdecl FUN_0041edb0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  param_1[8] = param_1[4];
  iVar2 = param_1[2];
  iVar1 = (*param_1 + iVar2) / 2;
  param_1[2] = iVar1;
  iVar2 = (param_1[4] + iVar2) / 2;
  param_1[4] = (iVar1 + iVar2) / 2;
  param_1[9] = param_1[5];
  param_1[6] = iVar2;
  iVar2 = (param_1[1] + param_1[3]) / 2;
  iVar1 = (param_1[5] + param_1[3]) / 2;
  param_1[3] = iVar2;
  param_1[7] = iVar1;
  param_1[5] = (iVar2 + iVar1) / 2;
  return;
}



uint __cdecl
FUN_0041ee10(undefined4 *param_1,int param_2,undefined *param_3,uint param_4,uint param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *local_8;
  
  piVar1 = (int *)param_1[0xe];
  local_8 = (int *)param_1[0xb];
  uVar4 = piVar1[param_2 * 2 + 1];
  piVar5 = local_8;
  if (((int)param_4 <= piVar1[1]) && ((int)uVar4 <= (int)param_5)) {
    uVar2 = -param_1[1] & piVar1[1];
    if ((int)param_5 < (int)uVar2) {
      uVar2 = param_5;
    }
    param_5 = param_4;
    if ((int)param_4 <= (int)uVar4) {
      param_5 = param_1[1] + -1 + uVar4 & -param_1[1];
      uVar4 = (ushort)(*(short *)(param_1 + 1) - 1) & uVar4;
      param_4 = param_5;
      if ((short)uVar4 == 0) {
        if (*(char *)((int)param_1 + 0x5b) != '\0') {
          local_8 = local_8 + -1;
          *(char *)((int)param_1 + 0x5b) = (char)uVar4;
        }
        *local_8 = piVar1[param_2 * 2];
        local_8 = local_8 + 1;
        param_4 = param_5 + param_1[1];
      }
    }
    if (*(char *)((int)param_1 + 0x5a) != '\0') {
      *(int *)(param_1[0x17] + 0x14) = (int)param_5 >> ((byte)*param_1 & 0x1f);
      *(undefined1 *)((int)param_1 + 0x5a) = 0;
    }
    piVar5 = local_8;
    if ((int)param_4 <= (int)uVar2) {
      piVar6 = piVar1;
      if ((int *)param_1[10] <= local_8 + ((int)(uVar2 - param_4) >> ((byte)*param_1 & 0x1f)) + 1) {
        param_1[0xb] = local_8;
        param_1[0xc] = 0x62;
        return CONCAT31((int3)((uint)(param_2 * 8) >> 8),1);
      }
      do {
        if ((int)uVar2 < (int)param_4) break;
        *(undefined1 *)((int)param_1 + 0x5b) = 0;
        uVar4 = piVar6[1];
        if ((int)param_4 < (int)uVar4) {
          iVar3 = uVar4 - piVar6[param_2 * 2 + 1];
          if (iVar3 < (int)param_1[5]) {
            piVar5 = local_8 + 1;
            *local_8 = (int)((*piVar6 - piVar6[param_2 * 2]) * (param_4 - piVar6[param_2 * 2 + 1]))
                       / iVar3 + piVar6[param_2 * 2];
            piVar6 = piVar6 + param_2 * -2;
            param_4 = param_4 + param_1[1];
            local_8 = piVar5;
          }
          else {
            (*(code *)param_3)(piVar6);
            piVar6 = piVar6 + param_2 * 2;
          }
        }
        else {
          if (uVar4 == param_4) {
            *(undefined1 *)((int)param_1 + 0x5b) = 1;
            *piVar5 = *piVar6;
            piVar5 = piVar5 + 1;
            param_4 = param_4 + param_1[1];
            local_8 = piVar5;
          }
          piVar6 = piVar6 + param_2 * -2;
        }
      } while (piVar1 <= piVar6);
    }
  }
  param_1[0xb] = piVar5;
  param_1[0xe] = param_1[0xe] + param_2 * -8;
  return param_2 * 8 & 0xffffff00;
}



void __cdecl
FUN_0041efb0(undefined4 *param_1,int param_2,undefined *param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  
  iVar2 = param_1[0xe];
  *(int *)(iVar2 + 4) = -*(int *)(iVar2 + 4);
  *(int *)(iVar2 + 0xc) = -*(int *)(iVar2 + 0xc);
  *(int *)(iVar2 + 0x14) = -*(int *)(iVar2 + 0x14);
  if (2 < param_2) {
    *(int *)(iVar2 + 0x1c) = -*(int *)(iVar2 + 0x1c);
  }
  cVar1 = *(char *)((int)param_1 + 0x5a);
  FUN_0041ee10(param_1,param_2,param_3,-param_5,-param_4);
  if ((cVar1 != '\0') && (*(char *)((int)param_1 + 0x5a) == '\0')) {
    *(int *)(param_1[0x17] + 0x14) = -*(int *)(param_1[0x17] + 0x14);
  }
  *(int *)(iVar2 + 4) = -*(int *)(iVar2 + 4);
  return;
}



uint __cdecl
FUN_0041f030(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  puVar4 = param_1;
  param_1[0xe] = param_1 + 0x2f;
  param_1[0x35] = param_1[0x12];
  *(undefined4 *)(param_1[0xe] + 0x1c) = param_1[0x13];
  *(int *)(param_1[0xe] + 0x10) = param_2;
  *(undefined4 *)(param_1[0xe] + 0x14) = param_3;
  *(undefined4 *)(param_1[0xe] + 8) = param_4;
  *(undefined4 *)(param_1[0xe] + 0xc) = param_5;
  *(undefined4 *)param_1[0xe] = param_6;
  *(undefined4 *)(param_1[0xe] + 4) = param_7;
  do {
    piVar7 = (int *)puVar4[0xe];
    puVar1 = (undefined4 *)piVar7[7];
    puVar2 = (undefined4 *)piVar7[1];
    iVar3 = *piVar7;
    iVar9 = piVar7[5];
    iVar10 = piVar7[3];
    param_1 = puVar2;
    param_2 = (int)puVar1;
    if ((int)puVar1 <= (int)puVar2) {
      param_1 = puVar1;
      param_2 = (int)puVar2;
    }
    iVar8 = iVar9;
    if (iVar9 <= iVar10) {
      iVar8 = iVar10;
      iVar10 = iVar9;
    }
    if ((iVar10 < (int)param_1) || (param_2 < iVar8)) {
      FUN_0041f190(piVar7);
      piVar7 = (int *)(puVar4[0xe] + 0x18);
LAB_0041f16a:
      puVar4[0xe] = piVar7;
    }
    else {
      if (puVar1 == puVar2) {
        piVar7 = piVar7 + -6;
        goto LAB_0041f16a;
      }
      iVar9 = ((int)puVar2 < (int)puVar1) + 1;
      if ((puVar4[0x1a] != iVar9) &&
         (((puVar4[0x1a] != 0 && (uVar6 = FUN_0041e420((int)puVar4), (char)uVar6 != '\0')) ||
          (uVar6 = FUN_0041ea00((int)puVar4,iVar9), (char)uVar6 != '\0')))) {
LAB_0041f136:
        return CONCAT31((int3)(uVar6 >> 8),1);
      }
      if (iVar9 == 1) {
        uVar6 = FUN_0041ee10(puVar4,3,FUN_0041f190,puVar4[0x14],puVar4[0x15]);
        cVar5 = (char)uVar6;
      }
      else {
        uVar6 = FUN_0041efb0(puVar4,3,FUN_0041f190,puVar4[0x14],puVar4[0x15]);
        cVar5 = (char)uVar6;
      }
      if (cVar5 != '\0') goto LAB_0041f136;
    }
    if ((undefined4 *)puVar4[0xe] < puVar4 + 0x2f) {
      puVar4[0x13] = puVar2;
      puVar4[0x12] = iVar3;
      return (uint)(puVar4 + 0x2f) & 0xffffff00;
    }
  } while( true );
}



void __cdecl FUN_0041f190(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1[0xc] = param_1[6];
  iVar2 = param_1[6] + 1 + param_1[4] >> 1;
  param_1[10] = iVar2;
  iVar1 = *param_1 + 1 + param_1[2] >> 1;
  iVar3 = param_1[4] + 1 + param_1[2] >> 1;
  iVar2 = iVar2 + 1 + iVar3 >> 1;
  param_1[2] = iVar1;
  param_1[8] = iVar2;
  iVar1 = iVar1 + 1 + iVar3 >> 1;
  param_1[6] = iVar2 + 1 + iVar1 >> 1;
  param_1[4] = iVar1;
  param_1[0xd] = param_1[7];
  iVar2 = param_1[7] + 1 + param_1[5] >> 1;
  iVar1 = param_1[1] + 1 + param_1[3] >> 1;
  param_1[0xb] = iVar2;
  iVar3 = param_1[5] + 1 + param_1[3] >> 1;
  param_1[3] = iVar1;
  iVar2 = iVar2 + 1 + iVar3 >> 1;
  iVar1 = iVar1 + 1 + iVar3 >> 1;
  param_1[9] = iVar2;
  param_1[5] = iVar1;
  param_1[7] = iVar2 + 1 + iVar1 >> 1;
  return;
}



uint __cdecl FUN_0041f220(undefined4 *param_1)

{
  ushort uVar1;
  short sVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  uint uVar12;
  uint **ppuVar13;
  uint *local_28;
  uint *local_24;
  uint uStack_20;
  uint local_1c;
  int *local_18;
  uint *puStack_14;
  int local_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  FUN_0041f590(&local_18);
  FUN_0041f590(&local_28);
  FUN_0041f590(&local_24);
  local_10 = (int)param_1[0x14] >> ((byte)*param_1 & 0x1f);
  local_1c = (int)param_1[0x15] >> ((byte)*param_1 & 0x1f);
  piVar11 = (int *)param_1[0x18];
  while (piVar11 != (int *)0x0) {
    piVar4 = (int *)piVar11[1];
    uVar1 = *(ushort *)(piVar11 + 5);
    iVar7 = (ushort)((short)piVar11[4] + uVar1) - 1;
    if ((short)uVar1 < (short)local_1c) {
      local_1c = (uint)uVar1;
    }
    if ((short)local_10 < (short)iVar7) {
      local_10 = iVar7;
    }
    *piVar11 = 0;
    FUN_0041f5a0((int *)&local_18,piVar11);
    piVar11 = piVar4;
  }
  if (param_1[0xd] == 0) {
    param_1[0xc] = 0x14;
    return 1;
  }
  (*(code *)param_1[0x2a])(param_1,&local_1c,&local_10);
  for (piVar11 = local_18; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[1]) {
    piVar11[6] = (uint)(ushort)((short)piVar11[5] - (short)local_1c);
  }
  iVar7 = param_1[0xd];
  if ((0 < iVar7) && (*(int *)(param_1[9] + iVar7 * -4) == (int)(short)local_1c)) {
    param_1[0xd] = iVar7 + -1;
  }
  iVar7 = 0;
  uStack_20 = local_1c;
  uVar9 = local_1c;
  piVar4 = local_18;
  piVar11 = (int *)param_1[0xd];
  do {
    if ((int)piVar11 < 1) {
      if ((short)uVar9 <= (short)local_10) {
        do {
          piVar4 = (int *)(*(code *)param_1[0x2d])(param_1);
          uVar9 = uVar9 + 1;
        } while ((short)uVar9 <= (short)local_10);
      }
      return (uint)piVar4 & 0xffffff00;
    }
    if (local_18 != (int *)0x0) {
      piVar11 = local_18;
      do {
        piVar4 = (int *)piVar11[1];
        iVar5 = piVar11[6] - (int)(short)iVar7;
        piVar11[6] = iVar5;
        if (iVar5 == 0) {
          FUN_0041f5d0((int *)&local_18,(int)piVar11);
          if (piVar11[3] == -1) {
            ppuVar13 = &local_24;
          }
          else {
            if (piVar11[3] != 1) goto LAB_0041f3ae;
            ppuVar13 = &local_28;
          }
          FUN_0041f5a0((int *)ppuVar13,piVar11);
        }
LAB_0041f3ae:
        piVar11 = piVar4;
      } while (piVar4 != (int *)0x0);
    }
    FUN_0041f600((int *)&local_28);
    FUN_0041f600((int *)&local_24);
    sVar2 = *(short *)(param_1[9] + param_1[0xd] * -4);
    iStack_4 = (int)sVar2;
    param_1[0xd] = param_1[0xd] + -1;
    iStack_8 = iStack_4 - uStack_20;
    puVar10 = local_28;
    uVar8 = uStack_20;
    if ((short)uStack_20 < sVar2) {
      do {
        iStack_c = 0;
        puStack_14 = local_24;
        puVar10 = local_28;
        if (local_28 != (uint *)0x0) {
          do {
            uVar9 = *puVar10;
            uVar8 = *puStack_14;
            uVar6 = uVar9;
            if ((int)uVar8 < (int)uVar9) {
              uVar6 = uVar8;
              uVar8 = uVar9;
            }
            iVar7 = param_1[1];
            if (iVar7 < (int)(uVar8 - uVar6)) {
LAB_0041f484:
              (*(code *)param_1[0x2b])(param_1,uStack_20,uVar6,uVar8,puVar10,puStack_14);
            }
            else {
              uVar12 = (uVar8 - 1) + iVar7 & -iVar7;
              uVar9 = -iVar7 & uVar6;
              if ((*(char *)(param_1 + 0x2e) == '\0') ||
                 (((int)uVar9 <= (int)uVar12 && (uVar12 != iVar7 + uVar9)))) goto LAB_0041f484;
              *puVar10 = uVar6;
              *puStack_14 = uVar8;
              iStack_c = iStack_c + 1;
              puVar10[6] = 1;
            }
            puVar3 = puVar10 + 1;
            puStack_14 = (uint *)puStack_14[1];
            puVar10 = (uint *)*puVar3;
          } while ((uint *)*puVar3 != (uint *)0x0);
          puVar10 = local_28;
          puVar3 = local_24;
          if (0 < (short)iStack_c) {
            for (; puVar10 != (uint *)0x0; puVar10 = (uint *)puVar10[1]) {
              if (puVar10[6] != 0) {
                puVar10[6] = 0;
                (*(code *)param_1[0x2c])(param_1,uStack_20,*puVar10,*puVar3,puVar10,puVar3);
              }
              puVar3 = (uint *)puVar3[1];
            }
          }
        }
        (*(code *)param_1[0x2d])(param_1);
        uStack_20 = uStack_20 + 1;
        puVar10 = local_28;
        uVar8 = uStack_20;
        if ((short)iStack_4 <= (short)uStack_20) break;
        FUN_0041f600((int *)&local_28);
        FUN_0041f600((int *)&local_24);
      } while( true );
    }
    while (puVar3 = puVar10, uVar9 = uStack_20, uStack_20 = uVar8, puVar10 = local_24,
          puVar3 != (uint *)0x0) {
      puVar10 = (uint *)puVar3[1];
      uStack_20 = uVar9;
      if (puVar3[4] == 0) {
        uStack_20 = uVar8;
        FUN_0041f5d0((int *)&local_28,(int)puVar3);
        uVar8 = uStack_20;
        uStack_20 = uVar9;
      }
    }
    while (puVar3 = puVar10, puVar3 != (uint *)0x0) {
      puVar10 = (uint *)puVar3[1];
      if (puVar3[4] == 0) {
        FUN_0041f5d0((int *)&local_24,(int)puVar3);
      }
    }
    piVar4 = (int *)param_1[0xd];
    iVar7 = iStack_8;
    piVar11 = piVar4;
  } while( true );
}



void __cdecl FUN_0041f590(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}



void __cdecl FUN_0041f5a0(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while ((piVar1 != (int *)0x0 && (*piVar1 <= *param_2))) {
    param_1 = piVar1 + 1;
    piVar1 = (int *)*param_1;
  }
  param_2[1] = (int)piVar1;
  *param_1 = (int)param_2;
  return;
}



void __cdecl FUN_0041f5d0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    while (iVar1 != param_2) {
      param_1 = (int *)(iVar1 + 4);
      iVar1 = *param_1;
      if (iVar1 == 0) {
        return;
      }
    }
    *param_1 = *(int *)(iVar1 + 4);
  }
  return;
}



void __cdecl FUN_0041f600(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    *puVar1 = *(undefined4 *)puVar1[2];
    puVar1[2] = (undefined4 *)puVar1[2] + puVar1[3];
    puVar1[4] = puVar1[4] + -1;
  }
  piVar4 = (int *)*param_1;
  if (piVar4 != (int *)0x0) {
    piVar2 = (int *)piVar4[1];
    piVar3 = param_1;
    while (piVar2 != (int *)0x0) {
      piVar5 = piVar4 + 1;
      if (*piVar2 < *piVar4) {
        *piVar3 = (int)piVar2;
        *piVar5 = piVar2[1];
        piVar2[1] = (int)piVar4;
        piVar4 = (int *)*param_1;
        piVar5 = param_1;
      }
      else {
        piVar4 = (int *)*piVar5;
        if (piVar4 == (int *)0x0) {
          return;
        }
      }
      piVar3 = piVar5;
      piVar2 = (int *)piVar4[1];
    }
  }
  return;
}



undefined4 FUN_0041f670(void)

{
  return 0x13;
}



uint __cdecl FUN_0041f890(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  size_t _Count;
  byte *pbVar8;
  int iVar9;
  bool bVar10;
  byte local_40 [64];
  
  bVar1 = *param_1;
  bVar2 = bVar1;
  pbVar8 = param_1;
  if (((bVar1 == 0x75) && (param_1[1] == 0x6e)) && (param_1[2] == 0x69)) {
    uVar3 = 0;
    pbVar7 = param_1 + 3;
    iVar9 = 4;
    do {
      uVar6 = (uint)*pbVar7;
      uVar5 = uVar6 - 0x30;
      if (9 < uVar5) {
        if (5 < uVar6 - 0x41) break;
        uVar5 = uVar6 - 0x37;
      }
      if (0xf < uVar5) break;
      uVar3 = uVar3 * 0x10 + uVar5;
      iVar9 = iVar9 + -1;
      pbVar7 = pbVar7 + 1;
    } while (0 < iVar9);
    if (iVar9 == 0) {
      return uVar3;
    }
  }
  while ((bVar2 != 0 && (bVar2 != 0x2e))) {
    bVar2 = pbVar8[1];
    pbVar8 = pbVar8 + 1;
  }
  _Count = (int)pbVar8 - (int)param_1;
  if ((*pbVar8 != 0) && ((int)_Count < 0x40)) {
    strncpy((char *)local_40,(char *)param_1,_Count);
    local_40[_Count] = 0;
    param_1 = local_40;
  }
  iVar9 = 0;
  do {
    pbVar8 = (&PTR_s__notdef_004313c0)[iVar9];
    pbVar7 = param_1;
    if (bVar1 == *pbVar8) {
      do {
        bVar2 = *pbVar7;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_0041f974:
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0041f979;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar7[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_0041f974;
        pbVar8 = pbVar8 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0041f979:
      if (iVar4 == 0) {
        return (uint)(ushort)(&DAT_00432658)[iVar9];
      }
    }
    iVar9 = iVar9 + 1;
    if (0x421 < iVar9) {
      return 0;
    }
  } while( true );
}



int __cdecl FUN_0041f9b0(int param_1,uint param_2,int param_3,size_t *param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  size_t _NumOfElements;
  size_t *psVar6;
  
  *param_4 = 0;
  psVar6 = param_4 + 1;
  *psVar6 = 0;
  iVar2 = FUN_00410c90(param_1,param_2 << 3,psVar6);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = 0;
  puVar5 = (uint *)*psVar6;
  if (param_2 != 0) {
    do {
      pbVar1 = *(byte **)(param_3 + uVar4 * 4);
      if (((pbVar1 != (byte *)0x0) && (uVar3 = FUN_0041f890(pbVar1), uVar3 != 0)) &&
         (uVar3 != 0xffff)) {
        *puVar5 = uVar3;
        puVar5[1] = uVar4;
        puVar5 = puVar5 + 2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  _NumOfElements = (int)((int)puVar5 - *psVar6) >> 3;
  iVar2 = 0;
  if ((_NumOfElements == 0) ||
     (iVar2 = FUN_00410ce0(param_1,param_2 << 3,_NumOfElements * 8,(int *)psVar6), iVar2 == 0)) {
    if (_NumOfElements != 0) {
      qsort((void *)*psVar6,_NumOfElements,8,FUN_0041faa0);
      goto LAB_0041fa92;
    }
  }
  else {
    _NumOfElements = 0;
  }
  FUN_00410d70(param_1,(int *)psVar6);
  if (iVar2 == 0) {
    *param_4 = _NumOfElements;
    return 6;
  }
LAB_0041fa92:
  *param_4 = _NumOfElements;
  return iVar2;
}



int __cdecl FUN_0041faa0(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}



int __cdecl FUN_0041fcb0(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_1;
  iVar1 = param_1[8];
  param_1 = (int *)*param_1;
  iVar3 = FUN_00410c90(iVar1,param_2,piVar2);
  if (iVar3 == 0) {
    if (param_1 != (int *)0x0) {
      uVar5 = piVar2[2];
      piVar6 = param_1;
      piVar7 = (int *)*piVar2;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)piVar7 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        piVar7 = (int *)((int)piVar7 + 1);
      }
      FUN_0041fd20(piVar2,(int)param_1);
      FUN_00410d70(iVar1,(int *)&param_1);
    }
    piVar2[2] = param_2;
    iVar3 = 0;
  }
  return iVar3;
}



void __cdecl FUN_0041fd20(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)param_1[6];
  iVar2 = *param_1;
  piVar1 = piVar3 + param_1[4];
  for (; piVar3 < piVar1; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      *piVar3 = *piVar3 + (iVar2 - param_2);
    }
  }
  return;
}



void __cdecl FUN_0041fd50(int *param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  
  piVar3 = param_1;
  iVar2 = param_1[8];
  if ((int *)*param_1 != (int *)0x0) {
    puVar1 = (uint *)(param_1 + 1);
    param_1 = (int *)*param_1;
    iVar4 = FUN_00410c90(iVar2,*puVar1,piVar3);
    if (iVar4 == 0) {
      uVar6 = piVar3[1];
      piVar7 = param_1;
      piVar8 = (int *)*piVar3;
      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar8 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar8 = piVar8 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)piVar8 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar8 = (int *)((int)piVar8 + 1);
      }
      FUN_0041fd20(piVar3,(int)param_1);
      piVar3[2] = piVar3[1];
      FUN_00410d70(iVar2,(int *)&param_1);
    }
  }
  return;
}



void __cdecl FUN_0041fdc0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[8];
  if (param_1[3] == -0x21524111) {
    FUN_00410d70(iVar1,param_1);
    FUN_00410d70(iVar1,param_1 + 6);
    FUN_00410d70(iVar1,param_1 + 7);
    param_1[3] = 0;
  }
  return;
}



void __cdecl FUN_0041fe00(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  
  for (pcVar2 = (char *)*param_1;
      (pcVar2 < (char *)param_1[2] &&
      ((((cVar1 = *pcVar2, cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\r')) || (cVar1 == '\n')))
      ); pcVar2 = pcVar2 + 1) {
  }
  *param_1 = pcVar2;
  return;
}



void __cdecl FUN_0041fe60(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
  param_2[2] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  FUN_0041fe00(param_1);
  pcVar3 = (char *)*param_1;
  pcVar2 = (char *)param_1[2];
  if (pcVar2 <= pcVar3) {
    return;
  }
  cVar4 = *pcVar3;
  if (cVar4 == '(') {
    param_2[2] = 2;
    cVar4 = ')';
  }
  else if (cVar4 == '[') {
    param_2[2] = 3;
    cVar4 = ']';
  }
  else {
    if (cVar4 != '{') {
      *param_2 = pcVar3;
      pcVar3 = pcVar3 + 1;
      param_2[2] = 1;
      if (pcVar3 < pcVar2) {
        while (((cVar4 = *pcVar3, cVar4 != ' ' && (cVar4 != '\t')) && (cVar4 != '\r'))) {
          if ((cVar4 == '\n') || (pcVar3 = pcVar3 + 1, pcVar2 <= pcVar3)) break;
        }
      }
      param_2[1] = pcVar3;
      goto LAB_0041ff1d;
    }
    param_2[2] = 3;
    cVar4 = '}';
  }
  cVar1 = *pcVar3;
  pcVar3 = pcVar3 + 1;
  iVar5 = 1;
  *param_2 = pcVar3;
  for (; pcVar3 < pcVar2; pcVar3 = pcVar3 + 1) {
    if (*pcVar3 == cVar1) {
      iVar5 = iVar5 + 1;
    }
    else if ((*pcVar3 == cVar4) && (iVar5 = iVar5 + -1, iVar5 < 1)) {
      param_2[1] = pcVar3;
      pcVar3 = pcVar3 + 1;
      break;
    }
  }
LAB_0041ff1d:
  if (param_2[1] == 0) {
    *param_2 = 0;
    param_2[2] = 0;
  }
  *param_1 = pcVar3;
  return;
}



void __cdecl FUN_0041ff40(uint *param_1,uint *param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  *param_4 = -1;
  FUN_0041fe60(param_1,&local_c);
  if (local_4 == 3) {
    uVar1 = param_1[2];
    uVar2 = *param_1;
    *param_1 = local_c;
    param_1[2] = local_8;
    puVar3 = param_2;
    if (local_c < local_8) {
      do {
        FUN_0041fe60(param_1,&local_c);
        if (local_4 == 0) break;
        if (puVar3 < param_2 + param_3 * 3) {
          *puVar3 = local_c;
          puVar3[1] = local_8;
          puVar3[2] = local_4;
        }
        puVar3 = puVar3 + 3;
      } while (*param_1 < param_1[2]);
    }
    *param_4 = ((int)puVar3 - (int)param_2) / 0xc;
    *param_1 = uVar2;
    param_1[2] = uVar1;
  }
  return;
}



int __cdecl FUN_00420010(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  char *local_8;
  int local_4;
  
  FUN_0041fe60(param_1,&local_c);
  if (local_4 != 0) {
    iVar1 = 0;
    local_10 = (undefined4 *)0x1;
    local_14 = local_c;
    if (local_4 == 3) {
      if (param_4 == (undefined4 *)0x0) {
        return 3;
      }
      local_10 = param_4;
      iVar1 = 1;
    }
    piVar2 = (int *)(param_3 + iVar1 * 4);
    do {
      piVar5 = (int *)(*piVar2 + *(int *)(param_2 + 0x10));
      switch(*(undefined4 *)(param_2 + 8)) {
      case 1:
        iVar1 = FUN_00420320(&local_14,local_8);
        break;
      case 2:
        iVar1 = FUN_00420180(&local_14,local_8);
        break;
      case 3:
        iVar1 = FUN_004201e0((uint *)&local_14,local_8,3);
        break;
      case 4:
        uVar4 = (int)local_8 - (int)local_14;
        if (*piVar5 == 0) {
          iVar1 = FUN_00410c90(param_1[4],uVar4 + 1,&param_4);
          if (iVar1 != 0) {
            return iVar1;
          }
          puVar6 = local_14;
          puVar7 = param_4;
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          *(undefined1 *)((int)param_4 + uVar4) = 0;
          *piVar5 = (int)param_4;
        }
        goto LAB_00420139;
      default:
        goto switchD_0042008a_default;
      }
      if (*(char *)(param_2 + 0x14) == '\x01') {
        *(char *)piVar5 = (char)iVar1;
      }
      else if (*(char *)(param_2 + 0x14) == '\x02') {
        *(short *)piVar5 = (short)iVar1;
      }
      else {
        *piVar5 = iVar1;
      }
LAB_00420139:
      local_10 = (undefined4 *)((int)local_10 + -1);
      piVar2 = piVar2 + 1;
      if (local_10 == (undefined4 *)0x0) {
        return 0;
      }
    } while( true );
  }
switchD_0042008a_default:
  return 3;
}



int __cdecl FUN_00420180(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = (char *)*param_1;
  iVar3 = 0;
  if (pcVar4 < param_2) {
    while ((cVar1 = *pcVar4, 9 < (byte)(cVar1 - 0x30U) && (pcVar4 = pcVar4 + 1, cVar1 != '-'))) {
      if (param_2 <= pcVar4) {
        *param_1 = pcVar4;
        return iVar3;
      }
    }
    if (pcVar4 < param_2) {
      do {
        cVar2 = *pcVar4;
        if (9 < (byte)(cVar2 - 0x30U)) break;
        pcVar4 = pcVar4 + 1;
        iVar3 = (uint)(byte)(cVar2 - 0x30U) + iVar3 * 10;
      } while (pcVar4 < param_2);
      if (cVar1 == '-') {
        iVar3 = -iVar3;
      }
    }
  }
  *param_1 = pcVar4;
  return iVar3;
}



int __cdecl FUN_004201e0(uint *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *local_8;
  uint local_4;
  
  local_8 = (char *)*param_1;
  uVar5 = 0;
  if (param_2 <= local_8) {
    return 0;
  }
  cVar2 = *local_8;
  uVar7 = 1;
  if (cVar2 == '-') {
    local_8 = local_8 + 1;
  }
  local_4 = (uint)(cVar2 == '-');
  if (*local_8 == '.') {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00420180(&local_8,param_2);
    iVar3 = iVar3 << 0x10;
  }
  pcVar6 = local_8;
  if (local_8 < param_2) {
    if ((*local_8 == '.') && (pcVar1 = local_8 + 1, pcVar1 < param_2)) {
      cVar2 = *pcVar1;
      pcVar6 = pcVar1;
      while ((byte)(cVar2 - 0x30U) < 10) {
        if ((int)uVar7 < 10000000) {
          uVar5 = (uint)(byte)(cVar2 - 0x30U) + uVar5 * 10;
          uVar7 = uVar7 * 10;
        }
        pcVar6 = pcVar6 + 1;
        if (param_2 <= pcVar6) break;
        cVar2 = *pcVar6;
      }
    }
    if ((pcVar6 + 1 < param_2) && ((*pcVar6 == 'e' || (*pcVar6 == 'E')))) {
      local_8 = pcVar6 + 1;
      iVar4 = FUN_00420180(&local_8,param_2);
      param_3 = param_3 + iVar4;
      pcVar6 = local_8;
    }
  }
  if (param_3 < 1) {
    if (param_3 < 0) {
      iVar4 = -param_3;
      do {
        iVar3 = iVar3 / 10;
        uVar7 = uVar7 * 10;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else {
    do {
      iVar3 = iVar3 * 10;
      uVar5 = uVar5 * 10;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  if (uVar5 != 0) {
    uVar5 = FUN_00410c00(uVar5,uVar7);
    iVar3 = iVar3 + uVar5;
  }
  if (local_4 != 0) {
    iVar3 = -iVar3;
  }
  *param_1 = (uint)pcVar6;
  return iVar3;
}



undefined4 __cdecl FUN_00420320(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)*param_1;
  pcVar1 = pcVar2 + 3;
  if ((((pcVar1 < param_2) && (*pcVar2 == 't')) && (pcVar2[1] == 'r')) &&
     ((pcVar2[2] == 'u' && (*pcVar1 == 'e')))) {
    *param_1 = pcVar2 + 5;
    return 1;
  }
  if ((((pcVar2 + 4 < param_2) && ((*pcVar2 == 'f' && (pcVar2[1] == 'a')))) && (pcVar2[2] == 'l'))
     && ((*pcVar1 == 's' && (pcVar2[4] == 'e')))) {
    pcVar2 = pcVar2 + 6;
  }
  *param_1 = pcVar2;
  return 0;
}



int __cdecl FUN_004204e0(undefined4 *param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *local_4;
  
  local_4 = (char *)*param_1;
  iVar4 = 0;
  if (param_2 <= local_4) goto LAB_00420562;
  cVar3 = '\0';
  if (*local_4 == '[') {
    cVar3 = ']';
LAB_0042050d:
    local_4 = local_4 + 1;
  }
  else if (*local_4 == '{') {
    cVar3 = '}';
    goto LAB_0042050d;
  }
  while (local_4 < param_2) {
    cVar1 = *local_4;
    if ((cVar1 == ' ') || (cVar1 == '\t')) {
      local_4 = local_4 + 1;
    }
    else {
      if ((param_3 <= iVar4) || (cVar1 == cVar3)) break;
      iVar2 = FUN_004201e0((uint *)&local_4,param_2,0);
      *(short *)(param_4 + iVar4 * 2) = (short)((uint)iVar2 >> 0x10);
      iVar4 = iVar4 + 1;
      if (cVar3 == '\0') break;
    }
  }
LAB_00420562:
  *param_1 = local_4;
  return iVar4;
}



int __cdecl FUN_004205a0(undefined4 *param_1,char *param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *local_4;
  
  local_4 = (char *)*param_1;
  iVar4 = 0;
  if (param_2 <= local_4) goto LAB_00420620;
  cVar3 = '\0';
  if (*local_4 == '[') {
    cVar3 = ']';
LAB_004205cd:
    local_4 = local_4 + 1;
  }
  else if (*local_4 == '{') {
    cVar3 = '}';
    goto LAB_004205cd;
  }
  while (local_4 < param_2) {
    cVar1 = *local_4;
    if ((cVar1 == ' ') || (cVar1 == '\t')) {
      local_4 = local_4 + 1;
    }
    else {
      if ((param_3 <= iVar4) || (cVar1 == cVar3)) break;
      iVar2 = FUN_004201e0((uint *)&local_4,param_2,param_5);
      *(int *)(param_4 + iVar4 * 4) = iVar2;
      iVar4 = iVar4 + 1;
      if (cVar3 == '\0') break;
    }
  }
LAB_00420620:
  *param_1 = local_4;
  return iVar4;
}



void __cdecl FUN_00420670(undefined4 *param_1,int param_2,int param_3,int param_4,char param_5)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 0x51) = 1;
  param_1[1] = param_2;
  param_1[2] = param_4;
  *param_1 = *(undefined4 *)(param_2 + 100);
  if (param_4 != 0) {
    iVar1 = **(int **)(param_4 + 0x94);
    param_1[3] = iVar1;
    param_1[4] = iVar1 + 0x14;
    param_1[5] = iVar1 + 0x34;
    FUN_00410dd0(iVar1);
    param_1[0x18] = *(undefined4 *)(param_3 + 0x28);
    param_1[0x17] = 0;
    if (param_5 != '\0') {
      param_1[0x17] = *(undefined4 *)(*(int *)(param_4 + 0x94) + 0x20);
    }
  }
  if (param_3 != 0) {
    param_1[8] = *(undefined4 *)(param_3 + 0x10);
    param_1[9] = *(undefined4 *)(param_3 + 0x14);
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  ppuVar2 = &PTR_FUN_00433330;
  puVar3 = param_1 + 0x19;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppuVar2;
    ppuVar2 = ppuVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



void __cdecl FUN_00420710(int param_1,int param_2)

{
  FUN_00410f10(*(int **)(param_1 + 0xc),param_2,0);
  return;
}



void __cdecl FUN_00420730(int param_1,int param_2,int param_3,char param_4)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(char *)(param_1 + 0x51) != '\0') {
    sVar2 = *(short *)(iVar3 + 2);
    iVar4 = *(int *)(iVar3 + 8);
    piVar1 = (int *)(*(int *)(iVar3 + 4) + sVar2 * 8);
    if (*(char *)(param_1 + 0x53) != '\0') {
      param_2 = param_2 >> 0x10;
      param_3 = param_3 >> 0x10;
    }
    *piVar1 = param_2;
    piVar1[1] = param_3;
    *(char *)(iVar4 + sVar2) = (param_4 == '\0') + '\x01';
    *(int *)(param_1 + 0x18) = *piVar1;
    *(int *)(param_1 + 0x1c) = piVar1[1];
  }
  *(short *)(iVar3 + 2) = *(short *)(iVar3 + 2) + 1;
  return;
}



int __cdecl FUN_00420790(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00420710(param_1,1);
  if (iVar1 == 0) {
    FUN_00420730(param_1,param_2,param_3,'\x01');
  }
  return iVar1;
}



int __cdecl FUN_004207d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(param_1 + 0x50) == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 1;
    iVar1 = FUN_004282c0(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_00420790(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



void __cdecl FUN_00420810(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    bVar1 = *param_1;
    *param_1 = (byte)((uint)param_3 >> 8) ^ bVar1;
    param_3 = ((uint)bVar1 + param_3) * -0x3193 + 0x58bf;
    param_1 = param_1 + 1;
  }
  return;
}



int __cdecl FUN_00421430(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_4;
  
  iVar9 = param_3 + *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x560) != 0) {
    uVar5 = FUN_00421590(param_1,param_5);
    uVar6 = FUN_00421590(param_1,param_6);
    if ((-1 < (int)uVar5) && (-1 < (int)uVar6)) {
      if (*(char *)(param_1 + 0x52) != '\0') {
        iVar8 = *(int *)(param_1 + 8);
        piVar1 = (int *)**(undefined4 **)(iVar8 + 0x94);
        iVar7 = FUN_00410ff0(piVar1,2);
        if (iVar7 != 0) {
          return iVar7;
        }
        puVar2 = (uint *)piVar1[0x13];
        puVar2[2] = 0;
        puVar2[3] = 0;
        *puVar2 = uVar5;
        *(undefined2 *)(puVar2 + 1) = 0x202;
        puVar2[8] = uVar6;
        puVar2[10] = iVar9 - param_2;
        puVar2[0xb] = param_4;
        *(undefined2 *)(puVar2 + 9) = 2;
        *(undefined4 *)(iVar8 + 0x80) = 2;
        *(int *)(iVar8 + 0x84) = piVar1[0xb];
        *(undefined4 *)(iVar8 + 0x48) = 0x636f6d70;
        piVar1[0x12] = 2;
        return 0;
      }
      FUN_00411070(*(int *)(param_1 + 0xc));
      iVar8 = FUN_00421630(param_1);
      if (iVar8 != 0) {
        return iVar8;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x3c);
      uVar4 = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(uint *)(param_1 + 0x28) = iVar9 - uVar5;
      *(int *)(param_1 + 0x2c) = param_5;
      iVar9 = FUN_00421630(param_1);
      if (iVar9 != 0) {
        return iVar9;
      }
      *(uint *)(param_1 + 0x34) = uVar6;
      *(undefined4 *)(param_1 + 0x30) = uVar4;
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x38) = uVar3;
      *(undefined4 *)(param_1 + 0x3c) = uStack_4;
      return 0;
    }
  }
  return 0xa0;
}



uint __cdecl FUN_00421590(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  uint uVar7;
  bool bVar8;
  
  if ((-1 < param_2) && (param_2 < 0x100)) {
    pbVar2 = (byte *)(**(code **)(*(int *)(param_1 + 0x558) + 0x10))
                               (*(undefined2 *)
                                 (*(int *)(*(int *)(param_1 + 0x558) + 0x14) + param_2 * 2));
    uVar7 = 0;
    if (*(uint *)(param_1 + 0x55c) != 0) {
      puVar5 = *(undefined4 **)(param_1 + 0x560);
      do {
        pbVar3 = (byte *)*puVar5;
        if ((pbVar3 != (byte *)0x0) && (pbVar6 = pbVar2, *pbVar3 == *pbVar2)) {
          do {
            bVar1 = *pbVar3;
            bVar8 = bVar1 < *pbVar6;
            if (bVar1 != *pbVar6) {
LAB_00421604:
              iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_00421609;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar8 = bVar1 < pbVar6[1];
            if (bVar1 != pbVar6[1]) goto LAB_00421604;
            pbVar3 = pbVar3 + 2;
            pbVar6 = pbVar6 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_00421609:
          if (iVar4 == 0) {
            return uVar7;
          }
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar7 < *(uint *)(param_1 + 0x55c));
    }
  }
  return 0xffffffff;
}



void FUN_00421630(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00421638. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(param_1 + 0x5d0))();
  return;
}



undefined4 __cdecl
FUN_00421640(undefined4 *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,char param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x178; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00411770(*(int *)(*(int *)(param_2 + 0x60) + 4),(byte *)s_psnames_0043eb94);
  if (iVar1 == 0) {
    return 7;
  }
  param_1[0x156] = iVar1;
  FUN_00420670(param_1,param_2,param_3,param_4,param_7);
  param_1[0x157] = *(undefined4 *)(param_2 + 0x10);
  param_1[0x158] = param_5;
  param_1[0x173] = param_6;
  param_1[0x174] = param_8;
  param_1[0x175] = FUN_00421640;
  param_1[0x176] = &LAB_004216e0;
  param_1[0x177] = &LAB_00420850;
  return 0;
}



void __cdecl FUN_004216f0(byte *param_1,int param_2)

{
  if (-1 < param_2 + -1) {
    do {
      *param_1 = (&DAT_00433400)[*param_1];
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}



void __cdecl FUN_00421710(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (0 < param_2) {
    iVar2 = (param_2 - 1U >> 1) + 1;
    do {
      uVar1 = *param_1;
      *param_1 = param_1[1];
      param_1[1] = uVar1;
      param_1 = param_1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



void __cdecl FUN_00421740(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (0 < param_2) {
    iVar2 = (param_2 - 1U >> 2) + 1;
    do {
      uVar1 = *param_1;
      *param_1 = param_1[3];
      param_1[3] = uVar1;
      uVar1 = param_1[1];
      param_1[1] = param_1[2];
      param_1[2] = uVar1;
      param_1 = param_1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



undefined4 __cdecl FUN_00421780(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0xf0);
  iVar2 = *(int *)(param_1 + 100);
  FUN_00410d70(iVar2,(int *)(param_1 + 0x100));
  FUN_00410d70(iVar2,(int *)(param_1 + 0xf8));
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xec)) {
    do {
      FUN_00410d70(iVar2,piVar1);
      if ((char)piVar1[1] != '\0') {
        FUN_00410d70(iVar2,piVar1 + 2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xec));
  }
  FUN_00410d70(iVar2,(int *)(param_1 + 0xf0));
  return 0;
}



int __cdecl FUN_00421840(int *param_1,byte *param_2)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  
  iVar10 = *(int *)(param_2 + 100);
  iVar4 = FUN_00421be0(param_1,(int)param_2);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = FUN_00421d90(param_1,(int)param_2);
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar5 = FUN_00421cd0(*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),0x100);
  if ((((((char)uVar5 == '\0') && (uVar6 = FUN_00422800(param_1,(uint)param_2,2), uVar6 != 0)) ||
       (iVar4 = FUN_00422140(param_1,param_2), iVar4 != 0)) ||
      ((iVar4 = FUN_004223a0(param_1,(int)param_2), iVar4 != 0 ||
       (iVar4 = FUN_00422580(param_1,(int)param_2), iVar4 != 0)))) ||
     (((char)uVar5 != '\0' && (uVar5 = FUN_00422800(param_1,(uint)param_2,0x100), uVar5 != 0))))
  goto LAB_00421b77;
  bVar3 = param_2[0x9b];
  param_2[0] = 1;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0x92;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  if (bVar3 != 0) {
    param_2[8] = 0x96;
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
  }
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  puVar7 = FUN_00421d00((int)param_2,(byte *)s_SLANT_00441904);
  if (((puVar7 != (undefined4 *)0x0) && (*(char *)(puVar7 + 1) != '\0')) &&
     ((*(char *)puVar7[2] == 'O' || (*(char *)puVar7[2] == 'I')))) {
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 1;
  }
  puVar7 = FUN_00421d00((int)param_2,(byte *)s_WEIGHT_NAME_004418f8);
  if (((puVar7 != (undefined4 *)0x0) && (*(char *)(puVar7 + 1) != '\0')) &&
     (*(char *)puVar7[2] == 'B')) {
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 2;
  }
  uVar5 = *(uint *)(param_2 + 0xc);
  *(char **)(param_2 + 0x18) = s_Regular_0043e944;
  if ((uVar5 & 2) == 0) {
    if ((uVar5 & 1) != 0) {
      *(char **)(param_2 + 0x18) = s_Italic_0043e928;
    }
  }
  else if ((uVar5 & 1) == 0) {
    *(undefined1 **)(param_2 + 0x18) = &DAT_0043e930;
  }
  else {
    *(char **)(param_2 + 0x18) = s_Bold_Italic_0043e938;
  }
  puVar7 = FUN_00421d00((int)param_2,(byte *)s_FAMILY_NAME_004418ec);
  if (puVar7 == (undefined4 *)0x0) {
    param_2[0x14] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
  }
  else if (*(char *)(puVar7 + 1) != '\0') {
    uVar5 = 0xffffffff;
    pcVar11 = (char *)puVar7[2];
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    iVar4 = FUN_00410c90(iVar10,~uVar5,(undefined4 *)(param_2 + 0x14));
    if (iVar4 != 0) goto LAB_00421b77;
    pcVar11 = (char *)puVar7[2];
    pcVar12 = *(char **)(param_2 + 0x14);
    do {
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar12 = cVar2;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
  }
  pbVar1 = param_2 + 0x20;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 0xf4);
  param_2[0x1c] = 1;
  param_2[0x1d] = 0;
  param_2[0x1e] = 0;
  param_2[0x1f] = 0;
  iVar4 = FUN_00410c90(iVar10,4,(undefined4 *)pbVar1);
  if (iVar4 != 0) goto LAB_00421b77;
  puVar7 = FUN_00421d00((int)param_2,(byte *)s_PIXEL_SIZE_004418e0);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = FUN_00421d00((int)param_2,(byte *)s_POINT_SIZE_004418d4);
    if (puVar7 != (undefined4 *)0x0) {
      puVar9 = FUN_00421d00((int)param_2,(byte *)s_RESOLUTION_X_004418c4);
      puVar8 = FUN_00421d00((int)param_2,(byte *)s_RESOLUTION_Y_004418b4);
      if ((puVar9 != (undefined4 *)0x0) && (puVar8 != (undefined4 *)0x0)) {
        *(short *)(*(int *)pbVar1 + 2) =
             (short)((int)(puVar9[2] * puVar7[2]) / 0x2d0) -
             (short)((int)(puVar9[2] * puVar7[2]) / -0x4c000000);
        **(short **)pbVar1 =
             (short)((int)(puVar8[2] * puVar7[2]) / 0x2d0) -
             (short)((int)(puVar8[2] * puVar7[2]) / -0x4c000000);
        goto LAB_00421ada;
      }
    }
    *(undefined2 *)(*(int *)pbVar1 + 2) = 0xc;
    **(undefined2 **)pbVar1 = 0xc;
  }
  else {
    *(undefined2 *)(*(int *)pbVar1 + 2) = *(undefined2 *)(puVar7 + 2);
    **(undefined2 **)pbVar1 = *(undefined2 *)(puVar7 + 2);
  }
LAB_00421ada:
  *(byte **)(param_2 + 0x28) = param_2 + 0x10c;
  param_2[0x24] = 1;
  param_2[0x25] = 0;
  param_2[0x26] = 0;
  param_2[0x27] = 0;
  puVar7 = FUN_00421d00((int)param_2,(byte *)s_CHARSET_REGISTRY_004418a0);
  puVar9 = FUN_00421d00((int)param_2,(byte *)s_CHARSET_ENCODING_0044188c);
  if (((puVar7 != (undefined4 *)0x0) && (puVar9 != (undefined4 *)0x0)) &&
     ((*(char *)(puVar7 + 1) != '\0' && (*(char *)(puVar9 + 1) != '\0')))) {
    uVar5 = 0xffffffff;
    pcVar11 = (char *)puVar9[2];
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    iVar4 = FUN_00410c90(iVar10,~uVar5,(undefined4 *)(param_2 + 0x84));
    if (iVar4 == 0) {
      uVar5 = 0xffffffff;
      pcVar11 = (char *)puVar7[2];
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      iVar10 = FUN_00410c90(iVar10,~uVar5,(undefined4 *)(param_2 + 0x88));
      if (iVar10 == 0) {
        pcVar11 = (char *)puVar7[2];
        pcVar12 = *(char **)(param_2 + 0x88);
        do {
          cVar2 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          *pcVar12 = cVar2;
          pcVar12 = pcVar12 + 1;
        } while (cVar2 != '\0');
        pcVar11 = (char *)puVar9[2];
        pcVar12 = *(char **)(param_2 + 0x84);
        do {
          cVar2 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          *pcVar12 = cVar2;
          pcVar12 = pcVar12 + 1;
        } while (cVar2 != '\0');
        goto LAB_00421bb1;
      }
    }
LAB_00421b77:
    FUN_00421780((int)param_2);
    return 3;
  }
LAB_00421bb1:
  param_2[0x114] = 0;
  param_2[0x115] = 0;
  param_2[0x116] = 0;
  param_2[0x117] = 0;
  param_2[0x118] = 0;
  param_2[0x119] = 0;
  param_2[0x11a] = 0;
  param_2[0x11b] = 0;
  pbVar1 = param_2 + 0x110;
  *(byte **)pbVar1 = param_2;
  *(byte **)(param_2 + 0x10c) = pbVar1;
  *(byte **)(param_2 + 0x5c) = pbVar1;
  return 0;
}



int __cdecl FUN_00421be0(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  iVar1 = *(int *)(param_2 + 100);
  bVar2 = FUN_00411790((int)param_1,0);
  if ((CONCAT31(extraout_var,bVar2) != 0) ||
     (iVar3 = FUN_00411d20(param_1,&DAT_00433500,param_2 + 0x8c), iVar3 != 0)) {
    return 1;
  }
  if (*(int *)(param_2 + 0x8c) != 0x70636601) {
    return 3;
  }
  piVar6 = (int *)(param_2 + 0x94);
  iVar3 = FUN_00410c90(iVar1,*(int *)(param_2 + 0x90) << 4,piVar6);
  if (iVar3 == 0) {
    iVar3 = *piVar6;
    uVar5 = 0;
    if (*(int *)(param_2 + 0x90) == 0) {
      return 0;
    }
    do {
      iVar4 = FUN_00411d20(param_1,&DAT_00433510,iVar3);
      if (iVar4 != 0) {
        FUN_00410d70(iVar1,piVar6);
        return iVar4;
      }
      iVar3 = iVar3 + 0x10;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_2 + 0x90));
    return 0;
  }
  return 0x40;
}



uint __cdecl FUN_00421cd0(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0 < param_2) {
    do {
      if (*param_1 == param_3) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 4;
    } while ((int)uVar1 < param_2);
  }
  return uVar1 & 0xffffff00;
}



undefined4 * __cdecl FUN_00421d00(int param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = 0;
  bVar2 = false;
  puVar5 = *(undefined4 **)(param_1 + 0xf0);
  if (0 < *(int *)(param_1 + 0xec)) {
    do {
      if (bVar2) goto LAB_00421d75;
      pbVar3 = (byte *)*puVar5;
      pbVar6 = param_2;
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_00421d54:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_00421d59;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_00421d54;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00421d59:
      if (iVar4 == 0) {
        bVar2 = true;
      }
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 3;
    } while (iVar7 < *(int *)(param_1 + 0xec));
    if (bVar2) {
LAB_00421d75:
      return *(undefined4 **)(param_1 + 0xf0) + iVar7 * 3 + -3;
    }
  }
  return (undefined4 *)0x0;
}



int __cdecl FUN_00421d90(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  piVar2 = param_1;
  iVar8 = *(int *)(param_2 + 100);
  local_1c = 0;
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  local_10 = iVar8;
  param_1 = (int *)FUN_004220c0((int)param_1,*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),1,
                                (int *)&local_8,&local_4);
  if (((param_1 == (int *)0x0) && (local_8 = FUN_00411ca0(piVar2,&param_1), param_1 == (int *)0x0))
     && ((local_8 & 0xffffff00) == 0)) {
    if (((byte)local_8 & 4) == 4) {
      uVar3 = FUN_00411c20(piVar2,&param_1);
    }
    else {
      uVar3 = FUN_00411ca0(piVar2,&param_1);
    }
    local_c = uVar3;
    if (param_1 == (int *)0x0) {
      param_1 = (int *)FUN_00410c90(iVar8,uVar3 * 0xc,&local_1c);
      if (param_1 == (int *)0x0) {
        iVar7 = 0;
        uVar4 = uVar3;
        if (0 < (int)uVar3) {
          iVar9 = 0;
          do {
            param_1 = (int *)0x0;
            if (((byte)local_8 & 4) == 4) {
              pbVar10 = &DAT_00433598;
            }
            else {
              pbVar10 = &DAT_00433584;
            }
            param_1 = (int *)FUN_00411d20(piVar2,pbVar10,iVar9 + local_1c);
            iVar8 = local_10;
            if (param_1 != (int *)0x0) goto LAB_00422093;
            iVar7 = iVar7 + 1;
            iVar9 = iVar9 + 0xc;
            uVar4 = local_c;
          } while (iVar7 < (int)local_c);
        }
        if ((uVar4 & 3) != 0) {
          FUN_004117c0((int)piVar2,4 - (uVar4 & 3));
        }
        if (((byte)local_8 & 4) == 4) {
          uVar4 = FUN_00411c20(piVar2,&param_1);
        }
        else {
          uVar4 = FUN_00411ca0(piVar2,&param_1);
        }
        iVar8 = local_10;
        if (((param_1 == (int *)0x0) &&
            (param_1 = (int *)FUN_00410c90(local_10,uVar4,&local_14), iVar8 = local_10,
            param_1 == (int *)0x0)) &&
           ((param_1 = (int *)FUN_004117f0(piVar2,local_14,uVar4), iVar8 = local_10,
            param_1 == (int *)0x0 &&
            (param_1 = (int *)FUN_00410c90(local_10,uVar3 * 0xc,&local_18), uVar3 = local_c,
            iVar8 = local_10, param_1 == (int *)0x0)))) {
          iVar7 = 0;
          if (0 < (int)local_c) {
            iVar9 = 0;
            do {
              param_1 = (int *)0x0;
              uVar4 = 0xffffffff;
              pcVar6 = (char *)(*(int *)(iVar9 + local_1c) + (int)local_14);
              do {
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              param_1 = (int *)FUN_00410c90(local_10,~uVar4,(undefined4 *)(iVar9 + local_18));
              iVar8 = local_10;
              if (param_1 != (int *)0x0) goto LAB_00422093;
              pcVar5 = (char *)(*(int *)(iVar9 + local_1c) + (int)local_14);
              pcVar6 = *(char **)(iVar9 + local_18);
              do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
                *pcVar6 = cVar1;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              *(undefined1 *)(iVar9 + 4 + local_18) = *(undefined1 *)(iVar9 + 4 + local_1c);
              if (*(char *)(iVar9 + 4 + local_1c) == '\0') {
                *(undefined4 *)(iVar9 + 8 + local_18) = *(undefined4 *)(iVar9 + 8 + local_1c);
              }
              else {
                uVar4 = 0xffffffff;
                pcVar6 = (char *)(*(int *)(iVar9 + 8 + local_1c) + (int)local_14);
                do {
                  if (uVar4 == 0) break;
                  uVar4 = uVar4 - 1;
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                param_1 = (int *)FUN_00410c90(local_10,~uVar4,(undefined4 *)(iVar9 + 8 + local_18));
                iVar8 = local_10;
                if (param_1 != (int *)0x0) goto LAB_00422093;
                pcVar5 = (char *)(*(int *)(iVar9 + 8 + local_1c) + (int)local_14);
                pcVar6 = *(char **)(iVar9 + 8 + local_18);
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                  *pcVar6 = cVar1;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
              }
              iVar7 = iVar7 + 1;
              iVar9 = iVar9 + 0xc;
            } while (iVar7 < (int)uVar3);
          }
          iVar8 = local_10;
          param_1 = (int *)0x0;
          *(int *)(param_2 + 0xf0) = local_18;
          *(uint *)(param_2 + 0xec) = uVar3;
          FUN_00410d70(local_10,&local_1c);
          FUN_00410d70(iVar8,(int *)&local_14);
          return 0;
        }
      }
    }
  }
LAB_00422093:
  FUN_00410d70(iVar8,&local_1c);
  FUN_00410d70(iVar8,(int *)&local_14);
  return (int)param_1;
}



undefined4 __cdecl
FUN_004220c0(int param_1,int *param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  piVar3 = param_2;
  if (0 < param_3) {
    do {
      if (*piVar3 == param_4) {
        if ((uint)param_2[iVar1 * 4 + 3] < *(uint *)(param_1 + 8)) {
          return 0x53;
        }
        iVar2 = FUN_004117c0(param_1,param_2[iVar1 * 4 + 3] - *(uint *)(param_1 + 8));
        if (iVar2 == 0) {
          *param_6 = param_2[iVar1 * 4 + 2];
          *param_5 = param_2[iVar1 * 4 + 1];
          return 0;
        }
        return 0x53;
      }
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar1 < param_3);
  }
  return 3;
}



int __cdecl FUN_00422140(int *param_1,byte *param_2)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  short *psVar7;
  uint local_8;
  int local_4;
  
  pbVar6 = param_2;
  piVar1 = param_1;
  iVar4 = *(int *)(param_2 + 100);
  local_8 = 0;
  local_4 = iVar4;
  local_8 = FUN_004220c0((int)param_1,*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),4,
                         (int *)&param_2,(int *)&param_1);
  if (local_8 == 0) {
    param_2 = (byte *)FUN_00411ca0(piVar1,&local_8);
    local_8 = (uint)(local_8 != 0);
    uVar5 = (uint)param_2 & 0xffffff00;
    if ((uVar5 == 0) || (uVar5 == 0x100)) {
      bVar2 = (byte)param_2 & 4;
      if (uVar5 == 0) {
        if (bVar2 == 4) {
          uVar5 = FUN_00411c20(piVar1,&local_8);
        }
        else {
          uVar5 = FUN_00411ca0(piVar1,&local_8);
        }
      }
      else {
        if (bVar2 == 4) {
          uVar5 = FUN_00411b40(piVar1,&local_8);
          uVar3 = (ushort)uVar5;
        }
        else {
          uVar5 = FUN_00411bb0(piVar1,&local_8);
          uVar3 = (ushort)uVar5;
        }
        uVar5 = (uint)uVar3;
      }
      if ((local_8 == 0) && (uVar5 != 0xffffffff)) {
        *(uint *)(pbVar6 + 0xf4) = uVar5;
        pbVar6 = pbVar6 + 0xf8;
        param_1 = (int *)pbVar6;
        iVar4 = FUN_00410c90(iVar4,uVar5 << 4,(undefined4 *)pbVar6);
        if (iVar4 != 0) {
          return 0x40;
        }
        psVar7 = *(short **)pbVar6;
        iVar4 = 0;
        if ((int)uVar5 < 1) {
          return 0;
        }
        local_8 = 0;
        do {
          FUN_004222d0(piVar1,param_2,psVar7);
          psVar7[6] = 0;
          psVar7[7] = 0;
          if (local_8 != 0) {
            FUN_00410d70(local_4,param_1);
            return local_8;
          }
          iVar4 = iVar4 + 1;
          psVar7 = psVar7 + 8;
        } while (iVar4 < (int)uVar5);
        return 0;
      }
    }
    local_8 = 3;
  }
  return local_8;
}



void __cdecl FUN_004222d0(int *param_1,byte *param_2,short *param_3)

{
  if (((uint)param_2 & 0xffffff00) == 0) {
    if (((byte)param_2 & 4) == 4) {
      param_2 = &DAT_00433548;
    }
    else {
      param_2 = &DAT_00433528;
    }
    FUN_00411d20(param_1,param_2,(int)param_3);
    return;
  }
  FUN_00422320(param_1,param_3);
  return;
}



int __cdecl FUN_00422320(int *param_1,short *param_2)

{
  int iVar1;
  byte local_8 [3];
  ushort uStack_5;
  
  iVar1 = FUN_00411d20(param_1,&DAT_00433568,(int)local_8);
  if (iVar1 == 0) {
    param_2[5] = 0;
    *param_2 = local_8[0] - 0x80;
    param_2[1] = ((ushort)stack0xfffffff9 & 0xff) - 0x80;
    param_2[2] = (byte)((uint)stack0xfffffff9 >> 8) - 0x80;
    param_2[3] = (uStack_5 & 0xff) - 0x80;
    param_2[4] = (uStack_5 >> 8) - 0x80;
    iVar1 = 0;
  }
  return iVar1;
}



int __cdecl FUN_004223a0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  undefined4 auStack_10 [4];
  
  iVar2 = param_2;
  piVar1 = param_1;
  iVar6 = *(int *)(param_2 + 100);
  local_20 = 0;
  local_18 = iVar6;
  local_20 = FUN_004220c0((int)param_1,*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),8,
                          (int *)&local_1c,(int *)&param_1);
  if ((local_20 == 0) && (local_20 = FUN_00411900(piVar1,8), local_20 == 0)) {
    local_1c = FUN_00411a90((int)piVar1);
    if ((local_1c & 0xffffff00) != 0) {
      return 3;
    }
    param_1 = (int *)(local_1c >> 2 & 1);
    if (param_1 == (int *)0x1) {
      iVar3 = FUN_00411a50((int)piVar1);
    }
    else {
      iVar3 = FUN_00411a90((int)piVar1);
    }
    FUN_004119a0(piVar1);
    if (iVar3 != *(int *)(iVar2 + 0xf4)) {
      return 3;
    }
    local_20 = FUN_00410c90(iVar6,iVar3 * 4,&param_2);
    if (local_20 == 0) {
      if (0 < iVar3) {
        iVar6 = 0;
        do {
          if (param_1 == (int *)0x1) {
            uVar4 = FUN_00411c20(piVar1,&local_20);
          }
          else {
            uVar4 = FUN_00411ca0(piVar1,&local_20);
          }
          *(undefined4 *)(param_2 + iVar6 * 4) = uVar4;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
      if (local_20 != 0) {
LAB_00422554:
        iVar6 = local_18;
        FUN_00410d70(local_18,&param_2);
        FUN_00410d70(iVar6,&local_14);
        return local_20;
      }
      iVar6 = 0;
      do {
        if (param_1 == (int *)0x1) {
          uVar4 = FUN_00411c20(piVar1,&local_20);
        }
        else {
          uVar4 = FUN_00411ca0(piVar1,&local_20);
        }
        auStack_10[iVar6] = uVar4;
        if (local_20 != 0) goto LAB_00422554;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 4);
      iVar6 = 0;
      if (0 < iVar3) {
        iVar5 = 0;
        do {
          *(int *)(iVar5 + 0xc + *(int *)(iVar2 + 0xf8)) = *(int *)(param_2 + iVar6 * 4) + piVar1[2]
          ;
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 < iVar3);
      }
      *(uint *)(iVar2 + 0x108) = local_1c;
      FUN_00410d70(local_18,&param_2);
    }
  }
  return local_20;
}



int __cdecl FUN_00422580(int *param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  piVar1 = param_1;
  local_18 = *(int *)(param_2 + 100);
  local_1c = 0;
  iVar6 = FUN_004220c0((int)param_1,*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),0x20,
                       (int *)&local_8,&local_4);
  if ((iVar6 != 0) || (iVar6 = FUN_00411900(piVar1,0xe), iVar6 != 0)) {
    return iVar6;
  }
  uVar7 = FUN_00411a90((int)piVar1);
  if ((uVar7 & 0xffffff00) != 0) {
    return 3;
  }
  local_8 = uVar7 >> 2 & 1;
  if (local_8 == 1) {
    sVar2 = FUN_004119f0((int)piVar1);
    sVar3 = FUN_004119f0((int)piVar1);
    sVar4 = FUN_004119f0((int)piVar1);
    local_14 = (int)sVar4;
    sVar4 = FUN_004119f0((int)piVar1);
    uVar5 = FUN_004119f0((int)piVar1);
    *(undefined2 *)(param_2 + 0x104) = uVar5;
  }
  else {
    sVar2 = FUN_00411a20((int)piVar1);
    sVar3 = FUN_00411a20((int)piVar1);
    sVar4 = FUN_00411a20((int)piVar1);
    local_14 = (int)sVar4;
    sVar4 = FUN_00411a20((int)piVar1);
    uVar5 = FUN_00411a20((int)piVar1);
    *(undefined2 *)(param_2 + 0x104) = uVar5;
  }
  FUN_004119a0(piVar1);
  iVar6 = local_18;
  local_4 = ((int)sVar3 - (int)sVar2) + 1;
  iVar9 = ((sVar4 - local_14) + 1) * local_4;
  local_c = iVar9;
  iVar8 = FUN_00410c90(local_18,iVar9 * 8,&param_1);
  if (iVar8 == 0) {
    iVar8 = FUN_00411900(piVar1,iVar9 * 2);
    if (iVar8 == 0) {
      iVar9 = 0;
      local_10 = 0;
      if (0 < local_c) {
        iVar6 = 0;
        do {
          local_10 = iVar6;
          if (local_8 == 1) {
            sVar4 = FUN_004119f0((int)piVar1);
          }
          else {
            sVar4 = FUN_00411a20((int)piVar1);
          }
          if (sVar4 != -1) {
            param_1[iVar9 * 2] = (iVar6 / local_4 + local_14) * 0x100 + iVar6 % local_4 + (int)sVar2
            ;
            *(short *)(param_1 + iVar9 * 2 + 1) = sVar4;
            iVar9 = iVar9 + 1;
            iVar6 = local_10;
          }
          iVar6 = iVar6 + 1;
          local_10 = iVar6;
        } while (iVar6 < local_c);
      }
      FUN_004119a0(piVar1);
      iVar9 = iVar9 + -1;
      iVar8 = FUN_00410c90(local_18,iVar9 * 8,&local_1c);
      iVar6 = local_18;
      if (iVar8 == 0) {
        iVar6 = 0;
        if (0 < iVar9) {
          do {
            *(int *)(local_1c + iVar6 * 8) = param_1[iVar6 * 2];
            *(short *)(local_1c + 4 + iVar6 * 8) = (short)param_1[iVar6 * 2 + 1];
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar9);
        }
        *(int *)(param_2 + 0xfc) = iVar9;
        *(int *)(param_2 + 0x100) = local_1c;
        FUN_00410d70(local_18,(int *)&param_1);
        return 0;
      }
    }
    FUN_00410d70(iVar6,&local_1c);
    FUN_00410d70(iVar6,(int *)&param_1);
    return iVar8;
  }
  return 0x40;
}



uint __cdecl FUN_00422800(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  uint local_4;
  
  uVar3 = param_2;
  iVar1 = param_2 + 0x98;
  local_4 = 0;
  local_4 = FUN_004220c0((int)param_1,*(int **)(param_2 + 0x94),*(int *)(param_2 + 0x90),param_3,
                         &param_3,(int *)&param_2);
  if (local_4 == 0) {
    pbVar2 = (byte *)FUN_00411ca0(param_1,&local_4);
    local_4 = (uint)(local_4 != 0);
    param_2 = (uint)pbVar2 & 0xffffff00;
    if ((param_2 == 0) || (param_2 == 0x100)) {
      if (((byte)pbVar2 & 4) == 4) {
        pbVar4 = &DAT_004335e0;
      }
      else {
        pbVar4 = &DAT_004335ac;
      }
      local_4 = FUN_00411d20(param_1,pbVar4,iVar1);
      if ((local_4 == 0) &&
         (local_4 = FUN_004222d0(param_1,pbVar2,(short *)(uVar3 + 0xac)), local_4 == 0)) {
        local_4 = FUN_004222d0(param_1,pbVar2,(short *)(uVar3 + 0xbc));
        if (local_4 == 0) {
          if (param_2 == 0x100) {
            local_4 = FUN_004222d0(param_1,pbVar2,(short *)(uVar3 + 0xcc));
            if (local_4 != 0) {
              return local_4;
            }
            uVar3 = FUN_004222d0(param_1,pbVar2,(short *)(uVar3 + 0xdc));
            if (uVar3 != 0) {
              return uVar3;
            }
          }
          else {
            *(undefined4 *)(uVar3 + 0xcc) = *(undefined4 *)(uVar3 + 0xac);
            *(undefined4 *)(uVar3 + 0xd0) = *(undefined4 *)(uVar3 + 0xb0);
            *(undefined4 *)(uVar3 + 0xd4) = *(undefined4 *)(uVar3 + 0xb4);
            *(undefined4 *)(uVar3 + 0xd8) = *(undefined4 *)(uVar3 + 0xb8);
            *(undefined4 *)(uVar3 + 0xdc) = *(undefined4 *)(uVar3 + 0xbc);
            *(undefined4 *)(uVar3 + 0xe0) = *(undefined4 *)(uVar3 + 0xc0);
            *(undefined4 *)(uVar3 + 0xe4) = *(undefined4 *)(uVar3 + 0xc4);
            *(undefined4 *)(uVar3 + 0xe8) = *(undefined4 *)(uVar3 + 200);
          }
          local_4 = 0;
        }
      }
    }
  }
  return local_4;
}



void __cdecl FUN_00422e30(int *param_1)

{
  int iVar1;
  
  if (param_1[10] != 0) {
    iVar1 = FUN_00422e60(param_1);
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(param_1[10]);
    }
    param_1[10] = 0;
  }
  return;
}



undefined4 __cdecl FUN_00422e60(int *param_1)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(*param_1 + 0x140);
  iVar2 = FUN_004116f0(*(int *)(*(int *)(*param_1 + 0x60) + 4),(byte *)s_pshinter_0043eb78);
  if (((iVar2 != 0) && (puVar1 != (undefined4 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)*puVar1, UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x00422e94. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (*UNRECOVERED_JUMPTABLE)();
    return uVar3;
  }
  return 0;
}



int __cdecl FUN_00422ea0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = param_1;
  puVar2 = (undefined4 *)FUN_00422e60(param_1);
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
    iVar3 = (*(code *)*puVar2)(*(undefined4 *)(iVar3 + 100),
                               *(int *)(iVar3 + 4) * 0xf8 + *(int *)(iVar3 + 0x130),&param_1);
    if (iVar3 == 0) {
      piVar1[10] = (int)param_1;
      return 0;
    }
  }
  return iVar3;
}



undefined4 __cdecl FUN_00422ef0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00422e60(param_1);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(iVar1 + 4))(param_1[10],param_1[4],param_1[5],0,0);
    return uVar2;
  }
  return 0;
}



void __cdecl FUN_00422f20(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 100);
    if (*(int *)(param_1 + 0x13c) != 0) {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 300)) {
        do {
          piVar1 = (int *)(*(int *)(param_1 + 0x13c) + iVar4 * 8 + 4);
          piVar3 = (int *)*piVar1;
          if (piVar3 != (int *)0x0) {
            FUN_00410d70(iVar2,piVar3);
            FUN_00410d70(iVar2,piVar1);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(param_1 + 300));
      }
      FUN_00410d70(iVar2,(int *)(param_1 + 0x13c));
    }
    FUN_00410d70(iVar2,(int *)(param_1 + 0xa4));
    FUN_00410d70(iVar2,(int *)(param_1 + 0xa8));
    FUN_00410d70(iVar2,(int *)(param_1 + 0xac));
    FUN_00410d70(iVar2,(int *)(param_1 + 0xb0));
    FUN_00410d70(iVar2,(int *)(param_1 + 0xb4));
    FUN_00410d70(iVar2,(int *)(param_1 + 0x130));
    *(undefined4 *)(param_1 + 300) = 0;
    FUN_00410d70(iVar2,(int *)(param_1 + 0x8c));
    FUN_00410d70(iVar2,(int *)(param_1 + 0x98));
    FUN_00410d70(iVar2,(int *)(param_1 + 0x9c));
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}



int __cdecl FUN_004231e0(int param_1)

{
  int iVar1;
  int local_60 [18];
  char *local_18;
  int local_14;
  undefined4 local_10;
  
  FUN_00423970(local_60);
  iVar1 = FUN_00423260(local_60,*(int **)(param_1 + 0x68),*(undefined4 *)(param_1 + 100),
                       *(int *)(param_1 + 0x88));
  if (iVar1 == 0) {
    iVar1 = FUN_004233e0(param_1,local_60,local_18,local_14);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x134) = local_10;
      iVar1 = FUN_00423630(param_1);
    }
  }
  thunk_FUN_00423990((int)local_60);
  return iVar1;
}



int __cdecl FUN_00423260(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  size_t _Size;
  char *_Str1;
  uint uVar6;
  int *piVar7;
  undefined4 auStackY_20c [51];
  undefined4 uStackY_140;
  char acStack_10c [256];
  char acStack_c [12];
  
  piVar7 = param_1;
  for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  (*(code *)**(undefined4 **)(param_4 + 4))();
  param_1[0x11] = (int)param_2;
  uVar2 = FUN_004117e0((int)param_2);
  uStackY_140 = 0x4232b1;
  iVar5 = FUN_00411900(param_2,0x1f);
  if (iVar5 == 0) {
    iVar3 = strncmp((char *)param_2[8],s___PS_Adobe_3_0_Resource_CIDFont_00441a04,0x1f);
    if (iVar3 != 0) {
      iVar5 = 2;
    }
    FUN_004119a0(param_2);
    if (iVar5 == 0) {
      iVar5 = 0x100;
      while( true ) {
        _Size = iVar5 - 0x100;
        if (0 < (int)_Size) {
          memmove(acStack_10c,acStack_c,_Size);
        }
        iVar5 = FUN_004117f0(param_2,(undefined4 *)((int)auStackY_20c + iVar5),0x10a - _Size);
        if (iVar5 != 0) break;
        iVar3 = FUN_004117e0((int)param_2);
        iVar5 = 0x10a;
        _Str1 = acStack_10c;
        do {
          if ((*_Str1 == 'S') && (iVar4 = strncmp(_Str1,s_StartData_004419f8,9), iVar4 == 0)) {
            uVar6 = (int)(_Str1 + ((iVar3 - _Size) - (int)acStack_c) + 10) - uVar2;
            bVar1 = FUN_00411790((int)param_2,uVar2);
            if (CONCAT31(extraout_var,bVar1) != 0) {
              return CONCAT31(extraout_var,bVar1);
            }
            iVar5 = FUN_004118a0(param_2,uVar6,param_1 + 0x12);
            if (iVar5 != 0) {
              return iVar5;
            }
            iVar5 = param_1[0x12];
            param_1[0x14] = (int)(_Str1 + ((iVar3 - _Size) - (int)acStack_c) + 10);
            param_1[1] = iVar5;
            *param_1 = iVar5;
            param_1[0x13] = uVar6;
            param_1[2] = iVar5 + uVar6;
            param_1[0x16] = -1;
            return 0;
          }
          _Str1 = _Str1 + 1;
        } while (_Str1 < acStack_c);
      }
    }
  }
  return iVar5;
}



int __cdecl FUN_004233e0(int param_1,undefined4 *param_2,char *param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined **ppuVar8;
  char *pcVar9;
  char *pcVar10;
  
  pcVar1 = param_3 + param_4;
  *param_2 = param_3;
  param_2[2] = pcVar1;
  param_2[3] = 0;
  do {
    if (pcVar1 <= param_3) {
      return param_2[3];
    }
    if (((*param_3 == '%') && (param_3 + 0x14 < pcVar1)) &&
       (iVar3 = strncmp(param_3,s__ADOBeginFontDict_00441a24,0x11), iVar3 == 0)) {
      pcVar9 = param_3 + 0x11;
      if (0 < *(int *)(param_1 + 300)) {
        param_2[0x16] = param_2[0x16] + 1;
      }
    }
    else {
      pcVar9 = param_3;
      if ((*param_3 == '/') && (param_3 + 2 < pcVar1)) {
        pcVar9 = param_3 + 1;
        pcVar10 = pcVar9;
        while ((pcVar10 < pcVar1 && (iVar3 = FUN_004235e0(*pcVar10), iVar3 != 0))) {
          pcVar10 = pcVar10 + 1;
        }
        iVar3 = (int)pcVar10 - (int)pcVar9;
        if ((0 < iVar3) && (iVar3 < 0x16)) {
          pcVar7 = s_CIDFontName_004419ec;
          ppuVar8 = &PTR_s_CIDFontName_00433680;
          do {
            if (*pcVar9 == *pcVar7) {
              uVar5 = 0xffffffff;
              pcVar4 = pcVar7;
              do {
                if (uVar5 == 0) break;
                uVar5 = uVar5 - 1;
                cVar2 = *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (cVar2 != '\0');
              if (iVar3 == ~uVar5 - 1) {
                if (1 < iVar3) {
                  pcVar4 = param_3 + 2;
                  iVar6 = 1;
                  while (*pcVar4 == pcVar4[(int)pcVar7 - (int)pcVar9]) {
                    iVar6 = iVar6 + 1;
                    pcVar4 = pcVar4 + 1;
                    if (iVar3 <= iVar6) goto LAB_004234dd;
                  }
                  if (iVar6 < iVar3) goto LAB_00423524;
                }
LAB_004234dd:
                *param_2 = pcVar10;
                (*(code *)param_2[7])(param_2);
                iVar3 = FUN_00423540(param_1,(int)param_2,(int)ppuVar8);
                param_2[3] = iVar3;
                if (iVar3 != 0) {
                  return iVar3;
                }
                pcVar9 = (char *)*param_2;
                break;
              }
            }
LAB_00423524:
            pcVar7 = ppuVar8[8];
            ppuVar8 = ppuVar8 + 8;
          } while (pcVar7 != (char *)0x0);
        }
      }
    }
    param_3 = pcVar9 + 1;
  } while( true );
}



undefined4 __cdecl FUN_00423540(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = param_2;
  iVar2 = *(int *)(param_3 + 8);
  iVar4 = param_1 + 0x8c;
  if (iVar2 == 7) {
    (**(code **)(param_3 + 0xc))(param_1,param_2);
    return *(undefined4 *)(iVar3 + 0xc);
  }
  if (*(int *)(param_3 + 4) != 0) {
    if (*(int *)(param_3 + 4) == 2) {
      iVar4 = param_1 + 0xa4;
    }
    else {
      if (*(int *)(param_2 + 0x58) < 0) {
        return 0xa0;
      }
      iVar4 = *(int *)(param_2 + 0x58) * 0xf8 + *(int *)(param_1 + 0x130);
    }
  }
  if ((iVar2 != 5) && (iVar2 != 6)) {
    puVar1 = (undefined4 *)(param_2 + 0x3c);
    param_2 = iVar4;
    uVar5 = (*(code *)*puVar1)(iVar3,param_3,&param_2,0,0);
    return uVar5;
  }
  puVar1 = (undefined4 *)(param_2 + 0x40);
  param_2 = iVar4;
  uVar5 = (*(code *)*puVar1)(iVar3,param_3,&param_2,0,0);
  return uVar5;
}



undefined4 __cdecl FUN_004235e0(char param_1)

{
  uint uVar1;
  
  if (DAT_004433c0 < 2) {
    uVar1 = *(ushort *)(PTR_DAT_004431b4 + param_1 * 2) & 0x107;
  }
  else {
    uVar1 = _isctype((int)param_1,0x107);
  }
  if (((uVar1 == 0) && (param_1 != '.')) && (param_1 != '_')) {
    return 0;
  }
  return 1;
}



int __cdecl FUN_00423630(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  byte bVar7;
  int iVar8;
  undefined3 extraout_var;
  uint uVar9;
  undefined3 extraout_var_00;
  int iVar10;
  uint uVar11;
  int *local_28;
  int local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  uint *local_c;
  int local_8;
  int local_4;
  
  local_24 = *(int *)(param_1 + 100);
  local_20 = *(int **)(param_1 + 0x68);
  local_1c = 0;
  local_28 = (int *)0x0;
  iVar8 = FUN_00410c90(local_24,*(int *)(param_1 + 300) << 3,(int *)(param_1 + 0x13c));
  if (iVar8 == 0) {
    local_10 = *(uint **)(param_1 + 0x13c);
    local_14 = 0;
    if (0 < *(int *)(param_1 + 300)) {
      local_c = local_10 + 1;
      local_18 = 0;
      do {
        iVar10 = *(int *)(param_1 + 0x130);
        local_4 = *(int *)(iVar10 + 4 + local_18);
        uVar2 = *(uint *)(iVar10 + 0xec + local_18);
        iVar10 = iVar10 + local_18;
        uVar11 = local_1c;
        if (local_1c < uVar2 + 1) {
          uVar11 = uVar2 + 4 & 0xfffffffc;
          iVar8 = FUN_00410ce0(local_24,local_1c * 4,uVar11 * 4,(int *)&local_28);
          if (iVar8 == 0) goto LAB_00423704;
LAB_004238b6:
          piVar1 = (int *)(param_1 + 0x13c);
          if (*(int *)(param_1 + 0x13c) != 0) {
            iVar10 = 0;
            if (0 < *(int *)(param_1 + 300)) {
              do {
                piVar4 = *(int **)(*piVar1 + 4 + iVar10 * 8);
                if (piVar4 != (int *)0x0) {
                  FUN_00410d70(local_24,piVar4);
                }
                FUN_00410d70(local_24,(int *)(*piVar1 + 4 + iVar10 * 8));
                iVar10 = iVar10 + 1;
              } while (iVar10 < *(int *)(param_1 + 300));
            }
            FUN_00410d70(local_24,piVar1);
          }
          break;
        }
LAB_00423704:
        local_1c = uVar11;
        puVar6 = local_c;
        bVar7 = FUN_00411790((int)local_20,*(int *)(iVar10 + 0xf0) + *(int *)(param_1 + 0x134));
        iVar8 = CONCAT31(extraout_var,bVar7);
        if ((iVar8 != 0) ||
           (iVar8 = FUN_00411900(local_20,*(int *)(iVar10 + 0xf4) * (uVar2 + 1)), iVar8 != 0))
        goto LAB_004238b6;
        local_8 = local_20[8];
        uVar11 = 0;
        do {
          uVar9 = FUN_00423940(&local_8,*(byte *)(iVar10 + 0xf4));
          local_28[uVar11] = uVar9;
          uVar11 = uVar11 + 1;
        } while (uVar11 <= uVar2);
        FUN_004119a0(local_20);
        iVar10 = *local_28;
        iVar3 = local_28[uVar2];
        iVar8 = FUN_00410c90(local_24,(uVar2 + 1) * 4,puVar6);
        if ((iVar8 != 0) ||
           (iVar8 = FUN_00410c90(local_24,iVar3 - iVar10,(undefined4 *)*puVar6), iVar8 != 0))
        goto LAB_004238b6;
        bVar7 = FUN_00411790((int)local_20,*local_28 + *(int *)(param_1 + 0x134));
        iVar8 = CONCAT31(extraout_var_00,bVar7);
        if ((iVar8 != 0) ||
           (iVar8 = FUN_004117f0(local_20,*(undefined4 **)*puVar6,iVar3 - iVar10), iVar8 != 0))
        goto LAB_004238b6;
        uVar11 = 1;
        if (uVar2 != 0) {
          do {
            iVar3 = uVar11 * 4;
            iVar5 = uVar11 - 1;
            iVar10 = uVar11 * 4;
            piVar1 = local_28 + uVar11;
            uVar11 = uVar11 + 1;
            *(int *)(*puVar6 + iVar10) =
                 (*(int *)((*puVar6 - 4) + iVar3) - local_28[iVar5]) + *piVar1;
          } while (uVar11 <= uVar2);
        }
        if ((-1 < local_4) && (uVar11 = 0, uVar2 != 0)) {
          do {
            FUN_00420810(*(byte **)(*puVar6 + uVar11 * 4),local_28[uVar11 + 1] - local_28[uVar11],
                         0x10ea);
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar2);
        }
        *local_10 = uVar2;
        local_10 = local_10 + 2;
        local_14 = local_14 + 1;
        local_18 = local_18 + 0xf8;
        local_c = puVar6 + 2;
      } while (local_14 < *(int *)(param_1 + 300));
    }
  }
  FUN_00410d70(local_24,(int *)&local_28);
  return iVar8;
}



uint __cdecl FUN_00423940(undefined4 *param_1,byte param_2)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = (byte *)*param_1;
  uVar1 = 0;
  if (param_2 != 0) {
    uVar3 = (uint)param_2;
    do {
      uVar1 = uVar1 << 8 | (uint)*pbVar2;
      pbVar2 = pbVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *param_1 = pbVar2;
  return uVar1;
}



void __cdecl FUN_00423970(undefined4 *param_1)

{
  int iVar1;
  
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



void __cdecl thunk_FUN_00423990(int param_1)

{
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_004118d0(*(int *)(param_1 + 0x44),(int *)(param_1 + 0x48));
  }
  (**(code **)(param_1 + 0x18))(param_1);
  return;
}



void __cdecl FUN_00423990(int param_1)

{
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_004118d0(*(int *)(param_1 + 0x44),(int *)(param_1 + 0x48));
  }
  (**(code **)(param_1 + 0x18))(param_1);
  return;
}



uint __cdecl FUN_004239d0(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  
  bVar3 = true;
  iVar1 = 0x10;
  pcVar2 = s_postscript_name_0043e900;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *param_2 == *pcVar2;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar3);
  return !bVar3 - 1 & 0x4239f0;
}



uint __cdecl FUN_00423a00(int *param_1,int param_2)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  uint uVar11;
  bool bVar12;
  
  iVar3 = *param_1;
  iVar7 = *(int *)(iVar3 + 0x1dc);
  uVar8 = 0;
  if (iVar7 != 0) {
    iVar4 = param_1[1];
    if (iVar4 == 0x41444243) {
      if ((*(int *)(iVar3 + 0x170) <= param_2) && (param_2 <= *(int *)(iVar3 + 0x174))) {
        uVar8 = (uint)*(ushort *)(*(int *)(iVar3 + 0x178) + param_2 * 2);
      }
    }
    else if (iVar4 == 0x756e6963) {
      uVar8 = (**(code **)(iVar7 + 8))(iVar3 + 0x208,param_2);
      if (uVar8 == 0xffff) {
        return 0;
      }
    }
    else if (param_2 < 0x100) {
      uVar2 = *(undefined2 *)(*(int *)(iVar7 + 0x14) + param_2 * 2);
      if (iVar4 == 0x41444245) {
        uVar2 = *(undefined2 *)(*(int *)(iVar7 + 0x18) + param_2 * 2);
      }
      pbVar5 = (byte *)(**(code **)(iVar7 + 0x10))(uVar2);
      if (pbVar5 != (byte *)0x0) {
        uVar11 = 0;
        if (0 < *(int *)(iVar3 + 0x198)) {
          puVar9 = *(undefined4 **)(iVar3 + 0x19c);
          do {
            pbVar6 = (byte *)*puVar9;
            if ((pbVar6 != (byte *)0x0) && (pbVar10 = pbVar5, *pbVar6 == *pbVar5)) {
              do {
                bVar1 = *pbVar6;
                bVar12 = bVar1 < *pbVar10;
                if (bVar1 != *pbVar10) {
LAB_00423ac4:
                  iVar7 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  goto LAB_00423ac9;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar6[1];
                bVar12 = bVar1 < pbVar10[1];
                if (bVar1 != pbVar10[1]) goto LAB_00423ac4;
                pbVar6 = pbVar6 + 2;
                pbVar10 = pbVar10 + 2;
              } while (bVar1 != 0);
              iVar7 = 0;
LAB_00423ac9:
              if (iVar7 == 0) {
                return uVar11;
              }
            }
            uVar11 = uVar11 + 1;
            puVar9 = puVar9 + 1;
            if (*(int *)(iVar3 + 0x198) <= (int)uVar11) {
              return 0;
            }
          } while( true );
        }
      }
    }
  }
  return uVar8;
}



int __cdecl FUN_00423e60(byte *param_1,uint param_2)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  pbVar2 = param_1;
  iVar7 = *(int *)(param_1 + 4);
  piVar1 = *(int **)(iVar7 + 0x68);
  iVar9 = *(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x124);
  bVar3 = FUN_00411790((int)piVar1,
                       iVar9 * param_2 + *(int *)(iVar7 + 0x11c) + *(int *)(iVar7 + 0x134));
  iVar4 = CONCAT31(extraout_var,bVar3);
  if ((iVar4 == 0) && (iVar4 = FUN_00411900(piVar1,iVar9 * 2), iVar4 == 0)) {
    param_1 = (byte *)piVar1[8];
    uVar5 = FUN_00423940(&param_1,*(byte *)(iVar7 + 0x120));
    bVar3 = *(byte *)(iVar7 + 0x124);
    param_2 = FUN_00423940(&param_1,bVar3);
    param_1 = param_1 + *(int *)(iVar7 + 0x120);
    uVar6 = FUN_00423940(&param_1,bVar3);
    uVar6 = uVar6 - param_2;
    FUN_004119a0(piVar1);
    if (uVar6 != 0) {
      iVar4 = *(int *)(iVar7 + 0x13c);
      iVar9 = *(int *)(iVar7 + 100);
      *(undefined4 *)(pbVar2 + 0x568) = *(undefined4 *)(iVar4 + uVar5 * 8);
      *(undefined4 *)(pbVar2 + 0x56c) = *(undefined4 *)(iVar4 + uVar5 * 8 + 4);
      pbVar2[0x570] = 0;
      pbVar2[0x571] = 0;
      pbVar2[0x572] = 0;
      pbVar2[0x573] = 0;
      iVar4 = uVar5 * 0xf8 + *(int *)(iVar7 + 0x130);
      *(undefined4 *)(pbVar2 + 0x574) = *(undefined4 *)(iVar4 + 0xd4);
      *(undefined4 *)(pbVar2 + 0x578) = *(undefined4 *)(iVar4 + 0xd8);
      *(undefined4 *)(pbVar2 + 0x57c) = *(undefined4 *)(iVar4 + 0xdc);
      *(undefined4 *)(pbVar2 + 0x580) = *(undefined4 *)(iVar4 + 0xe0);
      *(undefined4 *)(pbVar2 + 0x584) = *(undefined4 *)(iVar4 + 0xe4);
      *(undefined4 *)(pbVar2 + 0x588) = *(undefined4 *)(iVar4 + 0xe8);
      *(undefined4 *)(pbVar2 + 0x564) = *(undefined4 *)(iVar4 + 4);
      iVar4 = FUN_00410c90(iVar9,uVar6,&param_1);
      if (iVar4 == 0) {
        iVar7 = FUN_00411810(piVar1,*(int *)(iVar7 + 0x134) + param_2,(undefined4 *)param_1,uVar6);
        if (iVar7 == 0) {
          uVar5 = *(uint *)(pbVar2 + 0x564);
          uVar8 = ((int)uVar5 < 0) - 1 & uVar5;
          if (-1 < (int)uVar5) {
            FUN_00420810(param_1,uVar6,0x10ea);
          }
          iVar7 = (**(code **)(pbVar2 + 0x5dc))(pbVar2,param_1 + uVar8,uVar6 - uVar8);
        }
        FUN_00410d70(iVar9,(int *)&param_1);
        return iVar7;
      }
    }
  }
  return iVar4;
}



undefined1 * __cdecl FUN_004241a0(int param_1,char *param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar3 = 0xb;
  bVar6 = true;
  pcVar4 = param_2;
  pcVar5 = s_glyph_name_0043e8f4;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return &LAB_00424210;
  }
  iVar3 = 0xb;
  bVar6 = true;
  pcVar4 = param_2;
  pcVar5 = s_name_index_0043e8e8;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return &LAB_004242c0;
  }
  piVar1 = (int *)FUN_004116f0(*(int *)(param_1 + 4),&DAT_0043ec08);
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 0x20))(piVar1,param_2);
    return puVar2;
  }
  return (undefined1 *)0x0;
}



uint __cdecl FUN_004244d0(byte *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 == 0x1c) {
    if (param_1 + 3 <= param_2) {
      return (int)(short)((ushort)param_1[1] << 8) | (uint)param_1[2];
    }
  }
  else if (uVar1 == 0x1d) {
    if (param_1 + 5 <= param_2) {
      return CONCAT31(CONCAT21(CONCAT11(param_1[1],param_1[2]),param_1[3]),param_1[4]);
    }
  }
  else {
    if (uVar1 < 0xf7) {
      return uVar1 - 0x8b;
    }
    if (uVar1 < 0xfb) {
      if (param_1 + 2 <= param_2) {
        return uVar1 * 0x100 + -0xf694 + (uint)param_1[1];
      }
    }
    else if (param_1 + 2 <= param_2) {
      return (uVar1 * -0x100 + 0xfa94) - (uint)param_1[1];
    }
  }
  return 0;
}



uint __cdecl FUN_00424570(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  
  pbVar9 = param_1;
  iVar10 = 0;
  pbVar7 = (byte *)0x0;
  bVar2 = false;
  bVar3 = false;
  param_1 = (byte *)0x0;
  uVar6 = 1;
  iVar5 = 4;
  while( true ) {
    while( true ) {
      if ((iVar5 != 0) && (pbVar9 = pbVar9 + 1, param_2 <= pbVar9)) {
        return 0;
      }
      bVar1 = (byte)iVar5;
      iVar5 = 4 - iVar5;
      uVar4 = *pbVar9 >> (bVar1 & 0x1f) & 0xf;
      if (uVar4 != 0xe) break;
      bVar2 = true;
    }
    if (9 < uVar4) break;
    iVar10 = uVar4 + iVar10 * 10;
  }
  if (uVar4 == 10) {
    uVar6 = 1;
    while( true ) {
      if ((iVar5 != 0) && (pbVar9 = pbVar9 + 1, param_2 <= pbVar9)) {
        return 0;
      }
      bVar1 = (byte)iVar5;
      iVar5 = 4 - iVar5;
      uVar4 = *pbVar9 >> (bVar1 & 0x1f) & 0xf;
      if (9 < uVar4) break;
      if ((int)uVar6 < 10000000) {
        pbVar7 = (byte *)(uVar4 + (int)pbVar7 * 10);
        uVar6 = uVar6 * 10;
        param_1 = pbVar7;
      }
    }
  }
  if (uVar4 == 0xc) {
    bVar3 = true;
  }
  else if (uVar4 != 0xb) goto LAB_00424689;
  iVar8 = 0;
  while( true ) {
    if ((iVar5 != 0) && (pbVar9 = pbVar9 + 1, param_2 <= pbVar9)) {
      return 0;
    }
    bVar1 = (byte)iVar5;
    iVar5 = 4 - iVar5;
    uVar4 = *pbVar9 >> (bVar1 & 0x1f) & 0xf;
    if (9 < uVar4) break;
    iVar8 = uVar4 + iVar8 * 10;
  }
  if (bVar3) {
    iVar8 = -iVar8;
  }
  param_3 = param_3 + iVar8;
  pbVar7 = param_1;
LAB_00424689:
  if (param_3 < 1) {
    if (param_3 < 0) {
      iVar5 = -param_3;
      do {
        iVar10 = iVar10 / 10;
        uVar6 = uVar6 * 10;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  else {
    do {
      pbVar7 = (byte *)((int)pbVar7 * 10);
      iVar10 = iVar10 * 10;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  uVar4 = iVar10 << 0x10;
  if (pbVar7 != (byte *)0x0) {
    uVar6 = FUN_00410c00((uint)pbVar7,uVar6);
    uVar4 = uVar4 | uVar6;
  }
  if (bVar2) {
    uVar4 = -uVar4;
  }
  return uVar4;
}



uint __cdecl FUN_00424780(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)*param_1;
  if (*pbVar1 == 0x1e) {
    uVar2 = FUN_00424570(pbVar1,(byte *)param_1[1],0);
    return uVar2;
  }
  uVar2 = FUN_004244d0(pbVar1,(byte *)param_1[1]);
  return uVar2 << 0x10;
}



uint __cdecl FUN_004247f0(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)*param_1;
  if (*pbVar1 == 0x1e) {
    uVar2 = FUN_00424570(pbVar1,(byte *)param_1[1],0);
    return (int)uVar2 >> 0x10;
  }
  uVar2 = FUN_004244d0(pbVar1,(byte *)param_1[1]);
  return uVar2;
}



undefined4 * __cdecl FUN_00424880(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *local_4;
  
  piVar1 = param_1;
  iVar3 = *(int *)(*param_1 + 0x1c);
  param_1 = (int *)0x0;
  iVar2 = FUN_00424910(piVar1,param_2,(int *)&local_4,&param_2);
  if (iVar2 == 0) {
    iVar3 = FUN_00410c90(iVar3,param_2 + 1,&param_1);
    if (iVar3 == 0) {
      piVar5 = param_1;
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar5 = *local_4;
        local_4 = local_4 + 1;
        piVar5 = piVar5 + 1;
      }
      for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(char *)piVar5 = (char)*local_4;
        local_4 = (int *)((int)local_4 + 1);
        piVar5 = (int *)((int)piVar5 + 1);
      }
      *(undefined1 *)(param_2 + (int)param_1) = 0;
    }
    FUN_004249c0(piVar1,(int *)&local_4);
  }
  return param_1;
}



int __cdecl FUN_00424910(undefined4 *param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  
  if ((param_1 == (undefined4 *)0x0) || ((uint)param_1[1] <= param_2)) {
    return 6;
  }
  iVar2 = *(int *)(param_1[4] + param_2 * 4);
  iVar4 = param_1[4] + param_2 * 4;
  if (iVar2 != 0) {
    do {
      piVar1 = (int *)(iVar4 + 4);
      iVar4 = iVar4 + 4;
      param_2 = param_2 + 1;
      if (*piVar1 != 0) {
        uVar5 = *piVar1 - iVar2;
        *param_4 = uVar5;
        if (param_1[5] != 0) {
          *param_3 = param_1[5] + -1 + iVar2;
          return 0;
        }
        piVar1 = (int *)*param_1;
        bVar3 = FUN_00411790((int)piVar1,param_1[3] + -1 + iVar2);
        if (CONCAT31(extraout_var,bVar3) != 0) {
          return CONCAT31(extraout_var,bVar3);
        }
        iVar4 = FUN_004118a0(piVar1,uVar5,param_3);
        return iVar4;
      }
    } while (param_2 < (uint)param_1[1]);
  }
  *param_3 = 0;
  *param_4 = 0;
  return 0;
}



void __cdecl FUN_004249c0(int *param_1,int *param_2)

{
  if (param_1[5] == 0) {
    FUN_004118d0(*param_1,param_2);
    return;
  }
  return;
}



char * __cdecl FUN_004249e0(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  pcVar2 = param_2;
  if ((char *)0x186 < param_2) {
    pcVar2 = (char *)FUN_00424880(param_1,(uint)(param_2 + -0x187));
    return pcVar2;
  }
  param_2 = (char *)0x0;
  pcVar2 = (char *)(**(code **)(param_3 + 0x10))(pcVar2);
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar6 = pcVar2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar4 - 1;
    iVar3 = FUN_00410c90(*(int *)(*param_1 + 0x1c),~uVar4,&param_2);
    if (iVar3 == 0) {
      pcVar6 = param_2;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      }
      param_2[uVar5] = '\0';
    }
  }
  return param_2;
}



void __cdecl FUN_00424a70(int *param_1)

{
  int iVar1;
  
  if (param_1[10] != 0) {
    iVar1 = FUN_00424aa0(param_1);
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(param_1[10]);
    }
    param_1[10] = 0;
  }
  return;
}



undefined4 __cdecl FUN_00424aa0(int *param_1)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(*(int *)(*param_1 + 0x2b0) + 0x398);
  iVar2 = FUN_004116f0(*(int *)(*(int *)(*param_1 + 0x60) + 4),(byte *)s_pshinter_0043eb78);
  if (((iVar2 != 0) && (puVar1 != (undefined4 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)*puVar1, UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x00424ada. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (*UNRECOVERED_JUMPTABLE)();
    return uVar3;
  }
  return 0;
}



undefined4 __cdecl FUN_00424cc0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00424aa0(param_1);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(iVar1 + 4))(param_1[10],param_1[4],param_1[5],0,0);
    return uVar2;
  }
  return 0;
}



int * __cdecl FUN_00425090(int *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  puVar1 = param_3;
  local_1c = param_1[7];
  puVar4 = param_3;
  for (iVar5 = 0xe7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *param_3 = param_1;
  param_3[1] = local_1c;
  iVar5 = FUN_004117e0((int)param_1);
  piVar3 = (int *)FUN_00411d20(param_1,&DAT_00434b10,(int)param_3);
  if (piVar3 != (int *)0x0) {
    return piVar3;
  }
  if (((*(char *)(param_3 + 4) == '\x01') && (3 < *(byte *)((int)param_3 + 0x12))) &&
     (*(byte *)((int)param_3 + 0x13) < 5)) {
    piVar3 = (int *)FUN_004117c0((int)param_1,*(byte *)((int)param_3 + 0x12) - 4);
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    piVar3 = FUN_004253d0(param_3 + 5,param_1,'\0');
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    piVar3 = FUN_004253d0(param_3 + 0x2a,param_1,'\0');
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    piVar3 = FUN_004253d0(param_3 + 0x11,param_1,'\0');
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    piVar3 = FUN_004253d0(param_3 + 0x17,param_1,'\x01');
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    param_3[2] = param_3[6];
    piVar3 = (int *)0x0;
    if ((int)param_3[6] <= (int)param_2) {
      piVar3 = (int *)0x6;
    }
    if ((int)param_2 < 0) {
      return piVar3;
    }
    piVar3 = FUN_00425d80(param_3 + 0x3f,param_3 + 0x2a,param_2,param_1,iVar5);
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    if (param_3[0x61] == 0) {
      param_3[0xce] = 0;
    }
    else {
      bVar2 = FUN_00411790((int)param_1,param_3[0x69] + iVar5);
      if ((int *)CONCAT31(extraout_var,bVar2) != (int *)0x0) {
        return (int *)CONCAT31(extraout_var,bVar2);
      }
      piVar3 = FUN_004253d0(&local_18,param_1,bVar2);
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
      piVar3 = (int *)0x0;
      if (local_14 < 0x11) {
        param_3[0xce] = local_14;
        piVar3 = (int *)FUN_00410c90(local_1c,local_14 * 0x23c,&local_20);
        if (piVar3 == (int *)0x0) {
          if (local_14 != 0) {
            puVar4 = param_3 + 0xcf;
            puVar6 = local_20;
            uVar7 = local_14;
            do {
              *puVar4 = puVar6;
              puVar4 = puVar4 + 1;
              puVar6 = puVar6 + 0x8f;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          uVar7 = 0;
          if (local_14 != 0) {
            param_3 = param_3 + 0xcf;
            do {
              local_20 = (undefined4 *)*param_3;
              piVar3 = FUN_00425d80(local_20,&local_18,uVar7,param_1,iVar5);
              if (piVar3 != (int *)0x0) goto LAB_004252bf;
              uVar7 = uVar7 + 1;
              param_3 = param_3 + 1;
            } while (uVar7 < local_14);
          }
          piVar3 = (int *)FUN_00425620((char *)(puVar1 + 0xdf),puVar1[0x67],param_1,
                                       puVar1[0x6a] + iVar5);
        }
      }
LAB_004252bf:
      FUN_00425570(&local_18);
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
    }
    if (puVar1[0x5a] != 0) {
      bVar2 = FUN_00411790((int)param_1,puVar1[0x5a] + iVar5);
      if ((int *)CONCAT31(extraout_var_00,bVar2) != (int *)0x0) {
        return (int *)CONCAT31(extraout_var_00,bVar2);
      }
      piVar3 = FUN_004253d0(puVar1 + 0x24,param_1,bVar2);
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
      puVar1[0x3d] = puVar1[0x18];
      puVar1[3] = puVar1[0x25];
      piVar3 = (int *)FUN_004255b0(puVar1 + 0x17,puVar1 + 0x3e);
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
      piVar3 = FUN_004256b0(puVar1 + 0x21,puVar1[3],param_1,iVar5,puVar1[0x58]);
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
      piVar3 = (int *)FUN_00425950(puVar1 + 0x1d,puVar1 + 0x21,puVar1[3],param_1,iVar5,puVar1[0x59])
      ;
      if (piVar3 != (int *)0x0) {
        return piVar3;
      }
      puVar4 = FUN_00424880(puVar1 + 5,param_2);
      puVar1[0x3c] = puVar4;
      return (int *)0x0;
    }
  }
  return (int *)0x2;
}



int * __cdecl FUN_004253d0(undefined4 *param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_ECX;
  byte *pbVar7;
  short sVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint local_c;
  
  piVar2 = param_2;
  iVar1 = param_2[7];
  puVar9 = param_1;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *param_1 = param_2;
  uVar3 = FUN_00411b40(param_2,&param_2);
  if (param_2 == (int *)0x0) {
    sVar8 = (short)uVar3;
    if (sVar8 == 0) {
      return (int *)0x0;
    }
    uVar4 = FUN_00411ad0((uint3)extraout_ECX,piVar2,&param_2);
    if (param_2 == (int *)0x0) {
      *(byte *)(param_1 + 2) = (byte)uVar4;
      *param_1 = piVar2;
      iVar6 = (uVar3 & 0xffff) + 1;
      param_1[1] = uVar3 & 0xffff;
      param_2 = (int *)FUN_00410c90(iVar1,iVar6 * 4,param_1 + 4);
      if (param_2 == (int *)0x0) {
        param_2 = (int *)FUN_00411900(piVar2,(uVar4 & 0xff) * iVar6);
        if (param_2 == (int *)0x0) {
          puVar10 = (uint *)param_1[4];
          pbVar7 = (byte *)piVar2[8];
          param_2 = (int *)0x0;
          if (-1 < sVar8) {
            local_c = (uint)(ushort)(sVar8 + 1);
            do {
              uVar3 = FUN_00425540(pbVar7,(byte)uVar4);
              *puVar10 = uVar3;
              puVar10 = puVar10 + 1;
              pbVar7 = pbVar7 + (uVar4 & 0xff);
              local_c = local_c - 1;
            } while (local_c != 0);
          }
          FUN_004119a0(piVar2);
          uVar5 = FUN_004117e0((int)piVar2);
          param_1[3] = uVar5;
          if (param_3 == '\0') {
            param_2 = (int *)FUN_004117c0((int)piVar2,puVar10[-1] - 1);
            if (param_2 == (int *)0x0) {
              return (int *)0x0;
            }
          }
          else {
            param_2 = (int *)FUN_004118a0(piVar2,puVar10[-1] - 1,param_1 + 5);
            if (param_2 == (int *)0x0) {
              return (int *)0x0;
            }
          }
        }
      }
    }
  }
  FUN_00410d70(iVar1,param_1 + 4);
  return param_2;
}



uint __cdecl FUN_00425540(byte *param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar2 = (uint)param_2;
    do {
      uVar1 = uVar1 << 8 | (uint)*param_1;
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return uVar1;
}



void __cdecl FUN_00425570(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x1c);
    if (param_1[5] != 0) {
      FUN_004118d0(iVar2,param_1 + 5);
    }
    FUN_00410d70(iVar1,param_1 + 4);
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return;
}



void __cdecl FUN_004255b0(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = param_2;
  piVar1 = param_1;
  iVar3 = *(int *)(*param_1 + 0x1c);
  *param_2 = 0;
  if (param_1[1] != 0) {
    iVar3 = FUN_00410c90(iVar3,param_1[1] * 4 + 4,&param_1);
    if (iVar3 == 0) {
      uVar5 = 0;
      iVar3 = 1;
      do {
        iVar4 = *(int *)(piVar1[4] + uVar5 * 4);
        if (iVar4 == 0) {
          iVar4 = iVar3;
        }
        param_1[uVar5] = piVar1[5] + -1 + iVar4;
        uVar5 = uVar5 + 1;
        iVar3 = iVar4;
      } while (uVar5 <= (uint)piVar1[1]);
      *puVar2 = param_1;
    }
  }
  return;
}



int __cdecl FUN_00425620(char *param_1,undefined4 param_2,int *param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  
  bVar1 = FUN_00411790((int)param_3,param_4);
  param_4 = CONCAT31(extraout_var,bVar1);
  if ((param_4 != 0) || (uVar3 = FUN_00411ad0((uint3)&param_4,param_3,&param_4), param_4 != 0)) {
    return param_4;
  }
  cVar2 = (char)uVar3;
  *param_1 = cVar2;
  param_1[0x14] = '\0';
  param_1[0x15] = '\0';
  param_1[0x16] = '\0';
  param_1[0x17] = '\0';
  if (cVar2 == '\0') {
    *(undefined4 *)(param_1 + 0xc) = param_2;
  }
  else {
    if (cVar2 != '\x03') {
      return 3;
    }
    uVar3 = FUN_00411b40(param_3,&param_4);
    if (param_4 != 0) {
      return param_4;
    }
    *(uint *)(param_1 + 0xc) = (uVar3 & 0xffff) * 3 + 2;
  }
  iVar4 = FUN_004118a0(param_3,*(uint *)(param_1 + 0xc),(int *)(param_1 + 8));
  return iVar4;
}



int * __cdecl FUN_004256b0(uint *param_1,uint param_2,int *param_3,int param_4,uint param_5)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  undefined3 extraout_var;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  piVar3 = param_3;
  iVar2 = param_3[7];
  param_3 = (int *)0x0;
  param_1[1] = param_4 + param_5;
  bVar4 = FUN_00411790((int)piVar3,param_4 + param_5);
  param_3 = (int *)CONCAT31(extraout_var,bVar4);
  if (param_3 != (int *)0x0) goto LAB_00425914;
  uVar5 = FUN_00411ad0((uint3)extraout_ECX,piVar3,&param_3);
  *param_1 = uVar5 & 0xff;
  if (param_3 != (int *)0x0) goto LAB_00425914;
  if (param_5 < 3) {
    if (param_5 == 0) {
      if (param_2 != 0xe5) {
LAB_004258d3:
        param_3 = (int *)0x3;
        goto LAB_00425914;
      }
      param_3 = (int *)FUN_00410c90(iVar2,0x1ca,param_1 + 2);
      if (param_3 != (int *)0x0) goto LAB_00425914;
      iVar8 = 0x72;
      puVar9 = &DAT_00434340;
    }
    else {
      if (param_5 == 1) {
        if (param_2 != 0xa6) {
          param_3 = (int *)0x3;
          goto LAB_00425914;
        }
        param_3 = (int *)FUN_00410c90(iVar2,0x14c,param_1 + 2);
        if (param_3 != (int *)0x0) goto LAB_00425914;
        puVar9 = &DAT_00434510;
        puVar10 = (undefined4 *)param_1[2];
        for (iVar8 = 0x53; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        goto LAB_00425908;
      }
      if (param_5 != 2) {
        param_3 = (int *)0x3;
        goto LAB_00425914;
      }
      if (param_2 != 0x57) {
        param_3 = (int *)0x3;
        goto LAB_00425914;
      }
      param_3 = (int *)FUN_00410c90(iVar2,0xae,param_1 + 2);
      if (param_3 != (int *)0x0) goto LAB_00425914;
      iVar8 = 0x2b;
      puVar9 = &DAT_00434660;
    }
    puVar10 = (undefined4 *)param_1[2];
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = *(undefined2 *)puVar9;
  }
  else {
    puVar1 = param_1 + 2;
    param_3 = (int *)FUN_00410c90(iVar2,param_2 * 2,puVar1);
    if (param_3 != (int *)0x0) goto LAB_00425914;
    *(undefined2 *)*puVar1 = 0;
    if (*param_1 == 0) {
      uVar5 = 1;
      if (1 < param_2) {
        do {
          uVar6 = FUN_00411b40(piVar3,&param_3);
          if (param_3 != (int *)0x0) goto LAB_00425914;
          *(short *)(*puVar1 + uVar5 * 2) = (short)uVar6;
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
      }
    }
    else {
      if (2 < *param_1) goto LAB_004258d3;
      uVar5 = 1;
      if (1 < param_2) {
        do {
          uVar6 = FUN_00411b40(piVar3,&param_3);
          if (param_3 != (int *)0x0) goto LAB_00425914;
          if (*param_1 == 2) {
            uVar7 = FUN_00411b40(piVar3,&param_3);
            uVar7 = uVar7 & 0xffff;
          }
          else {
            uVar7 = FUN_00411ad0((uint3)extraout_ECX_00,piVar3,&param_3);
            uVar7 = uVar7 & 0xff;
          }
          if (param_3 != (int *)0x0) goto LAB_00425914;
          iVar8 = uVar7 + 1;
          do {
            *(short *)(param_1[2] + uVar5 * 2) = (short)uVar6;
            uVar5 = uVar5 + 1;
            uVar6 = uVar6 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        } while (uVar5 < param_2);
      }
    }
  }
LAB_00425908:
  if (param_3 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_00425914:
  if (param_1[2] != 0) {
    FUN_00410d70(iVar2,(int *)(param_1 + 2));
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return param_3;
}



int __cdecl
FUN_00425950(uint *param_1,undefined4 *param_2,uint param_3,int *param_4,int param_5,uint param_6)

{
  uint *puVar1;
  undefined2 uVar2;
  byte bVar3;
  uint uVar4;
  undefined3 extraout_var;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_ECX;
  uint extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int local_8;
  int local_4;
  
  local_4 = param_4[7];
  local_8 = 0;
  if (param_2[2] == 0) {
    local_8 = 3;
  }
  else {
    puVar1 = param_1 + 2;
    local_8 = FUN_00410c90(local_4,0x200,puVar1);
    if (local_8 == 0) {
      local_8 = FUN_00410c90(local_4,0x200,param_1 + 3);
      uVar4 = 0;
      if (local_8 == 0) {
        do {
          *(undefined2 *)(uVar4 + *puVar1) = 0;
          *(undefined2 *)(uVar4 + param_1[3]) = 0;
          uVar4 = uVar4 + 2;
        } while (uVar4 < 0x1fe);
        if (param_6 < 2) {
          if (param_6 == 0) {
            puVar11 = &DAT_00434710;
            puVar12 = (undefined4 *)*puVar1;
            for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
            uVar4 = 0;
            do {
              if (*(short *)(uVar4 + param_1[2]) != 0) {
                uVar6 = 1;
                if (1 < param_3) {
                  psVar10 = (short *)param_2[2];
                  do {
                    psVar10 = psVar10 + 1;
                    if (*psVar10 == *(short *)(uVar4 + param_1[2])) break;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < param_3);
                }
                if (uVar6 == param_3) {
                  *(undefined2 *)(uVar4 + param_1[3]) = 0;
                  *(undefined2 *)(uVar4 + param_1[2]) = 0;
                }
                else {
                  *(short *)(uVar4 + param_1[3]) = (short)uVar6;
                }
              }
              uVar4 = uVar4 + 2;
            } while (uVar4 < 0x200);
          }
          else {
            if (param_6 != 1) {
              local_8 = 3;
              goto LAB_00425d2b;
            }
            puVar11 = &DAT_00434910;
            puVar12 = (undefined4 *)*puVar1;
            for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
            uVar4 = 0;
            do {
              if (*(short *)(uVar4 + param_1[2]) != 0) {
                uVar6 = 1;
                if (1 < param_3) {
                  psVar10 = (short *)param_2[2];
                  do {
                    psVar10 = psVar10 + 1;
                    if (*psVar10 == *(short *)(uVar4 + param_1[2])) break;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < param_3);
                }
                if (uVar6 == param_3) {
                  *(undefined2 *)(uVar4 + param_1[3]) = 0;
                  *(undefined2 *)(uVar4 + param_1[2]) = 0;
                }
                else {
                  *(short *)(uVar4 + param_1[3]) = (short)uVar6;
                }
              }
              uVar4 = uVar4 + 2;
            } while (uVar4 < 0x200);
          }
        }
        else {
          param_1[1] = param_6 + param_5;
          bVar3 = FUN_00411790((int)param_4,param_6 + param_5);
          local_8 = CONCAT31(extraout_var,bVar3);
          if (local_8 != 0) goto LAB_00425d2b;
          uVar4 = FUN_00411ad0((uint3)extraout_ECX,param_4,&local_8);
          *param_1 = uVar4 & 0xff;
          if (local_8 != 0) goto LAB_00425d2b;
          uVar4 = FUN_00411ad0((uint3)&local_8,param_4,&local_8);
          uVar4 = uVar4 & 0xff;
          if (local_8 != 0) goto LAB_00425d2b;
          uVar6 = extraout_ECX_00;
          if ((*param_1 & 0x7f) == 0) {
            uVar9 = 1;
            if (uVar4 != 0) {
              do {
                uVar6 = FUN_00411ad0((uint3)uVar6,param_4,&local_8);
                if (local_8 != 0) goto LAB_00425d2b;
                if (param_3 < uVar9) {
                  return 0;
                }
                iVar7 = (uVar6 & 0xff) * 2;
                *(short *)(iVar7 + param_1[3]) = (short)uVar9;
                uVar2 = *(undefined2 *)(param_2[2] + uVar9 * 2);
                uVar6 = CONCAT22((short)((uint)param_2[2] >> 0x10),uVar2);
                uVar9 = uVar9 + 1;
                *(undefined2 *)(iVar7 + param_1[2]) = uVar2;
              } while (uVar9 <= uVar4);
            }
          }
          else {
            if ((*param_1 & 0x7f) != 1) {
              local_8 = 3;
              goto LAB_00425d2b;
            }
            uVar9 = 1;
            param_6 = 0;
            if (uVar4 != 0) {
              do {
                uVar5 = FUN_00411ad0((uint3)uVar6,param_4,&local_8);
                uVar5 = uVar5 & 0xff;
                if ((local_8 != 0) ||
                   (uVar6 = FUN_00411ad0((uint3)param_4,param_4,&local_8), local_8 != 0))
                goto LAB_00425d2b;
                uVar8 = (byte)((char)uVar6 + 1) + uVar9;
                for (uVar6 = uVar9; uVar6 < uVar8; uVar6 = uVar6 + 1) {
                  if (param_3 < uVar6) goto LAB_00425d1d;
                  iVar7 = uVar5 * 2;
                  *(short *)(iVar7 + param_1[3]) = (short)uVar6;
                  uVar5 = (uint)(byte)((char)uVar5 + 1);
                  *(undefined2 *)(iVar7 + param_1[2]) = *(undefined2 *)(param_2[2] + uVar6 * 2);
                }
                param_6 = param_6 + 1;
                uVar9 = uVar8;
              } while (param_6 < uVar4);
            }
          }
          if ((char)*param_1 < '\0') {
            uVar4 = FUN_00411ad0((uint3)uVar6,param_4,&local_8);
            if (local_8 != 0) goto LAB_00425d2b;
            uVar6 = 0;
            iVar7 = extraout_ECX_01;
            if ((uVar4 & 0xff) == 0) {
              return 0;
            }
            do {
              uVar9 = FUN_00411ad0((uint3)iVar7,param_4,&local_8);
              if ((local_8 != 0) || (uVar5 = FUN_00411b40(param_4,&local_8), local_8 != 0))
              goto LAB_00425d2b;
              iVar7 = (uVar9 & 0xff) * 2;
              *(short *)(iVar7 + param_1[2]) = (short)uVar5;
              uVar9 = 0;
              if (param_3 != 0) {
                psVar10 = (short *)param_2[2];
                do {
                  if (*psVar10 == (short)uVar5) break;
                  uVar9 = uVar9 + 1;
                  psVar10 = psVar10 + 1;
                } while (uVar9 < param_3);
              }
              uVar6 = uVar6 + 1;
              *(short *)(iVar7 + param_1[3]) = (short)uVar9;
            } while (uVar6 < (uVar4 & 0xff));
          }
        }
LAB_00425d1d:
        if (local_8 == 0) {
          return 0;
        }
      }
    }
  }
LAB_00425d2b:
  if (param_1[2] == 0) {
    if (param_1[3] == 0) {
      return local_8;
    }
  }
  else {
    FUN_00410d70(local_4,(int *)(param_1 + 2));
  }
  if (param_1[3] != 0) {
    FUN_00410d70(local_4,(int *)(param_1 + 3));
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  return local_8;
}



int * __cdecl FUN_00425d80(undefined4 *param_1,int *param_2,uint param_3,int *param_4,int param_5)

{
  byte bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  byte *local_1a4;
  uint local_1a0;
  undefined4 local_19c [103];
  
  FUN_00425f70(local_19c,0x1000,param_1);
  puVar4 = param_1;
  for (iVar2 = 0x2d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  param_1[0xc] = 0x10000;
  param_1[0xf] = 0x10000;
  param_1[8] = 0xffffff9c;
  param_1[9] = 0x32;
  param_1[0xb] = 2;
  param_1[0x28] = 0x2210;
  iVar2 = FUN_00424910(param_2,param_3,(int *)&local_1a4,&local_1a0);
  if ((iVar2 == 0) && (iVar2 = FUN_00425fa0(local_19c,local_1a4,local_1a4 + local_1a0), iVar2 == 0))
  {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)0x1;
  }
  FUN_004249c0(param_2,(int *)&local_1a4);
  if (piVar3 != (int *)0x0) {
    return piVar3;
  }
  if (param_1[0x22] != 0) {
    return (int *)0x0;
  }
  if ((param_1[0x1c] != 0) && (param_1[0x1d] != 0)) {
    puVar4 = param_1 + 0x2d;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    param_1[0x82] = 0;
    param_1[0x5e] = 0;
    param_1[0x5f] = 7;
    param_1[0x60] = 1;
    param_1[0x80] = 0xffffffff;
    FUN_00425f70(local_19c,0x2000,param_1 + 0x2d);
    bVar1 = FUN_00411790((int)param_4,param_1[0x1c] + param_5);
    if ((int *)CONCAT31(extraout_var,bVar1) != (int *)0x0) {
      return (int *)CONCAT31(extraout_var,bVar1);
    }
    piVar3 = (int *)FUN_00411900(param_4,param_1[0x1d]);
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    piVar3 = (int *)FUN_00425fa0(local_19c,(byte *)param_4[8],(byte *)param_4[9]);
    FUN_004119a0(param_4);
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
  }
  piVar3 = (int *)0x0;
  if (param_1[0x84] != 0) {
    bVar1 = FUN_00411790((int)param_4,param_1[0x1c] + param_1[0x84] + param_5);
    piVar3 = (int *)CONCAT31(extraout_var_00,bVar1);
    if (piVar3 == (int *)0x0) {
      piVar3 = FUN_004253d0(param_1 + 0x87,param_4,'\x01');
      if (piVar3 == (int *)0x0) {
        param_1[0x8d] = param_1[0x88];
        piVar3 = (int *)FUN_004255b0(param_1 + 0x87,param_1 + 0x8e);
      }
    }
  }
  return piVar3;
}



void __cdecl FUN_00425f70(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x67; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[100] = param_1 + 3;
  param_1[0x65] = param_2;
  param_1[0x66] = param_3;
  return;
}



int __cdecl FUN_00425fa0(undefined4 *param_1,byte *param_2,byte *param_3)

{
  byte *pbVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int local_8;
  
  local_8 = 0;
  param_1[100] = param_1 + 3;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_2;
  if (param_3 <= param_2) {
    return 0;
  }
  while ((uVar6 = (uint)*param_2, 0x1a < uVar6 && (uVar6 != 0x1f))) {
    if (0x17f < (int)((int)param_1[100] + (-0xc - (int)param_1) & 0xfffffffcU)) {
      return 6;
    }
    *(byte **)param_1[100] = param_2;
    param_1[100] = param_1[100] + 4;
    if (uVar6 == 0x1e) {
      do {
        param_2 = param_2 + 1;
        if (param_3 <= param_2) {
          return 6;
        }
      } while (((*param_2 & 0xf0) != 0xf0) && ((*param_2 & 0xf) != 0xf));
    }
    else if (uVar6 == 0x1c) {
      param_2 = param_2 + 2;
    }
    else if (uVar6 == 0x1d) {
      param_2 = param_2 + 4;
    }
    else if (0xf6 < uVar6) {
      param_2 = param_2 + 1;
    }
LAB_0042617b:
    param_2 = param_2 + 1;
    if (param_3 <= param_2) {
      return local_8;
    }
  }
  uVar4 = (int)param_1[100] + (-0xc - (int)param_1) >> 2;
  if (uVar4 == 0) {
    return 6;
  }
  *(byte **)param_1[100] = param_2;
  if (uVar6 == 0xc) {
    pbVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    uVar6 = *pbVar1 | 0x100;
  }
  puVar7 = (undefined4 *)&DAT_00433d70;
  while (puVar7[1] != (uVar6 | param_1[0x65])) {
    piVar2 = puVar7 + 7;
    puVar7 = puVar7 + 7;
    if (*piVar2 == 0) goto LAB_0042616e;
  }
  puVar8 = (uint *)(puVar7[2] + param_1[0x66]);
  switch(*puVar7) {
  case 1:
  case 3:
  case 4:
    uVar6 = FUN_004247f0(param_1 + 3);
    break;
  case 2:
    uVar6 = FUN_00424780(param_1 + 3);
    break;
  case 5:
    if ((uint)puVar7[5] < uVar4) {
      uVar4 = puVar7[5];
    }
    uVar6 = 0;
    *(char *)(puVar7[6] + param_1[0x66]) = (char)uVar4;
    puVar3 = param_1 + 3;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      uVar5 = FUN_004247f0(puVar3);
      uVar6 = uVar6 + uVar5;
      if (*(char *)(puVar7 + 3) == '\x01') {
        *(char *)puVar8 = (char)uVar6;
      }
      else if (*(char *)(puVar7 + 3) == '\x02') {
        *(short *)puVar8 = (short)uVar6;
      }
      else {
        *puVar8 = uVar6;
      }
      puVar8 = (uint *)((int)puVar8 + (uint)*(byte *)(puVar7 + 3));
      puVar3 = puVar3 + 1;
    }
LAB_0042616e:
    param_1[100] = param_1 + 3;
    goto LAB_0042617b;
  default:
    local_8 = (*(code *)puVar7[4])(param_1);
    if (local_8 != 0) {
      return local_8;
    }
    goto LAB_0042616e;
  }
  if (*(char *)(puVar7 + 3) == '\x01') {
    *(char *)puVar8 = (char)uVar6;
  }
  else if (*(char *)(puVar7 + 3) == '\x02') {
    *(short *)puVar8 = (short)uVar6;
  }
  else {
    *puVar8 = uVar6;
  }
  goto LAB_0042616e;
}



char * __cdecl FUN_004261e0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *local_4;
  
  uVar3 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar3 - 1;
  local_4 = (char *)0x0;
  iVar2 = FUN_00410c90(param_1,~uVar3,&local_4);
  if (iVar2 == 0) {
    pcVar5 = local_4;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *param_2;
      param_2 = param_2 + 1;
      pcVar5 = pcVar5 + 1;
    }
    local_4[uVar4] = '\0';
  }
  return local_4;
}



int __cdecl FUN_00426240(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = &DAT_00434b28;
  while ((*piVar1 != param_1 || ((piVar1[1] != param_2 && (piVar1[1] != -1))))) {
    piVar1 = piVar1 + 3;
    if (&UNK_00434b93 < piVar1) {
      return 0;
    }
  }
  return piVar1[2];
}



void __cdecl FUN_00426280(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 100);
  if (*(int *)(param_1 + 0x210) != 0) {
    (**(code **)(*(int *)(param_1 + 0x210) + 0xc))(param_1);
  }
  if (*(int **)(param_1 + 0x2b0) != (int *)0x0) {
    FUN_004262c0(*(int **)(param_1 + 0x2b0));
    FUN_00410d70(iVar1,(int *)(param_1 + 0x2b0));
  }
  return;
}



void __cdecl FUN_004262c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = param_1[1];
  FUN_00425570(param_1 + 0x17);
  FUN_00425570(param_1 + 0x11);
  FUN_00425570(param_1 + 0x2a);
  FUN_00425570(param_1 + 5);
  FUN_00425570(param_1 + 0x24);
  if (param_1[0xce] != 0) {
    uVar3 = 0;
    if (param_1[0xce] != 0) {
      piVar2 = param_1 + 0xcf;
      do {
        FUN_00426450(iVar1,*piVar2);
        uVar3 = uVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar3 < (uint)param_1[0xce]);
    }
    FUN_00410d70(iVar1,param_1 + 0xcf);
  }
  FUN_004263d0(param_1 + 0x1d,*param_1);
  FUN_00426420(param_1 + 0x21,*param_1);
  FUN_00426450(iVar1,(int)(param_1 + 0x3f));
  FUN_004263a0((undefined1 *)(param_1 + 0xdf),*param_1);
  FUN_00410d70(iVar1,param_1 + 0x3e);
  FUN_00410d70(iVar1,param_1 + 0x3c);
  return;
}



void __cdecl FUN_004263a0(undefined1 *param_1,int param_2)

{
  if (*(int *)(param_1 + 8) != 0) {
    FUN_004118d0(param_2,(int *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



void __cdecl FUN_004263d0(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  FUN_00410d70(iVar1,param_1 + 3);
  FUN_00410d70(iVar1,param_1 + 2);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



void __cdecl FUN_00426420(undefined4 *param_1,int param_2)

{
  FUN_00410d70(*(int *)(param_2 + 0x1c),param_1 + 2);
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



void __cdecl FUN_00426450(int param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_00425570((int *)(param_2 + 0x21c));
    FUN_00410d70(param_1,(int *)(param_2 + 0x238));
  }
  return;
}



void __cdecl FUN_00426810(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x10);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 8) + 0x6c);
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}



void __cdecl FUN_00426830(undefined4 *param_1,int param_2,int param_3,int param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_2 + 0x2b0);
  puVar4 = param_1;
  for (iVar3 = 0xce; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  FUN_00426890(param_1,param_2,param_3,param_4,param_5);
  uVar1 = *(uint *)(iVar2 + 0xf4);
  param_1[199] = uVar1;
  param_1[0xcb] = *(undefined4 *)(iVar2 + 0xf8);
  iVar2 = FUN_00426930(uVar1);
  param_1[0xc9] = iVar2;
  return;
}



void __cdecl FUN_00426890(undefined4 *param_1,int param_2,int param_3,int param_4,char param_5)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 0x51) = 1;
  param_1[1] = param_2;
  param_1[2] = param_4;
  *param_1 = *(undefined4 *)(param_2 + 100);
  if (param_4 != 0) {
    iVar1 = **(int **)(param_4 + 0x94);
    param_1[3] = iVar1;
    param_1[4] = iVar1 + 0x14;
    param_1[5] = iVar1 + 0x34;
    FUN_00410dd0(iVar1);
    param_1[0x18] = 0;
    param_1[0x17] = 0;
    if (param_5 != '\0') {
      if (param_3 == 0) goto LAB_00426910;
      param_1[0x18] = *(undefined4 *)(param_3 + 0x28);
      param_1[0x17] = *(undefined4 *)(*(int *)(param_4 + 0x94) + 0x20);
    }
  }
  if (param_3 != 0) {
    param_1[8] = *(undefined4 *)(param_3 + 0x10);
    param_1[9] = *(undefined4 *)(param_3 + 0x14);
  }
LAB_00426910:
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return;
}



int __cdecl FUN_00426930(uint param_1)

{
  if (param_1 < 0x4d8) {
    return 0x6b;
  }
  return (-(uint)(param_1 < 0x846c) & 0xffff846b) + 0x8000;
}



void __cdecl FUN_00426960(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int extraout_ECX;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x2b0);
  iVar4 = iVar1 + 0xfc;
  if (*(int *)(iVar1 + 0x338) != 0) {
    bVar3 = FUN_004269e0((char *)(iVar1 + 0x37c),param_2);
    iVar4 = *(int *)(iVar1 + 0x33c + (uint)bVar3 * 4);
  }
  uVar2 = *(uint *)(iVar4 + 0x234);
  *(uint *)(param_1 + 0x318) = uVar2;
  *(undefined4 *)(param_1 + 0x328) = *(undefined4 *)(iVar4 + 0x238);
  iVar4 = FUN_00426930(uVar2);
  *(int *)(param_1 + 800) = iVar4;
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(extraout_ECX + 0x214);
  *(undefined4 *)(param_1 + 0x304) = *(undefined4 *)(extraout_ECX + 0x218);
  return;
}



char __cdecl FUN_004269e0(char *param_1,uint param_2)

{
  char cVar1;
  undefined1 *puVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  
  cVar3 = '\0';
  if (*param_1 == '\0') {
    cVar3 = *(char *)(param_2 + *(int *)(param_1 + 8));
  }
  else if (*param_1 == '\x03') {
    if (param_2 - *(int *)(param_1 + 0x10) < *(uint *)(param_1 + 0x14)) {
      return param_1[0x18];
    }
    puVar2 = *(undefined1 **)(param_1 + 8);
    pcVar4 = puVar2 + 2;
    uVar6 = (uint)CONCAT11(*puVar2,puVar2[1]);
    while (uVar6 <= param_2) {
      cVar1 = *pcVar4;
      pcVar5 = pcVar4 + 3;
      uVar7 = (uint)CONCAT11(pcVar4[1],pcVar4[2]);
      if (param_2 < uVar7) {
        *(uint *)(param_1 + 0x10) = uVar6;
        param_1[0x18] = cVar1;
        *(uint *)(param_1 + 0x14) = uVar7 - uVar6;
        return cVar1;
      }
      pcVar4 = pcVar5;
      uVar6 = uVar7;
      if (puVar2 + *(int *)(param_1 + 0xc) <= pcVar5) {
        return '\0';
      }
    }
  }
  return cVar3;
}



int __cdecl FUN_00426a70(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  char cVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  sbyte sVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  uint *puVar16;
  int iVar17;
  bool bVar18;
  byte *local_24;
  uint *puStack_20;
  int *local_1c;
  byte *local_18;
  uint local_10;
  uint uStack_c;
  uint uStack_8;
  int local_4;
  
  iVar17 = param_1;
  *(undefined4 *)(param_1 + 0x30c) = 0;
  *(undefined1 *)(param_1 + 0x308) = 1;
  uVar6 = (uint)&local_10 ^ (uint)&param_1 ^ (uint)&param_2;
  local_10 = ((int)uVar6 >> 0x14 ^ uVar6) & 0xffff ^ (int)uVar6 >> 10 & 0xffffU;
  local_4 = param_1;
  if (local_10 == 0) {
    local_10 = 0x7384;
  }
  *(int *)(param_1 + 300) = param_1 + 0x68;
  *(int *)(param_1 + 700) = param_1 + 0x130;
  puVar2 = *(uint **)(param_1 + 300);
  local_1c = (int *)(param_1 + 0x130);
  *(undefined1 *)(param_1 + 0x50) = 0;
  puVar3 = *(undefined4 **)(param_1 + 0x5c);
  *local_1c = param_2;
  local_18 = (byte *)(param_3 + param_2);
  *(byte **)(param_1 + 0x134) = local_18;
  local_24 = (byte *)*local_1c;
  *(byte **)(param_1 + 0x138) = local_24;
  uVar6 = *(uint *)(param_1 + 0x28);
  uVar14 = *(uint *)(param_1 + 0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    (*(code *)puVar3[1])(*puVar3);
  }
  if (local_24 < local_18) {
    do {
      bVar1 = *local_24;
      pbVar15 = local_24 + 1;
      if ((0x1f < bVar1) || (bVar1 == 0x1c)) {
        sVar11 = 0x10;
        if (bVar1 == 0x1c) {
          if (local_18 <= local_24 + 2) {
            return 3;
          }
          uVar12 = (int)(short)((ushort)*pbVar15 << 8) | (uint)local_24[2];
          local_24 = local_24 + 3;
        }
        else if (bVar1 < 0xf7) {
          uVar12 = bVar1 - 0x8b;
          local_24 = pbVar15;
        }
        else if (bVar1 < 0xfb) {
          if (local_18 <= pbVar15) {
            return 3;
          }
          uVar12 = (uint)bVar1 * 0x100 + -0xf694 + (uint)*pbVar15;
          local_24 = local_24 + 2;
        }
        else if (bVar1 == 0xff) {
          if (local_18 <= local_24 + 4) {
            return 3;
          }
          uVar12 = CONCAT31(CONCAT21(CONCAT11(*pbVar15,local_24[2]),local_24[3]),local_24[4]);
          sVar11 = 0;
          local_24 = local_24 + 5;
        }
        else {
          if (local_18 <= pbVar15) {
            return 3;
          }
          uVar12 = ((uint)bVar1 * -0x100 + 0xfa94) - (uint)*pbVar15;
          local_24 = local_24 + 2;
        }
        if (0xbf < (int)((int)*(int **)(param_1 + 300) - (int)puVar2 & 0xfffffffcU)) {
          return 0x82;
        }
        **(int **)(param_1 + 300) = uVar12 << sVar11;
        *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 4;
        goto LAB_00427efa;
      }
      puStack_20 = *(uint **)(param_1 + 300);
      uVar12 = (int)puStack_20 + (-0x68 - param_1) >> 2;
      switch(bVar1) {
      case 1:
        param_3 = 0x13;
        local_24 = pbVar15;
        break;
      default:
        goto switchD_00426c04_caseD_1;
      case 3:
        param_3 = 0x14;
        local_24 = pbVar15;
        break;
      case 4:
        param_3 = 3;
        local_24 = pbVar15;
        break;
      case 5:
        param_3 = 4;
        local_24 = pbVar15;
        break;
      case 6:
        param_3 = 5;
        local_24 = pbVar15;
        break;
      case 7:
        param_3 = 6;
        local_24 = pbVar15;
        break;
      case 8:
        param_3 = 7;
        local_24 = pbVar15;
        break;
      case 10:
        param_3 = 0x31;
        local_24 = pbVar15;
        break;
      case 0xb:
        param_3 = 0x33;
        local_24 = pbVar15;
        break;
      case 0xc:
        if (local_18 <= pbVar15) {
          return 3;
        }
        local_24 = local_24 + 2;
        switch(*pbVar15) {
        case 0:
          param_3 = 0x19;
          break;
        default:
          goto switchD_00426c04_caseD_1;
        case 3:
          param_3 = 0x2c;
          break;
        case 4:
          param_3 = 0x2d;
          break;
        case 5:
          param_3 = 0x2e;
          break;
        case 8:
          param_3 = 0x2a;
          break;
        case 9:
          param_3 = 0x1a;
          break;
        case 10:
          param_3 = 0x1b;
          break;
        case 0xb:
          param_3 = 0x1c;
          break;
        case 0xc:
          param_3 = 0x1d;
          break;
        case 0xd:
          param_3 = 0x2b;
          break;
        case 0xe:
          param_3 = 0x1e;
          break;
        case 0xf:
          param_3 = 0x2f;
          break;
        case 0x12:
          param_3 = 0x23;
          break;
        case 0x14:
          param_3 = 0x28;
          break;
        case 0x15:
          param_3 = 0x29;
          break;
        case 0x16:
          param_3 = 0x30;
          break;
        case 0x17:
          param_3 = 0x1f;
          break;
        case 0x18:
          param_3 = 0x20;
          break;
        case 0x1a:
          param_3 = 0x21;
          break;
        case 0x1b:
          param_3 = 0x27;
          break;
        case 0x1c:
          param_3 = 0x24;
          break;
        case 0x1d:
          param_3 = 0x25;
          break;
        case 0x1e:
          param_3 = 0x26;
          break;
        case 0x22:
          param_3 = 0xf;
          break;
        case 0x23:
          param_3 = 0xe;
          break;
        case 0x24:
          param_3 = 0x10;
          break;
        case 0x25:
          param_3 = 0x11;
        }
        break;
      case 0xe:
        param_3 = 0x12;
        local_24 = pbVar15;
        break;
      case 0x10:
        param_3 = 0x22;
        local_24 = pbVar15;
        break;
      case 0x12:
        param_3 = 0x15;
        local_24 = pbVar15;
        break;
      case 0x13:
        param_3 = 0x17;
        local_24 = pbVar15;
        break;
      case 0x14:
        param_3 = 0x18;
        local_24 = pbVar15;
        break;
      case 0x15:
        param_3 = 1;
        local_24 = pbVar15;
        break;
      case 0x16:
        param_3 = 2;
        local_24 = pbVar15;
        break;
      case 0x17:
        param_3 = 0x16;
        local_24 = pbVar15;
        break;
      case 0x18:
        param_3 = 10;
        local_24 = pbVar15;
        break;
      case 0x19:
        param_3 = 0xb;
        local_24 = pbVar15;
        break;
      case 0x1a:
        param_3 = 0xd;
        local_24 = pbVar15;
        break;
      case 0x1b:
        param_3 = 8;
        local_24 = pbVar15;
        break;
      case 0x1d:
        param_3 = 0x32;
        local_24 = pbVar15;
        break;
      case 0x1e:
        param_3 = 0xc;
        local_24 = pbVar15;
        break;
      case 0x1f:
        param_3 = 9;
        local_24 = pbVar15;
      }
      uVar13 = (uint)(byte)(&DAT_00434b94)[param_3];
      if ((char)(&DAT_00434b94)[param_3] < '\0') {
        puStack_20 = puVar2;
        if ((0 < (int)uVar12) && (*(char *)(param_1 + 0x308) != '\0')) {
          switch(param_3) {
          case 1:
          case 0x13:
          case 0x14:
          case 0x15:
          case 0x16:
            uVar13 = uVar12 & 1;
            break;
          case 2:
          case 3:
            uVar13 = uVar12 & 2;
            break;
          default:
            goto switchD_00426da9_caseD_4;
          case 0x12:
            if ((uVar12 != 5) && (uVar12 != 1)) goto switchD_00426da9_caseD_4;
            goto LAB_00426db9;
          }
          if (uVar13 != 0) {
LAB_00426db9:
            uVar12 = uVar12 - 1;
            *(int *)(param_1 + 0x300) = (int)*(short *)((int)puVar2 + 2) + *(int *)(param_1 + 0x304)
            ;
            puStack_20 = puVar2 + 1;
          }
        }
switchD_00426da9_caseD_4:
        *(undefined1 *)(param_1 + 0x308) = 0;
        uVar13 = 0;
      }
      uVar13 = uVar13 & 0xf;
      if ((int)uVar12 < (int)uVar13) {
        return 0x81;
      }
      uVar12 = uVar12 - uVar13;
      puVar7 = puStack_20 + -uVar13;
      switch(param_3) {
      case 1:
        FUN_00428310(iVar17);
        *(undefined1 *)(iVar17 + 0x50) = 0;
        uVar6 = uVar6 + *puVar7;
        uVar14 = uVar14 + puVar7[1];
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 2:
        FUN_00428310(iVar17);
        *(undefined1 *)(iVar17 + 0x50) = 0;
        uVar6 = uVar6 + *puVar7;
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 3:
        FUN_00428310(iVar17);
        *(undefined1 *)(iVar17 + 0x50) = 0;
        uVar14 = uVar14 + *puVar7;
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 4:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,(int)uVar12 / 2), iVar8 != 0))
        goto LAB_00427f13;
        if ((int)uVar12 < 2) {
          return 0x81;
        }
        if ((uVar12 & 1) != 0) {
          return 0x81;
        }
        puVar7 = puVar2;
        if (*(uint **)(param_1 + 300) <= puVar2) goto LAB_00427806;
        do {
          uVar14 = uVar14 + puVar7[1];
          uVar6 = uVar6 + *puVar7;
          FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
          puVar7 = puVar7 + 2;
        } while (puVar7 < *(uint **)(param_1 + 300));
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 5:
      case 6:
        param_3 = (uint)(param_3 == 5);
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,uVar12), iVar8 != 0)) goto LAB_00427f13;
        puVar7 = puVar2;
        if (*(uint **)(param_1 + 300) <= puVar2) goto LAB_00427806;
        do {
          if (param_3 == 0) {
            uVar14 = uVar14 + *puVar7;
          }
          else {
            uVar6 = uVar6 + *puVar7;
          }
          iVar8 = FUN_00428240(iVar17,uVar6,uVar14);
          if (iVar8 != 0) goto LAB_00427f13;
          param_3 = param_3 ^ 1;
          puVar7 = puVar7 + 1;
        } while (puVar7 < *(uint **)(param_1 + 300));
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 7:
        if ((int)uVar12 % 6 != 0) {
          return 0x81;
        }
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,(int)uVar12 / 2), iVar8 != 0))
        goto LAB_00427f13;
        if (*(uint **)(param_1 + 300) <= puVar2) goto LAB_00427806;
        puVar7 = puVar2 + 2;
        do {
          uVar12 = puVar7[-1];
          uVar13 = puVar7[-2];
          FUN_004281e0(iVar17,uVar6 + uVar13,uVar14 + uVar12,'\0');
          iVar8 = uVar14 + uVar12 + puVar7[1];
          iVar10 = uVar6 + uVar13 + *puVar7;
          FUN_004281e0(iVar17,iVar10,iVar8,'\0');
          uVar14 = iVar8 + puVar7[3];
          uVar6 = iVar10 + puVar7[2];
          FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
          puVar4 = puVar7 + 4;
          puVar7 = puVar7 + 6;
        } while (puVar4 < *(uint **)(param_1 + 300));
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 8:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if (iVar8 != 0) {
LAB_00427f13:
          return *(int *)(iVar17 + 0x54);
        }
        puVar7 = puVar2;
        if ((uVar12 & 1) != 0) {
          uVar14 = uVar14 + *puVar2;
          puVar7 = puVar2 + 1;
          uVar12 = uVar12 - 1;
        }
        uVar13 = uVar12 & 0x80000003;
        bVar18 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar18 = (uVar13 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (!bVar18) {
          return 0x81;
        }
        iVar8 = FUN_00420710(iVar17,((int)(uVar12 + ((int)uVar12 >> 0x1f & 3U)) >> 2) * 3);
        if (iVar8 != 0) goto LAB_00427f13;
        if (*(uint **)(param_1 + 300) <= puVar7) goto LAB_00427806;
        do {
          uVar12 = *puVar7;
          FUN_004281e0(iVar17,uVar6 + uVar12,uVar14,'\0');
          uVar14 = uVar14 + puVar7[2];
          iVar8 = uVar6 + uVar12 + puVar7[1];
          FUN_004281e0(iVar17,iVar8,uVar14,'\0');
          uVar6 = iVar8 + puVar7[3];
          FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
          puVar7 = puVar7 + 4;
        } while (puVar7 < *(uint **)(param_1 + 300));
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 9:
      case 0xc:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if (iVar8 != 0) goto LAB_00427f13;
        if ((int)uVar12 < 4) {
          return 0x81;
        }
        uVar13 = uVar12 & 0x80000003;
        if ((int)uVar13 < 0) {
          uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar13) {
          return 0x81;
        }
        iVar8 = FUN_00420710(iVar17,((int)(uVar12 + ((int)uVar12 >> 0x1f & 3U)) >> 2) * 3);
        if (iVar8 != 0) {
          return 0x81;
        }
        param_3 = (uint)(param_3 == 9);
        puVar7 = puVar2 + 2;
        puStack_20 = (uint *)uVar12;
        do {
          puStack_20 = (uint *)((int)puStack_20 - 4);
          if (param_3 == 0) {
            iVar8 = uVar14 + puVar7[-2];
            FUN_004281e0(iVar17,uVar6,iVar8,'\0');
            uVar12 = puVar7[-1];
            uVar14 = iVar8 + *puVar7;
            FUN_004281e0(iVar17,uVar6 + uVar12,uVar14,'\0');
            uVar6 = uVar6 + uVar12 + puVar7[1];
            if (puStack_20 == (uint *)0x1) {
              uVar14 = uVar14 + puVar7[2];
            }
          }
          else {
            iVar8 = uVar6 + puVar7[-2];
            FUN_004281e0(iVar17,iVar8,uVar14,'\0');
            uVar12 = *puVar7;
            uVar6 = iVar8 + puVar7[-1];
            FUN_004281e0(iVar17,uVar6,uVar14 + uVar12,'\0');
            uVar14 = uVar14 + uVar12 + puVar7[1];
            if (puStack_20 == (uint *)0x1) {
              uVar6 = uVar6 + puVar7[2];
            }
          }
          FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
          param_3 = param_3 ^ 1;
          puVar7 = puVar7 + 4;
        } while (3 < (int)puStack_20);
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 10:
        uVar13 = (int)(uVar12 - 2) / 6;
        if ((int)uVar12 < 8) {
          return 0x81;
        }
        if ((int)(uVar12 - 2) % 6 != 0) {
          return 0x81;
        }
        param_3 = uVar13;
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,uVar13 * 3 + 2), iVar8 != 0))
        goto LAB_00427f13;
        puVar7 = puVar2;
        if (0 < (int)param_3) {
          do {
            uVar12 = puVar7[1];
            uVar13 = *puVar7;
            FUN_004281e0(iVar17,uVar6 + uVar13,uVar14 + uVar12,'\0');
            iVar8 = uVar14 + uVar12 + puVar7[3];
            iVar10 = uVar6 + uVar13 + puVar7[2];
            FUN_004281e0(iVar17,iVar10,iVar8,'\0');
            uVar14 = iVar8 + puVar7[5];
            uVar6 = iVar10 + puVar7[4];
            FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
            puVar7 = puVar7 + 6;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        uVar6 = uVar6 + *puVar7;
        uVar14 = uVar14 + puVar7[1];
        goto LAB_004277f9;
      case 0xb:
        uVar13 = (int)(uVar12 - 6) / 2;
        if ((int)uVar12 < 8) {
          return 0x81;
        }
        if ((uVar12 & 1) != 0) {
          return 0x81;
        }
        param_3 = uVar13;
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,uVar13 + 3), iVar8 != 0))
        goto LAB_00427f13;
        puVar7 = puVar2;
        if (0 < (int)param_3) {
          do {
            uVar14 = uVar14 + puVar7[1];
            uVar6 = uVar6 + *puVar7;
            FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
            puVar7 = puVar7 + 2;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        uVar12 = puVar7[1];
        uVar13 = *puVar7;
        FUN_004281e0(iVar17,uVar6 + uVar13,uVar14 + uVar12,'\0');
        iVar8 = uVar14 + uVar12 + puVar7[3];
        iVar10 = uVar6 + uVar13 + puVar7[2];
        FUN_004281e0(iVar17,iVar10,iVar8,'\0');
        uVar14 = iVar8 + puVar7[5];
        uVar6 = iVar10 + puVar7[4];
        FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0xd:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if (iVar8 != 0) goto LAB_00427f13;
        puVar7 = puVar2;
        if ((uVar12 & 1) != 0) {
          uVar6 = uVar6 + *puVar2;
          puVar7 = puVar2 + 1;
          uVar12 = uVar12 - 1;
        }
        uVar13 = uVar12 & 0x80000003;
        bVar18 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar18 = (uVar13 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (!bVar18) {
          return 0x81;
        }
        iVar8 = FUN_00420710(iVar17,((int)(uVar12 + ((int)uVar12 >> 0x1f & 3U)) >> 2) * 3);
        if (iVar8 != 0) goto LAB_00427f13;
        if (*(uint **)(param_1 + 300) <= puVar7) goto LAB_00427806;
        do {
          uVar12 = *puVar7;
          FUN_004281e0(iVar17,uVar6,uVar14 + uVar12,'\0');
          iVar8 = uVar14 + uVar12 + puVar7[2];
          uVar6 = uVar6 + puVar7[1];
          FUN_004281e0(iVar17,uVar6,iVar8,'\0');
          uVar14 = iVar8 + puVar7[3];
          FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
          puVar7 = puVar7 + 4;
        } while (puVar7 < *(uint **)(param_1 + 300));
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0xe:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,6), iVar8 != 0)) goto LAB_00427f13;
        param_3 = 6;
        puVar7 = puVar2;
        do {
          uVar6 = uVar6 + *puVar7;
          uVar14 = uVar14 + puVar7[1];
          if ((param_3 == 3) || (param_3 == 0)) {
            cVar5 = '\x01';
          }
          else {
            cVar5 = '\0';
          }
          FUN_004281e0(iVar17,uVar6,uVar14,cVar5);
          puVar7 = puVar7 + 2;
          param_3 = param_3 - 1;
        } while (param_3 != 0);
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0xf:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,6), iVar8 != 0)) goto LAB_00427f13;
        uVar12 = *puVar2;
        param_3 = uVar14;
        FUN_004281e0(iVar17,uVar6 + uVar12,uVar14,'\0');
        iVar8 = uVar14 + puVar2[2];
        iVar10 = uVar6 + uVar12 + puVar2[1];
        FUN_004281e0(iVar17,iVar10,iVar8,'\0');
        iVar10 = iVar10 + puVar2[3];
        FUN_004281e0(iVar17,iVar10,iVar8,'\x01');
        iVar10 = iVar10 + puVar2[4];
        FUN_004281e0(iVar17,iVar10,iVar8,'\0');
        uVar14 = param_3;
        iVar10 = iVar10 + puVar2[5];
        FUN_004281e0(iVar17,iVar10,param_3,'\0');
        uVar6 = iVar10 + puVar2[6];
        FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0x10:
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,6), iVar8 != 0)) goto LAB_00427f13;
        uVar12 = puVar2[1];
        uVar13 = *puVar2;
        param_3 = uVar14;
        FUN_004281e0(iVar17,uVar6 + uVar13,uVar14 + uVar12,'\0');
        iVar8 = uVar14 + uVar12 + puVar2[3];
        iVar10 = uVar6 + uVar13 + puVar2[2];
        FUN_004281e0(iVar17,iVar10,iVar8,'\0');
        iVar10 = iVar10 + puVar2[4];
        FUN_004281e0(iVar17,iVar10,iVar8,'\x01');
        iVar10 = iVar10 + puVar2[5];
        FUN_004281e0(iVar17,iVar10,iVar8,'\0');
        iVar10 = iVar10 + puVar2[6];
        FUN_004281e0(iVar17,iVar10,puVar2[7] + iVar8,'\0');
        uVar14 = param_3;
        uVar6 = iVar10 + puVar2[8];
        FUN_004281e0(iVar17,uVar6,param_3,'\x01');
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0x11:
        iVar10 = 0;
        param_3 = 0;
        iVar8 = FUN_00428280(iVar17,uVar6,uVar14);
        if ((iVar8 != 0) || (iVar8 = FUN_00420710(iVar17,6), iVar8 != 0)) goto LAB_00427f13;
        iVar8 = 5;
        puVar7 = puVar2;
        do {
          param_3 = param_3 + *puVar7;
          iVar10 = iVar10 + puVar7[1];
          puVar7 = puVar7 + 2;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if ((int)param_3 < 0) {
          param_3 = -param_3;
        }
        if (iVar10 < 0) {
          iVar10 = -iVar10;
        }
        uStack_c = (uint)(iVar10 < (int)param_3);
        param_3 = 5;
        uVar12 = uVar14;
        puVar7 = puVar2;
        uStack_8 = uVar6;
        do {
          uVar6 = uVar6 + *puVar7;
          uVar12 = uVar12 + puVar7[1];
          FUN_004281e0(iVar17,uVar6,uVar12,param_3 == 3);
          puVar7 = puVar7 + 2;
          param_3 = param_3 - 1;
        } while (0 < (int)param_3);
        if (uStack_c == 0) {
          uVar14 = uVar12 + *puVar7;
          uVar6 = uStack_8;
        }
        else {
          uVar6 = uVar6 + *puVar7;
        }
LAB_004277f9:
        FUN_004281e0(iVar17,uVar6,uVar14,'\x01');
LAB_00427806:
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0x12:
        if ((uVar12 != 4) ||
           (iVar8 = FUN_00428390(param_1,(int)*(short *)((int)puVar7 + 2),
                                 (int)*(short *)((int)puVar7 + 6),(int)*(short *)((int)puVar7 + 10),
                                 (int)*(short *)((int)puVar7 + 0xe)), iVar8 == 0)) {
          iVar8 = 0;
        }
        FUN_00428310(iVar17);
        if (puVar3 != (undefined4 *)0x0) {
          iVar10 = (*(code *)puVar3[2])(*puVar3,(int)*(short *)(*(int *)(iVar17 + 0x14) + 2));
          if (iVar10 != 0) {
            return 3;
          }
          (*(code *)puVar3[6])
                    (*puVar3,*(undefined4 *)(iVar17 + 0x14),*(undefined4 *)(iVar17 + 0x60));
        }
        FUN_004110a0(*(int *)(iVar17 + 0xc));
        return iVar8;
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
        if (puVar3 != (undefined4 *)0x0) {
          if ((param_3 == 0x13) || (bVar18 = param_3 == 0x15, param_3 = 0, bVar18)) {
            param_3 = 1;
          }
          (*(code *)puVar3[3])(*puVar3,param_3,(int)uVar12 / 2,puVar7);
        }
        *(int *)(param_1 + 0x30c) = *(int *)(param_1 + 0x30c) + (int)uVar12 / 2;
        *(uint **)(param_1 + 300) = puVar2;
        break;
      case 0x17:
      case 0x18:
        if (0 < (int)uVar12) {
          if (puVar3 != (undefined4 *)0x0) {
            (*(code *)puVar3[3])(*puVar3,0,(int)uVar12 / 2,puVar7);
          }
          *(int *)(param_1 + 0x30c) = *(int *)(param_1 + 0x30c) + (int)uVar12 / 2;
        }
        if (puVar3 != (undefined4 *)0x0) {
          if (param_3 == 0x17) {
            (*(code *)puVar3[4])(*puVar3,(int)*(short *)(*(int *)(iVar17 + 0x14) + 2));
          }
          else {
            (*(code *)puVar3[5])(*puVar3,*(undefined4 *)(param_1 + 0x30c),local_24);
          }
        }
        local_24 = local_24 + (*(int *)(param_1 + 0x30c) + 7 >> 3);
        if (local_18 <= local_24) {
          return 3;
        }
        goto LAB_00427806;
      case 0x19:
      case 0x23:
        goto switchD_00426e0a_caseD_19;
      case 0x1a:
        if ((int)*puVar7 < 0) {
          *puVar7 = -*puVar7;
        }
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x1b:
        *puVar7 = *puVar7 + puVar7[1];
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x1c:
        *puVar7 = *puVar7 - puVar7[1];
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x1d:
        uVar12 = FUN_00410c00(*puVar7,puVar7[1]);
        *puVar7 = uVar12;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x1e:
        *puVar7 = -*puVar7;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x1f:
        uVar12 = local_10;
        if (0x7fff < (int)local_10) {
          uVar12 = local_10 + 1;
        }
        *puVar7 = uVar12;
        local_10 = FUN_00410b80(local_10,0x10000 - local_10);
        if (local_10 == 0) {
          local_10 = 0x2873;
        }
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x20:
        uVar12 = FUN_00410b80(*puVar7,puVar7[1]);
        *puVar7 = uVar12;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x21:
        param_3 = *puVar7;
        if ((int)param_3 < 1) {
          *puVar7 = 0;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        else {
          uVar12 = FUN_00410c00(param_3,param_3);
          uVar12 = (int)(uVar12 + 1 + param_3) >> 1;
          bVar18 = uVar12 != param_3;
          param_3 = uVar12;
          if (bVar18) {
            do {
              uStack_8 = param_3;
              uVar12 = FUN_00410c00(*puVar7,param_3);
              param_3 = (int)(uVar12 + 1 + param_3) >> 1;
            } while (param_3 != uStack_8);
          }
          *puVar7 = param_3;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        break;
      default:
        return 7;
      case 0x24:
        uVar12 = *puVar7;
        *puVar7 = puVar7[1];
        puVar7[1] = uVar12;
        *(uint **)(param_1 + 300) = puVar7 + 2;
        break;
      case 0x25:
        iVar8 = (int)*(short *)((int)puVar7 + 2);
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        else if ((int)(uVar12 - 2) < iVar8) {
          iVar8 = uVar12 - 2;
        }
        *puVar7 = *(uint *)((int)puVar7 - (iVar8 * 4 + 4));
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x26:
        iVar8 = (int)*(short *)((int)puVar7 + 2);
        puStack_20 = (uint *)(int)*(short *)((int)puVar7 + 6);
        if (iVar8 < 1) {
          iVar8 = 1;
        }
        puVar7 = puVar7 + -iVar8;
        if (puVar7 < puVar2) {
          return 0x81;
        }
        if ((int)puStack_20 < 0) {
          uStack_c = -(int)puStack_20;
          do {
            uVar12 = *puVar7;
            iVar10 = iVar8 + -1;
            puVar16 = puVar7;
            puVar4 = puVar7;
            if (0 < iVar8 + -1) {
              for (; iVar17 = local_4, iVar10 != 0; iVar10 = iVar10 + -1) {
                *puVar16 = puVar4[1];
                puVar16 = puVar16 + 1;
                puVar4 = puVar4 + 1;
              }
            }
            puVar7[iVar8 + -1] = uVar12;
            uStack_c = uStack_c + -1;
          } while (uStack_c != 0);
          uStack_c = 0;
        }
        else if (0 < (int)puStack_20) {
          uStack_8 = iVar8 - 2;
          do {
            uVar12 = puVar7[iVar8 + -1];
            for (uVar13 = uStack_8; -1 < (int)uVar13; uVar13 = uVar13 - 1) {
              puVar7[uVar13 + 1] = puVar7[uVar13];
            }
            puStack_20 = (uint *)((int)puStack_20 + -1);
            *puVar7 = uVar12;
          } while (puStack_20 != (uint *)0x0);
          *(uint **)(param_1 + 300) = puVar7 + iVar8;
          break;
        }
        *(uint **)(param_1 + 300) = puVar7 + iVar8;
        break;
      case 0x27:
        puVar7[1] = *puVar7;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x28:
        iVar8 = (int)*(short *)((int)puVar7 + 6);
        if ((iVar8 < 0) || (*(int *)(param_1 + 0x314) <= iVar8)) goto switchD_00426e0a_caseD_19;
        *(uint *)(*(int *)(param_1 + 0x310) + iVar8 * 4) = *puVar7;
        *(uint **)(param_1 + 300) = puVar7;
        break;
      case 0x29:
        iVar8 = (int)*(short *)((int)puVar7 + 2);
        uVar12 = 0;
        if ((-1 < iVar8) && (iVar8 < *(int *)(param_1 + 0x314))) {
          uVar12 = *(uint *)(*(int *)(param_1 + 0x310) + iVar8 * 4);
        }
        *puVar7 = uVar12;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x2c:
        if ((*puVar7 == 0) || (puVar7[1] == 0)) {
          *puVar7 = 0;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        else {
          *puVar7 = 0x10000;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        break;
      case 0x2d:
        if ((*puVar7 == 0) && (puVar7[1] == 0)) {
          *puVar7 = 0;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        else {
          *puVar7 = 0x10000;
          *(uint **)(param_1 + 300) = puVar7 + 1;
        }
        break;
      case 0x2f:
        *puVar7 = (*puVar7 != 0) - 1 & 0x10000;
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x30:
        if ((int)puVar7[3] < (int)puVar7[2]) {
          *puVar7 = puVar7[1];
        }
        *(uint **)(param_1 + 300) = puVar7 + 1;
        break;
      case 0x31:
        uVar12 = (int)*(short *)((int)puVar7 + 2) + *(int *)(param_1 + 800);
        if ((*(uint *)(param_1 + 0x318) <= uVar12) ||
           (0x1f < ((int)local_1c + (-0x130 - param_1)) / 0xc)) {
switchD_00426c04_caseD_1:
          return 3;
        }
        local_1c[2] = (int)local_24;
        piVar9 = local_1c + 3;
        *piVar9 = *(int *)(*(int *)(param_1 + 0x328) + uVar12 * 4);
        local_1c[4] = *(int *)(*(int *)(param_1 + 0x328) + 4 + uVar12 * 4);
        local_1c[5] = *piVar9;
        if (*piVar9 == 0) {
          return 3;
        }
        *(int **)(param_1 + 700) = piVar9;
        local_24 = (byte *)*piVar9;
        local_1c = piVar9;
        goto LAB_00427df2;
      case 0x32:
        uVar12 = (int)*(short *)((int)puVar7 + 2) + *(int *)(param_1 + 0x324);
        if (*(uint *)(param_1 + 0x31c) <= uVar12) {
          return 3;
        }
        if (0x1f < ((int)local_1c + (-0x130 - param_1)) / 0xc) {
          return 3;
        }
        local_1c[2] = (int)local_24;
        piVar9 = local_1c + 3;
        *piVar9 = *(int *)(*(int *)(param_1 + 0x32c) + uVar12 * 4);
        local_1c[4] = *(int *)(*(int *)(param_1 + 0x32c) + 4 + uVar12 * 4);
        local_1c[5] = *piVar9;
        if (*piVar9 == 0) {
          return 3;
        }
        *(int **)(param_1 + 700) = piVar9;
        local_24 = (byte *)*piVar9;
        local_1c = piVar9;
        goto LAB_00427df2;
      case 0x33:
        if (*(uint *)(param_1 + 700) <= param_1 + 0x130U) {
          return 3;
        }
        *(uint *)(param_1 + 700) = *(uint *)(param_1 + 700) - 0xc;
        local_24 = (byte *)(*(int **)(param_1 + 700))[2];
        local_1c = *(int **)(param_1 + 700);
LAB_00427df2:
        local_18 = (byte *)local_1c[1];
switchD_00426e0a_caseD_19:
        *(uint **)(param_1 + 300) = puVar7;
      }
LAB_00427efa:
    } while (local_24 < local_18);
  }
  return 0;
}



void __cdecl FUN_004281e0(int param_1,int param_2,int param_3,char param_4)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(char *)(param_1 + 0x51) != '\0') {
    sVar2 = *(short *)(iVar3 + 2);
    piVar1 = (int *)(*(int *)(iVar3 + 4) + sVar2 * 8);
    iVar4 = *(int *)(iVar3 + 8);
    *piVar1 = param_2 >> 0x10;
    piVar1[1] = param_3 >> 0x10;
    *(char *)(iVar4 + sVar2) = (param_4 == '\0') + '\x01';
    *(int *)(param_1 + 0x18) = *piVar1;
    *(int *)(param_1 + 0x1c) = piVar1[1];
  }
  *(short *)(iVar3 + 2) = *(short *)(iVar3 + 2) + 1;
  return;
}



int __cdecl FUN_00428240(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00420710(param_1,1);
  if (iVar1 == 0) {
    FUN_004281e0(param_1,param_2,param_3,'\x01');
  }
  return iVar1;
}



int __cdecl FUN_00428280(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(param_1 + 0x50) == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 1;
    iVar1 = FUN_004282c0(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_00428240(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



int __cdecl FUN_004282c0(int param_1)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = *(short **)(param_1 + 0x14);
  if (*(char *)(param_1 + 0x51) == '\0') {
    *psVar1 = *psVar1 + 1;
    return 0;
  }
  iVar2 = FUN_00410f10(*(int **)(param_1 + 0xc),0,1);
  if (iVar2 == 0) {
    if (0 < *psVar1) {
      *(short *)(*(int *)(psVar1 + 6) + -2 + *psVar1 * 2) = psVar1[1] + -1;
    }
    *psVar1 = *psVar1 + 1;
  }
  return iVar2;
}



void __cdecl FUN_00428310(int param_1)

{
  int *piVar1;
  short sVar2;
  short *psVar3;
  int *piVar4;
  
  psVar3 = *(short **)(param_1 + 0x14);
  sVar2 = psVar3[1];
  if (1 < sVar2) {
    piVar4 = *(int **)(psVar3 + 2);
    piVar1 = piVar4 + sVar2 * 2 + -2;
    if (1 < *psVar3) {
      piVar4 = piVar4 + *(short *)(*(int *)(psVar3 + 6) + -4 + *psVar3 * 2) * 2 + 2;
    }
    if (((*piVar4 == *piVar1) && (piVar4[1] == piVar1[1])) &&
       (*(char *)(*(int *)(psVar3 + 4) + -1 + (int)sVar2) == '\x01')) {
      psVar3[1] = sVar2 + -1;
    }
  }
  if (0 < *psVar3) {
    *(short *)(*(int *)(psVar3 + 6) + -2 + *psVar3 * 2) = psVar3[1] + -1;
  }
  return;
}



int __cdecl FUN_00428390(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined1 local_14 [2];
  short local_12;
  int local_10;
  
  iVar10 = param_1;
  iVar2 = *(int *)(param_1 + 0x10);
  iVar13 = *(int *)(*(int *)(param_1 + 4) + 0x2b0);
  uVar11 = FUN_00428590(iVar13,param_4);
  param_4 = uVar11;
  param_5 = FUN_00428590(iVar13,param_5);
  if ((-1 < (int)uVar11) && (-1 < (int)param_5)) {
    if (*(char *)(iVar10 + 0x52) != '\0') {
      iVar3 = *(int *)(iVar10 + 8);
      piVar4 = (int *)**(undefined4 **)(iVar3 + 0x94);
      iVar12 = FUN_00410ff0(piVar4,2);
      if (iVar12 != 0) {
        return iVar12;
      }
      puVar5 = (uint *)piVar4[0x13];
      *puVar5 = param_4;
      puVar5[2] = 0;
      puVar5[3] = 0;
      *(undefined2 *)(puVar5 + 1) = 0x202;
      puVar5[8] = param_5;
      puVar5[10] = param_2;
      *(undefined2 *)(puVar5 + 9) = 2;
      puVar5[0xb] = param_3;
      *(undefined4 *)(iVar3 + 0x80) = 2;
      *(int *)(iVar3 + 0x84) = piVar4[0xb];
      *(undefined4 *)(iVar3 + 0x48) = 0x636f6d70;
      piVar4[0x12] = 2;
      uVar11 = param_4;
    }
    piVar4 = (int *)(iVar13 + 0x90);
    iVar13 = FUN_00424910(piVar4,uVar11,&param_1,&param_4);
    if (iVar13 == 0) {
      iVar13 = FUN_00426a70(iVar10,param_1,param_4);
      if (iVar13 != 0) {
        return iVar13;
      }
      FUN_004249c0(piVar4,&param_1);
    }
    sVar1 = *(short *)(iVar2 + 2);
    uVar6 = *(undefined4 *)(iVar10 + 0x34);
    uVar7 = *(undefined4 *)(iVar10 + 0x38);
    uVar8 = *(undefined4 *)(iVar10 + 0x30);
    uVar9 = *(undefined4 *)(iVar10 + 0x3c);
    *(undefined4 *)(iVar10 + 0x30) = 0;
    *(undefined4 *)(iVar10 + 0x34) = 0;
    iVar13 = FUN_00424910(piVar4,param_5,&param_1,&param_4);
    if (iVar13 == 0) {
      iVar13 = FUN_00426a70(iVar10,param_1,param_4);
      if (iVar13 != 0) {
        return iVar13;
      }
      FUN_004249c0(piVar4,&param_1);
      iVar13 = 0;
    }
    *(undefined4 *)(iVar10 + 0x38) = uVar7;
    *(undefined4 *)(iVar10 + 0x30) = uVar8;
    *(undefined4 *)(iVar10 + 0x34) = uVar6;
    *(undefined4 *)(iVar10 + 0x3c) = uVar9;
    if (*(char *)(iVar10 + 0x51) != '\0') {
      local_12 = *(short *)(iVar2 + 2) - sVar1;
      local_10 = *(int *)(iVar2 + 4) + sVar1 * 8;
      FUN_00412600((int)local_14,param_2,param_3);
    }
    return iVar13;
  }
  return 0xa0;
}



uint __cdecl FUN_00428590(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  if ((-1 < (int)param_2) && ((int)param_2 < 0x100)) {
    sVar1 = FUN_004285e0(param_2);
    uVar2 = 0;
    if (*(uint *)(param_1 + 0xc) != 0) {
      psVar3 = *(short **)(param_1 + 0x8c);
      do {
        if (*psVar3 == sVar1) {
          return uVar2;
        }
        uVar2 = uVar2 + 1;
        psVar3 = psVar3 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0xc));
    }
  }
  return 0xffffffff;
}



undefined2 __cdecl FUN_004285e0(uint param_1)

{
  if (param_1 < 0x100) {
    return *(undefined2 *)((int)&DAT_00434710 + param_1 * 2);
  }
  return 0;
}



int __cdecl FUN_00428620(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *local_4;
  
  piVar1 = (int *)*param_1;
  local_4 = (int *)0x0;
  *param_2 = 0;
  iVar2 = FUN_00410c90((int)piVar1,0x48,&local_4);
  if (iVar2 == 0) {
    *local_4 = (int)piVar1;
    local_4[1] = 0;
    iVar2 = FUN_004286d0(piVar1,local_4 + 5);
    if (iVar2 == 0) {
      iVar2 = FUN_00410da0(piVar1,local_4 + 6);
      if (iVar2 == 0) {
        iVar2 = FUN_00410e90((int *)local_4[6]);
        if (iVar2 == 0) {
          *param_2 = local_4;
          return 0;
        }
      }
    }
    iVar2 = 1;
  }
  FUN_00428700(local_4);
  return iVar2;
}



void __cdecl FUN_004286d0(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1;
  iVar2 = FUN_00410c90((int)param_1,0x50,&param_1);
  if (iVar2 == 0) {
    *param_1 = (int)piVar1;
    *param_2 = (int)param_1;
  }
  return;
}



void __cdecl FUN_00428700(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    FUN_00410e60((int *)param_1[6]);
    FUN_00428750((int *)param_1[5]);
    param_1[4] = 0;
    param_1[3] = 0;
    FUN_00410d70(iVar1,(int *)&param_1);
  }
  return;
}



void __cdecl FUN_00428750(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_00410d70(iVar1,param_1 + 0xd);
  FUN_00410d70(iVar1,param_1 + 0x11);
  FUN_00410d70(iVar1,param_1 + 0xb);
  FUN_00410d70(iVar1,param_1 + 8);
  FUN_00410d70(iVar1,(int *)&param_1);
  return;
}



void __cdecl FUN_00428850(int *param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  int local_c;
  
  iVar2 = param_1[4];
  piVar1 = (int *)(iVar2 + 4);
  piVar6 = (int *)(iVar2 + 0x94);
  piVar7 = piVar1;
  piVar9 = piVar6;
  for (iVar4 = 0x24; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar9 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  }
  iVar4 = 0;
  if (0 < *piVar1) {
    puVar8 = (uint *)(iVar2 + 0x9c);
    do {
      uVar3 = FUN_00410b80(*(uint *)(((int)piVar1 - (int)piVar6) + (int)puVar8),param_2);
      *puVar8 = uVar3;
      iVar4 = iVar4 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar4 < *piVar1);
  }
  iVar4 = 0;
  if (0 < *(int *)(iVar2 + 8)) {
    puVar8 = (uint *)(iVar2 + 0xcc);
    do {
      uVar3 = FUN_00410b80(*(uint *)((int)puVar8 + ((int)piVar1 - (int)piVar6)),param_3);
      *puVar8 = uVar3;
      iVar4 = iVar4 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar4 < *(int *)(iVar2 + 8));
  }
  param_1 = (int *)(iVar2 + 0x110);
  puVar8 = (uint *)(iVar2 + 0x6c);
  local_c = 5;
  do {
    uVar5 = puVar8[5] - *puVar8;
    uVar3 = uVar5;
    if ((int)uVar5 < 0) {
      uVar3 = -uVar5;
    }
    uVar3 = FUN_00410b80(uVar3,param_3);
    if ((int)uVar3 < 0x20) {
      uVar3 = 0;
    }
    else if ((int)uVar3 < 0x40) {
      uVar3 = (uVar3 - 0x10 & 0xffffffe0) + 0x20;
    }
    else {
      uVar3 = uVar3 + 0x20 & 0xffffffc0;
    }
    if ((int)uVar5 < 0) {
      uVar3 = -uVar3;
    }
    uVar5 = FUN_00410b80(*puVar8,param_3);
    uVar5 = uVar5 + 0x20 & 0xffffffc0;
    *(uint *)(((int)piVar6 - (int)piVar1) + (int)puVar8) = uVar5;
    *param_1 = uVar5 + uVar3;
    param_1 = param_1 + 1;
    puVar8 = puVar8 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  *(uint *)(iVar2 + 0x124) = param_2;
  *(uint *)(iVar2 + 0x128) = param_3;
  return;
}



int __cdecl FUN_004289a0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = param_1;
  iVar2 = FUN_00410c90(*param_1,0x130,&param_1);
  iVar1 = param_2;
  if (iVar2 == 0) {
    piVar4[3] = param_2;
    piVar4[4] = (int)param_1;
    if (param_3 == (int *)0x0) {
      FUN_00428a10((int)piVar4);
    }
    else {
      piVar4 = param_1;
      for (iVar3 = 0x24; piVar4 = piVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = *param_3;
        param_3 = param_3 + 1;
      }
    }
    *(int **)(iVar1 + 0x74) = param_1;
    *(code **)(iVar1 + 0x78) = FUN_00429a70;
    *param_1 = iVar1;
  }
  return iVar2;
}



undefined4 __cdecl FUN_00428a10(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00428d60(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00428a40(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



int __cdecl FUN_00428a40(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  bool bVar16;
  short *psVar17;
  uint uVar18;
  undefined **local_88;
  int local_7c;
  int local_78;
  int local_74;
  int local_60 [12];
  int local_30 [12];
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar3 + 0x5c);
  iVar9 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(iVar3 + 0x54);
  iVar7 = FUN_00411430(iVar3,0x756e6963);
  if (iVar7 == 0) {
    piVar14 = (int *)(iVar9 + 0x80);
    local_88 = &PTR_DAT_00441a48;
    do {
      pcVar12 = *local_88;
      pcVar1 = pcVar12 + 0xc;
      local_7c = 0;
      local_78 = 0;
      for (; (pcVar12 < pcVar1 && (*pcVar12 != '\0')); pcVar12 = pcVar12 + 1) {
        uVar8 = FUN_004114d0(iVar3);
        if ((uVar8 != 0) &&
           ((iVar9 = FUN_004111c0(iVar3,uVar8,1), iVar9 == 0 && (0 < *(short *)(iVar5 + 0x6e))))) {
          uVar6 = *(uint *)(iVar5 + 0x70);
          uVar2 = uVar6 + *(short *)(iVar5 + 0x6e) * 8;
          uVar8 = uVar6 + 8;
          uVar18 = uVar6;
          if ((local_88 == &PTR_DAT_00441a48) || (local_88 == &PTR_s_xzroesc_00441a50)) {
            for (; uVar8 < uVar2; uVar8 = uVar8 + 8) {
              if (*(int *)(uVar18 + 4) < *(int *)(uVar8 + 4)) {
                uVar18 = uVar8;
              }
            }
          }
          else {
            for (; uVar8 < uVar2; uVar8 = uVar8 + 8) {
              if (*(int *)(uVar8 + 4) < *(int *)(uVar18 + 4)) {
                uVar18 = uVar8;
              }
            }
          }
          iVar9 = 0;
          iVar7 = (int)(uVar18 - uVar6) >> 3;
          local_74 = 0;
          if (0 < *(short *)(iVar5 + 0x6c)) {
            psVar17 = *(short **)(iVar5 + 0x78);
            do {
              iVar15 = (int)*psVar17;
              if (iVar7 <= iVar15) {
                if (-1 < iVar15) {
                  iVar9 = *(int *)(uVar18 + 4);
                  iVar10 = iVar7;
                  do {
                    iVar13 = iVar15;
                    if (local_74 < iVar10) {
                      iVar13 = iVar10 + -1;
                    }
                    iVar10 = *(int *)(uVar6 + 4 + iVar13 * 8) - iVar9;
                    iVar11 = iVar7;
                  } while (((-6 < iVar10) && (iVar10 < 6)) && (iVar10 = iVar13, iVar13 != iVar7));
                  do {
                    iVar10 = local_74;
                    if (iVar11 < iVar15) {
                      iVar10 = iVar11 + 1;
                    }
                    iVar11 = *(int *)(uVar6 + 4 + iVar10 * 8) - iVar9;
                  } while (((-6 < iVar11) && (iVar11 < 6)) && (iVar11 = iVar10, iVar10 != iVar7));
                  if (((*(byte *)(*(int *)(iVar5 + 0x74) + iVar13) & 3) == 1) &&
                     ((*(byte *)(*(int *)(iVar5 + 0x74) + iVar10) & 3) == 1)) {
                    local_60[local_7c] = iVar9;
                    local_7c = local_7c + 1;
                  }
                  else {
                    local_30[local_78] = iVar9;
                    local_78 = local_78 + 1;
                  }
                }
                break;
              }
              local_74 = iVar15 + 1;
              iVar9 = iVar9 + 1;
              psVar17 = psVar17 + 1;
            } while (iVar9 < *(short *)(iVar5 + 0x6c));
          }
        }
      }
      FUN_00428d20(local_78,(int)local_30);
      FUN_00428d20(local_7c,(int)local_60);
      if (local_7c == 0) {
        if (local_78 == 0) {
          piVar14[-5] = -10000;
          *piVar14 = -10000;
        }
        else {
          iVar9 = local_30[local_78 / 2];
          *piVar14 = iVar9;
          piVar14[-5] = iVar9;
        }
      }
      else if (local_78 == 0) {
        iVar9 = local_60[local_7c / 2];
        *piVar14 = iVar9;
        piVar14[-5] = iVar9;
      }
      else {
        piVar14[-5] = local_60[local_7c / 2];
        *piVar14 = local_30[local_78 / 2];
      }
      iVar9 = *piVar14;
      iVar7 = piVar14[-5];
      if (iVar9 != iVar7) {
        if ((local_88 == &PTR_DAT_00441a48) || (local_88 == &PTR_s_xzroesc_00441a50)) {
          bVar16 = true;
        }
        else {
          bVar16 = false;
        }
        if (iVar7 <= iVar9 != bVar16) {
          iVar9 = (iVar9 + iVar7) / 2;
          piVar14[-5] = iVar9;
          *piVar14 = iVar9;
        }
      }
      local_88 = local_88 + 1;
      piVar14 = piVar14 + 1;
    } while ((int)local_88 < 0x441a5c);
    FUN_00411480(iVar3,iVar4);
    iVar7 = 0;
  }
  return iVar7;
}



void __cdecl FUN_00428d20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  iVar4 = iVar3;
  if (1 < param_1) {
joined_r0x00428d38:
    do {
      if (0 < iVar3) {
        iVar1 = *(int *)(param_2 + iVar3 * 4);
        iVar2 = *(int *)(param_2 + -4 + iVar3 * 4);
        if (iVar1 <= iVar2) {
          *(int *)(param_2 + iVar3 * 4) = iVar2;
          *(int *)(param_2 + -4 + iVar3 * 4) = iVar1;
          iVar3 = iVar3 + -1;
          goto joined_r0x00428d38;
        }
      }
      iVar3 = iVar4 + 1;
      iVar4 = iVar3;
    } while (iVar3 < param_1);
  }
  return;
}



int __cdecl FUN_00428d60(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_14;
  int *local_10;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14);
  *(int *)(iVar1 + 4) = 0;
  *(int *)(iVar1 + 8) = 0;
  local_14 = 32000;
  uVar4 = FUN_004114d0(*(int *)(param_1 + 0xc));
  if (uVar4 == 0) {
    return 0;
  }
  iVar5 = FUN_004111c0(*(int *)(param_1 + 0xc),uVar4,1);
  if ((iVar5 == 0) &&
     (iVar5 = FUN_00428ec0(*(int **)(param_1 + 0x14),*(int *)(param_1 + 0xc)), iVar5 == 0)) {
    FUN_00429540(*(int *)(param_1 + 0x14));
    FUN_004298d0(*(int *)(param_1 + 0x14));
    uVar4 = *(uint *)(iVar2 + 0x44);
    uVar6 = *(int *)(iVar2 + 0x40) * 0x38 + uVar4;
    piVar8 = (int *)(iVar1 + 0x3c);
    local_c = 2;
    local_10 = (int *)(iVar1 + 8);
    do {
      iVar9 = 0;
      for (; uVar4 < uVar6; uVar4 = uVar4 + 0x38) {
        uVar3 = *(uint *)(uVar4 + 0x28);
        if (((uVar3 != 0) && (*(uint *)(uVar3 + 0x28) == uVar4)) && (uVar4 < uVar3)) {
          iVar7 = *(int *)(uVar4 + 0x14) - *(int *)(uVar3 + 0x14);
          if (iVar7 < 0) {
            iVar7 = -iVar7;
          }
          if (iVar9 < 0xc) {
            piVar8[iVar9] = iVar7;
            iVar9 = iVar9 + 1;
          }
        }
      }
      FUN_00428d20(iVar9,(int)piVar8);
      *local_10 = iVar9;
      if ((0 < iVar9) && (*piVar8 < local_14)) {
        local_14 = *piVar8;
      }
      uVar4 = *(uint *)(iVar2 + 0x4c);
      uVar6 = *(int *)(iVar2 + 0x48) * 0x38 + uVar4;
      local_c = local_c + -1;
      piVar8 = (int *)(iVar1 + 0xc);
      local_10 = (int *)(iVar1 + 4);
    } while (local_c != 0);
    if (local_14 == 32000) {
      local_14 = 0x32;
    }
    *(int *)(*(int *)(param_1 + 0x14) + 0x14) = local_14 / 5;
  }
  return iVar5;
}



int __cdecl FUN_00428ec0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  short sVar9;
  uint *puVar10;
  short *psVar11;
  uint uVar12;
  uint *puVar13;
  byte *pbVar14;
  uint *puVar15;
  uint *puVar16;
  uint local_10;
  int local_c;
  uint *local_8;
  int local_4;
  
  iVar8 = *(int *)(param_2 + 0x54);
  local_8 = (uint *)(int)*(short *)(iVar8 + 0x6e);
  local_10 = (uint)*(short *)(iVar8 + 0x6c);
  iVar4 = *param_1;
  if ((*(int *)(param_2 + 0x58) == 0) || (*(int *)(iVar8 + 0x48) != 0x6f75746c)) {
    return 6;
  }
  if (param_1[9] < (int)local_10) {
    uVar12 = local_10 + 3 & 0xfffffffc;
    iVar2 = FUN_00410ce0(iVar4,param_1[9] << 2,uVar12 * 4,param_1 + 0xb);
    if (iVar2 != 0) {
      return iVar2;
    }
    param_1[9] = uVar12;
  }
  iVar2 = param_1[6];
  if (iVar2 < (int)local_8 + 2) {
    uVar12 = (int)local_8 + 9U & 0xfffffff8;
    iVar3 = FUN_00410ce0(iVar4,iVar2 * 0x3c,uVar12 * 0x3c,param_1 + 8);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = FUN_00410ce0(iVar4,iVar2 * 0x60,uVar12 * 0x60,param_1 + 0xd);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar4 = FUN_00410ce0(iVar4,iVar2 * 0x70,uVar12 * 0x70,param_1 + 0x11);
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1[0xf] = uVar12 * 0x30 + param_1[0xd];
    param_1[0x13] = uVar12 * 0x38 + param_1[0x11];
    param_1[6] = uVar12;
  }
  param_1[7] = (int)local_8;
  param_1[10] = local_10;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[1] = 2;
  param_1[2] = -1;
  iVar4 = FUN_004293a0((short *)(iVar8 + 0x6c));
  if (1 < iVar4) {
    param_1[1] = -2;
    param_1[2] = 1;
  }
  local_8 = *(uint **)(*(int *)(param_2 + 0x58) + 0x10);
  puVar16 = (uint *)param_1[8];
  param_1[3] = (int)local_8;
  local_10 = *(uint *)(*(int *)(param_2 + 0x58) + 0x14);
  param_1[4] = local_10;
  if (param_1[7] != 0) {
    puVar6 = *(uint **)(iVar8 + 0x70);
    puVar5 = puVar16 + param_1[7] * 0xf;
    if (puVar16 < puVar5) {
      puVar13 = puVar16 + 4;
      do {
        puVar13[-1] = *puVar6;
        *puVar13 = puVar6[1];
        uVar12 = FUN_00410b80(*puVar6,(uint)local_8);
        puVar13[1] = uVar12;
        puVar13[-3] = uVar12;
        uVar12 = FUN_00410b80(puVar6[1],local_10);
        puVar13[2] = uVar12;
        puVar13[-2] = uVar12;
        puVar13[-4] = 0;
        puVar15 = puVar13 + 0xb;
        puVar6 = puVar6 + 2;
        puVar13 = puVar13 + 0xf;
      } while (puVar15 < puVar5);
    }
    pbVar14 = *(byte **)(iVar8 + 0x74);
    for (puVar6 = puVar16; puVar6 < puVar5; puVar6 = puVar6 + 0xf) {
      if ((*pbVar14 & 3) == 0) {
        *puVar6 = 1;
      }
      else if ((*pbVar14 & 3) == 2) {
        *puVar6 = 2;
      }
      pbVar14 = pbVar14 + 1;
    }
    puVar6 = puVar16 + **(short **)(iVar8 + 0x78) * 0xf;
    if (puVar16 < puVar5) {
      local_10 = 0;
      puVar15 = puVar16;
      puVar13 = puVar16;
      local_8 = puVar6;
      do {
        puVar10 = puVar13 + 0xf;
        puVar13[0xe] = (uint)local_8;
        if (puVar13 < puVar6) {
          puVar13[0xd] = (uint)puVar10;
          local_8 = puVar13;
        }
        else {
          local_10 = local_10 + 2;
          puVar13[0xd] = (uint)puVar15;
          if (puVar10 < puVar5) {
            puVar6 = puVar16 + *(short *)(local_10 + *(int *)(iVar8 + 0x78)) * 0xf;
            puVar15 = puVar10;
            local_8 = puVar6;
          }
        }
        puVar13 = puVar10;
      } while (puVar10 < puVar5);
    }
    puVar7 = (undefined4 *)param_1[0xb];
    psVar11 = *(short **)(iVar8 + 0x78);
    puVar1 = puVar7 + param_1[10];
    sVar9 = 0;
    for (; puVar7 < puVar1; puVar7 = puVar7 + 1) {
      *puVar7 = puVar16 + sVar9 * 0xf;
      sVar9 = *psVar11 + 1;
      psVar11 = psVar11 + 1;
    }
    if (puVar16 < puVar5) {
      puVar16 = puVar16 + 3;
      do {
        local_8 = (uint *)(*puVar16 - *(int *)(puVar16[0xb] + 0xc));
        local_4 = puVar16[1] - *(int *)(puVar16[0xb] + 0x10);
        uVar12 = FUN_00429340((int)local_8,local_4);
        puVar16[6] = uVar12;
        local_10 = *(int *)(puVar16[10] + 0xc) - *puVar16;
        local_c = *(int *)(puVar16[10] + 0x10) - puVar16[1];
        uVar12 = FUN_00429340(local_10,local_c);
        puVar16[7] = uVar12;
        if ((puVar16[-3] & 3) == 0) {
          if (uVar12 == puVar16[6]) {
            if (uVar12 == 4) {
              iVar4 = FUN_00429280((uint *)&local_8);
              iVar8 = FUN_00429280(&local_10);
              iVar4 = iVar4 - iVar8;
              if (0x100 < iVar4) {
                iVar4 = 0x200 - iVar4;
              }
              if (iVar4 < 0) {
                iVar4 = -iVar4;
              }
              if (1 < iVar4) goto LAB_00429252;
            }
            goto LAB_0042924f;
          }
          if (puVar16[6] == -uVar12) goto LAB_0042924f;
        }
        else {
LAB_0042924f:
          puVar16[-3] = puVar16[-3] | 0x100;
        }
LAB_00429252:
        puVar6 = puVar16 + 0xc;
        puVar16 = puVar16 + 0xf;
      } while (puVar6 < puVar5);
    }
  }
  return 0;
}



int __cdecl FUN_00429280(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = param_1[1];
  uVar1 = *param_1;
  if (uVar3 == 0) {
    if (-1 < (int)uVar1) {
      return 0;
    }
    return 0x100;
  }
  if (uVar1 == 0) {
    if (-1 < (int)uVar3) {
      return 0x80;
    }
    return -0x80;
  }
  iVar5 = 0;
  if ((int)uVar1 < 0) {
    uVar1 = -uVar1;
    uVar3 = -uVar3;
    iVar5 = 0x100;
  }
  uVar4 = uVar1;
  if ((int)uVar3 < 0) {
    uVar4 = -uVar3;
    iVar5 = iVar5 + -0x80;
    uVar3 = uVar1;
  }
  if (uVar4 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
  }
  else if (uVar4 == uVar3) {
    iVar5 = iVar5 + 0x40;
    goto LAB_00429321;
  }
  if ((int)uVar3 < (int)uVar4) {
    uVar3 = FUN_00410c00(uVar3,uVar4);
    iVar2 = *(int *)(&DAT_00434bc8 + ((int)uVar3 >> 8) * 4);
  }
  else {
    uVar3 = FUN_00410c00(uVar4,uVar3);
    iVar2 = 0x80 - *(int *)(&DAT_00434bc8 + ((int)uVar3 >> 8) * 4);
  }
  iVar5 = iVar5 + iVar2;
LAB_00429321:
  if (0x100 < iVar5) {
    iVar5 = iVar5 + -0x200;
  }
  return iVar5;
}



int __cdecl FUN_00429340(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (param_1 < 0) {
    iVar3 = -param_1;
  }
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = -param_2;
  }
  iVar1 = 4;
  if (iVar3 * 0xc < iVar2) {
    return (uint)(0 < param_2) * 4 + -2;
  }
  if (iVar2 * 0xc < iVar3) {
    iVar1 = (uint)(0 < param_1) * 2 + -1;
  }
  return iVar1;
}



int __cdecl FUN_004293a0(short *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int local_8;
  int local_4;
  
  local_20 = (int *)0xffffffff;
  local_1c = (int *)0xffffffff;
  local_18 = (int *)0xffffffff;
  local_14 = (int *)0xffffffff;
  local_4 = -0x8000;
  local_8 = -0x8000;
  iVar7 = 0x7fff;
  iVar6 = 0x7fff;
  if (0 < *param_1) {
    iVar4 = (int)*(short *)(*(int *)(param_1 + 6) + -2 + *param_1 * 2);
    piVar3 = (int *)0x0;
    if (-1 < iVar4) {
      piVar5 = *(int **)(param_1 + 2);
      do {
        iVar1 = *piVar5;
        if (iVar1 < iVar6) {
          iVar6 = iVar1;
          local_20 = piVar3;
        }
        if (local_8 < iVar1) {
          local_18 = piVar3;
          local_8 = iVar1;
        }
        iVar1 = piVar5[1];
        if (iVar1 < iVar7) {
          iVar7 = iVar1;
          local_1c = piVar3;
        }
        if (local_4 < iVar1) {
          local_14 = piVar3;
          local_4 = iVar1;
        }
        piVar3 = (int *)((int)piVar3 + 1);
        piVar5 = piVar5 + 2;
      } while ((int)piVar3 <= iVar4);
    }
    cVar2 = FUN_00429490(param_1,local_20);
    if (CONCAT31(extraout_var,cVar2) != 0) {
      return CONCAT31(extraout_var,cVar2);
    }
    cVar2 = FUN_00429490(param_1,local_1c);
    if (CONCAT31(extraout_var_00,cVar2) != 0) {
      return CONCAT31(extraout_var_00,cVar2);
    }
    cVar2 = FUN_00429490(param_1,local_18);
    if (CONCAT31(extraout_var_01,cVar2) != 0) {
      return CONCAT31(extraout_var_01,cVar2);
    }
    cVar2 = FUN_00429490(param_1,local_14);
    if (CONCAT31(extraout_var_02,cVar2) != 0) {
      return CONCAT31(extraout_var_02,cVar2);
    }
  }
  return 1;
}



char __cdecl FUN_00429490(short *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char cVar7;
  short *psVar8;
  int *piVar9;
  
  piVar2 = param_2;
  iVar1 = *(int *)(param_1 + 2);
  piVar3 = (int *)(iVar1 + -8 + (int)param_2 * 8);
  piVar6 = (int *)0x0;
  piVar9 = (int *)(iVar1 + 8 + (int)param_2 * 8);
  param_2 = piVar3;
  if (0 < *param_1) {
    psVar8 = *(short **)(param_1 + 6);
    param_1 = (short *)(int)*param_1;
    do {
      piVar3 = (int *)(int)*psVar8;
      if (piVar2 == piVar6) {
        param_2 = (int *)(iVar1 + (int)piVar3 * 8);
      }
      if (piVar2 == piVar3) {
        piVar9 = (int *)(iVar1 + (int)piVar6 * 8);
      }
      piVar6 = (int *)((int)piVar3 + 1);
      psVar8 = psVar8 + 1;
      param_1 = (short *)((int)param_1 + -1);
    } while (param_1 != (short *)0x0);
  }
  uVar4 = FUN_00410a10(*(int *)(iVar1 + 4 + (int)piVar2 * 8) - param_2[1],
                       *piVar9 - *(int *)(iVar1 + (int)piVar2 * 8),0x40);
  uVar5 = FUN_00410a10(*(int *)(iVar1 + (int)piVar2 * 8) - *param_2,
                       piVar9[1] - *(int *)(iVar1 + 4 + (int)piVar2 * 8),0x40);
  cVar7 = '\0';
  if (uVar5 != uVar4) {
    cVar7 = (0 < (int)(uVar5 - uVar4)) + '\x01';
  }
  return cVar7;
}



void __cdecl FUN_00429540(int param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *local_34;
  int local_30;
  uint local_28;
  uint *local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int *local_10;
  
  puVar8 = *(uint **)(param_1 + 0x44);
  local_10 = (int *)(param_1 + 0x40);
  local_20 = 1;
  local_28 = 1;
  FUN_00429830(param_1,1);
  local_1c = 1;
  do {
    puVar5 = *(uint **)(param_1 + 0x2c);
    puVar14 = puVar5 + *(int *)(param_1 + 0x28);
    local_30 = 0;
    local_24 = (uint *)0x0;
    local_34 = (uint *)0x0;
    local_18 = 32000;
    local_14 = 0xffff8300;
    for (; puVar5 < puVar14; puVar5 = puVar5 + 1) {
      puVar11 = (uint *)*puVar5;
      uVar6 = puVar11[7];
      uVar9 = 32000;
      uVar4 = 0xffff8300;
      if ((int)uVar6 < (int)local_18) {
        local_24 = puVar11;
        local_18 = uVar6;
      }
      if ((int)local_14 < (int)uVar6) {
        local_34 = puVar11;
        local_14 = uVar6;
      }
      if (puVar11 != (uint *)puVar11[0xe]) {
        uVar6 = ((uint *)puVar11[0xe])[10];
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        puVar10 = puVar11;
        if (uVar6 == local_20) {
          uVar6 = puVar11[10];
          if ((int)uVar6 < 0) {
            uVar6 = -uVar6;
          }
          if (uVar6 == local_20) {
            do {
              puVar10 = (uint *)puVar10[0xe];
              uVar6 = puVar10[10];
              if ((int)uVar6 < 0) {
                uVar6 = -uVar6;
              }
              if (uVar6 != local_20) {
                puVar10 = (uint *)puVar10[0xd];
                break;
              }
            } while (puVar10 != puVar11);
          }
        }
        bVar2 = false;
        bVar3 = false;
        puVar11 = puVar10;
        do {
          if (bVar2) {
            uVar6 = puVar11[7];
            if ((int)uVar6 < (int)uVar9) {
              uVar9 = uVar6;
            }
            if ((int)uVar4 < (int)uVar6) {
              uVar4 = uVar6;
            }
            if ((puVar11[10] != local_28) || (puVar11 == puVar10)) {
              puVar8[5] = (int)(uVar4 + uVar9) >> 1;
              puVar8[3] = (uint)puVar11;
              if (((*puVar11 | *(uint *)puVar8[2]) & 3) != 0) {
                *puVar8 = *puVar8 | 1;
              }
              uVar4 = puVar11[8];
              uVar6 = ((uint *)puVar8[2])[8];
              uVar9 = uVar4;
              if ((int)uVar6 < (int)uVar4) {
                uVar9 = uVar6;
              }
              if ((int)uVar4 < (int)uVar6) {
                uVar4 = uVar6;
              }
              bVar2 = false;
              local_30 = local_30 + 1;
              puVar8[6] = uVar9;
              puVar8[7] = uVar4;
              puVar8 = puVar8 + 0xe;
              goto LAB_00429696;
            }
          }
          else {
LAB_00429696:
            if (puVar11 == puVar10) {
              if (bVar3) break;
              bVar3 = true;
            }
          }
          if (!bVar2) {
            uVar6 = puVar11[10];
            uVar12 = uVar6;
            if ((int)uVar6 < 0) {
              uVar12 = -uVar6;
            }
            if (uVar12 == local_20) {
              puVar13 = puVar8;
              for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar13 = 0;
                puVar13 = puVar13 + 1;
              }
              puVar8[1] = uVar6;
              *puVar8 = 0;
              uVar4 = puVar11[7];
              puVar8[4] = (uint)puVar5;
              puVar8[2] = (uint)puVar11;
              puVar8[3] = (uint)puVar11;
              bVar2 = true;
              if (puVar11 == local_34) {
                local_34 = (uint *)0x0;
              }
              uVar9 = uVar4;
              local_28 = uVar6;
              if (puVar11 == local_24) {
                local_24 = (uint *)0x0;
              }
            }
          }
          puVar11 = (uint *)puVar11[0xd];
        } while( true );
      }
    }
    if (local_1c == 0) {
      uVar6 = *(uint *)(param_1 + 0x20);
      uVar12 = *(int *)(param_1 + 0x1c) * 0x3c + uVar6;
      uVar9 = 0;
      uVar4 = 32000;
      local_24 = (uint *)0xffff8300;
      local_34 = (uint *)0x0;
      if (uVar6 < uVar12) {
        do {
          uVar1 = *(uint *)(uVar6 + 0xc);
          if ((int)uVar1 < (int)uVar4) {
            uVar4 = uVar1;
            uVar9 = uVar6;
          }
          if ((int)local_24 < (int)uVar1) {
            local_34 = (uint *)uVar6;
            local_24 = (uint *)uVar1;
          }
          uVar6 = uVar6 + 0x3c;
        } while (uVar6 < uVar12);
        if (uVar9 != 0) {
          puVar14 = puVar8;
          for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          }
          puVar8[1] = local_28;
          local_30 = local_30 + 1;
          *puVar8 = 0;
          puVar8[2] = uVar9;
          puVar8[3] = uVar9;
          puVar8[5] = uVar4;
          puVar8 = puVar8 + 0xe;
        }
        if (local_34 != (uint *)0x0) {
          puVar14 = puVar8;
          for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          }
          puVar8[1] = local_28;
          puVar8[2] = (uint)local_34;
          puVar8[3] = (uint)local_34;
          local_30 = local_30 + 1;
          *puVar8 = 0;
          puVar8[5] = (uint)local_24;
        }
      }
    }
    *local_10 = local_30;
    puVar8 = *(uint **)(param_1 + 0x4c);
    local_10 = (int *)(param_1 + 0x48);
    local_20 = 2;
    FUN_00429830(param_1,0);
    local_1c = local_1c + -1;
    if (local_1c < 0) {
      return;
    }
  } while( true );
}



void __cdecl FUN_00429830(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  uVar4 = *(int *)(param_1 + 0x1c) * 0x3c + uVar1;
  do {
    if (uVar4 <= uVar1) {
      return;
    }
    switch(param_2) {
    case 0:
      uVar2 = *(undefined4 *)(uVar1 + 0xc);
      uVar3 = *(undefined4 *)(uVar1 + 0x10);
      break;
    case 1:
      uVar2 = *(undefined4 *)(uVar1 + 0x10);
      uVar3 = *(undefined4 *)(uVar1 + 0xc);
      break;
    case 2:
      uVar2 = *(undefined4 *)(uVar1 + 4);
      uVar3 = *(undefined4 *)(uVar1 + 8);
      break;
    case 3:
      uVar2 = *(undefined4 *)(uVar1 + 8);
      uVar3 = *(undefined4 *)(uVar1 + 4);
      break;
    case 4:
      uVar3 = *(undefined4 *)(uVar1 + 4);
      goto LAB_00429894;
    case 5:
      uVar2 = *(undefined4 *)(uVar1 + 0x18);
      uVar3 = *(undefined4 *)(uVar1 + 8);
      break;
    case 6:
      uVar2 = *(undefined4 *)(uVar1 + 0x18);
      uVar3 = *(undefined4 *)(uVar1 + 0x14);
      break;
    default:
      uVar3 = *(undefined4 *)(uVar1 + 0x18);
LAB_00429894:
      uVar2 = *(undefined4 *)(uVar1 + 0x14);
    }
    *(undefined4 *)(uVar1 + 0x1c) = uVar2;
    *(undefined4 *)(uVar1 + 0x20) = uVar3;
    uVar1 = uVar1 + 0x3c;
  } while( true );
}



void __cdecl FUN_004298d0(int param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  int local_4;
  
  FUN_00429830(param_1,1);
  local_10 = *(int **)(param_1 + 0x44);
  local_8 = local_10 + *(int *)(param_1 + 0x40) * 0xe;
  local_4 = 2;
  do {
    if (local_10 < local_8) {
      piVar5 = local_10 + 1;
      do {
        if (piVar5[1] != piVar5[2]) {
          piVar8 = (int *)piVar5[9];
          if (piVar8 == (int *)0x0) {
            local_14 = 32000;
          }
          else {
            local_14 = piVar5[0xc];
          }
          piVar9 = local_10 + 6;
          local_c = piVar8;
          do {
            if ((piVar5 + -1 != piVar9 + -6) && (iVar7 = *piVar5, piVar9[-5] + iVar7 == 0)) {
              iVar2 = piVar5[4];
              iVar6 = piVar9[-1];
              if ((iVar7 == *(int *)(param_1 + 8)) || (iVar7 == *(int *)(param_1 + 4))) {
                bVar3 = true;
              }
              else {
                bVar3 = false;
              }
              if ((iVar2 != iVar6) && (piVar8 = local_c, iVar6 <= iVar2 != bVar3)) {
                iVar7 = piVar5[5];
                if (piVar5[5] < *piVar9) {
                  iVar7 = *piVar9;
                }
                iVar4 = piVar5[6];
                if (piVar9[1] < piVar5[6]) {
                  iVar4 = piVar9[1];
                }
                iVar4 = iVar4 - iVar7;
                iVar6 = iVar6 - iVar2;
                if (iVar6 < 0) {
                  iVar6 = -iVar6;
                }
                if (iVar4 < 8) {
                  iVar4 = 800 - iVar4;
                  iVar6 = iVar6 + iVar4 * 2;
                }
                else {
                  iVar4 = (int)(300 / (longlong)iVar4);
                }
                if (iVar4 + iVar6 < local_14) {
                  piVar8 = piVar9 + -6;
                  local_14 = iVar4 + iVar6;
                  local_c = piVar8;
                }
              }
            }
            piVar1 = piVar9 + 8;
            piVar9 = piVar9 + 0xe;
          } while (piVar1 < local_8);
          if (piVar8 != (int *)0x0) {
            piVar5[9] = (int)piVar8;
            piVar5[0xc] = local_14;
            piVar8[0xc] = piVar8[0xc] + 1;
          }
        }
        piVar8 = piVar5 + 0xd;
        piVar5 = piVar5 + 0xe;
      } while (piVar8 < local_8);
      piVar5 = local_10 + 10;
      do {
        iVar7 = *piVar5;
        if ((iVar7 != 0) && (*(int **)(iVar7 + 0x28) != piVar5 + -10)) {
          *piVar5 = 0;
          piVar5[1] = *(int *)(iVar7 + 0x28);
        }
        piVar8 = piVar5 + 4;
        piVar5 = piVar5 + 0xe;
      } while (piVar8 < local_8);
    }
    FUN_00429830(param_1,0);
    local_10 = *(int **)(param_1 + 0x4c);
    local_8 = local_10 + *(int *)(param_1 + 0x48) * 0xe;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}



void __cdecl FUN_00429a70(int *param_1)

{
  FUN_00410d70(*(int *)(*param_1 + 100),(int *)&param_1);
  return;
}



int __cdecl FUN_00429a90(int param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  char cVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  undefined4 *puVar20;
  uint *puVar21;
  int *piVar22;
  undefined4 *puVar23;
  int *piVar24;
  undefined2 local_40;
  uint local_3c;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  int local_10;
  
  iVar8 = param_1;
  iVar17 = *(int *)(param_1 + 0xc);
  uVar11 = *(uint *)(*(int *)(iVar17 + 0x58) + 0x10);
  uVar13 = *(uint *)(*(int *)(iVar17 + 0x58) + 0x14);
  piVar4 = *(int **)(param_1 + 0x18);
  piVar22 = *(int **)(param_1 + 0x14);
  iVar5 = *(int *)(iVar17 + 0x54);
  iVar12 = *(int *)(iVar5 + 0x94);
  iVar9 = FUN_004111c0(iVar17,param_2,param_3);
  if (iVar9 == 0) {
    cVar2 = *(char *)(iVar12 + 4);
    *(char *)(param_1 + 0x2c) = cVar2;
    if (cVar2 != '\0') {
      local_24 = *(uint *)(iVar12 + 8);
      local_20 = *(uint *)(iVar12 + 0xc);
      local_1c = *(int *)(iVar12 + 0x10);
      local_18 = *(int *)(iVar12 + 0x14);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar12 + 0x18);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar12 + 0x1c);
      *(uint *)(param_1 + 0x38) = local_24;
      *(uint *)(param_1 + 0x3c) = local_20;
      *(uint *)(param_1 + 0x40) = local_1c;
      *(uint *)(param_1 + 0x44) = local_18;
      FUN_0042b040(&local_24);
      FUN_00412650((uint *)(param_1 + 0x30),&local_24);
    }
    *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar5 + 0x28);
    *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x34);
    if (*(int *)(iVar5 + 0x48) == 0x636f6d70) {
      uVar14 = *(uint *)(iVar5 + 0x80);
      sVar3 = *(short *)((int)piVar4 + 0x16);
      iVar17 = FUN_00410ff0(piVar4,uVar14);
      if (iVar17 != 0) {
        return iVar17;
      }
      puVar20 = *(undefined4 **)(iVar5 + 0x84);
      puVar23 = (undefined4 *)piVar4[0x13];
      for (uVar15 = (uVar14 << 5) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
        *puVar23 = *puVar20;
        puVar20 = puVar20 + 1;
        puVar23 = puVar23 + 1;
      }
      for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {
        *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
        puVar20 = (undefined4 *)((int)puVar20 + 1);
        puVar23 = (undefined4 *)((int)puVar23 + 1);
      }
      piVar4[0x12] = uVar14;
      local_3c = 0;
      iVar12 = 0;
      if (uVar14 != 0) {
        param_2 = piVar4[10] << 5;
        do {
          uVar6 = *(undefined4 *)(param_1 + 0x1c);
          uVar7 = *(undefined4 *)(param_1 + 0x20);
          local_24 = *(uint *)(param_1 + 0x24);
          uVar15 = (uint)*(short *)((int)piVar4 + 0x16);
          local_20 = *(uint *)(param_1 + 0x28);
          iVar17 = FUN_00429a90(param_1,*(uint *)(piVar4[0xb] + param_2),param_3,param_4 + 1);
          if (iVar17 != 0) {
            return iVar17;
          }
          iVar17 = piVar4[0xb] + param_2;
          if ((*(byte *)(iVar17 + 5) & 2) == 0) {
            *(undefined4 *)(param_1 + 0x1c) = uVar6;
            *(undefined4 *)(param_1 + 0x20) = uVar7;
            *(uint *)(param_1 + 0x24) = local_24;
            *(uint *)(param_1 + 0x28) = local_20;
          }
          uVar18 = (int)*(short *)((int)piVar4 + 0x16) - uVar15;
          if ((*(byte *)(iVar17 + 4) & 200) != 0) {
            puVar10 = (uint *)(piVar4[0xc] + uVar15 * 8);
            puVar21 = (uint *)(piVar4[6] + uVar15 * 8);
            puVar1 = puVar21 + uVar18 * 2;
            for (; puVar21 < puVar1; puVar21 = puVar21 + 2) {
              FUN_00412650(puVar21,(uint *)(iVar17 + 0x10));
              FUN_00412650(puVar10,(uint *)(iVar17 + 0x10));
              puVar10 = puVar10 + 2;
            }
          }
          if ((*(byte *)(iVar17 + 4) & 2) == 0) {
            uVar16 = (int)sVar3 + *(uint *)(iVar17 + 8);
            if ((uVar15 <= uVar16) || (uVar18 <= *(uint *)(iVar17 + 0xc))) {
              return 0x15;
            }
            iVar12 = piVar4[6];
            piVar22 = (int *)(iVar12 + (*(uint *)(iVar17 + 0xc) + uVar15 + (int)sVar3) * 8);
            uVar19 = *(int *)(iVar12 + uVar16 * 8) - *piVar22;
            uVar16 = *(int *)(iVar12 + 4 + uVar16 * 8) - piVar22[1];
          }
          else {
            uVar19 = FUN_00410b80(*(uint *)(iVar17 + 8),uVar11);
            uVar19 = uVar19 + 0x20 & 0xffffffc0;
            uVar16 = FUN_00410b80(*(uint *)(iVar17 + 0xc),uVar13);
            uVar16 = uVar16 + 0x20 & 0xffffffc0;
          }
          piVar22 = piVar4 + 5;
          piVar24 = &local_14;
          for (iVar17 = 5; iVar17 != 0; iVar17 = iVar17 + -1) {
            *piVar24 = *piVar22;
            piVar22 = piVar22 + 1;
            piVar24 = piVar24 + 1;
          }
          local_10 = local_10 + uVar15 * 8;
          local_40 = (undefined2)uVar18;
          local_14._2_2_ = local_40;
          FUN_00412600((int)&local_14,uVar19,uVar16);
          local_3c = local_3c + 1;
          param_2 = param_2 + 0x20;
          iVar12 = 0;
        } while (local_3c < uVar14);
      }
    }
    else if (*(int *)(iVar5 + 0x48) == 0x6f75746c) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        piVar24 = *(int **)(iVar5 + 0x70);
        for (iVar12 = (int)*(short *)(iVar5 + 0x6e); iVar12 != 0; iVar12 = iVar12 + -1) {
          *piVar24 = *piVar24 + *(int *)(param_1 + 0x30);
          piVar24[1] = piVar24[1] + *(int *)(param_1 + 0x34);
          piVar24 = piVar24 + 2;
        }
      }
      iVar12 = FUN_00410f10(piVar4,*(short *)(iVar5 + 0x6e) + 2,(int)*(short *)(iVar5 + 0x6c));
      if (iVar12 != 0) {
        return iVar12;
      }
      puVar20 = *(undefined4 **)(iVar5 + 0x70);
      puVar23 = (undefined4 *)piVar4[0x14];
      for (uVar13 = (uint)((int)*(short *)(iVar5 + 0x6e) << 3) >> 2; uVar13 != 0;
          uVar13 = uVar13 - 1) {
        *puVar23 = *puVar20;
        puVar20 = puVar20 + 1;
        puVar23 = puVar23 + 1;
      }
      for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
        puVar20 = (undefined4 *)((int)puVar20 + 1);
        puVar23 = (undefined4 *)((int)puVar23 + 1);
      }
      uVar14 = (int)*(short *)(iVar5 + 0x6c) << 1;
      puVar20 = *(undefined4 **)(iVar5 + 0x78);
      puVar23 = (undefined4 *)piVar4[0x10];
      for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *puVar23 = *puVar20;
        puVar20 = puVar20 + 1;
        puVar23 = puVar23 + 1;
      }
      for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
        *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
        puVar20 = (undefined4 *)((int)puVar20 + 1);
        puVar23 = (undefined4 *)((int)puVar23 + 1);
      }
      sVar3 = *(short *)(iVar5 + 0x6e);
      puVar20 = *(undefined4 **)(iVar5 + 0x74);
      puVar23 = (undefined4 *)piVar4[0xf];
      for (uVar13 = (uint)(int)sVar3 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *puVar23 = *puVar20;
        puVar20 = puVar20 + 1;
        puVar23 = puVar23 + 1;
      }
      for (uVar13 = (int)sVar3 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
        puVar20 = (undefined4 *)((int)puVar20 + 1);
        puVar23 = (undefined4 *)((int)puVar23 + 1);
      }
      *(undefined2 *)((int)piVar4 + 0x36) = *(undefined2 *)(iVar5 + 0x6e);
      *(undefined2 *)(piVar4 + 0xd) = *(undefined2 *)(iVar5 + 0x6c);
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      uVar13 = FUN_00410b80(*(uint *)(iVar5 + 0x28),uVar11);
      *(uint *)(param_1 + 0x24) = uVar13;
      *(undefined4 *)(param_1 + 0x28) = 0;
      iVar12 = 0;
      if (*(short *)(iVar5 + 0x6e) != 0) {
        iVar17 = FUN_00428ec0(piVar22,iVar17);
        if (iVar17 != 0) {
          return iVar17;
        }
        FUN_0042a0d0((int)piVar22);
        if ((param_3 >> 0x11 & 1) == 0) {
          FUN_0042a3f0((int)piVar22,*(int **)(param_1 + 0x10));
          FUN_0042a590((int)piVar22);
        }
        FUN_0042a5c0(param_1);
        FUN_0042aa00(param_1);
        FUN_0042a080((int)piVar22,(int)piVar4);
        iVar12 = piVar22[0xf];
        iVar17 = piVar22[0xe] * 0x30 + -0x30 + iVar12;
        iVar9 = *(int *)(param_1 + 0x24) - *(int *)(piVar22[0xe] * 0x30 + -0x1c + iVar12);
        uVar14 = (*(int *)(iVar12 + 0x18) - *(int *)(iVar12 + 0x14)) + 0x20U & 0xffffffc0;
        *(uint *)(param_1 + 0x1c) = uVar14;
        uVar13 = *(int *)(iVar17 + 0x18) + 0x20 + iVar9 & 0xffffffc0;
        *(uint *)(param_1 + 0x24) = uVar13;
        if ((uVar14 + uVar13 == *(int *)(iVar17 + 0x18)) && (4 < iVar9)) {
          *(uint *)(param_1 + 0x24) = uVar13 + 0x40;
        }
        FUN_004110a0((int)piVar4);
        iVar12 = 0;
      }
    }
    else {
      param_1 = 7;
      iVar12 = param_1;
    }
    param_1 = iVar12;
    iVar9 = param_1;
    if (param_4 == 0) {
      if (*(char *)(iVar8 + 0x2c) != '\0') {
        FUN_004126b0((int)(piVar4 + 5),(uint *)(iVar8 + 0x38));
      }
      if (*(int *)(iVar8 + 0x1c) != 0) {
        FUN_00412600((int)(piVar4 + 5),-*(int *)(iVar8 + 0x1c),0);
      }
      FUN_00412570((int)(piVar4 + 5),(int *)&local_24);
      local_1c = local_1c + 0x3f & 0xffffffc0;
      local_24 = local_24 & 0xffffffc0;
      local_18 = local_18 + 0x3f & 0xffffffc0;
      *(uint *)(iVar5 + 0x18) = local_1c - local_24;
      local_20 = local_20 & 0xffffffc0;
      *(uint *)(iVar5 + 0x24) = local_18;
      *(uint *)(iVar5 + 0x1c) = local_18 - local_20;
      *(uint *)(iVar5 + 0x20) = local_24;
      if ((*(byte *)(*(int *)(iVar5 + 4) + 8) & 4) == 0) {
        *(int *)(iVar5 + 0x28) = *(int *)(iVar8 + 0x24) - *(int *)(iVar8 + 0x1c);
      }
      else {
        uVar11 = FUN_00410b80(*(uint *)(iVar5 + 0x28),uVar11);
        *(uint *)(iVar5 + 0x28) = uVar11;
      }
      *(uint *)(iVar5 + 0x28) = *(int *)(iVar5 + 0x28) + 0x20U & 0xffffffc0;
      FUN_00410dd0(**(int **)(iVar5 + 0x94));
      iVar9 = FUN_004110f0((int *)**(undefined4 **)(iVar5 + 0x94),(int)piVar4);
      if (iVar9 == 0) {
        puVar20 = (undefined4 *)(**(int **)(iVar5 + 0x94) + 0x14);
        puVar23 = (undefined4 *)(iVar5 + 0x6c);
        for (iVar17 = 5; iVar17 != 0; iVar17 = iVar17 + -1) {
          *puVar23 = *puVar20;
          puVar20 = puVar20 + 1;
          puVar23 = puVar23 + 1;
        }
        *(undefined4 *)(iVar5 + 0x48) = 0x6f75746c;
      }
    }
  }
  param_1 = iVar9;
  return param_1;
}



void __cdecl FUN_0042a080(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  char *pcVar4;
  
  puVar1 = *(uint **)(param_1 + 0x20);
  puVar3 = *(uint **)(param_2 + 0x38);
  puVar2 = puVar1 + *(int *)(param_1 + 0x1c) * 0xf;
  pcVar4 = *(char **)(param_2 + 0x3c);
  for (; puVar1 < puVar2; puVar1 = puVar1 + 0xf) {
    *puVar3 = puVar1[5];
    puVar3[1] = puVar1[6];
    if ((*puVar1 & 1) == 0) {
      *pcVar4 = ((*puVar1 & 2) != 0) + '\x01';
    }
    else {
      *pcVar4 = '\0';
    }
    puVar3 = puVar3 + 2;
    pcVar4 = pcVar4 + 1;
  }
  return;
}



void __cdecl FUN_0042a0d0(int param_1)

{
  FUN_00429540(param_1);
  FUN_004298d0(param_1);
  FUN_0042a0f0(param_1);
  return;
}



void __cdecl FUN_0042a0f0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int *local_8;
  int local_4;
  
  uVar8 = *(uint *)(param_1 + 0x44);
  local_20 = *(int **)(param_1 + 0x34);
  local_14 = *(uint *)(param_1 + 0x10);
  uVar9 = *(int *)(param_1 + 0x40) * 0x38 + uVar8;
  local_8 = (int *)(param_1 + 0x30);
  local_18 = 1;
  local_4 = 2;
  do {
    local_10 = FUN_00410b80(*(uint *)(param_1 + 0x14),local_14);
    local_1c = local_20;
    piVar6 = local_20;
    if (0x10 < (int)local_10) {
      local_10 = 0x10;
    }
    for (; uVar8 < uVar9; uVar8 = uVar8 + 0x38) {
      piVar5 = local_20;
      if (local_20 < piVar6) {
        do {
          piVar12 = piVar5;
          uVar2 = *(int *)(uVar8 + 0x14) - piVar12[4];
          if ((int)uVar2 < 0) {
            uVar2 = -uVar2;
          }
          uVar2 = FUN_00410b80(uVar2,local_14);
          if ((int)uVar2 < (int)local_10) {
            *(int *)(uVar8 + 0x24) = piVar12[2];
            *(uint *)(piVar12[3] + 0x24) = uVar8;
            piVar12[3] = uVar8;
            goto LAB_0042a213;
          }
          piVar5 = piVar12 + 0xc;
        } while (piVar5 < piVar6);
        for (; (local_20 < piVar5 && (*(int *)(uVar8 + 0x14) < piVar12[4]));
            piVar12 = piVar12 + -0xc) {
          piVar6 = piVar12;
          piVar11 = piVar5;
          for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar11 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar11 = piVar11 + 1;
          }
          piVar5 = piVar5 + -0xc;
          piVar6 = local_1c;
        }
      }
      piVar12 = piVar5;
      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
      }
      piVar5[2] = uVar8;
      piVar5[3] = uVar8;
      piVar5[4] = *(int *)(uVar8 + 0x14);
      piVar6 = piVar6 + 0xc;
      uVar2 = FUN_00410b80(*(uint *)(uVar8 + 0x14),local_14);
      piVar5[6] = uVar2;
      piVar5[5] = uVar2;
      *(uint *)(uVar8 + 0x24) = uVar8;
      local_1c = piVar6;
LAB_0042a213:
    }
    *local_8 = ((int)piVar6 - (int)local_20) / 0x30;
    piVar5 = local_20;
    if (local_20 < piVar6) {
      do {
        iVar4 = piVar5[2];
        if (iVar4 != 0) {
          do {
            *(int **)(iVar4 + 0x20) = piVar5;
            iVar4 = *(int *)(iVar4 + 0x24);
          } while (iVar4 != piVar5[2]);
        }
        piVar5 = piVar5 + 0xc;
      } while (piVar5 < piVar6);
      piVar6 = local_20 + 1;
      do {
        pbVar10 = (byte *)piVar6[1];
        local_14 = 0;
        local_20 = (int *)0x0;
        local_10 = 0;
        local_c = 0;
        do {
          if ((*pbVar10 & 1) == 0) {
            local_20 = (int *)((int)local_20 + 1);
          }
          else {
            local_14 = local_14 + 1;
          }
          if (*(int *)(pbVar10 + 4) == local_18) {
            local_10 = local_10 + (*(int *)(pbVar10 + 0x1c) - *(int *)(pbVar10 + 0x18));
          }
          else {
            local_c = local_c + (*(int *)(pbVar10 + 0x1c) - *(int *)(pbVar10 + 0x18));
          }
          iVar4 = *(int *)(pbVar10 + 0x2c);
          if ((iVar4 == 0) || (*(int **)(iVar4 + 0x20) == piVar6 + -1)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if ((*(int *)(pbVar10 + 0x28) != 0) || (bVar1)) {
            iVar3 = piVar6[6];
            iVar13 = *(int *)(pbVar10 + 0x28);
            if (bVar1) {
              iVar3 = piVar6[7];
              iVar13 = iVar4;
            }
            if (iVar3 == 0) {
LAB_0042a315:
              iVar3 = *(int *)(iVar13 + 0x20);
            }
            else {
              iVar4 = piVar6[3] - *(int *)(iVar3 + 0x10);
              if (iVar4 < 0) {
                iVar4 = -iVar4;
              }
              iVar7 = *(int *)(pbVar10 + 0x14) - *(int *)(iVar13 + 0x14);
              if (iVar7 < 0) {
                iVar7 = -iVar7;
              }
              if (iVar7 < iVar4) goto LAB_0042a315;
            }
            if (bVar1) {
              piVar6[7] = iVar3;
            }
            else {
              piVar6[6] = iVar3;
            }
          }
          pbVar10 = *(byte **)(pbVar10 + 0x24);
        } while (pbVar10 != (byte *)piVar6[1]);
        piVar6[-1] = 0;
        if ((0 < (int)local_14) && ((int)local_20 <= (int)local_14)) {
          piVar6[-1] = 1;
        }
        *piVar6 = 4;
        if (local_c < (int)local_10) {
          *piVar6 = local_18;
        }
        else if ((int)local_10 < local_c) {
          *piVar6 = -local_18;
        }
        else if (local_10 == local_c) {
          *piVar6 = 0;
        }
        if ((piVar6[7] != 0) && (piVar6[6] != 0)) {
          piVar6[7] = 0;
        }
        piVar5 = piVar6 + 0xb;
        piVar6 = piVar6 + 0xc;
      } while (piVar5 < local_1c);
    }
    local_20 = *(int **)(param_1 + 0x3c);
    uVar8 = *(uint *)(param_1 + 0x4c);
    local_14 = *(uint *)(param_1 + 0xc);
    uVar9 = *(int *)(param_1 + 0x48) * 0x38 + uVar8;
    local_8 = (int *)(param_1 + 0x38);
    local_4 = local_4 + -1;
    local_18 = 2;
    if (local_4 == 0) {
      return;
    }
  } while( true );
}



void __cdecl FUN_0042a3f0(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  int local_18;
  int *local_10;
  char acStack_8 [8];
  
  pbVar4 = *(byte **)(param_1 + 0x34);
  uVar1 = *(uint *)(param_1 + 0x10);
  pbVar6 = pbVar4 + *(int *)(param_1 + 0x30) * 0x30;
  bVar5 = false;
  iVar8 = 0;
  piVar7 = param_2 + 0x1b;
  do {
    uVar2 = *piVar7 - piVar7[5];
    if ((int)uVar2 < 0) {
      uVar2 = -uVar2;
    }
    acStack_8[iVar8] = '\0';
    uVar2 = FUN_00410b80(uVar2,uVar1);
    if ((int)uVar2 < 0x30) {
      acStack_8[iVar8] = '\x01';
      bVar5 = true;
    }
    iVar8 = iVar8 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar8 < 5);
  if (bVar5) {
    for (; pbVar4 < pbVar6; pbVar4 = pbVar4 + 0x30) {
      local_10 = (int *)0x0;
      uVar2 = FUN_00410b80(*(ushort *)(*param_2 + 0x44) / 0x28,uVar1);
      if (0x10 < (int)uVar2) {
        uVar2 = 0x10;
      }
      piVar7 = param_2 + 0x1b;
      local_18 = 0;
      do {
        if ((local_18 == 0) || (local_18 == 2)) {
          bVar5 = true;
        }
        else {
          bVar5 = false;
        }
        if ((acStack_8[local_18] != '\0') &&
           ((*(int *)(pbVar4 + 4) == *(int *)(param_1 + 8)) != bVar5)) {
          uVar3 = *(int *)(pbVar4 + 0x10) - *piVar7;
          if ((int)uVar3 < 0) {
            uVar3 = -uVar3;
          }
          uVar3 = FUN_00410b80(uVar3,uVar1);
          if ((int)uVar3 < (int)uVar2) {
            uVar2 = uVar3;
            local_10 = piVar7;
          }
          if ((((*pbVar4 & 1) != 0) && (uVar3 != 0)) && (*(int *)(pbVar4 + 0x10) < *piVar7 != bVar5)
             ) {
            uVar3 = *(int *)(pbVar4 + 0x10) - piVar7[5];
            if ((int)uVar3 < 0) {
              uVar3 = -uVar3;
            }
            uVar3 = FUN_00410b80(uVar3,uVar1);
            if ((int)uVar3 < (int)uVar2) {
              uVar2 = uVar3;
              local_10 = piVar7 + 5;
            }
          }
        }
        local_18 = local_18 + 1;
        piVar7 = piVar7 + 1;
      } while (local_18 < 5);
      if (local_10 != (int *)0x0) {
        *(int **)(pbVar4 + 0x2c) = local_10;
      }
    }
  }
  return;
}



void __cdecl FUN_0042a590(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  uVar2 = *(int *)(param_1 + 0x30) * 0x30 + uVar1;
  for (; uVar1 < uVar2; uVar1 = uVar1 + 0x30) {
    if (*(int *)(uVar1 + 0x2c) != 0) {
      *(int *)(uVar1 + 0x2c) = *(int *)(uVar1 + 0x2c) + 0x90;
    }
  }
  return;
}



void __cdecl FUN_0042a5c0(int param_1)

{
  FUN_0042a5d0(param_1);
  return;
}



void __cdecl FUN_0042a5d0(int param_1)

{
  int iVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *local_14;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x14);
  local_14 = *(uint **)(iVar1 + 0x34);
  puVar6 = local_14 + *(int *)(iVar1 + 0x30) * 0xc;
  local_8 = 1;
  do {
    puVar7 = (uint *)0x0;
    local_c = 0;
    if (local_8 == 0) {
LAB_0042a689:
      puVar9 = local_14;
      if (local_14 < puVar6) {
        do {
          if ((*puVar9 & 4) == 0) {
            puVar8 = (uint *)puVar9[7];
            if (puVar8 == (uint *)0x0) {
              local_c = local_c + 1;
            }
            else if ((puVar8[0xb] == 0) && (puVar9 <= puVar8)) {
              bVar2 = false;
              if (puVar7 == (uint *)0x0) {
                puVar9[6] = puVar9[5] + 0x20 & 0xffffffc0;
                puVar7 = puVar9;
              }
              else {
                puVar9[6] = ((puVar9[5] - puVar7[5]) + 0x20 & 0xffffffc0) + puVar7[6];
              }
              *puVar9 = *puVar9 | 4;
              if ((local_14 < puVar9) && ((int)puVar9[6] < (int)puVar9[-6])) {
                puVar9[6] = puVar9[-6];
                bVar2 = true;
              }
              FUN_0042a850(param_1,(int)puVar9,(int)puVar8,local_8);
              if ((puVar8 + 0xc < puVar6) && ((puVar8[0xc] & 4) != 0)) {
                iVar4 = puVar8[0x12] - puVar8[6];
                if ((iVar4 < 0) && (puVar8[6] = puVar8[6] + iVar4, !bVar2)) {
                  puVar9[6] = puVar9[6] + iVar4;
                }
              }
              *puVar8 = *puVar8 | 4;
            }
            else {
              FUN_0042a850(param_1,(int)puVar8,(int)puVar9,local_8);
              *puVar9 = *puVar9 | 4;
            }
          }
          puVar9 = puVar9 + 0xc;
        } while (puVar9 < puVar6);
        if (local_c != 0) {
          puVar9 = local_14 + 5;
          do {
            puVar8 = puVar9 + -5;
            if ((puVar9[-5] & 4) == 0) {
              if ((byte *)puVar9[3] == (byte *)0x0) {
                if (puVar7 == (uint *)0x0) {
                  puVar9[1] = *puVar9 + 0x20 & 0xffffffc0;
                  puVar7 = puVar8;
                }
                else {
                  puVar9[1] = ((*puVar9 - puVar7[5]) + 0x20 & 0xffffffc0) + puVar7[6];
                }
              }
              else {
                FUN_0042a990(param_1,(byte *)puVar9[3],(int)puVar8,local_8);
              }
              *puVar8 = *puVar8 | 4;
              if ((local_14 < puVar9 + -5) && ((int)puVar9[1] < (int)puVar9[-0xb])) {
                puVar9[1] = puVar9[-0xb];
              }
              if (((puVar9 + 7 < puVar6) && ((puVar9[7] & 4) != 0)) &&
                 ((int)puVar9[0xd] < (int)puVar9[1])) {
                puVar9[1] = puVar9[0xd];
              }
            }
            puVar8 = puVar9 + 7;
            puVar9 = puVar9 + 0xc;
          } while (puVar8 < puVar6);
        }
      }
    }
    else {
      puVar9 = local_14;
      if (local_14 < puVar6) {
        do {
          if ((*puVar9 & 4) == 0) {
            puVar5 = (uint *)puVar9[0xb];
            puVar8 = (uint *)puVar9[7];
            puVar3 = puVar9;
            if (((puVar5 != (uint *)0x0) ||
                ((puVar8 != (uint *)0x0 &&
                 (puVar5 = (uint *)puVar8[0xb], puVar3 = puVar8, puVar8 = puVar9,
                 puVar5 != (uint *)0x0)))) && (puVar3 != (uint *)0x0)) {
              puVar3[6] = *puVar5;
              *puVar3 = *puVar3 | 4;
              if ((puVar8 != (uint *)0x0) && (puVar8[0xb] == 0)) {
                FUN_0042a850(param_1,(int)puVar3,(int)puVar8,local_8);
                *puVar8 = *puVar8 | 4;
              }
              if (puVar7 == (uint *)0x0) {
                puVar7 = puVar9;
              }
            }
          }
          puVar9 = puVar9 + 0xc;
        } while (puVar9 < puVar6);
        goto LAB_0042a689;
      }
    }
    local_14 = *(uint **)(iVar1 + 0x3c);
    puVar6 = local_14 + *(int *)(iVar1 + 0x38) * 0xc;
    local_8 = local_8 + -1;
    if (local_8 < 0) {
      return;
    }
  } while( true );
}



void __cdecl FUN_0042a850(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_3 + 0x14) - *(int *)(param_2 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = 1;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
    iVar3 = -1;
  }
  if (param_4 != 0) {
    iVar2 = FUN_0042a930(iVar2 + 0xcc,*(int *)(iVar2 + 0x98),iVar1);
    if (0x3f < iVar2) {
      *(uint *)(param_3 + 0x18) = iVar3 * (iVar2 + 0x10U & 0xffffffc0) + *(int *)(param_2 + 0x18);
      return;
    }
LAB_0042a8cb:
    *(int *)(param_3 + 0x18) = iVar3 * 0x40 + *(int *)(param_2 + 0x18);
    return;
  }
  iVar2 = FUN_0042a930(iVar2 + 0x9c,*(int *)(iVar2 + 0x94),iVar1);
  if ((*(byte *)(param_1 + 4) & 1) == 0) {
    if (iVar2 < 0x30) {
      *(int *)(param_3 + 0x18) = iVar3 * (iVar2 + 0x40 >> 1) + *(int *)(param_2 + 0x18);
      return;
    }
    if (iVar2 < 0x80) {
      *(uint *)(param_3 + 0x18) = iVar3 * (iVar2 + 0x2aU & 0xffffffc0) + *(int *)(param_2 + 0x18);
      return;
    }
  }
  else if (iVar2 < 0x40) goto LAB_0042a8cb;
  *(uint *)(param_3 + 0x18) = iVar3 * (iVar2 + 0x20U & 0xffffffc0) + *(int *)(param_2 + 0x18);
  return;
}



int __cdecl FUN_0042a930(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar3 = 0x62;
  iVar5 = param_3;
  if (0 < param_2) {
    do {
      iVar1 = *(int *)(param_1 + iVar4 * 4);
      iVar2 = param_3 - iVar1;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
        iVar5 = iVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
    if (param_3 < iVar5) {
      if (param_3 + 0x21 <= iVar5) {
        return param_3 + 0x21;
      }
      return iVar5;
    }
  }
  if (iVar5 <= param_3 + -0x21) {
    return param_3 + -0x21;
  }
  return iVar5;
}



void __cdecl FUN_0042a990(undefined4 param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 0x14) - *(int *)(param_2 + 0x14);
  iVar2 = 1;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
    iVar2 = -1;
  }
  if ((*param_2 & 4) != 0) {
    if (0x3f < iVar1) {
      *(uint *)(param_3 + 0x18) = (iVar1 + 8U & 0xffffffc0) * iVar2 + *(int *)(param_2 + 0x18);
      return;
    }
    if ((iVar1 < 0x21) && (param_4 == 0)) {
      *(int *)(param_3 + 0x18) = (iVar1 + 0x21 >> 1) * iVar2 + *(int *)(param_2 + 0x18);
      return;
    }
    iVar1 = 0;
  }
  *(int *)(param_3 + 0x18) = iVar1 * iVar2 + *(int *)(param_2 + 0x18);
  return;
}



void __cdecl FUN_0042aa00(int param_1)

{
  FUN_0042aa20(param_1);
  FUN_0042aab0(param_1);
  return;
}



void __cdecl FUN_0042aa20(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 0x14);
  piVar3 = *(int **)(iVar2 + 0x34);
  piVar7 = piVar3 + *(int *)(iVar2 + 0x30) * 0xc;
  iVar8 = 1;
  do {
    if (piVar3 < piVar7) {
      piVar3 = piVar3 + 2;
      do {
        iVar5 = *piVar3;
        do {
          puVar4 = *(uint **)(iVar5 + 8);
          while( true ) {
            if (iVar8 == 0) {
              puVar4[5] = piVar3[4];
              uVar6 = *puVar4 | 0x40;
            }
            else {
              puVar4[6] = piVar3[4];
              uVar6 = *puVar4 | 0x80;
            }
            *puVar4 = uVar6;
            if (puVar4 == *(uint **)(iVar5 + 0xc)) break;
            puVar4 = (uint *)puVar4[0xd];
          }
          iVar5 = *(int *)(iVar5 + 0x24);
        } while (iVar5 != *piVar3);
        piVar1 = piVar3 + 10;
        piVar3 = piVar3 + 0xc;
      } while (piVar1 < piVar7);
    }
    piVar3 = *(int **)(iVar2 + 0x3c);
    piVar7 = piVar3 + *(int *)(iVar2 + 0x38) * 0xc;
    iVar8 = iVar8 + -1;
  } while (-1 < iVar8);
  return;
}



void __cdecl FUN_0042aab0(int param_1)

{
  FUN_0042aa20(param_1);
  FUN_0042aad0(param_1);
  FUN_0042ac60(param_1);
  return;
}



void __cdecl FUN_0042aad0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  uint local_18;
  int local_14;
  uint local_10;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar3 = *(int *)(iVar2 + 0x1c);
  piVar4 = *(int **)(iVar2 + 0x20);
  uVar11 = *(uint *)(iVar2 + 0x34);
  local_18 = *(int *)(iVar2 + 0x30) * 0x30 + uVar11;
  local_10 = 0x80;
  local_14 = 1;
  while ((local_18 <= uVar11 || (piVar4 + iVar3 * 0xf <= piVar4))) {
LAB_0042ac27:
    uVar11 = *(uint *)(iVar2 + 0x3c);
    local_18 = *(int *)(iVar2 + 0x38) * 0x30 + uVar11;
    local_14 = local_14 + -1;
    local_10 = 0x40;
    if (local_14 < 0) {
      return;
    }
  }
  piVar12 = piVar4 + 2;
LAB_0042ab34:
  if (((local_10 & piVar12[-2]) == 0) && ((piVar12[-2] & 0x100U) == 0)) {
    if (local_14 == 0) {
      iVar10 = piVar12[1];
      iVar7 = piVar12[-1];
    }
    else {
      iVar10 = piVar12[2];
      iVar7 = *piVar12;
    }
    if (*(int *)(uVar11 + 0x10) - iVar10 < 0) {
      if (iVar10 - *(int *)(local_18 - 0x20) < 0) {
        uVar8 = uVar11;
        uVar13 = 0;
        do {
          uVar9 = uVar8;
          if (iVar10 == *(int *)(uVar9 + 0x10)) goto LAB_0042abf5;
          uVar6 = 0;
          uVar5 = local_18;
        } while ((*(int *)(uVar9 + 0x10) <= iVar10) &&
                (uVar8 = uVar9 + 0x30, uVar13 = uVar9, uVar9 + 0x30 < local_18));
        do {
          uVar8 = uVar6;
          uVar9 = uVar5 - 0x30;
          if (uVar9 < uVar11) break;
          piVar1 = (int *)(uVar5 - 0x20);
          if (iVar10 == *piVar1) goto LAB_0042abf5;
          uVar6 = uVar9;
          uVar5 = uVar9;
        } while (iVar10 < *piVar1);
        uVar8 = FUN_00410a10(iVar10 - *(int *)(uVar13 + 0x10),
                             *(int *)(uVar8 + 0x18) - *(int *)(uVar13 + 0x18),
                             *(int *)(uVar8 + 0x10) - *(int *)(uVar13 + 0x10));
        iVar7 = uVar8 + *(int *)(uVar13 + 0x18);
      }
      else {
        iVar7 = (*(int *)(local_18 - 0x18) - *(int *)(local_18 - 0x1c)) + iVar7;
      }
    }
    else {
      iVar7 = (*(int *)(uVar11 + 0x18) - *(int *)(uVar11 + 0x14)) + iVar7;
    }
    goto LAB_0042abe8;
  }
  goto LAB_0042ac15;
LAB_0042abf5:
  iVar7 = *(int *)(uVar9 + 0x18);
LAB_0042abe8:
  if (local_14 == 0) {
    piVar12[3] = iVar7;
  }
  else {
    piVar12[4] = iVar7;
  }
  piVar12[-2] = piVar12[-2] | local_10;
LAB_0042ac15:
  piVar1 = piVar12 + 0xd;
  piVar12 = piVar12 + 0xf;
  if (piVar4 + iVar3 * 0xf <= piVar1) goto LAB_0042ac27;
  goto LAB_0042ab34;
}



void __cdecl FUN_0042ac60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint local_1c;
  int local_18;
  
  iVar1 = *(int *)(param_1 + 0x14);
  puVar10 = *(uint **)(iVar1 + 0x20);
  iVar2 = *(int *)(iVar1 + 0x28);
  iVar3 = *(int *)(iVar1 + 0x2c);
  puVar12 = puVar10 + *(int *)(iVar1 + 0x1c) * 0xf;
  local_1c = 0x80;
  FUN_00429830(iVar1,5);
  local_18 = 1;
  do {
    for (puVar8 = *(undefined4 **)(iVar1 + 0x2c); puVar8 < (undefined4 *)(iVar3 + iVar2 * 4);
        puVar8 = puVar8 + 1) {
      puVar9 = (uint *)*puVar8;
      puVar4 = (uint *)puVar9[0xe];
      for (puVar11 = puVar9; puVar11 <= puVar4; puVar11 = puVar11 + 0xf) {
        if ((*puVar11 & local_1c) != 0) {
          puVar5 = puVar11;
          puVar7 = puVar11;
          if (puVar11 <= puVar4) {
            while (puVar6 = puVar7, puVar7 = puVar6 + 0xf, puVar7 <= puVar4) {
              if ((*puVar7 & local_1c) != 0) {
                FUN_0042ae30((int *)(puVar5 + 0xf),(int *)puVar6,(int)puVar5,(int)puVar7);
                puVar5 = puVar7;
              }
            }
            if (puVar5 == puVar11) {
              FUN_0042ade0((int *)puVar9,(int *)puVar4,(int *)puVar5);
            }
            else {
              FUN_0042ae30((int *)(puVar5 + 0xf),(int *)puVar4,(int)puVar5,(int)puVar11);
              if (puVar10 < puVar11) {
                FUN_0042ae30((int *)puVar9,(int *)(puVar11 + -0xf),(int)puVar5,(int)puVar11);
              }
            }
          }
          break;
        }
      }
    }
    if (local_18 == 0) {
      if (puVar10 < puVar12) {
        puVar10 = puVar10 + 5;
        do {
          *puVar10 = puVar10[2];
          puVar9 = puVar10 + 10;
          puVar10 = puVar10 + 0xf;
        } while (puVar9 < puVar12);
      }
      return;
    }
    if (puVar10 < puVar12) {
      puVar9 = puVar10 + 6;
      do {
        *puVar9 = puVar9[1];
        puVar4 = puVar9 + 9;
        puVar9 = puVar9 + 0xf;
      } while (puVar4 < puVar12);
    }
    local_1c = 0x40;
    FUN_00429830(iVar1,4);
    local_18 = local_18 + -1;
    if (local_18 < 0) {
      return;
    }
  } while( true );
}



void __cdecl FUN_0042ade0(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = param_3[8];
  iVar3 = param_3[7];
  if (param_1 < param_3) {
    piVar4 = param_1 + 7;
    do {
      *piVar4 = piVar4[1] + (iVar3 - iVar2);
      piVar1 = piVar4 + 8;
      piVar4 = piVar4 + 0xf;
    } while (piVar1 < param_3);
  }
  while (param_3 + 0xf <= param_2) {
    param_3[0x16] = param_3[0x17] + (iVar3 - iVar2);
    param_3 = param_3 + 0xf;
  }
  return;
}



void __cdecl FUN_0042ae30(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_3 + 0x20);
  iVar3 = *(int *)(param_4 + 0x20);
  iVar4 = *(int *)(param_4 + 0x1c) - iVar3;
  iVar8 = *(int *)(param_3 + 0x1c) - iVar2;
  if (param_1 <= param_2) {
    if (iVar2 == iVar3) {
      piVar7 = param_1 + 7;
      do {
        iVar3 = iVar4;
        if (piVar7[1] <= iVar2) {
          iVar3 = iVar8;
        }
        *piVar7 = piVar7[1] + iVar3;
        piVar1 = piVar7 + 8;
        piVar7 = piVar7 + 0xf;
      } while (piVar1 <= param_2);
      return;
    }
    piVar7 = param_1 + 7;
    if (iVar2 < iVar3) {
      do {
        iVar5 = piVar7[1];
        if (iVar2 < iVar5) {
          if (iVar5 < iVar3) {
            uVar6 = FUN_00410a10(iVar5 - iVar2,*(int *)(param_4 + 0x1c) - *(int *)(param_3 + 0x1c),
                                 iVar3 - iVar2);
            iVar5 = uVar6 + *(int *)(param_3 + 0x1c);
          }
          else {
            iVar5 = iVar5 + iVar4;
          }
        }
        else {
          iVar5 = iVar5 + iVar8;
        }
        *piVar7 = iVar5;
        piVar1 = piVar7 + 8;
        piVar7 = piVar7 + 0xf;
      } while (piVar1 <= param_2);
      return;
    }
    do {
      iVar5 = piVar7[1];
      if (iVar3 < iVar5) {
        if (iVar5 < iVar2) {
          uVar6 = FUN_00410a10(iVar5 - iVar2,*(int *)(param_4 + 0x1c) - *(int *)(param_3 + 0x1c),
                               iVar3 - iVar2);
          iVar5 = uVar6 + *(int *)(param_3 + 0x1c);
        }
        else {
          iVar5 = iVar5 + iVar8;
        }
      }
      else {
        iVar5 = iVar5 + iVar4;
      }
      *piVar7 = iVar5;
      piVar1 = piVar7 + 8;
      piVar7 = piVar7 + 0xf;
    } while (piVar1 <= param_2);
  }
  return;
}



undefined4 __cdecl FUN_0042b040(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (uint *)0x0) {
    return 6;
  }
  uVar1 = FUN_00410b80(*param_1,param_1[3]);
  uVar2 = FUN_00410b80(param_1[1],param_1[2]);
  uVar1 = uVar1 - uVar2;
  if (uVar1 == 0) {
    return 6;
  }
  uVar2 = FUN_00410c00(param_1[1],uVar1);
  param_1[1] = -uVar2;
  uVar3 = FUN_00410c00(param_1[2],uVar1);
  uVar2 = *param_1;
  param_1[2] = -uVar3;
  uVar3 = FUN_00410c00(param_1[3],uVar1);
  *param_1 = uVar3;
  uVar1 = FUN_00410c00(uVar2,uVar1);
  param_1[3] = uVar1;
  return 0;
}



void __cdecl FUN_0042b130(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  
  iVar1 = param_2[2];
  piVar4 = param_2;
  piVar7 = param_3;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar7 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar7 = piVar7 + 1;
  }
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  uVar5 = *param_2 * iVar1;
  iVar1 = FUN_00410c90(param_1,uVar5,param_3 + 3);
  if (iVar1 == 0) {
    puVar6 = (undefined4 *)param_2[3];
    puVar8 = (undefined4 *)param_3[3];
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
  }
  return;
}



void __cdecl FUN_0042b660(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (*(uint *)(param_1 + 0x10) < uVar4) {
    uVar4 = *(uint *)(param_1 + 0x10);
  }
  if (uVar4 != 0) {
    puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x10);
    puVar6 = *(undefined4 **)(param_1 + 0xc);
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar4;
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x10);
    *piVar1 = *piVar1 + uVar4;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar4;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar4;
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x14);
    *piVar1 = *piVar1 - uVar4;
    iVar2 = *(int *)(param_1 + 0x1c);
    if (*(int *)(iVar2 + 0x14) == 0) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
    }
  }
  return;
}



void __cdecl FUN_0042b810(int *param_1)

{
  ushort *puVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  uVar2 = param_1[9];
  do {
    uVar4 = param_1[0x19];
    uVar6 = (param_1[0xd] - uVar4) - param_1[0x1b];
    if (uVar6 == 0) {
      if ((uVar4 != 0) || (uVar7 = uVar2, param_1[0x1b] != 0)) {
LAB_0042b84d:
        uVar7 = uVar6;
        if (param_1[9] + -0x106 + uVar2 <= uVar4) {
          puVar8 = (undefined4 *)(param_1[0xc] + uVar2);
          puVar10 = (undefined4 *)param_1[0xc];
          for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          param_1[0x19] = param_1[0x19] - uVar2;
          param_1[0x1a] = param_1[0x1a] - uVar2;
          iVar9 = param_1[0x11];
          param_1[0x15] = param_1[0x15] - uVar2;
          psVar5 = (short *)(param_1[0xf] + iVar9 * 2);
          do {
            puVar1 = (ushort *)(psVar5 + -1);
            psVar5 = psVar5 + -1;
            if (*puVar1 < uVar2) {
              sVar3 = 0;
            }
            else {
              sVar3 = *puVar1 - (short)uVar2;
            }
            iVar9 = iVar9 + -1;
            *psVar5 = sVar3;
          } while (iVar9 != 0);
          psVar5 = (short *)(param_1[0xe] + uVar2 * 2);
          uVar4 = uVar2;
          do {
            puVar1 = (ushort *)(psVar5 + -1);
            psVar5 = psVar5 + -1;
            if (*puVar1 < uVar2) {
              sVar3 = 0;
            }
            else {
              sVar3 = *puVar1 - (short)uVar2;
            }
            uVar4 = uVar4 - 1;
            *psVar5 = sVar3;
          } while (uVar4 != 0);
          uVar7 = uVar6 + uVar2;
        }
      }
    }
    else {
      if (uVar6 != 0xffffffff) goto LAB_0042b84d;
      uVar7 = 0xfffffffe;
    }
    if (((int *)*param_1)[1] == 0) {
      return;
    }
    uVar4 = FUN_0042b940((int *)*param_1,
                         (undefined4 *)(param_1[0x1b] + param_1[0x19] + param_1[0xc]),uVar7);
    uVar4 = param_1[0x1b] + uVar4;
    param_1[0x1b] = uVar4;
    if (2 < uVar4) {
      uVar6 = (uint)*(byte *)(param_1[0x19] + param_1[0xc]);
      param_1[0x10] = uVar6;
      param_1[0x10] =
           (uVar6 << ((byte)param_1[0x14] & 0x1f) ^
           (uint)((byte *)(param_1[0x19] + param_1[0xc]))[1]) & param_1[0x13];
    }
    if (0x105 < uVar4) {
      return;
    }
    if (*(int *)(*param_1 + 4) == 0) {
      return;
    }
  } while( true );
}



uint __cdecl FUN_0042b940(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = param_1[1];
  uVar2 = uVar1;
  if (param_3 < uVar1) {
    uVar2 = param_3;
  }
  if (uVar2 == 0) {
    return 0;
  }
  param_1[1] = uVar1 - uVar2;
  if (*(int *)(param_1[7] + 0x18) == 0) {
    uVar1 = FUN_0042c230(param_1[0xc],(byte *)*param_1,uVar2);
    param_1[0xc] = uVar1;
  }
  puVar3 = (undefined4 *)*param_1;
  for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *puVar3;
    puVar3 = puVar3 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar1 = uVar2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  param_1[2] = param_1[2] + uVar2;
  *param_1 = *param_1 + uVar2;
  return uVar2;
}



char * __cdecl FUN_0042bcd0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char local_11;
  uint local_10;
  char *local_c;
  uint local_8;
  
  iVar4 = param_1;
  local_10 = *(uint *)(param_1 + 0x74);
  uVar3 = *(uint *)(param_1 + 100);
  pcVar10 = *(char **)(param_1 + 0x70);
  puVar1 = (undefined4 *)(param_1 + 0x88);
  pcVar6 = (char *)(*(int *)(param_1 + 0x30) + uVar3);
  if (*(int *)(param_1 + 0x24) - 0x106U < uVar3) {
    local_8 = (uVar3 - *(int *)(param_1 + 0x24)) + 0x106;
  }
  else {
    local_8 = 0;
  }
  param_1 = (int)(byte)(pcVar6 + -1)[(int)pcVar10];
  local_11 = pcVar6[(int)pcVar10];
  pcVar2 = pcVar6 + 0x102;
  if (*(char **)(iVar4 + 0x84) <= pcVar10) {
    local_10 = local_10 >> 2;
  }
  pcVar5 = *(char **)(iVar4 + 0x6c);
  local_c = (char *)*puVar1;
  if (pcVar5 < (char *)*puVar1) {
    local_c = pcVar5;
  }
  do {
    pcVar9 = (char *)(*(int *)(iVar4 + 0x30) + param_2);
    if ((((pcVar9[(int)pcVar10] == local_11) && ((pcVar9 + -1)[(int)pcVar10] == (char)param_1)) &&
        (*pcVar9 == *pcVar6)) && (pcVar9[1] == pcVar6[1])) {
      pcVar9 = pcVar9 + 2;
      pcVar7 = pcVar6 + 2;
      while (((((pcVar8 = pcVar7 + 1, pcVar7[1] == pcVar9[1] &&
                (pcVar8 = pcVar7 + 2, pcVar7[2] == pcVar9[2])) &&
               ((pcVar8 = pcVar7 + 3, pcVar7[3] == pcVar9[3] &&
                ((pcVar8 = pcVar7 + 4, pcVar7[4] == pcVar9[4] &&
                 (pcVar8 = pcVar7 + 5, pcVar7[5] == pcVar9[5])))))) &&
              (pcVar8 = pcVar7 + 6, pcVar7[6] == pcVar9[6])) &&
             (pcVar8 = pcVar7 + 7, pcVar7[7] == pcVar9[7]))) {
        pcVar8 = pcVar7 + 8;
        pcVar9 = pcVar9 + 8;
        if ((pcVar7[8] != *pcVar9) || (pcVar7 = pcVar8, pcVar2 <= pcVar8)) break;
      }
      pcVar9 = pcVar8 + (0x102 - (int)pcVar2);
      if ((int)pcVar10 < (int)pcVar9) {
        *(uint *)(iVar4 + 0x68) = param_2;
        if ((int)local_c <= (int)pcVar9) {
LAB_0042be26:
          if (pcVar9 <= pcVar5) {
            pcVar5 = pcVar9;
          }
          return pcVar5;
        }
        local_11 = pcVar9[(int)pcVar6];
        param_1 = (int)(byte)pcVar6[(int)(pcVar8 + (0x101 - (int)pcVar2))];
        pcVar10 = pcVar9;
      }
    }
    pcVar9 = pcVar10;
    param_2 = (uint)*(ushort *)(*(int *)(iVar4 + 0x38) + (*(uint *)(iVar4 + 0x2c) & param_2) * 2);
    if ((param_2 <= local_8) || (local_10 = local_10 - 1, pcVar10 = pcVar9, local_10 == 0))
    goto LAB_0042be26;
  } while( true );
}



byte __cdecl FUN_0042be40(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  ushort uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  
  uVar12 = 0;
LAB_0042be50:
  do {
    uVar11 = param_1[0x1b];
    if (uVar11 < 0x106) {
      FUN_0042b810(param_1);
      uVar11 = param_1[0x1b];
      if ((uVar11 < 0x106) && (param_2 == 0)) {
        return 0;
      }
      if (uVar11 == 0) {
        if (param_1[0x18] != 0) {
          bVar10 = *(byte *)(param_1[0x19] + -1 + param_1[0xc]);
          *(undefined2 *)(param_1[0x5a7] + param_1[0x5a6] * 2) = 0;
          *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar10;
          param_1[0x5a6] = param_1[0x5a6] + 1;
          *(short *)(param_1 + bVar10 + 0x23) = (short)param_1[bVar10 + 0x23] + 1;
          param_1[0x18] = 0;
        }
        iVar9 = param_1[0x15];
        if (iVar9 < 0) {
          puVar8 = (undefined1 *)0x0;
        }
        else {
          puVar8 = (undefined1 *)(param_1[0xc] + iVar9);
        }
        FUN_0042c460(param_1,puVar8,param_1[0x19] - iVar9,(uint)(param_2 == 4));
        param_1[0x15] = param_1[0x19];
        FUN_0042b660(*param_1);
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + 1;
        }
        return (param_2 != 4) - 1U & 2;
      }
    }
    if (2 < uVar11) {
      uVar12 = (param_1[0x10] << ((byte)param_1[0x14] & 0x1f) ^
               (uint)*(byte *)(param_1[0xc] + 2 + param_1[0x19])) & param_1[0x13];
      param_1[0x10] = uVar12;
      uVar6 = *(ushort *)(param_1[0xf] + uVar12 * 2);
      uVar12 = (uint)uVar6;
      *(ushort *)(param_1[0xe] + (param_1[0xb] & param_1[0x19]) * 2) = uVar6;
      *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
    }
    uVar11 = param_1[0x16];
    param_1[0x1c] = uVar11;
    param_1[0x17] = param_1[0x1a];
    param_1[0x16] = 2;
    if (((uVar12 != 0) && (uVar11 < (uint)param_1[0x1e])) &&
       (param_1[0x19] - uVar12 <= param_1[9] - 0x106U)) {
      if (param_1[0x20] != 2) {
        pcVar7 = FUN_0042bcd0((int)param_1,uVar12);
        param_1[0x16] = (int)pcVar7;
      }
      if (((uint)param_1[0x16] < 6) &&
         ((param_1[0x20] == 1 ||
          ((param_1[0x16] == 3 && (0x1000 < (uint)(param_1[0x19] - param_1[0x1a]))))))) {
        param_1[0x16] = 2;
      }
    }
    if (((uint)param_1[0x1c] < 3) || ((uint)param_1[0x1c] < (uint)param_1[0x16])) {
      if (param_1[0x18] == 0) {
        param_1[0x18] = 1;
        param_1[0x19] = param_1[0x19] + 1;
        param_1[0x1b] = param_1[0x1b] + -1;
        goto LAB_0042be50;
      }
      bVar10 = *(byte *)(param_1[0x19] + -1 + param_1[0xc]);
      *(undefined2 *)(param_1[0x5a7] + param_1[0x5a6] * 2) = 0;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar10;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      *(short *)(param_1 + bVar10 + 0x23) = (short)param_1[bVar10 + 0x23] + 1;
      if (param_1[0x5a6] == param_1[0x5a5] + -1) {
        iVar9 = param_1[0x15];
        if (iVar9 < 0) {
          puVar8 = (undefined1 *)0x0;
        }
        else {
          puVar8 = (undefined1 *)(param_1[0xc] + iVar9);
        }
        FUN_0042c460(param_1,puVar8,param_1[0x19] - iVar9,0);
        param_1[0x15] = param_1[0x19];
        FUN_0042b660(*param_1);
      }
      param_1[0x19] = param_1[0x19] + 1;
      param_1[0x1b] = param_1[0x1b] + -1;
      iVar9 = *(int *)(*param_1 + 0x10);
    }
    else {
      iVar9 = param_1[0x19];
      iVar2 = param_1[0x1b];
      sVar5 = (short)iVar9 - (short)param_1[0x17];
      bVar10 = (char)param_1[0x1c] - 3;
      *(short *)(param_1[0x5a7] + param_1[0x5a6] * 2) = sVar5 + -1;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar10;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      uVar6 = sVar5 - 2;
      *(short *)(param_1 + (byte)(&DAT_00435de0)[bVar10] + 0x124) =
           (short)param_1[(byte)(&DAT_00435de0)[bVar10] + 0x124] + 1;
      if (uVar6 < 0x100) {
        bVar10 = (&DAT_00435be0)[uVar6];
      }
      else {
        bVar10 = (&DAT_00435ce0)[uVar6 >> 7];
      }
      *(short *)(param_1 + bVar10 + 0x260) = (short)param_1[bVar10 + 0x260] + 1;
      iVar3 = param_1[0x5a5];
      iVar4 = param_1[0x5a6];
      param_1[0x1b] = param_1[0x1b] + (1 - param_1[0x1c]);
      param_1[0x1c] = param_1[0x1c] + -2;
      do {
        uVar11 = param_1[0x19] + 1;
        param_1[0x19] = uVar11;
        if (uVar11 <= (uint)(iVar9 + -3 + iVar2)) {
          uVar12 = (param_1[0x10] << ((byte)param_1[0x14] & 0x1f) ^
                   (uint)*(byte *)(param_1[0xc] + 2 + uVar11)) & param_1[0x13];
          param_1[0x10] = uVar12;
          uVar6 = *(ushort *)(param_1[0xf] + uVar12 * 2);
          uVar12 = (uint)uVar6;
          *(ushort *)(param_1[0xe] + (param_1[0xb] & uVar11) * 2) = uVar6;
          *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
        }
        piVar1 = param_1 + 0x1c;
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      iVar9 = param_1[0x19];
      param_1[0x18] = 0;
      param_1[0x16] = 2;
      param_1[0x19] = iVar9 + 1;
      if (iVar4 != iVar3 + -1) goto LAB_0042be50;
      iVar2 = param_1[0x15];
      if (iVar2 < 0) {
        puVar8 = (undefined1 *)0x0;
      }
      else {
        puVar8 = (undefined1 *)(param_1[0xc] + iVar2);
      }
      FUN_0042c460(param_1,puVar8,(iVar9 + 1) - iVar2,0);
      param_1[0x15] = param_1[0x19];
      FUN_0042b660(*param_1);
      iVar9 = *(int *)(*param_1 + 0x10);
    }
    if (iVar9 == 0) {
      return 0;
    }
  } while( true );
}



uint __cdecl FUN_0042c230(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  
  uVar2 = param_1 & 0xffff;
  uVar19 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  while (param_3 != 0) {
    uVar1 = param_3;
    if (0x15af < param_3) {
      uVar1 = 0x15b0;
    }
    param_3 = param_3 - uVar1;
    if (0xf < (int)uVar1) {
      uVar18 = uVar1 >> 4;
      uVar1 = uVar1 + uVar18 * -0x10;
      do {
        iVar3 = uVar2 + *param_2;
        iVar4 = iVar3 + (uint)param_2[1];
        iVar5 = iVar4 + (uint)param_2[2];
        iVar6 = iVar5 + (uint)param_2[3];
        iVar7 = iVar6 + (uint)param_2[4];
        iVar8 = iVar7 + (uint)param_2[5];
        iVar9 = iVar8 + (uint)param_2[6];
        iVar10 = iVar9 + (uint)param_2[7];
        iVar11 = iVar10 + (uint)param_2[8];
        iVar12 = iVar11 + (uint)param_2[9];
        iVar13 = iVar12 + (uint)param_2[10];
        iVar14 = iVar13 + (uint)param_2[0xb];
        iVar15 = iVar14 + (uint)param_2[0xc];
        iVar16 = iVar15 + (uint)param_2[0xd];
        iVar17 = iVar16 + (uint)param_2[0xe];
        uVar2 = iVar17 + (uint)param_2[0xf];
        uVar19 = uVar19 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
                 iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + uVar2;
        param_2 = param_2 + 0x10;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uVar2 = uVar2 + *param_2;
      param_2 = param_2 + 1;
      uVar19 = uVar19 + uVar2;
    }
    uVar2 = uVar2 % 0xfff1;
    uVar19 = uVar19 % 0xfff1;
  }
  return uVar19 << 0x10 | uVar2;
}



void __cdecl FUN_0042c350(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)(param_1 + 0x8c);
  iVar2 = 0x11e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(param_1 + 0x980);
  iVar2 = 0x1e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(param_1 + 0xa74);
  iVar2 = 0x13;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x16a4) = 0;
  *(undefined4 *)(param_1 + 0x16a0) = 0;
  *(undefined4 *)(param_1 + 0x16a8) = 0;
  *(undefined4 *)(param_1 + 0x1698) = 0;
  *(undefined2 *)(param_1 + 0x48c) = 1;
  return;
}



void FUN_0042c3c0(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x16b4);
  if (0xd < iVar1) {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)param_4 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xd;
    FUN_0042d9b0(param_1,param_2,param_3,1);
    return;
  }
  *(ushort *)(param_1 + 0x16b0) =
       *(ushort *)(param_1 + 0x16b0) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
  *(int *)(param_1 + 0x16b4) = iVar1 + 3;
  FUN_0042d9b0(param_1,param_2,param_3,1);
  return;
}



void __cdecl FUN_0042c460(int *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = 0;
  if (param_1[0x1f] < 1) {
    uVar5 = param_3 + 5;
  }
  else {
    if ((char)param_1[7] == '\x02') {
      FUN_0042d890((int)param_1);
    }
    FUN_0042c650(param_1,param_1 + 0x2c4);
    FUN_0042c650(param_1,param_1 + 0x2c7);
    iVar3 = FUN_0042cbd0(param_1);
    uVar6 = param_1[0x5a8] + 10U >> 3;
    uVar5 = param_1[0x5a9] + 10U >> 3;
    if (uVar6 < uVar5) goto LAB_0042c4ca;
  }
  uVar6 = uVar5;
LAB_0042c4ca:
  if ((uVar6 < param_3 + 4U) || (param_2 == (undefined1 *)0x0)) {
    iVar2 = param_1[0x5ad];
    bVar4 = (byte)iVar2;
    if (uVar5 == uVar6) {
      iVar3 = param_4 + 2;
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x5ac) =
             *(ushort *)(param_1 + 0x5ac) | (ushort)(iVar3 << (bVar4 & 0x1f));
        param_1[0x5ad] = iVar2 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x5ac) =
             *(ushort *)(param_1 + 0x5ac) | (ushort)(iVar3 << (bVar4 & 0x1f));
        *(char *)(param_1[2] + param_1[5]) = (char)param_1[0x5ac];
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1;
        *(undefined1 *)(iVar2 + 1 + param_1[2]) = *(undefined1 *)((int)param_1 + 0x16b1);
        iVar2 = param_1[0x5ad];
        param_1[5] = param_1[5] + 1;
        param_1[0x5ad] = iVar2 + -0xd;
        *(ushort *)(param_1 + 0x5ac) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
      }
      FUN_0042d470((int)param_1,0x4356e8,0x435b68);
    }
    else {
      iVar1 = param_4 + 4;
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x5ac) =
             *(ushort *)(param_1 + 0x5ac) | (ushort)(iVar1 << (bVar4 & 0x1f));
        param_1[0x5ad] = iVar2 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x5ac) =
             *(ushort *)(param_1 + 0x5ac) | (ushort)(iVar1 << (bVar4 & 0x1f));
        *(char *)(param_1[2] + param_1[5]) = (char)param_1[0x5ac];
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1;
        *(undefined1 *)(iVar2 + 1 + param_1[2]) = *(undefined1 *)((int)param_1 + 0x16b1);
        param_1[5] = param_1[5] + 1;
        *(ushort *)(param_1 + 0x5ac) = (ushort)iVar1 >> (0x10U - (char)param_1[0x5ad] & 0x1f);
        param_1[0x5ad] = param_1[0x5ad] + -0xd;
      }
      FUN_0042cd20((int)param_1,param_1[0x2c5] + 1,param_1[0x2c8] + 1,iVar3 + 1);
      FUN_0042d470((int)param_1,(int)(param_1 + 0x23),(int)(param_1 + 0x260));
    }
  }
  else {
    FUN_0042c3c0((int)param_1,param_2,param_3,param_4);
  }
  FUN_0042c350((int)param_1);
  if (param_4 != 0) {
    FUN_0042d930((int)param_1);
  }
  return;
}



void __cdecl FUN_0042c650(int *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  iVar2 = *param_2;
  iVar5 = ((int *)param_2[2])[3];
  iVar7 = *(int *)param_2[2];
  iVar3 = 0;
  local_8 = -1;
  param_1[0x512] = 0;
  param_1[0x513] = 0x23d;
  if (0 < iVar5) {
    do {
      if (*(short *)(iVar2 + iVar3 * 4) == 0) {
        *(undefined2 *)(iVar2 + 2 + iVar3 * 4) = 0;
      }
      else {
        iVar6 = param_1[0x512];
        param_1[0x512] = iVar6 + 1;
        param_1[iVar6 + 0x2d6] = iVar3;
        *(undefined1 *)(iVar3 + 0x1450 + (int)param_1) = 0;
        local_8 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
  }
  iVar3 = param_1[0x512];
  while (iVar3 < 2) {
    if (local_8 < 2) {
      iVar6 = local_8 + 1;
      local_8 = iVar6;
    }
    else {
      iVar6 = 0;
    }
    param_1[0x512] = iVar3 + 1;
    param_1[iVar3 + 0x2d6] = iVar6;
    *(undefined2 *)(iVar2 + iVar6 * 4) = 1;
    *(undefined1 *)((int)param_1 + iVar6 + 0x1450) = 0;
    param_1[0x5a8] = param_1[0x5a8] + -1;
    if (iVar7 != 0) {
      param_1[0x5a9] = param_1[0x5a9] - (uint)*(ushort *)(iVar7 + 2 + iVar6 * 4);
    }
    iVar3 = param_1[0x512];
  }
  param_2[1] = local_8;
  for (iVar7 = param_1[0x512] / 2; 0 < iVar7; iVar7 = iVar7 + -1) {
    FUN_0042c860((int)param_1,iVar2,iVar7);
  }
  do {
    iVar7 = param_1[0x2d6];
    param_1[0x2d6] = param_1[param_1[0x512] + 0x2d5];
    param_1[0x512] = param_1[0x512] + -1;
    FUN_0042c860((int)param_1,iVar2,1);
    iVar3 = param_1[0x513];
    iVar6 = param_1[0x2d6];
    param_1[0x513] = iVar3 + -1;
    param_1[iVar3 + 0x2d4] = iVar7;
    iVar3 = param_1[0x513];
    param_1[0x513] = iVar3 + -1;
    param_1[iVar3 + 0x2d4] = iVar6;
    *(short *)(iVar2 + iVar5 * 4) = *(short *)(iVar2 + iVar6 * 4) + *(short *)(iVar2 + iVar7 * 4);
    bVar1 = *(byte *)((int)param_1 + iVar7 + 0x1450);
    bVar4 = *(byte *)((int)param_1 + iVar6 + 0x1450);
    if (bVar4 <= bVar1) {
      bVar4 = bVar1;
    }
    *(byte *)((int)param_1 + iVar5 + 0x1450) = bVar4 + 1;
    *(short *)(iVar2 + 2 + iVar6 * 4) = (short)iVar5;
    *(short *)(iVar2 + 2 + iVar7 * 4) = (short)iVar5;
    param_1[0x2d6] = iVar5;
    iVar5 = iVar5 + 1;
    FUN_0042c860((int)param_1,iVar2,1);
  } while (1 < param_1[0x512]);
  iVar5 = param_1[0x513];
  param_1[0x513] = iVar5 + -1;
  param_1[iVar5 + 0x2d4] = param_1[0x2d6];
  FUN_0042c930(param_1,param_2);
  FUN_0042cb50(iVar2,local_8,(int)(param_1 + 0x2cd));
  return;
}



void __cdecl FUN_0042c860(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar6 = *(int *)(param_1 + 0x1448);
  iVar3 = *(int *)(param_1 + 0xb54 + param_3 * 4);
  iVar7 = param_3 * 2;
  bVar8 = SBORROW4(iVar7,iVar6);
  iVar5 = iVar7 - iVar6;
  if (iVar6 < iVar7) {
    *(int *)(param_1 + 0xb54 + param_3 * 4) = iVar3;
    return;
  }
  do {
    iVar6 = iVar7;
    if (bVar8 != iVar5 < 0) {
      iVar5 = *(int *)(param_1 + 0xb58 + iVar7 * 4);
      iVar4 = *(int *)(param_1 + 0xb54 + iVar7 * 4);
      uVar1 = *(ushort *)(param_2 + iVar5 * 4);
      uVar2 = *(ushort *)(param_2 + iVar4 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(iVar5 + 0x1450 + param_1) <= *(byte *)(param_1 + 0x1450 + iVar4))))) {
        iVar6 = iVar7 + 1;
      }
    }
    iVar5 = *(int *)(param_1 + 0xb54 + iVar6 * 4);
    uVar1 = *(ushort *)(param_2 + iVar3 * 4);
    uVar2 = *(ushort *)(param_2 + iVar5 * 4);
    if (uVar1 < uVar2) break;
    if ((uVar1 == uVar2) &&
       (*(byte *)(param_1 + 0x1450 + iVar3) <= *(byte *)(iVar5 + 0x1450 + param_1))) {
      *(int *)(param_1 + 0xb54 + param_3 * 4) = iVar3;
      return;
    }
    *(int *)(param_1 + 0xb54 + param_3 * 4) = iVar5;
    iVar4 = *(int *)(param_1 + 0x1448);
    iVar7 = iVar6 * 2;
    bVar8 = SBORROW4(iVar7,iVar4);
    iVar5 = iVar7 - iVar4;
    param_3 = iVar6;
  } while (iVar5 == 0 || iVar7 < iVar4);
  *(int *)(param_1 + 0xb54 + param_3 * 4) = iVar3;
  return;
}



void __cdecl FUN_0042c930(int *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  ushort *puVar15;
  uint uVar16;
  int local_14;
  int local_10;
  
  piVar6 = param_1;
  iVar2 = param_2[1];
  iVar3 = *param_2;
  piVar14 = (int *)param_2[2];
  iVar4 = piVar14[1];
  iVar8 = piVar14[2];
  iVar5 = *piVar14;
  uVar11 = piVar14[4];
  piVar14 = param_1 + 0x2cd;
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
  }
  *(undefined2 *)(iVar3 + 2 + param_1[param_1[0x513] + 0x2d5] * 4) = 0;
  local_14 = param_1[0x513] + 1;
  param_2 = (int *)0x0;
  if (local_14 < 0x23d) {
    param_1 = param_1 + param_1[0x513] + 0x2d6;
    local_10 = 0x23d - local_14;
    local_14 = local_14 + local_10;
    do {
      iVar9 = *param_1;
      uVar7 = *(ushort *)(iVar3 + 2 + (uint)*(ushort *)(iVar3 + 2 + iVar9 * 4) * 4) + 1;
      if ((int)uVar11 < (int)uVar7) {
        param_2 = (int *)((int)param_2 + 1);
        uVar7 = uVar11;
      }
      *(short *)(iVar3 + 2 + iVar9 * 4) = (short)uVar7;
      if (iVar9 <= iVar2) {
        psVar10 = (short *)((int)piVar6 + uVar7 * 2 + 0xb34);
        *psVar10 = *psVar10 + 1;
        iVar13 = 0;
        if (iVar8 <= iVar9) {
          iVar13 = *(int *)(iVar4 + (iVar9 - iVar8) * 4);
        }
        uVar16 = (uint)*(ushort *)(iVar3 + iVar9 * 4);
        piVar6[0x5a8] = piVar6[0x5a8] + (uVar7 + iVar13) * uVar16;
        if (iVar5 != 0) {
          piVar6[0x5a9] =
               piVar6[0x5a9] + ((uint)*(ushort *)(iVar5 + 2 + iVar9 * 4) + iVar13) * uVar16;
        }
      }
      param_1 = param_1 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    if (param_2 != (int *)0x0) {
      iVar4 = uVar11 - 1;
      puVar15 = (ushort *)((int)piVar6 + uVar11 * 2 + 0xb34);
      do {
        psVar10 = (short *)((int)piVar6 + iVar4 * 2 + 0xb34);
        sVar1 = *(short *)((int)piVar6 + iVar4 * 2 + 0xb34);
        iVar8 = iVar4;
        while (sVar1 == 0) {
          psVar10 = psVar10 + -1;
          iVar8 = iVar8 + -1;
          sVar1 = *psVar10;
        }
        psVar10 = (short *)((int)piVar6 + iVar8 * 2 + 0xb34);
        *psVar10 = *psVar10 + -1;
        psVar10 = (short *)((int)piVar6 + iVar8 * 2 + 0xb36);
        *psVar10 = *psVar10 + 2;
        *puVar15 = *puVar15 - 1;
        param_2 = (int *)((int)param_2 + -2);
      } while (0 < (int)param_2);
      for (; uVar11 != 0; uVar11 = uVar11 - 1) {
        piVar14 = (int *)(uint)*puVar15;
        if (piVar14 != (int *)0x0) {
          piVar12 = piVar6 + local_14 + 0x2d5;
          param_2 = piVar14;
          do {
            iVar4 = piVar12[-1];
            local_14 = local_14 + -1;
            piVar12 = piVar12 + -1;
            if (iVar4 <= iVar2) {
              uVar7 = (uint)*(ushort *)(iVar3 + 2 + iVar4 * 4);
              if (uVar7 != uVar11) {
                piVar6[0x5a8] =
                     piVar6[0x5a8] + (uVar11 - uVar7) * (uint)*(ushort *)(iVar3 + iVar4 * 4);
                *(short *)(iVar3 + 2 + iVar4 * 4) = (short)uVar11;
              }
              piVar14 = (int *)((int)param_2 - 1);
              param_2 = piVar14;
            }
          } while (piVar14 != (int *)0x0);
        }
        puVar15 = puVar15 + -1;
      }
    }
  }
  return;
}



void __cdecl FUN_0042cb50(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort auStack_20 [16];
  
  uVar3 = 0;
  iVar1 = 1;
  do {
    uVar3 = (*(short *)(param_3 + iVar1 * 2 + -2) + uVar3) * 2;
    auStack_20[iVar1] = uVar3;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  iVar1 = 0;
  if (-1 < param_2) {
    do {
      uVar2 = (uint)*(ushort *)(param_1 + 2 + iVar1 * 4);
      if (uVar2 != 0) {
        uVar3 = auStack_20[uVar2];
        auStack_20[uVar2] = uVar3 + 1;
        uVar2 = FUN_0042d900((uint)uVar3,uVar2);
        *(short *)(param_1 + iVar1 * 4) = (short)uVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= param_2);
  }
  return;
}



void __cdecl FUN_0042cbd0(int *param_1)

{
  int iVar1;
  
  FUN_0042cc40((int)param_1,(ushort *)(param_1 + 0x23),param_1[0x2c5]);
  FUN_0042cc40((int)param_1,(ushort *)(param_1 + 0x260),param_1[0x2c8]);
  FUN_0042c650(param_1,param_1 + 0x2ca);
  iVar1 = 0x12;
  do {
    if (*(short *)((int)param_1 + (uint)(byte)(&DAT_004356d4)[iVar1] * 4 + 0xa76) != 0) break;
    iVar1 = iVar1 + -1;
  } while (2 < iVar1);
  param_1[0x5a8] = param_1[0x5a8] + iVar1 * 3 + 0x11;
  return;
}



void __cdecl FUN_0042cc40(int param_1,ushort *param_2,int param_3)

{
  short *psVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = param_2[1];
  uVar5 = 0xffffffff;
  iVar6 = 0;
  iVar3 = 7;
  iVar4 = 4;
  if (uVar2 == 0) {
    iVar3 = 0x8a;
    iVar4 = 3;
  }
  param_2[param_3 * 2 + 3] = 0xffff;
  if (-1 < param_3) {
    param_2 = param_2 + 3;
    param_3 = param_3 + 1;
    uVar7 = (uint)uVar2;
    do {
      uVar8 = (uint)*param_2;
      iVar6 = iVar6 + 1;
      if ((iVar3 <= iVar6) || (uVar7 != uVar8)) {
        if (iVar6 < iVar4) {
          psVar1 = (short *)(param_1 + 0xa74 + uVar7 * 4);
          *psVar1 = *psVar1 + (short)iVar6;
        }
        else if (uVar7 == 0) {
          if (iVar6 < 0xb) {
            *(short *)(param_1 + 0xab8) = *(short *)(param_1 + 0xab8) + 1;
          }
          else {
            *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
          }
        }
        else {
          if (uVar7 != uVar5) {
            psVar1 = (short *)(param_1 + 0xa74 + uVar7 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xab4) = *(short *)(param_1 + 0xab4) + 1;
        }
        iVar6 = 0;
        uVar5 = uVar7;
        if (uVar8 == 0) {
          iVar3 = 0x8a;
          iVar4 = 3;
        }
        else if (uVar7 == uVar8) {
          iVar3 = 6;
          iVar4 = 3;
        }
        else {
          iVar3 = 7;
          iVar4 = 4;
        }
      }
      param_2 = param_2 + 2;
      param_3 = param_3 + -1;
      uVar7 = uVar8;
    } while (param_3 != 0);
  }
  return;
}



void __cdecl FUN_0042cd20(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x16b4);
  iVar2 = param_2 + -0x101;
  if (iVar3 < 0xc) {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16b4) = iVar3 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)iVar2 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xb;
  }
  iVar3 = *(int *)(param_1 + 0x16b4);
  if (iVar3 < 0xc) {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(param_3 + -1 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16b4) = iVar3 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(param_3 + -1 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)(param_3 + -1) >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xb;
  }
  iVar2 = *(int *)(param_1 + 0x16b4);
  iVar3 = param_4 + -4;
  if (iVar2 < 0xd) {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16b4) = iVar2 + 4;
  }
  else {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    iVar2 = *(int *)(param_1 + 0x16b4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16b4) = iVar2 + -0xc;
    *(ushort *)(param_1 + 0x16b0) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar2 = *(int *)(param_1 + 0x16b4);
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) |
             *(short *)(param_1 + 0xa76 + (uint)(byte)(&DAT_004356d4)[iVar3] * 4) <<
             ((byte)iVar2 & 0x1f);
        *(int *)(param_1 + 0x16b4) = iVar2 + 3;
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0xa76 + (uint)(byte)(&DAT_004356d4)[iVar3] * 4);
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16b0);
        iVar2 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar2;
        *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
        iVar2 = *(int *)(param_1 + 0x16b4);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x16b4) = iVar2 + -0xd;
        *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - (char)iVar2 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  FUN_0042cf70(param_1,param_1 + 0x8c,(ushort *)(param_2 + -1));
  FUN_0042cf70(param_1,param_1 + 0x980,(ushort *)(param_3 + -1));
  return;
}



void __cdecl FUN_0042cf70(int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_4;
  
  uVar6 = 0xffffffff;
  iVar4 = 7;
  iVar5 = 4;
  if (*(ushort *)(param_2 + 2) == 0) {
    iVar4 = 0x8a;
    iVar5 = 3;
  }
  if (-1 < (int)param_3) {
    local_4 = (int)param_3 + 1;
    uVar7 = (uint)*(ushort *)(param_2 + 2);
    iVar9 = 0;
    param_3 = (ushort *)(param_2 + 6);
    do {
      uVar10 = (uint)*param_3;
      iVar8 = iVar9 + 1;
      if ((iVar4 <= iVar8) || (uVar7 != uVar10)) {
        if (iVar8 < iVar5) {
          do {
            uVar6 = (uint)*(ushort *)(param_1 + 0xa76 + uVar7 * 4);
            iVar4 = *(int *)(param_1 + 0x16b4);
            if ((int)(0x10 - uVar6) < iVar4) {
              uVar1 = *(ushort *)(param_1 + 0xa74 + uVar7 * 4);
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | uVar1 << ((byte)iVar4 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b0);
              iVar4 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar4;
              *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              iVar4 = *(int *)(param_1 + 0x16b4) + -0x10;
              *(ushort *)(param_1 + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) |
                   *(short *)(param_1 + 0xa74 + uVar7 * 4) << ((byte)iVar4 & 0x1f);
            }
            iVar8 = iVar8 + -1;
            *(uint *)(param_1 + 0x16b4) = iVar4 + uVar6;
          } while (iVar8 != 0);
        }
        else if (uVar7 == 0) {
          iVar4 = *(int *)(param_1 + 0x16b4);
          bVar3 = (byte)iVar4;
          if (iVar8 < 0xb) {
            uVar1 = *(ushort *)(param_1 + 0xaba);
            if ((int)(0x10 - (uint)uVar1) < iVar4) {
              uVar2 = *(ushort *)(param_1 + 0xab8);
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | uVar2 << (bVar3 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b0);
              iVar4 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar4;
              *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              iVar4 = *(int *)(param_1 + 0x16b4) + -0x10;
              *(ushort *)(param_1 + 0x16b0) =
                   uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | *(short *)(param_1 + 0xab8) << (bVar3 & 0x1f);
            }
            iVar4 = iVar4 + (uint)uVar1;
            iVar9 = iVar9 + -2;
            *(int *)(param_1 + 0x16b4) = iVar4;
            if (iVar4 < 0xe) {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar4 & 0x1f));
              iVar4 = iVar4 + 3;
LAB_0042d414:
              *(int *)(param_1 + 0x16b4) = iVar4;
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar4 & 0x1f));
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b0);
              iVar4 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar4;
              *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
              iVar4 = *(int *)(param_1 + 0x16b4);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x16b4) = iVar4 + -0xd;
              *(ushort *)(param_1 + 0x16b0) = (ushort)iVar9 >> (0x10U - (char)iVar4 & 0x1f);
            }
          }
          else {
            uVar1 = *(ushort *)(param_1 + 0xabe);
            if ((int)(0x10 - (uint)uVar1) < iVar4) {
              uVar2 = *(ushort *)(param_1 + 0xabc);
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | uVar2 << (bVar3 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b0);
              iVar4 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar4;
              *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              iVar4 = *(int *)(param_1 + 0x16b4) + -0x10;
              *(ushort *)(param_1 + 0x16b0) =
                   uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | *(short *)(param_1 + 0xabc) << (bVar3 & 0x1f);
            }
            iVar4 = iVar4 + (uint)uVar1;
            iVar9 = iVar9 + -10;
            *(int *)(param_1 + 0x16b4) = iVar4;
            if (iVar4 < 10) {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar4 & 0x1f));
              iVar4 = iVar4 + 7;
              goto LAB_0042d414;
            }
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar4 & 0x1f));
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b0);
            iVar4 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar4;
            *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            iVar4 = *(int *)(param_1 + 0x16b4);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x16b4) = iVar4 + -9;
            *(ushort *)(param_1 + 0x16b0) = (ushort)iVar9 >> (0x10U - (char)iVar4 & 0x1f);
          }
        }
        else {
          if (uVar7 != uVar6) {
            uVar6 = (uint)*(ushort *)(param_1 + 0xa76 + uVar7 * 4);
            iVar4 = *(int *)(param_1 + 0x16b4);
            if ((int)(0x10 - uVar6) < iVar4) {
              uVar1 = *(ushort *)(param_1 + 0xa74 + uVar7 * 4);
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) | uVar1 << ((byte)iVar4 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b0);
              iVar4 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar4;
              *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              iVar4 = *(int *)(param_1 + 0x16b4) + -0x10;
              *(ushort *)(param_1 + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(ushort *)(param_1 + 0x16b0) |
                   *(short *)(param_1 + 0xa74 + uVar7 * 4) << ((byte)iVar4 & 0x1f);
            }
            *(uint *)(param_1 + 0x16b4) = iVar4 + uVar6;
            iVar8 = iVar9;
          }
          uVar1 = *(ushort *)(param_1 + 0xab6);
          iVar4 = *(int *)(param_1 + 0x16b4);
          if ((int)(0x10 - (uint)uVar1) < iVar4) {
            uVar2 = *(ushort *)(param_1 + 0xab4);
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | uVar2 << ((byte)iVar4 & 0x1f);
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b0);
            iVar4 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar4;
            *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            iVar4 = *(int *)(param_1 + 0x16b4) + -0x10;
            *(ushort *)(param_1 + 0x16b0) =
                 uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | *(short *)(param_1 + 0xab4) << ((byte)iVar4 & 0x1f)
            ;
          }
          iVar4 = iVar4 + (uint)uVar1;
          iVar8 = iVar8 + -3;
          *(int *)(param_1 + 0x16b4) = iVar4;
          if (iVar4 < 0xf) {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar8 << ((byte)iVar4 & 0x1f));
            iVar4 = iVar4 + 2;
            goto LAB_0042d414;
          }
          *(ushort *)(param_1 + 0x16b0) =
               *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar8 << ((byte)iVar4 & 0x1f));
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b0);
          iVar4 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar4;
          *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          iVar4 = *(int *)(param_1 + 0x16b4);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x16b4) = iVar4 + -0xe;
          *(ushort *)(param_1 + 0x16b0) = (ushort)iVar8 >> (0x10U - (char)iVar4 & 0x1f);
        }
        iVar8 = 0;
        uVar6 = uVar7;
        if (uVar10 == 0) {
          iVar4 = 0x8a;
          iVar5 = 3;
        }
        else if (uVar7 == uVar10) {
          iVar4 = 6;
          iVar5 = 3;
        }
        else {
          iVar4 = 7;
          iVar5 = 4;
        }
      }
      param_3 = param_3 + 2;
      local_4 = local_4 + -1;
      uVar7 = uVar10;
      iVar9 = iVar8;
    } while (local_4 != 0);
  }
  return;
}



void __cdecl FUN_0042d470(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x1698) != 0) {
    do {
      uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x169c) + uVar3 * 2);
      uVar8 = (uint)*(byte *)(uVar3 + *(int *)(param_1 + 0x1690));
      uVar3 = uVar3 + 1;
      iVar4 = *(int *)(param_1 + 0x16b4);
      bVar2 = (byte)iVar4;
      if (uVar7 == 0) {
        uVar7 = (uint)*(ushort *)(param_2 + 2 + uVar8 * 4);
        if ((int)(0x10 - uVar7) < iVar4) {
          uVar1 = *(ushort *)(param_2 + uVar8 * 4);
          *(ushort *)(param_1 + 0x16b0) = *(ushort *)(param_1 + 0x16b0) | uVar1 << (bVar2 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b0);
          iVar4 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar4;
          *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          iVar4 = *(int *)(param_1 + 0x16b4) + -0x10 + uVar7;
          *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f)
          ;
        }
        else {
          *(ushort *)(param_1 + 0x16b0) =
               *(ushort *)(param_1 + 0x16b0) | *(short *)(param_2 + uVar8 * 4) << (bVar2 & 0x1f);
          iVar4 = iVar4 + uVar7;
        }
LAB_0042d7bb:
        *(int *)(param_1 + 0x16b4) = iVar4;
      }
      else {
        uVar5 = (uint)(byte)(&DAT_00435de0)[uVar8];
        uVar10 = (uint)*(ushort *)(param_2 + 0x406 + uVar5 * 4);
        if ((int)(0x10 - uVar10) < iVar4) {
          uVar1 = *(ushort *)(param_2 + 0x404 + uVar5 * 4);
          *(ushort *)(param_1 + 0x16b0) = *(ushort *)(param_1 + 0x16b0) | uVar1 << (bVar2 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b0);
          iVar4 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar4;
          *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          iVar4 = *(int *)(param_1 + 0x16b4);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(uint *)(param_1 + 0x16b4) = iVar4 + -0x10 + uVar10;
          *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - (char)iVar4 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x16b0) =
               *(ushort *)(param_1 + 0x16b0) |
               *(short *)(param_2 + 0x404 + uVar5 * 4) << (bVar2 & 0x1f);
          *(uint *)(param_1 + 0x16b4) = iVar4 + uVar10;
        }
        iVar4 = *(int *)(&DAT_00435598 + uVar5 * 4);
        if (iVar4 != 0) {
          iVar9 = uVar8 - *(int *)(&DAT_00435ee0 + uVar5 * 4);
          iVar6 = *(int *)(param_1 + 0x16b4);
          if (0x10 - iVar4 < iVar6) {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar6 & 0x1f));
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b0);
            iVar6 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar6;
            *(undefined1 *)(iVar6 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            iVar6 = *(int *)(param_1 + 0x16b4) + -0x10;
            *(ushort *)(param_1 + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar6 & 0x1f));
          }
          *(int *)(param_1 + 0x16b4) = iVar6 + iVar4;
        }
        uVar8 = uVar7 - 1;
        if (uVar8 < 0x100) {
          bVar2 = (&DAT_00435bdf)[uVar7];
        }
        else {
          bVar2 = (&DAT_00435ce0)[uVar8 >> 7];
        }
        uVar5 = (uint)bVar2;
        uVar7 = (uint)*(ushort *)(param_3 + 2 + uVar5 * 4);
        iVar4 = *(int *)(param_1 + 0x16b4);
        if ((int)(0x10 - uVar7) < iVar4) {
          uVar1 = *(ushort *)(param_3 + uVar5 * 4);
          *(ushort *)(param_1 + 0x16b0) =
               *(ushort *)(param_1 + 0x16b0) | uVar1 << ((byte)iVar4 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b0);
          iVar4 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar4;
          *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          iVar4 = *(int *)(param_1 + 0x16b4);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(uint *)(param_1 + 0x16b4) = iVar4 + -0x10 + uVar7;
          *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - (char)iVar4 & 0x1f);
        }
        else {
          *(ushort *)(param_1 + 0x16b0) =
               *(ushort *)(param_1 + 0x16b0) |
               *(short *)(param_3 + uVar5 * 4) << ((byte)iVar4 & 0x1f);
          *(uint *)(param_1 + 0x16b4) = iVar4 + uVar7;
        }
        iVar4 = *(int *)(&DAT_00435610 + uVar5 * 4);
        if (iVar4 != 0) {
          iVar9 = uVar8 - *(int *)(&DAT_00435f58 + uVar5 * 4);
          iVar6 = *(int *)(param_1 + 0x16b4);
          if (0x10 - iVar4 < iVar6) {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar6 & 0x1f));
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b0);
            iVar6 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar6;
            *(undefined1 *)(iVar6 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            iVar4 = *(int *)(param_1 + 0x16b4) + -0x10 + iVar4;
            *(ushort *)(param_1 + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(param_1 + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(param_1 + 0x16b0) =
                 *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar9 << ((byte)iVar6 & 0x1f));
            iVar4 = iVar6 + iVar4;
          }
          goto LAB_0042d7bb;
        }
      }
    } while (uVar3 < *(uint *)(param_1 + 0x1698));
  }
  uVar3 = (uint)*(ushort *)(param_2 + 0x402);
  iVar4 = *(int *)(param_1 + 0x16b4);
  if ((int)(0x10 - uVar3) < iVar4) {
    uVar1 = *(ushort *)(param_2 + 0x400);
    *(ushort *)(param_1 + 0x16b0) = *(ushort *)(param_1 + 0x16b0) | uVar1 << ((byte)iVar4 & 0x1f);
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar4 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar4;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b1);
    iVar4 = *(int *)(param_1 + 0x16b4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(uint *)(param_1 + 0x16b4) = iVar4 + -0x10 + uVar3;
    *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - (char)iVar4 & 0x1f);
    *(uint *)(param_1 + 0x16ac) = (uint)*(ushort *)(param_2 + 0x402);
    return;
  }
  *(ushort *)(param_1 + 0x16b0) =
       *(ushort *)(param_1 + 0x16b0) | *(short *)(param_2 + 0x400) << ((byte)iVar4 & 0x1f);
  *(uint *)(param_1 + 0x16b4) = iVar4 + uVar3;
  *(uint *)(param_1 + 0x16ac) = (uint)*(ushort *)(param_2 + 0x402);
  return;
}



void __cdecl FUN_0042d890(int param_1)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  puVar1 = (ushort *)(param_1 + 0x8c);
  iVar2 = 7;
  do {
    uVar3 = uVar3 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (ushort *)(param_1 + 0xa8);
  iVar2 = 0x79;
  do {
    uVar4 = uVar4 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (ushort *)(param_1 + 0x28c);
  iVar2 = 0x80;
  do {
    uVar3 = uVar3 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(char *)(param_1 + 0x1c) = '\x01' - (uVar4 >> 2 < uVar3);
  return;
}



uint __cdecl FUN_0042d900(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    uVar3 = param_1 & 1;
    param_1 = param_1 >> 1;
    param_2 = param_2 + -1;
    uVar1 = (uVar2 | uVar3) << 1;
  } while (0 < param_2);
  return uVar2 & 0x7fffffff | uVar3;
}



void __cdecl FUN_0042d930(int param_1)

{
  int iVar1;
  
  if (8 < *(int *)(param_1 + 0x16b4)) {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined2 *)(param_1 + 0x16b0) = 0;
    *(undefined4 *)(param_1 + 0x16b4) = 0;
    return;
  }
  if (0 < *(int *)(param_1 + 0x16b4)) {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(undefined2 *)(param_1 + 0x16b0) = 0;
  *(undefined4 *)(param_1 + 0x16b4) = 0;
  return;
}



void __cdecl FUN_0042d9b0(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  
  FUN_0042d930(param_1);
  *(undefined4 *)(param_1 + 0x16ac) = 8;
  if (param_4 != 0) {
    *(byte *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (byte)param_3;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    bVar1 = (byte)((uint)param_3 >> 8);
    *(byte *)(iVar2 + *(int *)(param_1 + 8)) = bVar1;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(param_1 + 8)) = ~(byte)param_3;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(param_1 + 8)) = ~bVar1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = *param_2;
    param_2 = param_2 + 1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  return;
}



void __cdecl FUN_0042da40(void *param_1)

{
  free(param_1);
  return;
}



basic_ostream<> * __cdecl std::operator<<(basic_ostream<> *param_1,basic_string<> *param_2)

{
  basic_ostream<> *pbVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042da4c. Too many branches
                    // WARNING: Treating indirect jump as call
  pbVar1 = operator<<(param_1,param_2);
  return pbVar1;
}



void __cdecl std::operator+(basic_string<> *param_1,char *param_2)

{
                    // WARNING: Could not recover jumptable at 0x0042da9a. Too many branches
                    // WARNING: Treating indirect jump as call
  operator+(param_1,param_2);
  return;
}



void __cdecl std::operator+(char *param_1,basic_string<> *param_2)

{
                    // WARNING: Could not recover jumptable at 0x0042daa0. Too many branches
                    // WARNING: Treating indirect jump as call
  operator+(param_1,param_2);
  return;
}



void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042daa6. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



void FUN_0042dac0(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004361f0;
  puStack_10 = &DAT_0042de10;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_0042db28();
  ExceptionList = local_14;
  return;
}



void FUN_0042db28(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    FUN_0042db40(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + 0x10),*(undefined **)(unaff_EBP + 0x14));
  }
  return;
}



void FUN_0042db40(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00436200;
  puStack_10 = &DAT_0042de10;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  ExceptionList = local_14;
  return;
}



undefined4 __cdecl FUN_0042db9e(undefined4 *param_1)

{
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  terminate();
}



type_info * __thiscall FUN_0042dbb4(void *this,byte param_1)

{
  type_info::~type_info(this);
  if ((param_1 & 1) != 0) {
    FUN_0042da40(this);
  }
  return this;
}



void __cdecl ftol(void)

{
                    // WARNING: Could not recover jumptable at 0x0042dbd6. Too many branches
                    // WARNING: Treating indirect jump as call
  ftol();
  return;
}



void _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    // WARNING: Could not recover jumptable at 0x0042dbdc. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}



void __cdecl FUN_0042dbe2(_onexit_t param_1)

{
  if (DAT_004550d0 == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_004550d0,&DAT_004550cc);
  return;
}



int __cdecl FUN_0042dc0e(_onexit_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_0042dbe2(param_1);
  return (iVar1 != 0) - 1;
}



void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042dc20. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void entry(void)

{
  undefined4 *puVar1;
  char **local_30;
  _startupinfo local_2c;
  int local_28;
  char **local_24;
  int local_20;
  undefined1 *local_1c;
  void *pvStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00436218;
  puStack_10 = &DAT_0042de10;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffffc0;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  __set_app_type(1);
  _DAT_004550cc = 0xffffffff;
  DAT_004550d0 = 0xffffffff;
  puVar1 = (undefined4 *)__p__fmode();
  *puVar1 = DAT_00454eb0;
  puVar1 = (undefined4 *)__p__commode();
  *puVar1 = DAT_00454eac;
  _DAT_004550c8 = *(undefined4 *)_adjust_fdiv_exref;
  FUN_0042de49();
  if (DAT_004431b0 == 0) {
    __setusermatherr(&LAB_0042de46);
  }
  FUN_0042de34();
  initterm(&DAT_004399a8,&DAT_004399ac);
  local_2c.newmode = DAT_00454ea8;
  __getmainargs(&local_20,&local_30,&local_24,DAT_00454ea4,&local_2c);
  initterm(&DAT_00439000,&DAT_004399a4);
  puVar1 = (undefined4 *)__p___initenv();
  *puVar1 = local_24;
  local_28 = FUN_00401450(local_20,(int)local_30);
                    // WARNING: Subroutine does not return
  exit(local_28);
}



// WARNING: Unable to track spacebase fully for stack

void FUN_0042dd40(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



void __RTDynamicCast(void)

{
                    // WARNING: Could not recover jumptable at 0x0042dd70. Too many branches
                    // WARNING: Treating indirect jump as call
  __RTDynamicCast();
  return;
}



char * __cdecl strncpy(char *_Dest,char *_Source,size_t _Count)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042dd76. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strncpy(_Dest,_Source,_Count);
  return pcVar1;
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x0042dd7c. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



void __cdecl
qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
                    // WARNING: Could not recover jumptable at 0x0042dd82. Too many branches
                    // WARNING: Treating indirect jump as call
  qsort(_Base,_NumOfElements,_SizeOfElements,_PtFuncCompare);
  return;
}



int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042ddf2. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = strncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



int __cdecl _isctype(int _C,int _Type)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042ddf8. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _isctype(_C,_Type);
  return iVar1;
}



void __cdecl longjmp(int *_Buf,int _Value)

{
                    // WARNING: Could not recover jumptable at 0x0042ddfe. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  longjmp(_Buf,_Value);
  return;
}



void __cdecl setjmp3(void)

{
                    // WARNING: Could not recover jumptable at 0x0042de04. Too many branches
                    // WARNING: Treating indirect jump as call
  setjmp3();
  return;
}



void __cdecl terminate(void)

{
                    // WARNING: Could not recover jumptable at 0x0042de16. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  terminate();
  return;
}



void __thiscall type_info::~type_info(type_info *this)

{
                    // WARNING: Could not recover jumptable at 0x0042de1c. Too many branches
                    // WARNING: Treating indirect jump as call
  ~type_info(this);
  return;
}



void __dllonexit(void)

{
                    // WARNING: Could not recover jumptable at 0x0042de22. Too many branches
                    // WARNING: Treating indirect jump as call
  __dllonexit();
  return;
}



int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042de28. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



void __cdecl initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x0042de2e. Too many branches
                    // WARNING: Treating indirect jump as call
  initterm();
  return;
}



void FUN_0042de34(void)

{
  _controlfp(0x10000,0x30000);
  return;
}



void FUN_0042de49(void)

{
  return;
}



uint __cdecl _controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
                    // WARNING: Could not recover jumptable at 0x0042de4a. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = _controlfp(_NewValue,_Mask);
  return uVar1;
}



void Unwind_0042eef0(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042ef10(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x120));
  return;
}



void Unwind_0042ef1e(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x120));
  return;
}



void Unwind_0042ef2c(void)

{
  int unaff_EBP;
  
  FUN_00409c50((undefined4 *)(unaff_EBP + -0x11c));
  return;
}



void Unwind_0042ef50(void)

{
  int unaff_EBP;
  
  FUN_00402100((undefined4 *)(unaff_EBP + -0x50));
  return;
}



void Unwind_0042ef58(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(unaff_EBP + -0x4c);
  return;
}



void Unwind_0042ef60(void)

{
  int unaff_EBP;
  
  FUN_00402d50((undefined4 *)(unaff_EBP + -0x50));
  return;
}



void Unwind_0042ef68(void)

{
  int unaff_EBP;
  
  FUN_00403060((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



void Unwind_0042ef73(void)

{
  int unaff_EBP;
  
  FUN_00401110((int *)(unaff_EBP + -100));
  return;
}



void Unwind_0042ef7b(void)

{
  int unaff_EBP;
  
  FUN_00404b70(unaff_EBP + -0x518);
  return;
}



void Unwind_0042ef86(void)

{
  int unaff_EBP;
  
  FUN_00403b20(unaff_EBP + -0x318);
  return;
}



void Unwind_0042ef91(void)

{
  int unaff_EBP;
  
  FUN_00403060((undefined4 *)(unaff_EBP + -0x94));
  return;
}



void Unwind_0042ef9c(void)

{
  int unaff_EBP;
  
  FUN_00402d50((undefined4 *)(unaff_EBP + -0x90));
  return;
}



void Unwind_0042efa7(void)

{
  int unaff_EBP;
  
  if (unaff_EBP == 0x94) {
    uRamffffffcc = 0;
  }
  else {
    *(int *)(unaff_EBP + -200) = unaff_EBP + -0x90;
  }
  FUN_00402100(*(undefined4 **)(unaff_EBP + -200));
  return;
}



void Unwind_0042efde(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(unaff_EBP + -0x8c);
  return;
}



void Unwind_0042efec(void)

{
  int unaff_EBP;
  
  FUN_00404610(unaff_EBP + -0x7c);
  return;
}



void Unwind_0042effa(void)

{
  int unaff_EBP;
  
  FUN_00402fc0(unaff_EBP + -0x1c8);
  return;
}



void Unwind_0042f005(void)

{
  int unaff_EBP;
  
  FUN_00402fc0(unaff_EBP + -0x1a4);
  return;
}



void Unwind_0042f010(void)

{
  int unaff_EBP;
  
  FUN_00402fc0(unaff_EBP + -0x210);
  return;
}



void Unwind_0042f01b(void)

{
  int unaff_EBP;
  
  FUN_00402fc0(unaff_EBP + -0x1ec);
  return;
}



void Unwind_0042f026(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0xd8);
  return;
}



void Unwind_0042f031(void)

{
  int unaff_EBP;
  
  if (unaff_EBP == 0x54) {
    uRamfffff5e4 = 0;
  }
  else {
    *(int *)(unaff_EBP + -0xa70) = unaff_EBP + -0x50;
  }
  FUN_00402100(*(undefined4 **)(unaff_EBP + -0xa70));
  return;
}



void Unwind_0042f062(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(unaff_EBP + -0x4c);
  return;
}



void Unwind_0042f06d(void)

{
  int unaff_EBP;
  
  FUN_00404610(unaff_EBP + -0x3c);
  return;
}



void Unwind_0042f090(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f096. Too many branches
                    // WARNING: Treating indirect jump as call
  std::strstream::~strstream((strstream *)(*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



void Unwind_0042f09c(void)

{
  int unaff_EBP;
  
  FUN_00402490(*(int *)(unaff_EBP + -0x10) + -0x44);
  return;
}



void Unwind_0042f0a7(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + -0x10) + -0x34);
  return;
}



void Unwind_0042f0b2(void)

{
  int unaff_EBP;
  
  FUN_00402af0((void *)(*(int *)(unaff_EBP + -0x10) + -0x24));
  return;
}



void Unwind_0042f0d0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f0d3. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f0d9(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x2c);
  return;
}



void Unwind_0042f0f0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  FUN_00402100(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



void Unwind_0042f118(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



void Unwind_0042f123(void)

{
  int unaff_EBP;
  
  FUN_00404610(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



void Unwind_0042f140(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f143. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f149(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x2c);
  return;
}



void Unwind_0042f151(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f154. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
  return;
}



void Unwind_0042f15a(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x1c);
  return;
}



void Unwind_0042f170(void)

{
  int unaff_EBP;
  
  FUN_00402100((undefined4 *)(*(int *)(unaff_EBP + -0x40) + 4));
  return;
}



void Unwind_0042f17b(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + -0x40) + 8);
  return;
}



void Unwind_0042f186(void)

{
  int unaff_EBP;
  
  FUN_00404610(*(int *)(unaff_EBP + -0x40) + 0x18);
  return;
}



void Unwind_0042f191(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f194. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f19a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x44) & 1) != 0) {
                    // WARNING: Could not recover jumptable at 0x0042f1ab. Too many branches
                    // WARNING: Treating indirect jump as call
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
    return;
  }
  return;
}



void Unwind_0042f1b2(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x44) & 2) != 0) {
                    // WARNING: Could not recover jumptable at 0x0042f1c3. Too many branches
                    // WARNING: Treating indirect jump as call
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



void Unwind_0042f1ca(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f1cd. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f1d3(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x2c);
  return;
}



void Unwind_0042f1f0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f1f6. Too many branches
                    // WARNING: Treating indirect jump as call
  std::strstream::~strstream((strstream *)(*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



void Unwind_0042f1fc(void)

{
  int unaff_EBP;
  
  FUN_00402490(*(int *)(unaff_EBP + -0x10) + -0x44);
  return;
}



void Unwind_0042f207(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + -0x10) + -0x34);
  return;
}



void Unwind_0042f212(void)

{
  int unaff_EBP;
  
  FUN_00402af0((void *)(*(int *)(unaff_EBP + -0x10) + -0x24));
  return;
}



void Unwind_0042f230(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f233. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f250(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
                    // WARNING: Could not recover jumptable at 0x0042f267. Too many branches
                    // WARNING: Treating indirect jump as call
    std::basic_ios<>::~basic_ios<>((basic_ios<> *)(*(int *)(unaff_EBP + 4) + 0xb0));
    return;
  }
  return;
}



void Unwind_0042f26e(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f274. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_iostream<>::~basic_iostream<>((basic_iostream<> *)(*(int *)(unaff_EBP + 4) + 0xc));
  return;
}



void Unwind_0042f27a(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f280. Too many branches
                    // WARNING: Treating indirect jump as call
  std::strstream::~strstream((strstream *)(*(int *)(unaff_EBP + 4) + 0x5c));
  return;
}



void Unwind_0042f286(void)

{
  int unaff_EBP;
  
  FUN_00402490(*(int *)(unaff_EBP + 4) + 100);
  return;
}



void Unwind_0042f291(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + 4) + 0x74);
  return;
}



void Unwind_0042f29c(void)

{
  int unaff_EBP;
  
  FUN_00402af0((void *)(*(int *)(unaff_EBP + 4) + 0x84));
  return;
}



void Unwind_0042f2c0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f2c3. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_streambuf<>::~basic_streambuf<>(*(basic_streambuf<> **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f2e0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f2e6. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(*(int *)(unaff_EBP + 4) + 0x10));
  return;
}



void Unwind_0042f2ec(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f2ef. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f300(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f303. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f309(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 8));
  return;
}



void Unwind_0042f314(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + 8));
  return;
}



void Unwind_0042f330(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f333. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + 4));
  return;
}



void Unwind_0042f339(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f33c. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f350(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f35b(void)

{
  int unaff_EBP;
  
  FUN_00404610(*(int *)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f370(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f373. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x38));
  return;
}



void Unwind_0042f390(void)

{
  FUN_00404950();
  return;
}



void Unwind_0042f3b0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f3b3. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f3b9(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x1c);
  return;
}



void Unwind_0042f3d0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f3d3. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f3d9(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x1c);
  return;
}



void Unwind_0042f3f0(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f3f3. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f3f9(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x3c);
  return;
}



void Unwind_0042f401(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f404. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
  return;
}



void Unwind_0042f40a(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x3c);
  return;
}



void Unwind_0042f420(void)

{
  FUN_00404950();
  return;
}



void Unwind_0042f440(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f446. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



void Unwind_0042f44c(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 0xc));
  return;
}



void Unwind_0042f457(void)

{
  int unaff_EBP;
  
  FUN_00401ca0(*(int *)(unaff_EBP + 0xc));
  return;
}



void Unwind_0042f45f(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 0xc));
  return;
}



void Unwind_0042f46a(void)

{
  int unaff_EBP;
  
  FUN_00404610(*(int *)(unaff_EBP + 0xc));
  return;
}



void Unwind_0042f480(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f486. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



void Unwind_0042f4a0(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x14));
  return;
}



void Unwind_0042f4ab(void)

{
  FUN_00404950();
  return;
}



void Unwind_0042f4bc(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f4e0(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 8));
  return;
}



void Unwind_0042f4eb(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 4));
  return;
}



void Unwind_0042f4f6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
                    // WARNING: Could not recover jumptable at 0x0042f507. Too many branches
                    // WARNING: Treating indirect jump as call
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



void Unwind_0042f50e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 2) != 0) {
                    // WARNING: Could not recover jumptable at 0x0042f51f. Too many branches
                    // WARNING: Treating indirect jump as call
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
    return;
  }
  return;
}



void Unwind_0042f530(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f533. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x4c));
  return;
}



void Unwind_0042f550(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f553. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f570(void)

{
  int unaff_EBP;
  
  FUN_004025b0(unaff_EBP + -0x20);
  return;
}



void Unwind_0042f590(void)

{
  int unaff_EBP;
  
                    // WARNING: Could not recover jumptable at 0x0042f593. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x3c));
  return;
}



void Unwind_0042f5b0(void)

{
  int unaff_EBP;
  
  FUN_00407d40(*(void **)(unaff_EBP + -0x20));
  return;
}



void Unwind_0042f5d0(void)

{
  int unaff_EBP;
  
  FUN_0040a770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f5f0(void)

{
  int unaff_EBP;
  
  FUN_0040a770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f610(void)

{
  int unaff_EBP;
  
  FUN_0040a770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f630(void)

{
  int unaff_EBP;
  
  FUN_0040b0f0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



void Unwind_0042f650(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f670(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + 4));
  return;
}



void Unwind_0042f690(void)

{
  int unaff_EBP;
  
  FUN_0040b8a0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



void Unwind_0042f6b0(void)

{
  int unaff_EBP;
  
  FUN_0040b8a0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f6d0(void)

{
  int unaff_EBP;
  
  FUN_0040ade0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f6f0(void)

{
  int unaff_EBP;
  
  FUN_0042da40(*(void **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f710(void)

{
  int unaff_EBP;
  
  FUN_0040b0f0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



void Unwind_0042f730(void)

{
  int unaff_EBP;
  
  FUN_0040b050(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f750(void)

{
  int unaff_EBP;
  
  FUN_0040b050(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



void Unwind_0042f770(void)

{
  int unaff_EBP;
  
  FUN_0040b8a0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


