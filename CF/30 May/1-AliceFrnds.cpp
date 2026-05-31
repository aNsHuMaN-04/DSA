#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> answers;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto& x : a) cin >> x;
        sort(a.begin(), a.end());

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int T = a[i];
            int left  = (int)(lower_bound(a.begin(), a.end(), T) - a.begin());
            int right = (int)(a.end() - upper_bound(a.begin(), a.end(), T));
            ans = min(ans, max(left, right));
        }

        answers.push_back(ans);
    }

    for(int x : answers)
        cout << x << "\n";

    return 0;
}