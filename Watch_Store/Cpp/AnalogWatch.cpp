#include <iostream>
#include <vector>
#include "../Headers/User.hpp"
#include "../Headers/AnalogWatch.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
using namespace std;

// default constructor
AnalogWatch::AnalogWatch() : QuartzWatch(){
    this->quartzType = "empty";
}

// normal constructor
AnalogWatch::AnalogWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber, string batteryType, bool easilyReplaceableBattery, string quartzType) : QuartzWatch(brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, price, warranty, customizationNumber, batteryType, easilyReplaceableBattery){
    this->quartzType = quartzType;    
}

// setter
void AnalogWatch::setQuartzType(string quartzType){
    this->quartzType = quartzType;
}

// getter
string AnalogWatch::getQuartzType() const{
    return this->quartzType;
}

// giving functionality to printInfo method that is an inherited abstract method
// the method prints the object's data types 
void AnalogWatch::printInfo() const{
    cout << "Brand Name:           " << AnalogWatch::getBrandName() << endl;
    cout << "Model Name:           " << AnalogWatch::getModelName() << endl;
    cout << "Case Material:        " << AnalogWatch::getCaseMaterial() << endl;
    cout << "Strap Material:       " << AnalogWatch::getStrapMaterial() << endl;
    cout << "Glass Material:       " << AnalogWatch::getGlassMaterial() << endl;
    cout << "Movement Type:        " << AnalogWatch::getMovementType() << endl;
    cout << "Complication Type:    " << AnalogWatch::getComplicationType() << endl;
    cout << "Watch Price:          " << AnalogWatch::getPrice() << endl;
    cout << "Watch Warranty:       " << AnalogWatch::getWarranty() << endl;
    cout << "Battery Type:         " << AnalogWatch::getBatteryType() << endl;
    cout << "Replaceable Battery:  " << AnalogWatch::getEasilyReplaceableBattery() << endl;
    cout << "Quartz Type:          " << AnalogWatch::getQuartzType() << endl;
    cout << "\n\nThis watch has " << AnalogWatch::getCustomizationNum() << " customization options." << endl; 
}

// customizeWatch method is used for creating a custom watch when it has customization options
void AnalogWatch::customizeWatch(const string& username, const string& userPass){
    int custLeft = this->getCustomizationNum();
    AnalogWatch customWatch = *this;
    char choice = ' ';
    string customDescription = "Customizations -> ";

    // the while loop runs until there are no customizations left or the user enter 'e' or 'b' to exit
    while(custLeft > 0){
        system("cls");
        cout << "\n\n\nCustomizations left: " << custLeft << "\n\n1. Change Case Material\n\n2. Change Strap Material\n\n3. Change Glass Material\n\n4. Change Complication Type\n\n5. Change Battery Type\n\n6. Change Quartz Type\n\n\nTo exit customization 'e', to go back 'b': ";
        cin >> choice;

        // selecting different custom options
        if(choice == '1'){
            system("cls");
            cout << "\n\n\nOriginal case: " << customWatch.getCaseMaterial() << "\n\n\n1. Aluminum\n\n2. Stainless Steel\n\n3. Titanium\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setCaseMaterial("Aluminum");
                customDescription += "Case: Aluminum, ";
            }
            else if(choice == '2'){
                customWatch.setCaseMaterial("Stainless Steel");
                customDescription += "Case: Stainless Steel, ";
            }
            else if(choice == '3'){
                customWatch.setCaseMaterial("Titanium");
                customDescription += "Case: Titanium, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '2'){
            system("cls");
            cout << "\n\n\nOriginal strap: " << customWatch.getStrapMaterial() << "\n\n1. Aluminum\n\n2. Stainless Steel\n\n3. Titanium\n\n4. Silicone\n\n5. Leather\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setStrapMaterial("Aluminum");
                customDescription += "Strap: Aluminum, ";
            }
            else if(choice == '2'){
                customWatch.setStrapMaterial("Stainless Steel");
                customDescription += "Strap: Stainless Steel, ";
            }
            else if(choice == '3'){
                customWatch.setStrapMaterial("Titanium");
                customDescription += "Strap: Titanium, ";
            }
            else if(choice == '4'){
                customWatch.setStrapMaterial("Silicone");
                customDescription += "Strap: Silicone, ";
            }
            else if(choice == '5'){
                customWatch.setStrapMaterial("Leather");
                customDescription += "Strap: Leather, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '3'){
            system("cls");
            cout << "\n\n\nOriginal glass: " << customWatch.getGlassMaterial() << "\n\n1. Mineral Glass\n\n2. Hesalite Crystal\n\n3. Sapphire Crystal\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setGlassMaterial("Mineral Glass");
                customDescription += "Glass: Mineral Glass, ";
            }
            else if(choice == '2'){
                customWatch.setGlassMaterial("Haselite Crystal");
                customDescription += "Glass: Haselite Crystal, ";
            }
            else if(choice == '3'){
                customWatch.setGlassMaterial("Sapphire Crystal");
                customDescription += "Glass: Sapphire Crystal, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '4'){
            system("cls");
            cout << "\n\n\nOriginal complication: " << customWatch.getComplicationType() << "\n\n1. Date\n\n2. Day - Date\n\n3. Chronograph\n\n4. Date - Chronograph\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setComplicationType("Date");
                customDescription += "Complication: Date, ";
            }
            else if(choice == '2'){
                customWatch.setComplicationType("Day - Date");
                customDescription += "Complication: Day - Date, ";
            }
            else if(choice == '3'){
                customWatch.setComplicationType("Chronograph");
                customDescription += "Complication: Chronograph, ";
            }
            else if(choice == '4'){
                customWatch.setComplicationType("Date - Chronograph");
                customDescription += "Complication: Date - Chronograph, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '5'){
            system("cls");
            cout << "\n\n\nOriginal battery: " << customWatch.getBatteryType() << "\n\n1. SR626SW\n\n2. MT920\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setBatteryType("SR626SW");
                customDescription += "Battery: SR626SW, ";
            }
            else if(choice == '2'){
                customWatch.setBatteryType("MT920");
                customDescription += "Battery: MT920, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '6'){
            system("cls");
            cout << "\n\n\nOriginal quartz type: " << customWatch.getQuartzType() << "\n\n1. Normal Quartz\n\n2. Solar Quartz\n\n3. Kinetic Quartz\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setQuartzType("Normal Quartz");
                customDescription += "Quartz: Normal, ";
            }
            else if(choice == '2'){
                customWatch.setQuartzType("Solar Quartz");
                customDescription += "Quartz: Solar, ";
            }
            else if(choice == '3'){
                customWatch.setQuartzType("Kinetic Quartz");
                customDescription += "Quartz: Kinetic, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == 'e'){
            break;
        }
        else if(choice == 'b'){
            return;
        }
        else{
            custLeft++;
        }

        custLeft--;
    }

    // the newly created custom watch has no custom options so that it is set to 0
    customWatch.setCustomizationNum(0);

    system("cls");
    cout << "\n\n\n\n\nOriginal Watch:\n";
    this->printInfo();
    cout << "\n\nCustom Watch:\n";
    customWatch.printInfo();
    cout << "\n\n1. Buy the custom watch\t\t\t2. Buy the original watch\n\n\nTo go back 'b': ";
    cin >> choice;

    // choice between buying the custom watch or the original one
    if(choice == '1'){
        User::buyWatch(username, userPass, customWatch.getBrandName(), customWatch.getModelName(), customDescription);
    }
    else if(choice == '2'){
        customDescription = "No customizations";
        User::buyWatch(username, userPass, this->getBrandName(), this->getModelName(), customDescription);
    }
    else if(choice == 'b'){
        return;
    }
    else{
        system("cls");
        cout << "\n\n\nInvalid choice!\n\n\nPress 'b' to go back: ";
        cin >> choice;
        return;
    }
}

// this method is used for initializing objects using information from the given JSON file
vector<AnalogWatch*> AnalogWatch::createAnalogWatches(const string& jsonFilePath) {
    
    // creating a vector storing pointers to the object
    vector<AnalogWatch*> watches;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }

    const auto& watchesArray = document["watches"];
    
    if (!watchesArray.IsArray()){
        throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
    }

    // getting the data
    for (rapidjson::SizeType i = 0; i < watchesArray.Size(); ++i){
        const auto& watchData = watchesArray[i];

        const auto& brandNameValue = watchData["brandName"];
        const auto& modelNameValue = watchData["modelName"];
        const auto& caseMaterialValue = watchData["caseMaterial"];
        const auto& strapMaterialValue = watchData["strapMaterial"];
        const auto& glassMaterialValue = watchData["glassMaterial"];
        const auto& movementTypeValue = watchData["movementType"];
        const auto& complicationTypeValue = watchData["complicationType"];
        const auto& priceValue = watchData["price"];
        const auto& warrantyValue = watchData["warranty"];
        const auto& customNumValue = watchData["custom"];
        const auto& batteryTypeValue = watchData["batteryType"];
        const auto& easilyReplaceableBatteryValue = watchData["easilyReplaceableBattery"];
        const auto& quartzTypeValue = watchData["quartzType"];

        // checking for invalid values
        if (!brandNameValue.IsString() || !modelNameValue.IsString() ||
            !caseMaterialValue.IsString() || !strapMaterialValue.IsString() ||
            !glassMaterialValue.IsString() || !movementTypeValue.IsString() ||
            !complicationTypeValue.IsString() || !priceValue.IsDouble() ||
            !warrantyValue.IsInt() || !customNumValue.IsInt() || !batteryTypeValue.IsString() ||
            !easilyReplaceableBatteryValue.IsBool() || !quartzTypeValue.IsString()) {
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }

        // allocating new pointer for every object 
        AnalogWatch* watch = new AnalogWatch();

        watch->setBrandName(brandNameValue.GetString());
        watch->setModelName(modelNameValue.GetString());
        watch->setCaseMaterial(caseMaterialValue.GetString());
        watch->setStrapMaterial(strapMaterialValue.GetString());
        watch->setGlassMaterial(glassMaterialValue.GetString());
        watch->setMovementType(movementTypeValue.GetString());
        watch->setComplicationType(complicationTypeValue.GetString());
        watch->setPrice(priceValue.GetDouble());
        watch->setWarranty(warrantyValue.GetInt());
        watch->setCustomizationNum(customNumValue.GetInt());
        watch->setBatteryType(batteryTypeValue.GetString());
        watch->setEasilyReplaceableBattery(easilyReplaceableBatteryValue.GetBool());
        watch->setQuartzType(quartzTypeValue.GetString());

        // passing the object to the vector 
        watches.push_back(watch);
    }

    return watches;
}

// this method deletes the newly allocated memory, and then clears the vector
// this is done at the end of the program, after the user has exited
void AnalogWatch::deleteAnalogWatches(vector<AnalogWatch*>& watches) {
    for (AnalogWatch* watch : watches) {
        delete watch;
    }
    watches.clear();
}