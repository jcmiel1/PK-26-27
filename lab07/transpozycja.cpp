// ConsoleApplication49.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

// na podstawie pliku tablice statyczne i dynamiczne stwórz dwie tablice dynamiczne A i B, odpowiednio o wymiarach M x N i N x M
// rozpisz sobie ręcznie tablicę A na kartce, wypełnioną kolejnymi wartościami; następnie samodzielnie transponuj ją na kartce
// do danych wartości dopisz sobie ołówkiem indeksy (współrzędne)... w jakich wsp. jest np.: wartość 3 w tablicy A, a w jakich jest w tablicy B?
// zrób to dla kilku wartości. Powinieneś zauważyć pewną zależność...
// jeśli zauważyłeś - gratulacje, masz rozwiązane zadanie.

// napisz funkcję, do transpozycji macierzy. Funkcja ma przyjmować 4 argumenty, dwie macierze dynamicznie utworzone w main i rozmiar M i N.
// jesli chcesz mozesz dopisac funckje, ktora bedzie uzupelniac macierz A i funkcje ktora bedzie wyswietlac przekazana w parametrze macierz

// do drukowania wartosci na "polu o szerokości 6" służy funkcja setw(szerokosc) -> czyli setw(6)


int main()
{
    // wczytanie wymiarów M N

    // alokacja pamięci dla tablicy M x N
    // A: m x n
    int** A = new int* [m];
    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }


    // alokacja pamięci dla tablicy N x M
    // B: n x m
    int** B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[m];
    }

    // wywołaj odpowiednie funkcje

    // pamiętaj o zwolnieniu pamięci (patrz plik macierze dynamiczne i statyczne.cpp - delete[])

    return 0;
}


