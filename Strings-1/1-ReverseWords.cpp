
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{
    s = ' ' + s;  // Add leading space to catch the leftmost word
    string word = "", ans = "";

    for (int i = s.length() - 1; i >= 0; i--) 
        {      
        if (s[i] != ' ')
            word = s[i] + word;
            
         else 
        {
            if (!word.empty()) {
                if (!ans.empty()) 
                    ans += " ";
                
                ans += word;
                word = "";
            }
        }
    }

    return ans;


        
    }