/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/time_series_generator.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

TimeSeriesGenerator::TimeSeriesGenerator():
seed(0)
{

}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
seed(_seed)
{

}

/* Méthodes-------------------------------------------------------------------*/
 
void TimeSeriesGenerator::printTimeSeries(const vector<double> series)
{
    for (double value : series)
    {
        cout << value << " ";
    }
    cout << endl;
}
