#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "card.h"

using namespace std;

/* Alias----------------------------------------------------------------------*/

/**
 * @typedef TotalCost
 * @brief Représente le coût total d'une attaque.
 */
using TotalCost = int;

/**
 * @typedef RemainingCost
 * @brief Représente le coût restant requis pour effectuer une attaque.
 */
using RemainingCost = int;

/**
 * @typedef Description
 * @brief Représente la description d'une attaque.
 */
using Description = string;

/**
 * @typedef Damages
 * @brief Représente les dommages infligés par une attaque.
 */
using Damages = int;

/**
 * @typedef Attack
 * @brief Définit une attaque comme un tuple de coût, coût restant, description 
 * et dommages.
 */
using Attack = tuple<TotalCost, RemainingCost, Description, Damages>;

/**
 * @class PokemonCard
 * @brief Représente une carte Pokémon dans le jeu.
 *
 * La classe `PokemonCard` dérive de la classe abstraite `Card` et stocke
 * des informations spécifiques à une carte Pokémon, telles que le type,
 * la famille, le niveau d'évolution, les points de vie et les attaques.
 */
class PokemonCard : public Card
{
private:
    /**
     * @brief Type de Pokémon (par exemple, "Électrique", "Feu").
     */
    string pokemonType;

    /**
     * @brief Famille du Pokémon (par exemple, "Pikachu" pour la famille de 
     * Raichu).
     */
    string familyName;

    /**
     * @brief Niveau d'évolution du Pokémon.
     */
    int evolutionLevel;

    /**
     * @brief Points de vie maximum du Pokémon.
     */
    int maxHP;

    /**
     * @brief Points de vie actuels du Pokémon.
     */
    int hp;

    /**
     * @brief Liste des attaques possibles du Pokémon.
     */
    vector<Attack> attacks;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur de la classe `PokemonCard`.
     *
     * Initialise une carte Pokémon avec le nom, le type de Pokémon, sa famille,
     * son niveau d'évolution, ses points de vie maximum, et jusqu'à deux 
     * attaques.
     *
     * @param _cardName Nom de la carte.
     * @param _pokemonType Type du Pokémon (ex: "Feu").
     * @param _familyName Nom de la famille du Pokémon (ex: "Pikachu").
     * @param _evolutionLevel Niveau d'évolution du Pokémon.
     * @param _maxHP Points de vie maximum du Pokémon.
     * @param attack1Cost Coût de la première attaque.
     * @param attack1Description Description de la première attaque.
     * @param attack1Damages Dommages de la première attaque.
     * @param attack2Cost Coût de la deuxième attaque.
     * @param attack2Description Description de la deuxième attaque.
     * @param attack2Damages Dommages de la deuxième attaque.
     */
    PokemonCard(const string& _cardName, const string& _pokemonType, 
                const string& _familyName, const int& _evolutionLevel, 
                const int& _maxHP, const int& attack1Cost, 
                const string& attack1Description, const int& attack1Damages,
                const int& attack2Cost, const string& attack2Description, 
                const int& attack2Damages);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~PokemonCard() = default;

    /* Méthodes */

    /**
     * @brief Récupère la liste des attaques disponibles.
     *
     * Retourne un vecteur contenant les attaques du Pokémon sous forme de 
     * `tuple`.
     *
     * @return Un vecteur d'attaques.
     */
    vector<Attack> getAttacks() const;

    /**
     * @brief Récupère les points de vie actuels du Pokémon.
     *
     * @return Points de vie actuels.
     */
    int getHP() const;

    /**
     * @brief Diminue les points de vie du Pokémon.
     *
     * Utilisé pour infliger des dégâts au Pokémon en réduisant ses points de 
     * vie.
     *
     * @param value Quantité de points de vie à retirer.
     */
    void decreaseHP(int value);

    /**
     * @brief Restaure les points de vie du Pokémon à leur maximum.
     */
    void fullHeal();

    /**
     * @brief Attache une carte d'énergie au Pokémon.
     *
     * Simule l'ajout d'une carte d'énergie, augmentant ainsi les ressources
     * nécessaires pour effectuer une attaque.
     */
    void attachEnergyCard();

    /**
     * @brief Retire une quantité d'énergie du Pokémon.
     *
     * Permet de retirer une certaine quantité d'énergie attachée au Pokémon.
     *
     * @param quantity Quantité d'énergie à retirer.
     */
    void removeEnergy(int quantity);

    /**
     * @brief Affiche les informations sur la carte Pokémon.
     *
     * Affiche le nom, le type, la famille, le niveau d'évolution, les points 
     * de vie, ainsi que les attaques disponibles du Pokémon.
     */
    void const displayInfo() override;
};

#endif
