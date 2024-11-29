#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

using namespace std;

/**
 * @class TimeSeriesDataset
 * @brief Représente un ensemble de séries temporelles et leurs labels associés.
 *
 * Cette classe permet de gérer des séries temporelles avec des options telles
 * que la normalisation Z, et offre des méthodes pour calculer des distances
 * entre séries temporelles.
 */
class TimeSeriesDataset
{
private:
    /**
     * @brief Indique si les séries doivent être normalisées avec Z-Normalization.
     */
    bool znormalize;

    /**
     * @brief Indique si le dataset est un jeu d'entraînement ou de test.
     */
    bool isTrain;

    /**
     * @brief Données contenant les séries temporelles.
     */
    vector<vector<double>> data;

    /**
     * @brief Labels associés aux séries temporelles.
     */
    vector<int> labels;

    /**
     * @brief Longueur maximale parmi toutes les séries du dataset.
     */
    int maxLength;

    /**
     * @brief Nombre total de séries dans le dataset.
     */
    int numberOfSamples;

    /**
     * @brief Applique la normalisation Z à une série temporelle.
     *
     * @param series Série temporelle à normaliser.
     */
    void applyZNormalization(vector<double>& series);

public:
    /* Constructeurs */

    /**
     * @brief Constructeur de dataset.
     *
     * Initialise un jeu de données avec ou sans normalisation Z.
     *
     * @param znorm Indique si la normalisation Z est activée.
     * @param is_train Indique si le dataset est un jeu d'entraînement.
     */
    TimeSeriesDataset(bool znorm = false, bool is_train = true);

    /* Méthodes */

    /**
     * @brief Récupère les données des séries temporelles.
     *
     * @return Données sous forme de vecteur de vecteurs.
     */
    const vector<vector<double>>& getData() const;

    /**
     * @brief Récupère les labels des séries temporelles.
     *
     * @return Labels sous forme de vecteur d'entiers.
     */
    const vector<int>& getLabels() const;

    /**
     * @brief Ajoute une série temporelle au dataset.
     *
     * @param series Série temporelle à ajouter.
     */
    void addTimeSeries(const vector<double>& series);

    /**
     * @brief Ajoute une série temporelle avec un label.
     *
     * @param series Série temporelle à ajouter.
     * @param label Label associé à la série.
     */
    void addTimeSeries(const vector<double>& series, int label);

    /**
     * @brief Calcule la distance euclidienne entre deux séries temporelles.
     *
     * @param x Première série temporelle.
     * @param y Deuxième série temporelle.
     * @return Distance euclidienne entre les deux séries.
     */
    double euclidean_distance(const vector<double>& x, const vector<double>& y);

    /**
     * @brief Calcule la distance DTW entre deux séries temporelles.
     *
     * @param x Première série temporelle.
     * @param y Deuxième série temporelle.
     * @return Distance DTW entre les deux séries.
     */
    double dtw_distance(const vector<double>& x, const vector<double>& y);

    /**
     * @brief Calcule la distance EDR entre deux séries temporelles.
     *
     * @param x Première série temporelle.
     * @param y Deuxième série temporelle.
     * @param epsilon Tolérance pour l'alignement.
     * @return Distance EDR entre les deux séries.
     */
    double edr_distance(const vector<double>& x, const vector<double>& y,
                        double epsilon = 0.5);
};

#endif
