#include <bits/stdc++.h>
using namespace std;

// Approach -1 : Using Map
 int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2)
            return nums[i];
        }
        return -1;
    }


// Approach -2 : O(1) SC

int majorityElement(vector<int>& nums) {
       int n = nums.size();
    int cnt = 0; 
    int ans; 

    for (int i = 0; i < n; i++) {
       
        if (cnt == 0) {
            cnt ++;
            ans = nums[i];
        }

        else if (ans == nums[i]) 
            cnt++;
        
        else cnt--;
    }

    return ans;
    
    }