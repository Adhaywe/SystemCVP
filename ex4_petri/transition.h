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
//template<unsigned int N = 1, unsigned int M = 1>
SC_MODULE(transition){
  sc_port<placeInterface, N, SC_ALL_BOUND> in;
  sc_port<placeInterface, M, SC_ALL_BOUND> out;
  sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors; // for inhibitor arcs

  //task-1
//  sc_port<placeInterface> in;
//  sc_port<placeInterface> out;

    SC_CTOR(transition) {
    }

//    //part 1
//    void fire() {
//
//        bool tokens = true;
//            if (! (in->testTokens())) {
//                tokens = false;
//            }
//
//            else {
//                tokens = true;
//            }
//
//            if (tokens) {
//                in->removeTokens(1);
//                out->addTokens(1);
//
//                std::cout << this->name() << ": Fired" << std::endl;
//            }
//            else {
//                std::cout << this->name() << ": NOT Fired" << std::endl;
//            }
//    }

        //part 2
//        void fire() {
//            bool tokens = true;
//
//            for(int i = 0; i < N ; i++) {
//                if (!in[i]->testTokens()) {
//                    tokens = false;
//                }
//            }
//
//            if (tokens) {
//                for (int i = 0; i < N; i++) {
//                    in[i]->removeTokens();
//                }
//                for (int i = 0; i < M; i++) {
//                    out[i]->addTokens();
//                }
//                std::cout << this->name() << ": Fired" << std::endl;
//            }
//            else {
//                std::cout << this ->name() << ": NOT Fired" << std::endl;
//            }
//
//        }


        void fire() {
            bool tokens = true;

            for(int i = 0; i < N ; i++) {
                if (!in[i]->testTokens()) {
                    tokens = false;
                }
            }

            for(int j = 0; j < L ; j++) {
                if (inhibitors[j]->testTokens()) {
                    tokens = false;
                }
            }

            if (tokens) {
                for (int i = 0; i < N; i++) {
                    in[i]->removeTokens();
                }
                for (int i = 0; i < M; i++) {
                    out[i]->addTokens();
                }
                std::cout << this->name() << ": Fired" << std::endl;
            }
            else {
                std::cout << this ->name() << ": NOT Fired" << std::endl;
            }

        }



};



#endif // TRANSITION_H
