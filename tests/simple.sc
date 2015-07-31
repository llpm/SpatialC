package simple;

module Simple {
    int8 counter;

    input int sig;
    input int  sig2;
    output int8 countOut;
    output int sigRelay;

    event "relay" (sig -> sMsg) {
        sigRelay <- sMsg;
    }

    event "waiter" (sig -> sMsg, sig2 -> msg2) {
    }
}
