package simple;



module Partition {
    int upperBound;

    input  int din;
    output int next;
    output int part_data;

    input int cnfg;

    event (cnfg -> cfg) {
        upperBound <- cfg;
    }

    event (din -> d) {
        if (d <= upperBound) {
            part_data <- d;
        } else {
            next <- d;
        }
    }
}

struct DataOut {
    int partNum;
    int value;
}

struct Config {
    int partNum;
    int upperBound;
}

module Harp (
    int NumPart
) {
    Partition[NumPart] parts;

    input Config cnfg;
    input int din;
    output DataOut dout;

    event(cnfg -> cfg) {
        parts[cfg.partNum].cnfg <- cfg.upperBound;
    }

    static_for(N: 0 .. NumPart) {
        event(parts[N].part_data -> data) {
            dout <- DataOut {
                partNum: N,
                value: data
            };
        }
    }

    event(parts[NumPart-1].next -> data) {
        dout <- DataOut {
            partNum: NumPart,
            value: data
        };
    }

    connect din -> parts[0].din;
    static_for(N: 0 .. NumPart - 1) {
        connect parts[N].next -> parts[N+1].din;
    }
}

module Simple {
    input Config cnfg;
    input int din;
    output DataOut dout;

    Harp!(NumPart = 10) harp;

    connect cnfg -> harp.cnfg;
    connect din -> harp.din;
    connect harp.dout -> dout;
}
