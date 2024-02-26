//
// Created by adam on 01.01.24.
//

#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
SC_MODULE(toplevel) {
//    transition<1, 2> t1;
//    transition<2, 1> t2;
//    transition<1, 1> t3;
//    place p1, p2, p3, p4;

   //part 1
//   transition t1, t2;
//   place p1, p2;

   //for templated channels - single memory bank
//    transition<1, 1> ACT, RD, WR, PRE;
//    place<1, 1>IDLE;
//    place<3,3>ACTIVE;


    //hierarchical PNS
    subnet s1, s2;



    SC_CTOR(toplevel): s1("s1"), s2("s2")
     //IDLE(1), ACTIVE(0), ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR")
    //p1(1), t1("t1"), p2(0), t2("t2"), p3(0), t3("t3"), p4(0)
    //p1(1), t1("t1"), p2(0), t2("t2")
    {
        //hierarchical pns

        s1.ACT.in.bind(s1.IDLE);
        s1.PRE.out.bind(s1.IDLE);

        s2.ACT.in.bind(s2.IDLE);
        s2.PRE.out.bind(s2.IDLE);


        //a single memory bank
        //ACT.in.bind(IDLE);
        //ACT.out.bind(ACTIVE);

        //RD.in.bind(ACTIVE);
        //RD.out.bind(ACTIVE);

        //PRE.in.bind(ACTIVE);
        //PRE.out.bind(IDLE);

        //WR.in.bind(ACTIVE);
        //WR.out.bind(ACTIVE);



        //part 2 binding - multiports
//        t1.in.bind(p1);
//        t1.out.bind(p3);
//        t1.out.bind(p2);
//
//        t3.in.bind(p3);
//        t3.out.bind(p4);
//
//        t2.in.bind(p4);
//        t2.in.bind(p2);
//        t2.out.bind(p1);




        //part1
//        t1.in.bind(p1);
//        t1.out.bind(p2);
//
//        t2.in.bind(p2);
//        t2.out.bind(p1);

        SC_THREAD(process);
    }

    void process() {
        while(true)
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