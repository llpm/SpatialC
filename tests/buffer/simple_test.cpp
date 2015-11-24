#include "Simple.hpp"
#include "obj/verilator_extra.h"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    start_debug(fopen("debug.txt", "w"));
    s->reset();
    s->run(5);

    unsigned NUM = 50;

    // srand(time(NULL));
    unsigned outCounter = 0;
    deque<int> q;

    uint64_t start = s->cycles();
    for (int32_t i=0; i<NUM; ) {
        Simple::dout_type dout;

        if (s->din_size() == 0) {
            Simple::din_type din;
            din.arg0 = rand() % 1000;
            s->din_nonblock(din);
            q.push_back(din.arg0);
            // printf("-> %u (%u)\n", din.arg0, i);
            i++;
        } else if ((rand() & 0x3F) == 0 &&
                   s->dout_nonblock(&dout)) {
            int correct = q.front();
            q.pop_front();
            if (dout.arg0 == correct)
                printf("%u: %d, %d\n", outCounter, dout.arg0, correct);
            else 
                printf("%u: %d, %d (ERROR)\n", outCounter, dout.arg0, correct);
            outCounter++;
        } else {
            if (s->flush_size() == 0)
                s->flush_nonblock({});
            s->run(1);
        }
        fflush(stdout);
    }

    // s->flush();
    printf("Switching to read only\n");
    while (outCounter < NUM) {
        Simple::dout_type dout;
        if(s->dout_nonblock(&dout)) {
            int correct = q.front();
            q.pop_front();
            if (dout.arg0 == correct)
                printf("%u: %d, %d (rdonly)\n", outCounter, dout.arg0, correct);
            else 
                printf("%u: %d, %d (rdonly, ERROR)\n", outCounter, dout.arg0, correct);
            outCounter++;
            fflush(stdout);
        } else if (s->flush_size() == 0) {
            s->flush_nonblock({});
        } else {
            s->run(1);
        }
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    close_debug();

    delete s;
    return 0;
}
