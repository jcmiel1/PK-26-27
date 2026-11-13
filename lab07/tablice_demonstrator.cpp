// ConsoleApplication44.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iomanip>

using namespace std;


// funkcja od wyświetlania tab1D

void wyswietl1D(int tab[], int r) {

	// wyswietlenie
	for (int i = 0; i < r; i++) {
		cout << tab[i] << " " << endl;
	}
}

void wczytaj_oceny(int tab[], int r) {

	int pkt;

	for (int i = r - 1; i >= 0; i--) {
		cin >> pkt;
		tab[i] = pkt;
	}
}

float srednia(int tab[], int r) {

	int suma = 0;
	// pobranie danych z tab (sumowania)
	for (int i = 0; i < r; i++) {
		suma = suma + tab[i];					// suma += tab1[i];				
	}

	// obliczenie sredniej i wyswietlenie
	float srednia = suma / r;
	cout << fixed << setprecision(2) << srednia << endl;

	return srednia;

}

void wyswietl_2d (int arr[][5], int wiersze, int kolumny) {

	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			cout << arr[i][j] << " ";
		}
	}
}



// Tworzenie dynamicznej tablicy 1D
int* createDynamic1D(int size) {
	int* arr = new int[size]; // alokacja

	for (int i = 0; i < size; i++) {
		arr[i] = (i + 1);    // 1, 2, 3, ...
	}

	return arr;  // zwracamy wskaźnik
}

int main()
{
	// srednia = suma / ilosc
	float srednia_zw;
	int suma = 0, il_ocen;
	const int rozmiar = 5;
	const int w = 5;
	const int k = 5;

	int tab1[rozmiar] = { 0 };
	int tab2d[w][k] = { 0 };


	cout << "Podaj ilosc ocen";
	cin >> il_ocen;
	int* wsk = createDynamic1D(il_ocen);
	cout << wsk[1];

	/*
	wyswietl1D(tab1, rozmiar);
	cout << endl;
	cout << "---------------------------";

	// wczytanie
	wczytaj_oceny(tab1, rozmiar);

	// wyswietlenie
	wyswietl1D(tab1, rozmiar);
	cout << endl;
	cout << "---------------------------";

	srednia_zw = srednia(tab1, rozmiar);

	// --------------------------- tablice 2D ---------------------------

	// wyswietl 2D
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			cout << tab2d[i][j] << " ";
		}
		cout << endl;
	}

	// ustawienie przekatnej
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			if (i == j)
				tab2d[i][j] = 1;
		}
	}
	cout << endl;
	// wyswietl 2D
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			cout << tab2d[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}

