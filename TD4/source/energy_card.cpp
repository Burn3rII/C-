/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/energy_card.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

EnergyCard::EnergyCard(const string& _energyType):
Card("Energy"), energyType(_energyType)
{
    
}

/* Méthodes-------------------------------------------------------------------*/

string EnergyCard::getEnergyType() const
{
    return energyType;
}

void const EnergyCard::displayInfo()
{
    cout << cardName << " of type " << energyType << endl;
}
