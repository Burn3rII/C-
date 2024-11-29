#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

/* Bibliothèques internes-----------------------------------------------------*/
#include "time_series_generator.h"

/**
 * @class SinWaveGenerator
 * @brief Générateur de séries temporelles basées sur une fonction sinus.
 *
 * Ce générateur crée des séries temporelles suivant la fonction :
 * \f$ f(x) = A \cdot \sin(\omega \cdot x + \phi) \f$
 */
class SinWaveGenerator : public TimeSeriesGenerator
{
private:
    /**
     * @brief Amplitude de la fonction sinus.
     */
    double amplitude;

    /**
     * @brief Fréquence de la fonction sinus.
     */
    double frequency;

    /**
     * @brief Phase initiale de la fonction sinus.
     */
    double phase;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise une fonction sinus avec une amplitude de 1, une fréquence de 1,
     * et une phase de 0, avec un seed à 0.
     */
    SinWaveGenerator();

    /**
     * @brief Constructeur paramétré.
     *
     * Permet de spécifier les paramètres de la fonction sinus et un seed.
     *
     * @param seed Seed initial pour le générateur.
     * @param a Amplitude de la fonction sinus.
     * @param omega Fréquence de la fonction sinus.
     * @param phi Phase initiale de la fonction sinus.
     */
    SinWaveGenerator(int seed, double a, double omega, double phi);

    /* Destructeurs */

    /**
     * @brief Destructeur par défaut virtuel.
     */
    virtual ~SinWaveGenerator() = default;

    /* Méthodes */

    /**
     * @brief Génère une série temporelle basée sur une fonction sinus.
     *
     * @param size Taille de la série temporelle à générer.
     * @return Vecteur contenant la série temporelle générée.
     */
    vector<double> generateTimeSeries(int size) override;
};

#endif
