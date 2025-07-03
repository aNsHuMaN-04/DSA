#include<bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) 
        return "";

    string ans = "";
    string first = strs[0];

    for (int i = 0; i < first.size(); i++) {
        char c = first[i];  

        for (int j = 1; j < strs.size(); j++) {
           
            if (i >= strs[j].size() || strs[j][i] != c)
                return ans;
        }

        ans += c;  
    }

    return ans;
}
