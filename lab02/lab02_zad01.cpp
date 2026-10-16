/*
Podaj znak: a
Znak: 'a'
Kod: 97 (0x61)
*/

#include <iostream>

using namespace std;


int main() {
    char znak;    // Zmienna przechowująca pojedynczy znak.
    int kod_dec;  // Zmienna przechowująca jego kod jako liczbę całkowitą.

    cout << "Podaj znak: ";
    cin >> znak;  // Wczytujemy jeden znak; białe znaki, np. spacje, są pomijane.

    // Zamieniamy wartość typu char na int.
    // Dla znaków ASCII, np. 'a', otrzymujemy kod znaku: 97.
    // To nie jest zamiana cyfry na liczbę: znak '7' ma kod 55, a nie 7.
    kod_dec = static_cast<int>(znak);

    // Apostrofy są tekstem, który wypisujemy przed znakiem i po nim.
    cout << "Znak: '" << znak << "'" << endl;

    // Najpierw wypisujemy kod dziesiętnie, np. 97.
    // hex zmienia sposób wyświetlania kolejnych liczb na szesnastkowy.
    // showbase dodaje oznaczenie podstawy, np. prefiks 0x.
    cout << "Kod: " << kod_dec << " ("
         << hex << showbase << kod_dec << ")" << endl;

    // Manipulatory nie zmieniają wartości zmiennej, tylko format wyjścia.
    // Ich ustawienia pozostają aktywne przy kolejnych operacjach cout.
    // Przywracamy zapis dziesiętny i wyłączamy oznaczenie podstawy.
    cout << dec << noshowbase;

    // Uwaga: char przechowuje jeden bajt.
    // Polskie litery w UTF-8 zajmują więcej niż jeden bajt,
    // więc ten przykład nie odczytuje ich jako całych znaków.

    return 0;
}