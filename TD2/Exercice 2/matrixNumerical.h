#ifndef MATRIX_NUMERICAL_H
#define MATRIX_NUMERICAL_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <stdexcept>

/* Bibliothèques internes-----------------------------------------------------*/
#include "matrixBase.h"

using namespace std;

/**
 * @class MatrixNumerical
 * @brief Classe dérivée de `MatrixBase` pour effectuer des opérations numériques
 * sur les matrices (addition, soustraction, multiplication, inversion).
 * 
 * @tparam T Type numérique des éléments de la matrice (int, float, double, etc.).
 */
template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut. 
     * Initialise une matrice 1x1 avec une valeur par défaut.
     */
    MatrixNumerical();

    /**
     * @brief Constructeur avec dimensions personnalisées.
     * 
     * @param _rows Nombre de lignes.
     * @param _cols Nombre de colonnes.
     */
    MatrixNumerical(size_t, size_t);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel pour permettre la destruction correcte des objets dérivés.
     */
    virtual ~MatrixNumerical() = default;

    /* Opérateurs */

    /**
     * @brief Surcharge de l'opérateur d'addition pour additionner deux matrices de même dimension.
     * 
     * @param other Matrice à ajouter.
     * @return Nouvelle matrice résultant de l'addition.
     * @throws std::invalid_argument Si les dimensions des matrices ne correspondent pas.
     */
    MatrixNumerical<T> operator +(const MatrixNumerical<T>& mtx2) const;
    
    /**
     * @brief Surcharge de l'opérateur de soustraction pour soustraire deux matrices de même dimension.
     * 
     * @param other Matrice à soustraire.
     * @return Nouvelle matrice résultant de la soustraction.
     * @throws std::invalid_argument Si les dimensions des matrices ne correspondent pas.
     */
    MatrixNumerical<T> operator -(const MatrixNumerical<T>& mtx2) const;
    
    /**
     * @brief Surcharge de l'opérateur de multiplication pour multiplier deux matrices.
     * 
     * @param other Matrice à multiplier.
     * @return Nouvelle matrice résultant de la multiplication.
     * @throws std::invalid_argument Si les dimensions des matrices ne permettent pas la multiplication.
     */
    MatrixNumerical<T> operator *(const MatrixNumerical<T>& mtx2) const;
    
    /**
     * @brief Surcharge de l'opérateur de division pour diviser deux matrices.
     * La division est définie comme la multiplication par l'inverse.
     * 
     * @param other Matrice à diviser.
     * @return Nouvelle matrice résultant de la division.
     * @throws std::invalid_argument Si les dimensions des matrices ne permettent pas la division.
     */
    MatrixNumerical<T> operator /(const MatrixNumerical<T>& mtx2) const;

    /* Méthodes */

    /**
     * @brief Calcule le déterminant de la matrice actuelle.
     * 
     * Utilise la méthode des cofacteurs pour les matrices de taille supérieure à 2x2.
     * 
     * @return Le déterminant de la matrice.
     * @throws std::invalid_argument Si la matrice n'est pas carrée.
     */
    T getDeterminant() const;

    /**
     * @brief Calcule l'inverse de la matrice actuelle.
     * 
     * @return Nouvelle matrice représentant l'inverse de la matrice actuelle.
     * @throws std::invalid_argument Si la matrice n'est pas carrée ou si elle est singulière (non inversible).
     */
    MatrixNumerical<T> getInverse() const;

    /**
     * @brief Génère une matrice identité de taille n x n.
     * 
     * @param n Taille de la matrice identité.
     * @return Matrice identité de taille n x n.
     */
    static MatrixNumerical<T> getIdentity(size_t size);

private:
    /* Méthodes */

    /**
     * @brief Calcule le cofacteur d'un élément de la matrice donnée.
     * 
     * Remplit la matrice `temp` en excluant la ligne `p` et la colonne `q`.
     * 
     * @param mat Matrice source.
     * @param temp Matrice cofacteur résultante.
     * @param p Indice de la ligne à exclure.
     * @param q Indice de la colonne à exclure.
     * @param n Taille de la matrice source.
     */
    void getCoFactor(const MatrixNumerical<T>& mat, MatrixNumerical<T>& temp, int p, int q, int n) const;
};

/* Constructeurs--------------------------------------------------------------*/

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>()
{

}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols)
{

}

/* Opérateurs-----------------------------------------------------------------*/

/* + */ 

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator +(const MatrixNumerical<T>& mtx2) const
{
    if (this->rows != mtx2.rows || this->cols != mtx2.cols)
    {
        throw invalid_argument("Matrices must have the same dimensions for addition.");
    }

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->cols; ++j)
        {
            result.data[i][j] = this->data[i][j] + mtx2.data[i][j];
        }
    }
    return result;
}

/* - */

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator -(const MatrixNumerical<T>& mtx2) const
{
    if (this->rows != mtx2.rows || this->cols != mtx2.cols)
    {
        throw invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->cols; ++j)
        {
            result.data[i][j] = this->data[i][j] - mtx2.data[i][j];
        }
    }
    return result;
}

/* * */

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator *(const MatrixNumerical<T>& mtx2) const
{
    if (this->cols != mtx2.rows)
    {
        throw invalid_argument("Number of columns of the first matrix must equal the number of rows of the second matrix.");
    }

    MatrixNumerical<T> result(this->rows, mtx2.cols);
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < mtx2.cols; ++j)
        {
            result.data[i][j] = 0;
            for (size_t k = 0; k < this->cols; ++k)
            {
                result.data[i][j] += this->data[i][k] * mtx2.data[k][j];
            }
        }
    }
    return result;
}

/* / */

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator /(const MatrixNumerical<T>& mtx2) const
{
    return *this * mtx2.getInverse();
}

/* Méthodes-------------------------------------------------------------------*/

template <typename T>
T MatrixNumerical<T>::getDeterminant() const
{
    if (this->rows != this->cols)
    {
        throw invalid_argument("Determinant is only defined for square matrices.");
    }

    if (this->rows == 1)
    {
        return this->data[0][0];
    }

    if (this->rows == 2)
    {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }

    T det = 0;

    // Matrice temporaire de taille (n-1) x (n-1)
    MatrixNumerical<T> temp(this->rows - 1, this->cols - 1);

    int sign = 1;
    for (size_t f = 0; f < this->cols; f++)
    {
        // Remplir la matrice cofacteur pour chaque colonne de la première ligne
        getCoFactor(*this, temp, 0, f, this->rows);
        det += sign * this->data[0][f] * temp.getDeterminant();
        sign = -sign;
    }

    return det;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const
{
    T det = getDeterminant();
    if (det == 0)
    {
        throw runtime_error("Singular matrix, can't find its inverse.");
    }

    MatrixNumerical<T> adj(this->rows, this->cols);
    MatrixNumerical<T> inverse(this->rows, this->cols);

    if (this->rows == 1)
    {
        inverse.data[0][0] = 1 / this->data[0][0];
        return inverse;
    }

    int sign = 1;
    MatrixNumerical<T> temp(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            getCoFactor(*this, temp, i, j, this->rows);

            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj.data[j][i] = sign * temp.getDeterminant();
        }
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            inverse.data[i][j] = adj.data[i][j] / det;
        }
    }

    return inverse;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size)
{
    MatrixNumerical<T> identity(size, size);
    for (size_t i = 0; i < size; ++i)
    {
        identity.data[i][i] = 1;
    }
    return identity;
}

template <typename T>
void MatrixNumerical<T>::getCoFactor(const MatrixNumerical<T>& mat, MatrixNumerical<T>& temp, int p, int q, int n) const
{
    int i = 0, j = 0;
    temp = MatrixNumerical<T>(n - 1, n - 1); // Réallocation de temp à chaque appel

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp.data[i][j++] = mat.data[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

#endif