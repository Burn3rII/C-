/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/bird.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Bird::Bird():
Animal(), wingspan(0.0)
{

}

Bird::Bird(const string& _name, const string& _color, const string& _diet,  
           const string& _habitat, const string& _sounds, bool _isPet,
           int _age, double _weight, double _height, double _wingspan):
Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height),
wingspan(_wingspan)
{

}

Bird::Bird(const Bird& other):
Animal(other), wingspan(other.wingspan)
{

}

/* Getters--------------------------------------------------------------------*/

double Bird::getWingspan() const { return wingspan; }

/* Setters--------------------------------------------------------------------*/

void Bird::setWingspan(double _wingspan) { wingspan = _wingspan; }

/* Méthodes-------------------------------------------------------------------*/

void Bird::printInfo() const
{
    cout << "Animal of type Bird:\n";
    cout << "Name : " << name << "\n";
    cout << "Color : " << color << "\n";
    cout << "Diet : " << diet << "\n";
    cout << "Habitat : " << habitat << "\n";
    cout << "Age : " << age << "'s old\n";
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet\n";
    cout << "Weight : " << weight << "kg\n";
    cout << "Height : " << height << "cm\n";
    cout << "Wingspan : " << wingspan << "cm\n";
    cout << endl;
}
