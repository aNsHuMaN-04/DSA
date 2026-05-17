#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    vector<long long> ans;

    while(t--)
    {
        long long a;
        int n;
        cin >> a >> n;
        int d1, d2;
        cin >> d1 >> d2;

        long long best = LLONG_MAX;
        vector<long long> next;
        queue<long long> q;
        q.push(d1);
        q.push(d2);
        while(!q.empty()) {
            long long curr = q.front();
            q.pop();

            next.push_back(curr);
            if(curr == 0) continue;
            if(curr <= 1e17) {
                q.push(curr * 10 + d1);
                q.push(curr * 10 + d2);
            }

    }
    for(long long b : next) 
        best = min(best, abs(a-b));
    ans.push_back(best);
}
for(auto x : ans)
    cout << x << endl;
}