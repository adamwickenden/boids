#ifndef MOVER_H
#define MOVER_H

#include "Item.h"
#include "PolarVector.h"

//second tier inheritance class has a position, velocity and acceleration to be used for prey and predator, has avoidance of edges of area coded here (virtual)

class Mover:public Item{
public:
    Mover();
    Mover(PolarVector position, PolarVector velocity, PolarVector acceleration);
    virtual ~Mover();

    //Get/Set and other declarations
    PolarVector GetVelocity() const;
    void SetVelocity(PolarVector velocity);
    PolarVector GetAcceleration() const;
    void SetAcceleration(PolarVector acceleration);
    void Fly(); //Simulation of flight. Contains avoidance of edges.

    void Print() const;


protected:
    PolarVector fVelocity;
    PolarVector fAcceleration;
};

#endif // MOVER_H
