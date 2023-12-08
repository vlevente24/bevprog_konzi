#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/**
 * szintaktika (include, std)
 * struct
 * konstruktor
 * destruktor
 * operator
 * függvények (paraméter, referencia)
 * beolvasás
 * beugrók
 * feladat
**/

struct Datum {
    int ev;
    string honap;
    int nap;
    // konstruktor (rögtön értéket adunk a Datum -nak)
    Datum(int _ev, string _honap, int _nap) {
        ev = _ev;
        honap = _honap;
        nap = _nap;
    }
    // üres konstruktor (arra jó, hogy értékek megadása nélkül is tudsz egy Datum -ot létrehozni)
    Datum() {}
    // destruktor (ha meghal a Datum, még végrendeletében egyszer megtörténik, amit ide írunk, esetünkben, hogy elköszön)
    ~Datum() {
        cout << "szia!" << endl;
    }
};

Datum operator+ (Datum d1, Datum d2) {
    // ez csak szemléltetésként, akárhogy definiálhatod a dátumok összeadását, igazából sok értelme nincs :)
    Datum eredmeny;
    eredmeny.ev = d1.ev + d2.ev;
    eredmeny.nap = (d1.nap + d2.nap) % 31;
    eredmeny.honap = "neadjosszeketdatumot";
    return eredmeny;
}


Datum sorbeolvas(ifstream& ezleszafajl) {
    //fileból egy sort
    Datum eredmeny;
    char c;
    ezleszafajl >> eredmeny.ev >> c;
    getline(ezleszafajl, eredmeny.honap, ',');
    ezleszafajl >> eredmeny.nap >> ws;
    return eredmeny;
}

void beolvas(vector<Datum>& v) {
    ifstream befajl("valami.txt");
    while (befajl.good()) {
        v.push_back(sorbeolvas(befajl));
    }
    befajl.close();
}

int main() {

    /*
    {
        Datum dat(2020, "december", 6);
        cout << dat.nap << endl;
    }
    cout << "---------idaig--------" << endl;

    Datum d1(2014, "majus", 7);
    Datum d2(1999, "januar", 1);
    Datum d3 = d1 + d2;
    cout << d3.honap << endl;
    cout << d3 << endl;
     */


    vector<Datum> v;
    beolvas(v);
    cout << v[0].ev << endl;

    return 0;
}
