// After Removing the Duplicates , the result should be smallest order that ezists in the string

#include<bits/stdc++.h>
using namespace std;

    string removeDuplicateLetters(string s) 
    {
        unordered_map<char, int> lastIndex;
        unordered_map<char, bool> seen;
        stack<char> st;

        // Store the last index of each character
        for (int i = 0; i < s.length(); ++i)
            lastIndex[s[i]] = i;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // If character already in result, skip it
            if (seen[c]) continue;

            // Remove characters from stack if:
            // 1. Stack is not empty
            // 2. Top character is greater than current
            // 3. Top character occurs later again
            while (!st.empty() && c < st.top() && lastIndex[st.top()] > i) {
                seen[st.top()] = false;
                st.pop();
            }

            st.push(c);
            seen[c] = true;
        }

        // Build result from stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
