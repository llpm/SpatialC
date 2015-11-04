#include "Simple.hpp"
#include "obj/verilator_extra.h"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>

#define NUM 4

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();
    uint32_t tmp;

    start_debug(fopen("debug.txt", "w"));

    srand(time(NULL));

    for (int32_t i=0; i<NUM; i++) {
        unsigned val = rand() % 1000;
        printf("[%lu] %d: %u\n", s->cycles(), i, val);
        s->write(i, val);
        // s->run(5);
    }

    for (int32_t i=0; i<NUM; i++) {
        s->read(i);
        int32_t n;
        s->val((uint32_t*)&n);
        printf("%d\n", n);
    }

    printf("Sorting!\n");
    s->sort();
    s->sortDone(&tmp);

    int32_t last;
    for (int32_t i=0; i<NUM; i++) {
        s->read(i);
        int32_t n;
        s->val((uint32_t*)&n);
        if (i > 1 && n > last) {
            printf("%d  FAIL\n", n);
        } else {
            printf("%d\n", n);
        }
        last = n;
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    close_debug();

    delete s;
    return 0;
}
