//
// Created by adam on 26.11.23.
//

#include <systemc.h>
//#include <systemc-ams.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    sc_clock Clk;

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.Clk(Clk);

    exor DUT("exor");
    DUT.a(sigA);
    DUT.b(sigB);
    DUT.f(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.Clk(Clk);

    // Add tracing objects
    //sc_trace_file* tracefile = sc_create_vcd_trace_file("waveform");
    //tracefile->set_time_unit(1, SC_PS);  // Set time unit to picoseconds

    //sc_trace(tracefile, sigA, "sigA");
    //sc_trace(tracefile, sigB, "sigB");
    //sc_trace(tracefile, sigZ, "sigZ");


    sc_start();  // run forever


    // Close trace file
   // sc_close_vcd_trace_file(tracefile);


    return 0;
}