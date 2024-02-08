//
// Created by adam on 01.01.24.
//

#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
//for multiports section 4.2
template<unsigned int N = 1, unsigned int M = 1, unsigned int L=0>
SC_MODULE(transition){
  sc_port<placeInterface, N, SC_ALL_BOUND> in;
  sc_port<placeInterface, M, SC_ALL_BOUND > out;
  sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors; // for inhibitor arcs


    SC_CTOR(transition) {
    }

    void fire() {

        for(int i = 0; i < N; i++) {
            if ((in[i]->testTokens() > 0)) //|| (inhibitors = 0))
            {
                in[i] ->removeTokens();
                out[i]->addTokens();

                //in[i] ->removeTokens(1);
                //out[i]->addTokens(1);
                std::cout <<this->name()<< ": FIRED" << std::endl;
            }
            else {
                  std::cout <<this->name()<< ": NOT FIRED" << std::endl;
                }
        }

    }




    //part 1
        // if (in->testTokens() > 0) {
        //   std::cout <<this->name()<< ": FIRED" << std::endl;
        //}
        //in ->removeTokens(1);
        //out->addTokens(1);

        //if (in->testTokens() == 0) {
          //  std::cout <<this->name()<< ": NOT FIRED" << std::endl;
        //}

};



#endif // TRANSITION_H
