//
// Created by adam on 26.11.23.
//

#include <systemc.h>


#include "stim.h"
#include "exor.h"
#include "mon.h"



int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    sc_clock clk;

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);

    exor DUT("exor");
    DUT.a(sigA);
    DUT.b(sigB);
    DUT.f(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);


    sc_start();  // run forever

    return 0;
}