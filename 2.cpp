#include <iostream>
using namespace std;

// Suma od 1 do N
int suma_do_N(int liczba) {
    int suma = 0;
    for (int i = 1; i <= liczba; i++) suma += i;
    return suma;
}

// Sprawdzenie parzystości
bool czy_parzysta(int liczba) {
    return liczba % 2 == 0;
}

// Największy element
int znajdz_maksimum(int tablica[], int n) {
    int maksimum = tablica[0];
    for (int i = 1; i < n; i++)
        if (tablica[i] > maksimum) maksimum = tablica[i];
    return maksimum;
}

// Najmniejszy element
int znajdz_minimum(int tablica[], int n) {
    int minimum = tablica[0];
    for (int i = 1; i < n; i++)
        if (tablica[i] < minimum) minimum = tablica[i];
    return minimum;
}

// Suma tablicy
int suma_tablicy(int tablica[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) suma += tablica[i];
    return suma;
}

// Średnia tablicy
double srednia_tablicy(int tablica[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) suma += tablica[i];
    return (double)suma / n;
}

// Szukaj element
int szukaj(int tablica[], int n, int szukana) {
    for (int i = 0; i < n; i++)
        if (tablica[i] == szukana) return i;
    return -1;
}

// Sortowanie bąbelkowe
void sortowanie_babelkowe(int tablica[], int n) {
    bool zmiana;
    do {
        zmiana = false;
        for (int i = 0; i < n - 1; i++) {
            if (tablica[i] > tablica[i+1]) {
                int tmp = tablica[i];
                tablica[i] = tablica[i+1];
                tablica[i+1] = tmp;
                zmiana = true;
            }
        }
    } while (zmiana);
}

// Liczba pierwsza
bool czy_pierwsza(int liczba) {
    if (liczba < 2) return false;
    for (int i = 2; i * i <= liczba; i++)
        if (liczba % i == 0) return false;
    return true;
}

// NWD – algorytm Euklidesa (reszta)
int NWD(int a, int b) {
    while (b != 0) {
        int reszta = a % b;
        a = b;
        b = reszta;
    }
    return a;
}

int main() {
    int wybor;
    do {
        cout << "\n=== MENU ALGORYTMÓW ===\n";
        cout << "1. Suma liczb od 1 do N\n";
        cout << "2. Sprawdzenie parzystości\n";
        cout << "3. Największy element tablicy\n";
        cout << "4. Najmniejszy element tablicy\n";
        cout << "5. Suma tablicy\n";
        cout << "6. Średnia tablicy\n";
        cout << "7. Szukanie elementu\n";
        cout << "8. Sortowanie bąbelkowe\n";
        cout << "9. Sprawdzenie czy liczba pierwsza\n";
        cout << "10. NWD dwóch liczb\n";
        cout << "0. Wyjście\n";
        cout << "Wybór: ";
        cin >> wybor;

        if (wybor == 1) {
            int N; cout << "Podaj N: "; cin >> N;
            cout << "Suma od 1 do " << N << " = " << suma_do_N(N) << endl;
        }
        else if (wybor == 2) {
            int N; cout << "Podaj liczbę: "; cin >> N;
            cout << (czy_parzysta(N) ? "TAK" : "NIE") << endl;
        }
        else if (wybor == 3) {
            int n; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            cout << "Największy element = " << znajdz_maksimum(tablica, n) << endl;
        }
        else if (wybor == 4) {
            int n; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            cout << "Najmniejszy element = " << znajdz_minimum(tablica, n) << endl;
        }
        else if (wybor == 5) {
            int n; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            cout << "Suma elementów = " << suma_tablicy(tablica, n) << endl;
        }
        else if (wybor == 6) {
            int n; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            cout << "Średnia = " << srednia_tablicy(tablica, n) << endl;
        }
        else if (wybor == 7) {
            int n, x; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            cout << "Podaj szukaną liczbę: "; cin >> x;
            int indeks = szukaj(tablica, n, x);
            if (indeks == -1) cout << "Nie znaleziono\n";
            else cout << "Znaleziono na pozycji: " << indeks << endl;
        }
        else if (wybor == 8) {
            int n; cout << "Podaj rozmiar tablicy: "; cin >> n;
            int tablica[100];
            for (int i = 0; i < n; i++) cin >> tablica[i];
            sortowanie_babelkowe(tablica, n);
            cout << "Posortowana tablica: ";
            for (int i = 0; i < n; i++) cout << tablica[i] << " ";
            cout << endl;
        }
        else if (wybor == 9) {
            int N; cout << "Podaj liczbę: "; cin >> N;
            cout << (czy_pierwsza(N) ? "PRAWDA" : "FAŁSZ") << endl;
        }
        else if (wybor == 10) {
            int a, b; cout << "Podaj dwie liczby: "; cin >> a >> b;
            cout << "NWD(" << a << "," << b << ") = " << NWD(a, b) << endl;
        }

    } while (wybor != 0);

    return 0;
}
