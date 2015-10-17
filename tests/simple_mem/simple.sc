package simple;

module Simple {
    input int setReq;
    input void getReq;
    output int32 getResp;

    int value;

    event "set" (setReq -> msg) {
        value <- msg;
    }

    event "get" (getReq -> msg) {
        getResp <- value;
    }

}
