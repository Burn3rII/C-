/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "matrixNumerical.h"

using namespace std;

int main() {
    // Test des constructeurs et de l'affichage des matrices
    cout << "Test des constructeurs avec des matrices 3x3" << endl;
    MatrixNumerical<int> m1(3, 3);
    MatrixNumerical<int> m2(3, 3);

    m1.addElement(0, 0, 1);
    m1.addElement(0, 1, 2);
    m1.addElement(0, 2, 3);
    m1.addElement(1, 0, 4);
    m1.addElement(1, 1, 5);
    m1.addElement(1, 2, 6);
    m1.addElement(2, 0, 7);
    m1.addElement(2, 1, 8);
    m1.addElement(2, 2, 9);

    m2.addElement(0, 0, 9);
    m2.addElement(0, 1, 8);
    m2.addElement(0, 2, 7);
    m2.addElement(1, 0, 6);
    m2.addElement(1, 1, 5);
    m2.addElement(1, 2, 4);
    m2.addElement(2, 0, 3);
    m2.addElement(2, 1, 2);
    m2.addElement(2, 2, 1);

    cout << "Matrice m1:" << endl;
    m1.display();
    cout << "Matrice m2:" << endl;
    m2.display();

    // Test de l'addition
    cout << "\nTest de l'addition (m1 + m2):" << endl;
    try {
        MatrixNumerical<int> sum = m1 + m2;
        sum.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Test de la soustraction
    cout << "\nTest de la soustraction (m1 - m2):" << endl;
    try {
        MatrixNumerical<int> diff = m1 - m2;
        diff.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Test de la multiplication
    cout << "\nTest de la multiplication (m1 * m2):" << endl;
    try {
        MatrixNumerical<int> product = m1 * m2;
        product.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Test de l'inversion (erreur attendue pour une matrice singulière)
    cout << "\nTest de l'inversion de m1 (matrice singulière):" << endl;
    try {
        MatrixNumerical<int> inverse = m1.getInverse();
        inverse.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Création d'une matrice 3x3 inversible
    cout << "\nTest de l'inversion d'une matrice inversible m3:" << endl;
    MatrixNumerical<double> m3(3, 3);
    m3.addElement(0, 0, 2);
    m3.addElement(0, 1, -1);
    m3.addElement(0, 2, 0);
    m3.addElement(1, 0, -1);
    m3.addElement(1, 1, 2);
    m3.addElement(1, 2, -1);
    m3.addElement(2, 0, 0);
    m3.addElement(2, 1, -1);
    m3.addElement(2, 2, 2);

    cout << "Matrice inversible m3:" << endl;
    m3.display();

    try {
        MatrixNumerical<double> inverse = m3.getInverse();
        cout << "Matrice inverse de m3:" << endl;
        inverse.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Test de la matrice identité
    cout << "\nTest de la matrice identité 3x3:" << endl;
    MatrixNumerical<int> identity = MatrixNumerical<int>::getIdentity(3);
    identity.display();

    // Test de la division (multiplication par l'inverse)
    cout << "\nTest de la division (m3 / m3):" << endl;
    try {
        MatrixNumerical<double> div = m3 / m3;
        div.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    // Test des erreurs pour matrices de dimensions différentes
    cout << "\nTest d'une addition avec des matrices de dimensions différentes:" << endl;
    MatrixNumerical<int> m4(4, 4);
    try {
        MatrixNumerical<int> sumError = m1 + m4;
        sumError.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
