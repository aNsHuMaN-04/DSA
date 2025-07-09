#include <bits/stdc++.h>
using namespace std;

// n-2 for when we swap 
// n-1 for when we don't swap

int countDer(int n)
{

    if(n == 1)
        return 0;

    if(n == 2)
        return 1;
        
    int ans = (n-1) * ((countDer(n - 1)) + countDer(n - 2));

    return ans;
}

// Memoization

int solveMem(int n, vector<int>& dp)
{

    if(n == 1)
        return 0;

    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];
        
    dp[n] = (n-1) * ((countDer(n - 1)) + countDer(n - 2));

    return dp[n];

}

int countDer2(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solveMem(n, dp);
    return ans; 
}