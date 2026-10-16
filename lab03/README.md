# Laboratorium 03: schematy blokowe, pętle i algorytmy iteracyjne

Na trzecim laboratorium rozwijamy podstawy poznane podczas poprzednich zajęć.

Będziemy pracować przede wszystkim z:

- analizą schematów blokowych,
- instrukcjami warunkowymi,
- pętlami,
- wielokrotnym wczytywaniem danych,
- zmiennymi pomocniczymi,
- wyznaczaniem wartości największej,
- sumowaniem kolejnych wartości,
- algorytmami iteracyjnymi,
- sprawdzaniem poprawności danych wejściowych.

W przykładach poniżej pokazane są mechanizmy potrzebne do rozwiązania zadań z laboratorium.

Przykłady są jednak celowo inne niż zadania do samodzielnego wykonania.

---

## 1. Od schematu blokowego do programu

Schemat blokowy przedstawia algorytm w postaci graficznej.

Pokazuje przede wszystkim:

- kolejność wykonywania instrukcji,
- miejsca podejmowania decyzji,
- operacje wykonywane wielokrotnie,
- moment rozpoczęcia i zakończenia algorytmu.

Podczas przepisywania schematu blokowego na C++ warto analizować go krok po kroku.

Przykładowy schemat myślenia:

```text
START
  ↓
wczytaj dane
  ↓
sprawdź warunek
  ↓
wykonaj odpowiednie instrukcje
  ↓
wyświetl wynik
  ↓
STOP
```

W kodzie C++ może to odpowiadać konstrukcji:

```cpp
#include <iostream>

using namespace std;

int main() {

    // wczytanie danych

    if (warunek) {

        // pierwszy przypadek
    }
    else {

        // drugi przypadek
    }

    // wyświetlenie wyniku

    return 0;
}
```

---

## 2. Element decyzyjny na schemacie blokowym

Na schemacie blokowym warunek jest zwykle przedstawiany w postaci rombu.

W programie C++ odpowiada mu najczęściej instrukcja:

```cpp
if
```

Przykład:

```cpp
int liczba;

cin >> liczba;

if (liczba > 0) {
    cout << "Dodatnia" << endl;
}
else {
    cout << "Niedodatnia" << endl;
}
```

Jeżeli schemat zawiera kilka możliwych przypadków, możemy użyć:

```cpp
if
else if
else
```

---

## 3. Pętla

Pętla służy do wielokrotnego wykonywania tego samego fragmentu programu.

Zamiast pisać:

```cpp
cout << "Test" << endl;
cout << "Test" << endl;
cout << "Test" << endl;
```

możemy użyć pętli.

Na tym laboratorium przydatna będzie przede wszystkim pętla:

```cpp
for
```

---

## 4. Pętla `for`

Podstawowy zapis pętli `for` wygląda tak:

```cpp
for (inicjalizacja; warunek; zmiana) {

    // instrukcje wykonywane w pętli
}
```

Przykład:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Wynik:

```text
0
1
2
3
4
```

---

## 5. Jak działa pętla `for`

Rozważmy:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Poszczególne części oznaczają:

```cpp
int i = 0
```

utworzenie licznika i nadanie mu wartości początkowej.

```cpp
i < 5
```

warunek wykonywania pętli.

```cpp
i++
```

zwiększenie wartości `i` o `1` po każdym obiegu pętli.

Możemy to zapisać również jako:

```cpp
i = i + 1;
```

---

## 6. Licznik pętli

Zmienna:

```cpp
i
```

jest często używana jako licznik pętli.

Przykład:

```cpp
for (int i = 1; i <= 4; i++) {
    cout << "Obieg: " << i << endl;
}
```

Wynik:

```text
Obieg: 1
Obieg: 2
Obieg: 3
Obieg: 4
```

Nazwa `i` jest często używana dla prostych liczników, ale można zastosować również bardziej opisową nazwę.

---

## 7. Ile razy wykona się pętla?

Rozważmy:

```cpp
for (int i = 0; i < 4; i++) {
    cout << i << endl;
}
```

Pętla wykona się dla:

```text
i = 0
i = 1
i = 2
i = 3
```

czyli cztery razy.

Natomiast:

```cpp
for (int i = 1; i <= 4; i++) {
    cout << i << endl;
}
```

również wykona się cztery razy, ale dla wartości:

```text
1
2
3
4
```

Dlatego przy tworzeniu pętli należy dokładnie zwracać uwagę na:

```text
<
<=
```

oraz wartość początkową licznika.

---


## 8. Pętla `for` nie musi zwiększać licznika o `1`

Najczęściej spotykamy zapis:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

ale trzeci element pętli:

```cpp
i++
```

nie musi oznaczać zwiększania wartości o `1`.

Możemy na przykład zmniejszać licznik:

```cpp
for (int i = 5; i > 0; i--) {
    cout << i << endl;
}
```

Wynik:

```text
5
4
3
2
1
```

Możemy również zwiększać licznik o więcej niż `1`:

```cpp
for (int i = 0; i <= 10; i += 2) {
    cout << i << endl;
}
```

Wynik:

```text
0
2
4
6
8
10
```

Możemy też wykonywać inną operację, na przykład mnożenie:

```cpp
for (int i = 1; i <= 16; i *= 2) {
    cout << i << endl;
}
```

Wynik:

```text
1
2
4
8
16
```

Ogólny zapis:

```cpp
for (inicjalizacja; warunek; zmiana) {
    // instrukcje
}
```

oznacza:

1. wykonaj `inicjalizacja`,
2. sprawdź `warunek`,
3. wykonaj instrukcje znajdujące się w pętli,
4. wykonaj `zmiana`,
5. wróć do sprawdzenia warunku.

Trzeci element pętli może więc zawierać różne operacje, nie tylko:

```cpp
i++
```

Ważne jest jednak, aby wykonywana zmiana prowadziła w końcu do zakończenia pętli.

---

## 8. Wczytywanie wielu wartości w pętli

Jeżeli program ma wczytać wiele liczb, nie musimy tworzyć osobnej zmiennej dla każdej z nich.

Możemy wczytywać kolejne wartości w pętli.

Przykład:

```cpp
int n;
int liczba;

cout << "Ile liczb: ";
cin >> n;

for (int i = 0; i < n; i++) {

    cout << "Podaj liczbe: ";
    cin >> liczba;

    cout << "Wczytano: " << liczba << endl;
}
```

Ta sama zmienna:

```cpp
liczba
```

otrzymuje w każdym obiegu pętli nową wartość.

---

## 9. Zmienna pomocnicza

W wielu algorytmach potrzebujemy zmiennej, która przechowuje wynik częściowy.

Przykładowo:

```cpp
int wynik = 0;
```

Następnie możemy aktualizować ją w pętli:

```cpp
for (int i = 0; i < 4; i++) {
    wynik = wynik + 2;
}
```

Po wykonaniu pętli zmienna `wynik` będzie zawierała:

```text
8
```

---

## 10. Skrócony zapis przypisania

Instrukcję:

```cpp
wynik = wynik + 2;
```

możemy zapisać krócej:

```cpp
wynik += 2;
```

Analogicznie:

```cpp
x = x - 3;
```

możemy zapisać:

```cpp
x -= 3;
```

oraz:

```cpp
x = x * 2;
```

jako:

```cpp
x *= 2;
```

Na początku można korzystać z dłuższego zapisu, jeśli jest bardziej czytelny.

---

## 11. Sumowanie wartości w pętli

Typowy schemat sumowania wygląda tak:

```cpp
int suma = 0;

for (int i = 1; i <= 4; i++) {
    suma = suma + i;
}
```

Prześledźmy działanie:

```text
początek: suma = 0

i = 1    suma = 0 + 1 = 1
i = 2    suma = 1 + 2 = 3
i = 3    suma = 3 + 3 = 6
i = 4    suma = 6 + 4 = 10
```

Po zakończeniu pętli:

```text
suma = 10
```

Zmienna `suma` musi zostać zainicjalizowana przed rozpoczęciem pętli.

---

## 12. Dlaczego suma zwykle zaczyna się od `0`?

Jeżeli chcemy dodawać kolejne wartości, naturalną wartością początkową jest:

```cpp
int suma = 0;
```

Ponieważ:

```text
0 + x = x
```

Gdybyśmy pozostawili zmienną niezainicjalizowaną:

```cpp
int suma;
```

a następnie wykonali:

```cpp
suma = suma + x;
```

program próbowałby użyć wartości, której wcześniej nie nadaliśmy.

---

## 13. Iloczyn wartości w pętli

Jeżeli zamiast sumowania chcemy mnożyć kolejne wartości, zmienna wynikowa powinna zwykle zaczynać się od:

```cpp
1
```

Przykład:

```cpp
int iloczyn = 1;

for (int i = 1; i <= 4; i++) {
    iloczyn = iloczyn * 2;
}
```

Dlaczego nie zaczynamy od:

```cpp
0
```

?

Ponieważ:

```text
0 * x = 0
```

i cały wynik pozostałby równy `0`.

---

## 14. Wyznaczanie największej wartości

Jeżeli chcemy znaleźć największą z kilku wczytywanych wartości, potrzebujemy zmiennej przechowującej aktualne maksimum.

Nie powinniśmy zawsze zaczynać od:

```cpp
int maksimum = 0;
```

Dlaczego?

Jeżeli wszystkie wczytane liczby są ujemne, `0` może w ogóle nie występować w danych, a mimo to pozostałoby maksimum.

Lepszym sposobem jest wczytanie pierwszej wartości i przyjęcie jej jako początkowego maksimum.

Schemat:

```cpp
int maksimum;
int liczba;

cin >> maksimum;

for (...) {

    cin >> liczba;

    if (liczba > maksimum) {
        maksimum = liczba;
    }
}
```

To ważny ogólny sposób inicjalizacji algorytmu wyszukiwania minimum lub maksimum.

---

## 15. Jak działa aktualizacja maksimum?

Załóżmy, że aktualne maksimum wynosi:

```text
7
```

Wczytujemy:

```text
4
```

Sprawdzamy:

```cpp
if (4 > 7)
```

Warunek jest fałszywy, więc maksimum pozostaje:

```text
7
```

Następnie wczytujemy:

```text
11
```

Warunek:

```cpp
if (11 > 7)
```

jest prawdziwy.

Wykonujemy więc:

```cpp
maksimum = 11;
```

Od tego momentu aktualnym maksimum jest `11`.

---

## 16. Pętla a schemat blokowy

Na schemacie blokowym pętla zwykle wygląda jak powrót strzałką do wcześniej wykonywanego fragmentu algorytmu.

Przykładowo:

```text
ustaw i = 0
    ↓
czy i < n?
   / \
 TAK  NIE
  ↓    ↓
wykonaj  STOP
instrukcje
  ↓
i = i + 1
  ↓
powrót do warunku
```

W C++ możemy to zapisać:

```cpp
for (int i = 0; i < n; i++) {

    // instrukcje
}
```

---

## 17. Walidacja danych przed pętlą

Jeżeli liczba powtórzeń musi spełniać określony warunek, należy sprawdzić go przed rozpoczęciem pętli.

Przykład:

```cpp
int n;

cin >> n;

if (n <= 0) {
    cout << "Niepoprawna wartosc" << endl;
}
else {

    for (int i = 0; i < n; i++) {

        // instrukcje
    }
}
```

Dzięki temu pętla wykona się tylko dla poprawnych danych.

---

## 18. Liczby naturalne

W zadaniach może pojawić się pojęcie liczby naturalnej.

W praktyce trzeba zwrócić uwagę na to, jak jest ono zdefiniowane w treści zadania.

W zależności od przyjętej konwencji zbiór liczb naturalnych może zaczynać się od:

```text
0
```

albo od:

```text
1
```

Jeżeli zadanie wymaga sprawdzenia, czy wartość jest liczbą naturalną, należy stosować dokładnie warunek wynikający z treści zadania lub ustaleń prowadzącego.

---

## 19. Kolejne liczby

Jeżeli zaczynamy od pewnej wartości:

```cpp
int a = 5;
```

to kolejne liczby możemy otrzymać jako:

```text
5
6
7
8
...
```

W pętli można to zapisać na przykład:

```cpp
for (int i = 0; i < 4; i++) {

    int aktualna = a + i;

    cout << aktualna << endl;
}
```

Dla:

```text
a = 5
```

otrzymamy:

```text
5
6
7
8
```

---

## 20. Sumowanie kolejnych liczb od zadanej wartości

Jeżeli chcemy sumować wartości zaczynając od pewnej liczby, możemy połączyć licznik pętli ze zmienną początkową.

Neutralny przykład:

```cpp
int poczatek = 4;
int liczbaElementow = 3;
int suma = 0;

for (int i = 0; i < liczbaElementow; i++) {

    int aktualna = poczatek + i;

    suma = suma + aktualna;
}
```

W kolejnych obiegach pętli `aktualna` przyjmuje wartości:

```text
4
5
6
```

Nie jest to gotowe rozwiązanie zadania laboratoryjnego, ale pokazuje mechanizm generowania kolejnych wartości.

---

## 21. Silnia jako przykład algorytmu iteracyjnego

Silnia jest przykładem działania, które można obliczać krok po kroku.

Dla dodatniej liczby całkowitej:

```text
4! = 1 * 2 * 3 * 4
```

czyli:

```text
4! = 24
```

Ważny przypadek:

```text
0! = 1
```

Nie trzeba zapamiętywać osobnego algorytmu dla `0`.

Jeżeli zmienna wynikowa zaczyna się od:

```cpp
1
```

a pętla nie wykona żadnego mnożenia dla `0`, wynik pozostanie równy `1`.

---

## 22. Dlaczego przy mnożeniu zaczynamy od `1`?

Rozważmy:

```cpp
int wynik = 1;
```

Następnie mnożymy przez kolejne wartości:

```text
1 * 1 = 1
1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
```

Jeżeli rozpoczęlibyśmy od:

```cpp
int wynik = 0;
```

otrzymalibyśmy:

```text
0 * 1 = 0
0 * 2 = 0
0 * 3 = 0
...
```

czyli wynik zawsze pozostałby równy `0`.

---

## 23. Typ zmiennej a zakres wyniku

Warto pamiętać, że typ:

```cpp
int
```

ma ograniczony zakres.

Niektóre obliczenia, szczególnie wielokrotne mnożenie, bardzo szybko prowadzą do dużych wartości.

Dlatego czasem zamiast:

```cpp
int wynik;
```

stosujemy:

```cpp
long long wynik;
```

Typ `long long` pozwala przechowywać większe liczby całkowite niż typowy `int`.

Nie oznacza to jednak, że jego zakres jest nieograniczony.

---

## 24. Pętla `while`

Algorytm można również zapisać za pomocą pętli:

```cpp
while
```

Schemat:

```cpp
while (warunek) {

    // instrukcje
}
```

Przykład:

```cpp
int i = 0;

while (i < 4) {

    cout << i << endl;

    i++;
}
```

Wynik:

```text
0
1
2
3
```

---

## 25. `for` czy `while`?

Pętla `for` jest wygodna, gdy z góry wiemy, ile razy chcemy wykonać daną operację.

Przykład:

```cpp
for (int i = 0; i < n; i++) {
    // instrukcje
}
```

Pętla `while` jest wygodna, gdy wykonujemy instrukcje tak długo, jak spełniony jest określony warunek:

```cpp
while (warunek) {
    // instrukcje
}
```

W wielu prostych przypadkach oba rodzaje pętli mogą zostać użyte do rozwiązania tego samego problemu.

---


## Pętla `while` z licznikiem utworzonym wcześniej

Pętlę:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

możemy zapisać za pomocą `while`.

Najpierw tworzymy zmienną pomocniczą:

```cpp
int i = 0;
```

Następnie sprawdzamy warunek w pętli:

```cpp
while (i < 5) {

    cout << i << endl;

    i++;
}
```

W pętli `while` trzy elementy znane z `for` znajdują się w różnych miejscach:

```text
for:

for (int i = 0; i < 5; i++)
     ↑          ↑      ↑
 inicjalizacja warunek zmiana
```

Odpowiednik z `while`:

```cpp
int i = 0;          // inicjalizacja

while (i < 5) {     // warunek

    cout << i << endl;

    i++;            // zmiana
}
```

Dlatego bardzo ważne jest, aby przy użyciu `while` pamiętać o zmianie wartości zmiennej sterującej pętlą.

Bez:

```cpp
i++;
```

warunek:

```cpp
i < 5
```

pozostałby cały czas prawdziwy i powstałaby pętla nieskończona.

---

## Pętla `do...while`

Pętla:

```cpp
do {
    // instrukcje
}
while (warunek);
```

różni się od `while` kolejnością sprawdzania warunku.

W przypadku `while`:

```cpp
while (warunek) {
    // instrukcje
}
```

najpierw sprawdzany jest warunek.

Jeżeli od początku jest fałszywy, pętla nie wykona się ani razu.

Natomiast w `do...while`:

```cpp
do {
    // instrukcje
}
while (warunek);
```

najpierw wykonywane są instrukcje, a dopiero później sprawdzany jest warunek.

Oznacza to, że pętla `do...while` wykona się co najmniej jeden raz.

---

## Przykład `do...while`

```cpp
int i = 0;

do {

    cout << i << endl;

    i++;

}
while (i < 5);
```

Wynik:

```text
0
1
2
3
4
```

Przebieg programu:

```text
i = 0
  ↓
wykonaj instrukcje
  ↓
i = i + 1
  ↓
sprawdź warunek i < 5
  ↓
jeżeli TAK -> wróć do początku pętli
jeżeli NIE -> zakończ pętlę
```

---

## `while` i `do...while` nie działają identycznie

Rozważ:

```cpp
int i = 10;

while (i < 5) {

    cout << i << endl;

    i++;
}
```

Warunek:

```cpp
i < 5
```

jest od początku fałszywy.

Pętla nie wykona się ani razu.

Natomiast:

```cpp
int i = 10;

do {

    cout << i << endl;

    i++;

}
while (i < 5);
```

najpierw wykona instrukcje znajdujące się w `do`.

Dlatego zostanie wypisane:

```text
10
```

Dopiero później program sprawdzi warunek i zakończy pętlę.

---

## Kiedy używać `do...while`?

`do...while` jest wygodne wtedy, gdy pewna operacja powinna wykonać się przynajmniej raz.

Przykładowy schemat:

```text
pobierz wartość
    ↓
sprawdź poprawność
    ↓
jeżeli niepoprawna -> pobierz ponownie
```

Można to zapisać:

```cpp
int liczba;

do {

    cout << "Podaj liczbe dodatnia: ";
    cin >> liczba;

}
while (liczba <= 0);
```

Program zawsze przynajmniej raz poprosi użytkownika o podanie wartości.

---

## Porównanie `for`, `while` i `do...while`

### `for`

Najczęściej stosujemy, gdy wiemy, ile razy pętla ma się wykonać.

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

### `while`

Stosujemy, gdy chcemy wykonywać instrukcje tak długo, jak długo warunek jest prawdziwy.

```cpp
int i = 0;

while (i < 5) {

    cout << i << endl;

    i++;
}
```

Warunek jest sprawdzany przed wykonaniem instrukcji.

### `do...while`

Stosujemy, gdy instrukcje powinny wykonać się co najmniej raz.

```cpp
int i = 0;

do {

    cout << i << endl;

    i++;

}
while (i < 5);
```

Warunek jest sprawdzany po wykonaniu instrukcji.

---

## Pętle na schematach blokowych

Na schemacie blokowym pętlę rozpoznajemy po tym, że jedna ze strzałek prowadzi z powrotem do wcześniej wykonywanego fragmentu algorytmu.

Nie każdy romb oznacza więc tylko pojedynczą instrukcję `if`.

Jeżeli jedna z gałęzi prowadzi z powrotem do wcześniejszego miejsca, mamy do czynienia z powtarzaniem, czyli pętlą.

### Odpowiednik pętli `while`

```text
ustaw i = 0
    ↓
czy i < 5?
   / \
 TAK  NIE
  ↓    ↓
wypisz i STOP
  ↓
i = i + 1
  ↓
powrót do warunku
```

Warunek jest tutaj sprawdzany przed wykonaniem instrukcji.

Odpowiada to:

```cpp
int i = 0;

while (i < 5) {

    cout << i << endl;

    i++;
}
```

### Odpowiednik pętli `do...while`

```text
ustaw i = 0
    ↓
wypisz i
    ↓
i = i + 1
    ↓
czy i < 5?
   / \
 TAK  NIE
  ↓    ↓
powrót STOP
do instrukcji
```

Odpowiada to:

```cpp
int i = 0;

do {

    cout << i << endl;

    i++;

}
while (i < 5);
```

Najważniejsza różnica:

```text
while:
najpierw warunek
potem instrukcje

do...while:
najpierw instrukcje
potem warunek
```

### Schemat blokowy a pętla `for`

Na schemacie blokowym nie ma osobnego symbolu oznaczającego `for`.

Widzimy natomiast:

- inicjalizację licznika,
- warunek,
- instrukcje wykonywane w pętli,
- zmianę licznika,
- strzałkę wracającą do warunku.

Przykład:

```text
i = 0
  ↓
czy i < 5?
 / \
TAK NIE
 ↓   ↓
kod STOP
 ↓
i = i + 1
 ↓
powrót do warunku
```

Możemy zapisać go jako:

```cpp
for (int i = 0; i < 5; i++) {

    // kod
}
```

albo równoważnie:

```cpp
int i = 0;

while (i < 5) {

    // kod

    i++;
}
```

Schemat blokowy opisuje **algorytm**, a nie konkretną składnię języka programowania.

---

## Jak przełożyć schemat blokowy na pętlę?

Analizując schemat, warto zadać sobie pytania:

1. Co wykonuje się przed rozpoczęciem pętli?
2. Gdzie znajduje się warunek?
3. Czy warunek jest sprawdzany przed czy po wykonaniu instrukcji?
4. Która strzałka prowadzi z powrotem?
5. Co zmienia się w każdym obiegu pętli?
6. Kiedy algorytm przestaje się powtarzać?

Jeżeli warunek znajduje się przed powtarzanym fragmentem, naturalnym wyborem jest często:

```cpp
while
```

Jeżeli warunek znajduje się po powtarzanym fragmencie, naturalnym odpowiednikiem jest:

```cpp
do...while
```

Jeżeli dodatkowo mamy wyraźny licznik, wartość początkową oraz zmianę licznika, wygodny może być:

```cpp
for
```

---

## 26. Uważaj na pętlę nieskończoną

Rozważ:

```cpp
int i = 0;

while (i < 5) {
    cout << i << endl;
}
```

Wartość:

```cpp
i
```

nigdy się nie zmienia.

Warunek:

```cpp
i < 5
```

pozostaje więc cały czas prawdziwy.

Powstaje pętla nieskończona.

Poprawny zapis wymaga zmiany licznika:

```cpp
int i = 0;

while (i < 5) {

    cout << i << endl;

    i++;
}
```

---

## 27. Zagnieżdżenie `if` wewnątrz pętli

Instrukcja warunkowa może znajdować się wewnątrz pętli.

Przykład:

```cpp
for (int i = 0; i < 5; i++) {

    if (i % 2 == 0) {
        cout << i << endl;
    }
}
```

Dla każdej wartości `i` sprawdzany jest warunek.

Takie połączenie pętli i instrukcji `if` jest bardzo częste.

---

## 28. Pętla wewnątrz instrukcji warunkowej

Możliwy jest również odwrotny układ:

```cpp
if (n > 0) {

    for (int i = 0; i < n; i++) {

        // instrukcje
    }
}
else {

    cout << "Niepoprawna wartosc" << endl;
}
```

Najpierw sprawdzamy poprawność danych.

Dopiero później uruchamiamy pętlę.

---

## 29. Znak jako wybór użytkownika

Użytkownik może wybierać wariant programu za pomocą znaku.

Przykład:

```cpp
char wybor;

cout << "Wybierz A lub B: ";
cin >> wybor;

if (wybor == 'A') {
    cout << "Wybrano A" << endl;
}
else if (wybor == 'B') {
    cout << "Wybrano B" << endl;
}
else {
    cout << "Niepoprawny wybor" << endl;
}
```

Pamiętaj:

```cpp
'A'
```

jest znakiem typu `char`.

Dlatego przy porównaniu używamy pojedynczych apostrofów.

---

## 30. Wielkie i małe litery są różne

Dla typu `char`:

```cpp
'C'
```

i:

```cpp
'c'
```

to dwa różne znaki.

Warunek:

```cpp
if (jednostka == 'C')
```

nie będzie prawdziwy dla:

```text
c
```

Jeżeli zadanie wymaga konkretnego znaku, należy sprawdzać dokładnie taki znak, jaki podano w treści.

---

## 31. Wiele wyników obliczanych na podstawie jednej wartości

Czasami program wczytuje jedną wartość, a następnie oblicza kilka związanych z nią wyników.

Schemat:

```cpp
double x;
double wynik1;
double wynik2;

cin >> x;

wynik1 = /* obliczenie */;
wynik2 = /* obliczenie */;

cout << wynik1 << endl;
cout << wynik2 << endl;
```

Jeżeli sposób obliczenia zależy od rodzaju danych wejściowych, możemy połączyć to z instrukcją warunkową:

```cpp
if (wybor == 'A') {

    // pierwszy sposób obliczeń
}
else if (wybor == 'B') {

    // drugi sposób obliczeń
}
else {

    // niepoprawny wybór
}
```

---

## 32. Formatowanie wyników rzeczywistych

Jeżeli wynik ma być wyświetlony z określoną liczbą miejsc po przecinku, korzystamy z:

```cpp
#include <iomanip>
```

oraz:

```cpp
fixed
setprecision(...)
```

Przykład:

```cpp
double x = 12.34567;

cout << fixed << setprecision(2);
cout << x << endl;
```

Wynik:

```text
12.35
```

Ustawienie:

```cpp
fixed << setprecision(2)
```

pozostaje aktywne dla kolejnych liczb rzeczywistych wypisywanych przez `cout`.

---

## 33. Walidacja przed dalszym działaniem programu

Jeżeli użytkownik może podać niepoprawną wartość, warto sprawdzić ją możliwie wcześnie.

Przykład:

```cpp
int n;

cin >> n;

if (n < 0) {
    cout << "Niepoprawne dane" << endl;
}
else {

    // dalsza część programu
}
```

Dzięki temu kod wykonywany dla poprawnych danych znajduje się w osobnym bloku.

---

## 34. Kolejność sprawdzania danych

Jeżeli program wczytuje kilka danych, kolejność walidacji może mieć znaczenie.

Przykładowy schemat:

```text
wczytaj N
    ↓
czy N jest poprawne?
    ↓
TAK
    ↓
wczytaj kolejne dane
    ↓
wykonaj obliczenia
```

Jeżeli pierwsza wartość jest niepoprawna, nie zawsze ma sens wczytywanie kolejnych danych.

W zadaniach automatycznie sprawdzanych należy również zwrócić uwagę na to, jakie komunikaty i w jakiej kolejności są wymagane.

---

## 35. Dokładny format wyjścia

Tak jak na poprzednich laboratoriach, zadania są sprawdzane automatycznie.

Znaczenie mogą mieć:

- wielkie i małe litery,
- spacje,
- znaki `=`,
- dwukropki,
- kolejność komunikatów,
- przejścia do nowej linii,
- liczba miejsc po przecinku.

Jeżeli oczekiwane wyjście zawiera:

```text
Wynik = 12
```

program powinien wypisać właśnie taki tekst.

Nie jest tym samym:

```text
Wynik: 12
```

Automatyczny system może uznać drugi zapis za błędny.

---

## 36. Najczęstsze błędy na tym laboratorium

Przed uruchomieniem programu sprawdź:

- czy pętla wykonuje się odpowiednią liczbę razy,
- czy licznik ma poprawną wartość początkową,
- czy używasz `<` czy `<=` zgodnie z założeniem,
- czy licznik zmienia się w każdym obiegu pętli,
- czy zmienna sumująca została zainicjalizowana wartością `0`,
- czy zmienna używana do mnożenia została odpowiednio zainicjalizowana,
- czy maksimum nie zostało bezmyślnie ustawione na `0`,
- czy poprawnie wczytujesz pierwszą wartość przed szukaniem maksimum,
- czy sprawdzasz poprawność danych przed uruchomieniem pętli,
- czy nie wykonujesz pętli dla niepoprawnej liczby powtórzeń,
- czy przy porównywaniu `char` używasz pojedynczych apostrofów,
- czy tekst wyjściowy jest zgodny z wymaganym formatem,
- czy przy liczbach rzeczywistych używasz odpowiedniego `setprecision()`.

---

## 37. Najważniejszy schemat programu z pętlą

Typowy program wykorzystujący pętlę może wyglądać tak:

```cpp
#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    if (n <= 0) {

        cout << "Niepoprawna wartosc" << endl;
    }
    else {

        for (int i = 0; i < n; i++) {

            // instrukcje wykonywane n razy
        }
    }

    return 0;
}
```

Jeżeli potrzebujemy zmiennej wynikowej:

```cpp
#include <iostream>

using namespace std;

int main() {

    int n;
    int wynik = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {

        // aktualizacja wyniku
    }

    cout << wynik << endl;

    return 0;
}
```

---

## 38. Schemat pracy nad zadaniem

Przed rozpoczęciem pisania kodu zastanów się:

1. Jakie dane program ma wczytać?
2. Czy wszystkie dane są poprawne dla dowolnej wartości?
3. Czy przed dalszym działaniem trzeba sprawdzić warunek?
4. Czy jakaś operacja ma zostać wykonana wiele razy?
5. Ile razy powinna wykonać się pętla?
6. Od jakiej wartości powinien zaczynać licznik?
7. Czy warunek pętli powinien zawierać `<` czy `<=`?
8. Czy potrzebuję zmiennej sumującej?
9. Czy potrzebuję zmiennej przechowującej maksimum?
10. Jak poprawnie zainicjalizować zmienną wynikową?
11. Czy wynik może przekroczyć zakres typu `int`?
12. Czy użytkownik wybiera wariant programu za pomocą liczby lub znaku?
13. Czy wynik rzeczywisty wymaga formatowania?
14. Czy format wyjścia jest dokładnie zgodny z treścią zadania?

Typowy tok pracy:

```text
wczytaj dane
    ↓
sprawdź poprawność danych
    ↓
ustaw wartości początkowe
    ↓
uruchom pętlę
    ↓
wykonuj obliczenia / porównania
    ↓
aktualizuj wynik
    ↓
wyświetl wynik
```

Na tym laboratorium najważniejsze jest zrozumienie, że wiele algorytmów można opisać jako powtarzanie tych samych operacji dla kolejnych danych. Pętla pozwala zapisać taki algorytm krótko i czytelnie.
