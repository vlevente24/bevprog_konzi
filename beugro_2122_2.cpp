#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugr� �rv�nyes, amely nem tartalmaz semmilyen v�ltoztat�st a main()-ben,
        �s m�r nincs benne kommentezve semmi
    - nem tartalmaz #undefine-t, az "ellenoriz"-en k�v�l nem tartalmaz #define sorokat, �s azt sem szabad megv�ltoztatni
    - warningokat bekapcsolva nem ad "no return statement" warningot
*/

// Innentol
bool az_egyik_a_val_kezdodik(string s1, string s2) {
    return (s1[0] == 'a' or s2[0] == 'a');
}
string vissza(string s) {
    string vissza;
    for (int i = s.size()-1; i >= 0; i--) {
        vissza += s[i];
    }
    return vissza;
}
struct K {
    int a, b;
};
void kezel(K & valami) {
    valami.b = valami.a;
}
int osszesen(K k) {
    return (k.a + k.b);
}
vector<int> rejtveny() {
    vector<int> v(10, 0);
    v[0] = 10;
    return v;
}
// Idaig

int main()
{
    int pont = 0;
    srand(time(0));

    ellenoriz(az_egyik_a_val_kezdodik("abc","bca") &&
              az_egyik_a_val_kezdodik("bca","abc") &&
              !az_egyik_a_val_kezdodik("bca","bca") , pont)

    string randomszo;
    for (int i=0;i<5;i++) {
        char c = "qwertyuiop"[rand()%10];
        randomszo = randomszo + c;
    }
    for (int i=0;i<5;i++) {
        char c = "asdfghjklm"[rand()%10];
        randomszo = randomszo + c;
    }
    ellenoriz(vissza("abc") == "cba" &&
              vissza(vissza(randomszo))==randomszo &&
              vissza(randomszo)!=randomszo , pont)

    K k;
    int vel = rand()%100;
    k.a = vel;
    kezel(k);
    ellenoriz(k.b==k.a , pont)

    const K kc = {2,2};
    ellenoriz(osszesen(k)==vel*2 && osszesen(kc)==4, pont)

    vector<int> valami = rejtveny();
    int sum=0; int szorzat=1;
    for (int a : valami) {
        sum+=a;
        szorzat *= a;
    }
    ellenoriz(valami.size() == 10 && szorzat == 0 && sum == 10 , pont)
/*
*/

    cout << endl << pont << "/5 pont";
}