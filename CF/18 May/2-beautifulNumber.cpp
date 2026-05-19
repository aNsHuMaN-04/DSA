#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    vector<int> ans;

    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        
        int cnt = 0;
        for(char c : s) 
            if(c == '1' || c == '3') cnt++;
        
        int maxi = cnt;
        int cnt2 = 0, cnt13 = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1' || s[i] == '3') cnt13++;
            if(s[i] == '2') cnt2++;
            maxi = max(maxi, cnt2 + (cnt - cnt13));
        }
        ans.push_back(n - maxi);
        
    }
    
    for(auto x : ans)
        cout << x << endl;

}
