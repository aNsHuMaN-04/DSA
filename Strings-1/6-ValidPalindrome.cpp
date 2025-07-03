#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            // Move i to next alphanumeric
            while (i < j && !isalnum(s[i])) i++;
            // Move j to previous alphanumeric
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }