
#include "vector.h"
#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <size.h>
#define LICZBAPUNKTOW 10
#define SIZE 3
/*!
 * \file prostopadloscian.h
 * \brief Plik zawiera definicje klasy prostokat
 *
 */
/*!
 *  \brief definicja klasy prostokat
 *
 *  Sa w niej zapisane wartosci wspolrzednych poszczegolnych wierzcholkow
 *  
 */
class Prostopadloscian {
 
  Vector<SIZE> wierzcholki[LICZBAPUNKTOW]; //tablica wektorow z wspolrzednymi wierzcholkow
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
  Prostopadloscian();// konstruktor bez parametryczny pobiera wspolrzedne z pliku
   void wczytajwsp ();//wczytaj wspolrzedne z pliku do tablicy
  void zapiszwsp ();// zapisuje wspolrzedne z tablicy do pliku
  void obroc(Matrix<SIZE> macierz,int liczbaobrt);// obraca Prostopadloscian n-razy o dany kat
  void przesun(Vector<SIZE> wek);// przesuwa Prostopadloscian o dany wektor
  std::ostream& operator << ( std::ostream  &Strm)const;//wypisuje wspolrzedne Prostopadlosciana na podane wyjscie
  void obliczboki(std::ostream &strm);//oblicza dlugosci bokow i porownuje ich dlugosci
  bool operator == (Prostopadloscian &Pr);//operator porownania Prostopadloscianow
  ~Prostopadloscian(){std::cout<<"Koniec"<<std::endl;};//destruktor
  
};

/*!
*****************************************************************************
 |  \brief Konstruktor klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartosciami z pliku .                                       |
 */
Prostopadloscian::Prostopadloscian(){
wczytajwsp();

}

/*!
*****************************************************************************
 | \brief Metoda klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartosciami z pliku .                                       |
 */
 void Prostopadloscian::wczytajwsp (){
   int i;
std::fstream plik;
plik.open("../datasets/prostopadloscian.dat",std::ios::in);
if (plik.good()==true)
{
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       
       plik>>wierzcholki[i];
       
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
}


/*!
*****************************************************************************
 | \brief Metoda klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |      zapisuje do pliku wartosci z macierzy .                                       |
 */
void Prostopadloscian::zapiszwsp (){

int i;
std::ofstream plik;
plik.open("../datasets/prostopadloscian.dat",std::ios::out);
if (plik.good()==true)
{
for ( i = 0; i <LICZBAPUNKTOW; i++)
     {
       
       plik<<wierzcholki[i]<<std::endl;
      i++;
       plik<<wierzcholki[i]<<std::endl<<std::endl;
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
  }


  /*!
  *****************************************************************************
 | \brief Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 */
std::ostream& Prostopadloscian::operator << ( std::ostream  &Strm)const
{
  int i;
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       
       Strm<<wierzcholki[i]<<std::endl;
       
       
     }

return Strm;


}    

/*!
*****************************************************************************
 | \brief Metoda klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |      zapisuje do pliku wartosci z macierzy .                                       |
 */
void Prostopadloscian::obliczboki(std::ostream  &Strm){
  int i;
  double dlugosci[12];

  Vector<SIZE> tmp;
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       tmp=wierzcholki[i]-wierzcholki[i+1];
       dlugosci[i]=tmp.dlugosc();

       Strm<<"dlugosc boku "<<i+1<<" jest rowna"<<dlugosci[i]<<std::endl;
       
     }
     
     for ( i = 0; i < 2; i++)
     {
     if (std::abs(dlugosci[i]-dlugosci[i+2])<MINDIF)
     {
       Strm<<"boki "<<i+1<<" i "<<i+3<<" sa rowne"<<std::endl;
     }
     else
     {
       Strm<<"boki "<<i+1<<" i "<<i+3<<" sa rozne"<<std::endl;
     }
     
}}

/*!
*****************************************************************************
 | \brief Metoda klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |     kat-kat o ktory wykona sie obrot(w stopniach)      |
  | liczbaobrt-liczba obrotow                                             |
 |      Obraca Prostopadloscian o kat.                                       |
 */
void Prostopadloscian::obroc(Matrix<SIZE> macierz,int liczbaobrt){
  int i,j=0;

  while (j<liczbaobrt)
  {
    
  
  
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       
       wierzcholki[i]=macierz*wierzcholki[i];
       
       
     }
j++;
  }
     zapiszwsp();

}




/*!
*****************************************************************************
 | \brief Metoda klasy Prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |     wek-wektor przesuniecia     |
 |      przesuwa Prostopadloscian o kat.                                       |
 */
void Prostopadloscian::przesun(Vector<SIZE> wek){

  int i;

 
  
  
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       
       wierzcholki[i]+wek;
      
       
     }

  
     zapiszwsp();

}
  /*!
  *****************************************************************************
 | \brief Przeciazenie operatora ==                                                 |
 |  Argumenty:                                                                |
 |      Pr - Prostopadloscian.                                                         |
 */
bool Prostopadloscian::operator == (Prostopadloscian &Pr){
int i;
    Vector<SIZE> tmp;
    double dlugosci[4];
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       tmp=wierzcholki[i]-Pr.wierzcholki[i];
       dlugosci[i]=tmp.dlugosc();}
if ((dlugosci[0] <= MINDIF) && ( dlugosci[1]<= MINDIF)&& ( dlugosci[2]<= MINDIF)&& ( dlugosci[3]<= MINDIF)) {
    return true;
  }
  else {
    return false;
  }


}