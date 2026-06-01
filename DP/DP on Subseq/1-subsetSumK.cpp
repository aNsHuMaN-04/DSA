// Approach 1 : Memoisation + explore both branches and then store in DP
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper function to check if a subset sum equals target
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: target achieved
        if (target == 0) return true;

        // Base case: at the first index, check if it equals the target
        if (ind == 0) return arr[0] == target;

        // Check memoization table
        if (dp[ind][target] != -1) return dp[ind][target];

        // Choice 1: do not take the current element
        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        // Choice 2: take the current element if possible
        bool taken = false;
        if (arr[ind] <= target) {
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        }

        // Store result in DP table
        return dp[ind][target] = notTaken || taken;
    }

    // Main function to check if subset with sum = k exists
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
};

// Since we always ned to return just Possible or not possible so no need to explore both 
// bracnhes if foun din one
// therefore Approach 2 : Memoisation + store and return after exploring one branch only

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSumUtil(int ind, int target,
                       vector<int>& arr,
                       vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Not take
        if (subsetSumUtil(ind - 1, target, arr, dp))
            return dp[ind][target] = true;

        // Take
        if (arr[ind] <= target && subsetSumUtil(ind - 1, target - arr[ind], arr, dp))
            return dp[ind][target] = true;

        return dp[ind][target] = false;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
};

// Since s1+s2 = s and equal partiotion therefore
// s1 = s2 => s1 + s1 = s => s1 = s/2
// therefore we can check if there is a subset with sum = s/2 or not
// hence instead of checking for total sum we check for subset sum


    bool solve(int ind, int target,
               vector<int>& nums,
               vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (ind == 0)
            return nums[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = solve(ind - 1, target,
                             nums, dp);

        bool take = false;
        if (nums[ind] <= target)
            take = solve(ind - 1,
                         target - nums[ind],
                         nums, dp);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for (int x : nums)
            totSum += x;

        if (totSum % 2)
            return false;

        int target = totSum / 2;

        vector<vector<int>> dp(n,
                               vector<int>(target + 1, -1));

        return solve(n - 1, target,
                     nums, dp);
    }
