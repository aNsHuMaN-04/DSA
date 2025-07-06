#include<bits/stdc++.h>
using namespace std;

 int solve(vector<int>& nums, int i, vector<int>& dp)
    {
        if(i < 0)
            return 0;
        
        if(i == 0)
            return nums[0];  // We need max sum so we need to include 0th index cuz something toh it'll add only        
        if(dp[i] != -1)
            return dp[i];

        int incl = nums[i] + solve(nums, i - 2, dp);
        int excl = 0 + solve(nums, i - 1, dp);

        dp[i] = max(incl ,excl);
        return dp[i];
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, n-  1, dp);
        return ans;
    }