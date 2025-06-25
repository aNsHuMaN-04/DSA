#include <bits/stdc++.h>
using namespace std;

   
// Approach -1 : Use Set , because in case of [2,2] it gets pushed twice 
// Unordered for better TC
// An array of size N can have atmost 2 majority (N/3) elements

    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        int n = nums.size();
        unordered_set <int> st;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] > n/3 )
                st.insert(nums[i]);

            if (st.size() == 2) break;
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }


// Approach -2 : Replica of Voter's Algo for N/2


   vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    vector<int> ans;
    int mini = n / 3 + 1;
    if (cnt1 >= mini) ans.push_back(el1);
    if (cnt2 >= mini) ans.push_back(el2);

    return ans;
}


