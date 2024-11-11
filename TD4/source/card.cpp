/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/card.h"

/* Bibliothèques externes-----------------------------------------------------*/
#include <string>

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

Card::Card(const string& _cardName):
cardName(_cardName)
{

}

/* Méthodes-------------------------------------------------------------------*/

string Card::getCardName() const
{
    return cardName;
}
