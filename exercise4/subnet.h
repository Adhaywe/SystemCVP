//
// Created by adam on 09.12.23.
//

#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
SC_MODULE(subnet) {
    transition<1, 1> ACT; //1 input port 2 output ports
    transition<1, 1> RD;
    transition<1, 1> PRE;
    transition<1, 1> WR;

    place<1, 1> IDLE, ACTIVE;


    SC_CTOR(subnet) : IDLE(2), ACTIVE(0), ACT("ACT"), RD("RD"), PRE("PRE"),
                      WR("WR") //t1("t1"), t2("t2"), t3("t3"), p1(1),  p2(0), p3(0), p4(0)
    {
       // ACT.in.bind(IDLE);
        ACT.out.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);

        PRE.in.bind(ACTIVE);
       // PRE.out.bind(IDLE);

        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

    }
};

#endif // SUBNET_H