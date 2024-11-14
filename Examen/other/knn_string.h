#ifndef KNN_STRING_H
#define KNN_STRING_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>
#include <string>

/* Bibliothèques internes-----------------------------------------------------*/
#include "knn.h"

using namespace std;

class KNNString : public KNN<vector<string>>
{
public:
    /* Constructeurs */

    KNNString();
    KNNString(int k);

    /* Destructeurs */

    ~KNNString() override = default;

    /* Méthodes */

    double similarityMeasure(vector<string>& element1, 
                             vector<string>& element2) override;
};

#endif
