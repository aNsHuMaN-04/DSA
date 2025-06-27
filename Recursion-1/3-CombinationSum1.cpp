#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int target, int i, vector<int>& ds, vector<vector<int>>& ans) {
    if (i == nums.size()) {
        if (target == 0)
            ans.push_back(ds);
        return;
    }

    if (nums[i] <= target) {
        ds.push_back(nums[i]);
        solve(nums, target - nums[i], i, ds, ans); // Same element can be reused unlimited no. of times
        ds.pop_back();
    }

    solve(nums, target, i + 1, ds, ans); // Skip and move to next element
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<int> ds;
    vector<vector<int>> ans;
    solve(nums, target, 0, ds, ans);
    return ans;
}
