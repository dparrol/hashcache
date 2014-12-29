// Keys and values in the cache are both strings. You could use
// whatever you want, but let's keep it simple for now.
typedef char* key_t;
typedef char* payload_t;
// A cache is just an array of slots where we can put payloads.
typedef struct {
    key_t key; 
    payload_t value;
} cache_entry_t;
typedef cache_entry_t* cache_t;

// Here are the basic functions.
cache_t cacheCreate(void);
void cacheFree(cache_t cache);
void cacheInsert(cache_t cache, key_t key, payload_t payload);
payload_t cacheGet(cache_t cache, key_t key);
