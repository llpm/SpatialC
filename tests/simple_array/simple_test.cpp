#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<25; i++) {
        s->wreq(i, i*5);
    }

    for (int32_t i=0; i<25; i++) {
        s->rreq(i);
        uint32_t res;
        s->rresp(&res);
        printf("i: %d, res: %u\n", i, res);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
