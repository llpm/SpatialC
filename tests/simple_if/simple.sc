package simple;

module Simple {
    input int valueIn;
    output int large;
    output int small;

    input void reqCounter;
    output int largeCount;

    int counter;

    event "sieve" (valueIn -> msg) {
        if (valueIn > 50 == 0) {
            large <- msg;
            counter <- counter + 1;
        } else {
            small <- msg;
        }
    }

    event (reqCounter -> msg) {
        largeCount <- counter;
    }
}
