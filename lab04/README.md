# Laboratorium 04: pętle zagnieżdżone, wzory tekstowe i `switch-case`

Na tym laboratorium rozwijamy materiał dotyczący pętli i instrukcji warunkowych.

Będziemy pracować przede wszystkim z:
- wielokrotnym mnożeniem w pętli,
- pętlami zagnieżdżonymi,
- rysowaniem prostych wzorów tekstowych,
- zależnością między numerem wiersza a liczbą wypisywanych znaków,
- instrukcją `switch-case`,
- grupowaniem kilku wartości w jednej gałęzi `case`,
- walidacją danych wejściowych.



---

## 1. Powtarzanie tego samego działania

Pętla jest przydatna wtedy, gdy tę samą operację trzeba wykonać wiele razy.

```cpp
int wynik = 1;

for (int i = 0; i < 4; i++) {
    wynik = wynik * 3;
}
```

Przebieg:

```text
początek: wynik = 1
po 1. obiegu: 3
po 2. obiegu: 9
po 3. obiegu: 27
po 4. obiegu: 81
```

---

## 2. Dlaczego przy mnożeniu zaczynamy od `1`?

Jeżeli wynik powstaje przez kolejne mnożenie, zmienna wynikowa powinna zwykle zaczynać się od:

```cpp
int wynik = 1;
```

Nie od `0`, ponieważ:

```text
0 * x = 0
```

i cały wynik pozostałby równy `0`.

---

## 3. Liczba powtórzeń a pętla `for`

Jeżeli działanie ma zostać wykonane dokładnie `n` razy:

```cpp
for (int i = 0; i < n; i++) {
    // instrukcja wykonywana n razy
}
```

Dla `n = 4` pętla wykona się dla:

```text
i = 0
i = 1
i = 2
i = 3
```

czyli dokładnie cztery razy.

---

## 4. Szczególny przypadek: zero powtórzeń

Jeżeli warunek pętli od początku jest fałszywy, pętla nie wykona się ani razu.

```cpp
for (int i = 0; i < 0; i++) {
    // instrukcje
}
```

Jeżeli zmienna wynikowa została wcześniej ustawiona na `1`, pozostanie równa `1`.

---

## 5. Walidacja przed wykonaniem obliczeń

Jeżeli pewne dane są niedozwolone, sprawdzamy je przed rozpoczęciem algorytmu.

```cpp
cin >> n;

if (n < 0) {
    cout << "Niepoprawna wartosc" << endl;
}
else {
    // dalsze obliczenia
}
```

---

## 6. Pętle zagnieżdżone

Pętla może znajdować się wewnątrz innej pętli.

```cpp
for (int wiersz = 0; wiersz < 3; wiersz++) {

    for (int kolumna = 0; kolumna < 4; kolumna++) {
        cout << "#";
    }

    cout << endl;
}
```

Wynik:

```text
####
####
####
```

Najczęściej:
- pętla zewnętrzna steruje wierszami,
- pętla wewnętrzna steruje elementami w danym wierszu.

---

## 7. Jak działa pętla zagnieżdżona?

Dla każdego pojedynczego obiegu pętli zewnętrznej pętla wewnętrzna wykonuje się od początku do końca.

```cpp
for (int wiersz = 0; wiersz < 3; wiersz++) {

    for (int kolumna = 0; kolumna < 2; kolumna++) {
        cout << "*";
    }

    cout << endl;
}
```

Wynik:

```text
**
**
**
```

---

## 8. Wypisywanie kilku znaków jako jednego elementu

Pojedynczy element wzoru może mieć więcej niż jeden znak.

```cpp
cout << "[]";
cout << "..";
```

Przykład:

```cpp
for (int i = 0; i < 4; i++) {
    cout << "[]";
}
```

Wynik:

```text
[][][][]
```

To ważne, gdy dwa różne elementy wzoru mają mieć taką samą szerokość.

---

## 9. Naprzemienne elementy i operator `%`

Do tworzenia wzorów naprzemiennych można wykorzystać modulo.

```cpp
for (int i = 0; i < 6; i++) {

    if (i % 2 == 0) {
        cout << "AA";
    }
    else {
        cout << "..";
    }
}
```

Wynik:

```text
AA..AA..AA..
```

---

## 10. Numer wiersza może wpływać na wzór

W pętlach zagnieżdżonych można korzystać jednocześnie z numeru wiersza i kolumny.

```cpp
for (int wiersz = 0; wiersz < 4; wiersz++) {

    for (int kolumna = 0; kolumna < 6; kolumna++) {

        if ((wiersz + kolumna) % 2 == 0) {
            cout << "XX";
        }
        else {
            cout << "..";
        }
    }

    cout << endl;
}
```

Dzięki `(wiersz + kolumna) % 2` wzór przesuwa się w kolejnym wierszu.

---

## 11. Rysowanie kształtu zależnego od numeru wiersza

Nie każdy wiersz musi mieć tyle samo znaków.

```cpp
for (int wiersz = 1; wiersz <= 4; wiersz++) {

    for (int i = 0; i < wiersz; i++) {
        cout << "*";
    }

    cout << endl;
}
```

Wynik:

```text
*
**
***
****
```

---

## 12. Wzór matematyczny liczby elementów

Jeżeli numer wiersza wynosi:

```text
1
2
3
4
```

to zależność:

```cpp
2 * wiersz
```

daje:

```text
2
4
6
8
```

a:

```cpp
2 * wiersz - 1
```

daje:

```text
1
3
5
7
```

Takie zależności są bardzo przydatne przy rysowaniu figur tekstowych.

---

## 13. Wypisywanie spacji

Spacja jest normalnym znakiem:

```cpp
cout << " ";
```

Liczbę spacji można kontrolować pętlą:

```cpp
for (int i = 0; i < liczbaSpacji; i++) {
    cout << " ";
}
```

---

## 14. Łączenie spacji i znaków

Przy rysowaniu figur jeden wiersz często składa się z:

```text
spacje + znaki
```

Schemat:

```cpp
for (int wiersz = 0; wiersz < wysokosc; wiersz++) {

    for (...) {
        cout << " ";
    }

    for (...) {
        cout << "*";
    }

    cout << endl;
}
```

---

## 15. Myślenie wierszami

Przed napisaniem kodu warto rozpisać wzór.

Na przykład:

```text
wiersz 0: 3 spacje, 1 znak
wiersz 1: 2 spacje, 3 znaki
wiersz 2: 1 spacja, 5 znaków
wiersz 3: 0 spacji, 7 znaków
```

Wtedy łatwo zauważyć zależności:

```text
spacje: 3, 2, 1, 0
znaki:  1, 3, 5, 7
```

Dopiero potem warto pisać pętle.

---

## 16. Nie wpisuj osobno każdego wiersza

Jeżeli rozmiar figury podaje użytkownik, nie wypisujemy każdego wiersza ręcznie.

Zamiast tego trzeba znaleźć zależność między:
- numerem wiersza,
- liczbą spacji,
- liczbą znaków.

---

## 17. Instrukcja `switch`

Instrukcja `switch` pozwala wybrać jeden z wielu wariantów na podstawie jednej wartości.

```cpp
switch (zmienna) {

    case wartosc1:
        // instrukcje
        break;

    case wartosc2:
        // instrukcje
        break;

    default:
        // pozostałe przypadki
        break;
}
```

---

## 18. Prosty przykład `switch-case`

```cpp
int opcja;

cin >> opcja;

switch (opcja) {

    case 1:
        cout << "Wybrano A" << endl;
        break;

    case 2:
        cout << "Wybrano B" << endl;
        break;

    case 3:
        cout << "Wybrano C" << endl;
        break;

    default:
        cout << "Niepoprawna opcja" << endl;
        break;
}
```

---

## 19. Do czego służy `break`?

`break` kończy wykonywanie bieżącego `switch`.

Bez `break` program przejdzie do kolejnego `case`.

```cpp
switch (x) {

    case 1:
        cout << "A" << endl;

    case 2:
        cout << "B" << endl;
        break;
}
```

Dla `x = 1` zostanie wypisane:

```text
A
B
```

---

## 20. Kilka wartości może prowadzić do tego samego kodu

Brak `break` może być użyty celowo do grupowania wartości.

```cpp
switch (x) {

    case 2:
    case 4:
    case 6:
        cout << "Wybrano jedna z trzech wartosci" << endl;
        break;

    default:
        cout << "Inna wartosc" << endl;
        break;
}
```

---

## 21. `default`

Sekcja:

```cpp
default:
```

jest wykonywana, gdy żaden wcześniejszy `case` nie pasuje.

Pełni podobną rolę jak końcowe `else`.

---

## 22. `switch` działa na konkretnych wartościach

W standardowym C++ `switch-case` najlepiej nadaje się do konkretnych wartości:

```cpp
case 1:
case 2:
case 3:
```

Nie zapisujemy:

```cpp
case x < 10:
```

ani:

```cpp
case 10 ... 20:
```

Jeżeli potrzebujemy całych przedziałów, zwykle stosujemy `if/else if` albo najpierw klasyfikujemy wartość do odpowiedniej kategorii.

---

## 23. Łączenie `if` i `switch`

Możemy najpierw obsłużyć przypadki ogólne za pomocą `if`, a potem konkretne wartości za pomocą `switch`.

```cpp
if (wartosc < 0) {

    cout << "Niepoprawna wartosc" << endl;
}
else if (wartosc >= pewnaGranica) {

    // przypadek dla całego zakresu
}
else {

    switch (wartosc) {

        case 1:
            // konkretna wartość
            break;

        default:
            // pozostałe wartości
            break;
    }
}
```

---

## 24. Grupowanie wielu `case`

Jeżeli kilka wartości daje ten sam wynik, nie powtarzamy tego samego kodu.

Zamiast:

```cpp
case 4:
    cout << "X" << endl;
    break;

case 7:
    cout << "X" << endl;
    break;
```

lepiej:

```cpp
case 4:
case 7:
    cout << "X" << endl;
    break;
```

---

## 25. `switch` i typ `char`

`switch` może pracować również ze znakami.

```cpp
char znak;

cin >> znak;

switch (znak) {

    case 'A':
        cout << "Litera A" << endl;
        break;

    case 'B':
        cout << "Litera B" << endl;
        break;

    default:
        cout << "Inny znak" << endl;
        break;
}
```

---

## 26. Walidacja danych przed `switch`

Jeżeli jakaś wartość jest niedozwolona niezależnie od dalszej logiki, warto sprawdzić ją wcześniej.

```cpp
int wartosc;

cin >> wartosc;

if (wartosc < 0) {
    cout << "Niepoprawna wartosc" << endl;
}
else {

    switch (wartosc) {
        // przypadki
    }
}
```

---

## 27. Pętle i instrukcje warunkowe można łączyć

Wewnątrz pętli możemy używać `if`:

```cpp
for (int i = 0; i < 8; i++) {

    if (i % 2 == 0) {
        cout << "A";
    }
    else {
        cout << "B";
    }
}
```

Możliwe są też inne zagnieżdżenia, jeśli wynikają z algorytmu.

---

## 28. Rysowanie wzorów: najpierw analiza, potem kod

Przed napisaniem pętli warto odpowiedzieć sobie na pytania:

1. Ile ma być wierszy?
2. Co zmienia się między kolejnymi wierszami?
3. Ile elementów znajduje się w danym wierszu?
4. Czy potrzebujemy spacji?
5. Czy elementy są jednakowe czy naprzemienne?
6. Czy liczba znaków zależy od numeru wiersza?
7. Czy potrzebujemy jednej czy kilku pętli wewnętrznych?

---

## 29. Typowy schemat rysowania wzoru

```cpp
for (int wiersz = 0; wiersz < wysokosc; wiersz++) {

    for (...) {
        cout << " ";
    }

    for (...) {
        cout << "*";
    }

    cout << endl;
}
```

---

## 30. Uważaj na `endl`

Przy rysowaniu wzoru `endl` powinno zwykle znajdować się po zakończeniu całego wiersza.

```cpp
for (int wiersz = 0; wiersz < 3; wiersz++) {

    for (int kolumna = 0; kolumna < 4; kolumna++) {
        cout << "*";
    }

    cout << endl;
}
```

Jeżeli `endl` umieścimy wewnątrz pętli kolumn, każdy znak pojawi się w osobnym wierszu.

---

## 31. Typowe błędy w pętlach zagnieżdżonych

Sprawdź:
- czy pętla zewnętrzna odpowiada za właściwą liczbę wierszy,
- czy pętla wewnętrzna wykonuje się odpowiednią liczbę razy,
- czy liczniki mają różne nazwy,
- czy `endl` znajduje się w odpowiednim miejscu,
- czy liczba spacji jest poprawna,
- czy liczba znaków zależy od właściwego numeru wiersza,
- czy modulo korzysta z właściwych zmiennych.

---

## 32. Typowe błędy w `switch-case`

Sprawdź:
- czy po odpowiednich `case` znajduje się `break`,
- czy brak `break` jest celowy,
- czy kilka wartości prowadzących do tego samego wyniku zostało zgrupowanych,
- czy `default` obsługuje pozostałe przypadki,
- czy nie próbujesz używać zakresów bezpośrednio w `case`,
- czy wartości `char` zapisujesz w pojedynczych apostrofach,
- czy dane niepoprawne zostały wcześniej odrzucone.

---

## 33. Dokładny format wyjścia

Tak jak na poprzednich laboratoriach, zadania są sprawdzane automatycznie.

Znaczenie mogą mieć:
- wielkie i małe litery,
- spacje,
- liczba spacji,
- znaki `#`, `*` i inne symbole,
- liczba znaków w wierszu,
- przejścia do nowej linii,
- kolejność komunikatów,
- znaki `=` i `^`.

Przy zadaniach rysujących wzory nawet jedna dodatkowa spacja może spowodować niezgodność z oczekiwanym wynikiem.

---

## 34. Najważniejszy schemat wielokrotnego działania

```cpp
#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    if (n < 0) {
        cout << "Niepoprawna wartosc" << endl;
    }
    else {

        int wynik = 1;

        for (int i = 0; i < n; i++) {
            // aktualizacja wyniku
        }

        cout << wynik << endl;
    }

    return 0;
}
```

To jedynie ogólny schemat, nie gotowe rozwiązanie zadania laboratoryjnego.

---

## 35. Najważniejszy schemat pętli zagnieżdżonych

```cpp
for (int wiersz = 0; wiersz < wysokosc; wiersz++) {

    for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
        // element bieżącego wiersza
    }

    cout << endl;
}
```

---

## 36. Najważniejszy schemat `switch-case`

```cpp
switch (wartosc) {

    case 1:
        // instrukcje
        break;

    case 2:
    case 3:
        // wspólne instrukcje
        break;

    default:
        // pozostałe przypadki
        break;
}
```

---

## 37. Schemat pracy nad zadaniem

Przed rozpoczęciem pisania kodu zastanów się:

1. Jakie dane program ma wczytać?
2. Czy dane wymagają walidacji?
3. Czy działanie trzeba wykonać wiele razy?
4. Jaka powinna być wartość początkowa wyniku?
5. Ile razy ma wykonać się pętla?
6. Czy potrzebna jest jedna pętla czy pętle zagnieżdżone?
7. Co oznacza numer wiersza?
8. Co oznacza numer kolumny?
9. Czy wzór zmienia się w zależności od parzystości?
10. Ile spacji ma się znaleźć w każdym wierszu?
11. Ile znaków ma się znaleźć w każdym wierszu?
12. Czy kilka konkretnych wartości prowadzi do tego samego przypadku?
13. Czy lepszy będzie `if` czy `switch`?
14. Czy przypadki obejmują pojedyncze wartości czy całe zakresy?
15. Czy format wyjścia jest dokładnie zgodny z treścią zadania?

Typowy tok pracy przy obliczeniach:

```text
wczytaj dane
    ↓
sprawdź poprawność
    ↓
ustaw wartość początkową
    ↓
uruchom pętlę
    ↓
aktualizuj wynik
    ↓
wyświetl wynik
```

Typowy tok pracy przy wzorach tekstowych:

```text
ustal liczbę wierszy
    ↓
dla każdego wiersza
    ↓
oblicz liczbę spacji
    ↓
oblicz liczbę znaków
    ↓
wypisz cały wiersz
    ↓
przejdź do nowej linii
```

Na tym laboratorium najważniejsze jest zrozumienie, jak numer obiegu pętli może wpływać na wynik oraz jak za pomocą pętli zagnieżdżonych budować bardziej złożone wzory bez ręcznego wypisywania każdego wiersza.
