#include <iostream>
#include "WristWatch.hpp"
using namespace std;

#pragma once

// header for class MechanicalWatch that inherits WristWatch

class MechanicalWatch : public WristWatch
{
private:

    // private data members

    int powerReserve;
    int beatRate;

public:

    // default and normal constructors

    MechanicalWatch();

    MechanicalWatch(string, string, string, string, string, string, string, double, int, int, int, int);

    // getters and setters

    void setPowerReserve(int);

    void setBeatRate(int);

    int getPowerReserve() const;

    int getBeatRate() const;

    // pure virtual methods printInfo and customizeWatch

    virtual void printInfo() const = 0;

    virtual void customizeWatch(const string&, const string&) = 0;
};