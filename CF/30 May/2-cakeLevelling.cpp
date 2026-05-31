#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> ans;
        long long prefix = 0, mini = LLONG_MAX;

        for(int i = 1; i <= n; i++){
            long long x;
            cin >> x;
            prefix += x;
            mini = min(mini, prefix / i);
            ans.push_back(mini);
        }

        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}