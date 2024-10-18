/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "linearSearch.h"
#include "jumpSearch.h"
#include "binarySearch.h"

using namespace std;

int main()
{
    vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "Data : ";
    for (int i = 0; i < data.size(); i++)
        cout << data[i] << " ";
    cout << endl;

    LinearSearch linearSearch;
    JumpSearch jumpSearch;
    BinarySearch binarySearch;

    int target = 15;

    // Recherche linéaire
    int result = linearSearch.search(data, target);
    printf("Linear search : ");
    linearSearch.displaySearchResults(cout, result, target);

    // Recherche par saut
    result = jumpSearch.search(data, target);
    printf("Jump search : ");
    jumpSearch.displaySearchResults(cout, result, target);

    // Recherche binaire
    result = binarySearch.search(data, target);
    printf("Binary search : ");
    binarySearch.displaySearchResults(cout, result, target);

    return 0;
}