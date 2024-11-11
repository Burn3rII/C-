/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <tuple>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/player.h"
#include "../headers/pokemon_card.h"
#include "../headers/energy_card.h"
#include "../headers/trainer_card.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Player::Player(const string& _playerName):
playerName(_playerName)
{
    
}

/* Méthodes-------------------------------------------------------------------*/

void Player::displayBench() const
{
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (auto& card : benchCards)
    {
        card->displayInfo();
    }
}

void Player::displayAction() const
{
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (auto& card : actionCards)
    {
        card->displayInfo();
    }
}

void Player::addCardToBench(Card* card)
{
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchCardIndex)
{
    PokemonCard* card = dynamic_cast<PokemonCard*>(benchCards.at
    (benchCardIndex));

    if (card == NULL)
    {
        cout << "You can not add a card other than a Pokemon Card in your action cards";

        return;
    }

    actionCards.push_back(card); // On ajoute la carte du bench aux actionCards
    benchCards.erase(benchCards.begin() + benchCardIndex); /* Puis on retire la
    carte des benchCards */

    cout << playerName << " is activating a Pokemon Card: " 
    << card->getCardName() << endl;
}

void Player::attachEnergyCard(int actionCardIndex, int energyIndex)
{
    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards.at
    (actionCardIndex));

    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards.at
    (energyIndex));

    if (pokemonCard == NULL or energyCard == NULL)
    {
        cout << "You cannot perform this action : wrong type of card used" 
        << endl;

        return;
    }

    pokemonCard->attachEnergyCard();

    cout << playerName << " is attaching Energy Card of type " << 
    energyCard->getEnergyType() << " to the Pokemon " << 
    pokemonCard->getCardName() << endl;

    benchCards.erase(benchCards.begin() + energyIndex); /* On supprime la carte 
    energy du bench une fois qu'elle a été utilisée. */
}

void Player::attack(int attackerActionCardIndex, int attackerAttackIndex,
                    Player enemy, int enemyActionCardIndex)
{
    PokemonCard* attackerPokemonCard = dynamic_cast<PokemonCard*>(actionCards.at
    (attackerActionCardIndex));

    PokemonCard* enemyPokemonCard = dynamic_cast<PokemonCard*>(enemy.
    actionCards.at(enemyActionCardIndex));

    if (attackerPokemonCard == NULL or enemyPokemonCard == NULL)
    {
        cout << "You cannot perform this action : wrong type of card used" 
        << endl;

        return;
    }

    Attack attack = attackerPokemonCard->getAttacks().at(attackerAttackIndex);
    int totalEnergyCost = get<0>(attack);
    string description = get<2>(attack);
    int damages = get<3>(attack);

    if (!hasEnoughEnergy(attack)) 
    {
        cout << "No enough energy to use this attack." << endl;

        return;
    }

    attackerPokemonCard->removeEnergy(totalEnergyCost);

    enemyPokemonCard->decreaseHP(damages);

    cout << playerName << " attacking " << enemy.playerName << "'s Pokemon " 
    << enemyPokemonCard->getCardName() 
    << " with the Pokemon " << attackerPokemonCard->getCardName() 
    << " with its attack : " << description << endl;

    cout << "Reducing " << damages << " from " 
    << enemy.playerName << "'s Pokemon's HP" << endl;

    if (enemyPokemonCard->getHP() <= 0) {
        enemy.actionCards.erase(enemy.actionCards.begin() + 
        attackerActionCardIndex);

        cout << "Pokemon " << enemyPokemonCard->getCardName()
        << " is dead" << endl;
    } else {
        cout << "Pokemon " << enemyPokemonCard->getCardName() 
        << " is still alive" << endl;
    }
}

bool Player::hasEnoughEnergy(const Attack& attack) const {
    return get<1>(attack) == 0;
}

void Player::useTrainer(int benchCardIndex)
{
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards.at
    (benchCardIndex));

    if (trainerCard == NULL)
    {
        cout << "The card you are trying to use is not a trainer." << endl;

        return;
    }

    cout << playerName << " is using the Trainer Card to \" " 
    << trainerCard->getTrainerEffect() << " \"" << endl;

    for (auto& card : actionCards)
    {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(card);

        if (pokemonCard == NULL) continue;

        pokemonCard->fullHeal();

        benchCards.erase(benchCards.begin() + benchCardIndex);
    }
}
