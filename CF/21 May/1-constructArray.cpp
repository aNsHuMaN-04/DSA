#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<vector<int>> ans(t);

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr;
        unordered_set<int> s;

        for(int j = 1; j < 2 * n; j++) {
            if((int)arr.size() == n) break;

            if(s.count(j)) continue;
            if(!arr.empty()) {
                int newSum = arr.back() + j;
                if(s.count(newSum)) continue;
                s.insert(newSum);
            }
            arr.push_back(j);
            s.insert(j);
    } 
    ans[i] = arr;
}
    for(int i = 0; i < t; i++) {
        for(int j : ans[i])
            cout << j << " ";
        cout << "\n";
    }
}

