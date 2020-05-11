#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include <iostream>
#include "SWektor.hh"

template <typename STyp, int SWymiar>
class SMacierz 
{
  /*
  * tablica wektorow o rozmiarze ROZMIAR
  */
  SWektor<STyp,SWymiar> tab[SWymiar];

  public:
    /*
    * inicjalizacja macierzy
    */
    SMacierz();

    SWektor<STyp,SWymiar> operator [] (int Ind) const {return tab[Ind];}
    SWektor<STyp,SWymiar>& operator [] (int Ind) {return tab[Ind];}
    /*
    *  przeciazenie operatora mnozenia dla operacji macierz*wektor, zwracajaca wektor 
    */
    SWektor<STyp,SWymiar> operator * (SWektor<STyp,SWymiar> We);
    /*
    * funkcja zwracajaca wyznacznik macierzy 
    */
    STyp wyznacznik();
    /*
    * metoda zamieniajaca wybrana z kolumn macierzy na podany wektor
    */
    SMacierz<STyp,SWymiar> podstawKolumne(SWektor<STyp,SWymiar> We, int numerKolumny);
    /*
    * metoda - transpozycja macierzy
    */
    SMacierz<STyp,SWymiar> transpozycja();
};

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar>::SMacierz()
{
        for(int i=0;i<SWymiar;i++){
            for(int j=0;j<SWymiar;j++){
                tab[i][j]=0;
            }
        }
    }

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> We){
    SWektor<STyp,SWymiar> wynik;
    for(int i=0; i<SWymiar; i++){
        for(int j=0; j<SWymiar; j++){
            wynik[i]=tab[j][i]*We[j]+wynik[i];
        }
    }
    return wynik;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac)
{   Strm.clear();
    for(int i=0;i<SWymiar;i++){
        if(!(Strm >> Mac[i])) Strm.setstate(std::ios::failbit);
    }
    return Strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp,SWymiar> &Mac)
{
    for (int i=0;i<SWymiar;i++){
        std::cout << Mac[i] << std::endl;
    }
    return Strm;
}

template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::wyznacznik(){
     double det;
     SMacierz<STyp,SWymiar> Ma;
     for(int i=0; i<SWymiar; i++){
         for(int j=0; j<SWymiar; j++){
             Ma[i][j]=tab[i][j];
         }
     }
  for(int i=0;i<SWymiar-1;i++)

    for(int j=i+1;j<SWymiar;j++)

      for(int k=i+1;k<SWymiar;k++)

        Ma[j][k]-= Ma[j][i] / Ma[i][i] * Ma[i][k];



  det=1;

    for(int i=0;i<SWymiar;i++) det *= Ma[i][i];

    return det;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::podstawKolumne(SWektor<STyp,SWymiar> We, int numerKolumny){
    for (int i=0; i<SWymiar; i++){
        tab[numerKolumny][i]=We[i];
    }
    return *this;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::transpozycja(){
    STyp temp;
    for(int i=0;i<SWymiar;i++){
        for(int j=0;j<i;j++){
            temp=tab[i][j];
            tab[i][j]=tab[j][i];
            tab[j][i]=temp;
        }
    }
    return *this;
}

#endif