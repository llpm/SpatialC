package simple;

module Simple {

    // Constant 'k'. Loaded from software to reduce hardware size slightly.
    mem uint32[64] k;
    // The current state. Initialized from software to reduce hardware size slightly.
    reg uint32<8>  state;

    // Iteration variable for loading 'k'
    reg uint       iterK;

    // Iteration variable for loading/reading 'state'
    reg uint       iterState;

    // Load the next 'k'
    input uint32 loadK;
    // Load the next state word
    input uint32 loadState;
    // Ask the hardware to write out the state
    input void   readState;
    internal void readStateInt;
    // Output channel for the state
    output uint32 stateOut;
    
    // Update the state with this new data
    input uint32 update;
    // For knowing where in 'm' update data we are
    reg   uint   iterUpdate;
    // Signal the update is done -- signals once every 64 'update' inputs
    output void updateDone;

    // Temporaries
    reg uint32<8> tmp;
    
    init {
        iterK <- 0;
        iterState <- 0;
        iterUpdate <- 0;
    }

    event (loadK -> loadK) xact {
        var :uint i = iterK;
        k[i] <- loadK;
        iterK <- (i + 1) & 0x3F;
    }

    event (loadState -> loadState) xact {
        var :uint i = iterState;
        var :uint32<8> s = state;
        s[i] = loadState;
        state <- s;
        tmp <- s;
        iterState <- (i + 1) & 0x7;
    }

    event ((readState | readStateInt) -> _) xact {
        var :uint i = iterState;
        stateOut <- state[i];
        i = i + 1;
        if (i != 0) {
            readStateInt <- void;
        }
        iterState <- i & 0x7;
    }

    event (update -> update) {
        var :uint i = iterUpdate;


        var s = tmp;
        var a = s[0];
        var b = s[1];
        var c = s[2];
        var d = s[3];
        var e = s[4];
        var f = s[5];
        var g = s[6];
        var h = s[7];

        //               h +  EP1(e)                               + CH(e, f, g)            + k[i] + m[i]
        var :uint32 t1 = h + ((e >>> 6) ^ (e >>> 11) ^ (e >>> 25)) + ((e & f) ^ ((~e) & g)) + k[i] + update;
        //               EP0(a)                                + MAJ(a, b, c)
        var :uint32 t2 = ((a >>> 2) ^ (a >>> 13) ^ (a >>> 22)) + ( (a & b) ^ (a & c) ^ (b & c) );
        
        // Re-assignments
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;

        tmp <- [a, b, c, d, e, f, g, h];


        xact {
            i = (i + 1) & 0x3F;
            iterUpdate <- i;

            if (i == 0) {
                var st = state;
                a = st[0] + a;
                b = st[1] + b;
                c = st[2] + c;
                d = st[3] + d;
                e = st[4] + e;
                f = st[5] + f;
                g = st[6] + g;
                h = st[7] + h;
                state <- [a, b, c, d, e, f, g, h];

                updateDone <- void;
                tmp <- [a, b, c, d, e, f, g, h];
            }
        }
    }
}
