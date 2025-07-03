#include<bits/stdc++.h>
using namespace std;

// Brute Force : O(N^3)

bool isPalindrome(string s, int left, int right) {
    while (left <= right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

string longestPalindrome1(string s) {
    string ans = "";
    int maxi = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = s.length() - 1; j >= i; j--) {
            if (isPalindrome(s, i, j)) {
                if (j - i + 1 > maxi) {
                    maxi = j - i + 1;
                    ans = s.substr(i, maxi);
                }
            }
        }
    }
    return ans;
}

// Optimized O(N^2) : Centered around indices approach

string longestPalindrome2(string s) {
    int n = s.size();
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindrome (center at i)
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }

        // Even length palindrome (center between i and i+1)
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, maxLen);
}