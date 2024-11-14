#ifndef ANIMAL_H
#define ANIMAL_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
    string color;
    string diet;
    string habitat;
    string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    /* Constructeurs */

    Animal();
    Animal(const string& _name, const string& _color, const string& _diet,  
           const string& _habitat, const string& _sounds, bool _isPet,
           int _age, double _weight, double _height);
    Animal(const Animal& other);

    /* Destructeurs */

    virtual ~Animal() = default;

    /* Getters */
    
    string getName() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;
    string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

    /* Setters */

    void setName(const string& _name);
    void setColor(const string& _color);
    void setDiet(const string& _diet);
    void setHabitat(const string& _habitat);
    void setSounds(const string& _sounds);
    void setIsPet(bool _isPet);
    void setAge(int _age);
    void setWeight(double _weight);
    void setHeight(double _height);

    /* Méthodes */

    virtual void printInfo() const;
};

#endif
