package simple;

module Simple {
    input int count;
    output int nums;
    internal int countInt;

    event "counter" ((countInt | count) -> msg) {
        if (msg > 0) {
            nums <- msg;
            countInt <- msg - 1;
        }
    }
}
