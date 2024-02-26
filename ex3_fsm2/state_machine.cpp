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
            if (dna == 'G') {
                currentState = GAAG;
            }
            else if (dna == 'A' || dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAG:

            std::cout << "We are in state 1 GAAG" << std::endl;

            if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'A') {
                currentState = GAAAG;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAAG:

            std::cout << "We are in state 2 GAAAG" << std::endl;

            if (dna == 'A') {
                currentState = GAAAAG;
            }
            else if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;

        case GAAAAG:

            std::cout << "We are in state 3 GAAAAG" << std::endl;

            if (dna == 'G') {
                currentState = G_s;
            }
            else if (dna == 'A' || dna == 'C' || dna == 'T') {
                currentState = Start;
            }
            break;


        default:
            break;

    }
}