#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include <math.h>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &we);
    SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &we);
    SWektor<STyp,SWymiar> operator / (STyp liczba);
    STyp dlugosc();
};


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &we)
{
    SWektor<STyp,SWymiar> Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + we[Ind];
  return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &we)
{
    SWektor<STyp,SWymiar> Wynik;

    for(unsigned int Ind = 0;Ind<ROZMIAR;Ind++){
        Wynik[Ind]=we[Ind]*Wynik[Ind];
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp liczba)
{
   SWektor<STyp,SWymiar> Wynik;

    for(int Ind=0;Ind<ROZMIAR;Ind++){
        Wynik[Ind]=Wynik[Ind]/liczba;
    }
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

template <typename STyp, int SWymiar>
STyp SWektor<STyp, SWymiar>::dlugosc(){
    STyp dlugosc=0;
    for(int i=0;i<SWymiar;i++){
        dlugosc += pow(_Wsp[i], 2);
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp, SWymiar> &Wek)
{
    Strm.clear();
    for(int i=0;i<ROZMIAR;i++){
        if(!(Strm >> Wek[i])) Strm.setstate(std::ios::failbit);
    }
    return Strm;
}

#endif
