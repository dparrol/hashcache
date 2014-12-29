# Trivial hash-table-based cache with vaguely LRU-ish eviction

In `trivial.c` you'll find code for a really simple cache, as explained in the blog post
[Trivial caching with a simplified hash table](https://dparrol.github.io/trivial-cache.html). In `hitrate.c` is some code to insert words from stdin, and report the hit rate. You can try it out on the text of *Alice in Wonderland* like this:

    $ make
    $ ./hitrate-trivial < wonderland.txt
    Hits: 13398, Misses: 17132
    Hit rate: 0.439%

