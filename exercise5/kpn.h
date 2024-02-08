//
// Created by adam on 24.12.23.
//

#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    sc_fifo<unsigned int> a, b, c, d;
    void add();
    void delay();
    void split();

public:
    SC_CTOR(kpn): a(10), b(10), c(10), d(10)
    {
        b.write(1);
        c.write(0);
        SC_THREAD(split);
        SC_THREAD(add);
        SC_THREAD(delay);

    }
};

#endif
