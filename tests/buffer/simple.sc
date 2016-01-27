package simple;


module Buffer (
    int Size,
    int Threshold=0,
    type Type
) {
    mem Type [Size] buffer;
    reg uint start;
    reg uint end;

    input Type din;
    output Type dout;
    input void flush;
    internal void intFlushStart;

    init {
        start <- 0;
        end <- 0;
    }

    event "din" (din -> data) atomic {
        wait_until ( (end != 0 && start != (end - 1)) ||
                     (end == 0 && start != (Size - 1)) );

        var start = start;
        var startNext = start + 1;
        if (startNext >= Size) {
            startNext = 0;
        }

        xact {
            buffer[start] <- data;
        }
        xact {
            start <- startNext;
        }

        var end = end;
        var trueStart = startNext;
        if (end > startNext) {
            trueStart = trueStart + Size;
        }

        if (trueStart - end >= Threshold) {
            intFlushStart <- void;
        }
    }

    reg uint1 flushing;
    internal void flushLoop;
    event "startFlush" ((flush | intFlushStart) -> *) atomic {
        if (flushing == 0) {
            xact { flushing <- 1; }
            flushLoop <- void;
        }
    }

    event "flush" (flushLoop -> *) atomic xact {
        var end = end;
        if (end != start) {
            dout <- buffer[end];
            var endVal = end + 1;
            if (endVal >= Size) {
                endVal = 0;
            }
            end <- endVal;
            flushLoop <- void;
        } else {
            flushing <- 0;
        }
    }
}

module Simple {
    input int din;
    input void flush;
    output int dout;

    mod Buffer!(Type=type int, Size=32, Threshold=12) buffer;

    connect din -> buffer.din;
    connect buffer.dout -> dout;
    connect flush -> buffer.flush;
}
