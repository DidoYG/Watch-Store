#include <iostream>
using namespace std;

#pragma once

// header for class WristWatch

class WristWatch
{
private:

    // private data members

    string brandName;
    string modelName;
    string caseMaterial;
    string strapMaterial;
    string glassMaterial;
    string movementType;
    string complicationType;
    double price;
    int warranty;
    int customizationNumber;

public:

    // default and normal constructors

    WristWatch();

    WristWatch(string, string, string, string, string, string, string, double, int, int);

    // setters

    void setBrandName(string);
    void setModelName(string);
    void setCaseMaterial(string);
    void setStrapMaterial(string);
    void setGlassMaterial(string);
    void setMovementType(string);
    void setComplicationType(string);
    void setPrice(double);
    void setWarranty(int);
    void setCustomizationNum(int);

    // getters

    string getBrandName() const;
    string getModelName() const;
    string getCaseMaterial() const;
    string getStrapMaterial() const;
    string getGlassMaterial() const;
    string getMovementType() const;
    string getComplicationType() const;
    double getPrice() const;
    int getWarranty() const;
    int getCustomizationNum() const;
    
    // pure virtual methods printInfo and customizeWatch

    virtual void printInfo() const = 0;

    virtual void customizeWatch(const string&, const string&) = 0;

};