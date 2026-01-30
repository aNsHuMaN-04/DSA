   // Whenever we have to find something using sliding window which has something = k
   // we will find something <= k and something <= k-1 and subtract the two
   // because normal counting leaves out some cases

int count(vector<int>& nums, int k)
{
    int l = 0, r = 0, cnt = 0, n = nums.size();
    unordered_map<int, int> mp;

    while(r < n) {
        mp[nums[r]]++;
        while(mp.size() > k) {
            mp[nums[l]]--;
            if(mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
       return count(nums, k) - count(nums, k - 1);
    }