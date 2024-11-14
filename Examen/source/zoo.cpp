/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/zoo.h"
#include "../headers/mammal.h"
#include "../headers/bird.h"
#include "../headers/reptile.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Zoo::Zoo():
name("Unknown Zoo")
{

}

Zoo::Zoo(const string& _name):
name(_name)
{

}

Zoo::Zoo(const Zoo& other):
name(other.name)
{
    for (auto animal : other.animals)
    {
        animals.push_back(animal); // Ajoute un pointeur vers les animaux (pas de copie)
    }
}

/* Getters--------------------------------------------------------------------*/

string Zoo::getName() const { return name; }
int Zoo::getCurrentCapacity() const { return animals.size(); }
int Zoo::getMaxCapacity() const { return MAX_CAPACITY; }
vector<Animal*> Zoo::getAnimals() const { return animals; }

/* Setters--------------------------------------------------------------------*/

void Zoo::setName(const string& _name) { name = _name; }

/* Méthodes-------------------------------------------------------------------*/

void Zoo::listAnimals() const
{
    cout << "Zoo: " << name << "\n";
    for (const auto& animal : animals)
    {
        animal->printInfo();
        cout << endl;
    }
}

bool compareAnimalsByName(Animal* a, Animal* b)
{
    return a->getName() < b->getName();
}

bool Zoo::addAnimal(Animal* animal)
{
    if (animals.size() >= MAX_CAPACITY)
    {
        cout << "Le zoo est plein. Impossible d'ajouter l'animal.\n";
        return false;
    }

    // Vérifie si un animal avec le même nom existe déjà
    auto it = lower_bound(animals.begin(), animals.end(), animal,
                          compareAnimalsByName);

    if (it != animals.end() && (*it)->getName() == animal->getName())
    {
        cout << "Un animal avec le nom " << animal->getName() 
        << " existe déjà dans le zoo.\n";
        return false;
    }

    // Insère l'animal à la position correcte
    animals.insert(it, animal);
    return true;
}

int Zoo::searchAnimalByName(const string& animalName) const
{
    for (size_t i = 0; i < animals.size(); ++i)
    {
        if (animals[i]->getName() == animalName)
        {
            return i;
        }
    }

    return -1;  // Si l'animal n'est pas trouvé
}

void Zoo::removeAnimal(const string& animalName)
{
    int index = searchAnimalByName(animalName);
    if (index != -1)
    {
        delete animals[index]; // Libère la mémoire
        animals.erase(animals.begin() + index); // Supprime l'animal du vecteur
        cout << "Animal " << animalName << " a été retiré du zoo.\n";
    }
    else
    {
        cout << "Animal " << animalName << " n'existe pas dans le zoo.\n";
    }
}

double Zoo::averageAgeForType(const string& type) const
{
    int count = 0;
    int totalAge = 0;

    for (Animal* animal : animals)
    {
        // On vérifie si l'animal est du type voulu à l'aide de dynamic_cast
        if (type == "Mammal")
        {
            Mammal* mammal = dynamic_cast<Mammal*>(animal);
            if (mammal)
            {
                totalAge += mammal->getAge();
                count++;
            }
        }
        else if (type == "Bird")
        {
            Bird* bird = dynamic_cast<Bird*>(animal);
            if (bird)
            {
                totalAge += bird->getAge();
                count++;
            }
        }
        else if (type == "Reptile")
        {
            Reptile* reptile = dynamic_cast<Reptile*>(animal);
            if (reptile)
            {
                totalAge += reptile->getAge();
                count++;
            }
        }
    }

    // Si aucun animal du type n'a été trouvé, on renvoie 0.0
    return count > 0 ? static_cast<double>(totalAge) / count : 0.0;
}


