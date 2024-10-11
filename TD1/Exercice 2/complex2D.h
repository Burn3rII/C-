#ifndef COMPLEX_H
#define COMPLEX_H

/* Bibliothèques externes-----------------------------------------------------*/
#include <cmath>

/**
 * @class Complex2D
 * @brief Représente un nombre complexe en deux dimensions (partie réelle et partie imaginaire).
 */
class Complex2D
{
private:
    /**
     * @brief Partie réelle du nombre complexe.
     */
    double re;

    /**
     * @brief Partie imaginaire du nombre complexe.
     */
    double im;

public:
    /* Constructeurs */

    /**
     * @brief Constructeur par défaut de Complex2D.
     * Initialise un nombre complexe (0, 0).
     */
    Complex2D();

    /**
     * @brief Constructeur initialisant les parties réelle et imaginaire avec la même valeur.
     * 
     * @param val Valeur pour les parties réelle et imaginaire.
     */
    Complex2D(double val);

    /**
     * @brief Constructeur avec parties réelle et imaginaire.
     * Initialise un nombre complexe avec des valeurs spécifiques.
     * 
     * @param re Partie réelle.
     * @param im Partie imaginaire (par défaut à 0).
     */
    Complex2D(double re, double im = 0);

    /**
     * @brief Constructeur de copie.
     * Crée un nouveau Complex2D en copiant un autre.
     * 
     * @param other Objet Complex2D à copier.
     */
    Complex2D(const Complex2D& other);

    /* Destructeurs */

    /**
     * @brief Destructeur virtuel de Complex2D.
     * Permet à la classe d'être détruite proprement.
     */
    virtual ~Complex2D() = default;

    /* Opérateurs */

    /**
     * @brief Addition de deux nombres complexes.
     * 
     * @param complx1 Premier nombre complexe.
     * @param complx2 Deuxième nombre complexe.
     * @return Résultat de l'addition.
     */
    friend Complex2D operator +(const Complex2D& complx1, const Complex2D& complx2);

    /**
     * @brief Soustraction de deux nombres complexes.
     * 
     * @param complx1 Premier nombre complexe.
     * @param complx2 Deuxième nombre complexe.
     * @return Résultat de la soustraction.
     */
    friend Complex2D operator -(const Complex2D& complx1, const Complex2D& complx2);

    /**
     * @brief Renvoie l'opposé d'un nombre complexe.
     * 
     * @param complx Nombre complexe à opposer.
     * @return Opposé du nombre complexe.
     */
    friend Complex2D operator -(const Complex2D& complx); // Opposé

    /**
     * @brief Multiplication de deux nombres complexes.
     * 
     * @param complx1 Premier nombre complexe.
     * @param complx2 Deuxième nombre complexe.
     * @return Résultat de la multiplication.
     */
    friend Complex2D operator *(const Complex2D& complx1, const Complex2D& complx2);

    /**
     * @brief Multiplication d'un nombre complexe par un scalaire.
     * 
     * @tparam T Type du scalaire.
     * @param complx Nombre complexe.
     * @param scalar Scalaire.
     * @return Résultat de la multiplication.
     */
    template <typename T>
    friend Complex2D operator *(const Complex2D& complx, const T scalar)
    {
        return Complex2D(scalar * complx.re, scalar * complx.im);
    }

    /**
     * @brief Multiplication d'un scalaire par un nombre complexe.
     * 
     * @tparam T Type du scalaire.
     * @param scalar Scalaire.
     * @param complx Nombre complexe.
     * @return Résultat de la multiplication.
     */
    template <typename T>
    friend Complex2D operator *(const T scalar, const Complex2D& complx)
    {
        return complx * scalar;
    }

    /**
     * @brief Division de deux nombres complexes.
     * 
     * @param complx1 Dividende.
     * @param complx2 Diviseur.
     * @return Résultat de la division.
     */
    friend Complex2D operator /(const Complex2D& complx1, const Complex2D& complx2);
    
    /**
     * @brief Division d'un nombre complexe par un scalaire.
     * 
     * @tparam T Type du scalaire.
     * @param complx Nombre complexe.
     * @param scalar Scalaire.
     * @return Résultat de la division.
     */
    template <typename T>
    friend Complex2D operator /(const Complex2D& complx, const T scalar)
    {
        return Complex2D(complx.re / static_cast<double>(scalar), complx.im / static_cast<double>(scalar));
    }

    /**
     * @brief Division d'un scalaire par un nombre complexe.
     * 
     * @tparam T Type du scalaire.
     * @param scalar Scalaire.
     * @param complx Nombre complexe.
     * @return Résultat de la division.
     */
    template <typename T>
    friend Complex2D operator /(const T scalar, const Complex2D& complx)
    {
        double re = (scalar * complx.conjugate().getRe()) / pow(complx.module(), 2);
        double im = (scalar * complx.conjugate().getIm()) / pow(complx.module(), 2);
        return Complex2D(re, im);
    }

    /**
     * @brief Comparaison de deux nombres complexes (inférieur à).
     * 
     * @param complx1 Premier nombre complexe.
     * @param complx2 Deuxième nombre complexe.
     * @return true si complx1 < complx2, false sinon.
     */
    friend bool operator <(const Complex2D& complx1, const Complex2D& complx2);

    /**
     * @brief Comparaison de deux nombres complexes (supérieur à).
     * 
     * @param complx1 Premier nombre complexe.
     * @param complx2 Deuxième nombre complexe.
     * @return true si complx1 > complx2, false sinon.
     */
    friend bool operator >(const Complex2D& complx1, const Complex2D& complx2);

    /* Méthodes */

    /**
     * @brief Obtient la partie réelle du nombre complexe.
     * 
     * @return La partie réelle.
     */
    double getRe() const;

    /**
     * @brief Obtient la partie imaginaire du nombre complexe.
     * 
     * @return La partie imaginaire.
     */
    double getIm() const;

    /**
     * @brief Définit la partie réelle du nombre complexe.
     * 
     * @param val Nouvelle valeur pour la partie réelle.
     */
    void setRe(double val);

    /**
     * @brief Définit la partie imaginaire du nombre complexe.
     * 
     * @param val Nouvelle valeur pour la partie imaginaire.
     */
    void setIm(double val);

    /**
     * @brief Renvoie le conjugué du nombre complexe.
     * 
     * @return Nombre complexe conjugué.
     */
    Complex2D conjugate() const;

    /**
     * @brief Calcule le module (norme) du nombre complexe.
     * 
     * @return Le module du nombre complexe.
     */
    double module() const;
};

#endif
