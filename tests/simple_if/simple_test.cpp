#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<100; i++) {
        s->valueIn(i);
        uint32_t j;
        if (i > 50) {
            s->largeNum(&j);
        } else {
            s->smallNum(&j);
        }
        printf("in: %u, out: %u\n", i, j);
        assert( i == j );
    }
    s->reqCounter();
    uint32_t c;
    s->largeCount(&c);
    printf("Large count: %u\n", c);

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
