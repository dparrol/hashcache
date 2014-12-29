// Let's hash strings.

#include <stdint.h>
#include <stdlib.h>

int siphash(uint8_t *out, const uint8_t *in, uint64_t inlen, const uint8_t *k);
void randomHashKey(void);
uint32_t __hash32(unsigned char *str);
uint64_t __hash64(unsigned char *str);
#define hash32(x) __hash32((unsigned char *)(x))
#define hash64(x) __hash64((unsigned char *)(x))
