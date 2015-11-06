#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<100; i++) {
        uint32_t a = rand() % 1000;
        s->v1(a);
        uint32_t ret;
        s->o(&ret);
        printf("%u + %u = %u\n", a, a, ret);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
