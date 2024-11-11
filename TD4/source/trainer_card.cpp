/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/trainer_card.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

TrainerCard::TrainerCard(const string& _cardName, const string& _trainerEffect):
Card(_cardName), trainerEffect(_trainerEffect)
{
    
}

/* Méthodes-------------------------------------------------------------------*/

string TrainerCard::getTrainerEffect() const
{
    return trainerEffect;
}

void const TrainerCard::displayInfo()
{
    cout << "Trainer card - Name: " << cardName
    << ", Effect: " << trainerEffect << endl;
}
