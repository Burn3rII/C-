/* Bibliothèques externes-----------------------------------------------------*/
#include <random>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/stp.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

StepGenerator::StepGenerator():
TimeSeriesGenerator(0)
{

}

StepGenerator::StepGenerator(int seed):
TimeSeriesGenerator(seed)
{

}

/* Méthodes-------------------------------------------------------------------*/

vector<double> StepGenerator::generateTimeSeries(int size)
{
    vector<double> series;
    series.reserve(size);

    default_random_engine generator(seed);
    uniform_int_distribution<int> value_distribution(0, 100);   // Pour générer des valeurs entre 0 et 100
    uniform_real_distribution<double> probability_distribution(0.0, 1.0); // Pour la probabilité de 50%

    // Le premier instant est fixé à 0
    double current_value = 0;
    series.push_back(current_value);

    for (int i = 1; i < size; ++i)
    {
        if (probability_distribution(generator) < 0.5)
        {
            // Avec 50% de chance, on génère une nouvelle valeur entre 0 et 100
            current_value = value_distribution(generator);
        }
        // Avec 50% de chance, la valeur précédente est conservée
        series.push_back(current_value);
    }

    return series;
}
