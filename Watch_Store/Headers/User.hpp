#include <iostream>
#include <vector>
using namespace std;

#pragma once

// header for class Admin

class User
{
public:

    // public methods, that are declared static so that they can be used without an object

    static void buyWatch(const string&, const string&, const string&, const string&, const string&);

    static void displayCollection(const string&, const string&);

    static void createProfile();

    static bool loginProfile(const string&, const string&);
};