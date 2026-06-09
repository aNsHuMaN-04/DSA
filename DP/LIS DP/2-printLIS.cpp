class Solution {
public:

    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {

        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int not_take = solve(i + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, not_take);
    }

    void buildLIS(int i, int prev, vector<int>& nums, vector<vector<int>>& dp, vector<int>& ans) {

        if (i == nums.size()) return;

        int not_take = solve(i + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        if ((prev == -1 || nums[i] > nums[prev]) && take >= not_take) {

            ans.push_back(nums[i]);
            buildLIS(i + 1, i, nums, dp, ans);
        }
        else {
            buildLIS(i + 1, prev, nums, dp, ans);
        }
    }

    vector<int> getLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        solve(0, -1, nums, dp);

        vector<int> ans;
        buildLIS(0, -1, nums, dp, ans);

        return ans;
    }
};