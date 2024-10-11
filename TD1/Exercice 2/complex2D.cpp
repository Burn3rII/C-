/* Bibliothèques externes-----------------------------------------------------*/
#include <cmath>

/* Bibliothèques internes-----------------------------------------------------*/
#include "complex2D.h"

/* Constructeurs--------------------------------------------------------------*/

Complex2D::Complex2D():  
re(0), im(0) // Plus lisible et rapide que de mettre des = dans la fonction car 
             // il ne va pas appeler le constructeur par défaut comme il le 
             // ferait avec des = dans la fonction. 
{

}

Complex2D::Complex2D(double val):
re(val), im(val)
{

}

Complex2D::Complex2D(double _re, double _im):
re(_re), im(_im)
{

}

Complex2D::Complex2D(const Complex2D& other):
re(other.re), im(other.im)
{

}

/* Opérateurs-----------------------------------------------------------------*/

/* + */ 

Complex2D operator +(const Complex2D& complx1, const Complex2D& complx2)
{
    return Complex2D(complx1.re+complx2.re, complx1.im+complx2.im);
}

/* - */

Complex2D operator -(const Complex2D& complx1, const Complex2D& complx2)
{
    return complx1 + (-complx2);
}

Complex2D operator -(const Complex2D& complx)
{
    return Complex2D(-complx.re, -complx.im);
}

/* * */

Complex2D operator *(const Complex2D& complx1, const Complex2D& complx2)
{
    double re = complx1.re*complx2.re - complx1.im*complx2.im;
    double im = complx1.re*complx2.im + complx1.im*complx2.re;
    return Complex2D(re, im);
}

/* / */

Complex2D operator /(const Complex2D& complx1, const Complex2D& complx2)
{
    return complx1 * (1/complx2);
}

/* Comparaison */

bool operator <(const Complex2D& complx1, const Complex2D& complx2)
{
    return complx1.module() < complx2.module() ? true : false;
}

bool operator >(const Complex2D& complx1, const Complex2D& complx2)
{
    return complx1.module() > complx2.module() ? true : false;
}

/* Méthodes-------------------------------------------------------------------*/

double Complex2D::getRe() const
{
    return re;
}

double Complex2D::getIm() const
{
    return im;
}

void Complex2D::setRe(double val)
{
    re = val;
}

void Complex2D::setIm(double val)
{
    im = val;
}

Complex2D Complex2D::conjugate() const
{
    return Complex2D(re, -im);
}

double Complex2D::module() const
{
    return sqrt(re*re+im*im);
}