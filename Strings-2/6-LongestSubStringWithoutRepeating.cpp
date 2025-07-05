#include<bits/stdc++.h>
using namespace std;

// Approach - 1 : Hashing 

int lengthOfLongestSubstring(string s) {
    
    int ans = 0;

     for(int i = 0; i < s.length(); i++)   
        {
            string temp ="";
            unordered_set<char> hashset;
            
            for(int j = i; j < s.length(); j++)
            {
                if(hashset.find(s[j]) != hashset.end())
                    break;
            
                temp += s[j]; 
                hashset.insert(s[j]);
            }

            if(temp.length() > ans)
                ans = temp.size();
        }
    
    return ans;
    } 

// Approach - 2 : Two pointer and Sliding Window 

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}