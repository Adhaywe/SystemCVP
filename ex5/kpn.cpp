#include <unistd.h>
#include <systemc.h>

#include "kpn.h"
#include <iostream>
#include <systemc.h>
#include <unistd.h>

//implement all the functions



void kpn::add() {
    while(true) {
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

        std::cout << "output: " << e << std::endl;
        i--;
    }
}

