#include <iostream>
using namespace std;

/* =======================
   1. TABLICE STATYCZNE 1D
   ======================= */

   // Funkcja przyjmuje statyczną tablicę 1D i jej rozmiar
void printStatic1D(int arr[], int size) {
    cout << "Static 1D array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// NOWA: Funkcja, która MODYFIKUJE tablicę statyczną 1D
// (np. mnoży każdy element razy 10)
void modifyStatic1D(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 10;
    }
}

// Funkcja „zwraca” wskaźnik do statycznej tablicy 1D
// Uwaga: tablica jest static wewnątrz funkcji, więc żyje
// przez cały czas działania programu.
int* createStatic1D() {
    static int arr[5]; // [0..4]

    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;  // 10, 20, 30, 40, 50
    }

    return arr; // zwracamy adres arr[0]
}


/* =======================
   2. TABLICE STATYCZNE 2D
   ======================= */

   // Funkcja przyjmuje statyczną tablicę 2D o znanej liczbie kolumn (3)
void printStatic2D(int arr[][3], int rows, int cols) {
    cout << "Static 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// NOWA: Funkcja, która MODYFIKUJE statyczną tablicę 2D
// (np. dodaje 100 do każdego elementu)
void modifyStatic2D(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] += 100;
        }
    }
}

// Funkcja „zwraca” wskaźnik do statycznej tablicy 2D 2x3
// Typ zwracany: wskaźnik na tablicę 3 intów: int (*)[3]
int (*createStatic2D())[3] {
    static int arr[2][3]; // 2 wiersze, 3 kolumny

    int value = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = value++;  // 1..6
        }
    }

    return arr; // zwracamy adres „pierwszego wiersza”
}


/* =======================
   3. TABLICE DYNAMICZNE 1D
   ======================= */

   // Tworzenie dynamicznej tablicy 1D
int* createDynamic1D(int size) {
    int* arr = new int[size]; // alokacja

    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1);    // 1, 2, 3, ...
    }

    return arr;  // zwracamy wskaźnik
}

// Wypisywanie dynamicznej tablicy 1D
void printDynamic1D(int* arr, int size) {
    cout << "Dynamic 1D array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Zwolnienie pamięci tablicy dynamicznej 1D
void deleteDynamic1D(int* arr) {
    delete[] arr;
}


/* =======================
   4. TABLICE DYNAMICZNE 2D (int**)
   ======================= */

   // Tworzenie dynamicznej tablicy 2D (rows x cols)
int** createDynamic2D(int rows, int cols) {
    int** arr = new int* [rows];   // tablica wskaźników - wiersze
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];   // osobna tablica dla każdej kolumny
    }

    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++;  // wypełniamy 1,2,3,...
        }
    }

    return arr;
}

// Wypisywanie dynamicznej tablicy 2D
void printDynamic2D(int** arr, int rows, int cols) {
    cout << "Dynamic 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Zwolnienie pamięci dynamicznej tablicy 2D
void deleteDynamic2D(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  // najpierw wiersze
    }
    delete[] arr;         // potem tablica wskaźników
}


/* =======================
   5. FUNKCJA main – DEMONSTRATOR
   ======================= */

int main() {

    // --- 1. Tablica statyczna 1D ---
    cout << "=== Statyczna tablica 1D ===" << endl;

    int staticArr1D[5] = { 1, 2, 3, 4, 5 };  // zwykla statyczna tablica

    cout << "Przed modifyStatic1D: ";
    printStatic1D(staticArr1D, 5);           // przekazanie do funkcji (tylko wypisanie)

    modifyStatic1D(staticArr1D, 5);          // MODYFIKACJA tablicy w funkcji

    cout << "Po modifyStatic1D:    ";
    printStatic1D(staticArr1D, 5);           // widać zmiany

    cout << endl << "Tablica zwrócona z createStatic1D:" << endl;
    int* staticReturned1D = createStatic1D(); // „zwrócona” tablica statyczna (wskaźnik)
    printStatic1D(staticReturned1D, 5);


    // --- 2. Tablica statyczna 2D ---
    cout << endl << "=== Statyczna tablica 2D ===" << endl;

    int staticArr2D[2][3] = { {10, 20, 30}, {40, 50, 60} };

    cout << "Przed modifyStatic2D:" << endl;
    printStatic2D(staticArr2D, 2, 3);         // przekazanie do funkcji (wypisanie)

    modifyStatic2D(staticArr2D, 2, 3);        // MODYFIKACJA tablicy w funkcji

    cout << "Po modifyStatic2D:" << endl;
    printStatic2D(staticArr2D, 2, 3);         // zmieniona w main, bo funkcja działa na oryginale

    cout << endl << "Tablica zwrócona z createStatic2D:" << endl;
    int (*staticReturned2D)[3] = createStatic2D(); // „zwrócona” tablica 2D
    printStatic2D(staticReturned2D, 2, 3);


    // --- 3. Tablica dynamiczna 1D ---
    cout << endl << "=== Dynamiczna tablica 1D ===" << endl;

    int size1D = 4;
    int* dynArr1D = createDynamic1D(size1D);   // tworzenie (zwrócona tablica 1D)
    printDynamic1D(dynArr1D, size1D);          // przekazanie do funkcji
    deleteDynamic1D(dynArr1D);                 // zwolnienie pamięci


    // --- 4. Tablica dynamiczna 2D ---
    cout << endl << "=== Dynamiczna tablica 2D ===" << endl;

    int rows = 3, cols = 4;
    int** dynArr2D = createDynamic2D(rows, cols);  // tworzenie (zwrócona tablica 2D)
    printDynamic2D(dynArr2D, rows, cols);          // przekazanie do funkcji
    deleteDynamic2D(dynArr2D, rows);               // zwolnienie pamięci

    return 0;
}
