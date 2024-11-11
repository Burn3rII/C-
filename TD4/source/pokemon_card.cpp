/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <tuple>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/pokemon_card.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

PokemonCard::PokemonCard(const string& _cardName, const string& _pokemonType, 
    const string& _familyName, const int& _evolutionLevel, const int& _maxHP,
    const int& attack1Cost, const string& attack1Description, 
    const int& attack1Damages,
    const int& attack2Cost, const string& attack2Description, 
    const int& attack2Damages):
Card(_cardName), pokemonType(_pokemonType), familyName(_familyName), 
evolutionLevel(_evolutionLevel), maxHP(_maxHP), hp(_maxHP)
{
    Attack attack1 = { attack1Cost, attack1Cost, attack1Description, 
    attack1Damages };
    Attack attack2 = { attack2Cost, attack2Cost, attack2Description, 
    attack2Damages };

    attacks = {attack1, attack2};
}

/* Méthodes-------------------------------------------------------------------*/

vector<Attack> PokemonCard::getAttacks() const
{
    return attacks;
}

int PokemonCard::getHP() const
{
    return hp;
}

void PokemonCard::decreaseHP(int value)
{
    hp -= value;
}

void PokemonCard::fullHeal()
{
    hp = maxHP;
}

void PokemonCard::attachEnergyCard()
{
    for (auto& attack : attacks)
    {
        get<1>(attack) -= 1; /* Lorsqu'on attache une carte, on diminue de 1 le 
        coût de chaque attaque. On peut passer en-dessous de 0, ce n'est pas un 
        problème. */
    }
}

void PokemonCard::removeEnergy(int quantity)
{
    for (auto& attack : attacks)
    {
        get<0>(attack) += quantity; /* Pour simuler l'utilisation des 
        cartes energy, on augmente le coût de chaque attaque du nombre d'energy 
        utilisées. */
    }
}

void const PokemonCard::displayInfo()
{
    cout << "Pokemon card - Name: " << cardName 
    << ", Type: " << pokemonType 
    << ", Evolution Level: " << evolutionLevel 
    << " of the family " << familyName 
    << ", HP: " << hp 
    << endl;

    cout << "Attacks :" << endl;

    for (int i = 0; i < attacks.size(); i++)
    {
        int currentEnergyStorage = get<0>(attacks[i]) - get<1>(attacks[i]);

        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage: " << currentEnergyStorage 
        << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }
}
