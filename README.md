
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp # etc.
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    test_Wektor2D.cpp
    test_Macierz2x2.cpp
    test_Prostokat.cpp # etc.
) 
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

Wazne informacje 

1. nie udalo mi sie zaimplemetowac liczenia dlugosci bokow( zabraklo mi czasu na sprawdzenie zaleznosci polozenia poszczegolnych punktow ) 
2. Nie zaimplemetowalem sceny bo w sumie nie byla mi potrzebna, a zabraklo mi czasu na implementowanie jej dla zasady.
3. dokumentacja wygenerowana z doxywizarda znajduje sie w folderze doc/html
4. Program kompiluje sie i dziala poprawnie 
5  nie udalo mi sie zaimplemetowac  Testu mnozenia macierzy przez macierz ze wzgledu na blad pojawiajacy sie przez uzycie operatora == mimo ze w samym kodzie nie wywolywal bledow
6 Udalo mi sie odkryc przyczyne segmentation fall(pojawiajacego sie na zakonczenie programu) z poprzedniego zadania wynikal on z niedostosowania rozmiaru tablicy klasy prostokat (nalezy zwiekszyc jej rozmiar o jeden oraz dokonac zmiany w metodach tej funkcji w petlach for (zamienic=< na <))
