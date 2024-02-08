//
// Created by adam on 01.01.24.
//

#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
class placeInterface : public sc_interface {
public:
    //for templated channels
    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual unsigned int testTokens() = 0;

    //virtual void addTokens(unsigned int n) = 0;
    //virtual void removeTokens(unsigned int n) = 0;
    //virtual unsigned int testTokens() = 0;
};

// Place Channel:
template<unsigned int Win=1, unsigned int Wout=1>
class place: public placeInterface {
private:
    unsigned int tokens;

public:
    place(unsigned int size=1) : tokens(size)
    {
    }
    void addTokens() { //unsigned int n
        tokens = tokens + Win;
    }

    void removeTokens() { //unsigned int n
        tokens = tokens - Wout;
    }

    unsigned int testTokens() {
        //return tokens;
        return(tokens >= Wout); //changed for templated channels
    }

};

#endif // PLACE_H
