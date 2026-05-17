#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    vector<int> ans;

    while(t--)
    {
        int n, x1,x2,k;
        cin >> n >> x1 >> x2 >> k;
        int d = min(abs(x1-x2), n-abs(x1-x2));
        ans.push_back(min(d + k, n -d));
    }
    for(auto x : ans)
        cout << x << endl;
}