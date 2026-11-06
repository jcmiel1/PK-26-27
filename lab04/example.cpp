#include <iostream>

using namespace std;

// używając pętli for napisz odliczanie od zera do zadanej przez użytkownika wartości
//0, 1, 2, 3, 4, 5! dla N == 5
// to samo, ale od zadanej wartości odliczanie w dół (wartości w obu przypadkach wczytujemy z konsoli)
// 5, 4, 3, 2, 1, 0!

// wartość od zera co drugą, do zadanej przez użytkownika, np.:
// N = 8
// 0, 2, 4, 6, 8



int main() {
    int n;
    int wynik;

    cout<< "Podaj liczbę";
    cin>> n;
 
    for (int i = 0; i <= n; i++) {
        cout << i << " ";
    }

    cout << endl;

    for (int j = n; j >= 0; j--) {
        cout << j << " ";
    }
    cout << endl;
    for (int i=0 ; i<=n ; i=i+2){
        cout << i << " ";
    }


// poruszanie się po szachownicy / konsoli w przestrzeni 2D
    
    int wiersze, kolumny, nr_komorki = 1;

    cin >> wiersze >> kolumny;

    for(int w = 0; w < wiersze; w++) {

        for (int k = 0; k < kolumny; k++){
            cout << nr_komorki << " ";
            nr_komorki++;
        }
        cout << endl;

    }


    return 0;
}