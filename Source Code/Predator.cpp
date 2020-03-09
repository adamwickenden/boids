#include "Predator.h"

//constructors
Predator::Predator(){
}

Predator::Predator(PolarVector position, PolarVector velocity, PolarVector acceleration)//inherits from mover
    :Mover(position, velocity, acceleration){

}

Predator::~Predator(){

}
