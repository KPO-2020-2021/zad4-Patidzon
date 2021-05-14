// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>

#include "exampleConfig.h"
#include "example.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "lacze_do_gnuplota.hh"
/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  Prostopadloscian Pr=Prostopadloscian();
  int liczbaobrt;
  double kat ;
  char os ,z='a';
  Vector<SIZE> przesuniecie=Vector<SIZE>();
  Matrix<SIZE> macierz=Matrix<SIZE>(), macierztmp=Matrix<SIZE>();


  
    /*Matrix<SIZE> macierz1=Matrix<SIZE>('x',90);
    double argumentsV1[] = {1.0, 2.0,1.0};
    Vector<SIZE> wek=Vector<SIZE>(argumentsV1);
    Vector<SIZE> wynik=macierz1*wek;
    std::cout<<wynik;
*/

  /*std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
  std::system("cat ../LICENSE");
  double argumentsV[] = {1.0, 2.0,3.0};
Vector<3> V1={argumentsV};
std::cout<<V1<<std::endl;
Pr<<std::cout;*/
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-500,500);
    Lacze.UstawZakresX(-500,500);
      Lacze.UstawZakresZ(-500,500);
  //Lacze.UstawZakresX(-155,155);
  //Lacze.UstawZakresZ(-155,155);
 /* Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(10000,'\n');*/
  Lacze.Rysuj();
  while (z!='k')
{std::cout<<"o obroc o kat"<<std::endl
<<"r obroc o poprzedni kat"<<std::endl
<<"s obroc o sekwencje katów"<<std::endl
<<"p przesun o podany wektor"<<std::endl
<<"w wypisz wspolrzedne"<<std::endl
<<"k koniec"<<std::endl
<<"m wypisz macierz obrotu"<<std::endl;
  std::cin>>z;
  switch (z)
  {
  case 'o':
Pr.wczytajwsp();
    std::cout<<"podaj kat obrotu w stopniach, os obrotu(x ,y,z) i liczbe obrotow"<<std::endl;
std::cin>>kat;
std::cin>>os;
std::cin>>liczbaobrt;
std::cout<<"kat obrotu to "<<kat<<" a liczba obrotow to "<<liczbaobrt<<std::endl;
macierz.zaladuj(os,kat);
Pr.obroc(macierz,liczbaobrt);
Lacze.Rysuj();
    break;
    case 'p':
Pr.wczytajwsp();
    std::cout<<"podaj wektor przesuniecia"<<std::endl;
std::cin>>przesuniecie;

std::cout<<"wektor przesuniecia to "<<przesuniecie<<std::endl;
Pr.przesun(przesuniecie);
Lacze.Rysuj();
    break;
    case 'w':
Pr.wczytajwsp();
std::cout<<"wspolrzedne to"<<std::endl;
 Pr<<std::cout;
 std::cout<<std::endl;
 //Pr.obliczboki(std::cout); Nie dziala
 std::cout<<std::endl;
    break;
  case 'm' :
std::cout<<macierz;
break;
  case 'r':
Pr.wczytajwsp();

Pr.obroc(macierz,liczbaobrt);
Lacze.Rysuj();
    break;
      case 's':
      std::cout<<"wpisuj wartosci w postaci <os> <kat>"<<std::endl 
      <<"po wpisaniu co najmniej 1 wartosci wpisz (duze)V i dowolna wartosc kata aby zakonczyc "<<std::endl;
      std::cin>>os>>kat;
      std::cout<<os<<" "<<kat<<std::endl;
      macierz.zaladuj(os,kat);
      while (os!='V')
      {
         std::cin>>os>>kat;
      std::cout<<os<<" "<<kat<<std::endl;
        if(os=='x'|| os=='y'|| os=='z')
        {macierztmp.zaladuj(os,kat);
        std::cout<<macierztmp<<std::endl;
        macierz=macierz*macierztmp;
         std::cout<<macierz<<std::endl;
        }
        else
        {if(os!='V')
          std::cout<<"Podano nieprawidlowa os"<<std::endl;
        }
        
      }
      std::cout<<"Podaj liczbe obrotow"<<std::endl;
      std::cin>>liczbaobrt;
      Pr.obroc(macierz,liczbaobrt);
      Lacze.Rysuj();
//Pr.wczytajwsp();
//macierz.zaladuj(kat)
//Pr.obroc(macierz,liczbaobrt);
//Lacze.Rysuj();
    break;
  default:
  if (z!='k')
  {
    std::cout<<"nie poprawna opcja"<<std::endl;
  }
  

    break;
  }
}

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
