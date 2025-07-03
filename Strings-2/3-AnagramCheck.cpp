#include<bits/stdc++.h>
using namespace std;


// Using Map Hashing

 bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq;

       for (int i = 0; i < s.size(); i++) 
            freq[s[i]]++;
    
        for (int i = 0; i < t.size(); i++) 
            freq[t[i]]--;
    
        for (auto p : freq) {
            if (p.second != 0)
                return false;
        }

        return true;
    }

    // Using Array Hashing

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};
        int i;

        for (i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }


    // Using Sorting

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }