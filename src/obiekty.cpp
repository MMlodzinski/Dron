#include "Obiekty.hh"
#include <math.h>

void ObiektRysowalny::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api){
    drawingApi = api;
}

void ObiektRysowalny::zmienKolor(std::string kolorObiektu){
    this->kolor = kolorObiektu;
}

void Bryla::ObrocOKat(double katWStopniach, Axis osObrotu){
double kat = -M_PI*katWStopniach/180;
    switch(osObrotu){
        case OX:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,std::cos(kat),-std::sin(kat)),Wektor3D(0,std::sin(kat),std::cos(kat)));
        break;

        case OY:
            this->macierzObrotu =  this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(kat),0,std::sin(kat)),Wektor3D(0,1,0),Wektor3D(-std::sin(kat),0,std::cos(kat)));
        break;

        case OZ:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(kat),-std::sin(kat),0),Wektor3D(std::sin(kat),std::cos(kat),0),Wektor3D(0,0,1));
        break;
    }
}



void Bryla::Przenies(const Wektor3D & wektorPrzesuniecia){
    this->pozycjaSrodka = this->pozycjaSrodka + wektorPrzesuniecia;
}

Bryla::Bryla(const Wektor3D & pozycja){
    this->pozycjaSrodka = pozycja;
}

Bryla::Bryla(){
    this->pozycjaSrodka = Wektor3D();
    this->macierzObrotu = MacierzObrotu();
}

int Prostopadloscian::Rysuj(){
    this->aktualizujPolozenie();
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
    }

    this->id = drawingApi->draw_polyhedron(this->wierzcholki,this->kolor);
    drawingApi->redraw();
    return this->id;
}

void Prostopadloscian::aktualizujPolozenie(){
    this->wierzcholki[0][0]= (macierzObrotu*Wektor3D(-szerokosc/2,-dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][1]= (macierzObrotu*Wektor3D(-szerokosc/2, dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][2]= (macierzObrotu*Wektor3D( szerokosc/2, dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][3]= (macierzObrotu*Wektor3D( szerokosc/2,-dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);

    this->wierzcholki[1][0]= (macierzObrotu*Wektor3D(-szerokosc/2,-dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][1]= (macierzObrotu*Wektor3D(-szerokosc/2, dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][2]= (macierzObrotu*Wektor3D( szerokosc/2, dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][3]= (macierzObrotu*Wektor3D( szerokosc/2,-dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
}


Prostopadloscian::Prostopadloscian(){
    this->szerokosc=SZEROKOSC_KORPUSU;
    this->wysokosc=WYSOKOSC_KORPUSU;
    this->dlugosc=DLUGOSC_KORPUSU;
}

Prostopadloscian::Prostopadloscian(double dlugoscX,double dlugoscY, double wysokosc){
    this->szerokosc = dlugoscX;
    this->dlugosc = dlugoscY;
    this->wysokosc = wysokosc;
}

Plaszczyzna::Plaszczyzna(const Wektor3D & pozycja){
    this->pozycjaSrodka = pozycja;
}

Plaszczyzna::Plaszczyzna(){
    this->pozycjaSrodka = Wektor3D();
}


void Dno::Ustaw(){
    int i;

    for(i=0;i<11;i++){
        this->punkty[i][0]= Wektor3D(-szerokosc/2+i,-dlugosc/2,-wysokosc/2);
        this->punkty[i][1]= Wektor3D(-szerokosc/2+i,dlugosc/2,-wysokosc/2);
    }

    for(i=0;i<11;i++){
        this->punkty[i+11][0]= Wektor3D(-szerokosc/2,-dlugosc/2+i,-wysokosc/2);
        this->punkty[i+11][1]= Wektor3D(szerokosc/2,-dlugosc/2+i,-wysokosc/2);
    }
}

int Plaszczyzna::Rysuj(){
    this->Ustaw();
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
    }

    this->id = drawingApi->draw_surface(this->punkty,this->kolor);
    drawingApi->redraw();
    return this->id;
}

Dno::Dno(){
    this->szerokosc=DLUGOSC_DNA;
    this->dlugosc=DLUGOSC_DNA;
    this->wysokosc=DLUGOSC_DNA;
    this->punkty=std::vector<std::vector<drawNS::Point3D>>(22,std::vector<drawNS::Point3D>(2,drawNS::Point3D(0,0,-wysokosc/2)));
}

PowierzchniaWody::PowierzchniaWody(){
    this->szerokosc=DLUGOSC_DNA;
    this->dlugosc=DLUGOSC_DNA;
    this->wysokosc=DLUGOSC_DNA;
    this->punkty=std::vector<std::vector<drawNS::Point3D>>(11,std::vector<drawNS::Point3D>(12,drawNS::Point3D(0,0,wysokosc/2)));
}

void PowierzchniaWody::Ustaw(){
    int i, j;

    for(i=0;i<11;i++){
        for(j=0;j<11;j++){
            this->punkty[i][j]= Wektor3D(-szerokosc/2+i,-dlugosc/2+j,wysokosc/2-1+0.5*pow(-1,j+1));
            this->punkty[i][j+1]= Wektor3D(-szerokosc/2+i,-dlugosc/2+1+j,wysokosc/2-1+0.5*pow(-1,j+2));
        }
    }

    /*for(i=0;i<11;i++){
        this->punkty[i+11][0]= Wektor3D(-szerokosc/2,-dlugosc/2+i,wysokosc/2);
        this->punkty[i+11][1]= Wektor3D(szerokosc/2,-dlugosc/2+i,wysokosc/2);
    }*/
}

int Graniastoslup::Rysuj(){
    this->aktualizujPolozenie();
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
    }

    this->id = drawingApi->draw_polyhedron(this->wierzcholki,this->kolor);
    drawingApi->redraw();
    return this->id;
}

void Graniastoslup::aktualizujPolozenie(){
    this->wierzcholki[0][0]= (macierzObrotu*Wektor3D(-dlugosc,0,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][1]= (macierzObrotu*Wektor3D(-dlugosc/2, (dlugosc*sqrt(3))/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][2]= (macierzObrotu*Wektor3D( dlugosc/2, (dlugosc*sqrt(3))/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][3]= (macierzObrotu*Wektor3D( dlugosc,0,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][4]= (macierzObrotu*Wektor3D( dlugosc/2,-(dlugosc*sqrt(3))/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][5]= (macierzObrotu*Wektor3D( -dlugosc/2,-(dlugosc*sqrt(3))/2,-wysokosc/2)+this->pozycjaSrodka);

    this->wierzcholki[1][0]= (macierzObrotu*Wektor3D(-dlugosc,0,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][1]= (macierzObrotu*Wektor3D(-dlugosc/2, (dlugosc*sqrt(3))/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][2]= (macierzObrotu*Wektor3D( dlugosc/2, (dlugosc*sqrt(3))/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][3]= (macierzObrotu*Wektor3D( dlugosc,0,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][4]= (macierzObrotu*Wektor3D( dlugosc/2,-(dlugosc*sqrt(3))/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][5]= (macierzObrotu*Wektor3D( -dlugosc/2,-(dlugosc*sqrt(3))/2,wysokosc/2)+this->pozycjaSrodka);
}


Graniastoslup::Graniastoslup(){
    this->wysokosc=WYSOKOSC_WIRNIKA;
    this->dlugosc=DLUGOSC_WIRNIKA;
}