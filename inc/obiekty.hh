#ifndef OBIEKTY_HH
#define OBIEKTY_HH

#define M_PI           3.14159265358979323846

#include "Dr3D_gnuplot_api.hh"
#include "Macierz.hh"
#include "Wektor3D.hh"
#include <string>
#include <cmath>
#include <vector>
# include "Ustawienia.h"

enum Axis{OX,OY,OZ};
class InterfejsDrona{

public:
    virtual void plynDoPrzodu(double odleglosc,double katWznoszenia)=0;
    virtual void plynDoPrzodu(double odleglosc)=0;
    virtual void obroc(double katObrotu, Axis os)=0;

    virtual double promien()=0;
    virtual Wektor3D pozycja()=0;
};

class Zliczanie{

public:
    int stworzono;
    int istnieje;
    void wypisz();
    Zliczanie(){stworzono=0;istnieje=0;}
};

class ObiektRysowalny:public Zliczanie{

protected:
    int id;
    std::shared_ptr<drawNS::Draw3DAPI> drawingApi;
    std::string kolor;

public:
    virtual int Rysuj() = 0;
    void ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api);
    void zmienKolor(std::string kolorObiektu);
    ObiektRysowalny():id(-1){this->kolor = "black"; stworzono++; istnieje++;}
    ~ObiektRysowalny(){istnieje--;}

};



class Bryla:public ObiektRysowalny{

protected:





public:
MacierzObrotu macierzObrotu;
Wektor3D pozycjaSrodka;
    Bryla();
    virtual int Rysuj() = 0;
    virtual void aktualizujPolozenie() = 0;
    Bryla(const Wektor3D & pozycja);
    void ObrocOKat(double alpha, Axis osObrotu);
    void Przenies(const Wektor3D & wektorPrzesuniecia);
};

class Prostopadloscian:public Bryla{

protected:
    double dlugosc;
    double szerokosc;
    double wysokosc;
    std::vector<std::vector<drawNS::Point3D>> wierzcholki=std::vector<std::vector<drawNS::Point3D>>(2,std::vector<drawNS::Point3D>(4,drawNS::Point3D(0,0,0))); //2 poziomy po 4 punkty

public:
    int Rysuj() override;
    void aktualizujPolozenie() override;
    Prostopadloscian();
    Prostopadloscian(double dlugoscX,double dlugoscY, double wysokosc);

};

class Plaszczyzna:public ObiektRysowalny{
protected:
    Wektor3D pozycjaSrodka;
    double szerokosc;
    double dlugosc;
    double wysokosc;
    std::vector<std::vector<drawNS::Point3D>> punkty;
public:
    int Rysuj();
    Plaszczyzna();
    Plaszczyzna(const Wektor3D & pozycja);
    virtual void Ustaw()=0;
};

class InterfejsPrzeszkody{
public:
    virtual bool czyKolizja(std::shared_ptr<InterfejsDrona> dron)=0;


};

class Dno:public InterfejsPrzeszkody, public Plaszczyzna{
public:
    
    Dno();
    Dno(double dlugoscX,double dlugoscY);
    void Ustaw()override;
    bool czyKolizja(std::shared_ptr<InterfejsDrona> dron)override;
};

class PowierzchniaWody:public InterfejsPrzeszkody, public Plaszczyzna{
public:
    
    PowierzchniaWody();
    PowierzchniaWody(double dlugoscX,double dlugoscY);
    void Ustaw()override;
    bool czyKolizja(std::shared_ptr<InterfejsDrona> dron)override;
};

class Graniastoslup:public Bryla{
protected:
    double dlugosc;
    double wysokosc;
    std::vector<std::vector<drawNS::Point3D>> wierzcholki=std::vector<std::vector<drawNS::Point3D>>(2,std::vector<drawNS::Point3D>(6,drawNS::Point3D(0,0,0)));
     //2 poziomy po 6 punktów

public:

    int Rysuj() override;
    void aktualizujPolozenie() override;
    Graniastoslup();

};



class PrzeszkodaProst: public InterfejsPrzeszkody, public Prostopadloscian{
public:
    using Prostopadloscian::Prostopadloscian;
    double promien();
  bool czyKolizja(std::shared_ptr<InterfejsDrona> dron)override;

};

#endif