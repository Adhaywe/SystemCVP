
#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn) {
private:

    sc_fifo<unsigned int> a, b, c, d;
    unsigned int e;

    void add();
    void split();
    void delay();

public:

    //define the size of the fifo in the constructor
    SC_CTOR(kpn): a(10), b(10), c(10), d(10)
    {
        //initialize the value of b and c
        b.write(1);
        c.write(0);

        //define the threads for the processes
        SC_THREAD(add);
        SC_THREAD(split);
        SC_THREAD(delay);

        sensitive << a.data_read_event() << a.data_written_event()
                  << b.data_read_event() << b.data_written_event()
                  << c.data_read_event() << c.data_written_event()
                  << d.data_read_event() << d.data_written_event();
    }
};


#endif // KPN_H