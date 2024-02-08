#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    // define the fifo
    sc_fifo<unsigned int> a, b, c, d;
    //define the functions
    void add();
    void delay();
    void split();


public:
    SC_CTOR(kpn): a(10), b(10), c(10), d(10)
    //fifo depth of 10
    {
        //SC_THREADS for the processes
        b.write(1);
        c.write(0);
        SC_THREAD(add);
        SC_THREAD(split);
        SC_THREAD(delay);

        sensitive << a.data_read_event() << a.data_written_event()
                  << b.data_read_event() << b.data_written_event()
                  << c.data_read_event() << c.data_written_event()
                  << d.data_read_event() << d.data_written_event();
#
    }
};

#endif // KPN_H