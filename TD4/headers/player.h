#ifndef PLAYER_H
#define PLAYER_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "card.h"
#include "pokemon_card.h"

using namespace std;

/**
 * @class Player
 * @brief Représente un joueur dans le jeu.
 *
 * La classe `Player` stocke les informations relatives à un joueur, y compris
 * son nom, ses cartes sur le banc et ses cartes en action.
 */
class Player
{
private:
    /**
     * @brief Nom du joueur.
     */
    string playerName;

    /**
     * @brief Cartes du joueur placées sur le banc (bench).
     */
    vector<Card*> benchCards;

    /**
     * @brief Cartes Pokémon actives du joueur.
     */
    vector<PokemonCard*> actionCards;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur de la classe `Player`.
     *
     * Initialise un joueur avec un nom spécifique.
     *
     * @param _playerName Nom du joueur.
     */
    Player(const string& _playerName);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel par défaut.
     */
    virtual ~Player() = default;

    /* Méthodes */

    /**
     * @brief Affiche les cartes présentes sur le banc du joueur.
     *
     * Affiche les informations de chaque carte placée sur le banc.
     */
    void displayBench() const;

    /**
     * @brief Affiche les cartes actives du joueur.
     *
     * Affiche les informations de chaque carte active (action).
     */
    void displayAction() const;

    /**
     * @brief Ajoute une carte au banc du joueur.
     *
     * @param card Pointeur vers la carte à ajouter.
     */
    void addCardToBench(Card* card);

    /**
     * @brief Active une carte Pokémon depuis le banc.
     *
     * Transfère une carte Pokémon du banc vers les cartes actives.
     *
     * @param benchCardIndex Index de la carte sur le banc à activer.
     */
    void activatePokemonCard(int benchCardIndex);

    /**
     * @brief Attache une carte d'énergie à une carte Pokémon active.
     *
     * @param actionCardIndex Index de la carte Pokémon active.
     * @param energyIndex Index de la carte d'énergie à attacher.
     */
    void attachEnergyCard(int actionCardIndex, int energyIndex);

    /**
     * @brief Effectue une attaque contre un autre joueur.
     *
     * Permet à une carte Pokémon active d'attaquer une carte active d'un 
     * adversaire.
     *
     * @param attackerActionCardIndex Index de la carte Pokémon attaquante.
     * @param attackerAttackIndex Index de l'attaque à utiliser.
     * @param enemy Joueur adverse.
     * @param enemyActionCardIndex Index de la carte active de l'adversaire à 
     * attaquer.
     */
    void attack(int attackerActionCardIndex, int attackerAttackIndex, 
                Player enemy, int enemyActionCardIndex);

    /**
     * @brief Vérifie si une attaque a suffisamment d'énergie pour être utilisée.
     *
     * @param attack L'attaque à vérifier.
     * @return true si l'énergie est suffisante, false sinon.
     */
    bool hasEnoughEnergy(const Attack& attack) const;

    /**
     * @brief Utilise une carte d'entraîneur depuis le banc.
     *
     * @param benchCardIndex Index de la carte d'entraîneur à utiliser.
     */
    void useTrainer(int benchCardIndex);
};

#endif
