#include <iostream>
#include <vector>
#include "MechanicalWatch.hpp"
using namespace std;

#pragma once

// header for class AutomaticWatch that inherits MechanicalWatch

class AutomaticWatch : public MechanicalWatch
{
private:

    // private data members

    string rotorType;
    bool hasHandWinding;

public:

    // default and normal constructors

    AutomaticWatch();

    AutomaticWatch(string, string, string, string, string, string, string, double, int, int, int, int, string, bool);

    // getters and setters

    void setRotorType(string);

    void setHandWinding(bool);

    string getRotorType() const;

    bool getHandWinding() const;

    // method printInfo that displays the watch's data members

    void printInfo() const;

    // method customizeWatch that allows the user to make a custom watch

    void customizeWatch(const string&, const string&); 

    // static method createAutomaticWatches initializes AutomaticWatch objects using information from a JSON file

    static vector<AutomaticWatch*> createAutomaticWatches(const string&);

    // static method deleteAutomaticWatches deletes newly allocated pointers for AutomaticWatch objects

    static void deleteAutomaticWatches(vector<AutomaticWatch*>&);
};