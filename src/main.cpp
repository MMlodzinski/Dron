#include <iostream>
#include "Obiekty.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

//main tylko do testowania na razie
int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-5,5,-5,5,-5,5,-1));        //nie dziala dla ref_time_ms dodatnich
    Dron dron;
    Dno dno;
    PowierzchniaWody woda;
    
    dron.ustawPredkosc(8);
    dron.ustawApi(api);
    dron.Rysuj();
    dno.ustawApi(api);
    dno.Rysuj();
    woda.ustawApi(api);
    woda.Rysuj();

    do{

    }while(std::cin.get()!='\n');

    dron.plynDoPrzodu(2);

    do{

    }while(std::cin.get()!='\n');

    dron.obroc(180, OZ);

    do{

    }while(std::cin.get()!='\n');

    dron.plynDoPrzodu(2,40);

    do{

    }while(std::cin.get()!='\n');

return 0;
}
