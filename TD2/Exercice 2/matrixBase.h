#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <vector>

using namespace std;

/**
 * @class MatrixBase
 * @brief Classe de base générique pour représenter une matrice de taille `rows x cols`.
 * 
 * @tparam T Type des éléments de la matrice.
 */
template <typename T>
class MatrixBase
{
protected:
    /**
     * @brief Données de la matrice, stockées sous forme de tableau 2D.
     */
    vector<vector<T>> data;

    /**
     * @brief Nombre de lignes de la matrice.
     */
    size_t rows;

    /**
     * @brief Nombre de colonnes de la matrice.
     */
    size_t cols;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut, initialisant une matrice 1x1 avec des valeurs par défaut.
     */
    MatrixBase();

        /**
     * @brief Constructeur avec dimensions personnalisées.
     * 
     * @param _rows Nombre de lignes.
     * @param _cols Nombre de colonnes.
     */
    MatrixBase(size_t, size_t);

        /**
     * @brief Constructeur par copie.
     * 
     * @param other Matrice à copier.
     */
    MatrixBase(const MatrixBase<T>& other);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel pour permettre la destruction correcte des objets dérivés.
     */
    virtual ~MatrixBase() = default;

    /* Méthodes */

    /**
     * @brief Récupère le nombre de lignes de la matrice.
     * 
     * @return Nombre de lignes.
     */
    size_t getRows();

    /**
     * @brief Récupère le nombre de colonnes de la matrice.
     * 
     * @return Nombre de colonnes.
     */
    size_t getCols();

    /**
     * @brief Récupère un élément de la matrice.
     * 
     * @param row Numéro de la ligne.
     * @param col Numéro de la colonne.
     * @return Élément à la position donnée.
     */
    T getElement(size_t, size_t) const;

    /**
     * @brief Ajoute ou modifie un élément à la position donnée dans la matrice.
     * 
     * @param row Numéro de la ligne.
     * @param col Numéro de la colonne.
     * @param x Valeur de l'élément à ajouter.
     */
    void addElement(size_t, size_t, T);

    /**
     * @brief Affiche la matrice dans la console.
     */
    void display() const;
};

/* Constructeurs--------------------------------------------------------------*/

template <typename T>
MatrixBase<T>::MatrixBase():
data(1, vector<T>(1)), rows(1), cols(1)
{
    
}

template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols):
data(_rows, vector<T>(_cols)), rows(_rows), cols(_cols)
{

}

template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase<T>& other) : 
data(other.data), rows(other.rows), cols(other.cols)
{

}

/* Méthodes-------------------------------------------------------------------*/

template <typename T>
size_t MatrixBase<T>::getRows()
{
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols()
{
    return cols;
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const
{
    return data[row][col];
}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T x)
{
    data[row][col] = x;
}

template <typename T>
void MatrixBase<T>::display() const
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif