#ifndef MAMMAL_H
#define MAMMAL_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "animal.h"

using namespace std;

class Mammal : public Animal
{
private:
    string furColor;

public:
    /* Constructeurs */

    Mammal();
    Mammal(const string& _name, const string& _color, const string& _diet,  
           const string& _habitat, const string& _sounds, bool _isPet,
           int _age, double _weight, double _height, const string& _furColor);
    Mammal(const Mammal& other);

    /* Destructeurs */

    ~Mammal() override = default;

    /* Getters */

    string getFurColor() const;

    /* Setters */

    void setFurColor(const string& _furColor);

    /* Méthodes */

    virtual void printInfo() const override;
};

#endif
