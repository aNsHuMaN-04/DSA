#include<bits/stdc++.h>
using namespace std;

// Using int 

 int strStr(string haystack, string needle) {
    
    int pos = haystack.find(needle);    
    
    if (pos != -1)
        return pos;
    else
        return -1;
    }

// Using size_t

int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if (pos != string :: npos)
            return pos;
        else
            return -1;
    }

// Without Using Function

int strStr(string haystack, string needle) {
        return findSub(haystack, needle);
    }

    int findSub(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0)
            return 0;

        for (int i = 0; i <= h - n; i++) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == n)
                return i;
        }

        return -1;
    }