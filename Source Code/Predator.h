#ifndef PREDATOR_H
#define PREDATOR_H

#include "Mover.h"
#include "PolarVector.h"

class Predator:public Mover{//real class that obeys avoidance behaviour
public:
    Predator();
    Predator(PolarVector position, PolarVector velocity, PolarVector acceleration);
    ~Predator();
};

#endif // PREDATOR_H
