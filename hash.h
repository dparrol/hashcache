// Let's hash strings.

#include <stdint.h>

static inline uint32_t djbhash(unsigned char *str) {
    uint32_t hash = 5381;
    for (int c; (c = *str++); ) hash = ((hash << 5) + hash) + c;
    return hash;
}

#define hash(x) djbhash((unsigned char *)(x))
