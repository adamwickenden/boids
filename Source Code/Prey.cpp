#include "Prey.h"

//constructors
Prey::Prey(){

}

Prey::Prey(PolarVector position, PolarVector velocity, PolarVector acceleration)//inherits from mover
    :Mover(position, velocity, acceleration){

}

Prey::~Prey(){

}


