#include <iostream>
#include "../Headers/MechanicalWatch.hpp"
using namespace std;

// default constructor
MechanicalWatch::MechanicalWatch() : WristWatch(){
    this->powerReserve = 0;
    this->beatRate = 0;
}

// normal constructor
MechanicalWatch::MechanicalWatch(string brandName, string modelName, string caseMaterial, string strapMaterial, string glassMaterial, string movementType, string complicationType, double price, int warranty, int customizationNumber, int powerReserve, int beatRate) : WristWatch(brandName, modelName, caseMaterial, strapMaterial, glassMaterial, movementType, complicationType, price, warranty, customizationNumber){
    this->powerReserve = powerReserve;
    this->beatRate = beatRate;
}

// setters
void MechanicalWatch::setPowerReserve(int powerReserve){
    this->powerReserve = powerReserve;
}

void MechanicalWatch::setBeatRate(int beatRate){
    this->beatRate = beatRate;
}

// getters
int MechanicalWatch::getPowerReserve() const{
    return this->powerReserve;
}

int MechanicalWatch::getBeatRate() const{
    return this->beatRate;
}
