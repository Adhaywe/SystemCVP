#include <unistd.h>
#include <systemc.h>
#include <iostream>

#include "kpn.h"

// implement all the functions

void kpn::add() {
    while (true) {
        b.write(a.read() + c.read());
    }
}


void kpn::delay() {
    while (true) {
        c.write(d.read());
    }
}

void kpn::split() {
    int i = 10;

    while (i) {

        e = b.read();
        d.write(e);
        a.write(e);

        std::cout << "Output : " << e << std::endl;

        i--;
    }
}
