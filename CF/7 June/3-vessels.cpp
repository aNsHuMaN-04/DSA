#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;

    vector<vector<long long>> results;

    while(t--){
        int n;
        cin >> n;
        vector<long long> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];

        vector<long long> ans(n, 0);

        for(int l = 0; l < n; l++){
            vector<long long> suf(n + 1, 0);
            for(int k = n - 1; k >= 1; k--){
                suf[k] = max(h[(l + k) % n], suf[k + 1]);
            }

            long long prefix_max = 0;
            long long total = 0;
            for(int k = 1; k < n; k++){
                prefix_max = max(prefix_max, h[(l + k - 1) % n]);
                long long level = min(prefix_max, suf[k]);
                total += level;
            }
            ans[l] = total;
        }

        results.push_back(ans);
    }

    for(auto& ans : results){
        for(int i = 0; i < (int)ans.size(); i++){
            cout << ans[i];
            if(i < (int)ans.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}