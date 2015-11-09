package simple;

struct Write {
    int addr;
    int value;
}

module Simple {
    input void rst;
    Memory!(N=64) mem;

    input Write write;
    input int read;
    output int read_val;   

    write -> mem.write;
    read -> mem.read;
    mem.read_val -> read_val;
}

module Memory (
    int N
) {
    int[N] arr;

    input Write write;
    input int read;
    output int read_val;

    event(write -> msg) {
        arr[msg.addr] <- msg.value;
    }

    event(read -> msg) {
        read_val <- arr[msg];
    }
}
