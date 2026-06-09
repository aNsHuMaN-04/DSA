class Solution {
public:
    int solve(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i >= n - 1) return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {
            int next = solve(i + j, nums, n, dp);
            if (next != INT_MAX)
                mini = min(mini, 1 + next);
        }

        dp[i] = mini;
        return dp[i];
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, n, dp);
    }
};
