/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Cherche une somme de deux nombre contenus dans le tableau nums étant 
 * égale à la valeur target. Algorithme brut, de complexité O(n²).
 * 
 * @param nums Tableau d'entiers contenant les nombres à associés.
 * @param target Nombre auquel doit être égale la somme.
 * @return Un tableau des 2 indices de nums dont les somme des éléments est 
 * égale à target
 * 
 */
vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    vector<int> results;

    for (int i=0; i<nums.size(); i++) {
        for (int j=i+1; j<nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                results.push_back(i);
                results.push_back(j);
                return results;
            }
        }
    }

    return results;
}

/**
 * @brief Cherche une somme de deux nombre contenus dans le tableau nums étant égale à la valeur target. Algorithme optimal, de complexité O(n).
 * 
 * @param nums Tableau d'entiers contenant les nombres à associés.
 * @param target Nombre auquel doit être égale la somme.
 * @return Un tableau des 2 indices de nums dont les somme des éléments est 
 * égale à target
 * 
 */
vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i=0; i<nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    if (indicesBruteForce.empty()) {
        cout << "Solution not found" << endl;
    } else {
        cout << "Brute Force Solution: ["
             << indicesBruteForce[0] << ", " << indicesBruteForce[1] << "]" 
             << endl;
    }

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    if (indicesOptimal.empty()) {
        cout << "Solution not found" << endl;
    } else {
        cout << "Optimal Solution: ["
             << indicesOptimal[0] << ", " << indicesOptimal[1] << "]" << endl;
    }

    return 0;
}
