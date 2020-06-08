#include <iostream>
#include "Obiekty.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"

using std::vector;
using std::cout;
using std::cin;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-10,10,-10,10,-10,10,-1));        //nie dziala dla ref_time_ms dodatnich
    std::vector<std::shared_ptr<Dron>> kolekcjaDronow;
    std::vector<std::shared_ptr<InterfejsPrzeszkody>> kolekcjaPrzeszkod;
    Dno dno;
    PowierzchniaWody woda;
    std::shared_ptr<Dron> dron(new Dron);
    char w1;
    double w2, w3;
    std::shared_ptr<Dron> dronTmp;
    std::shared_ptr<PrzeszkodaProst> tmp;
    Zliczanie zliczanie;

    dron->ustawPredkosc(2);
    dron->ustawApi(api);
    dron->zmienKolor("green");
    dron->Rysuj();

    dno.ustawApi(api);
    dno.zmienKolor("yellow");
    dno.Rysuj();

    woda.ustawApi(api);
    woda.zmienKolor("blue");
    woda.Rysuj();

    for(int i=0;i<3;i++){
        kolekcjaDronow.push_back(std::shared_ptr<Dron>(new Dron));
        kolekcjaDronow[i]->ustawApi(api);
        kolekcjaDronow[i]->ustawPredkosc(2);
        kolekcjaDronow[i]->Rysuj();
    }

    for(int i=0;i<3;i++){
        tmp = std::shared_ptr<PrzeszkodaProst>(new PrzeszkodaProst(i+1,i+2,i+1));
        tmp->ustawApi(api);
        tmp->Rysuj();
        kolekcjaPrzeszkod.push_back(tmp);
    }
//na razie wszystko pojawia się na środku
    do{
        cout<<"Wybierz akcję:";
        cout<<"p - plyn do przodu pod zadanym kątem\n";
        cout<<"o - obróć w miejscu o zadany kąt\n";
        cout<<"b - ilość brył\n";
        cout<<"z - zmiana drona\n";
        cout<<"q - zakończ\n";


        cin>>w1;

        switch(w1)
        {
            case 'p':
            cout<<"Podaj odległość\n";
            cin>>w2;
            cout<<"Podaj kąt pochylenia\n";
            cin>>w3;
            dron->plynDoPrzodu(w2,w3);
            for(int i=0;i<3;i++){
                if(kolekcjaDronow[i]->czyKolizja(dron)){
                    cout<<"Kolizja\n";
                }
                if(kolekcjaPrzeszkod[i]->czyKolizja(dron)){
                    cout<<"Kolizja\n";
                }
            }
            break;

            case 'o':
            cout<<"Podaj kąt obrotu\n";
            cin>>w2;
            dron->obroc(w2, OZ);
            break;

           case 'b':
            zliczanie.wypisz();

            break;

            case 'z':
            cout<<"Na ktorego drona zmienic (podaj numer)\n";
            cin>>w2;
            dronTmp = dron;
            dron = kolekcjaDronow[w2];
            kolekcjaDronow[w2] = dronTmp;
            dron->zmienKolor("green");
            dron->Rysuj();
            kolekcjaDronow[w2]->zmienKolor("black");
            kolekcjaDronow[w2]->Rysuj();
            break;

            case 'q':
            break;

            default:
            cout<<"Nie rozpoznano znaku, spróbuj jeszcze raz\n\n";
            break;
        }
    }while(w1!='q');

return 0;
}
