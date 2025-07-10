#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{        
    if (digits.empty())
         return {};

        vector<string> ans;
        string curr = "";

        vector<string> mapping = { "", "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" } ;

        solve(0, digits, mapping, curr, ans);
        return ans;
    }

    void solve(int index, string& digits, vector<string>& mapping, string& curr, vector<string>& ans) 
        {
          if (index == digits.size()) 
             {
                ans.push_back(curr);
                return;
             }

        string letters = mapping[digits[index] - '0'];
            
        for (int i = 0; i < letters.size(); i++) 
        {
            curr.push_back(letters[i]);
            solve(index + 1, digits, mapping, curr, ans);
            curr.pop_back();
        }
    
    }