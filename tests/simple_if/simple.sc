package simple;

module Simple {
    input int valueIn;
    output int largeNum;
    output int smallNum;
    output int modified;

    input void reqCounter;
    output int largeCount;

    int counter;

    event "sieve" (valueIn -> msg) {
        if (msg > 50) {
            largeNum <- msg;
            counter <- msg;
        } else {
            smallNum <- msg;
        }
    }

    event "modify" (valueIn -> msg) {
        int sv = 0;
        if (msg > 25) {
            sv = 1;
        }
        modified <- sv;
    }

    event (reqCounter -> msg) {
        largeCount <- counter;
    }
}
