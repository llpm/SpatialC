#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();
    s->rst();

    for (int32_t i=0; i<5; i++) {
        s->intIn(i);
        int32_t j;
        int64_t k;
        bool c;
        s->intOut((uint32_t*)&j);
        s->incrOut((uint64_t*)&k);
        s->cmpOut(&c);
        printf("in: %u, out: %u, %ld, %u\n", i, j, k, c);
        if (i != j)
            printf(" ^^^ ERROR ^^^\n");
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
