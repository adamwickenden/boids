#include <math.h>
#include <iostream>

#include "PolarVector.h"
//constructors
PolarVector::PolarVector(){
    fX = 0.0;
    fY = 0.0;
}

PolarVector::PolarVector(double x, double y){
    fX = x;
    fY = y;
}

PolarVector::PolarVector(const double * c0){
    fX = c0[0];
    fY = c0[1];
}

PolarVector::PolarVector(const PolarVector & b){
    fX = b.fX;
    fY = b.fY;
}

PolarVector::~PolarVector() {
}
//Define Get & Set Methods
double PolarVector::GetX() const {return fX;}
double PolarVector::GetY() const {return fY;}

void PolarVector::SetX(double x) {fX = x;}
void PolarVector::SetY(double y) {fY = y;}
void PolarVector::SetXY(double x, double y){fX = x; fY = y;}

//Define Local operators
PolarVector & PolarVector::operator = (const PolarVector & b){
  fX = b.fX;
  fY = b.fY;
  return *this;
}
PolarVector & PolarVector::operator += (const PolarVector & b){
  fX += b.fX;
  fY += b.fY;
  return *this;
}
PolarVector & PolarVector::operator -= (const PolarVector & b){
  fX -= b.fX;
  fY -= b.fY;
  return *this;
}
PolarVector & PolarVector::operator - () {
    fX=-fX;
    fY=-fY;
  return *this;
}
PolarVector & PolarVector::operator *= (double a){
  fX *= a;
  fX *= a;
  return *this;
}


//Define other methods:
double PolarVector::Radius2() const {return fX*fX + fY*fY;}

double PolarVector::Dot(const PolarVector & b) const {return fX*b.fX + fY*b.fY;}

double PolarVector::Radius() const{
    return sqrt(Radius2());
}

double PolarVector::Theta() const{
    return fX == 0.0 && fY == 0.0 ? 0.0 : atan2(fY,fX);
}

void PolarVector::Print() const{
    std::cout << "(x,y) = " << GetX() << " , " << GetY() << std::endl;
}

PolarVector PolarVector::Normalise(){
    double a = sqrt(fX*fX + fY*fY);
    return PolarVector(fX/a,fY/a);
}

//Define global operators
PolarVector operator + (const PolarVector & a, const PolarVector & b){
    return PolarVector (a.GetX() + b.GetX(), a.GetY() + b.GetY());
}
PolarVector operator - (const PolarVector & a, const PolarVector & b){
    return PolarVector (a.GetX() - b.GetX(), a.GetY() - b.GetY());
}
PolarVector operator *(const PolarVector & b, double a){
    return PolarVector (a*b.GetX(), a*b.GetY());
}
PolarVector operator *(double a, const PolarVector & b){
    return PolarVector (a*b.GetX(), a*b.GetY());
}




