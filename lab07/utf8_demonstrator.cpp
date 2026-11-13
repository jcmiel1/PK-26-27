// ConsoleApplication49.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

// Napisz FUNKCJE, które odpowiednio zamieniają tekst
// Masz przykład w funkjci main, przenieś go do odpowiedniej własnej funkcji, dopisz resztę kodu

int main()
{
    const int MAX_SIZE = 1000;
    char tekst[MAX_SIZE];

    cin.getline(tekst, MAX_SIZE);



    for (int i = 0; tekst[i] != '\0'; ) {
        unsigned char c = (unsigned char)tekst[i];

        if (c < 128) {
            // ASCII
            // tak jak się uczyliśmy do tej pory (1 bajt)
        }
        else {
            // gdyby interesujowało nas tylko: ł (C5 82) Ł (C5 81) - dopisać resztę znaków polskich...
            /// uwaga! kodowanie 2-bajtowe!
            if ((unsigned char)tekst[i] == 0xC5 && (unsigned char)tekst[i + 1] == 0x82) {
                // tu odpowiednio podmień na kod literki, którą chcemy uzyskać
            }
        }
    
    return 0;
}