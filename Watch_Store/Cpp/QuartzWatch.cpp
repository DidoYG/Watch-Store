#include <iostream>
#include "../Headers/QuartzWatch.hpp"
using namespace std;

// default constructor
QuartzWatch::QuartzWatch() : WristWatch(){
    this->batteryType = "empty";
    this->easilyReplaceableBattery = false;
}

// normal constructor
QuartzWatch::QuartzWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber, string batteryType, bool easilyReplaceableBattery) : WristWatch(brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, price, warranty, customizationNumber){
    this->batteryType = batteryType;
    this->easilyReplaceableBattery = easilyReplaceableBattery;
}

// setters
void QuartzWatch::setBatteryType(string batteryType){
    this->batteryType = batteryType;
}

void QuartzWatch::setEasilyReplaceableBattery(bool easilyReplaceableBattery){
    this->easilyReplaceableBattery = easilyReplaceableBattery;
}

// getters
string QuartzWatch::getBatteryType() const{
    return this->batteryType;
}

bool QuartzWatch::getEasilyReplaceableBattery() const{
    return this->easilyReplaceableBattery;
}