#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
        if (n == 1)
            return "1";

        string prev = countAndSay(n - 1);
        string curr = "";
        int i = 0;

        while (i < prev.size()) {
            char c = prev[i];
            int count = 0;

            // Count occurrences of prev[i]
            while (i < prev.size() && prev[i] == c) {
                count++;
                i++;
            }

            curr += to_string(count) + c;
        }

        return curr;
    }
