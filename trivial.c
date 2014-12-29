#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "api.h"

// A simple wrapper function for comparing keys
static int keys_equal(key_t x, key_t y) {
    return x && y && strcmp(x, y) == 0;
}

#define CACHE_SIZE 128

cache_t cacheCreate(void) {
    return calloc(CACHE_SIZE, sizeof(cache_entry_t));
}

void cacheFree(cache_t cache) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        free(cache[i].key);
        free(cache[i].value);
    }
    free(cache);
}

void cacheInsert(cache_t cache, key_t key, payload_t payload) {
    int i = hash(key) % CACHE_SIZE; // Get position in cache
    free(cache[i].key);             // Evict anything already there
    free(cache[i].value);
    cache[i].key = key;             // Put new payload in place
    cache[i].value = payload;
}

payload_t cacheGet(cache_t cache, key_t key) {
    int i = hash(key) % CACHE_SIZE;
    if (cache[i].key && keys_equal(cache[i].key, key)) {
        return cache[i].value;  // We found the key! :-D
    } 
    return NULL;                // We didn't find the key. :-(
}
