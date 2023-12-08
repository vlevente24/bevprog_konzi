#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/**
 * szintaktika (include, std)
 * struct (tantárgy)
 * konstruktor
 * destruktor
 * operator
 * függvények (paraméter, referencia)
 * beolvasás
 * beugrók
 * feladat
*/

/** Amiket meg kell nézni a fájlban beolvasás előtt!!!
 * mi az elválasztó karakter
 * milyen adatok
 * van e szóköz a stringekben
 * mi a sorrend
**/

struct Tantargy {
    string nev;
    int kredit;
    string eloado;
    Tantargy(string _nev, int _kredit, string _eloado) {
        nev = _nev;
        kredit = _kredit;
        eloado = _eloado;
    }
    Tantargy() {}
    ~Tantargy() {
        //cout << "Boldog Karácsonyt kíván " << eloado << " !" << endl;
    }

};

ostream& operator<< (ostream & ki, Tantargy t) {
    return ki << t.nev << ", " << t.eloado << ", kredit: " << t.kredit;
}

int fgv(int a) {
    cout << a << " : " << &a << endl;
    a = a + 8;
    return a;
}

Tantargy sorbeolvas(ifstream & bf) {
    Tantargy t;
    char c;
    getline(bf, t.nev, ',') >> ws;
    bf >> t.kredit >> c >> ws;
    getline(bf, t.eloado) >> ws;
    return t;
}

void beolvas(vector<Tantargy> & v) {
    ifstream befajl("targyadatok.txt");
    if (!befajl.good()) {
        cout << "nem jo a fajl!!" << endl;
        return;
    }
    while (befajl.good()) {
        v.push_back(sorbeolvas(befajl));
    }
    befajl.close();
}

int main() {
    Tantargy bevprog("BevProg1", 4, "Flugi");
    cout << bevprog.eloado << endl;

    Tantargy anal("Anal1", 5, "Vago Tanarno");
    cout << anal << endl;

    int szam(45);
    cout << szam << endl;
    int valami = 19;
    cout << valami << " : " << &valami << endl;
    cout << fgv(valami) << endl;

    // innentől a rendes beolvasós történet
    vector<Tantargy> v;
    beolvas(v);
    // itt ezután meglegyen benne az összes adat
    cout << "-----beolvasas utan------" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}