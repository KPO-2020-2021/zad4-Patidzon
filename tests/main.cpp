#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <size.h>
#include "vector.h"
#include "matrix.h"
#include "prostopadloscian.h"
#define SIZE 3

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("konstruktor bez parametryczny ") {
    double argumentsV1[] = {0.0, 0.0,0.0};
    
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>();
  
   
    CHECK(x == t);
}
TEST_CASE("dodawanie wektorow") {
    double argumentsV1[] = {1.0, 2.0, 1.0};
    double argumentsV2[] = {1.0, 2.0 , 1.0};
    double argumentsV3[] = {2.0, 4.0 ,2.0};
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>(argumentsV2);
   Vector<SIZE> y=Vector<SIZE>(argumentsV3);
   Vector<SIZE> a=x+t;
    CHECK(a == y);
}

TEST_CASE("odejmowanie wektorow") {
    double argumentsV1[] = {2.0, 3.0 ,2.0};
    double argumentsV2[] = {1.0, 2.0 ,1.0};
    double argumentsV3[] = {1.0, 1.0, 1.0};
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>(argumentsV2);
   Vector<SIZE> y=Vector<SIZE>(argumentsV3);
   Vector<SIZE> a=x-t;
    CHECK(a == y);
}
TEST_CASE("dodawanie wektorow zaokraglanie") {
    double argumentsV1[] = {1.0, 2.0,1.0};
    double argumentsV2[] = {1.0, 2.0,1.0};
    double argumentsV3[] = {1.999999, 4.0,2.0};
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>(argumentsV2);
   Vector<SIZE> y=Vector<SIZE>(argumentsV3);
   Vector<SIZE> a=x+t;
   WARN_THROWS(a == y);
}
TEST_CASE("Mnozenie wektorow przez liczbe") {
    double argumentsV1[] = {1.0, 2.0, 1.0};
    double argumentsV2[] = {2.0, 4.0 ,2.0};
   
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>(argumentsV2);
  
   Vector<SIZE> a=x*2;
  CHECK(a == t);
}
TEST_CASE("Operator indeksowania wektora") {
    double argumentsV1[] = {1.0, 2.0,3.0};
    double a;
   
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   
  a=x[2];
  //b=x[3];
  CHECK(a == 3 );
}
TEST_CASE("konstruktor parametryczny wektora") {
    double argumentsV1[] = {1.0, 2.0 ,3.0};
    
   
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   
std::ostringstream out ;
out << x;
std::cout << out.str() << std::endl;
CHECK( "1 2.0000000000 3.0000000000 "== out.str() );
}
TEST_CASE("konstruktor bezparametryczny macierzy") {
  Matrix<SIZE> macierz=Matrix<SIZE>();
 double i ;
 i=macierz(1,1);
    
   

CHECK( i== 0 );
}
TEST_CASE("mnozenie wektora przez macierz") {
  
  Matrix<SIZE> macierz=Matrix<SIZE>('x',90);
    double argumentsV1[] = {1.0, 2.0,1.0};
    double argumentsV2[] = {1, -1,2};
    Vector<SIZE> odpowiedz=Vector<SIZE>(argumentsV2);
Vector<SIZE> wek=Vector<SIZE>(argumentsV1);
Vector<SIZE> wynik=macierz*wek;
    
   

CHECK( wynik== odpowiedz );
}
/*TEST_CASE("mnozenie macierzy przez macierz") {
  
  Matrix<SIZE> macierz1=Matrix<SIZE>('x',90);
    Matrix<SIZE> macierz2=Matrix<SIZE>('y',90);
    double argumentsV1[][SIZE] = {{0.0, 0.0,1},{1.0, 0.0,0},{0,1,0}};
    

Matrix<SIZE> wynik=Matrix<SIZE>(argumentsV1);
Matrix<SIZE> odpowiedz=macierz1*macierz2;
    
   Matrix<SIZE> odpowiedz=Matrix<SIZE>();
    Matrix<SIZE> wynik=Matrix<SIZE>();

CHECK( odpowiedz==wynik);
}*/
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
