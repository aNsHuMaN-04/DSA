#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)    // for( char c : s)
         {
            char c = s[i];

            if(c == '(' || c == '{' || c == '[') 
                st.push(c);
            
            else 
            {
                if(st.empty()) 
                    return false;
                
                char top = st.top();
                st.pop();
                
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) 
                        return false;
                
            }
        }
        
        return st.empty();
    }