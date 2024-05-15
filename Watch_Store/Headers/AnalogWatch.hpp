#include <iostream>
#include <vector>
#include "QuartzWatch.hpp"
using namespace std;

#pragma once

// header for class AnalogWatch that inherits QuartzWatch

class AnalogWatch : public QuartzWatch
{
private:

    // private data member

    string quartzType;

public:

    // default and normal constructors

    AnalogWatch();

    AnalogWatch(string, string, string, string, string, string, string, double, int, int, string, bool, string);

    // a getter and a setter

    void setQuartzType(string);

    string getQuartzType() const;

    // method printInfo that displays the watch's data members

    void printInfo() const;

    // method customizeWatch that allows the user to make a custom watch

    void customizeWatch(const string&, const string&);

    // static method createAnalogWatches initializes AnalogWatch objects using information from a JSON file

    static vector<AnalogWatch*> createAnalogWatches(const string&);

    // static method deleteAnalogWatches deletes newly allocated pointers for AnalogWatch objects

    static void deleteAnalogWatches(vector<AnalogWatch*>&);
};