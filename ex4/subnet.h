//
// Created by adam on 01.01.24.
//

#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
SC_MODULE(subnet) {
    transition<1, 1> ACT;
    transition<1, 1> RD;
    transition<1, 1> PRE;
    transition<1, 1> WR;

    place<2, 2> IDLE; //number of inputs and outputs
    place<3, 3> ACTIVE;

    SC_CTOR(subnet): IDLE(2), ACTIVE(0), ACT("ACT"),
                     RD("RD"), PRE("PRE"), WR("WR")
    {
        ACT.out.bind(ACTIVE);
        //ACT.inhibitors.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);

        PRE.in.bind(ACTIVE);

        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

    }
};

#endif // SUBNET_H
