#include <iostream>
#include <vector>
#include "../Headers/HandWoundWatch.hpp"
#include "../Headers/User.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
using namespace std;

// default constructor
HandWoundWatch::HandWoundWatch() : MechanicalWatch(){
    this->windsRequired = 0;
    this->crownWoundPosition = 0;
}

// normal constructor
HandWoundWatch::HandWoundWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber, int powerReserve, int beatRate, int windsRequired, int crownWoundPosition) : MechanicalWatch(brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, price, warranty, customizationNumber, powerReserve, beatRate){
    this->windsRequired = windsRequired;
    this->crownWoundPosition = crownWoundPosition;
}

// setters
void HandWoundWatch::setWindsRequired(int windsRequired){
    this->windsRequired = windsRequired;
}

void HandWoundWatch::setCrownWoundPosition(int crownWoundPosition){
    this->crownWoundPosition = crownWoundPosition;
}

// getters
int HandWoundWatch::getWindsRequired() const{
    return this->windsRequired;
}

int HandWoundWatch::getCrownWoundPosition() const{
    return this->crownWoundPosition;
}

// giving functionality to printInfo method that is an inherited abstract method
// the method prints the object's data types 
void HandWoundWatch::printInfo() const{
    cout << "Brand Name:              " << HandWoundWatch::getBrandName() << endl;
    cout << "Model Name:              " << HandWoundWatch::getModelName() << endl;
    cout << "Case Material:           " << HandWoundWatch::getCaseMaterial() << endl;
    cout << "Strap Material:          " << HandWoundWatch::getStrapMaterial() << endl;
    cout << "Glass Material:          " << HandWoundWatch::getGlassMaterial() << endl;
    cout << "Movement Type:           " << HandWoundWatch::getMovementType() << endl;
    cout << "Complication Type:       " << HandWoundWatch::getComplicationType() << endl;
    cout << "Watch Price:             " << HandWoundWatch::getPrice() << endl;
    cout << "Watch Warranty:          " << HandWoundWatch::getWarranty() << endl;
    cout << "Power Reserve:           " << HandWoundWatch::getPowerReserve() << endl;
    cout << "Beat Rate:               " << HandWoundWatch::getBeatRate() << endl;
    cout << "Winds Required:          " << HandWoundWatch::getWindsRequired() << endl;
    cout << "Crown Winding Position:  " << HandWoundWatch::getCrownWoundPosition() << endl;
    cout << "\n\nThis watch has " << HandWoundWatch::getCustomizationNum() << " customization options." << endl;
}

// customizeWatch method is used for creating a custom watch when it has customization options
void HandWoundWatch::customizeWatch(const string& username, const string& userPass){
    int custLeft = this->getCustomizationNum();
    HandWoundWatch customWatch = *this;
    char choice = ' ';
    string customDescription = "Customizations -> ";

    // the while loop runs until there are no customizations left or the user enter 'e' or 'b' to exit
    while(custLeft > 0){
        system("cls");
        cout << "\n\n\nCustomizations left: " << custLeft << "\n\n1. Change Case Material\n\n2. Change Strap Material\n\n3. Change Glass Material\n\n4. Change Complication Type\n\n5. Change Power Reserve\n\n6. Change Beat Rate\n\n7. Change Maximum Winds\n\n\nTo exit customization 'e', to go back 'b': ";
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
            cout << "\n\n\nOriginal maximum winds: " << customWatch.getWindsRequired() << "\n\n1. 20\n\n2. 30\n\n3. 40\n\n\nEnter a number or 'b' to go back: ";
            cin >> choice;

            if(choice == '1'){
                customWatch.setWindsRequired(20);
                customDescription += "Winds Required: 20, ";
            }
            else if(choice == '2'){
                customWatch.setWindsRequired(30);
                customDescription += "Winds Required: 30, ";
            }
            else if(choice == '3'){
                customWatch.setWindsRequired(40);
                customDescription += "Winds Required: 40, ";
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
vector<HandWoundWatch*> HandWoundWatch::createHandWoundWatches(const string& jsonFilePath) {
    
    // creating a vector storing pointers to the object
    vector<HandWoundWatch*> watches;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }

    const auto& watchesArray = document["watches"];
    
    if (!watchesArray.IsArray()) {
        throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
    }

    // getting the data
    for (rapidjson::SizeType i = 0; i < watchesArray.Size(); ++i) {
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
        const auto& windsRequiredValue = watchData["windsRequired"];
        const auto& crownWoundPositionValue = watchData["crownWoundPosition"];

        // checking for invalid values
        if (!brandNameValue.IsString() || !modelNameValue.IsString() ||
            !caseMaterialValue.IsString() || !strapMaterialValue.IsString() ||
            !glassMaterialValue.IsString() || !movementTypeValue.IsString() ||
            !complicationTypeValue.IsString() || !priceValue.IsDouble() ||
            !warrantyValue.IsInt() || !customNumValue.IsInt() || !powerReserveValue.IsInt() ||
            !beatRateValue.IsInt() || !windsRequiredValue.IsInt() ||
            !crownWoundPositionValue.IsInt()) {
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }

        // allocating new pointer for every object 
        HandWoundWatch* watch = new HandWoundWatch();

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
        watch->setWindsRequired(windsRequiredValue.GetInt());
        watch->setCrownWoundPosition(crownWoundPositionValue.GetInt());

        // passing the object to the vector
        watches.push_back(watch);
    }

    return watches;
}

// this method deletes the newly allocated memory, and then clears the vector
// this is done at the end of the program, after the user has exited
void HandWoundWatch::deleteHandWoundWatches(vector<HandWoundWatch*>& watches) {
    for (HandWoundWatch* watch : watches) {
        delete watch;
    }
    watches.clear();
}