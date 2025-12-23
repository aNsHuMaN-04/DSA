// Find Duplicate in an array with Constant Space complexity

// Approach - 1 : O(nlogn) : Sort and check with next

#include<bits/stdc++.h>
using namespace std;
  
  int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                return nums[i];
  }
  return -1;
    }


// Approach - 2 : O(n) : Floyd's Cycle Detetction (Fast Slow Method) :

int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}