/* Bibliothèques externes-----------------------------------------------------*/
#include <numeric>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

/* Bibliothèques internes-----------------------------------------------------*/
#include "../headers/tsdata.h"

using namespace std;

/* Constructeurs--------------------------------------------------------------*/

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool is_train):
znormalize(znorm), isTrain(is_train), maxLength(0), numberOfSamples(0)
{

}

/* Méthodes-------------------------------------------------------------------*/

void TimeSeriesDataset::addTimeSeries(const vector<double>& series) {
    vector<double> processedSeries = series;

    // Appliquer la normalisation Z si l'option est activée
    if (znormalize) {
        applyZNormalization(processedSeries);
    }

    // Ajouter la série traitée aux données
    data.push_back(processedSeries);

    // Mettre à jour le nombre d'échantillons et la longueur maximale
    numberOfSamples++;
    if (processedSeries.size() > maxLength) {
        maxLength = processedSeries.size();
    }
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    addTimeSeries(series); // Appeler la version sans label
    labels.push_back(label); // Ajouter le label
}

double TimeSeriesDataset::euclidean_distance(const vector<double>& x, 
                                             const vector<double>& y)
{
    double distance = 0.0;
    for (size_t i = 0; i < x.size(); i++)
    {
        distance += pow(x[i] - y[i], 2);
    }
    return sqrt(distance);
}

double TimeSeriesDataset::dtw_distance(const vector<double>& x, 
                                       const vector<double>& y)
{
    int Lx = x.size();
    int Ly = y.size();
    vector<vector<double>> D(Lx + 1, vector<double>(Ly + 1, numeric_limits<double>::infinity()));

    D[0][0] = 0;

    for (int i = 1; i <= Lx; i++)
    {
        for (int j = 1; j <= Ly; j++)
        {
            double cost = pow(x[i - 1] - y[j - 1], 2);
            D[i][j] = cost + min({D[i-1][j], D[i][j-1], D[i-1][j-1]});
        }
    }

    return sqrt(D[Lx][Ly]);
}

double TimeSeriesDataset::edr_distance(const vector<double>& x, 
                                       const vector<double>& y,
                                       double epsilon)
{
    int Lx = x.size();
    int Ly = y.size();
    vector<vector<int>> D(Lx + 1, vector<int>(Ly + 1, 0));

    for (int i = 1; i <= Lx; i++)
    {
        D[i][0] = i;
    }
    for (int j = 1; j <= Ly; j++)
    {
        D[0][j] = j;
    }

    for (int i = 1; i <= Lx; i++)
    {
        for (int j = 1; j <= Ly; j++)
        {
            if (fabs(x[i - 1] - y[j - 1]) < epsilon)
            {
                D[i][j] = D[i - 1][j - 1];
            }
            else
            {
                D[i][j] = 1 + min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
            }
        }
    }

    return static_cast<double>(D[Lx][Ly]) / max(Lx, Ly); // Normalisé entre 0 et 1
}

void TimeSeriesDataset::applyZNormalization(vector<double>& series)
{
    // Calcul de la moyenne
    double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();

    // Calcul de l'écart type
    double variance = 0.0;
    for (double value : series) {
        variance += (value - mean) * (value - mean);
    }
    double stddev = sqrt(variance / series.size());

    // Appliquer la normalisation Z si l'écart type est non nul
    if (stddev != 0) {
        for (double& value : series) {
            value = (value - mean) / stddev;
        }
    }
}

const vector<vector<double>>& TimeSeriesDataset::getData() const
{
    return data;
}

const vector<int>& TimeSeriesDataset::getLabels() const
{
    return labels;
}
