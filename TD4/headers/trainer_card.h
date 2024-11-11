#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "card.h"

using namespace std;

/**
 * @class TrainerCard
 * @brief Représente une carte d'entraîneur dans le jeu.
 *
 * La classe `TrainerCard` dérive de la classe abstraite `Card` et stocke des
 * informations spécifiques à une carte d'entraîneur, notamment l'effet de 
 * l'entraîneur.
 */
class TrainerCard : public Card
{
private:
    /**
     * @brief Effet spécifique de l'entraîneur (par exemple, "soigne tous les 
     * Pokémon en action").
     */
    string trainerEffect;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur de la classe `TrainerCard`.
     *
     * Initialise une carte d'entraîneur avec un nom et un effet spécifique.
     *
     * @param _cardName Nom de la carte.
     * @param _trainerEffect Effet associé à la carte d'entraîneur.
     */
    TrainerCard(const string& _cardName, const string& _trainerEffect);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel par défaut.
     */
    virtual ~TrainerCard() = default;

    /* Méthodes */

    /**
     * @brief Récupère l'effet de l'entraîneur de la carte.
     *
     * @return Une chaîne de caractères représentant l'effet de la carte 
     * d'entraîneur.
     */
    string getTrainerEffect() const;

    /**
     * @brief Affiche les informations sur la carte d'entraîneur.
     *
     * Affiche le nom de la carte et l'effet associé à l'entraîneur.
     */
    void const displayInfo() override;
};

#endif
