#ifndef KNN_H
#define KNN_H

#include <algorithm>

using namespace std;

template <typename T>
class KNN
{
private:
    int k;

public:
    /* Constructeurs */

    KNN();
    KNN(int k);

    /* Destructeurs */

    virtual ~KNN() = default;

    /* Getters */

    int getK() const;

    /* Méthodes */

    vector<int> findNearestNeighbours(vector<T>& trainData, T& target) const;
    double virtual similarityMeasure(T& element1, T& element2) = 0;
};

/* Constructeurs--------------------------------------------------------------*/

template <typename T>
KNN<T>::KNN():
k(0)
{
    
}

template <typename T>
KNN<T>::KNN(int _k):
k(_k)
{

}

/* Méthodes-------------------------------------------------------------------*/

bool compareDistances(const pair<double, int>& a, const pair<double, int>& b)
{
    return a.first < b.first;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(vector<T>& trainData, T& target) const
{
    vector<pair<double, int>> distances;

    for (int i = 0; i < trainData.size(); ++i)
    {
        double dist = similarityMeasure(trainData[i], target);
        distances.push_back({dist, i});
    }

    // Trier les distances en ordre croissant de distance (les plus proches en premier)
    sort(distances.begin(), distances.end(), compareDistances);

    // Extraire les indices des k voisins les plus proches
    vector<int> nearestNeighbours;
    for (int i = 0; i < getK(); ++i)
    {
        if (i < distances.size())  // Vérifier si on a suffisamment de voisins
        {
            nearestNeighbours.push_back(distances[i].second);
        }
    }

    return nearestNeighbours;
}

template <typename T>
int KNN<T>::getK() const
{
    return k;
}

#endif
