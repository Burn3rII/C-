/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "complex2D.h"

using namespace std;

int main()
{
    Complex2D complx1 = Complex2D(2,3);
    Complex2D complx2 = Complex2D(4,1);

    cout << "Complexe 1 : " << complx1.getRe() << ", " << complx1.getIm() 
         << endl;
    cout << "Complexe 2 : " << complx2.getRe() << ", " << complx2.getIm()
         << endl;

    cout << "C1 + C2 : " << (complx1 + complx2).getRe() << ", " << 
                            (complx1 + complx2).getIm() << endl;
    cout << "C1 - C2 : " << (complx1 - complx2).getRe() << ", " << 
                            (complx1 - complx2).getIm() << endl;
    cout << "C1 * C2 : " << (complx1 * complx2).getRe() << ", " << 
                            (complx1 * complx2).getIm() << endl;
    cout << "3 * C1 : " << (3 * complx1).getRe() << ", " <<
                           (3 * complx1).getIm() << endl;
    cout << "C1 / C2 : " << (complx1 / complx2).getRe() << ", " << 
                            (complx1 / complx2).getIm() << endl;
    cout << "C1 < C2 : " << (complx1 < complx2) << endl;
    cout << "C1 > C2 : " << (complx1 > complx2) << endl;

    return 0;
}