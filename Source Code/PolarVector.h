#ifndef POLARVECTOR_H
#define POLARVECTOR_H


class PolarVector
{
public:
    PolarVector(); //Empty Constructor
    PolarVector(double x, double y); //Numerical input constructor
    PolarVector(const double *); //Constructor for pointers
    PolarVector(const PolarVector &); //Constructor for copying another PolarVector
    ~PolarVector(); //Destructor

    double GetX() const; //Declare Get Methods
    double GetY() const;

    void SetX(double); //Declare Set Methods
    void SetY(double);
    void SetXY(double x, double y);

    //Declare Other Methods and Operators:
    double Radius() const; //radial component (equivalent to magnitude of vector)
    double Radius2() const; //radial component squared
    double Theta() const; //polar angle
    void Print() const;
    double Dot(const PolarVector &) const; //Dot product
    PolarVector Normalise();  //Returns a normalised PolarVector

    //Declaration of local operators that alter the object
    PolarVector & operator = (const PolarVector &); //Equals
    PolarVector & operator += (const PolarVector &); //Scalar addition
    PolarVector & operator -= (const PolarVector &); //Scalar subtraction
    PolarVector & operator *= (double); //Scalar multiplication
    PolarVector & operator - (); //Unit negative

private:
    double fX, fY; //Data Components
};

//Declare global operators that return a new object
PolarVector operator + (const PolarVector &, const PolarVector &); //Addition of vectors
PolarVector operator - (const PolarVector &, const PolarVector &); //Subtraction of vectors
PolarVector operator * (const PolarVector &, double a); //Multiplication by a scalar number
PolarVector operator * (double a, const PolarVector &); //Multiplication by a scalar number

#endif // POLARVECTOR_H
