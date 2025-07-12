#include <bits/stdc++.h>
using namespace std;

    int mincostTickets(vector<int>& days, vector<int>& costs) {

     int n = days.size();
     vector<int> dp(n, -1);
     return solveMem(0, n, days, costs, dp);
    }

    int solveMem(int i, int n, vector<int>& days, vector<int>& costs, vector<int>& dp)
    {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans1 = costs[0] + solveMem(i+1, n, days, costs, dp);

        int j;
        for(j = i; j < n && days[j] < days[i] + 7; j++);
        int ans2 = costs[1] + solveMem(j, n, days, costs, dp);

        for(j = i; j < n && days[j] < days[i] + 30; j++);
        int ans3 = costs[2] + solveMem(j, n, days, costs, dp);
  
        dp[i] = min(ans1, min(ans2, ans3));
        return dp[i];

    }
