#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugró érvényes, amely nem tartalmaz semmilyen változtatást a main()-ben,
        és már nincs benne kommentezve semmi
    - nem tartalmaz #undefine-t, az "ellenoriz"-en kívül nem tartalmaz #define sorokat, és azt sem szabad megváltoztatni
*/

// Innentol
int masodikszamjegy(int a) {
    return (a % 100) / 10;
}
void megdolgoz(string& s) {
    s = "masik";
}
struct Csomag {
    int x, y;
    Csomag() {}
    Csomag(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
Csomag csomagfeltoltes() {
    return Csomag(12,13);
}
Csomag csomagbetoltes() {
    ifstream bef("atmenetifile.txt");
    Csomag csomi;
    bef >> csomi.x >> csomi.y;
    bef.close();
    return csomi;
}
bool anagramma(string s1, string s2) {
    vector<int> v1(26,0), v2(26,0);
    for (int i = 0; i < s1.size(); i++)
        v1[s1[i]-97]++;
    for (int i = 0; i < s2.size(); i++)
        v2[s2[i]-97]++;
    for (int i = 0; i < 26; i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}

// Idaig

int main()
{
    int pont = 0;
    srand(time(0));
    int a = masodikszamjegy(123); //10-es helyiertek
    int b = masodikszamjegy(234);
    ellenoriz(a==2 && b==3, pont)

    string egyik="egyik";
    megdolgoz(egyik);
    ellenoriz(egyik=="masik", pont)

    Csomag cs = csomagfeltoltes();
    ellenoriz(cs.x==12 && cs.y==13, pont)

    int vel = rand()%100;
    ofstream f("atmenetifile.txt");
    f << "23 " << vel;
    f.close();
    Csomag cs2 = csomagbetoltes();
    ellenoriz(cs2.x==23 && cs2.y==vel, pont)

/*
    string s1 = "abrakadabra";
    string s2 = "babadarabka";
    string s3 = "arabdarabka";
    //anagramma: betűk átrendezésével megkapható-e az egyik szóból a másik?
    ellenoriz(anagramma(s1, s3) && !anagramma(s1, s2) && anagramma(s3,s1) && !anagramma(s2,s3), pont)
*/
    cout << endl << pont << "/5 pont" << endl;
    int valm = 'z';
    cout << valm << endl;
}