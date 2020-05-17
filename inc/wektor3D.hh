#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "SWektor.hh"

class Wektor3D:public SWektor<double, 3>{

public:
    using SWektor::SWektor; //uzywa konstruktorow dla wektora
    using SWektor::operator=;
    Wektor3D(double x,double y,double z);
};

#endif