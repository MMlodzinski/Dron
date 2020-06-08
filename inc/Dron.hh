#ifndef DRON_HH
#define DRON_HH

#include "Obiekty.hh"
#include <chrono>




class Dron:protected Prostopadloscian, protected Graniastoslup, public InterfejsDrona, public InterfejsPrzeszkody{

protected:
Prostopadloscian korpus;
Graniastoslup wirnikL, wirnikP;
double predkosc;

public:
    void plynDoPrzodu(double odleglosc,double katWznoszenia)override;
    void plynDoPrzodu(double odleglosc)override;
    void obroc(double katObrotu, Axis os)override;
    void ustawPredkosc(double predkoscDrona);
    int Rysuj()override;
    Dron();
    void ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api);
    double promien()override;
    Wektor3D pozycja()override;
    bool czyKolizja(std::shared_ptr<InterfejsDrona> dron)override;
    void zmienKolor(std::string kolorObiektu);
};


#endif
