#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (uint32_t i=0; i<5; i++) {
        s->intIn(i);
        uint32_t j;
        s->intOut(&j);
        printf("in: %u, out: %u\n", i, j);
        assert( i == j );
    }

    delete s;
    return 0;
}
