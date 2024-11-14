/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/reptile.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Reptile::Reptile():
Animal(), scalePattern("unknown")
{

}

Reptile::Reptile(const string& _name, const string& _color, const string& _diet,
                 const string& _habitat, const string& _sounds, bool _isPet, 
                 int _age, double _weight, double _height, 
                 const string& _scalePattern):
Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height),
scalePattern(_scalePattern)
{

}

Reptile::Reptile(const Reptile& other):
Animal(other), scalePattern(other.scalePattern)
{

}

/* Getters--------------------------------------------------------------------*/

string Reptile::getScalePattern() const { return scalePattern; }

/* Setters--------------------------------------------------------------------*/

void Reptile::setScalePattern(const string& _scalePattern) { scalePattern = 
_scalePattern; }

/* Méthodes-------------------------------------------------------------------*/

void Reptile::printInfo() const
{
    cout << "Animal of type Reptile:\n";
    cout << "Name : " << name << "\n";
    cout << "Color : " << color << "\n";
    cout << "Scale Pattern : " << scalePattern << "\n";
    cout << "Diet : " << diet << "\n";
    cout << "Habitat : " << habitat << "\n";
    cout << "Age : " << age << "'s old\n";
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet\n";
    cout << "Weight : " << weight << "kg\n";
    cout << "Height : " << height << "cm\n";
    cout << endl;
}
