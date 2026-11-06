# Ćwiczenia przykładowe : programowanie w C++

Zadania są przykładami do samodzielnego rozwiązania w języku C++. Ćwiczą wczytywanie danych, instrukcje warunkowe, pętle, obliczenia oraz wypisywanie wyników.

W przykładach linie po znaku zachęty (np. `Podaj A:`) oznaczają dane wpisane przez użytkownika. Program powinien wypisać wskazane komunikaty i wyniki.

---

## Zadanie 1. Zakres temperatur

Napisz program, który wczytuje liczbę pomiarów `N`, a następnie `N` całkowitych temperatur. Program wyznacza najwyższą i najniższą temperaturę oraz różnicę między nimi.

Jeżeli `N` jest mniejsze lub równe zero, program ma wypisać komunikat `Liczba pomiarów musi być większa od zera.` i ponownie poprosić o liczbę pomiarów. Wczytywanie należy powtarzać aż do otrzymania poprawnego `N`.

Jeżeli wszystkie temperatury są jednakowe, program wypisuje komunikat `Wszystkie temperatury są takie same: X`, gdzie `X` oznacza podaną temperaturę. W przeciwnym razie wypisuje temperaturę najwyższą, najniższą i ich różnicę.

### Przykład 1 : ponowne pytanie i temperatury ujemne

Wejście:
```text
Liczba pomiarów: 0
Liczba pomiarów musi być większa od zera.
Liczba pomiarów: 4
Podaj temperatury: -3 8 2 8
```

Wyjście:
```text
Najwyższa temperatura: 8
Najniższa temperatura: -3
Różnica: 11
```

### Przykład 2 : wszystkie wartości jednakowe

Wejście:
```text
Liczba pomiarów: 3
Podaj temperatury: 5 5 5
```

Wyjście:
```text
Wszystkie temperatury są takie same: 5
```

### Przykład 3 : jedna wartość

Wejście:
```text
Liczba pomiarów: 1
Podaj temperatury: -12
```

Wyjście:
```text
Wszystkie temperatury są takie same: -12
```

---

## Zadanie 2. Przeliczanie ciśnienia

Napisz program w C++, który przelicza ciśnienie między kilopaskalami (`kPa`) a hektopaskalami (`hPa`).

Program wczytuje wartość ciśnienia oraz wybór jednostki, w której podano wartość:

- `1` : kilopaskale (`kPa`),
- `2` : hektopaskale (`hPa`).

Następnie przelicza wartość na drugą jednostkę i wypisuje obie wartości z dokładnością do dwóch miejsc po przecinku. Przyjmij, że `1 kPa = 10 hPa`.

Wartość ciśnienia nie może być ujemna. Dla ujemnej wartości program wypisuje `Wartość nie może być ujemna.` Dla wyboru innego niż `1` lub `2` wypisuje `Niepoprawny wybór jednostki.`

### Przykład 1 : kPa na hPa

Wejście:
```text
Podaj wartość ciśnienia: 101.325
Podaj jednostkę [1] kPa [2] hPa: 1
```

Wyjście:
```text
101.33 kPa = 1013.25 hPa
```

### Przykład 2 : hPa na kPa

Wejście:
```text
Podaj wartość ciśnienia: 500
Podaj jednostkę [1] kPa [2] hPa: 2
```

Wyjście:
```text
500.00 hPa = 50.00 kPa
```

### Przykład 3 : niepoprawna jednostka

Wejście:
```text
Podaj wartość ciśnienia: 200
Podaj jednostkę [1] kPa [2] hPa: 3
```

Wyjście:
```text
Niepoprawny wybór jednostki.
```

### Przykład 4 : ujemne ciśnienie

Wejście:
```text
Podaj wartość ciśnienia: -500
```

Wyjście:
```text
Wartość nie może być ujemna.
```

---

## Zadanie 3. Rysowanie znaku plus

Napisz program, który wczytuje nieparzystą liczbę całkowitą `N` z przedziału od 3 do 21, a następnie rysuje w konsoli znak plus (`+`) w kwadracie o wymiarach `N × N`.

Znak plus tworzą środkowy wiersz oraz środkowa kolumna. Pozostałe miejsca należy wypełnić kropkami (`.`). Każdy wiersz rysunku ma zawierać dokładnie `N` znaków.

Jeżeli `N` jest parzyste albo nie należy do przedziału 3–21, program wypisuje `Nieprawidłowy rozmiar.`

### Przykład 1

Wejście:
```text
Podaj rozmiar: 5
```

Wyjście:
```text
..+..
..+..
+++++
..+..
..+..
```

### Przykład 2 : parzysty rozmiar

Wejście:
```text
Podaj rozmiar: 4
```

Wyjście:
```text
Nieprawidłowy rozmiar.
```

### Przykład 3 : rozmiar poza zakresem

Wejście:
```text
Podaj rozmiar: 23
```

Wyjście:
```text
Nieprawidłowy rozmiar.
```

---

## Zadanie 4. Suma liczb spełniających warunek

Napisz program, który wczytuje dwie dodatnie liczby całkowite `A` i `B`, określające przedział domknięty `[A, B]`.

Oblicz sumę liczb z tego przedziału, które są jednocześnie nieparzyste i podzielne przez 3.

Jeżeli `A > B`, program wypisuje `Błąd: A musi być mniejsze lub równe B.` Jeżeli w przedziale nie ma liczb spełniających oba warunki, wypisuje `Brak liczb spełniających warunek.`

### Przykład 1

Wejście:
```text
Podaj A: 4
Podaj B: 20
```

Wyjście:
```text
Suma liczb nieparzystych i podzielnych przez 3 z przedziału [4, 20] wynosi: 24
```

### Przykład 2

Wejście:
```text
Podaj A: 10
Podaj B: 20
```

Wyjście:
```text
Suma liczb nieparzystych i podzielnych przez 3 z przedziału [10, 20] wynosi: 15
```

### Przykład 3 : brak liczb spełniających warunek

Wejście:
```text
Podaj A: 10
Podaj B: 11
```

Wyjście:
```text
Brak liczb spełniających warunek.
```

### Przykład 4 : błędny przedział

Wejście:
```text
Podaj A: 20
Podaj B: 10
```

Wyjście:
```text
Błąd: A musi być mniejsze lub równe B.
```

---

## Zadanie 5. Analiza wczytanego znaku

Napisz program, który wczyta jeden znak typu `char`. Program ma określić, czy znak jest:

- wielką literą (`A`–`Z`),
- małą literą (`a`–`z`),
- cyfrą (`0`–`9`),
- innym znakiem.

Następnie wypisz znak, jego kod ASCII w systemie dziesiętnym oraz kod w systemie szesnastkowym. Kod szesnastkowy poprzedź prefiksem `0x`. Litery szesnastkowe wypisuj małymi znakami. W zadaniu przyjmij znaki ASCII.

### Przykład 1 : mała litera

Wejście:
```text
Podaj znak: a
```

Wyjście:
```text
Znak: 'a'
Rodzaj: mała litera
Kod dziesiętnie: 97
Kod szesnastkowo: 0x61
```

### Przykład 2 : cyfra

Wejście:
```text
Podaj znak: 7
```

Wyjście:
```text
Znak: '7'
Rodzaj: cyfra
Kod dziesiętnie: 55
Kod szesnastkowo: 0x37
```

### Przykład 3 : znak interpunkcyjny

Wejście:
```text
Podaj znak: ?
```

Wyjście:
```text
Znak: '?'
Rodzaj: inny znak
Kod dziesiętnie: 63
Kod szesnastkowo: 0x3f
```
