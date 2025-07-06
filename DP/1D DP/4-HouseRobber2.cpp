#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int i, vector<int>& dp) {
    if (i < 0)
        return 0;
    if (i == 0)
        return nums[0];
    if (dp[i] != -1)
        return dp[i];

    int incl = nums[i] + solve(nums, i - 2, dp);
    int excl = solve(nums, i - 1, dp);

    dp[i] = max(incl, excl);
    return dp[i];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    // Exclude first
    vector<int> nums1(nums.begin() + 1, nums.end());
    // Exclude last
    vector<int> nums2(nums.begin(), nums.end() - 1);

    vector<int> dp1(nums1.size(), -1);
    vector<int> dp2(nums2.size(), -1);

    int ans1 = solve(nums1, nums1.size() - 1, dp1);
    int ans2 = solve(nums2, nums2.size() - 1, dp2);

    return max(ans1, ans2);
}
