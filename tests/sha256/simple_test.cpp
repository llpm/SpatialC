#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>

#include "sha256.h"

static const size_t ITERS = 10;

static const uint32_t k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

static const uint32_t init[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    s->reset();
    s->run(5);
    printf("Finished reset\n");

    // This happens once, when hardware is loaded
    for (size_t i = 0; i < 64; i++) {
        s->loadK(k[i]);
    }


    // Load the initial state
    for (size_t i=0; i < 8; i++) {
        s->loadState(init[i]);
    }

    s->run(5);

    SHA256_CTX ctx;
    sha256_init(&ctx);

    for (size_t iters=0; iters < ITERS; iters++) {
        BYTE data[64];
        for (size_t i=0; i<64; i++) {
            data[i] = rand();
        }
        sha256_transform(&ctx, data);


        uint32_t m[64];

        uint64_t start = s->cycles();
        printf("Running update iteration %lu\n", iters);
        for (size_t i=0; i<64; i++) {
            if (i < 16) {
                size_t j = i * 4;
		m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
            } else {
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
            }
            s->update(m[i]);
        }
        Simple::updateDone_type done;
        s->updateDone(&done);
        uint64_t end = s->cycles();
        printf("Update cycles: %lu\n", (end - start));
    }


    printf("Reading final state...\n");
    s->readState();
    uint32_t state[8];
    for (size_t i=0; i<8; i++) {
        s->stateOut(&state[i]);
    }
    printf("Done reading final state.\n");

    for (size_t i = 0; i<8; i++) {
        const char* s = "";
        if (state[i] != ctx.state[i]) {
            s = "  <- WRONG";
        }
        printf("State %lu: %08x, %08x %s\n", i, state[i], ctx.state[i], s);
    }
    
    delete s;
    return 0;
}



