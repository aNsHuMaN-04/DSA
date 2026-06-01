// Explaination on Gemini

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        
        // Find the current position of 0
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        // 1. Check if the array is an Ascending Cycle
        bool is_asc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                is_asc = false;
                break;
            }
        }
        
        if (is_asc) {
            // Min of: standard left shifts OR reverse-shift-reverse
            return min(idx, n - idx + 2);
        }
        
        // 2. Check if the array is a Descending Cycle
        bool is_desc = true;
        for (int i = 0; i < n; ++i) {
            // + n prevents negative results during modulo in C++
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                is_desc = false;
                break;
            }
        }
        
        if (is_desc) {
            // Min of: shift-then-reverse OR reverse-then-shift
            return min(idx + 2, n - idx);
        }
        
        // 3. If it's neither, the relative order is broken
        return -1;
    }
};