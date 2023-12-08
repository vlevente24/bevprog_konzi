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
bool paros(int a) {
    return a % 2 == 0;
}
struct KetSzam {
    int egyik, masik;
    KetSzam() {}
    KetSzam(int a, int b) : egyik(a), masik(b) {}
};
KetSzam ujKetSzam(int a, int b) {
    return KetSzam(a, b);
}
void lenullaz(KetSzam& k) {
    k.egyik = 0;
    k.masik = 0;
}
bool helyes(string zarojelezes) {
    int bal = 0;
    for (char c : zarojelezes) {
        if (c == '('){
            bal++;
        }
        if (c == ')') {
            if (bal > 0) {
                bal--;
            } else {
                return false;
            }
        }
    }
    if (bal > 0)
        return false;
    return true;
}
// Idaig

int main()
{
    int pont = 0;
    srand(time(0));
    int rnd = rand()%100;
    ellenoriz(paros(2*rnd) && !paros(2*rnd+1), pont)

    const int konst=42;  //ha az el�z�t j�l csin�ltad ez is egyb�l kell m�k�dj�n
    ellenoriz(paros(konst) , pont)

    KetSzam ksz = ujKetSzam(3,rnd);
    ellenoriz(ksz.egyik == 3 && ksz.masik==rnd, pont)

    lenullaz(ksz);
    ellenoriz(ksz.egyik == 0 && ksz.masik==0, pont)

    //helyes az a z�r�jelez�s amelyiket ki lehet eg�sz�teni besz�rt sz�mokkal �s m�veletekkel �rtelmes aritmetikai kifejez�ss�
    ellenoriz(helyes("(()(()))") && !helyes("()(") && !helyes(")("), pont)
/*
*/

    cout << endl << pont << "/5 pont";
}