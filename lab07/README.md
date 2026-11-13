# Laboratorium 07: tablice, tekst, bisekcja i dynamiczne tablice dwuwymiarowe

Na tym laboratorium pojawiają się bardziej złożone zagadnienia łączące wcześniejsze elementy języka C++.

Będziemy pracować między innymi z:

- tablicami jednowymiarowymi,
- przechowywaniem współczynników wielomianu,
- obliczaniem wartości wielomianu,
- metodą bisekcji,
- rekurencyjnym zawężaniem przedziału,
- wczytywaniem całej linii tekstu,
- zmianą wielkości liter,
- biblioteką `<cctype>`,
- dynamiczną alokacją pamięci,
- dynamicznymi tablicami dwuwymiarowymi,
- transpozycją macierzy,
- formatowaniem kolumn za pomocą `setw`,
- wypełnianiem tablicy według określonego porządku,
- sterowaniem granicami podczas przechodzenia po macierzy.

Przykłady w tym materiale pokazują mechanizmy potrzebne do rozwiązania zadań.

Nie są jednak gotowymi rozwiązaniami zadań laboratoryjnych.

---

# Część I: tablice jednowymiarowe i wielomiany

## 1. Tablica

Tablica pozwala przechowywać wiele wartości tego samego typu pod jedną nazwą.

Przykład:

```cpp
int liczby[5];
```

Tworzy tablicę pięciu liczb całkowitych.

Elementy mają indeksy:

```text
0
1
2
3
4
```

Pierwszy element:

```cpp
liczby[0]
```

Ostatni element:

```cpp
liczby[4]
```

---

## 2. Indeksy tablic zaczynają się od `0`

Dla:

```cpp
double dane[4];
```

poprawne indeksy to:

```text
dane[0]
dane[1]
dane[2]
dane[3]
```

Nie istnieje element:

```cpp
dane[4]
```

Odwołanie poza zakresem tablicy prowadzi do błędnego działania programu.

---

## 3. Wczytywanie elementów tablicy w pętli

Tablice bardzo często współpracują z pętlami.

Przykład:

```cpp
int dane[5];

for (int i = 0; i < 5; i++) {
    cin >> dane[i];
}
```

Każdy obieg pętli zapisuje wartość do kolejnego elementu.

---

## 4. Tablica współczynników wielomianu

Wielomian:

```text
a₀ + a₁x + a₂x² + a₃x³ + ...
```

możemy przechować w tablicy.

Przykładowo wielomian:

```text
2 + 3x - 4x²
```

ma współczynniki:

```text
a₀ = 2
a₁ = 3
a₂ = -4
```

Możemy więc myśleć o tablicy:

```text
indeks:       0   1   2
współczynnik: 2   3  -4
```

Indeks elementu odpowiada potędze `x`.

---

## 5. Stopień wielomianu a liczba współczynników

Jeżeli wielomian ma stopień:

```text
n
```

to potrzebujemy:

```text
n + 1
```

współczynników.

Dla stopnia `3`:

```text
a₀ + a₁x + a₂x² + a₃x³
```

mamy cztery współczynniki.

Czyli:

```text
stopień 3 -> 4 współczynniki
stopień 5 -> 6 współczynników
```

---

## 6. Obliczanie wartości wielomianu

Jeżeli znamy współczynniki i wartość `x`, wartość wielomianu obliczamy jako:

```text
W(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ
```

Przykład:

```text
W(x) = 2 + 3x - x²
```

Dla:

```text
x = 2
```

otrzymujemy:

```text
W(2) = 2 + 3*2 - 2²
     = 2 + 6 - 4
     = 4
```

---

## 7. Wielomian można obliczać w pętli

Jeżeli współczynniki znajdują się w tablicy, możemy przechodzić po nich pętlą.

Ogólny schemat:

```cpp
double wynik = 0;

for (int i = 0; i <= n; i++) {

    // dodanie składnika odpowiadającego potędze i
}
```

W każdym obiegu wykorzystujemy:

```text
współczynnik o indeksie i
```

oraz:

```text
x do potęgi i
```

---

## 8. Funkcja obliczająca wielomian

W zadaniach bardziej złożonych warto wydzielić obliczanie wielomianu do osobnej funkcji.

Schemat funkcji:

```cpp
double wartoscWielomianu(double x, /* współczynniki */, int stopien) {

    double wynik = 0;

    // obliczenia

    return wynik;
}
```

Dzięki temu ten sam kod można wykorzystać wielokrotnie dla różnych wartości `x`.

To szczególnie ważne przy bisekcji, gdzie wartość funkcji będzie sprawdzana wiele razy.

---

# Część II: metoda bisekcji

## 9. Co to jest miejsce zerowe funkcji?

Miejsce zerowe funkcji to taka wartość:

```text
x₀
```

dla której:

```text
f(x₀) = 0
```

Przykład:

```text
f(x) = 2x - 6
```

Miejsce zerowe spełnia:

```text
2x - 6 = 0
```

czyli:

```text
x = 3
```

---

## 10. Na czym polega bisekcja?

Bisekcja, czyli metoda połowienia przedziału, polega na wielokrotnym dzieleniu przedziału na pół.

Mamy początkowy przedział:

```text
[a, b]
```

i obliczamy jego środek:

```text
c = (a + b) / 2
```

Następnie sprawdzamy, w której połowie może znajdować się miejsce zerowe.

Schemat:

```text
[a ---------------- b]
          c
```

Po sprawdzeniu znaków funkcji pozostawiamy tylko jedną połowę:

```text
[a ----- c]
```

albo:

```text
[c ----- b]
```

i powtarzamy procedurę.

---

## 11. Dlaczego znaki funkcji są ważne?

Dla funkcji ciągłej, takiej jak wielomian, jeżeli:

```text
f(a) < 0
```

oraz:

```text
f(b) > 0
```

to pomiędzy `a` i `b` znajduje się co najmniej jedno miejsce zerowe.

Analogicznie może być:

```text
f(a) > 0
f(b) < 0
```

Najważniejsze jest to, że wartości mają różne znaki.

Można to sprawdzić:

```text
f(a) * f(b) < 0
```

---

## 12. Przykład działania bisekcji

Rozważmy prostą funkcję:

```text
f(x) = x - 5
```

i przedział:

```text
[0, 8]
```

Na końcach:

```text
f(0) = -5
f(8) = 3
```

Znaki są różne.

Obliczamy środek:

```text
c = (0 + 8) / 2 = 4
```

Sprawdzamy:

```text
f(4) = -1
```

Mamy więc:

```text
f(4) < 0
f(8) > 0
```

Zostawiamy przedział:

```text
[4, 8]
```

Następny środek:

```text
c = (4 + 8) / 2 = 6
```

```text
f(6) = 1
```

Teraz znak zmienia się pomiędzy:

```text
4 i 6
```

więc nowy przedział to:

```text
[4, 6]
```

Następnie:

```text
c = 5
```

i:

```text
f(5) = 0
```

Znaleźliśmy miejsce zerowe.

---

## 13. Co dokładnie robimy w każdym kroku bisekcji?

W każdym kroku:

```text
1. obliczamy środek c
2. obliczamy f(a)
3. obliczamy f(c)
4. sprawdzamy znaki
5. wybieramy lewą lub prawą połowę
6. powtarzamy
```

---

## 14. Jak zdecydować, którą połowę zostawić?

Jeżeli:

```text
f(a) i f(c)
```

mają różne znaki, miejsce zerowe znajduje się w:

```text
[a, c]
```

Jeżeli nie, sprawdzamy drugą połowę:

```text
[c, b]
```

Możemy myśleć:

```text
czy znak zmienia się pomiędzy a i c?

TAK -> szukaj w [a, c]
NIE -> szukaj w [c, b]
```

---

## 15. Kiedy zakończyć bisekcję?

Komputer nie może dzielić przedziału w nieskończoność.

Potrzebujemy warunku zakończenia.

W metodach numerycznych bardzo często używamy do tego wartości:

```text
epsilon
```

oznaczanej matematycznie jako:

```text
ε
```

---

## 16. Co to jest epsilon?

`Epsilon` oznacza **dopuszczalny błąd**, czyli dokładność, z jaką chcemy znaleźć wynik.

Jeżeli w zadaniu podano dokładność:

```text
0.001
```

możemy przyjąć:

```cpp
double epsilon = 0.001;
```

Nie oznacza to, że komputer znajdzie idealne miejsce zerowe.

Oznacza to, że przestajemy dzielić przedział wtedy, gdy uznamy, że dalsze zawężanie nie jest już potrzebne.

Im mniejszy `epsilon`, tym dokładniejszy wynik, ale tym więcej kroków bisekcji trzeba wykonać.

Przykładowo:

```text
epsilon = 0.1
```

daje mniejszą dokładność niż:

```text
epsilon = 0.001
```

a:

```text
epsilon = 0.000001
```

wymaga jeszcze dokładniejszego zawężenia przedziału.

---

## 17. Epsilon jako dokładność przedziału

Najbardziej naturalnym warunkiem stopu w bisekcji jest sprawdzenie długości aktualnego przedziału.

Jeżeli:

```text
|b - a| < epsilon
```

to przedział jest już bardzo mały i możemy przyjąć jego środek jako przybliżone miejsce zerowe.

Przykład:

```text
a = 1.4140
b = 1.4148

epsilon = 0.001
```

Długość przedziału:

```text
|1.4148 - 1.4140| = 0.0008
```

Ponieważ:

```text
0.0008 < 0.001
```

możemy zakończyć bisekcję.

Przybliżeniem miejsca zerowego będzie środek:

```text
c = (1.4140 + 1.4148) / 2
  = 1.4144
```

---

## 18. Inny możliwy warunek: wartość funkcji bliska zeru

Możemy również sprawdzić, czy wartość funkcji w środku przedziału jest dostatecznie bliska zeru.

Czyli:

```text
|f(c)| < epsilon
```

Przykład:

```text
f(c) = 0.0003
epsilon = 0.001
```

Ponieważ:

```text
|0.0003| < 0.001
```

możemy uznać, że znaleziony punkt jest wystarczająco blisko miejsca zerowego.

---

## 19. Który warunek stopu wybrać?

W bisekcji bardzo często stosuje się warunek oparty na długości przedziału:

```text
|b - a| < epsilon
```

ponieważ dokładnie odpowiada idei metody: z każdym krokiem zawężamy przedział.

Można też dodatkowo sprawdzać:

```text
|f(c)| < epsilon
```

Wtedy algorytm może zakończyć się wcześniej, jeżeli trafi bardzo blisko miejsca zerowego.

Można więc myśleć:

```text
jeżeli przedział jest wystarczająco mały
LUB
wartość funkcji jest wystarczająco bliska 0

-> zakończ
```

---

## 20. Gdzie epsilon pojawia się w algorytmie?

Schemat bisekcji z epsilonem:

```text
bisekcja(a, b)
        |
        +-- oblicz środek:
        |      c = (a + b) / 2
        |
        +-- sprawdź warunek stopu:
        |
        |      czy |b - a| < epsilon?
        |
        |      TAK
        |       |
        |       +-- zwróć c
        |
        +-- sprawdź, w której połowie
        |   zmienia się znak funkcji
        |
        +-- wywołaj bisekcję ponownie
               dla mniejszego przedziału
```

Czyli epsilon jest sprawdzany **w każdym wywołaniu rekurencyjnym**.

---

## 21. Epsilon a rekurencja

Każde kolejne wywołanie funkcji dostaje mniejszy przedział.

Na początku może być:

```text
[-10, 10]
```

Długość:

```text
20
```

Po jednym kroku:

```text
10
```

potem:

```text
5
```

następnie:

```text
2.5
1.25
0.625
0.3125
...
```

W pewnym momencie otrzymamy:

```text
|b - a| < 0.001
```

i wtedy rekurencja się zatrzyma.

To właśnie `epsilon` wyznacza moment zakończenia.

---

## 22. Przypadek bazowy rekurencji z epsilonem

W rekurencji musimy mieć przypadek bazowy.

Dla bisekcji może on mieć postać logiczną:

```text
jeżeli długość przedziału jest mniejsza od epsilon
    zwróć środek przedziału
```

Czyli:

```text
JEŻELI |b - a| < epsilon
    KONIEC
```

W przeciwnym razie:

```text
wybierz połowę przedziału
i wywołaj funkcję ponownie
```

Bez tego warunku rekurencja nie wiedziałaby, kiedy zakończyć działanie.

---

## 23. Bisekcja rekurencyjna

Bisekcja bardzo dobrze nadaje się do rekurencji.

Każde wywołanie funkcji pracuje na mniejszym przedziale.

Schemat:

```text
bisekcja(a, b)
        |
        +-- oblicz środek c
        |
        +-- czy dokładność wystarcza?
        |       |
        |       TAK -> zwróć wynik
        |
        +-- wybierz połowę
                |
                +-- bisekcja(a, c)

lub

                +-- bisekcja(c, b)
```

Najważniejsze jest to, że kolejne wywołanie dostaje **mniejszy przedział**.

---

## 24. Przypadek bazowy rekurencji w bisekcji

Rekurencja musi mieć warunek zakończenia.

Przykładowa idea:

```text
jeżeli przedział jest już wystarczająco mały
    zwróć środek
```

Bez takiego warunku funkcja wywoływałaby się dalej bez końca.

---

## 25. Kiedy bisekcja może nie zadziałać?

Metoda bisekcji nie gwarantuje znalezienia każdego miejsca zerowego w dowolnym przedziale.

Najprostszy przypadek problematyczny:

```text
f(a)
```

oraz:

```text
f(b)
```

mają ten sam znak.

Przykład:

```text
f(x) = x² + 1
```

Ta funkcja nie ma rzeczywistych miejsc zerowych.

Dla dowolnego `x`:

```text
x² + 1 > 0
```

Nie następuje więc zmiana znaku.

---

## 26. Uwaga: brak zmiany znaku nie zawsze oznacza brak miejsca zerowego

Rozważmy:

```text
f(x) = x²
```

W przedziale:

```text
[-1, 1]
```

mamy:

```text
f(-1) = 1
f(1) = 1
```

Znaki są takie same.

A jednak:

```text
f(0) = 0
```

Istnieje miejsce zerowe.

Dlatego klasyczna metoda bisekcji oparta na zmianie znaku nie wykryje wszystkich możliwych przypadków.

To właśnie dlatego w treści zadania pojawia się informacja:

> Metoda ta nie zawsze znajduje miejsce zerowe.

---

# Część III: tekst i zmiana wielkości liter

## 27. `char` a `string`

Typ:

```cpp
char
```

przechowuje pojedynczy znak.

Przykład:

```cpp
char znak = 'A';
```

Natomiast:

```cpp
string
```

przechowuje tekst.

Przykład:

```cpp
string napis = "Ala ma kota";
```

Do korzystania z `string` używamy:

```cpp
#include <string>
```

---

## 28. Wczytywanie tekstu przez `cin`

Instrukcja:

```cpp
cin >> tekst;
```

wczytuje tekst tylko do pierwszego białego znaku.

Dla wejścia:

```text
Ala ma kota
```

zostanie wczytane tylko:

```text
Ala
```

Dlatego do całych linii potrzebujemy innego rozwiązania.

---

## 29. `getline`

Całą linię tekstu wczytujemy za pomocą:

```cpp
getline(cin, tekst);
```

Przykład:

```cpp
string tekst;

cout << "Tekst: ";
getline(cin, tekst);
```

Wtedy można wczytać:

```text
Ala ma kota i psa
```

razem ze spacjami.

---

## 30. Problem `cin >>` i `getline`

Jeżeli wcześniej wykonamy:

```cpp
cin >> liczba;
```

a później:

```cpp
getline(cin, tekst);
```

w buforze wejściowym może pozostać znak nowej linii.

Wtedy `getline` może odczytać pustą linię.

Jednym ze sposobów rozwiązania tego problemu jest:

```cpp
cin.ignore();
```

przed `getline`.

W prostych programach warto pamiętać o tym problemie przy łączeniu obu metod wczytywania.

---

## 31. Przechodzenie po znakach tekstu

Do każdego znaku `string` możemy odwołać się przez indeks.

Przykład:

```cpp
string tekst = "Kot";

cout << tekst[0] << endl;
cout << tekst[1] << endl;
cout << tekst[2] << endl;
```

otrzymamy:

```text
K
o
t
```

---

## 32. Przetwarzanie tekstu w pętli

Możemy przejść przez wszystkie znaki:

```cpp
for (int i = 0; i < tekst.length(); i++) {

    // operacja na tekst[i]
}
```

Każdy obieg pętli dotyczy jednego znaku.

---

## 33. Biblioteka `<cctype>`

Do prostych operacji na znakach przydaje się:

```cpp
#include <cctype>
```

Znajdują się tam między innymi funkcje:

```cpp
tolower()
toupper()
isalpha()
isspace()
```

---

## 34. `tolower`

Funkcja:

```cpp
tolower(znak)
```

zamienia literę na małą.

Przykład:

```cpp
char znak = 'G';

znak = tolower(znak);
```

Po operacji:

```text
g
```

---

## 35. `toupper`

Funkcja:

```cpp
toupper(znak)
```

zamienia literę na wielką.

Przykład:

```cpp
char znak = 'k';

znak = toupper(znak);
```

Po operacji:

```text
K
```

---

## 36. Zamiana całego tekstu na małe litery

Mechanizm:

```cpp
for (int i = 0; i < tekst.length(); i++) {
    tekst[i] = tolower(tekst[i]);
}
```

Pętla przechodzi po każdym znaku i zmienia jego wielkość.

---

## 37. Zamiana całego tekstu na wielkie litery

Analogicznie:

```cpp
for (int i = 0; i < tekst.length(); i++) {
    tekst[i] = toupper(tekst[i]);
}
```

---

## 38. Co oznacza zapis tytułowy?

W zapisie tytułowym:

```text
Ala Ma Kota
```

pierwsza litera każdego słowa jest wielka.

Pozostałe litery są małe.

Przykład:

```text
programowanie komputerów
```

po zmianie:

```text
Programowanie Komputerów
```

---

## 39. Jak rozpoznać początek słowa?

Pierwszy znak tekstu jest początkiem słowa.

Nowe słowo zaczyna się również po spacji.

Możemy więc analizować:

```text
czy aktualny znak jest pierwszym znakiem tekstu?
```

lub:

```text
czy poprzedni znak był spacją?
```

Przykład:

```text
ala ma kota
^   ^  ^
```

Właśnie te miejsca powinny zostać zamienione na wielkie litery.

---

## 40. Przykład analizy tytułowego zapisu

Dla:

```text
kot ma mleko
```

indeksy:

```text
0 1 2 3 4 5 6 7 8 9 10 11
k o t   m a   m l e  k  o
```

Wielkimi literami powinny zostać znaki:

```text
tekst[0]
tekst[4]
tekst[7]
```

ponieważ są pierwszymi znakami kolejnych słów.

---

## 41. Uwaga dotycząca UTF-8 i polskich znaków

Funkcje:

```cpp
tolower()
toupper()
```

działają prosto dla podstawowego zestawu znaków, np.:

```text
A-Z
a-z
```

Kodowanie UTF-8 jest bardziej złożone.

Polskie znaki, takie jak:

```text
ą ć ę ł ń ó ś ź ż
```

mogą być zapisane w UTF-8 za pomocą więcej niż jednego bajtu.

Dlatego zwykłe przechodzenie po `string` znak po znaku nie jest pełnym rozwiązaniem dla wszystkich znaków Unicode.

Jeżeli zadania testowe wykorzystują podstawowe litery alfabetu angielskiego, standardowe `tolower()` i `toupper()` są wystarczające.

---


# Część III-A: UTF-8 i polskie litery

## 42. Jak polskie litery są zapisane w UTF-8?

W zwykłym alfabecie angielskim litery takie jak:

```text
A
B
C
a
b
c
```

są zapisywane w UTF-8 za pomocą jednego bajtu.

Przykładowo:

```text
A -> 41
a -> 61
```

Polskie znaki, takie jak:

```text
ą ć ę ł ń ó ś ź ż
```

są w UTF-8 zapisywane za pomocą dwóch bajtów.

Dlatego jeden widoczny znak nie zawsze odpowiada jednemu elementowi typu:

```cpp
char
```

---

## 43. Tabela polskich liter w UTF-8

| Litera | UTF-8 hex |
|---|---|
| Ą | `C4 84` |
| ą | `C4 85` |
| Ć | `C4 86` |
| ć | `C4 87` |
| Ę | `C4 98` |
| ę | `C4 99` |
| Ł | `C5 81` |
| ł | `C5 82` |
| Ń | `C5 83` |
| ń | `C5 84` |
| Ó | `C3 93` |
| ó | `C3 B3` |
| Ś | `C5 9A` |
| ś | `C5 9B` |
| Ź | `C5 B9` |
| ź | `C5 BA` |
| Ż | `C5 BB` |
| ż | `C5 BC` |

Warto zauważyć, że jedna polska litera jest reprezentowana przez dwa bajty.

Przykład:

```text
ą -> C4 85
```

czyli w pamięci znajdują się dwa bajty:

```text
C4
85
```

---

## 44. Duża i mała litera w UTF-8

Dla części polskich liter zmiana wielkości litery zmienia tylko drugi bajt.

Przykład:

```text
Ą -> C4 84
ą -> C4 85
```

oraz:

```text
Ć -> C4 86
ć -> C4 87
```

Podobnie:

```text
Ł -> C5 81
ł -> C5 82
```

Nie oznacza to jednak, że dla każdej litery można zastosować jedną prostą regułę arytmetyczną.

Przykład:

```text
Ó -> C3 93
ó -> C3 B3
```

Tutaj różnica wygląda inaczej.

Dlatego przy UTF-8 nie należy zakładać, że:

```text
mała litera = duża litera + stała wartość
```

dla wszystkich znaków.

---

## 45. Dlaczego to ma znaczenie w `string`?

W C++ obiekt:

```cpp
string
```

przechowuje ciąg bajtów.

Dla zwykłych liter:

```text
Ala
```

każda litera zajmuje jeden bajt.

Natomiast dla:

```text
Łódź
```

niektóre widoczne znaki zajmują po dwa bajty.

Dlatego:

```cpp
tekst.length()
```

dla tekstu zawierającego polskie litery może zwrócić liczbę bajtów większą niż liczba znaków widocznych na ekranie.

---

## 46. Przykład: jeden znak, dwa bajty

Dla litery:

```text
ż
```

UTF-8:

```text
C5 BC
```

czyli:

```text
pierwszy bajt:  C5
drugi bajt:     BC
```

Jeżeli przechodzimy po `string`:

```cpp
for (int i = 0; i < tekst.length(); i++) {
    cout << tekst[i] << endl;
}
```

to program przechodzi po kolejnych bajtach, a nie po znakach rozumianych jako pełne litery Unicode.

To ważna różnica przy pracy z polskimi znakami.

---

## 47. ASCII a UTF-8

Dla podstawowych znaków alfabetu angielskiego UTF-8 zachowuje te same wartości co ASCII.

Przykład:

```text
A -> 41
B -> 42
C -> 43

a -> 61
b -> 62
c -> 63
```

Tutaj przejście z wielkiej litery na małą wygląda regularnie:

```text
A -> 41
a -> 61
```

Różnica wynosi:

```text
20 hex
```

Dla polskich liter zapisanych dwoma bajtami nie można przyjąć jednej takiej reguły dla wszystkich znaków.

---

## 48. Tabela UTF-8 online

Pełną tabelę znaków można znaleźć tutaj:

[UTF-8 Character Table](https://www.utf8-chartable.de/unicode-utf8-table.pl?start=256&names=-&utf8=0x)

W tabeli można odszukać między innymi polskie litery i zobaczyć ich zapis bajtowy w UTF-8.

---


# Część IV: dynamiczna pamięć

## 49. Tablica statyczna

Dotychczas mogliśmy tworzyć tablice:

```cpp
int tab[10];
```

Rozmiar jest tutaj ustalony przy tworzeniu tablicy.

---

## 50. Po co dynamiczna alokacja?

Czasami rozmiar tablicy poznajemy dopiero podczas działania programu.

Na przykład użytkownik podaje:

```text
N
M
```

Dopiero wtedy wiemy, ile elementów potrzebujemy.

Do dynamicznego przydzielenia pamięci używamy:

```cpp
new
```

---

## 51. Dynamiczna tablica jednowymiarowa

Przykład:

```cpp
int n;

cin >> n;

int* tablica = new int[n];
```

Po tej instrukcji mamy tablicę o `n` elementach.

Możemy korzystać z niej:

```cpp
tablica[0]
tablica[1]
...
```

---

## 52. Zwalnianie pamięci

Pamięć utworzoną przez:

```cpp
new[]
```

należy później zwolnić:

```cpp
delete[] tablica;
```

Dobra zasada:

```text
new[] -> delete[]
```

---

# Część V: dynamiczna tablica dwuwymiarowa

## 53. Tablica dwuwymiarowa

Tablicę dwuwymiarową możemy traktować jako tabelę:

```text
wiersze × kolumny
```

Przykład:

```text
3 × 4
```

oznacza:

```text
3 wiersze
4 kolumny
```

---

## 54. Indeksy tablicy 2D

Element oznaczamy:

```cpp
tablica[wiersz][kolumna]
```

Przykładowo:

```cpp
tablica[1][2]
```

oznacza:

```text
wiersz 1
kolumna 2
```

Pamiętaj, że indeksy zaczynają się od `0`.

---

## 55. Dynamiczna tablica 2D jako tablica wskaźników

Jednym ze sposobów utworzenia dynamicznej tablicy 2D jest:

```cpp
int** tablica;
```

Najpierw tworzymy tablicę wskaźników na wiersze:

```cpp
tablica = new int*[N];
```

Następnie dla każdego wiersza tworzymy tablicę kolumn:

```cpp
for (int i = 0; i < N; i++) {
    tablica[i] = new int[M];
}
```

Możemy to sobie wyobrazić:

```text
tablica
  |
  +-- wiersz 0 -> [ ][ ][ ][ ]
  +-- wiersz 1 -> [ ][ ][ ][ ]
  +-- wiersz 2 -> [ ][ ][ ][ ]
```

---

## 56. Funkcja alokująca tablicę 2D

Jeżeli alokację wykonujemy wielokrotnie, warto utworzyć funkcję.

Ogólny schemat:

```cpp
int** alokuj(int wiersze, int kolumny) {

    int** tablica = new int*[wiersze];

    for (int i = 0; i < wiersze; i++) {
        tablica[i] = new int[kolumny];
    }

    return tablica;
}
```

Funkcja zwraca adres utworzonej tablicy.

---

## 57. Zwalnianie dynamicznej tablicy 2D

Najpierw zwalniamy każdy wiersz:

```cpp
for (int i = 0; i < N; i++) {
    delete[] tablica[i];
}
```

Na końcu:

```cpp
delete[] tablica;
```

Kolejność ma znaczenie.

Najpierw:

```text
wiersze
```

potem:

```text
tablica wskaźników
```

---


# Część V-A: tablice statyczne i dynamiczne

## 58. Tablica statyczna jednowymiarowa

Tablica statyczna ma rozmiar ustalony podczas kompilacji programu.

Przykład:

```cpp
int tablica[5];
```

Tworzymy pięć elementów typu `int`:

```text
indeks:     0   1   2   3   4
wartość:   ?   ?   ?   ?   ?
```

Możemy przypisywać wartości:

```cpp
tablica[0] = 10;
tablica[1] = 20;
```

albo wypełniać tablicę w pętli:

```cpp
for (int i = 0; i < 5; i++) {
    tablica[i] = i * 2;
}
```

Ważne:

```text
int tablica[5];
```

oznacza pięć elementów, ale ostatni poprawny indeks to:

```text
4
```

---

## 59. Tablica dynamiczna jednowymiarowa

Jeżeli rozmiar tablicy poznajemy dopiero podczas działania programu, możemy zaalokować pamięć dynamicznie.

Przykład:

```cpp
int n;

cin >> n;

int* tablica = new int[n];
```

Zmienna:

```cpp
tablica
```

jest wskaźnikiem na pierwszy element utworzonej tablicy.

Możemy jednak korzystać z niej tak samo jak ze zwykłej tablicy:

```cpp
tablica[0]
tablica[1]
tablica[2]
```

---

## 60. Dlaczego przy tablicy dynamicznej używamy wskaźnika?

Instrukcja:

```cpp
new int[n]
```

tworzy w pamięci miejsce dla `n` elementów typu `int`.

Operator `new[]` zwraca adres początku tego obszaru pamięci.

Dlatego zapisujemy go w zmiennej wskaźnikowej:

```cpp
int* tablica
```

Można to sobie wyobrazić:

```text
tablica
   |
   v
+----+----+----+----+----+
|    |    |    |    |    |
+----+----+----+----+----+
  0    1    2    3    4
```

---

## 61. Zwalnianie dynamicznej tablicy 1D

Pamięć utworzoną przez:

```cpp
new[]
```

należy zwolnić przez:

```cpp
delete[]
```

Przykład:

```cpp
int* tablica = new int[n];

// korzystanie z tablicy

delete[] tablica;
```

Dobra zasada:

```text
new[]  -> delete[]
```

Po:

```cpp
delete[] tablica;
```

nie należy już korzystać z elementów tej tablicy.

---

## 62. Tablica statyczna dwuwymiarowa

Tablicę dwuwymiarową możemy potraktować jako tabelę.

Przykład:

```cpp
int tablica[2][3];
```

oznacza:

```text
2 wiersze
3 kolumny
```

Możemy ją sobie wyobrazić:

```text
        kolumna
          0   1   2

wiersz 0 [ ] [ ] [ ]
wiersz 1 [ ] [ ] [ ]
```

Dostęp do elementu:

```cpp
tablica[wiersz][kolumna]
```

Na przykład:

```cpp
tablica[1][2] = 7;
```

---

## 63. Wypełnianie statycznej tablicy 2D

Najczęściej wykorzystujemy dwie pętle:

```cpp
for (int i = 0; i < 2; i++) {

    for (int j = 0; j < 3; j++) {

        tablica[i][j] = 0;
    }
}
```

Pierwsza pętla zmienia numer wiersza:

```text
i
```

Druga zmienia numer kolumny:

```text
j
```

---

## 64. Dynamiczna tablica dwuwymiarowa

Jeżeli liczba wierszy i kolumn jest znana dopiero podczas działania programu, możemy utworzyć tablicę dynamiczną.

Przykład:

```cpp
int N;
int M;

cin >> N >> M;
```

Najpierw tworzymy tablicę wskaźników na wiersze:

```cpp
int** tablica = new int*[N];
```

Następnie dla każdego wiersza tworzymy miejsce na `M` elementów:

```cpp
for (int i = 0; i < N; i++) {
    tablica[i] = new int[M];
}
```

---

## 65. Jak wygląda dynamiczna tablica 2D w pamięci?

Możemy ją sobie wyobrazić tak:

```text
tablica
   |
   v
+-------+
|   *---+------> [ ][ ][ ][ ]
+-------+
|   *---+------> [ ][ ][ ][ ]
+-------+
|   *---+------> [ ][ ][ ][ ]
+-------+
```

Pierwsza tablica przechowuje adresy wierszy.

Każdy wiersz jest osobną dynamiczną tablicą jednowymiarową.

Dlatego używamy typu:

```cpp
int**
```

czyli wskaźnika do wskaźnika.

---

## 66. Wypełnianie dynamicznej tablicy 2D

Po zaalokowaniu pamięci korzystamy z niej tak samo:

```cpp
for (int i = 0; i < N; i++) {

    for (int j = 0; j < M; j++) {

        tablica[i][j] = 0;
    }
}
```

---

## 67. Zwalnianie dynamicznej tablicy 2D

Pamięć trzeba zwolnić w odwrotnej kolejności niż była tworzona.

Najpierw każdy wiersz:

```cpp
for (int i = 0; i < N; i++) {
    delete[] tablica[i];
}
```

Następnie tablicę wskaźników:

```cpp
delete[] tablica;
```

Czyli:

```text
1. usuń wiersze
2. usuń tablicę adresów wierszy
```

---

# Część V-B: przekazywanie tablic do funkcji

## 68. Przekazywanie statycznej tablicy 1D do funkcji

Dla tablic jednowymiarowych możemy napisać funkcję:

```cpp
void wypisz(int tablica[], int rozmiar) {

    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
}
```

Wywołanie:

```cpp
int dane[5] = {1, 2, 3, 4, 5};

wypisz(dane, 5);
```

W parametrze:

```cpp
int tablica[]
```

tablica jest przekazywana do funkcji jako adres jej pierwszego elementu.

Dlatego funkcja powinna dostać również informację o jej rozmiarze.

---

## 69. Równoważny zapis parametru tablicy 1D

W parametrze funkcji zapis:

```cpp
int tablica[]
```

jest w praktyce równoważny:

```cpp
int* tablica
```

Możemy więc spotkać oba zapisy:

```cpp
void wypisz(int tablica[], int n)
```

oraz:

```cpp
void wypisz(int* tablica, int n)
```

W obu przypadkach funkcja otrzymuje dostęp do elementów istniejącej tablicy.

---

## 70. Czy funkcja może zmienić elementy przekazanej tablicy?

Tak.

Przykład:

```cpp
void wyzeruj(int tablica[], int n) {

    for (int i = 0; i < n; i++) {
        tablica[i] = 0;
    }
}
```

Jeżeli wywołamy:

```cpp
int dane[3] = {4, 5, 6};

wyzeruj(dane, 3);
```

to po powrocie z funkcji zawartość `dane` będzie zmieniona.

Dzieje się tak dlatego, że funkcja pracuje na pamięci należącej do tej samej tablicy.

---

## 71. Przekazywanie dynamicznej tablicy 1D do funkcji

Dynamiczną tablicę przekazujemy tak samo, ponieważ zmienna przechowuje wskaźnik:

```cpp
void wypisz(int* tablica, int n) {

    for (int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
}
```

Przykład użycia:

```cpp
int* dane = new int[n];

// ...

wypisz(dane, n);

// ...

delete[] dane;
```

Funkcja nie musi wiedzieć, czy tablica została utworzona jako:

```cpp
int dane[10];
```

czy jako:

```cpp
int* dane = new int[n];
```

W obu przypadkach otrzymuje adres pierwszego elementu.

---

## 72. Przekazywanie statycznej tablicy 2D do funkcji

Przy zwykłej tablicy dwuwymiarowej kompilator musi znać liczbę kolumn.

Przykład:

```cpp
void wypisz(int tablica[][4], int wiersze) {

    for (int i = 0; i < wiersze; i++) {

        for (int j = 0; j < 4; j++) {
            cout << tablica[i][j] << " ";
        }

        cout << endl;
    }
}
```

Możemy przekazać:

```cpp
int dane[3][4];
```

Liczba wierszy może być przekazana jako parametr:

```text
3
```

ale liczba kolumn:

```text
4
```

musi być znana w deklaracji parametru w takim prostym zapisie.

---

## 73. Dlaczego w tablicy statycznej 2D trzeba znać liczbę kolumn?

Aby znaleźć:

```cpp
tablica[i][j]
```

kompilator musi wiedzieć, o ile elementów przesunąć się, aby przejść do kolejnego wiersza.

Dla:

```cpp
int tablica[][4]
```

każdy wiersz zawiera cztery elementy.

Schemat:

```text
wiersz 0: [0][0] [0][1] [0][2] [0][3]
wiersz 1: [1][0] [1][1] [1][2] [1][3]
```

Znajomość szerokości wiersza jest więc konieczna.

---

## 74. Przekazywanie dynamicznej tablicy 2D do funkcji

Dla tablicy utworzonej jako:

```cpp
int** tablica
```

funkcja może przyjąć:

```cpp
void wypisz(int** tablica, int wiersze, int kolumny) {

    for (int i = 0; i < wiersze; i++) {

        for (int j = 0; j < kolumny; j++) {
            cout << tablica[i][j] << " ";
        }

        cout << endl;
    }
}
```

Wywołanie:

```cpp
wypisz(tablica, N, M);
```

Tutaj przekazujemy osobno:

```text
adres tablicy
liczbę wierszy
liczbę kolumn
```

---

## 75. Funkcja alokująca dynamiczną tablicę 1D

Funkcja może sama utworzyć dynamiczną tablicę.

Przykład ogólnego mechanizmu:

```cpp
int* utworz(int n) {

    int* tablica = new int[n];

    return tablica;
}
```

Wywołanie:

```cpp
int* dane = utworz(10);
```

Funkcja zwraca adres utworzonego obszaru pamięci.

Pamięć nadal istnieje po zakończeniu funkcji, ponieważ została utworzona przez:

```cpp
new[]
```

Na końcu programu trzeba ją zwolnić:

```cpp
delete[] dane;
```

---

## 76. Funkcja alokująca dynamiczną tablicę 2D

Analogicznie funkcja może utworzyć dynamiczną tablicę dwuwymiarową.

Ogólny mechanizm:

```cpp
int** alokuj(int wiersze, int kolumny) {

    int** tablica = new int*[wiersze];

    for (int i = 0; i < wiersze; i++) {
        tablica[i] = new int[kolumny];
    }

    return tablica;
}
```

Wywołanie:

```cpp
int** macierz = alokuj(N, M);
```

Funkcja zwraca:

```text
adres tablicy wskaźników
```

czyli typ:

```cpp
int**
```

---

# Część V-C: zwracanie tablic z funkcji

## 77. Czy można zwrócić zwykłą tablicę statyczną przez `return`?

Surowej tablicy C++ nie zwracamy przez wartość tak jak zwykłej zmiennej.

Nie możemy napisać funkcji w rodzaju:

```cpp
int[5] utworz();
```

Taki typ zwracany nie jest poprawnym sposobem zwracania surowej tablicy.

---

## 78. Nie wolno zwracać adresu zwykłej lokalnej tablicy

Błędny pomysł:

```cpp
int* utworz() {

    int tablica[5];

    return tablica;
}
```

Dlaczego?

Tablica:

```cpp
int tablica[5];
```

jest zmienną lokalną funkcji.

Po zakończeniu funkcji przestaje istnieć.

Zwrócony adres wskazywałby więc na pamięć, która nie należy już do tej tablicy.

Takiego rozwiązania nie należy stosować.

---

## 79. Jak bezpiecznie uzyskać tablicę z funkcji?

Na obecnym etapie najprostsze są dwa podejścia.

### Sposób 1: funkcja dostaje istniejącą tablicę i ją wypełnia

```cpp
void wypelnij(int tablica[], int n) {

    for (int i = 0; i < n; i++) {
        tablica[i] = i;
    }
}
```

Wywołanie:

```cpp
int dane[5];

wypelnij(dane, 5);
```

Funkcja nie tworzy nowej tablicy.

Pracuje na tablicy utworzonej w `main`.

### Sposób 2: funkcja tworzy tablicę dynamiczną i zwraca wskaźnik

```cpp
int* utworz(int n) {

    int* tablica = new int[n];

    return tablica;
}
```

Wtedy pamięć istnieje również po zakończeniu funkcji.

---

## 80. Kto powinien zwolnić pamięć zwróconą przez funkcję?

Jeżeli funkcja wykonała:

```cpp
new[]
```

a zwrócony wskaźnik przechowujemy w `main`, pamięć trzeba później zwolnić.

Przykładowo:

```cpp
int* dane = utworz(n);

// korzystanie

delete[] dane;
```

Dla tablicy 2D trzeba zwolnić najpierw wszystkie wiersze, a potem tablicę wskaźników.

---

## 81. Ważna różnica: przekazanie tablicy a zwrócenie tablicy

Przekazanie tablicy:

```text
main tworzy tablicę
        ↓
funkcja dostaje jej adres
        ↓
funkcja może ją odczytać lub zmienić
```

Zwrócenie tablicy dynamicznej:

```text
funkcja wykonuje new[]
        ↓
powstaje nowy obszar pamięci
        ↓
funkcja zwraca jego adres
        ↓
main przejmuje wskaźnik
        ↓
main później wykonuje delete[]
```

---

# Część V-D: przykład matematyczny bisekcji

## 82. Bisekcja krok po kroku na przykładzie matematycznym

Rozważmy funkcję:

```text
f(x) = x² - 2
```

Szukamy miejsca zerowego, czyli rozwiązania:

```text
x² - 2 = 0
```

Wiadomo matematycznie, że:

```text
x = √2
```

czyli około:

```text
1.4142
```

Załóżmy jednak, że nie znamy tego wyniku i chcemy znaleźć go metodą bisekcji.

Wybieramy przedział:

```text
[1, 2]
```

Na końcach:

```text
f(1) = 1² - 2 = -1
f(2) = 2² - 2 = 2
```

Mamy zmianę znaku:

```text
f(1) < 0
f(2) > 0
```

czyli w przedziale `[1, 2]` znajduje się miejsce zerowe.

---

## 83. Pierwszy krok bisekcji

Środek przedziału:

```text
c = (1 + 2) / 2
  = 1.5
```

Liczymy wartość funkcji:

```text
f(1.5) = 1.5² - 2
       = 2.25 - 2
       = 0.25
```

Mamy:

```text
f(1)   = -1
f(1.5) = 0.25
```

Znaki są różne.

Miejsce zerowe znajduje się więc w:

```text
[1, 1.5]
```

---

## 84. Drugi krok bisekcji

Nowy środek:

```text
c = (1 + 1.5) / 2
  = 1.25
```

Wartość:

```text
f(1.25) = 1.25² - 2
        = 1.5625 - 2
        = -0.4375
```

Teraz:

```text
f(1.25) = -0.4375
f(1.5)  = 0.25
```

Zmiana znaku występuje pomiędzy:

```text
1.25
```

i:

```text
1.5
```

Nowy przedział:

```text
[1.25, 1.5]
```

---

## 85. Kolejne kroki

Dalej postępujemy identycznie:

```text
[1.25, 1.5]

środek:
1.375

f(1.375) = 1.375² - 2
         = -0.109375
```

Zatem:

```text
[1.375, 1.5]
```

Następny środek:

```text
1.4375
```

```text
f(1.4375) > 0
```

więc:

```text
[1.375, 1.4375]
```

Następnie:

```text
1.40625
```

```text
f(1.40625) < 0
```

więc:

```text
[1.40625, 1.4375]
```

Przedział staje się coraz mniejszy i coraz dokładniej otacza:

```text
√2 ≈ 1.4142
```

---

## 86. Tabela kolejnych przybliżeń

Możemy zapisać kilka kroków w tabeli:

| krok | a | b | środek c |
|---:|---:|---:|---:|
| 1 | 1.000000 | 2.000000 | 1.500000 |
| 2 | 1.000000 | 1.500000 | 1.250000 |
| 3 | 1.250000 | 1.500000 | 1.375000 |
| 4 | 1.375000 | 1.500000 | 1.437500 |
| 5 | 1.375000 | 1.437500 | 1.406250 |

Za każdym razem długość przedziału zmniejsza się dwukrotnie.

To właśnie oznacza:

```text
bisekcja = dzielenie przedziału na połowę
```

---

# Część V-E: przykład matematyczny transpozycji

## 87. Transpozycja macierzy krok po kroku

Rozważmy macierz:

```text
A =
[ 1  2  3 ]
[ 4  5  6 ]
```

Macierz `A` ma:

```text
2 wiersze
3 kolumny
```

czyli rozmiar:

```text
2 × 3
```

---

## 88. Zamiana wierszy na kolumny

Pierwszy wiersz macierzy `A`:

```text
1 2 3
```

staje się pierwszą kolumną macierzy transponowanej.

Drugi wiersz:

```text
4 5 6
```

staje się drugą kolumną.

Otrzymujemy:

```text
Aᵀ =
[ 1  4 ]
[ 2  5 ]
[ 3  6 ]
```

Rozmiar zmienił się z:

```text
2 × 3
```

na:

```text
3 × 2
```

---

## 89. Transpozycja przez indeksy

Oznaczmy element:

```text
A[i][j]
```

Po transpozycji trafia on do:

```text
B[j][i]
```

Przykładowo:

```text
A[0][0] = 1  ->  B[0][0] = 1
A[0][1] = 2  ->  B[1][0] = 2
A[0][2] = 3  ->  B[2][0] = 3

A[1][0] = 4  ->  B[0][1] = 4
A[1][1] = 5  ->  B[1][1] = 5
A[1][2] = 6  ->  B[2][1] = 6
```

Czyli zawsze:

```text
B[j][i] = A[i][j]
```

---

## 90. Matematyczny zapis transpozycji

Jeżeli:

```text
A =
[ a  b  c ]
[ d  e  f ]
```

to:

```text
Aᵀ =
[ a  d ]
[ b  e ]
[ c  f ]
```

Możemy więc powiedzieć:

```text
wiersze macierzy A stają się kolumnami macierzy Aᵀ
```

i odwrotnie:

```text
kolumny macierzy A stają się wierszami macierzy Aᵀ
```

---


# Część VI: transpozycja macierzy

## 91. Co to jest transpozycja?

Transpozycja polega na zamianie wierszy z kolumnami.

Jeżeli macierz `A` ma rozmiar:

```text
N × M
```

to macierz transponowana `B` ma rozmiar:

```text
M × N
```

---

## 92. Przykład transpozycji

Macierz:

```text
A =

1  2  3
4  5  6
```

ma rozmiar:

```text
2 × 3
```

Po transpozycji:

```text
B =

1  4
2  5
3  6
```

ma rozmiar:

```text
3 × 2
```

---

## 93. Co dzieje się z indeksami?

Dla transpozycji:

```text
A[i][j]
```

przechodzi do:

```text
B[j][i]
```

Czyli zamieniamy miejscami:

```text
wiersz <-> kolumna
```

Przykład:

```text
A[0][2] -> B[2][0]
A[1][0] -> B[0][1]
```

---

## 94. Matematyczny zapis transpozycji

Możemy zapisać:

```text
B[j][i] = A[i][j]
```

dla wszystkich poprawnych:

```text
i
j
```

To jest najważniejsza zależność potrzebna do zrozumienia transpozycji.

---

## 95. Pętle przy transpozycji

Ponieważ musimy odwiedzić każdy element macierzy, naturalnie wykorzystujemy dwie pętle.

Schemat:

```cpp
for (int i = 0; i < liczbaWierszy; i++) {

    for (int j = 0; j < liczbaKolumn; j++) {

        // przeniesienie elementu do macierzy transponowanej
    }
}
```

---

# Część VII: formatowanie macierzy

## 96. `setw`

Do ustawienia szerokości pola używamy:

```cpp
#include <iomanip>
```

oraz:

```cpp
setw(...)
```

Przykład:

```cpp
cout << setw(6) << 12;
```

Liczba zostanie wypisana na polu o szerokości sześciu znaków.

---

## 97. Dlaczego `setw` przydaje się przy tabelach?

Bez formatowania:

```text
1 2 300 4
10 20 30 40
```

kolumny mogą wyglądać nierówno.

Przy:

```cpp
setw(6)
```

każda wartość otrzymuje takie samo pole.

Schemat:

```cpp
cout << setw(6) << tablica[i][j];
```

---

## 98. `setw` działa tylko na następny element

W przeciwieństwie do:

```cpp
fixed
```

ustawienie:

```cpp
setw(6)
```

dotyczy tylko następnej wypisywanej wartości.

Dlatego zwykle stosujemy je bezpośrednio w pętli:

```cpp
cout << setw(6) << tablica[i][j];
```

---

# Część VIII: wypełnianie tablicy po spirali

## 99. Na czym polega spirala?

Wypełnianie spiralne oznacza przechodzenie po krawędziach aktualnego prostokąta.

Kolejność:

```text
w prawo
↓
w dół
↓
w lewo
↓
w górę
```

Następnie przechodzimy do mniejszego prostokąta wewnątrz.

---

## 100. Prosty przykład spirali

Dla tablicy `3 × 4` kolejność odwiedzania pól może wyglądać:

```text
 1  2  3  4
10 11 12  5
 9  8  7  6
```

Po przejściu po zewnętrznej warstwie pozostaje mniejszy obszar wewnątrz.

---

## 101. Cztery granice

Przy algorytmie spiralnym wygodnie przechowywać cztery granice:

```text
góra
dół
lewo
prawo
```

Na początku:

```text
góra  = 0
dół   = N - 1
lewo  = 0
prawo = M - 1
```

---

## 102. Przejście w prawo

Najpierw poruszamy się po górnym wierszu:

```text
od lewej granicy
do prawej granicy
```

Po zakończeniu ten wiersz jest już wypełniony.

Możemy więc przesunąć górną granicę o jeden w dół.

---

## 103. Przejście w dół

Następnie przechodzimy po prawej kolumnie:

```text
od góry
do dołu
```

Po jej wypełnieniu przesuwamy prawą granicę o jeden w lewo.

---

## 104. Przejście w lewo

Następny etap:

```text
dolny wiersz
```

od prawej strony do lewej.

Po jego wypełnieniu dolna granica przesuwa się w górę.

---

## 105. Przejście w górę

Na końcu przechodzimy lewą kolumną w górę.

Po zakończeniu lewa granica przesuwa się w prawo.

---

## 106. Jeden pełny obrót spirali

Możemy myśleć:

```text
1. góra:  lewo -> prawo
2. prawa: góra  -> dół
3. dół:   prawo -> lewo
4. lewa:  dół   -> góra
```

Po tych czterech krokach:

```text
góra++
prawo--
dół--
lewo++
```

i zaczynamy kolejną warstwę.

---

## 107. Kiedy zakończyć spiralę?

Kontynuujemy tak długo, jak istnieje niewypełniony prostokąt.

Czyli dopóki granice się nie miną.

Idea:

```text
góra <= dół
```

oraz:

```text
lewo <= prawo
```

Gdy granice się spotkają lub przekroczą, wszystkie pola zostały wypełnione.

---

## 108. Dlaczego trzeba uważać na tablice prostokątne?

Dla tablicy kwadratowej:

```text
4 × 4
```

spirala jest dość intuicyjna.

Ale program musi również poprawnie działać dla:

```text
2 × 5
5 × 2
1 × 6
6 × 1
```

Dlatego przed przejściem po dolnym wierszu lub lewej kolumnie warto sprawdzić, czy odpowiednie granice nadal są poprawne.

---

## 109. Śledzenie wartości licznika

Przy wypełnianiu spirali wygodnie użyć zmiennej:

```cpp
int wartosc = 1;
```

Po wpisaniu wartości do komórki:

```cpp
wartosc++;
```

Dzięki temu kolejne odwiedzane pola otrzymują:

```text
1
2
3
4
...
```

---

# Część IX: funkcje pomocnicze

## 110. Po co funkcja do wypisywania tablicy?

Zamiast pisać kilka razy te same dwie pętle, można utworzyć funkcję:

```cpp
void wypisz(/* tablica */, int wiersze, int kolumny) {

    // dwie pętle
}
```

Dzięki temu można wykorzystać tę samą funkcję dla kilku różnych macierzy.

---

## 111. Ogólny schemat wypisywania tablicy 2D

```cpp
for (int i = 0; i < wiersze; i++) {

    for (int j = 0; j < kolumny; j++) {

        cout << setw(6) << tablica[i][j];
    }

    cout << endl;
}
```

To jest ogólny mechanizm formatowania macierzy, a nie rozwiązanie konkretnego zadania.

---

# Część X: najczęstsze błędy

## 112. Błędy przy tablicach

Sprawdź:

- czy indeks zaczyna się od `0`,
- czy ostatni indeks wynosi `rozmiar - 1`,
- czy nie wychodzisz poza zakres,
- czy liczba współczynników wielomianu wynosi `n + 1`,
- czy pętla obejmuje wszystkie współczynniki.

---

## 113. Błędy przy bisekcji

Sprawdź:

- czy obliczasz środek przedziału poprawnie,
- czy funkcja wielomianu zwraca właściwą wartość,
- czy wybierasz właściwą połowę przedziału,
- czy rekurencja zmniejsza przedział,
- czy istnieje warunek zakończenia,
- czy obsługujesz przypadek braku zmiany znaku,
- czy wynik wypisujesz z wymaganą dokładnością.

---

## 114. Błędy przy tekście

Sprawdź:

- czy używasz `getline`, jeśli tekst zawiera spacje,
- czy nie pozostał znak nowej linii po wcześniejszym `cin`,
- czy przechodzisz po wszystkich znakach,
- czy poprawnie wykrywasz początek słowa,
- czy pamiętasz, że zwykły `string` i `<cctype>` nie rozwiązują wszystkich problemów Unicode.

---

## 115. Błędy przy dynamicznej pamięci

Sprawdź:

- czy pamięć została przydzielona,
- czy każdy wiersz został zaalokowany,
- czy po zakończeniu programu zwalniasz pamięć,
- czy liczba `delete[]` odpowiada liczbie zaalokowanych wierszy,
- czy nie używasz tablicy po jej zwolnieniu.

---

## 116. Błędy przy transpozycji

Najczęstszy błąd to pomylenie wymiarów.

Jeżeli:

```text
A ma N × M
```

to:

```text
B ma M × N
```

oraz:

```text
B[j][i] = A[i][j]
```

---

## 117. Błędy przy spirali

Sprawdź:

- czy wszystkie cztery kierunki mają właściwe granice,
- czy po każdym kierunku aktualizujesz odpowiednią granicę,
- czy nie wpisujesz dwukrotnie do tej samej komórki,
- czy algorytm działa dla tablic prostokątnych,
- czy kończysz po wpisaniu `N * M` wartości.

---

# Część XI: schemat pracy nad zadaniami

## 118. Zadanie z bisekcją

Przed pisaniem kodu odpowiedz:

1. Jak przechowam współczynniki?
2. Jak policzę `f(x)`?
3. Jak sprawdzę, czy na końcach przedziału zmienia się znak?
4. Jak policzę środek?
5. Jak wybiorę nowy przedział?
6. Jaki będzie przypadek bazowy rekurencji?
7. Jaką dokładność muszę osiągnąć?

Schemat myślenia:

```text
wczytaj dane
    ↓
wczytaj współczynniki
    ↓
sprawdź wartości na końcach
    ↓
czy można zastosować bisekcję?
    ↓
oblicz środek
    ↓
wybierz połowę
    ↓
wywołaj funkcję ponownie
```

---

## 119. Zadanie z tekstem

Pomyśl:

1. Czy tekst zawiera spacje?
2. Czy potrzebuję `getline`?
3. Jak przejdę po kolejnych znakach?
4. Jak zmienię pojedynczą literę?
5. Jak rozpoznam początek słowa?
6. Jak wybiorę rodzaj konwersji?

---

## 120. Zadanie z transpozycją

Pomyśl:

1. Jakie są wymiary `A`?
2. Jakie będą wymiary `B`?
3. Jak zaalokować obie tablice?
4. Jak wypełnić `A`?
5. Jak przekształcić `A[i][j]` na odpowiedni element `B`?
6. Jak wypisać obie tablice?
7. Jak zwolnić pamięć?

Najważniejsza zależność:

```text
B[j][i] = A[i][j]
```

---

## 121. Zadanie ze spiralą

Najpierw nie pisz kodu.

Rozrysuj niewielką macierz, np.:

```text
3 × 4
```

i zaznacz kolejność przechodzenia po komórkach.

Następnie określ:

```text
góra
dół
lewo
prawo
```

Po każdym kierunku zastanów się:

```text
która granica została właśnie wykorzystana?
```

i przesuń ją do środka.

---

# Podsumowanie

Po tym laboratorium warto rozumieć przede wszystkim:

### Wielomian

```text
W(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ
```

Współczynniki można przechowywać w tablicy.

### Bisekcja

```text
[a, b]
   ↓
środek
   ↓
wybór połowy
   ↓
mniejszy przedział
```

Rekurencja działa, ponieważ każde kolejne wywołanie rozwiązuje ten sam problem dla mniejszego przedziału.

### Tekst

```cpp
getline(cin, tekst);
```

wczytuje całą linię, a:

```cpp
tolower()
toupper()
```

pozwalają zmieniać wielkość podstawowych liter.

### Dynamiczna tablica 2D

```cpp
int** tablica
```

może reprezentować macierz o wymiarach poznanych dopiero podczas działania programu.

### Transpozycja

```text
A[i][j] -> B[j][i]
```

Wiersze stają się kolumnami.

### Spirala

```text
prawo
dół
lewo
góra
```

Po przejściu każdej krawędzi przesuwamy odpowiednią granicę do wnętrza macierzy.
