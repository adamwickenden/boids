#include "Obstacle.h"
//constructors
Obstacle::Obstacle(){
}

Obstacle::Obstacle(PolarVector position)//inherits from item
    :Item(position){
}

Obstacle::~Obstacle(){

}

//get/set and other methods
void Obstacle::Print() const{
   std::cout << "Position ";
   fPosition.Print();
}

PolarVector Obstacle::GetPosition() const{
    return fPosition;
}

void Obstacle::SetPosition(PolarVector position){
    fPosition = position;
}

