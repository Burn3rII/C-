/* Bibliothèques externes-----------------------------------------------------*/
#include <ostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "searchingAlgorithm.h"

using namespace std;

/* Variables static-----------------------------------------------------------*/

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

/* Constructeurs--------------------------------------------------------------*/

SearchingAlgorithm::SearchingAlgorithm():
numberComparisons(0)
{
    
}

/* Méthodes-------------------------------------------------------------------*/

void SearchingAlgorithm::displaySearchResults(ostream& os, 
                                              int results, int target) const
{
    totalSearch++;

    if (results == -1)
    {
        os << "Could not find the element" << target << "." << endl;
    } else {
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<double>(totalComparisons) / 
                             totalSearch;
        os << numberComparisons << " comparisons where made to find the"
        " element " << target << endl;
    }
}
