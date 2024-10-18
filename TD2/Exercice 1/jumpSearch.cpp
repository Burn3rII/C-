/* Bibliothèques externes-----------------------------------------------------*/
#include <cmath>

/* Bibliothèques internes-----------------------------------------------------*/
#include "jumpSearch.h"

/* Méthodes-------------------------------------------------------------------*/

int JumpSearch::search(const vector<int>& arr, int target) {
    numberComparisons = 0; // Réinitialisation des comparaisons pour cette recherche
    int n = arr.size();
    int step = sqrt(n); // Taille du saut
    int prev = 0;

    // Trouver le bloc où l'élément pourrait se trouver
    while (arr[min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return -1;
        }
    }

    // Recherche linéaire dans le bloc identifié
    for (int i = prev; i < min(step, n); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return i;
        }
    }

    // Met à jour les statistiques et retourne -1 si l'élément n'est pas trouvé
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}
