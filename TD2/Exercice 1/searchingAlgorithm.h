
#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <ostream>
#include <vector>

using namespace std;

/**
 * @class SearchingAlgorithm
 * @brief Classe abstraite pour les algorithmes de recherche.
 *
 * Cette classe définit une interface pour les algorithmes de recherche.
 * Les classes dérivées doivent implémenter la méthode search.
 */
class SearchingAlgorithm
{
protected:
    /**
     * @brief Compteur de comparaisons pour l'instance actuelle
     */
    int numberComparisons;

    /**
     * @brief Compteur total de comparaisons pour toutes les instances
     */
    static int totalComparisons;
        /**
     * @brief Compteur total de recherches effectuées
     */
    static int totalSearch;
        /**
     * @brief Moyenne des comparaisons par recherche
     */
    static double averageComparisons;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut de la classe SearchingAlgorithm.
     *
     * Ce constructeur initialise le compteur de comparaisons à zéro.
     */
    SearchingAlgorithm();

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel par défaut.
     *
     * Permet aux classes dérivées de libérer les ressources correctement.
     */
    virtual ~SearchingAlgorithm() = default;

    /* Méthodes */

    /**
     * @brief Affiche les résultats de la recherche.
     *
     * @param os Le flux de sortie où afficher les résultats.
     * @param results Le résultat de la recherche (indice de l'élément trouvé ou -1).
     * @param target La valeur cible recherchée.
     */
    void displaySearchResults(ostream& os, int results, int target) const;

    /**
     * @brief Méthode de recherche virtuelle pure.
     *
     * Les classes dérivées doivent implémenter cette méthode pour effectuer
     * une recherche dans un tableau d'entiers.
     *
     * @param arr Le tableau d'entiers dans lequel effectuer la recherche.
     * @param target La valeur cible à rechercher.
     * @return L'indice de la valeur cible si elle est trouvée, sinon -1.
     */
    virtual int search(const vector<int>&, int) = 0;
};

#endif
