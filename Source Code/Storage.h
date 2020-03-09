#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "Prey.h"
#include "Obstacle.h"
#include "Predator.h"


class Storage //Contains all of the Birds and obstacles, full descriptions in c++ file
{
public:
    Storage();
    Storage(int, int, int); //Generates Vectors of Prey, Obstacles & Predators respectively.
    ~Storage();

    void AddPrey();
    void AddObstacle ();
    void AddPredator ();
    void RemovePrey();
    void RemoveObstacle();
    void RemovePredator();

    Prey * GetComponentP(int);
    Obstacle * GetComponentO(int);
    Predator * GetComponentPr(int);
    int GetSizeP() const;
    int GetSizeO() const;
    int GetSizePr() const;
    void Simulate();

    void PredatorAvoidOb();
    void PreyAvoidOb();
    void PreyAvoidPred();
    void PreyAllign();
    void PreySeparate();
    void PreyCohesion();

private:
    std::vector <Prey *> fFlock;
    std::vector <Obstacle*> fObstacle;
    std::vector <Predator*> fPredator;
};

#endif // STORAGE_H
