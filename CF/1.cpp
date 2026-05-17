#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    vector<int> ans;

    while(t--)
    {

        int n, cnt0 = 0, cnt1 = 0, cnt2 = 0;
        cin >>n;
        vector<int> w(n);
        for(int i = 0; i < n; i++)
        {
            cin >> w[i];
            if(w[i] == 0) cnt0++;
            else if(w[i] == 1) cnt1++;
            else cnt2++;
        }
        int pairs = min(cnt1, cnt2);
        int cnt = cnt0 + pairs;
        cnt1 -= pairs;
        cnt2 -= pairs;
        cnt += cnt1/3;
        cnt += cnt2/3;
        ans.push_back(cnt);
    }

    for(auto x : ans)
        cout << x << endl;
    }
