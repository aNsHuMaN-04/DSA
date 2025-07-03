#include<bits/stdc++.h>
using namespace std;

    int longestConsecutive(vector<int>& nums) {
       
        if(nums.empty())
            return 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi = 1;
    int cnt = 1;


    for (int i = 1; i < n; i++)
     {
        if (nums[i] == nums[i - 1] + 1) 
            cnt++;
        
         else if (nums[i] != nums[i - 1])
          {
            if (cnt > maxi)
                maxi = cnt;

            cnt = 1;
        }
    }

    if (cnt > maxi) 
        maxi = cnt;
    

    return maxi;
}
