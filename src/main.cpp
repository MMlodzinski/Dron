#include <iostream>
#include "Obiekty.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-5,5,-5,5,-5,5,-1));        //nie dziala dla ref_time_ms dodatnich
    Dron dron;
    
    dron.ustawPredkosc(8);
    dron.ustawApi(api);
    dron.Rysuj();

    do{

    }while(std::cin.get()!='\n');

    dron.plynDoPrzodu(2);

    do{

    }while(std::cin.get()!='\n');

    dron.obroc(30, OX);

    do{

    }while(std::cin.get()!='\n');

    dron.plynDoPrzodu(2,90);

    do{

    }while(std::cin.get()!='\n');

return 0;
}
