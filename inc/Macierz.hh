#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "SMacierz.hh"
#include "Wektor3D.hh"

class Macierz3na3:public SMacierz<double,3>{

public:
    using SMacierz::SMacierz;
    using SMacierz::operator=;
    Macierz3na3(const Wektor3D & wek1,const Wektor3D & wek2,const Wektor3D & wek3);
};

class MacierzObrotu:public Macierz3na3{

public:
    MacierzObrotu();
    MacierzObrotu(SWektor<double,3> *wek);
    MacierzObrotu(Wektor3D wek1,Wektor3D wek2,Wektor3D wek3):Macierz3na3(wek1,wek2,wek3){}
    void operator=(const Macierz3na3 & macierz);
    void operator=(const SMacierz<double,3> & macierz);

};

#endif