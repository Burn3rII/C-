/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "headers/animal.h"
#include "headers/bird.h"
#include "headers/mammal.h"
#include "headers/reptile.h"
#include "headers/zoo.h"

using namespace std;

int main()
{
    // Création d'un zoo
    Zoo zoo("Wildlife Zoo");

    // Création d'animaux
    Bird* bird1 = new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 5, 3.0, 100.0, 2.5);
    Mammal* mammal1 = new Mammal("Lion", "Golden", "Carnivore", "Savannah", "Roar", false, 8, 180.5, 120.0, "Tawny");
    Reptile* reptile1 = new Reptile("Cobra", "Green", "Carnivore", "Desert", "Hiss", false, 3, 10.0, 60.0, "Diamond");

    // Test de l'ajout d'animaux au zoo
    zoo.addAnimal(bird1);
    zoo.addAnimal(mammal1);
    zoo.addAnimal(reptile1);

    // Affichage des animaux du zoo
    cout << "Listing animals in the zoo:\n";
    zoo.listAnimals();

    // Recherche d'un animal par nom
    cout << "\nSearching for 'Lion' in the zoo...\n";
    int index = zoo.searchAnimalByName("Lion");
    if (index != -1)
    {
        cout << "Found Lion at index: " << index << endl;
    }
    else
    {
        cout << "Lion not found.\n";
    }

    // Suppression d'un animal
    cout << "\nRemoving 'Eagle' from the zoo...\n";
    zoo.removeAnimal("Eagle");

    // Affichage des animaux après suppression
    cout << "\nListing animals in the zoo after removal:\n";
    zoo.listAnimals();

    // Calcul de l'âge moyen des animaux d'un type
    cout << "\nAverage age of Mammals in the zoo:\n";
    double avgAge = zoo.averageAgeForType("Mammal");
    cout << "Average age of Mammals: " << avgAge << " years\n";

    cout << "\nAverage age of Birds in the zoo:\n";
    avgAge = zoo.averageAgeForType("Bird");
    cout << "Average age of Birds: " << avgAge << " years\n";

    // Tentative de suppression d'un animal inexistant
    cout << "\nTrying to remove an animal that doesn't exist (Tiger)...\n";
    zoo.removeAnimal("Tiger");

    // Ajout d'un autre animal pour tester le maximum de capacité
    for (int i = 0; i < 100; ++i) {
        string name = "Animal_" + to_string(i);
        zoo.addAnimal(new Mammal(name, "Gray", "Herbivore", "Forest", "Silent", true, 5, 50.0, 60.0, "Gray"));
    }

    // Test du dépassement de capacité
    Mammal* excessAnimal = new Mammal("Elephant", "Gray", "Herbivore", "Forest", "Trumpet", false, 10, 5000.0, 300.0, "Gray");
    bool added = zoo.addAnimal(excessAnimal);
    if (!added) {
        cout << "\nCould not add the Elephant, zoo is at full capacity.\n";
    }

    return 0;
}
