/* Bibliothèques externes-----------------------------------------------------*/
#include <cmath>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/sin.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

SinWaveGenerator::SinWaveGenerator():
TimeSeriesGenerator(0), amplitude(1.0), frequency(1.0), phase(0.0)
{

}

SinWaveGenerator::SinWaveGenerator(int seed, double a, double omega, 
                                   double phi):
TimeSeriesGenerator(seed), amplitude(a), frequency(omega), phase(phi)
{

}

/* Méthodes-------------------------------------------------------------------*/

vector<double> SinWaveGenerator::generateTimeSeries(int size)
{
    vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        double x = static_cast<double>(i);
        double value = amplitude * sin(frequency * x + phase);
        series.push_back(value);
    }

    return series;
}
