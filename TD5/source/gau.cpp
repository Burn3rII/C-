/* Bibliothèques externes-----------------------------------------------------*/
#include <cmath>
#include <random>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/gau.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

GaussianGenerator::GaussianGenerator():
TimeSeriesGenerator(0), mean(0.0), std(1.0)
{

}

GaussianGenerator::GaussianGenerator(int seed, double _mean, double _std): 
TimeSeriesGenerator(seed), mean(_mean), std(_std)
{

}

/* Méthodes-------------------------------------------------------------------*/

vector<double> GaussianGenerator::generateTimeSeries(int size)
{
    vector<double> series;
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < size; ++i)
    {
        double u1 = distribution(generator);
        double u2 = distribution(generator);
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2); // Box-Muller
        double value = mean + z0 * std; // Génération de la valeur gaussienne
        series.push_back(value);
    }

    return series;
}
