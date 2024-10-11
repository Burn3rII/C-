#ifndef MYCLASS_H
#define MYCLASS_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

/**
 * @class MyClass
 * @brief Classe stockant et manipulant du texte.
 */
class MyClass {
private:
    /**
     * @brief Texte à stocker.
     */
    string text;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut de MyClass.
     * Initialise un objet MyClass avec une chaîne par défaut.
     */
    MyClass();

    /**
     * @brief Constructeur de MyClass.
     * Initialise l'objet avec la chaîne de caractères donnée.
     * 
     * @param str Chaîne de caractères utilisée pour initialiser le texte.
     */
    MyClass(const string& str);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel de MyClass.
     * Permet à la classe d'être détruite proprement, même en cas d'héritage.
     */
    virtual ~MyClass() = default;

    /* Méthodes */

    /**
     * @brief Affiche le contenu du texte dans la console.
     */
    void printMyElement() const;
};

#endif

