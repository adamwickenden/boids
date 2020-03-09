#include "Item.h"
#include "PolarVector.h"
#include <iostream>

//constructors
Item::Item(){
}

Item::Item(PolarVector& position){
    fPosition = position;
}

Item::~Item(){

}

//get and sets
PolarVector Item::GetPosition() const{
    return fPosition;
}

void Item::SetPosition(PolarVector position){
    fPosition = position;
}
