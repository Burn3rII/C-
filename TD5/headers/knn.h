/* Bibliothèques internes-----------------------------------------------------*/
#include "tsdata.h"

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

/**
 * @brief Calcule la distance euclidienne entre deux séries temporelles.
 *
 * La distance euclidienne suppose un alignement temporel parfait entre
 * les séries.
 *
 * @param x Première série temporelle.
 * @param y Deuxième série temporelle.
 * @return Distance euclidienne entre les deux séries.
 */
double euclidean_distance(const vector<double>& x, const vector<double>& y)
{
    double distance = 0.0;
    for (size_t i = 0; i < x.size(); i++) {
        distance += pow(x[i] - y[i], 2);
    }
    return sqrt(distance);
}

/**
 * @brief Calcule la distance DTW (Dynamic Time Warping) entre deux séries temporelles.
 *
 * La distance DTW est une mesure de similarité spécifique aux séries temporelles,
 * prenant en compte des décalages temporels entre les séries.
 *
 * @param x Première série temporelle.
 * @param y Deuxième série temporelle.
 * @return Distance DTW entre les deux séries.
 */
double dtw_distance(const vector<double>& x, const vector<double>& y)
{
    int Lx = x.size();
    int Ly = y.size();
    vector<vector<double>> D(Lx + 1, vector<double>(Ly + 1, numeric_limits<double>::infinity()));

    D[0][0] = 0;

    for (int i = 1; i <= Lx; i++) {
        for (int j = 1; j <= Ly; j++) {
            double cost = pow(x[i - 1] - y[j - 1], 2);
            D[i][j] = cost + min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
        }
    }

    return sqrt(D[Lx][Ly]);
}

/**
 * @brief Calcule la distance EDR (Edit Distance on Real sequences) entre deux séries temporelles.
 *
 * La distance EDR utilise une tolérance pour ignorer les petites différences entre
 * les points alignés des deux séries.
 *
 * @param x Première série temporelle.
 * @param y Deuxième série temporelle.
 * @param epsilon Tolérance pour l'alignement (par défaut 0.5).
 * @return Distance EDR normalisée entre les deux séries (valeur entre 0 et 1).
 */
double edr_distance(const vector<double>& x, const vector<double>& y,
                    double epsilon = 0.5)
{
    int Lx = x.size();
    int Ly = y.size();
    vector<vector<int>> D(Lx + 1, vector<int>(Ly + 1, 0));

    for (int i = 1; i <= Lx; i++) {
        D[i][0] = i;
    }
    for (int j = 1; j <= Ly; j++) {
        D[0][j] = j;
    }

    for (int i = 1; i <= Lx; i++) {
        for (int j = 1; j <= Ly; j++) {
            if (fabs(x[i - 1] - y[j - 1]) < epsilon) {
                D[i][j] = D[i - 1][j - 1];
            } else {
                D[i][j] = 1 + min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
            }
        }
    }

    return static_cast<double>(D[Lx][Ly]) / max(Lx, Ly); // Normalisé entre 0 et 1
}

/**
 * @class KNN
 * @brief Implémentation de l'algorithme des k plus proches voisins (KNN).
 *
 * Cette classe permet de classifier des séries temporelles en utilisant
 * différentes mesures de similarité (distance euclidienne, DTW, ou EDR).
 */
class KNN
{
private:
    /**
     * @brief Nombre de voisins pris en compte pour la classification.
     */
    int k;

        /**
     * @brief Mesure de similarité utilisée pour comparer les séries temporelles.
     *
     * Les valeurs possibles sont :
     * - "euclidean" : distance euclidienne.
     * - "dtw" : Dynamic Time Warping.
     * - "edr" : Edit Distance on Real sequences.
     */
    string similarity_measure;

    /**
     * @brief Calcule la distance entre deux séries temporelles en fonction
     * de la mesure choisie.
     *
     * @param a Première série temporelle.
     * @param b Deuxième série temporelle.
     * @return Distance entre les deux séries temporelles.
     */
    double calculate_distance(const vector<double>& a, const vector<double>& b) const {
        if (similarity_measure == "euclidean") {
            return euclidean_distance(a, b);
        } else if (similarity_measure == "dtw") {
            return dtw_distance(a, b);
        } else if (similarity_measure == "edr") {
            return edr_distance(a, b);
        }
        return numeric_limits<double>::infinity();
    }

public:
    // Constructeur

        /**
     * @brief Constructeur paramétré.
     *
     * Initialise un classifieur KNN avec un nombre de voisins et une mesure
     * de similarité spécifiques.
     *
     * @param k_value Nombre de voisins à considérer.
     * @param measure Mesure de similarité utilisée ("euclidean", "dtw", ou "edr").
     */
    KNN(int k_value, const string& measure) : k(k_value), similarity_measure(measure) {}

    /**
     * @brief Évalue l'accuracy du classifieur sur un jeu de test.
     *
     * Calcule le pourcentage de séries temporelles correctement classifiées
     * par rapport à leurs labels réels.
     *
     * @param trainData Jeu d'entraînement contenant les séries et leurs labels.
     * @param testData Jeu de test contenant les séries à classifier.
     * @param ground_truth Labels réels des séries dans le jeu de test.
     * @return Accuracy du classifieur (valeur entre 0 et 1).
     */
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth) const {
        int correct_predictions = 0;

        for (size_t i = 0; i < testData.getData().size(); ++i) {
            const auto& test_series = testData.getData()[i];
            vector<pair<double, int>> distances;

            // Calculer la distance entre la série de test et chaque série d'entraînement
            for (size_t j = 0; j < trainData.getData().size(); ++j) {
                double dist = calculate_distance(test_series, trainData.getData()[j]);
                distances.push_back({dist, trainData.getLabels()[j]});
            }

            // Trier les distances pour trouver les k plus proches voisins
            sort(distances.begin(), distances.end());
            unordered_map<int, int> label_counts;

            for (int n = 0; n < k; ++n) {
                label_counts[distances[n].second]++;
            }

            // Trouver le label majoritaire parmi les k voisins
            int predicted_label = max_element(label_counts.begin(), 
            label_counts.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->first;

            // Vérifier si la prédiction est correcte
            if (predicted_label == ground_truth[i]) {
                correct_predictions++;
            }
        }

        return static_cast<double>(correct_predictions) / ground_truth.size();
    }
};
