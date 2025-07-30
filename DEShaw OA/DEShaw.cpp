#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, unordered_map<string, bool>& memo) 
{
    if (s == "") 
        return true;
    
        if (memo.find(s) != memo.end()) return memo[s];

    if (s.length() >= 2 && s[0] == s[s.length() - 1]) {
        string inner = s.substr(1, s.length() - 2);
        if (isValid(inner, memo)) {
            memo[s] = true;
            return true;
        }
    }

    for (int i = 1; i < s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (isValid(left, memo) && isValid(right, memo)) {
            memo[s] = true;
            return true;
        }
    }

    memo[s] = false;
    return false;
}

vector<int> validatePasswords(vector<string> passwords) {
    vector<int> result;
    unordered_map<string, bool> memo;

    for (int i = 0; i < passwords.size(); i++) {
        if (isValid(passwords[i], memo)) {
            result.push_back(1);
        } else {
            result.push_back(0);
        }
    }

    return result;
}

int main() {
    vector<string> passwords = {"", "a", "aa", "aba", "abba", "abca", "aaaa", "aabb"};
    vector<int> result = validatePasswords(passwords);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
