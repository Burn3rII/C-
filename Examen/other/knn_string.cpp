/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/knn_string.h"

using namespace std;

/* Constructeurs -------------------------------------------------------------*/

KNNString::KNNString():
KNN<vector<string>>()
{

}

KNNString::KNNString(int k):
KNN<vector<string>>(k)
{

}

/* Méthodes-------------------------------------------------------------------*/

double KNNString::similarityMeasure(vector<string>& element1,
                                    vector<string>& element2)
{
    return 0.0;
}
