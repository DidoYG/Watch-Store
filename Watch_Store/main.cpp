#include <iostream>
#include <vector>
#include <cstdlib>
#include "Cpp/Admin.cpp"
#include "Cpp/AnalogWatch.cpp"
#include "Cpp/AutomaticWatch.cpp"
#include "Cpp/DigitalWatch.cpp"
#include "Cpp/HandWoundWatch.cpp"
#include "Cpp/MechanicalWatch.cpp"
#include "Cpp/QuartzWatch.cpp"
#include "Cpp/User.cpp"
#include "Cpp/WristWatch.cpp"
#include "Cpp/InputValidation.cpp"
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
using namespace std;

// function for printing watches in order
template <class T1>
void printWatches(const vector<T1>& watches){
    int count = 1;

    cout << "\n\n\n\n\n";
    for(const T1& watch : watches){  // it prints their brand name, model name, and price
        cout << count << ". " << watch->getBrandName() << " " << watch->getModelName() << endl;
        cout << "Price: $" << watch->getPrice() << endl;
        cout << "\n";
        count++;
    }
}

// insertionSort function that is called in quicksort function
template <class T2>
void insertionSort(vector<T2>& watches, int low, int high){
    for (int i = low + 1; i <= high; i++) {
        T2 temp = watches[i];
        int tempCustomization = temp->getCustomizationNum();

        // the algorithm sorts the elements in a descending order, based on their number of customizations
        int j = i;
        while (j > 0 && tempCustomization > watches[j - 1]->getCustomizationNum()) {
            watches[j] = watches[j - 1];
            j--;
        }

        watches[j] = temp;
    }
}

// quicksort function that uses three reference points: low, middle, and high
template <class T3>
void quicksort(vector<T3>& watches, int low, int high){

    // if the number of elements is smaller than 10, then we call insertionSort
    if (low + 10 > high){ 
        insertionSort(watches, low, high);
    } else {
        int middle = (low + high) / 2;

        // swapping the low, middle, and high (if needed)
        if (watches[middle]->getCustomizationNum() > watches[low]->getCustomizationNum()) {
            swap(watches[low], watches[middle]);
        }
        if (watches[high]->getCustomizationNum() > watches[low]->getCustomizationNum()) {
            swap(watches[low], watches[high]);
        }
        if (watches[high]->getCustomizationNum() > watches[middle]->getCustomizationNum()) {
            swap(watches[middle], watches[high]);
        }

        int pivot = watches[middle]->getCustomizationNum();
        swap(watches[middle], watches[high - 1]);

        // sorting the elements 
        int i = low, j = high - 1;
        for (i, j; ;) {
            while (i <= high && watches[i]->getCustomizationNum() > pivot) {
                i++;
            }
            while (j >= low && pivot > watches[j]->getCustomizationNum()) {
                j--;
            }

            if (i < j) {
                swap(watches[i], watches[j]);
            } else {
                break;
            }
        }

        swap(watches[i], watches[high - 1]);

        // recursively calling the function
        quicksort(watches, low, i - 1);
        quicksort(watches, i + 1, high);
    }
}

// function assignWatches initializes objects from JSON files stored locally
void assignWatches(vector<WristWatch*>& allWatches, vector<QuartzWatch*>& quartzWatches, vector<MechanicalWatch*>& mechanicalWatches, vector<AnalogWatch*>& analogWatches, vector<DigitalWatch*>& digitalWatches, vector<HandWoundWatch*>& handWatches, vector<AutomaticWatch*>& automaticWatches){
    
    // using try-catch for createWatches method in case there is an invalid data types in any of the files
    try{
        analogWatches = AnalogWatch::createAnalogWatches("JSON_Data/analog.json");
        digitalWatches = DigitalWatch::createDigitalWatches("JSON_Data/digital.json");
        handWatches = HandWoundWatch::createHandWoundWatches("JSON_Data/handWound.json");
        automaticWatches = AutomaticWatch::createAutomaticWatches("JSON_Data/automatic.json");

    } 
    catch(const exception& ex){
        cerr << "Error: " << ex.what() << endl;
    }

    // filling vector allWatches with all objects
    for(int i = 0; i < analogWatches.size(); i++){
        allWatches.push_back(analogWatches[i]);
    }
    for(int i = 0; i < digitalWatches.size(); i++){
        allWatches.push_back(digitalWatches[i]);
    }
    for(int i = 0; i < handWatches.size(); i++){
        allWatches.push_back(handWatches[i]);
    }
    for(int i = 0; i < automaticWatches.size(); i++){
        allWatches.push_back(automaticWatches[i]);
    }

    // filling vector quartzWatches with only QuartzWatch objects
    for(int i = 0; i < analogWatches.size(); i++){
        quartzWatches.push_back(analogWatches[i]);
    }
    for(int i = 0; i < digitalWatches.size(); i++){
        quartzWatches.push_back(digitalWatches[i]);
    }

    // filling vector mechanicalWatches with only MechanicalWatch objects
    for(int i = 0; i < handWatches.size(); i++){
        mechanicalWatches.push_back(handWatches[i]);
    }
    for(int i = 0; i < automaticWatches.size(); i++){
        mechanicalWatches.push_back(automaticWatches[i]);
    }
}

// menu function that is used for UI 
void menu(){

    // creating vectors for storing all objects
    vector<AnalogWatch*> analogWatches;
    vector<DigitalWatch*> digitalWatches;
    vector<HandWoundWatch*> handWatches;
    vector<AutomaticWatch*> automaticWatches;
    vector<QuartzWatch*> quartzWatches;
    vector<MechanicalWatch*> mechanicalWatches;
    vector<WristWatch*> allWatches;

    assignWatches(allWatches, quartzWatches, mechanicalWatches, analogWatches, digitalWatches, handWatches, automaticWatches);

    // copy vectors that will not be ordered, so that when removing objects from JSON files the order of the vector is the same as in the file
    vector<AnalogWatch*> unorderedAnalogWatches = analogWatches;
    vector<DigitalWatch*> unorderedDigitalWatches = digitalWatches;
    vector<HandWoundWatch*> unorderedHandWatches = handWatches;
    vector<AutomaticWatch*> unorderedAutomaticWatches = automaticWatches;

    // sorting the main vectors used for displaying content to the user
    quicksort(analogWatches, 0, analogWatches.size() - 1);
    quicksort(digitalWatches, 0, digitalWatches.size() - 1);
    quicksort(handWatches, 0, handWatches.size() - 1);
    quicksort(automaticWatches, 0, automaticWatches.size() - 1);

    char choice = ' ';
    int watchChoice;
    string name, pass;

    // sentinel controlled while loop that runs until the user decides to exit using 'q'
    // there are a lot of if else statements that lead to different outputs to the console
    // -> displaying watches, buying watches, customizing watches, etc
    while(choice != 'q'){
        system("cls");
        cout << "\n\n\n1. Admin Log-In\t\t\t2. User Log-In\n\n\nTo exit 'q': ";
        cin >> choice;

        if(choice == '1'){
            system("cls");
            cout << "\n\n\nEnter username: ";
            cin >> name;
            cout << "\n\n\nEnter password: ";
            cin >> pass;

            if(Admin::loginProfile(name, pass)){
                system("cls");
                cout << "\n\n\n1. Add Watch\t\t\t2. Remove Watch\n\n\nTo go back 'b', to exit 'q': ";
                cin >> choice;

                if(choice == '1'){
                    system("cls");
                    Admin::addWatch();
                }
                else if(choice == '2'){
                    system("cls");
                    cout << "\n\n\n1. Remove Analog Watch\t\t\t2. Remove Digital Watch\n3. Remove Hand Wound Watch\t\t4. Remove Automatic Watch\n\n\nTo go back 'b', to exit 'q': ";
                    cin >> choice;

                    if(choice == '1'){
                        system("cls");
                        printWatches(unorderedAnalogWatches);
                        watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to remove a watch or '-1' to return: ");

                        if(watchChoice > 0 && watchChoice <= unorderedAnalogWatches.size()){
                            Admin::removeWatch("JSON_Data/analog.json", watchChoice - 1);
                        }
                        else if(watchChoice == -1){
                            choice = 'b';
                        }
                        else{
                            system("cls");
                            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                            cin >> choice;
                        }
                    }
                    else if(choice == '2'){
                        system("cls");
                        printWatches(unorderedDigitalWatches);
                        watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to remove a watch or '-1' to return: ");

                        if(watchChoice > 0 && watchChoice <= unorderedDigitalWatches.size()){
                            Admin::removeWatch("JSON_Data/digital.json", watchChoice - 1);
                        }
                        else if(watchChoice == -1){
                            choice = 'b';
                        }
                        else{
                            system("cls");
                            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                            cin >> choice;
                        }
                    }
                    else if(choice == '3'){
                        system("cls");
                        printWatches(unorderedHandWatches);
                        watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to remove a watch or '-1' to return: ");

                        if(watchChoice > 0 && watchChoice <= unorderedHandWatches.size()){
                            Admin::removeWatch("JSON_Data/handWound.json", watchChoice - 1);
                        }
                        else if(watchChoice == -1){
                            choice = 'b';
                        }
                        else{
                            system("cls");
                            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                            cin >> choice;
                        }
                    }
                    else if(choice == '4'){
                        system("cls");
                        printWatches(unorderedAutomaticWatches);
                        watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to remove a watch or '-1' to return: ");

                        if(watchChoice > 0 && watchChoice <= unorderedAutomaticWatches.size()){
                            Admin::removeWatch("JSON_Data/automatic.json", watchChoice - 1);
                        }
                        else if(watchChoice == -1){
                            choice = 'b';
                        }
                        else{
                            system("cls");
                            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                            cin >> choice;
                        }
                    }
                    else if(choice == 'q' || choice == 'b'){
                        continue;
                    }
                    else{
                        system("cls");
                        cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                        cin >> choice; 
                    }
                }
                else if(choice == 'q' || choice == 'b'){
                    continue;
                }
                else{
                    system("cls");
                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                    cin >> choice; 
                }
            }
            else{
                system("cls");
                cout << "\n\n\nWrong credentials!\n\n\nPress 'b' to go back: ";
                cin >> choice;
            }
        }
        else if(choice == '2'){
            system("cls");
            cout << "\n\n\n1. Create a profile\t\t\t2. Log-In\n\n\nTo go back 'b', to exit 'q': ";
            cin >> choice;

            if(choice == '1'){
                system("cls");
                User::createProfile();
            }
            else if(choice == '2'){
                system("cls");
                cin.ignore();
                cout << "\n\n\nEnter username: ";
                getline(cin, name);
                cout << "\n\n\nEnter password: ";
                cin >> pass;
                
                if(User::loginProfile(name, pass)){
                    system("cls");
                    cout << "\n\n\nLogged as: " << name << "\t\tSee collection 's'\n\n\n1. Shop All Watches\t\t\t2. Shop Quartz Watches\t\t\t3. Shop Mechanical Watches\n\n\nTo go back 'b', to exit 'q': ";
                    cin >> choice;

                    if(choice == '1'){
                        system("cls");
                        printWatches(allWatches);
                        watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to select a watch or '-1' to return: ");

                        if(watchChoice > 0 && watchChoice <= allWatches.size()){
                            system("cls");
                            cout << "\n\n\n\n\n";
                            allWatches[watchChoice - 1]->printInfo();
                            cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                            cin >> choice;

                            if(choice == 'b'){
                                User::buyWatch(name, pass, allWatches[watchChoice - 1]->getBrandName(), allWatches[watchChoice - 1]->getModelName(), "No customizations");
                            }
                            else if(choice == 'c'){
                                allWatches[watchChoice - 1]->customizeWatch(name, pass);
                            }
                            else if(choice == 'q'){
                                continue;
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                        else if(watchChoice == -1){
                            choice = 'b';
                        }
                        else{
                            system("cls");
                            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                            cin >> choice;
                        }
                    }
                    else if(choice == '2'){
                        system("cls");
                        cout << "\n\n\n1. Shop All Quartz Watches\t\t\t2. Shop Analog Quartz Watches\t\t\t3. Shop Digital Quartz Watches\n\n\nTo go back 'b', to exit 'q': ";
                        cin >> choice;

                        if(choice == '1'){
                            system("cls");
                            printWatches(quartzWatches);
                            watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= quartzWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                quartzWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, quartzWatches[watchChoice - 1]->getBrandName(), quartzWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    quartzWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                        else if(choice == '2'){
                            system("cls");
                            printWatches(analogWatches);
                            cout << "\n\nWatches are ordered by the number of customizations.";
                            watchChoice = InputValidation::getIntInput("\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= analogWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                analogWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, analogWatches[watchChoice - 1]->getBrandName(), analogWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    analogWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                        else if(choice == '3'){
                            system("cls");
                            printWatches(digitalWatches);
                            cout << "\n\nWatches are ordered by the number of customizations.";
                            watchChoice = InputValidation::getIntInput("\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= digitalWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                digitalWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, digitalWatches[watchChoice - 1]->getBrandName(), digitalWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    digitalWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                    }
                    else if(choice == '3'){
                        system("cls");
                        cout << "\n\n\n1. Shop All Mechanical Watches\t\t\t2. Shop Hand Wound Watches\t\t\t3. Shop Automatic Watches\n\n\nTo go back 'b', to exit 'q': ";
                        cin >> choice;

                        if(choice == '1'){
                            system("cls");
                            printWatches(mechanicalWatches);
                            watchChoice = InputValidation::getIntInput("\n\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= mechanicalWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                mechanicalWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, mechanicalWatches[watchChoice - 1]->getBrandName(), mechanicalWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    mechanicalWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                        else if(choice == '2'){
                            system("cls");
                            printWatches(handWatches);
                            cout << "\n\nWatches are ordered by the number of customizations.";
                            watchChoice = InputValidation::getIntInput("\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= handWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                handWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, handWatches[watchChoice - 1]->getBrandName(), handWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    handWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }
                        else if(choice == '3'){
                            system("cls");
                            printWatches(automaticWatches);
                            cout << "\n\nWatches are ordered by the number of customizations.";
                            watchChoice = InputValidation::getIntInput("\n\nEnter a number to select a watch or '-1' to return: ");

                            if(watchChoice > 0 && watchChoice <= automaticWatches.size()){
                                system("cls");
                                cout << "\n\n\n\n\n";
                                automaticWatches[watchChoice - 1]->printInfo();
                                cout << "\n\n\nTo buy 'b', to customize 'c', or to exit 'q': ";
                                cin >> choice;

                                if(choice == 'b'){
                                    User::buyWatch(name, pass, automaticWatches[watchChoice - 1]->getBrandName(), automaticWatches[watchChoice - 1]->getModelName(), "No customizations");
                                }
                                else if(choice == 'c'){
                                    automaticWatches[watchChoice - 1]->customizeWatch(name, pass);
                                }
                                else if(choice == 'q'){
                                    continue;
                                }
                                else{
                                    system("cls");
                                    cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                    cin >> choice;
                                }
                            }
                            else if(watchChoice == -1){
                                choice = 'b';
                            }
                            else{
                                system("cls");
                                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                                cin >> choice;
                            }
                        }    
                    }
                    else if(choice == 's'){
                        system("cls");
                        User::displayCollection(name, pass);
                    }
                    else if(choice == 'q' || choice == 'b'){
                        continue;
                    }
                    else{
                        system("cls");
                        cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                        cin >> choice; 
                    }
                }
                else{
                    system("cls");
                    cout << "\n\n\nNo profile found!\n\n\nPress 'b' to go back: ";
                    cin >> choice;
                }
            }
            else if(choice == 'q' || choice == 'b'){
                continue;
            }
            else{
                system("cls");
                cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
                cin >> choice; 
            }
        }
        else if(choice == 'q'){
            continue;
        }
        else{
            system("cls");
            cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
            cin >> choice;
        }
    }

    // deleting the vectors and their elements
    // the vectors contain newly allocated pointers, therefore they should be deleted after the program ends
    AnalogWatch::deleteAnalogWatches(analogWatches);
    AnalogWatch::deleteAnalogWatches(unorderedAnalogWatches);

    DigitalWatch::deleteDigitalWatches(digitalWatches);
    DigitalWatch::deleteDigitalWatches(unorderedDigitalWatches);

    HandWoundWatch::deleteHandWoundWatches(handWatches);
    HandWoundWatch::deleteHandWoundWatches(unorderedHandWatches);

    AutomaticWatch::deleteAutomaticWatches(automaticWatches);
    AutomaticWatch::deleteAutomaticWatches(unorderedAutomaticWatches);

    allWatches.clear();
    quartzWatches.clear();
    mechanicalWatches.clear();
    analogWatches.clear();
    digitalWatches.clear();
    handWatches.clear();
    automaticWatches.clear();

    unorderedAnalogWatches.clear();
    unorderedDigitalWatches.clear();
    unorderedHandWatches.clear();
    unorderedAutomaticWatches.clear();
}

int main(){
    menu();

    return 0;
}