//
// Created by adam on 24.12.23.
//

#include <unistd.h>
#include <systemc.h>
#include <iostream>

#include "kpn.h"

void kpn::add() {
    while (true) {
        //wait(sc_time(20, SC_NS));
        b.write(a.read() + c.read());
    }

}

void kpn::delay() {
    while(true) {
        c.write(d.read());
    }
}

void kpn::split() {
    int i = 10;
    while (i) {
       wait(sc_time(20, SC_NS));
        unsigned int e = b.read();
        a.write(e);
        d.write(e);

        std::cout << "output: "<< e << std::endl;
        i--;
    }
//sc_stop();
}
