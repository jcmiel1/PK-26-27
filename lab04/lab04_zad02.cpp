#include<iostream>

using namespace std;

int main() {

    int wiersze, kolumny, nr_komorki = 1;

    cin >> wiersze >> kolumny;

    for(int w = 0; w < wiersze; w++) {

        for (int k = 0; k < kolumny; k++){
            int sum = w + k;
            if (sum % 2 == 0) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;

    }

    return 0;
}