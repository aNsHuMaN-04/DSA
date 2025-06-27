#include <bits/stdc++.h>
using namespace std;


void solve(vector<int>& candidates, int target, int i, vector<int>& ds, set<vector<int>>& st) {
    if (i == candidates.size()) {
        if (target == 0)
            st.insert(ds);
        return;
    }

    if (candidates[i] <= target) {
        ds.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, ds, st); 
        ds.pop_back();
    }

    solve(candidates, target, i + 1, ds, st); 
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
    vector<int> ds;
    set<vector<int>> st;
    solve(candidates, target, 0, ds, st);
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
    }




//Approach - 2 : 

void solve2(vector<int>& candidates, int target, int start, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve2(candidates, target - candidates[i], i + 1, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2_2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve2(candidates, target, 0, ds, ans);
        return ans;
    }