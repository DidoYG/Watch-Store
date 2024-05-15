#include <iostream>
#include <limits>
#include "../Headers/InputValidation.hpp"

using namespace std;

namespace InputValidation{
    int getIntInput(const string& prompt){
        int value;

        while(true){
            cout << prompt;

            if(cin >> value){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                break;  // Exit the loop on successful input
            } 
            else{
                // Handle invalid input
                cout << "\nInvalid input! Please enter an int!\n";
                cin.clear();  // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input
            }
        }

        return value;
    }

    double getDoubleInput(const string& prompt){
        double value;

        while(true){
            cout << prompt;

            if(cin >> value){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                break;  // Exit the loop on successful input
            } 
            else{
                // Handle invalid input
                cout << "\nInvalid input! Please enter an int or a double!\n";
                cin.clear();  // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input
            }
        }

        return value;
    }

    bool getBoolInput(const string& prompt){
        int value;

        while(true){
            cout << prompt;

            if(cin >> value && (value == 0 || value == 1)){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                break;  // Exit the loop on successful input
            } 
            else{
                // Handle invalid input
                cout << "\nInvalid input! Please enter '1' or '0'!\n";
                cin.clear();  // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input
            }
        }

        return value == 1;
    }
}
