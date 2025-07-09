#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums , int tar)
{
    if(tar < 0)
        return 0;
    if(tar == 0)
        return 1;

    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ans += solve(nums, tar - nums[i]);
    }
    return ans;

}

int countWays(vector<int> nums , int tar)
{
    return solve(nums, tar);

    vector<int> dp(tar + 1, -1);
    return solveMem(nums, tar, dp);
}

// Memoization

int solveMem(vector<int> nums , int tar, vector<int>& dp)
{
    if(tar < 0)
        return 0;
    if(tar == 0)
        return 1;
    if(dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ans += solve(nums, tar - nums[i]);
    }

    dp[tar] = ans;

    return dp[tar];
    
}


// Tabulation

int solveTab(vector<int> nums , int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for(int i = 0; i <= tar; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            dp[i] = dp[i - nums[j]];
        }
    }

    return dp[tar];
}