#include<fstream>
#include "obiekty.hh"

std::istream& operator >> (std::istream &Str, Lamana &Przykladowa){
    
    Str.clear();
    Wektor3D Wek;
    /*
    for( int i=0; i<4 && Str.good(); i++)
    {
        if(!(Str >> Wek)){Str.setstate(std::ios::failbit);}
        else Przykladowa.DajWektor().push_back(Wek);
    }
    */
   char c;
   
   do
   {    
        if(!(Str >> Wek)){Str.setstate(std::ios::failbit);}
        else Przykladowa.DajWektor().push_back(Wek);
        Str.get(c);
        if(c!='#') Str.unget();
        
   }while (Str.good() && c!='#');

    return Str;
}

std::ostream& operator << (std::ostream &Str, Lamana &Przykladowa){

    for(Wektor3D& Wsp : Przykladowa.WezWektor()){
        Str << Wsp;
        
    }

    
    return Str;
}

std::istream& operator >> (std::istream &Str, ObiektRysowalny &Przykladowy){

    char c;
    Str.clear();
    while( !Str.eof() && Str.good())
    {   Lamana Lam;



        if(Str >> Lam){Przykladowy.DajLamana().push_back(Lam);}
    }
    
    return Str; 
}

std::ostream& operator << (std::ostream &Str, ObiektRysowalny &Przykladowy){

    for(Lamana& Wsp : Przykladowy.WezLamana()){
        Str << Wsp; 
        Str << std::endl;
    }

    return Str;
}

void Prostopadloscian::zapisz(std::ofstream plik, std::vector<Lamana> _TabLamanych){
    plik.open("prostopadloscian.dat");
    
    for(int j=0;j<6;j++){
        for(int i=0;i<4;i++){plik<<_TabLamanych[i]<<"\n";}
        plik<<"#";
    }

    plik.close();
}

Prostopadloscian::Prostopadloscian(){
    std::vector<Wektor3D> _Wiersz;

    for(int i=0;i<4;i++){
        
    }
}