#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include <iostream>
#include "SWektor.hh"

template <typename STyp, int SWymiar>
class SMacierz 
{
  protected:
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
    const SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &We)const;
    const SMacierz<STyp, SWymiar> operator *(const SMacierz<STyp, SWymiar> &W)const;
    const SMacierz<STyp,SWymiar> operator *(const STyp l)const;
    /*
    * funkcja zwracajaca wyznacznik macierzy 
    */
    const double wyznacznik()const;
    /*
    * metoda zamieniajaca wybrana z kolumn macierzy na podany wektor
    */
    SMacierz<STyp,SWymiar> podstawKolumne(SWektor<STyp,SWymiar> We, int numerKolumny);
    /*
    * metoda - transpozycja macierzy
    */
    SMacierz<STyp,SWymiar> transpozycja();
    double dopelnienieAlgebraiczne(int i, int j) const;
    const SMacierz<STyp,SWymiar> macierzDopelnien() const;
    const SMacierz<STyp,SWymiar> odwrotnosc() const;
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
const SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator*(const SWektor<STyp,SWymiar> &We)const{
    SWektor<STyp,SWymiar> wynik;
    for(int i=0; i<SWymiar; i++){
        for(int j=0; j<SWymiar; j++){
            wynik[i]=tab[j][i]*We[j]+wynik[i];
        }
    }
    return wynik;
}

template<class STyp, int SWymiar>
const SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator *(const SMacierz<STyp,SWymiar> &W)const
{
    SMacierz<STyp,SWymiar> tmp;
    STyp tmp2;
    tmp2 = 0;
    for(int i=0;i<SWymiar;i++)
    {
        for(int j=0; j<SWymiar;j++)
        {
            for(int k=0;k<SWymiar;k++)
            {
                tmp2=tmp2+this->tab[j][k]*W[k][i];
            }
            tmp[j][i] = tmp2;
            tmp2 = 0;
            //tmp[i][j] = this->tab[j][0]*W[0][i]+this->tab[j][1]*W[1][i]+this->tab[j][2]*W[2][i];
        }
    }
    return tmp;
}

template<class STyp, int SWymiar>
const SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator *(const STyp l)const{
    SMacierz<STyp,SWymiar> tmp;
    for(int i=0;i<SWymiar;i++)
    {
        for(int j=0;j<SWymiar;j++)
        {
            tmp[i][j]=this->tab[i][j]*l;
        }
    }
    return tmp;
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
const double SMacierz<STyp,SWymiar>::wyznacznik()const{
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

template<class STyp, int SWymiar>
double SMacierz<STyp,SWymiar>::dopelnienieAlgebraiczne(int i, int j) const{
    SMacierz<STyp,SWymiar-1> macierz;
    int a=0,b=0;
    for(int k=0;k<SWymiar-1;k++)
    {
        if(k==i)
            a=1;
        for(int l=0;l<SWymiar-1;l++)
        {
            if(l==j)
                b=1;
            macierz[l][k]=this->tab[k+a][l+b];
        }
        b=0;
    }
    if((i+j)%2==0)
        return macierz.wyznacznik();
    else
        return macierz.wyznacznik()*(-1);
}

template<class STyp, int SWymiar>
const SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::macierzDopelnien() const{
    SMacierz<STyp,SWymiar> tmp;
    for(int i=0;i<SWymiar;i++)
    {
        for(int j=0;j<SWymiar;j++)
        {
            tmp[i][j]=dopelnienieAlgebraiczne(i,j);
        }
    }
    return tmp;
}

template<class STyp, int SWymiar>
const SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::odwrotnosc() const{
    SMacierz<STyp,SWymiar> tmp;
    tmp=this->macierzDopelnien();
    tmp.transpozycja();
    tmp=tmp*(1/this->wyznacznik());
    return tmp;
}


#endif