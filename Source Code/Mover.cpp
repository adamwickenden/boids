#include <iostream>

#include "Mover.h"

//contructors
Mover::Mover(){
}

Mover::Mover(PolarVector position, PolarVector velocity, PolarVector acceleration)//contructor that inherits from item
    :Item(position){
    fVelocity = velocity;
    fAcceleration = acceleration;
}

Mover::~Mover(){
}

//get/sets and other methods
PolarVector Mover::GetVelocity() const{
    return fVelocity;
}

void Mover::SetVelocity(PolarVector velocity){
    fVelocity = velocity;
}

PolarVector Mover::GetAcceleration() const{
    return fAcceleration;
}

void Mover::SetAcceleration(PolarVector acceleration){
    fAcceleration = acceleration;
}

void Mover::Print() const{
   std::cout << "Position ";
   fPosition.Print();
   fVelocity.Print();
}

void Mover::Fly(){ //simple simulaton of movement with ability to avoide edges, thus both prey and predator will do this

        fVelocity += fAcceleration;
        fPosition += fVelocity;

        if (fVelocity.Radius2() > 2){ //set a maximum magnitude of the velocity vector
            fVelocity = fVelocity.Normalise();
        }

        //Boundary avoidance logic
        if(fPosition.GetX() <= 980 && fPosition.GetX() >= 950 && fAcceleration.Radius() != 0){ //Check to see if mover is within boundary and has acceleration
            fAcceleration = PolarVector(0,0);           
        }
        else if(fPosition.GetX() >= 980){ //Check to see if mover has left far x boundary, steer in the -x direction
            fAcceleration = PolarVector(-1,0);
        }

        else if(fPosition.GetX() >= 20 && fPosition.GetX() <=50 && fAcceleration.Radius() != 0){ //Check to see if mover is within boundary and has acceleration
            fAcceleration = PolarVector(0,0);
        }
        else if (fPosition.GetX() <= 20){ //Check to see if mover has left x boundary, if so steer in x direction
            fAcceleration = PolarVector(1,0);
        }



        else if(fPosition.GetY() <= 680 && fPosition.GetY() >= 650 && fAcceleration.Radius() != 0){ //Check to see if mover is within boundary and has acceleration
            fAcceleration = PolarVector(0,0);
        }
        else if (fPosition.GetY() >= 680){ //Check to see if mover has left top y boundary, if so steer in - y direction
            fAcceleration = PolarVector(0,-1);
        }

        else if(fPosition.GetY() >= 20 && fPosition.GetY() <= 50 && fAcceleration.Radius() != 0){ //Check to see if mover is within boundary and has acceleration
            fAcceleration = PolarVector(0,0);
        }
        else if (fPosition.GetY() <= 20){ //Check to see if mover has left y boundary, if so steer in y direction
            fAcceleration = PolarVector(0,1);
        }

}



