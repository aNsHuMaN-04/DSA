class Solution {
public:
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
};

// since s1 + s2 = s
// and s1 = s2 => s1 + s1 = s => s1 = s/2
// therefore we can check if there is a subset with sum = s/2 or not