#define CLONE_PARENT    0x0001
#define CLONE_FILES     0x0002
#define CLONE_VM        0x0004
#define CLONE_FS        0x0008
#define FLAG_CHECK(a, b)    ((a) & (b))