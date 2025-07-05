#include<bits/stdc++.h>
using namespace std;

// Approach - 1: Three Loops cuzz why not ?

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }


// Approach - 2: Using Set Hashing : Use the HashSet to store values between the i and j pointers 


 vector<vector<int>> threeSum(vector<int>& nums) {
     set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++) 
    {
        set<int> hashset;
    
        for (int j = i + 1; j < n; j++) 
        {
            int third = -(nums[i] + nums[j]);
           
            if (hashset.find(third) != hashset.end())
             {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
             }
            
            hashset.insert(nums[j]);
        
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Approach - 3: Two Pointer 

// nums = [-2,-2,-2,-1,-1,-1,0,0,0,1,1,1,2,2,2]  for understanding and skipping duplicate values

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }