#ifndef ZOO_H
#define ZOO_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "animal.h"

using namespace std;

class Zoo
{
private:
    string name;
    static const int MAX_CAPACITY = 100;
    vector<Animal*> animals;

public:
    /* Constructeurs */

    Zoo();
    Zoo(const string& _name);
    Zoo(const Zoo& other);

    /* Destructeurs */

    virtual ~Zoo() = default;

    /* Getters */

    string getName() const;
    int getCurrentCapacity() const;
    int getMaxCapacity() const;
    vector<Animal*> getAnimals() const;

    /* Setters */

    void setName(const string& _name);

    /* Méthodes */

    void listAnimals() const;
    bool addAnimal(Animal* animal);
    int searchAnimalByName(const string& animalName) const;
    void removeAnimal(const string& animalName);
    double averageAgeForType(const string& type) const;
};

#endif
