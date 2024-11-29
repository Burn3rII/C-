#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "time_series_generator.h"

using namespace std;

/**
 * @class StepGenerator
 * @brief Générateur de séries temporelles basées sur une fonction de saut.
 *
 * Ce générateur crée des séries temporelles où chaque valeur a 50% de chance
 * de changer (prise aléatoire entre 0 et 100) ou de conserver la valeur
 * précédente. La première valeur est toujours 0.
 */
class StepGenerator : public TimeSeriesGenerator
{
public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise le seed à 0.
     */
    StepGenerator();

    /**
     * @brief Constructeur paramétré.
     *
     * Permet de spécifier un seed pour la génération aléatoire.
     *
     * @param seed Seed initial pour le générateur.
     */
    StepGenerator(int seed);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~StepGenerator() = default;

    /* Méthodes */

    /**
     * @brief Génère une série temporelle basée sur des sauts aléatoires.
     *
     * Chaque valeur a 50% de chance de conserver la valeur précédente ou
     * de prendre une nouvelle valeur aléatoire entre 0 et 100.
     *
     * @param size Taille de la série temporelle à générer.
     * @return Vecteur contenant la série temporelle générée.
     */
    vector<double> generateTimeSeries(int size) override;
};

#endif
