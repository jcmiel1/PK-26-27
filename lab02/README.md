# Laboratorium 02: typy danych, systemy liczbowe i instrukcje warunkowe

Na drugim laboratorium rozwijamy podstawy poznane podczas poprzednich zajęć.

Będziemy korzystać między innymi z:

- typu `char`,

- kodów znaków,

- systemów liczbowych,

- typów `float` i `double`,

- operatorów porównania,

- operatorów logicznych,

- operatora modulo `%`,

- instrukcji `if`, `else if` i `else`,

- prostego sprawdzania poprawności danych.

W przykładach poniżej pokazane są mechanizmy potrzebne do rozwiązania zadań z laboratorium.

Przykłady są jednak celowo inne niż zadania do samodzielnego wykonania.

---

## 1. Przypomnienie podstawowej struktury programu

Na poprzednich zajęciach korzystaliśmy ze schematu:

```cpp

#include <iostream>

using namespace std;

int main() {

    // deklaracja zmiennych

    // wczytanie danych

    // obliczenia

    // wyświetlenie wyniku

    return 0;

}

```

Na drugim laboratorium do tego schematu dojdą przede wszystkim instrukcje warunkowe.

Przykładowy układ programu:

```cpp

#include <iostream>

using namespace std;

int main() {

    // deklaracja zmiennych

    // wczytanie danych

    // sprawdzenie warunków

    // obliczenia

    // wyświetlenie wyniku

    return 0;

}

```

---

## 2. Typ `char`

Typ:

```cpp

char

```

służy do przechowywania pojedynczego znaku.

Przykład:

```cpp

char symbol = '#';

```

Wartość typu `char` zapisujemy w pojedynczych apostrofach:

```cpp

'A'

'7'

'?'

```

Pamiętaj, że:

```cpp

'A'

```

to pojedynczy znak.

Natomiast:

```cpp

"A"

```

to tekst.

---

## 3. Wczytywanie znaku

Znak możemy wczytać za pomocą:

```cpp

cin

```

Przykład:

```cpp

char symbol;

cout << "Podaj symbol: ";

cin >> symbol;

cout << "Wczytano: " << symbol << endl;

```

Schemat jest więc taki sam jak przy innych typach danych:

```text

deklaracja zmiennej

    ↓

wczytanie wartości

    ↓

wykorzystanie wartości

```

---

## 4. Znak ma również wartość liczbową

Znaki są w komputerze reprezentowane za pomocą wartości liczbowych.

Możemy przedstawić znak jako liczbę typu `int`.

Przykład:

```cpp

char symbol = '#';

cout << static_cast<int>(symbol) << endl;

```

Zapis:

```cpp

static_cast<int>(symbol)

```

oznacza w tym przypadku:

> przedstaw wartość zmiennej `symbol` jako typ `int`.

Na poprzednich zajęciach używaliśmy `static_cast<int>()` do konwersji liczby rzeczywistej na całkowitą.

Tutaj korzystamy z tego samego mechanizmu dla typu `char`.

### Tabela ASCII

Standard ASCII przypisuje znakom wartości liczbowe.

Przykładowo znak:

```cpp
'A'
```

ma kod dziesiętny:

```text
65
```

a znak:

```cpp
'a'
```

ma kod:

```text
97
```

Pełną tabelę kodów ASCII można znaleźć tutaj:

**[Tabela ASCII](https://pl.wikipedia.org/wiki/ASCII)**

Warto zwrócić uwagę, że tabela zawiera między innymi:

- wielkie litery,
- małe litery,
- cyfry,
- znaki specjalne,
- znaki sterujące.

Nie trzeba uczyć się wartości kodów na pamięć. Program może odczytać wartość liczbową znaku za pomocą:

```cpp
static_cast<int>(znak)
```

---

## 5. Systemy liczbowe

Liczbę całkowitą możemy wyświetlić w różnych systemach liczbowych.

Przydatne są:

```cpp

dec

oct

hex

```

Oznaczają odpowiednio:

```text

dec    system dziesiętny

oct    system ósemkowy

hex    system szesnastkowy

```

Przykład:

```cpp

int liczba = 42;

cout << dec << liczba << endl;

cout << oct << liczba << endl;

cout << hex << liczba << endl;

```

W każdym przypadku przechowujemy w zmiennej tę samą wartość.

Zmienia się tylko sposób jej wyświetlania.

---

## 6. `hex`, `oct` i `dec` zmieniają sposób wyświetlania

Instrukcja:

```cpp

cout << hex;

```

nie zmienia wartości zmiennej.

Zmienia tylko sposób, w jaki kolejne liczby całkowite będą wypisywane przez `cout`.

Przykład:

```cpp

int liczba = 31;

cout << hex;

cout << liczba << endl;

cout << dec;

cout << liczba << endl;

```

Po użyciu:

```cpp

hex

```

warto więc pamiętać, że w razie potrzeby możemy wrócić do:

```cpp

dec

```

---

## 7. Prefiks systemu liczbowego: `showbase`

Możemy również poprosić `cout`, aby przy wyświetlaniu liczby podał oznaczenie używanego systemu.

Służy do tego:

```cpp

showbase

```

Przykład:

```cpp

int liczba = 42;

cout << showbase << hex << liczba << endl;

```

Dla systemu szesnastkowego pojawi się prefiks:

```text

0x

```

Jeżeli nie chcemy dalej używać prefiksu, możemy zastosować:

```cpp

noshowbase

```

---

## 8. Przypomnienie: `float` i `double`

Na poprzednich zajęciach poznaliśmy dwa typy służące do przechowywania liczb rzeczywistych:

```cpp

float

double

```

Przykład:

```cpp

float x = 2.5f;

double y = 2.5;

```

`double` pozwala przechowywać liczbę z większej precyzji niż `float`.

---

## 9. Literały typu `float` i `double`

Liczba zapisana jako:

```cpp

2.5

```

jest domyślnie typu:

```cpp

double

```

Jeżeli chcemy jawnie zapisać wartość typu `float`, możemy dopisać:

```cpp

f

```

Przykład:

```cpp

float x = 2.5f;

double y = 2.5;

```

Na tym etapie warto przyzwyczaić się do takiego zapisu wartości typu `float`.

## Rozmiary i zakresy podstawowych typów danych

Każdy typ danych zajmuje określoną ilość pamięci i może przechowywać wartości tylko z określonego zakresu.

Typowe rozmiary w środowisku **Linux x86-64 z kompilatorem GCC**, takim jak używane w GitHub Codespaces, wyglądają następująco:

| Typ | Typowy rozmiar | Najmniejsza wartość | Największa wartość |
| --- | ---: | ---: | ---: |
| `bool` | 1 bajt | `false` | `true` |
| `char`* | 1 bajt | zależy od implementacji | zależy od implementacji |
| `signed char` | 1 bajt | -128 | 127 |
| `unsigned char` | 1 bajt | 0 | 255 |
| `short` | 2 bajty | -32 768 | 32 767 |
| `unsigned short` | 2 bajty | 0 | 65 535 |
| `int` | 4 bajty | -2 147 483 648 | 2 147 483 647 |
| `unsigned int` | 4 bajty | 0 | 4 294 967 295 |
| `long` | 8 bajtów | -9 223 372 036 854 775 808 | 9 223 372 036 854 775 807 |
| `unsigned long` | 8 bajtów | 0 | 18 446 744 073 709 551 615 |
| `long long` | 8 bajtów | -9 223 372 036 854 775 808 | 9 223 372 036 854 775 807 |
| `unsigned long long` | 8 bajtów | 0 | 18 446 744 073 709 551 615 |
| `float` | 4 bajty | około -3.4 × 10^38 | około 3.4 × 10^38 |
| `double` | 8 bajtów | około -1.8 × 10^308 | około 1.8 × 10^308 |

\* Sam typ `char` może być traktowany jako `signed char` albo `unsigned char`, zależnie od kompilatora i platformy. Do przechowywania zwykłych znaków nie musimy się na tym etapie tym przejmować.

### Typy `signed` i `unsigned`

Domyślnie typy całkowite, takie jak:

```cpp
int
short
long
```

mogą przechowywać zarówno liczby dodatnie, jak i ujemne.

Na przykład:

```cpp
int x = -20;
```

Jeżeli przed typem użyjemy:

```cpp
unsigned
```

zmienna nie przechowuje wartości ujemnych.

Przykład:

```cpp
unsigned int liczba = 100;
```

Ponieważ nie trzeba przeznaczać części dostępnego zakresu na liczby ujemne, największa możliwa wartość typu `unsigned` jest większa.

Dla typowego 32-bitowego `int`:

```text
int:
-2 147 483 648 ... 2 147 483 647

unsigned int:
0 ... 4 294 967 295
```

### Rozmiar typu: `sizeof`

Rozmiar typu możemy sprawdzić bezpośrednio w programie za pomocą operatora:

```cpp
sizeof
```

Przykład:

```cpp
cout << sizeof(int) << endl;
cout << sizeof(float) << endl;
cout << sizeof(double) << endl;
```

`sizeof` podaje rozmiar w bajtach.

Przykładowo w naszym środowisku możemy otrzymać:

```text
4
4
8
```

czyli:

```text
int       4 bajty
float     4 bajty
double    8 bajtów
```

Nie należy jednak zakładać, że na każdym komputerze wszystkie typy będą miały dokładnie taki sam rozmiar.

Standard C++ określa pewne minimalne wymagania dotyczące typów, ale ich dokładny rozmiar może zależeć od:

- systemu operacyjnego,
- architektury procesora,
- kompilatora.

### Większy zakres nie oznacza zawsze większej precyzji

W przypadku typów całkowitych większy typ pozwala przede wszystkim przechowywać większe liczby.

W przypadku:

```cpp
float
double
```

ważna jest również **precyzja**.

Typowo:

```text
float     około 6-7 cyfr znaczących
double    około 15-16 cyfr znaczących
```

Dlatego `double` pozwala nie tylko przechowywać znacznie większe wartości, ale również dokładniej reprezentować liczby rzeczywiste.

Na kolejnych przykładach zobaczymy, że te same obliczenia wykonane za pomocą `float` i `double` mogą dać nieco inne wyniki.

---

## 10. Dzielenie liczb całkowitych i rzeczywistych

To bardzo ważna różnica.

Jeżeli dzielimy dwie liczby całkowite:

```cpp

cout << 3 / 8 << endl;

```

to wykonywane jest ****dzielenie całkowite****.

Wynikiem będzie:

```text

0

```

ponieważ obie wartości:

```cpp

3

8

```

są typu `int`, a część ułamkowa zostaje odrzucona.

Jeżeli chcemy wykonać dzielenie rzeczywiste, przynajmniej jedna z wartości powinna być liczbą rzeczywistą.

Na przykład:

```cpp

cout << 3.0 / 8.0 << endl;

```

otrzymamy wartość:

```text

0.375

```

Możemy również zapisać:

```cpp

float a = 3.0f;

float b = 8.0f;

cout << a / b << endl;

```

Dlatego zapis:

```cpp

8.0 / 3.0

```

który pojawia się w dalszych przykładach, jest zapisany celowo z `.0`.

Chcemy, aby C++ wykonał dzielenie liczb rzeczywistych, a nie całkowitych.

---

## 11. Precyzja `float` i `double`

Typy:

```cpp

float

double

```

mają różną precyzję.

Możemy to zaobserwować, wykonując to samo obliczenie dla obu typów.

Przykład:

```cpp

float x = 1.0f / 7.0f;

double y = 1.0 / 7.0;

```

Jeżeli wyświetlimy wiele miejsc po przecinku, wyniki mogą się różnić.

Do wyświetlania większej liczby miejsc po przecinku potrzebujemy:

```cpp

#include <iomanip>

```

Przykład:

```cpp

cout << fixed << setprecision(12);

cout << x << endl;

cout << y << endl;

```

---

## 12. `fixed` i `setprecision()`

Na poprzednich zajęciach używaliśmy:

```cpp

cout << fixed << setprecision(2);

```

W połączeniu z:

```cpp

fixed

```

wartość:

```cpp

setprecision(2)

```

oznacza dwie cyfry po przecinku.

Analogicznie:

```cpp

cout << fixed << setprecision(12);

```

oznacza dwanaście cyfr po przecinku.

Przykład:

```cpp

double x = 8.0 / 3.0;

cout << fixed << setprecision(4);

cout << x << endl;

```

Wynik:

```text

2.6667

```

Wartość zostanie odpowiednio zaokrąglona podczas wyświetlania.

---

## 13. Wyświetlanie a dokładność obliczeń

Instrukcja:

```cpp

setprecision(...)

```

zmienia sposób wyświetlania liczby.

Nie zwiększa precyzji samej zmiennej.

Przykład:

```cpp

float x = 1.0f / 7.0f;

```

Zmiennej `x` nadal dotyczy precyzja typu `float`, nawet jeżeli napiszemy:

```cpp

cout << fixed << setprecision(12);

```

Analogicznie `double` zachowuje precyzję właściwą dla typu `double`.

---

## 14. Dlaczego `float` i `double` mogą dawać inne wyniki?

Liczby rzeczywiste są przechowywane w komputerze w postaci binarnej.

Nie każdą liczbę dziesiętną można zapisać w tej postaci dokładnie.

Dlatego po wykonaniu obliczeń i wyświetleniu wielu miejsc po przecinku możemy zobaczyć drobne różnice.

Przykładowo:

```cpp

float x = 1.0f / 7.0f;

double y = 1.0 / 7.0;

```

mogą dać nieco inne wyniki przy dużej liczbie wyświetlanych cyfr.

Nie oznacza to, że program działa źle.

Wynika to z ograniczonej precyzji reprezentacji liczb rzeczywistych.

---

## 15. Instrukcja warunkowa `if`

Do tej pory większość naszych programów wykonywała wszystkie instrukcje kolejno od góry do dołu.

Instrukcja:

```cpp

if

```

pozwala wykonać fragment kodu tylko wtedy, gdy określony warunek jest prawdziwy.

Schemat:

```cpp

if (warunek) {

    // instrukcje wykonywane,

    // jeśli warunek jest prawdziwy

}

```

Przykład:

```cpp

int liczba;

cin >> liczba;

if (liczba > 100) {

    cout << "Duza liczba" << endl;

}

```

Jeżeli warunek:

```cpp

liczba > 100

```

jest prawdziwy, program wykona instrukcję znajdującą się wewnątrz `{ }`.

---

## 16. `if` i `else`

Jeżeli chcemy obsłużyć dwa przypadki, możemy użyć:

```cpp

if (warunek) {

    // gdy warunek jest prawdziwy

}

else {

    // gdy warunek jest fałszywy

}

```

Przykład:

```cpp

int poziom;

cin >> poziom;

if (poziom >= 50) {

    cout << "Wysoki poziom" << endl;

}

else {

    cout << "Niski poziom" << endl;

}

```

Zostanie wykonany dokładnie jeden z tych dwóch bloków.

---

## 17. `if`, `else if`, `else`

Jeżeli program ma obsługiwać więcej niż dwa przypadki, możemy użyć:

```cpp

if (warunek1) {

    // przypadek 1

}

else if (warunek2) {

    // przypadek 2

}

else {

    // pozostale przypadki

}

```

Przykład:

```cpp

int bateria;

cin >> bateria;

if (bateria < 0 || bateria > 100) {

    cout << "Niepoprawna wartosc" << endl;

}

else if (bateria < 20) {

    cout << "Niski poziom" << endl;

}

else if (bateria < 60) {

    cout << "Sredni poziom" << endl;

}

else {

    cout << "Wysoki poziom" << endl;

}

```

Program sprawdza warunki od góry do dołu.

Po znalezieniu pierwszego prawdziwego warunku wykonuje odpowiedni blok i pomija pozostałe elementy tego łańcucha.

---

## 18. Operatory porównania

W warunkach możemy używać operatorów porównania:

```text

==    równe

!=    różne

<     mniejsze

>     większe

<=    mniejsze lub równe

>=    większe lub równe

```

Przykład:

```cpp

if (x == 10) {

    cout << "x ma wartosc 10" << endl;

}

```

Bardzo ważne:

```cpp

=

```

oznacza przypisanie wartości.

Natomiast:

```cpp

==

```

oznacza porównanie.

Przykład przypisania:

```cpp

x = 10;

```

Przykład porównania:

```cpp

x == 10

```

---

## 19. Operatory logiczne

Warunki możemy ze sobą łączyć.

### Operator AND: `&&`

Oba warunki muszą być prawdziwe.

Przykład:

```cpp

if (x >= 10 && x <= 20) {

    cout << "x jest w przedziale" << endl;

}

```

---

### Operator OR: `||`

Wystarczy, że jeden z warunków jest prawdziwy.

Przykład:

```cpp

if (x < 0 || x > 100) {

    cout << "Wartosc poza zakresem" << endl;

}

```

---

### Operator NOT: `!`

Operator:

```cpp

!

```

oznacza negację warunku.

Przykład:

```cpp

if (!(x == 0)) {

    cout << "x nie jest zerem" << endl;

}

```

---

## 20. Sprawdzanie przedziału

W matematyce możemy zapisać:

```text

10 <= x <= 20

```

W C++ nie zapisujemy warunku w ten sposób.

Poprawnie:

```cpp

if (x >= 10 && x <= 20) {

    cout << "Wartosc nalezy do przedzialu" << endl;

}

```

Jeżeli chcemy sprawdzić, czy wartość znajduje się poza zakresem:

```cpp

if (x < 10 || x > 20) {

    cout << "Wartosc poza przedzialem" << endl;

}

```

---

## 21. Operator modulo `%`

Operator:

```cpp

%

```

zwraca resztę z dzielenia dwóch liczb całkowitych.

Przykład:

```cpp

int reszta = 17 % 5;

```

Wynik:

```text

2

```

ponieważ:

```text

17 = 3 * 5 + 2

```

---

## 22. Sprawdzanie podzielności

Jeżeli liczba jest podzielna przez inną liczbę bez reszty, wynik operacji modulo jest równy:

```text

0

```

Przykład:

```cpp

int x = 30;

if (x % 5 == 0) {

    cout << "Podzielna przez 5" << endl;

}

```

Warunek:

```cpp

x % 5 == 0

```

sprawdza więc, czy `x` jest podzielne przez `5`.

---

## 23. Kilka niezależnych warunków

Nie zawsze powinniśmy używać:

```cpp

else if

```

Jeżeli chcemy sprawdzić kilka niezależnych cech tej samej wartości, możemy użyć kilku osobnych instrukcji `if`.

Przykład:

```cpp

int x;

cin >> x;

if (x > 0) {

    cout << "Dodatnia" << endl;

}

if (x % 3 == 0) {

    cout << "Podzielna przez 3" << endl;

}

if (x % 5 == 0) {

    cout << "Podzielna przez 5" << endl;

}

```

Każdy warunek zostanie tutaj sprawdzony osobno.

Porównaj:

```text

if

if

if

```

z:

```text

if

else if

else

```

W pierwszym przypadku kilka warunków może być prawdziwych jednocześnie.

W drugim przypadku zostanie wybrana jedna gałąź.

---

## 24. Wypisywanie wyniku warunku słowami

Czasami zamiast wartości logicznej chcemy wypisać tekst.

Schemat:

```cpp

if (warunek) {

    cout << "TAK" << endl;

}

else {

    cout << "NIE" << endl;

}

```

Możemy w ten sposób przedstawić wynik dowolnego sprawdzenia.

---

## 25. Wybór jednej z kilku opcji

Program może poprosić użytkownika o wybór określonego wariantu.

Przykład:

```cpp

int wybor;

cout << "[1] Opcja A" << endl;

cout << "[2] Opcja B" << endl;

cout << "Wybor: ";

cin >> wybor;

```

Następnie możemy sprawdzić podaną wartość:

```cpp

if (wybor == 1) {

    cout << "Wybrano opcje A" << endl;

}

else if (wybor == 2) {

    cout << "Wybrano opcje B" << endl;

}

else {

    cout << "Niepoprawny wybor" << endl;

}

```

Jest to prosty schemat menu.

---

## 26. Zmienne wewnątrz instrukcji warunkowej

Przypomnijmy sobie pojęcie zasięgu zmiennej.

Przykład:

```cpp

if (wybor == 1) {

    float x = 2.5f;

    cout << x << endl;

}

```

Zmienna:

```cpp

x

```

jest dostępna tylko wewnątrz bloku `{ }`, w którym została zadeklarowana.

Po wyjściu z tego bloku nie możemy już z niej korzystać.

---

## 27. Różne typy danych w różnych gałęziach programu

Każda gałąź instrukcji warunkowej może zawierać własne zmienne.

Przykład:

```cpp

if (wybor == 1) {

    float x;

    cin >> x;

    // operacje na float

}

else if (wybor == 2) {

    double x;

    cin >> x;

    // operacje na double

}

```

W pierwszym przypadku zmienna ma typ:

```cpp

float

```

a w drugim:

```cpp

double

```

Dzięki temu możemy wykonywać podobne obliczenia z różną precyzją.

---

## 28. Walidacja danych

Walidacja oznacza sprawdzenie, czy dane podane do programu są poprawne.

Przykład:

```cpp

float wilgotnosc;

cin >> wilgotnosc;

if (wilgotnosc < 0.0f || wilgotnosc > 100.0f) {

    cout << "Niepoprawna wartosc" << endl;

}

else {

    cout << "Wartosc zaakceptowana" << endl;

}

```

W tym przykładzie wartości spoza zakresu:

```text

0 ... 100

```

są traktowane jako niepoprawne.

---

## 29. Najpierw sprawdzamy dane, później wykonujemy obliczenia

Jeżeli dla pewnych danych obliczenia nie mają sensu, najpierw należy sprawdzić ich poprawność.

Schemat:

```cpp

if (daneSaNiepoprawne) {

    cout << "Niepoprawne dane" << endl;

}

else {

    // obliczenia

}

```

Dzięki temu nie wykonujemy obliczeń dla wartości, które powinny zostać wcześniej odrzucone.

---

## 30. Granice przedziałów

Przy konstruowaniu warunków należy dokładnie zwracać uwagę na operatory:

```text

<

<=

>

>=

```

Przykład:

```cpp

if (x < 5.0) {

    cout << "Pierwszy zakres" << endl;

}

else if (x <= 8.0) {

    cout << "Drugi zakres" << endl;

}

else {

    cout << "Trzeci zakres" << endl;

}

```

Jeżeli program znalazł się w drugim warunku, wiemy już, że:

```cpp

x >= 5.0

```

ponieważ pierwszy warunek:

```cpp

x < 5.0

```

okazał się fałszywy.

Drugi zakres oznacza więc w praktyce:

```text

5.0 <= x <= 8.0

```

---

## 31. Kolejność warunków ma znaczenie

Rozważ:

```cpp

if (x < 100) {

    cout << "A" << endl;

}

else if (x < 50) {

    cout << "B" << endl;

}

```

Drugi blok nigdy nie zostanie wykonany.

Każda liczba mniejsza od `50` jest jednocześnie mniejsza od `100`.

Zostanie więc obsłużona już przez pierwszy `if`.

Warunki w łańcuchu:

```cpp

if

else if

else if

else

```

należy układać w odpowiedniej kolejności.

---

## 32. Dokładny format wyjścia

Tak jak na poprzednich zajęciach, zadania są sprawdzane automatycznie.

Znaczenie mogą mieć:

- wielkie i małe litery,

- spacje,

- dwukropki,

- kolejność informacji,

- przejścia do nowej linii,

- liczba miejsc po przecinku,

- sposób zapisu liczby.

Jeżeli oczekiwany wynik zawiera:

```text

Status: TAK

```

program powinien wypisać dokładnie taki tekst.

Nie jest tym samym:

```text

status = tak

```

Automatyczny system sprawdzający może uznać drugi zapis za błędny, nawet jeżeli warunek został sprawdzony poprawnie.

---

## 33. Dane testowe nie powinny być wpisywane na stałe

Jeżeli zadanie mówi, że program ma wczytać dane, używamy:

```cpp

cin

```

Przykładowa wartość pokazana w treści zadania służy tylko do zaprezentowania działania programu.

Nie wpisujemy jej na stałe do kodu.

Zamiast:

```cpp

int liczba = 42;

```

jeżeli `42` jest tylko przykładową wartością z testu, używamy:

```cpp

int liczba;

cin >> liczba;

```

---

## 34. Najczęstsze błędy na tym laboratorium

Przed uruchomieniem programu sprawdź:

- czy używasz `==` do porównania, a nie `=`,

- czy granice przedziałów są poprawne,

- czy używasz `&&` i `||` we właściwy sposób,

- czy nie zapisujesz warunku matematycznie jako `a < x < b`,

- czy przy sprawdzaniu podzielności używasz `%`,

- czy nie mylisz `%` z `/`,

- czy po `hex` lub `oct` wracasz do `dec`, jeśli jest to potrzebne,

- czy używasz właściwego typu: `char`, `int`, `float` albo `double`,

- czy przy dzieleniu liczb rzeczywistych nie wykonujesz przypadkiem dzielenia całkowitego,

- czy przy `setprecision()` masz `#include <iomanip>`,

- czy format wyjścia jest zgodny z treścią zadania,

- czy obsługujesz wartości niepoprawne,

- czy warunki `if`, `else if` i `else` znajdują się w logicznej kolejności.

---

## 35. Najważniejszy schemat programu z warunkami

Na tym laboratorium wiele programów będzie miało strukturę podobną do:

```cpp

#include <iostream>

using namespace std;

int main() {

    // deklaracja zmiennych

    // wczytanie danych

    if (warunek) {

        // instrukcje dla pierwszego przypadku

    }

    else {

        // instrukcje dla drugiego przypadku

    }

    return 0;

}

```

Jeżeli potrzebujemy kilku możliwości:

```cpp

#include <iostream>

using namespace std;

int main() {

    // deklaracja zmiennych

    // wczytanie danych

    if (warunek1) {

        // pierwszy przypadek

    }

    else if (warunek2) {

        // drugi przypadek

    }

    else {

        // pozostale przypadki

    }

    return 0;

}

```

Jeżeli dodatkowo formatujemy liczby rzeczywiste:

```cpp

#include <iostream>

#include <iomanip>

using namespace std;

int main() {

    // deklaracja zmiennych

    // wczytanie danych

    // obliczenia

    cout << fixed << setprecision(2);

    // wyświetlenie wyniku

    return 0;

}

```

---

## 36. Schemat pracy nad zadaniem

Przed rozpoczęciem pisania kodu zastanów się:

1. Jakie dane program ma wczytać?

2. Jakiego typu powinny być zmienne?

3. Czy potrzebuję `char`, `int`, `float` czy `double`?

4. Czy program ma wybrać jedną z kilku możliwości?

5. Jakie warunki należy sprawdzić?

6. Czy warunki są niezależne?

7. Czy tylko jeden przypadek powinien zostać wykonany?

8. Czy potrzebuję operatora `%`?

9. Czy wynik ma być wyświetlany w innym systemie liczbowym?

10. Czy wynik ma mieć określoną liczbę miejsc po przecinku?

11. Czy istnieją wartości wejściowe, które należy odrzucić?

12. Czy kolejność warunków jest poprawna?

13. Czy format wyjścia dokładnie odpowiada treści zadania?

Typowy schemat:

```text

biblioteki

    ↓

using namespace

    ↓

main()

    ↓

deklaracja zmiennych

    ↓

wczytanie danych

    ↓

sprawdzenie poprawności danych

    ↓

sprawdzenie warunków

    ↓

obliczenia

    ↓

wyświetlenie wyniku

    ↓

return 0

```

Na tym laboratorium najważniejsze jest zrozumienie, że program może wykonywać różne fragmenty kodu zależnie od danych wejściowych oraz że wybór odpowiedniego typu danych wpływa na sposób wykonywania obliczeń.
