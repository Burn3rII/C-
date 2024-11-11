#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "card.h"

using namespace std;

/**
 * @class EnergyCard
 * @brief Représente une carte d'énergie dans le jeu.
 *
 * La classe `EnergyCard` dérive de la classe abstraite `Card` et stocke des
 * informations spécifiques à une carte d'énergie, notamment son type.
 */
class EnergyCard : public Card
{
private:
    /**
     * @brief Type d'énergie de la carte (par exemple, "Électrique", "Feu").
     */
    string energyType;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur de la classe `EnergyCard`.
     *
     * Initialise une carte d'énergie avec un type spécifique.
     *
     * @param _energyType Type d'énergie de la carte.
     */
    EnergyCard(const string& _energyType);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~EnergyCard() = default;

    /* Méthodes */

    /**
     * @brief Récupère le type d'énergie de la carte.
     *
     * @return Une chaîne de caractères représentant le type d'énergie.
     */
    string getEnergyType() const;

    /**
     * @brief Affiche les informations sur la carte d'énergie.
     *
     * Affiche le nom de la carte et le type d'énergie associé.
     */
    void const displayInfo() override;
};

#endif
