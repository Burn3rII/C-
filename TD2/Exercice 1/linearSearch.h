#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

/* Bibliothèques internes-----------------------------------------------------*/
#include "searchingAlgorithm.h"

using namespace std;

/**
 * @class LinearSearch
 * @brief Classe pour effectuer une recherche linéaire dans un tableau.
 *
 * La classe LinearSearch hérite de la classe SearchingAlgorithm 
 * et fournit une implémentation de la méthode search pour effectuer 
 * une recherche linéaire dans un tableau d'entiers.
 */
class LinearSearch : public SearchingAlgorithm {
public:
    /* Méthodes */

    /**
     * @brief Effectue une recherche linéaire dans un tableau d'entiers.
     * 
     * Cette méthode recherche une valeur cible dans un tableau d'entiers 
     * en parcourant chaque élément du tableau séquentiellement. 
     * Si la valeur cible est trouvée, son indice est retourné.
     * 
     * @param arr Le tableau d'entiers dans lequel effectuer la recherche.
     * @param target La valeur cible à rechercher.
     * @return L'indice de la valeur cible si elle est trouvée, sinon -1.
     * 
     * @note La recherche linéaire ne nécessite pas que le tableau soit trié.
     */
    int search(const vector<int>&, int) override;
};

#endif
