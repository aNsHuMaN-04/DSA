#include<bits/stdc++.h>
using namespace std;

 int myAtoi(string s) {
        int i = 0, flag = 1;
        long long ans = 0;

        while (i < s.length() && (s[i] == ' ' || s[i] == 0))
            i++;

    
       if (i < s.length() && (s[i] == '-' || s[i] == '+')) 
       {

        if (s[i] == '-') 
            flag = -1;

        i++;
       }
    
   while (i < s.length() && isdigit(s[i])) 
   {
        ans = ans * 10 + (s[i] - '0');

        // Overflow check
        if (flag * ans > INT_MAX)
            return INT_MAX;
        if (flag * ans < INT_MIN)
            return INT_MIN;

        i++;
    }
    
    return flag * ans;
    }