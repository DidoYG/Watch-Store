#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "../Headers/Admin.hpp"
#include "../Headers/InputValidation.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/ostreamwrapper.h"
#include "../include/rapidjson/istreamwrapper.h"
using namespace std;
using namespace rapidjson;

// addWatch method adds new watch elements to the JSON file chosen by the admin
void Admin::addWatch(){
    char choice;
    cout << "\n\n\n1. Add Analog Watch\t\t\t2. Add Digital Watch\n3. Add Hand Wound Watch\t\t\t4. Add Automatic Watch\n\n\nTo go back 'b': ";
    cin >> choice;
    cin.ignore();

    string brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, batteryType, quartzType, displayType, rotorType;
    double price, displaySize;
    int warranty, customizationNumber, powerReserve, beatRate, windsRequired, crownWoundPosition;
    bool easilyReplaceableBattery, hasHandWinding;

    char c;

    string jsonFilePath;

    if(choice == 'b'){
        return;
    }

    // entering all the information for the particular watch we want to add
    system("cls");
    cout << "Enter brand name: ";
    getline(cin, brandName);
    cout << "Enter model name: ";
    getline(cin, modelName);
    cout << "Enter case material: ";
    getline(cin, caseMaterial);
    cout << "Enter strap material: ";
    getline(cin, strapMaterial);
    cout << "Enter glass material: ";
    getline(cin, glassMaterial);
    cout << "Enter movement type: ";
    getline(cin, movementType);
    cout << "Enter complication type: ";
    getline(cin, complicationType);
    price = InputValidation::getDoubleInput("Enter price (double): ");
    warranty = InputValidation::getIntInput("Enter warranty (int): ");
    customizationNumber = InputValidation::getIntInput("Enter number of customizations (int): ");

    if(choice == '1'){
        jsonFilePath = "JSON_Data/analog.json";
        cout << "Enter battery type: ";
        getline(cin, batteryType);
        easilyReplaceableBattery = InputValidation::getBoolInput("Enter if the battery is easy to replace ('1' or '0'): ");
        cout << "Enter quartz type: ";
        getline(cin, quartzType);
    }
    else if(choice == '2'){
        jsonFilePath = "JSON_Data/digital.json";
        cout << "Enter battery type: ";
        getline(cin, batteryType);
        easilyReplaceableBattery = InputValidation::getBoolInput("Enter if the battery is easy to replace ('1' or '0'): ");
        cout << "Enter display type: ";
        getline(cin, displayType);
        displaySize = InputValidation::getDoubleInput("Enter display size (double): ");
    }
    else if(choice == '3'){
        jsonFilePath = "JSON_Data/handWound.json";
        powerReserve = InputValidation::getIntInput("Enter power reserve (int): ");
        beatRate = InputValidation::getIntInput("Enter beat rate (int): ");
        windsRequired = InputValidation::getIntInput("Enter winds required (int): ");
        crownWoundPosition = InputValidation::getIntInput("Enter crown winding position (int): ");
    }
    else if(choice == '4'){
        jsonFilePath = "JSON_Data/automatic.json";
        powerReserve = InputValidation::getIntInput("Enter power reserve (int): ");
        beatRate = InputValidation::getIntInput("Enter beat rate (int): ");
        cout << "Enter rotor type: ";
        getline(cin, rotorType);
        hasHandWinding = InputValidation::getBoolInput("Enter if the watch has manual winding ('1' or '0'): ");
    }
    else{
        system("cls");
        cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
        cin >> choice;
        return; 
    }

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }

    // declaring a newWatch object that will be added to the files
    Value newWatch(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();

    newWatch.AddMember("brandName", StringRef(brandName.c_str()), allocator);
    newWatch.AddMember("modelName", StringRef(modelName.c_str()), allocator);
    newWatch.AddMember("caseMaterial", StringRef(caseMaterial.c_str()), allocator);
    newWatch.AddMember("strapMaterial", StringRef(strapMaterial.c_str()), allocator);
    newWatch.AddMember("glassMaterial", StringRef(glassMaterial.c_str()), allocator);
    newWatch.AddMember("movementType", StringRef(movementType.c_str()), allocator);
    newWatch.AddMember("complicationType", StringRef(complicationType.c_str()), allocator);
    newWatch.AddMember("price", price, allocator);
    newWatch.AddMember("warranty", warranty, allocator);
    newWatch.AddMember("custom", customizationNumber, allocator);

    if(choice == '1'){
        newWatch.AddMember("batteryType", StringRef(batteryType.c_str()), allocator);
        newWatch.AddMember("easilyReplaceableBattery", easilyReplaceableBattery, allocator);
        newWatch.AddMember("quartzType", StringRef(quartzType.c_str()), allocator);
    } 
    else if(choice == '2'){
        newWatch.AddMember("batteryType", StringRef(batteryType.c_str()), allocator);
        newWatch.AddMember("easilyReplaceableBattery", easilyReplaceableBattery, allocator);
        newWatch.AddMember("displayType", StringRef(displayType.c_str()), allocator);
        newWatch.AddMember("displaySize", displaySize, allocator);
    } 
    else if(choice == '3'){
        newWatch.AddMember("powerReserve", powerReserve, allocator);
        newWatch.AddMember("beatRate", beatRate, allocator);
        newWatch.AddMember("windsRequired", windsRequired, allocator);
        newWatch.AddMember("crownWoundPosition", crownWoundPosition, allocator);
    } 
    else if(choice == '4'){
        newWatch.AddMember("powerReserve", powerReserve, allocator);
        newWatch.AddMember("beatRate", beatRate, allocator);
        newWatch.AddMember("rotorType", StringRef(rotorType.c_str()), allocator);
        newWatch.AddMember("hasHandWinding", hasHandWinding, allocator);
    }

    Value& watches = document["watches"];
    if (!watches.IsArray()) {
        watches.SetArray();
    }
    watches.PushBack(newWatch, allocator);

    ofstream ofs(jsonFilePath);
    if (!ofs.is_open()) {
        cerr << "Failed to open JSON file for writing: " << jsonFilePath << endl;
        cin >> c;
        return;
    }

    OStreamWrapper osw(ofs);
    Writer<OStreamWrapper> writer(osw);
    document.Accept(writer);

    cout << "\nWatch added successfully to " << jsonFilePath << endl;
    cout << "Restart the app to see the changes!\nPress any letter to continue: ";
    cin >> c;
}

// removeWatch method removes a selected element from a particular file
void Admin::removeWatch(const string& jsonFilePath, const int& elementToRemove){
    char c;

    ifstream ifs(jsonFilePath);
    Document document;
    if (!ifs.is_open()) {
        cerr << "Error opening file: " << jsonFilePath << endl;
        cin >> c;
        return;
    }

    string jsonStr((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    if (document.Parse(jsonStr.c_str()).HasParseError()) {
        cerr << "Error parsing JSON." << endl;
        cin >> c;
        return;
    }
    
    // checking if the watch collection exists
    if (!document.HasMember("watches") || !document["watches"].IsArray()) {
        cerr << "'watches' array not found in JSON." << endl;
        cin >> c;
        return;
    }

    Value& watches = document["watches"];
    
    // checking if the collection is empty
    if (watches.Size() == 0) {
        cerr << "'watches' array is empty." << endl;
        cin >> c;
        return;
    }

    // if everything is fine then we remove the watch with the index given by the admin
    watches.Erase(watches.Begin() + elementToRemove);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);

    ofstream ofs(jsonFilePath);
    if (!ofs.is_open()) {
        cerr << "Error opening file for writing: " << jsonFilePath << endl;
        cin >> c;
        return;
    }
    ofs << buffer.GetString();
    ofs.close();

    cout << "\nWatch number " << elementToRemove + 1 << " removed successfully." << endl;
    cout << "Restart the app to see the changes!\nPress any letter to continue: ";
    cin >> c;
}

// loginProfile method checks wether the adminName and adminPass match the credentials saved in the program
bool Admin::loginProfile(const string& adminName, const string& adminPass){
    string jsonFilePath = "JSON_Data/admin.json";
    char c;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }

    // checking for the collection where the credentials are stored 
    const auto& adminArray = document["admin"];
    if (!adminArray.IsArray()){
        cerr << "Invalid JSON format in file: " << jsonFilePath << endl;
    }

    // passing the values to variables
    const auto& adminData = adminArray[0];

    const auto& adminNameValue = adminData["adminName"];
    const auto& adminPassValue = adminData["adminPass"];

    if (!adminNameValue.IsString() || !adminPassValue.IsString()){
        cerr << "Invalid JSON data types in file: " << jsonFilePath << endl;
    }

    // if there is a match the admin is logged in successfully
    if(adminNameValue.GetString() == adminName && adminPassValue.GetString() == adminPass){
        return true;
    }

    return false;
}