/* Bibliothèques internes-----------------------------------------------------*/
#include "linearSearch.h"

using namespace std;

/* Méthodes-------------------------------------------------------------------*/

int LinearSearch::search(const std::vector<int>& arr, int target) {
    numberComparisons = 0; // Réinitialisation des comparaisons pour cette recherche

    for (int i = 0; i < arr.size(); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return i; // Élément trouvé
        }
    }

    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1; // Élément non trouvé
}
