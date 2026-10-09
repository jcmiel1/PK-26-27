/*
Uruchom ten sam kod:

1. w GitHub Codespaces,
2. na UPEL-u w dowolnym zadaniu.

Zaobserwuj wynik działania programu.

Czy w obu środowiskach otrzymujesz ten sam rezultat?
Jeżeli nie, zastanów się, z czego może wynikać różnica.

UWAGA:
Nie próbujemy przewidzieć konkretnej wartości zmiennej `wiek`.
Celem przykładu jest pokazanie, dlaczego zmienne należy
inicjalizować przed odczytaniem ich wartości.
*/

#include <iostream>

using namespace std;

int main() {

    /*
    UWAGA: zmienna została zadeklarowana, ale NIE została zainicjalizowana.

    Podaliśmy jej typ i nazwę:

        int wiek;

    ale nie nadaliśmy jej żadnej wartości.

    Poprawna inicjalizacja mogłaby wyglądać np.:

        int wiek = 0;

    albo wartość mogłaby zostać wcześniej wczytana:

        cin >> wiek;
    */
    int wiek;

    /*
    W tym miejscu próbujemy odczytać wartość zmiennej,
    mimo że wcześniej nie nadaliśmy jej wartości.

    Taki kod jest błędny.

    Nie można zakładać, że pojawi się 0 ani żadna konkretna
    "losowa" liczba. Wynik może zależeć m.in. od kompilatora,
    ustawień kompilacji i środowiska uruchomieniowego.

    Dlatego nie należy odczytywać zmiennej lokalnej,
    zanim nie zostanie jej nadana poprawna wartość.
    */
    cout << "Twój wiek to: " << wiek << endl;

    return 0;
}