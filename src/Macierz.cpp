#include "Macierz.hh"

Macierz3na3::Macierz3na3(const Wektor3D & wek1,const Wektor3D & wek2,const Wektor3D & wek3){
    this->tab[0]=wek1;
    this->tab[1]=wek2;
    this->tab[2]=wek3;
}

MacierzObrotu::MacierzObrotu(){
    this->tab[0]=Wektor3D(1,0,0);
    this->tab[1]=Wektor3D(0,1,0);
    this->tab[2]=Wektor3D(0,0,1);
}


MacierzObrotu::MacierzObrotu(SWektor<double,3> *wek){
    this->tab[0]=wek[0];
    this->tab[1]=wek[1];
    this->tab[2]=wek[2];
}


void MacierzObrotu::operator=(const Macierz3na3 & macierz){
    this->tab[0] = macierz[0];
    this->tab[1] = macierz[1];
    this->tab[2] = macierz[2];
}

void MacierzObrotu::operator=(const SMacierz<double,3> & macierz){
    Macierz3na3 tmp;
    tmp = macierz;
    *this = tmp;
}