package simple;

module Simple {
    input int valueIn;
    output int largeNum;
    output int smallNum;

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

    event (reqCounter -> msg) {
        largeCount <- counter;
    }
}
