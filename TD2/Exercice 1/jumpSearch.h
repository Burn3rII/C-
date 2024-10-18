#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

/* Bibliothèques internes-----------------------------------------------------*/
#include "searchingAlgorithm.h"

using namespace std;

/**
 * @class JumpSearch
 * @brief Classe pour l'implémentation de l'algorithme de recherche par saut.
 * 
 * La classe JumpSearch hérite de la classe SearchingAlgorithm et 
 * fournit une implémentation spécifique de la méthode search pour 
 * effectuer une recherche par saut sur un tableau trié d'entiers.
 */
class JumpSearch : public SearchingAlgorithm {
public:
    /* Méthodes */

    /**
     * @brief Effectue une recherche par saut dans un tableau trié.
     * 
     * Cette méthode recherche une valeur cible dans un tableau d'entiers 
     * en utilisant l'algorithme de recherche par saut. Elle est implémentée 
     * en remplaçant la méthode search de la classe parente SearchingAlgorithm.
     * 
     * @param arr Le tableau d'entiers trié dans lequel effectuer la recherche.
     * @param target La valeur cible à rechercher.
     * @return L'indice de la valeur cible si elle est trouvée, sinon -1.
     * 
     * @note Le tableau doit être trié pour que la recherche par saut fonctionne correctement.
     */
    int search(const vector<int>&, int) override;
};

#endif
