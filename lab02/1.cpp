/*
Wybierz precyzję:
[1] pojedyncza precyzja
[2] podwójna precyzja
Wybór: 1
Podaj a: 1
Podaj b: 3
Suma: 4.000000000000
Różnica: -2.000000000000
Iloczyn: 3.000000000000
Iloraz: 0.333333343267


Wybierz precyzję:
[1] pojedyncza precyzja
[2] podwójna precyzja
Wybór: 2
Podaj a: 1
Podaj b: 3
Suma: 4.000000000000
Różnica: -2.000000000000
Iloczyn: 3.000000000000
Iloraz: 0.333333333333


Wybierz precyzję:
[1] pojedyncza precyzja
[2] podwójna precyzja
Wybór: 1
Podaj a: 0.12345
Podaj b: 10000000
Suma: 10000000.000000000000
Różnica: -10000000.000000000000
Iloczyn: 1234500.000000000000
Iloraz: 0.000000012345


Wybierz precyzję:
[1] pojedyncza precyzja
[2] podwójna precyzja
Wybór: 3
Niepoprawny wybór

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int p;

    cout << "Wybierz precyzję" << endl;
    cout << "[1] pojedyncza precyzja" << endl;
    cout << "[2] podwójna precyzja" << endl;

    cin >> p;

    cout <<fixed << setprecision(12);

    if (p==1) {
        float a,b;
        cout << "Podaj a: ";
        cin >> a;
        cout << "Podaj b: ";
        cin >> b;




         
    }

    else if (p==2) {
        double a,b;
        cout << "Podaj a: "; 
        cin >> a;
        cout << "Podaj b: ";
        cin >> b;

    }

    else {
        cout << "Niepoprawny wybór" << endl;
    }



return 0;
}
