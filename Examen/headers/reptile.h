#ifndef REPTILE_H
#define REPTILE_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "animal.h"

using namespace std;

class Reptile : public Animal
{
private:
    string scalePattern; // Motif d'écailles du reptile

public:
    /* Constructeurs */

    Reptile();
    Reptile(const string& _name, const string& _color, const string& _diet,  
            const string& _habitat, const string& _sounds, bool _isPet,
            int _age, double _weight, double _height, const string& _scalePattern);
    Reptile(const Reptile& other);

    /* Destructeurs */

    ~Reptile() override = default;

    /* Getters */

    string getScalePattern() const;

    /* Setters */

    void setScalePattern(const string& _scalePattern);

    /* Méthodes */

    virtual void printInfo() const override;
};

#endif
