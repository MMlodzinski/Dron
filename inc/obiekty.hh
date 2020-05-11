#ifndef OBIEKTY_HH
#define OBIEKTY_HH

#include<vector>
#include "wektor3D.hh"

class Lamana
{
    std::vector<Wektor3D> _Wiersz;

    public:

    Wektor3D operator [](int Ind) const {return _Wiersz[Ind];}
    Wektor3D & operator [] (int Ind) {return _Wiersz[Ind];}

    void DodajWektor(Wektor3D Wek){ 
        _Wiersz.push_back(Wek);
    }

    std::vector<Wektor3D> &DajWektor(){
        return _Wiersz;
    }

    std::vector<Wektor3D> WezWektor(){
        return _Wiersz;
    }


};

std::istream& operator >> (std::istream &Str, Lamana &Przykladowa);

std::ostream& operator << (std::ostream &Str, Lamana &Przykladowa);

class ObiektRysowalny{
std::vector<Lamana> _TabLamanych;

    public:

    Lamana operator [](int Ind) const {return _TabLamanych[Ind];}
    Lamana & operator [] (int Ind) {return _TabLamanych[Ind];}

    void DodajLamana(Lamana Lam){ 
        _TabLamanych.push_back(Lam);
    }

    std::vector<Lamana> &DajLamana(){
        return _TabLamanych;
    }

    std::vector<Lamana> WezLamana()const{
        return _TabLamanych;
    }

};

std::istream& operator >> (std::istream &Str, ObiektRysowalny &Przykladowy);

std::ostream& operator << (std::ostream &Str, ObiektRysowalny &Przykladowy);

class Prostopadloscian: public ObiektRysowalny{
std::vector<Lamana> _TabLamanych;
    public:

    Prostopadloscian();
    void zapisz (std::ofstream plik, std::vector<Lamana> _TabLamanych);
};

class Dron: public Prostopadloscian{
    Prostopadloscian dron;
    Dron();
};



#endif