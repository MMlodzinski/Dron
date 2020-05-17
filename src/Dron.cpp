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
        //std::cout<<"HKKK\n";
        this->pozycjaSrodka = this->pozycjaSrodka + (this->macierzObrotu*Wektor3D(0,odleglosc*elapsedTime.count(),0));
        deltaTime+=elapsedTime.count();
        this->Rysuj();
    }while(deltaTime*this->predkosc<odleglosc);


}

void Dron::plynDoPrzodu(double odleglosc, double katWznoszenia){
    MacierzObrotu tmp = this->macierzObrotu;
    this->ObrocOKat(-katWznoszenia,OX);
    this->plynDoPrzodu(odleglosc);
    this->macierzObrotu = tmp;
    this->Rysuj();
}

void Dron::obroc(double katObrotu, Axis os){
    this->ObrocOKat(katObrotu, os);
    this->Rysuj();
}


void Dron::ustawPredkosc(double predkoscDrona){
    this->predkosc = predkoscDrona;
}
