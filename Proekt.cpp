#include <iostream>
#include <vector>
#include <algorithm>

class Pravoagolnik {
private:
    double a, b;

public:
    Pravoagolnik(double a_, double b_) : a(a_), b(b_) {}

    double povrsina() const {
        return a * b;
    }
};

class Kvadrat {
private:
    double a;

public:
    Kvadrat(double a_) : a(a_) {}

    double povrsina() const {
        return a * a;
    }
};

class Krug {
private:
    double r;

public:
    Krug(double r_) : r(r_) {}

    double povrsina() const {
        return 3.14 * r * r;
    }
};

template <typename T>
class Mnozestvo {
private:
    std::vector<T> elementi;

public:
    void dodadi(const T& element) {
        elementi.push_back(element);
    }

    void prikazi() const {
        for (const auto& element : elementi) {
            std::cout << element.povrsina() << ' ';
        }
        std::cout << '\n';
    }

    T najgolem() const {
        auto maxIt = std::max_element(elementi.begin(), elementi.end(),
            [](const T& a, const T& b) {
                return a.povrsina() < b.povrsina();
            });
        return *maxIt;
    }

    int broj_elementi() const {
        return elementi.size();
    }
};

int main() {
    Mnozestvo<Pravoagolnik> pravoagolnici;
    Mnozestvo<Kvadrat> kvadrati;
    Mnozestvo<Krug> krugovi;

    int izbor = 0;
    do {
        std::cout << "Izberete opcija:\n"
                  << "1. Dodaj pravoagolnik\n"
                  << "2. Dodaj kvadrat\n"
                  << "3. Dodaj krug\n"
                  << "4. Prikazi pravoagolnici\n"
                  << "5. Prikazi kvadrati\n"
                  << "6. Prikazi krugovi\n"
                  << "7. Prikazi najgolem element\n"
                  << "8. Prikazi broj na elementi\n"
                  << "9. Kraj\n";

        std::cin >> izbor;

        if (izbor == 1) {
            double a, b;
            std::cout << "Vnesi stranica a: ";
            std::cin >> a;
            std::cout << "Vnesi stranica b: ";
            std::cin >> b;
            pravoagolnici.dodadi(Pravoagolnik(a, b));
        }
        else if (izbor == 2) {
            double a;
            std::cout << "Vnesi stranica a: ";
            std::cin >> a;
            kvadrati.dodadi(Kvadrat(a));
        }
        else if (izbor == 3) {
            double r;
            std::cout << "Vnesi radius r: ";
            std::cin >> r;
            krugovi.dodadi(Krug(r));
        }
        else if (izbor == 4) {
            std::cout << "Pravoagolnici:";
            pravoagolnici.prikazi();
        }
        else if (izbor == 5) {
            std::cout << "Kvadrati:";
            kvadrati.prikazi();
        }
        else if (izbor == 6) {
            std::cout << "Krugovi:";
            krugovi.prikazi();
        }
        else if (izbor == 7) {
            std::cout << "Najgolem element:";
            pravoagolnici.najgolem();
            kvadrati.najgolem();
            krugovi.najgolem();
        }
        else if (izbor == 8) {
            std::cout << "Broj na elementi:";
            pravoagolnici.broj_elementi();
            kvadrati.broj_elementi();
            krugovi.broj_elementi();
        }
        else if (izbor == 9) {
            break;
        }
        
    }
    while (izbor != 9);
    return 0;
}
        
