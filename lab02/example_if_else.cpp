#include <iostream>

using namespace std;

int main() {
    int warunek;

    cout << "Podaj liczbe: ";
    cin >> warunek;

    // == porównuje wartości, np. warunek == 1
    // = przypisuje wartość, np. warunek = 1

    // 1. Łańcuch if / else if / else
    // Wykona się tylko jedna gałąź: pierwsza pasująca.
    if (warunek == 1) {
        cout << "Wybrano wariant 1." << endl;

        float a = 2.5f, b = 1.5f;
        cout << "Suma (float): " << a + b << endl;
    }
    else if (warunek == 2) {
        cout << "Wybrano wariant 2." << endl;

        // Możemy ponownie użyć nazw a i b.
        // To inne zmienne, należące do osobnego bloku.
        double a = 2.5, b = 1.5;
        cout << "Suma (double): " << a + b << endl;
    }
    else {
        cout << "Wybrano inna liczbe niz 1 lub 2." << endl;
    }

    // Zmienne a i b są dostępne tylko wewnątrz swoich bloków {}.
    // Tutaj nie możemy ich użyć.

    // 2. Niezależne instrukcje if
    // Każdy warunek sprawdzamy osobno.
    // Może wykonać się kilka bloków podczas jednego uruchomienia.
    if (warunek > 0) {
        cout << "Liczba jest dodatnia." << endl;
    }

    if (warunek < 0) {
        cout << "Liczba jest ujemna." << endl;
    }

    if (warunek == 0) {
        cout << "Liczba jest rowna zero." << endl;
    }

    if (warunek % 2 == 0) {
        cout << "Liczba jest parzysta." << endl;
    }

    if (warunek >= 1 && warunek <= 10) {
        cout << "Liczba nalezy do przedzialu [1, 10]." << endl;
    }

    if (warunek == 1 || warunek == 2) {
        cout << "Liczba jest rowna 1 lub 2." << endl;
    }

    return 0;
}