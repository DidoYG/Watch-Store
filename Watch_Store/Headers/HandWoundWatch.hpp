#include <iostream>
#include <vector>
#include "MechanicalWatch.hpp"
using namespace std;

#pragma once

// header for class HandWoundWatch that inherits MechanicalWatch

class HandWoundWatch : public MechanicalWatch
{
private:

    // private data members

    int windsRequired;
    int crownWoundPosition;

public:

    // default and normal constructors

    HandWoundWatch();

    HandWoundWatch(string, string, string, string, string, string, string, double, int, int, int, int, int, int);

    // getters and setters

    void setWindsRequired(int);

    void setCrownWoundPosition(int);

    int getWindsRequired() const;

    int getCrownWoundPosition() const;

    // method printInfo that displays the watch's data members

    void printInfo() const;

    // method customizeWatch that allows the user to make a custom watch

    void customizeWatch(const string&, const string&);

    // static method createHandWoundWatches initializes HandWoundWatch objects using information from a JSON file

    static vector<HandWoundWatch*> createHandWoundWatches(const string&);

    // static method deleteHandWoundWatches deletes newly allocated pointers for HandWoundWatch objects

    static void deleteHandWoundWatches(vector<HandWoundWatch*>&);
};