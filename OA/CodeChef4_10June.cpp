#include <bits/stdc++.h>
using namespace std;

long long mygcd(long long x, long long y) {
    while(y) {
        x = x % y;
        swap(x, y);
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    vector<long long> ans;

    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a == b) {
            ans.push_back(0);
            continue;
        }

        vector<long long> candidates;
        candidates.push_back(c);

        for(long long i = 1; i * i <= a; i++) {
            if(a % i == 0) {
                candidates.push_back(i);
                candidates.push_back(a / i);
            }
        }
        for(long long i = 1; i * i <= b; i++) {
            if(b % i == 0) {
                candidates.push_back(i);
                candidates.push_back(b / i);
            }
        }

        sort(candidates.begin(), candidates.end());

        long long best = LLONG_MAX;
        for(long long v : candidates) {
            if(v < c) continue;
            if(mygcd(a, v) == mygcd(b, v)) {
                best = min(best, (v - c) + 1);
                break;
            }
        }

        ans.push_back(best);
    }

    for(auto it : ans)
        cout << it << endl;
}