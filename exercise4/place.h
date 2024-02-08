//
// Created by adam on 09.12.23.
//


#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:

class placeInterface : public sc_interface
{
public:
    virtual void addTokens() = 0; //removed usigned int
    virtual void removeTokens() = 0;
    virtual unsigned int testTokens() = 0;
};

// Place Channel:
template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public  placeInterface
{
private:
    unsigned int tokens; //numbers of tokens in the place

public:
    place(unsigned int size) : tokens(size)
    {
    }

    void addTokens()
    {
        tokens = tokens + Win;
    }

    void removeTokens()
    {
        tokens = tokens - Wout;
    }

    unsigned int testTokens()
    {
        if (tokens >= Wout)
            return true;
        //return (tokens >= Wout);
    }
};

#endif // PLACE_H