#include "Dron.hh"

void Dron::plynDoPrzodu(double odleglosc){
    double deltaTime=0;
    std::chrono::steady_clock::time_point beginMeasuring;
    std::chrono::steady_clock::time_point endMeasuring;
    std::chrono::duration<double> elapsedTime;
    do{
        beginMeasuring = std::chrono::steady_clock::now();
        do{
        endMeasuring = std::chrono::steady_clock::now();
        elapsedTime = endMeasuring - beginMeasuring;
        }while(elapsedTime.count()<0.01);
        this->korpus.pozycjaSrodka = this->korpus.pozycjaSrodka + (this->korpus.macierzObrotu*Wektor3D(0,odleglosc*elapsedTime.count(),0));
        this->wirnikL.pozycjaSrodka = this->wirnikL.pozycjaSrodka + (this->wirnikL.macierzObrotu*Wektor3D(0,odleglosc*elapsedTime.count(),0));
        wirnikL.ObrocOKat(45, OY);
        wirnikP.ObrocOKat(45, OY);
        deltaTime+=elapsedTime.count();
        this->Rysuj();
    }while(deltaTime*this->predkosc<odleglosc);


}

void Dron::plynDoPrzodu(double odleglosc, double katWznoszenia){
    MacierzObrotu tmp = this->korpus.macierzObrotu;
    MacierzObrotu tmp2 = this->wirnikL.macierzObrotu;
    this->korpus.ObrocOKat(-katWznoszenia,OX);
    this->wirnikL.ObrocOKat(-katWznoszenia,OX);
    this->wirnikP.ObrocOKat(-katWznoszenia,OX);
    this->plynDoPrzodu(odleglosc);
    this->korpus.macierzObrotu = tmp;
    this->wirnikL.macierzObrotu = tmp2;
    this->wirnikP.macierzObrotu = tmp2;
    this->Rysuj();
}

void Dron::obroc(double katObrotu, Axis os){
    this->korpus.ObrocOKat(katObrotu, os);
    this->wirnikL.ObrocOKat(katObrotu, os);
    this->wirnikP.ObrocOKat(katObrotu, os);
    this->Rysuj();
}


void Dron::ustawPredkosc(double predkoscDrona){
    this->predkosc = predkoscDrona;
}

int Dron::Rysuj(){
    this->wirnikL.pozycjaSrodka = this->korpus.pozycjaSrodka + (this->korpus.macierzObrotu*Wektor3D(-0.5,-1.75,0));
    
    this->wirnikP.pozycjaSrodka = this->korpus.pozycjaSrodka + (this->korpus.macierzObrotu*Wektor3D(0.5,-1.75,0));
    
    korpus.Rysuj();
    wirnikL.Rysuj();
    wirnikP.Rysuj();
}

Dron::Dron(){
    wirnikL.ObrocOKat(90, OX);
    wirnikP.ObrocOKat(90, OX);
    
    
}

void Dron::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api){
    this->korpus.ustawApi(api);
    this->wirnikL.ustawApi(api);
    this->wirnikP.ustawApi(api);
}
