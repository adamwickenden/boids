#include "Storage.h"
#include "math.h"

//constructors
Storage::Storage(){}

Storage::Storage(int nPrey, int nObstacle, int nPredator){//Spawns all objects

    //Generate an array of pointers to prey
    for(int i=0; i < nPrey; i++){
        Prey * prey = new Prey();
        double xp = ((double) rand() / (RAND_MAX));
        double yp = ((double) rand() / (RAND_MAX));
        double xv = ((double) rand() / (RAND_MAX));
        double yv = ((double) rand() / (RAND_MAX));
        prey->SetPosition(PolarVector(xp * 1000 , yp * 700));
        prey->SetVelocity(PolarVector(xv * 5, yv * 5));

        fFlock.push_back(prey); //Add prey to the prey vector
    }

    //Generate array of pointers to obstacles
    for(int i=0; i < nObstacle; i++){
        Obstacle * tree = new Obstacle();
        double xo = ((double) rand() / (RAND_MAX));
        double yo = ((double) rand() / (RAND_MAX));
        tree->SetPosition(PolarVector(xo * 1000 , yo * 700));

        fObstacle.push_back(tree); //add obstacle to the obstacle vector
    }

    //Generate an array of pointers to predators
    for(int i=0; i < nPredator; i++){
        Predator * predator = new Predator();
        double xpr = ((double) rand() / (RAND_MAX));
        double ypr = ((double) rand() / (RAND_MAX));
        double xvr = ((double) rand() / (RAND_MAX));
        double yvr = ((double) rand() / (RAND_MAX));
        predator->SetPosition(PolarVector(xpr * 1000 , ypr * 700));
        predator->SetVelocity(PolarVector(xvr * 5, yvr * 5));

        fPredator.push_back(predator); //Add predator to the predator vector
    }
}

Storage::~Storage(){//destructor
    for(int i=0; i < fFlock.size(); i++){//Deallocate prey
        fFlock[i]->~Prey();//Delete from heap
        delete fFlock[i];//Delete vector element
    }
    for(int i=0; i < fObstacle.size(); i++){//Deallocate Obstacles
        fObstacle[i]->~Obstacle();
        delete fObstacle[i];
    }
    for(int i=0; i < fPredator.size(); i++){//Deallocate predators
        fPredator[i]->~Predator();
        delete fPredator[i];
    }
}

//Gets/Adds and other methods
//define computational vectors required for the simulation functions
PolarVector allign;
PolarVector group;
PolarVector separation;
PolarVector steer;
double Neighbours, angle;
void Storage::Simulate(){//Simulates the motion of all objects within the storage

    PreyAllign();
    PreySeparate();
    PreyCohesion();
    PreyAvoidPred();
    PreyAvoidOb();
    PredatorAvoidOb();

    for(int i=0; i < fFlock.size(); i++){//Fly - Calls the fly function from mover through prey
        fFlock[i]->Fly();
    }

    for(int i=0; i < fPredator.size(); i++){//Fly - Calls the fly function from mover through predator
        fPredator[i]->Fly();
    }
}

void Storage::PreySeparate(){//Separation - makes prey avoid getting to close to local neighbours
    for(int i=0; i < fFlock.size(); i++){
        group.SetXY(0,0);//Reset all calculation variables
        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        angle = 0;
        Neighbours = 0;
        for(int j = 0; j < fFlock.size(); j++){//loop through all prey for each prey
            if (fFlock[i] != fFlock[j]){//if not current prey, perform action
                separation = fFlock[i]->GetPosition() - fFlock[j]->GetPosition();//gets separation between prey
                angle = acos(fFlock[i]->GetVelocity().Normalise().Dot(separation.Normalise()));//gets angle between each prey
                if(separation.Radius() < 10 && angle > (-0.76)){//if within line of sight and closest approach boundary performs action
                    Neighbours ++;//increment neighbour count
                    group.operator =(group.operator +=(separation));//sum the separation between prey[i]and all neighbours
                    allign = (group*(1/Neighbours)) ;//direction the prey needs to move corrected for number of neighbours (away from closest)
                    steer = ((fFlock[i]->GetVelocity().operator +=(allign.Normalise())));//updating of velocity to steer prey
                    fFlock[i]->SetVelocity(steer);
                }
            }
        }
    }
}

void Storage::PreyCohesion(){//Cohesion - makes prey steer to local average position
    for(int i=0; i < fFlock.size(); i++){
        group.SetXY(0,0);//Reset all calculation variables
        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        angle = 0;
        Neighbours = 0;
        for(int j = 0; j < fFlock.size(); j++){//loop through all prey for each prey
            if (fFlock[i] != fFlock[j]){
                separation = fFlock[i]->GetPosition() - fFlock[j]->GetPosition();
                angle = acos(fFlock[i]->GetVelocity().Normalise().Dot(separation.Normalise()));
                if(separation.Radius() < 30 && separation.Radius() > 10 && angle > (-0.76)){//if within line of sight and outer cohesion boundary and outside separation boundary performs action
                    Neighbours ++;//increment neighbour count
                    group.operator =(group.operator +=(fFlock[j]->GetPosition()));//sum positions of neighbours
                    allign = (group*(1/Neighbours)) - (fFlock[i]->GetPosition());//direction the prey needs to move corrected for number of neighbours (average position of neighbours)
                    steer = (fFlock[i]->GetVelocity().operator +=(allign.Normalise()*0.001));//updating of velocity to steer prey
                    fFlock[i]->SetVelocity(steer);
                }
            }
        }
    }
}

void Storage::PreyAllign(){//Allignment - makes prey allign velocities
    for(int i=0; i < fFlock.size(); i++){
        group.SetXY(0,0);
        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        angle = 0;
        Neighbours = 0;
        for(int j = 0; j < fFlock.size(); j++){//loop through all prey for each prey
            if (fFlock[i] != fFlock[j]){
                separation = fFlock[i]->GetPosition() - fFlock[j]->GetPosition();
                angle = acos(fFlock[i]->GetVelocity().Normalise().Dot(separation.Normalise()));
                if(separation.Radius() < 30 && angle > (-0.76)){
                    Neighbours ++;//increment neighbour count
                    group.operator =(group.operator +=(fFlock[j]->GetVelocity()));//sum velocities of neighbours
                    allign = (group*(1/Neighbours)).Normalise() - (fFlock[i]->GetVelocity()).Normalise();//direction the prey needs to move corrected for number of neighbours (average heading of neighbours)
                    steer = (fFlock[i]->GetVelocity().operator +=(allign));//updating of velocity to steer prey
                    fFlock[i]->SetVelocity(steer);
                }
            }
        }
    }
}

void Storage::PreyAvoidPred(){//Avoid - makes prey avoid Predators
    for(int i=0; i < fFlock.size(); i++){
        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        angle = 0;
        for(int j = 0; j < fPredator.size(); j++){
            separation = (fFlock[i]->GetPosition() - fPredator[j]->GetPosition());
            angle = acos(fFlock[i]->GetVelocity().Normalise().Dot(separation.Normalise()));
            if(separation.Radius() < 30 && angle > (-0.76)){
                allign = (((fFlock[i]->GetVelocity()).Normalise()) + separation.Normalise())*(15/separation.Radius());
                steer = fFlock[i]->GetVelocity().operator +=(allign);
                fFlock[i]->SetVelocity(steer);
            }
        }
    }
}

void Storage::PredatorAvoidOb(){//Avoid - makes predators avoid objects
    for(int i=0; i < fPredator.size(); i++){

        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        for(int j = 0; j < fObstacle.size(); j++){
            separation = (fPredator[i]->GetPosition() - fObstacle[j]->GetPosition());
            angle = acos(fPredator[i]->GetVelocity().Normalise().Dot(separation.Normalise()));
            if(separation.Radius() < 30 && angle > (-0.76)){
                allign = (((fPredator[i]->GetVelocity()).Normalise()) + separation.Normalise())*(5/separation.Radius());
                steer = fPredator[i]->GetVelocity().operator +=(allign);
                fPredator[i]->SetVelocity(steer);
            }
        }
    }
}

void Storage::PreyAvoidOb(){//Avoid - makes prey avoid objects
    for(int i=0; i < fFlock.size(); i++){
        allign.SetXY(0,0);
        separation.SetXY(0,0);
        steer.SetXY(0,0);
        angle = 0;
        for(int j = 0; j < fObstacle.size(); j++){
            separation = (fFlock[i]->GetPosition() - fObstacle[j]->GetPosition());
            angle = acos(fFlock[i]->GetVelocity().Normalise().Dot(separation.Normalise()));
            if(separation.Radius() < 30 && angle > (-0.76)){
                allign = (((fFlock[i]->GetVelocity()).Normalise()) + separation.Normalise())*(5/separation.Radius());
                steer = fFlock[i]->GetVelocity().operator +=(allign);
                fFlock[i]->SetVelocity(steer);
            }
        }
    }

}

Prey * Storage::GetComponentP(int a){//Get prey object from fFlock
    return fFlock[a];
}

Obstacle * Storage::GetComponentO(int a){//Get obstacle object from fObstacle
    return fObstacle[a];
}

Predator * Storage::GetComponentPr(int a){//Get predator object from fPredator
    return fPredator[a];
}

void Storage::AddPrey(){//Add a prey to fFlock
    Prey * prey = new Prey();
    double xp = ((double) rand() / (RAND_MAX));
    double yp = ((double) rand() / (RAND_MAX));
    double xv = ((double) rand() / (RAND_MAX));
    double yv = ((double) rand() / (RAND_MAX));
    prey->SetPosition(PolarVector(xp * 1000 , yp * 700));
    prey->SetVelocity(PolarVector(xv * 5, yv * 5));
    fFlock.push_back(prey);
}

void Storage::AddObstacle(){//Add an obstacle to fObstacle
    Obstacle * tree = new Obstacle();
    double xo = ((double) rand() / (RAND_MAX));
    double yo = ((double) rand() / (RAND_MAX));
    tree->SetPosition(PolarVector(xo * 1000 , yo * 700));
    fObstacle.push_back(tree);
}

void Storage::AddPredator(){//Add a predator to fPredator
    Predator * predator = new Predator();
    double xpr = ((double) rand() / (RAND_MAX));
    double ypr = ((double) rand() / (RAND_MAX));
    double xvr = ((double) rand() / (RAND_MAX));
    double yvr = ((double) rand() / (RAND_MAX));
    predator->SetPosition(PolarVector(xpr * 1000 , ypr * 700));
    predator->SetVelocity(PolarVector(xvr * 5, yvr * 5));
    fPredator.push_back(predator);
}

void Storage::RemovePrey(){//remove a prey, checks to make sure there are prey to remove
    if(fFlock.size() >= 2){
        fFlock.pop_back();
        fFlock[fFlock.size() - 1]->~Prey();//deletes actual instance of prey from the heap
    }
    else{}
}

void Storage::RemoveObstacle(){//remove an obstacle, checks to make sure there are obstacles to remove
    if(fObstacle.size() >= 2){
        fObstacle.pop_back();
        fObstacle[fObstacle.size() - 1]->~Obstacle();//deletes actual instance of obstacle from the heap
    }
    else{}
}

void Storage::RemovePredator(){//remove a predator, checks to make sure there are predators to remove
    if(fPredator.size()>= 2){
        fPredator.pop_back();
        fPredator[fPredator.size() - 1]->~Predator();//deletes actual instance of predator from the heap
    }
    else{}
}

int Storage::GetSizeP() const{//GetSize of fFlock
    return fFlock.size();
}

int Storage::GetSizeO() const{//GetSize of fObstacle
    return fObstacle.size();
}

int Storage::GetSizePr() const{//GetSize of fPredator
    return fPredator.size();
}
