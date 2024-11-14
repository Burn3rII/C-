/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/knn_double.h"

using namespace std;

/* Constructeurs -------------------------------------------------------------*/

KNNDouble::KNNDouble():
KNN<pair<double, double>>()
{

}

KNNDouble::KNNDouble(int k):
KNN<pair<double, double>>(k)
{

}

/* Méthodes-------------------------------------------------------------------*/

double KNNDouble::similarityMeasure(pair<double, double>& element1,
                                    pair<double, double>& element2)
{
    double diffX = element1.first - element2.first;
    double diffY = element1.second - element2.second;
    return sqrt(diffX * diffX + diffY * diffY); // Distance euclidienne
}
