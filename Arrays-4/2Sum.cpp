#include<bits/stdc++.h>
using namespace std;

// Aproach -1 : Hashing

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int needed = target - curr;

            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            mp[curr] = i;
        }

        return {-1, -1};
    }

// Approach -2 : Two Pointer O(1) S.C.

 vector<int> twoSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {nums[left], nums[right]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }

    // Approach -2 is Not for Leetcode becuz we return values in this
    // if we want it to be ike leetcode we need to create another array like

    // vector<pair<int, int>> arr;
    //     for (int i = 0; i < nums.size(); i++) {
    //         arr.push_back({nums[i], i});
    //     }
    //  sort(arr.begin(),arr.end());

    // This would store values and original indices