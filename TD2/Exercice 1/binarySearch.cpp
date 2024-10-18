/* Bibliothèques internes-----------------------------------------------------*/
#include "binarySearch.h"

using namespace std;

/* Méthodes-------------------------------------------------------------------*/

int BinarySearch::search(const vector<int>& arr, int target) {
    numberComparisons = 0; // Réinitialisation des comparaisons pour cette recherche
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        numberComparisons++;

        // Si l'élément central est la cible, retour de son indice
        if (arr[mid] == target) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return mid;
        }

        // Si la cible est supérieure, on cherche dans la moitié droite
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // Sinon, on cherche dans la moitié gauche
        else {
            right = mid - 1;
        }
    }

    // Si la cible n'est pas trouvée
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}
