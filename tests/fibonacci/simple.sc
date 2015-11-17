package simple;

module Simple {
    input void goFib;
    internal void fibControl;
    reg uint64 fib1;
    reg uint64 fib2;
    output uint64 fibSeq;

    event "fibStart" (goFib -> msg) {
        xact {
            fib1 <- 0;
            fib2 <- 1;
        }
        fibControl <- msg;
    }

    event "fibber" (fibControl -> msg) {
        xact { 
            var next = fib1 + fib2;
            fibSeq <- next; 
            fib1 <- fib2;
            fib2 <- next;
        }
        fibControl <- msg;
    }
}
