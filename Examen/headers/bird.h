#ifndef BIRD_H
#define BIRD_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "animal.h"

using namespace std;

class Bird : public Animal
{
private:
    double wingspan;

public:
    /* Constructeurs */

    Bird();
    Bird(const string& _name, const string& _color, const string& _diet,  
         const string& _habitat, const string& _sounds, bool _isPet,
         int _age, double _weight, double _height, double _wingspan);
    Bird(const Bird& other);

    /* Destructeurs */

    ~Bird() override = default;

    /* Getters */

    double getWingspan() const;

    /* Setters */

    void setWingspan(double _wingspan);

    /* Méthodes */

    virtual void printInfo() const override;
};

#endif
