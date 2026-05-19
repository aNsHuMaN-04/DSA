#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    vector<long long> ans;

    while(t--)
    {
        long long n, a, b, cost = 0;
        cin >> n >> a >> b;
        long long groups = n / 3;
        long long rem = n % 3;
        cost += groups * min(b, a * 3);
        if(rem > 0)
            cost += min(b, a * rem);
       ans.push_back(cost);
    }
    
    for(auto x : ans)
        cout << x << endl;

}
