/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/mammal.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Mammal::Mammal():
Animal(), furColor("brown")
{
    
}

Mammal::Mammal(const string& _name, const string& _color, const string& _diet,  
               const string& _habitat, const string& _sounds, bool _isPet,
               int _age, double _weight, double _height, 
               const string& _furColor):
Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, 
_height), furColor(_furColor)
{

}

Mammal::Mammal(const Mammal& other):
Animal(other), furColor(other.furColor)
{

}

/* Getters--------------------------------------------------------------------*/

string Mammal::getFurColor() const { return furColor; }

/* Setters--------------------------------------------------------------------*/

void Mammal::setFurColor(const string& _furColor) { furColor = _furColor; }

/* Méthodes-------------------------------------------------------------------*/

void Mammal::printInfo() const
{
    cout << "Animal of type Mammal:\n";
    cout << "Name : " << name << "\n";
    cout << "Color : " << color << "\n";
    cout << "Fur Color : " << furColor << "\n";
    cout << "Diet : " << diet << "\n";
    cout << "Habitat : " << habitat << "\n";
    cout << "Age : " << age << "'s old\n";
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet\n";
    cout << "Weight : " << weight << "kg\n";
    cout << "Height : " << height << "cm\n";
    cout << endl;
}