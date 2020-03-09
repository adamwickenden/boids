#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Item.h"
#include "PolarVector.h"

//Real obstacle class, just has a position and will be avoided by both prey and predator

class Obstacle:public Item{
public:
    Obstacle();
    Obstacle(PolarVector position);
    ~Obstacle();

    //Get/Set and other declarations
    PolarVector GetPosition() const;
    void SetPosition(PolarVector position);
    void Print() const;
};

#endif // OBSTACLE_H
