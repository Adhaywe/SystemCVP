//
// Created by adam on 09.12.23.
//

#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
template<unsigned int N = 1, unsigned int M = 1, unsigned int L=0>
SC_MODULE(transition)
{
public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

    SC_CTOR(transition) {

    }

    void fire()
    {

        for (int i =0; i < N; ++i)
        {
            if (in[i]->testTokens() ) //&& !(inhibitors->testTokens())
            {
                in[i]->removeTokens();
                out[i]->addTokens();
                std::cout << this->name() << " Fired" << std::endl;
            }

            else
            {
                std::cout << this->name() << " NOT Fired" << std::endl;
            }
        }


    }

};

#endif // TRANSITION_H
