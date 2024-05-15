#include <iostream>
#include "WristWatch.hpp"
using namespace std;

#pragma once

// header for class QuartzWatch that inherits WristWatch

class QuartzWatch : public WristWatch
{
private:
    
    // private data members

    string batteryType;
    bool easilyReplaceableBattery;

public:

    // default and normal constructors

    QuartzWatch();

    QuartzWatch(string, string, string, string, string, string, string, double, int, int, string, bool);

    // getters and setters

    void setBatteryType(string);

    void setEasilyReplaceableBattery(bool);

    string getBatteryType() const;

    bool getEasilyReplaceableBattery() const;

    // pure virtual methods printInfo and customizeWatch

    virtual void printInfo() const = 0;

    virtual void customizeWatch(const string&, const string&) = 0;
};