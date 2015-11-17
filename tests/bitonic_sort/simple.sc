package simple;

module Switch {
    input int a;
    input int b;
    output int hi;
    output int lo;
    
    event (a -> a, b -> b) {
        if (a > b) {
            hi <- a;
            lo <- b;
        } else {
            hi <- b;
            lo <- a;
        }
    }
}

struct Write {
    int idx;
    int val;
}

module Simple {

    reg int<4> vec;

    input Write write;
    input void sort;
    output uint32 sortDone;
    
    input int read;
    output int val;

    event (write -> w) atomic {
        var tmp = vec;
        tmp[w.idx] = w.val;
        vec <- tmp;
    }

    event (read -> i) {
        val <- vec[i];
    }

    mod Switch a;
    mod Switch b;
    mod Switch c;
    mod Switch d;
    mod Switch e;

    connect a.hi -> c.a;
    connect a.lo -> d.a;
    connect b.hi -> c.b;
    connect b.lo -> d.b;

    connect d.hi -> e.a;
    connect c.lo -> e.b;

    event (sort -> sort) {
        a.a <- vec[0];
        a.b <- vec[1];
        b.a <- vec[2];
        b.b <- vec[3];
    }

    event(c.hi -> v0, e.hi -> v1,
          e.lo -> v2, d.lo -> v3) {
        vec <- [v0, v1, v2, v3];
        sortDone <- 1;
    }
}
