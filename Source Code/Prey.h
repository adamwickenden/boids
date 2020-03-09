#ifndef PREY_H
#define PREY_H

#include "Mover.h"
#include "PolarVector.h"

class Prey:public Mover{ //Real class that obeys flocking and avoidance behaviour
public:
    Prey();
    Prey(PolarVector position, PolarVector velocity, PolarVector acceleration);
    ~Prey();
};

#endif // PREY_H
