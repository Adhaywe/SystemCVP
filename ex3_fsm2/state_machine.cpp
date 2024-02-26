//
// Created by adam on 22.02.24.
//
#include <iostream>

#include "state_machine.h"

void stateMachine::process() {
    char dna = input.read();

    switch (currentState) {
        case Start:
            if (dna == 'A'|| dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            else if (dna == 'G') {
                currentState = G_s;
            }
            break;

        case G_s:
            if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'A') {
                currentState = GA;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GA:
            if (dna == 'A') {
                currentState = GAA;
            }
            else if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAA:
            if (dna == 'A') {
                currentState = GAAA;
            }
            else if (dna == 'G') {
                currentState = GAAG;
                std::cout << "State 1 GAAG" << std::endl;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAG:

            if (dna == 'G') {

                currentState = G_s;
            }
            else if (dna == 'A' || dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAA:

            if (dna == 'G') {
                currentState = GAAAG;
                std::cout << "State 2 GAAAG "<< std::endl;
            }
            else if (dna == 'A') {
                currentState = GAAAA;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAAG:

            if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'A' || dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAAA:
            if (dna == 'G') {
                currentState = GAAAAG;
                std::cout << "State 3 GAAAAG" << std::endl;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAAAG:
            if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'C' || dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        default:
            break;

    }
}