// Measure cache hit rate on text given to stdin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "api.h"

cache_t cache;
int hits, misses;

static void handleToken(char *token) {
    if (cacheGet(cache, token)) {
        hits++;
    } else {
        misses++;
    }
    cacheInsert(cache, strdup(token), strdup(token));
}

int main(void) {
    cache = cacheCreate();

    char c, buffer[1024], *buf = buffer;
    while ((c = getchar()) != EOF) {
        if (!isalnum(c)) {
            *buf = '\0';
            if (strlen(buffer)) handleToken(buffer);
            buf = buffer;
        } else {
            *buf++ = c;
            assert(buf - buffer < 1024);
        }
    }

    printf("Hits: %i, Misses: %i\n", hits, misses);
    printf("Hit rate: %0.3f%%\n", (double)hits / (hits + misses));

    cacheFree(cache);
    return 0;
}
