#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "time_series_generator.h"

using namespace std;

/**
 * @class GaussianGenerator
 * @brief Générateur de séries temporelles suivant une distribution gaussienne.
 *
 * Ce générateur utilise la méthode de Box-Muller pour créer des valeurs
 * aléatoires suivant une loi normale définie par une moyenne et un écart type.
 */
class GaussianGenerator : public TimeSeriesGenerator
{
private:
    /**
     * @brief Moyenne de la distribution gaussienne.
     */
    double mean;

    /**
     * @brief Écart type de la distribution gaussienne.
     */
    double std;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise une distribution gaussienne avec une moyenne de 0, un écart
     * type de 1, et un seed à 0.
     */
    GaussianGenerator();

    /**
     * @brief Constructeur paramétré.
     *
     * Permet de spécifier les paramètres de la distribution gaussienne et un
     * seed.
     *
     * @param seed Seed initial pour le générateur.
     * @param _mean Moyenne de la distribution.
     * @param _std Écart type de la distribution.
     */
    GaussianGenerator(int seed, double _mean, double _std);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~GaussianGenerator() = default;

    /* Méthodes */

    /**
     * @brief Génère une série temporelle suivant une distribution gaussienne.
     *
     * @param size Taille de la série temporelle à générer.
     * @return Vecteur contenant la série temporelle générée.
     */
    vector<double> generateTimeSeries(int size) override;
};

#endif
