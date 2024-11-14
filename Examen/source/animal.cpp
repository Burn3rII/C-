/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/animal.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Animal::Animal():
name("Inconnu"), color("Inconnu"), diet("Inconnu"), habitat("Inconnu"),
sounds("Inconnu"), isPet(false), age(0), weight(0.0), height(0.0)
{
    
}

Animal::Animal(const string& _name, const string& _color, const string& _diet,  
               const string& _habitat, const string& _sounds, bool _isPet,
               int _age, double _weight, double _height):
name(_name), color(_color), diet(_diet), habitat(_habitat), sounds(_sounds), 
isPet(_isPet), age(_age), weight(_weight), height(_height)
{

}

Animal::Animal(const Animal& other):
name(other.name), color(other.color), diet(other.diet), habitat(other.habitat),
sounds(other.sounds), isPet(other.isPet), age(other.age), weight(other.weight), 
height(other.height)
{

}

/* Getters--------------------------------------------------------------------*/

string Animal::getName() const { return name; }
string Animal::getColor() const { return color; }
string Animal::getDiet() const { return diet; }
string Animal::getHabitat() const { return habitat; }
string Animal::getSounds() const { return sounds; }
bool Animal::getIsPet() const { return isPet; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
double Animal::getHeight() const { return height; }

/* Setters--------------------------------------------------------------------*/

void Animal::setName(const string& _name) { name = _name; }
void Animal::setColor(const string& _color) { color = _color; }
void Animal::setDiet(const string& _diet) { diet = _diet; }
void Animal::setHabitat(const string& _habitat) { habitat = _habitat; }
void Animal::setSounds(const string& _sounds) { sounds = _sounds; }
void Animal::setIsPet(bool _isPet) { isPet = _isPet; }
void Animal::setAge(int _age) { age = _age; }
void Animal::setWeight(double _weight) { weight = _weight; }
void Animal::setHeight(double _height) { height = _height; }

/* Méthodes-------------------------------------------------------------------*/

void Animal::printInfo() const
{
    cout << "Animal of unknown type:\n";
    cout << "Name : " << name << "\n";
    cout << "Color : " << color << "\n";
    cout << "Diet : " << diet << "\n";
    cout << "Habitat : " << habitat << "\n";
    cout << "Age : " << age << "'s old\n";
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet\n";
    cout << "Weight : " << weight << "kg\n";
    cout << "Height : " << height << "cm\n";
    cout << endl;
}