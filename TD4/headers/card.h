#ifndef CARD_H
#define CARD_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

using namespace std;

/**
 * @class Card
 * @brief Représente une carte dans le jeu.
 * 
 * La classe Card est une classe de base abstraite qui représente une carte générique
 * dans un jeu. Elle contient un nom de carte, ainsi que des méthodes permettant
 * d'obtenir ce nom et d'afficher des informations relatives à la carte.
 * 
 * Cette classe est conçue pour être dérivée par des classes spécifiques de cartes,
 * comme des cartes Pokémon, des cartes d'énergie, ou des cartes d'entraîneur.
 */
class Card
{
protected:
    string cardName;

public:
    /**
     * @brief Constructeur de la classe Card.
     * 
     * Crée une nouvelle carte avec un nom spécifié.
     * 
     * @param _cardName Le nom de la carte.
     */
    Card(const string& _cardName);

    /**
     * @brief Destructeur virtuel de la classe Card.
     * 
     * Permet de garantir un nettoyage approprié des ressources lorsqu'une
     * carte est supprimée. Il est marqué `virtual` pour permettre la suppression
     * correcte des objets dérivés via des pointeurs de type Card.
     */
    virtual ~Card() = default;

    /**
     * @brief Récupère le nom de la carte.
     * 
     * Cette méthode permet d'obtenir le nom de la carte sous forme de chaîne de caractères.
     * 
     * @return Le nom de la carte.
     */
    string getCardName() const;

    /**
     * @brief Affiche des informations sur la carte.
     * 
     * Méthode virtuelle pure qui doit être implémentée dans les classes dérivées.
     * Chaque type de carte (par exemple, une carte Pokémon ou une carte d'énergie) devra
     * définir cette méthode pour afficher des informations spécifiques sur cette carte.
     */
    virtual void const displayInfo() = 0;
};

#endif
