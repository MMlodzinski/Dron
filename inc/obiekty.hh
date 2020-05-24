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

class ObiektRysowalny{

protected:
    int id;
    std::shared_ptr<drawNS::Draw3DAPI> drawingApi;
    std::string kolor;

public:
    virtual int Rysuj() = 0;
    void ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api);
    void zmienKolor(std::string kolorObiektu);
    ObiektRysowalny():id(-1){this->kolor = "black";}

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

class Dno:public Plaszczyzna{
public:
    
    Dno();
    Dno(double dlugoscX,double dlugoscY);
    void Ustaw()override;
};

class PowierzchniaWody:public Plaszczyzna{
public:

    PowierzchniaWody();
    PowierzchniaWody(double dlugoscX,double dlugoscY);
    void Ustaw()override;
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

#endif