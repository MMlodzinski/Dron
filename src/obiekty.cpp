#include "Obiekty.hh"

void ObiektRysowalny::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api){
    drawingApi = api;
}

void ObiektRysowalny::zmienKolor(std::string kolorObiektu){
    this->kolor = kolorObiektu;
}

void Bryla::ObrocOKat(double katWStopniach, Axis osObrotu){
double alpha = -M_PI*katWStopniach/180;
    switch(osObrotu){
        case OX:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,std::cos(alpha),-std::sin(alpha)),Wektor3D(0,std::sin(alpha),std::cos(alpha)));
        break;

        case OY:
            this->macierzObrotu =  this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(alpha),0,std::sin(alpha)),Wektor3D(0,1,0),Wektor3D(-std::sin(alpha),0,std::cos(alpha)));
        break;

        case OZ:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(alpha),-std::sin(alpha),0),Wektor3D(std::sin(alpha),std::cos(alpha),0),Wektor3D(0,0,1));
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
    this->szerokosc=2;
    this->wysokosc=2;
    this->dlugosc=3;
}

Prostopadloscian::Prostopadloscian(double dlugoscX,double dlugoscY, double wysokosc){
    this->szerokosc = dlugoscX;
    this->dlugosc = dlugoscY;
    this->wysokosc = wysokosc;
}