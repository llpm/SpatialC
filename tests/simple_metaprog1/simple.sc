package simple;

struct Write {
    int addr;
    int value;
}

module Simple {
    input void rst;
    mod Memory!(N=64) memVar;

    input void resetAll;

    input Write write;
    input int read;
    output int read_val;   

    connect resetAll -> memVar.resetAll;
    connect write -> memVar.write;
    connect read -> memVar.read;
    connect memVar.read_val -> read_val;
}

module Memory (
    int N
) {
    mem int[N] arr;

    input void resetAll;

    input Write write;
    input int read;
    output int read_val;

    event(write -> msg) {
        arr[msg.addr] <- msg.value;
    }

    event(read -> msg) {
        read_val <- arr[msg];
    }

        event(resetAll -> msg) {
    static_for (I: 0 .. N) {
            arr[I] <- 0;
        }
    }
}
