class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();

            
        vector<int>ans;
        
        ans.push_back(nums[0]);
        int cnt=1;
        for(int i=1 ; i<n  ;i++){
            if(nums[i]==nums[i-1]){
                cnt = cnt+1;
                if(cnt<=k)
                    ans.push_back(nums[i]);
            }

            else{
                cnt=1;
            ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};