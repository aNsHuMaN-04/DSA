#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<string> ans;

    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(b.begin(), b.end(), greater<int>());

        bool ok = true;
        for(int i = 2; i < n; i++){
            if(b[i-2] % b[i-1] != b[i]){
                ok = false;
                break;
            }
        }

        if(b[0] < b[1]) ok = false;

        if(ok){
            ans.push_back(to_string(b[0]) + " " + to_string(b[1]));
        } else {
            ans.push_back("-1");
        }
    }

    for(auto& s : ans)
        cout << s << "\n";
    return 0;
}