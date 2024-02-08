//
// Created by adam on 09.12.23.
//

#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
SC_MODULE(toplevel)
{
    subnet s1, s2;

    SC_CTOR(toplevel): s1("s1"),  s2("s2")
    {
        s1.ACT.in.bind(s1.IDLE);
        s1.PRE.out.bind(s1.IDLE);

        s2.ACT.in.bind(s2.IDLE);
        s2.PRE.out.bind(s2.IDLE);

    //transition<1, 2> t1; //1 input port 2 output ports
    //transition<2, 1> t2;
    //transition<1, 1> t3;
    //place<> p1, p2, p3, p4;

        //t1.in.bind(p1);
        //t1.out.bind(p3);
        //t1.out.bind(p2);

        //t3.in.bind(p3);
        //t3.out.bind(p4);

        //t2.in.bind(p4);
        //t2.in.bind(p2);
        //t2.out.bind(p1);


        SC_THREAD(process);
    }


    void process()
    {
        while (true)
        {
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }
};

int sc_main(int, char**)
{
    toplevel t("t");

    sc_start();
    return 0;
}