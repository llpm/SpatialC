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

    int<4> vec;

    input Write write;
    input void sort;
    output uint32 sortDone;
    
    input int read;
    output int val;

    event (write -> w) atomic {
        int<4> tmp = vec;
        tmp[w.idx] = w.val;
        vec <- tmp;
    }

    event (read -> i) {
        val <- vec[i];
    }

    Switch a;
    Switch b;
    Switch c;
    Switch d;
    Switch e;

    a.hi -> c.a;
    a.lo -> d.a;
    b.hi -> c.b;
    b.lo -> d.b;

    d.hi -> e.a;
    c.lo -> e.b;

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
