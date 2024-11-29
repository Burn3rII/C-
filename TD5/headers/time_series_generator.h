#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

using namespace std;

/**
 * @class TimeSeriesGenerator
 * @brief Classe abstraite pour la génération de séries temporelles.
 *
 * Cette classe sert de base pour définir différents types de générateurs
 * de séries temporelles, tels que des séries gaussiennes, sinusoidales ou
 * basées sur des sauts. Elle fournit une interface commune pour la génération
 * et l'affichage de séries temporelles.
 */
class TimeSeriesGenerator
{
protected:
    /**
     * @brief Seed pour le générateur aléatoire.
     */
    int seed;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise le seed à 0.
     */
    TimeSeriesGenerator();

    /**
     * @brief Constructeur paramétré.
     *
     * Permet de spécifier un seed pour la génération aléatoire.
     *
     * @param seed Seed initial pour le générateur.
     */
    TimeSeriesGenerator(int seed);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~TimeSeriesGenerator() = default;

    /* Méthodes */

    /**
     * @brief Méthode virtuelle pure pour générer une série temporelle.
     *
     * Cette méthode doit être implémentée par les classes dérivées afin de
     * générer une série temporelle spécifique.
     *
     * @param size Taille de la série temporelle à générer.
     * @return Vecteur contenant la série temporelle générée.
     */
    virtual vector<double> generateTimeSeries(int size) = 0;

    /**
     * @brief Méthode statique pour afficher une série temporelle.
     *
     * Affiche les éléments de la série passée en paramètre sur une seule ligne.
     *
     * @param series Série temporelle à afficher.
     */
    static void printTimeSeries(const vector<double> series);
};

#endif
