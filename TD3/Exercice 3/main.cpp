/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

/**
 * @brief Teste si la chaine de caractèreres passée en arguments en un palindrome.
 * 
 * @param input La chaine de caractères à tester
 * @return true si la chaine est un palindrome, false sinon
 * 
 */
bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;

    for (char c : input) {
        if (isalnum(c)) {
            char lowerC = tolower(c);
            q.push(lowerC);
            s.push(lowerC);
        }
    }

    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }
        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome? " 
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome? " 
         << isPalindrome("hello") << endl;

    return 0;
}
