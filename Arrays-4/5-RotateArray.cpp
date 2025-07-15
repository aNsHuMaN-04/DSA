#include<bits/stdc++.h>
using namespace std;
 
 void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Reverse the whole array
        for (int i = 0, j = n - 1; i < j; ++i, --j)
            swap(nums[i], nums[j]);

        // Reverse first k elements
        for (int i = 0, j = k - 1; i < j; ++i, --j)
            swap(nums[i], nums[j]);

        // Reverse remaining n - k elements
        for (int i = k, j = n - 1; i < j; ++i, --j)
            swap(nums[i], nums[j]);
    }