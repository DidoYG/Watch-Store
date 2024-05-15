#include <iostream>
#include <vector>
#include "QuartzWatch.hpp"
using namespace std;

#pragma once

// header for class DigitalWatch that inherits QuartzWatch

class DigitalWatch : public QuartzWatch
{
private:

    // private data members

    string displayType;
    double displaySize;

public:

    // default and normal constructors

    DigitalWatch();

    DigitalWatch(string, string, string, string, string, string, string, double, int, int, string, bool, string, double);

    // getters and setters

    void setDisplayType(string);

    void setDisplaySize(double);

    string getDisplayType() const;

    double getDisplaySize() const;

    // method printInfo that displays the watch's data members

    void printInfo() const;

    // method customizeWatch that allows the user to make a custom watch

    void customizeWatch(const string&, const string&);

    // static method createDigitalWatches initializes DigitalWatch objects using information from a JSON file

    static vector<DigitalWatch*> createDigitalWatches(const string&);

    // static method deleteDigitalWatches deletes newly allocated pointers for DigitalWatch objects

    static void deleteDigitalWatches(vector<DigitalWatch*>&);
};