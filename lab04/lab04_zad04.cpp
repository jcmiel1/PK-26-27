#include<iostream>

using namespace std;

int main() {

    int wysokosc, il_spacji, il_gwiazdek = 1;
    cin >> wysokosc;

    il_spacji = wysokosc - 1;

    for (int w = 0; w < wysokosc; w++) {

        for (int s = 0; s < il_spacji; s++  ) {
            cout << " ";
        }
        for (int g = 0; g < il_gwiazdek; g++) {
            cout << "*";
        }
        cout << endl;
        il_gwiazdek+=2;
        il_spacji--;
    }

    return 0;
}