// in this we can't use the normal sliding window cuz that'll make the r reach the end without counting all subarrays
// so we use prefix sum and hashmap to store the count of prefix sums


// prefixSum

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixsum=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(mp.count(prefixsum-goal)){
                count+=mp[prefixsum-goal];
            }
            mp[prefixsum]++;
        }
        return count;
        
    }
    

// sliding window variable size

// no. of subarrays with sum at most k - no. of subarrays with sum at most k-1

class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
    private int atMost(int[] nums, int goal) {
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.length; head++) {
            sum += nums[head];
            while (sum > goal && tail <= head) {
                sum -= nums[tail];
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }
}