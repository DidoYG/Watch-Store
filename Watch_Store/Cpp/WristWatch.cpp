#include <iostream>
#include "../Headers/WristWatch.hpp"
using namespace std;

// default constructor
WristWatch::WristWatch(){
    this->brandName = "empty";
    this->modelName = "empty";
    this->caseMaterial = "empty";
    this->strapMaterial = "empty";
    this->glassMaterial = "empty";
    this->movementType = "empty";
    this->complicationType = "empty";
    this->price = 0.0;
    this->warranty = 0;
    this->customizationNumber = 0;
}

// normal constructor
WristWatch::WristWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber){
    this->brandName = brandName;
    this->modelName = modelName;
    this->caseMaterial = caseMaterial;
    this->strapMaterial = strapMaterial;
    this->glassMaterial = glassMaterial;
    this->movementType = movementType;
    this->complicationType = complicationType;
    this->price = price;
    this->warranty = warranty;    
    this->customizationNumber = customizationNumber;   
}

// setters
void WristWatch::setBrandName(string brandName){
    this->brandName = brandName;
}

void WristWatch::setModelName(string modelName){
    this->modelName = modelName;
}

void WristWatch::setCaseMaterial(string caseMaterial){
    this->caseMaterial = caseMaterial;
}

void WristWatch::setStrapMaterial(string strapMaterial){
    this->strapMaterial = strapMaterial;
}

void WristWatch::setGlassMaterial(string glassMaterial){
    this->glassMaterial = glassMaterial;
}

void WristWatch::setMovementType(string movementType){
    this->movementType = movementType;
}

void WristWatch::setComplicationType(string complicationType){
    this->complicationType = complicationType;
}

void WristWatch::setPrice(double price){
    this->price = price;
}

void WristWatch::setWarranty(int warranty){
    this->warranty = warranty;
}

void WristWatch::setCustomizationNum(int customizationNumber){
    this->customizationNumber = customizationNumber;
}

// getters
string WristWatch::getBrandName() const{
    return this->brandName;
}

string WristWatch::getModelName() const{
    return this->modelName;
}

string WristWatch::getCaseMaterial() const{
    return this->caseMaterial;
}

string WristWatch::getStrapMaterial() const{
    return this->strapMaterial;
}

string WristWatch::getGlassMaterial() const{
    return this->glassMaterial;
}

string WristWatch::getMovementType() const{
    return this->movementType;
}

string WristWatch::getComplicationType() const{
    return this->complicationType;
}

double WristWatch::getPrice() const{
    return this->price;
}

int WristWatch::getWarranty() const{
    return this->warranty;
}

int WristWatch::getCustomizationNum() const{
    return this->customizationNumber;
}