#include <iostream>
using namespace std;

#pragma once

// header for class Admin

class Admin
{
public:

    // public methods, that are declared static so that they can be used without an object

    static void addWatch();

    static void removeWatch(const string&, const int&);

    static bool loginProfile(const string&, const string&);
};