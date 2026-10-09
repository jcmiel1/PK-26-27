#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int r;
    float o,p;

    cout << " R = ";
    cin >> r;
    
    o = 2 * 3.14 * r;
    p = 3.14 * r * r;

    cout << fixed << setprecision(2);

    cout << "Obwód: " << o <<endl;
    cout << "Pole: " << p << endl;
    

    return 0;
}

