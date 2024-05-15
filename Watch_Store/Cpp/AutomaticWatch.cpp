#include <iostream>
#include <vector>
#include "../Headers/AutomaticWatch.hpp"
#include "../Headers/User.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
using namespace std;

// default constructor
AutomaticWatch::AutomaticWatch() : MechanicalWatch(){
    this->rotorType = "empty";
    this->hasHandWinding = false;
}

// normal constructor
AutomaticWatch::AutomaticWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber, int powerReserve, int beatRate, string rotorType, bool hasHandWinding) : MechanicalWatch(brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, price, warranty, customizationNumber, powerReserve, beatRate){
    this->rotorType = rotorType;
    this->hasHandWinding = hasHandWinding;
}

// setters
void AutomaticWatch::setRotorType(string rotorType){
    this->rotorType = rotorType;
}

void AutomaticWatch::setHandWinding(bool hasHandWinding){
    this->hasHandWinding = hasHandWinding;
}

// getters
string AutomaticWatch::getRotorType() const{
    return this->rotorType;
}

bool AutomaticWatch::getHandWinding() const{
    return this->hasHandWinding;
}

// giving functionality to printInfo method that is an inherited abstract method
// the method prints the object's data types 
void AutomaticWatch::printInfo() const{
    cout << "Brand Name:          " << AutomaticWatch::getBrandName() << endl;
    cout << "Model Name:          " << AutomaticWatch::getModelName() << endl;
    cout << "Case Material:       " << AutomaticWatch::getCaseMaterial() << endl;
    cout << "Strap Material:      " << AutomaticWatch::getStrapMaterial() << endl;
    cout << "Glass Material:      " << AutomaticWatch::getGlassMaterial() << endl;
    cout << "Movement Type:       " << AutomaticWatch::getMovementType() << endl;
    cout << "Complication Type:   " << AutomaticWatch::getComplicationType() << endl;
    cout << "Watch Price:         " << AutomaticWatch::getPrice() << endl;
    cout << "Watch Warranty:      " << AutomaticWatch::getWarranty() << endl;
    cout << "Power Reserve:       " << AutomaticWatch::getPowerReserve() << endl;
    cout << "Beat Rate:           " << AutomaticWatch::getBeatRate() << endl;
    cout << "Rotor Type:          " << AutomaticWatch::getRotorType() << endl;
    cout << "Has Hand Winding:    " << AutomaticWatch::getHandWinding() << endl;
    cout << "\n\nThis watch has " << AutomaticWatch::getCustomizationNum() << " customization options." << endl;
}

// customizeWatch method is used for creating a custom watch when it has customization options
void AutomaticWatch::customizeWatch(const string&username, const string& userPass){
    int custLeft = this->getCustomizationNum();
    AutomaticWatch customWatch = *this;
    char choice = ' ';
    string customDescription = "Customizations -> ";

    // the while loop runs until there are no customizations left or the user enter 'e' or 'b' to exit
    while(custLeft > 0){
        system("cls");
        cout << "\n\n\nCustomizations left: " << custLeft << "\n\n1. Change Case Material\n\n2. Change Strap Material\n\n3. Change Glass Material\n\n4. Change Complication Type\n\n5. Change Power Reserve\n\n6. Change Beat Rate\n\n7. Change Rotor Type\n\n8. Add/Remove Manual Winding\n\n\nTo exit customization 'e', to go back 'b': ";
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
            cout << "\n\n\nOriginal power reserve: " << customWatch.getPowerReserve() << "\n\n1. 40\n\n2. 65\n\n3. 80\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setPowerReserve(40);
                customDescription += "Power Reserve: 40, ";
            }
            else if(choice == '2'){
                customWatch.setPowerReserve(65);
                customDescription += "Power Reserve: 65, ";
            }
            else if(choice == '3'){
                customWatch.setPowerReserve(80);
                customDescription += "Power Reserve: 80, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '6'){
            system("cls");
            cout << "\n\n\nOriginal beat rate: " << customWatch.getBeatRate() << "\n\n1. 21600\n\n2. 28800\n\n3. 32786\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setBeatRate(21600);
                customDescription += "Beat Rate: 21600, ";
            }
            else if(choice == '2'){
                customWatch.setBeatRate(28800);
                customDescription += "Beat Rate: 28800, ";
            }
            else if(choice == '3'){
                customWatch.setBeatRate(32786);
                customDescription += "Beat Rate: 32786, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '7'){
            system("cls");
            cout << "\n\n\nOriginal rotor: " << customWatch.getRotorType() << "\n\n1. Semicircle\n\n2. Round\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setRotorType("Semicircle");
                customDescription += "Rotor: Semicircle, ";
            }
            else if(choice == '2'){
                customWatch.setRotorType("Round");
                customDescription += "Rotor: Round, ";
            }
            else{
                custLeft++;
            }
        }
        else if(choice == '8'){
            system("cls");
            cout << "\n\n\nManual winding: " << customWatch.getHandWinding() << "\n\n1. Add\n\n2. Remove\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setHandWinding(1);
                customDescription += "Manual Winding: Yes, ";
            }
            else if(choice == '2'){
                customWatch.setHandWinding(0);
                customDescription += "Manual Winding: No, ";
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
vector<AutomaticWatch*> AutomaticWatch::createAutomaticWatches(const string& jsonFilePath) {
    
    // creating a vector storing pointers to the object
    vector<AutomaticWatch*> watches;

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
        const auto& powerReserveValue = watchData["powerReserve"];
        const auto& beatRateValue = watchData["beatRate"];
        const auto& rotorTypeValue = watchData["rotorType"];
        const auto& hasHandWindingValue = watchData["hasHandWinding"];

        // checking for invalid values
        if (!brandNameValue.IsString() || !modelNameValue.IsString() ||
            !caseMaterialValue.IsString() || !strapMaterialValue.IsString() ||
            !glassMaterialValue.IsString() || !movementTypeValue.IsString() ||
            !complicationTypeValue.IsString() || !priceValue.IsDouble() ||
            !warrantyValue.IsInt() || !customNumValue.IsInt() || !powerReserveValue.IsInt() ||
            !beatRateValue.IsInt() || !rotorTypeValue.IsString() ||
            !hasHandWindingValue.IsBool()) {
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }

        // allocating new pointer for every object 
        AutomaticWatch* watch = new AutomaticWatch();

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
        watch->setPowerReserve(powerReserveValue.GetInt());
        watch->setBeatRate(beatRateValue.GetInt());
        watch->setRotorType(rotorTypeValue.GetString());
        watch->setHandWinding(hasHandWindingValue.GetBool());

        // passing the object to the vector
        watches.push_back(watch);
    }

    return watches;
}

// this method deletes the newly allocated memory, and then clears the vector
// this is done at the end of the program, after the user has exited
void AutomaticWatch::deleteAutomaticWatches(vector<AutomaticWatch*>& watches) {
    for (AutomaticWatch* watch : watches) {
        delete watch;
    }
    watches.clear();
}