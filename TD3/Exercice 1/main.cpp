/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * @brief Compte le nombre d'occurences pour chaque élément du tableau passé en 
 * paramètres et affiche ce nombre. Algorithme brut, de complexité O(n²).
 * 
 * @param numbers Tableau d'entiers contenant les nombres à compter.
 */
void countFrequencyBruteForce(const vector<int>& numbers)
{
    vector<int> done;

    for (int i=0; i<numbers.size(); i++) {
        bool seen = false;

        for (int j=0; j<done.size(); j++) {
            if (done[j]==numbers[i]) seen = true; // Élément déjà vu
        }

        if (seen) continue;

        int target = numbers[i];
        done.push_back(target);
        int compteur = 1;

        for (int j=i+1; j<numbers.size(); j++) {
            if (numbers[j]==numbers[i]) compteur++;
        }

        cout << "Nombre d'occurences pour le numéro " << target << " : " << compteur << endl;
    }
}

/**
 * @brief Compte le nombre d'occurences pour chaque élément du tableau passé en 
 * paramètres et renvoie la map contenant le nombre d'occurences associé à 
 * chaque nombre. Algorithme optimal, de complexité O(n).
 * 
 * @param numbers Tableau d'entiers contenant les nombres à compter.
 * @return La map contenant les nombres du vector "numbers" et le nombre 
 * d'occurences associé
 */
map<int, int> countFrequencyOptimal(const vector <int>& numbers)
{
    map<int, int> frequencyMapOptimal;

    for (int i=0; i<numbers.size(); i++) {
        frequencyMapOptimal[numbers[i]]++;
    }

    return frequencyMapOptimal;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force) :" << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal) :" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }

    return 0 ;
}