#include<bits/stdc++.h>
using namespace std;

// Repeated String

int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Keep appending until length of repeated >= length of b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring
        if (repeated.find(b) != string::npos)
            return count;

        // One more repeat might be needed for overlap cases
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos)
            return count;

        // If still not found
        return -1;
    }