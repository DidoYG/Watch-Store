#include <iostream>
using namespace std;

#pragma once

// class containing utility methods for validation of user input

namespace InputValidation{
    int getIntInput(const string& prompt);

    double getDoubleInput(const string& prompt);

    bool getBoolInput(const string& prompt);
}