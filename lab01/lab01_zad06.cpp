/*
Napisz program do obliczania prostych odsetek dla
konkretnego klienta banku dla zadanej kwoty P (typ float),
okresu kredytowania T (int) oraz stopy procentowej R (float).

Wynikiem jest wartość wyrażenia:

I = (P * T * R) / 100

Wypisz wynik zarówno jako typ float, jak i typ int.
Wynik w postaci wartości rzeczywistej wyświetl
do dwóch miejsc po przecinku.

Wyjście:

P = 2500.50
T = 2
R = 3.66
Wynik rzeczywisty: 183.04
Wynik całkowity: 183
*/

#include <iostream>
#include <iomanip>

int main() {

    // Deklaracja i inicjalizacja zmiennych.
    // Dzięki inicjalizacji zmienne mają określoną wartość już od momentu utworzenia.
    float P = 0.0f;
    float R = 0.0f;
    float I = 0.0f;
    int T = 0;

    // Wczytanie wartości podanych przez użytkownika.
    // Operator >> zapisuje kolejne wartości odpowiednio do zmiennych P, T i R.
    std::cin >> P >> T >> R;

    // Obliczenie wartości prostych odsetek.
    I = (P * T * R) / 100;

    /*
    Nie używamy tutaj:

        using namespace std;

    dlatego przed elementami należącymi do standardowej przestrzeni nazw
    zapisujemy std::, np.:

        std::cout
        std::cin
        std::endl
        std::fixed
        std::setprecision
    */

    /*
    std::fixed powoduje wyświetlanie liczb rzeczywistych
    w zapisie dziesiętnym.

    std::setprecision(2) w połączeniu z std::fixed oznacza:
    wyświetlaj dwie cyfry po przecinku.

    To ustawienie pozostaje aktywne dla kolejnych liczb
    zmiennoprzecinkowych wypisywanych przez std::cout.
    Nie trzeba więc powtarzać go przy każdym cout.
    */
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "P = " << P << std::endl;
    std::cout << "T = " << T << std::endl;
    std::cout << "R = " << R << std::endl;

    std::cout << "Wynik rzeczywisty: " << I << std::endl;

    /*
    static_cast<int>(I) wykonuje konwersję wartości typu float na int.

    Część ułamkowa zostaje odrzucona, np.:

        183.04 -> 183

    Nie jest to to samo co zmiana sposobu wyświetlania
    za pomocą setprecision().
    */
    std::cout << "Wynik całkowity: "
              << static_cast<int>(I)
              << std::endl;

    return 0;
}