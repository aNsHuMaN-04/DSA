#include<bits/stdc++.h>
using namespace std;

   
    void solve(string& temp, int open, int close, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }

        if (open > 0) {
            temp.push_back('(');
            solve(temp, open - 1, close, ans);
            temp.pop_back();
        }

        if (close > open) {
            temp.push_back(')');
            solve(temp, open, close - 1, ans);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(temp, n, n, ans);
        return ans;
    }


