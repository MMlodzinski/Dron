#ifndef DRON_HH
#define DRON_HH

#include "Obiekty.hh"
#include <chrono>

class InterfejsDrona{

public:
    virtual void plynDoPrzodu(double odleglosc,double katWznoszenia)=0;
    virtual void plynDoPrzodu(double odleglosc)=0;
    virtual void obroc(double katObrotu, Axis os)=0;
};


class Dron:public Prostopadloscian,public InterfejsDrona{

protected:
double predkosc;

public:
    void plynDoPrzodu(double odleglosc,double katWznoszenia)override;
    void plynDoPrzodu(double odleglosc)override;
    void obroc(double katObrotu, Axis os)override;
    void ustawPredkosc(double predkoscDrona);

    using Prostopadloscian::Prostopadloscian;
};


#endif
