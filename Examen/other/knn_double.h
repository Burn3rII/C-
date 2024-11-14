#ifndef KNN_DOUBLE_H
#define KNN_DOUBLE_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>
#include <cmath>

/* Bibliothèques internes-----------------------------------------------------*/
#include "knn.h"

using namespace std;

class KNNDouble : public KNN<pair<double, double>>
{
public:
    /* Constructeurs */

    KNNDouble();
    KNNDouble(int k);

    /* Destructeurs */

    ~KNNDouble() override = default;

    /* Méthodes */

    double similarityMeasure(pair<double, double>& element1, 
                             pair<double, double>& element2) override;
};

#endif
