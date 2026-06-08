#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll makePalin(ll half, bool odd) {
    string h = to_string(half);
    string rev = h;
    reverse(rev.begin(), rev.end());
    string full = odd ? h + rev.substr(1) : h + rev;
    if (full.size() > 18) return -1;  
    return stoll(full);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        string ns = to_string(n);
        int len = ns.size();

        ll ans_a = -1, ans_b = -1;

        for (int d = len; d >= 1 && ans_a == -1; d--) {
            int halfLen = (d + 1) / 2;
            bool odd = d % 2 == 1;

            ll minHalf = (halfLen == 1) ? 0 : 1;
            for (int i = 0; i < halfLen - 1; i++) minHalf *= 10;

            ll startHalf;
            if (d == len) {
                startHalf = stoll(ns.substr(0, halfLen));
                if (makePalin(startHalf, odd) > n) startHalf--;
            } else {
                ll mxH = 1;
                for (int i = 0; i < halfLen; i++) mxH *= 10;
                startHalf = mxH - 1;
            }

            for (ll hh = startHalf; hh >= max(minHalf, startHalf - 25); hh--) {
                ll palin = makePalin(hh, odd);
                if (palin < 0 || palin > n) continue;
                ll b = n - palin;
                if (b % 12 == 0) {
                    ans_a = palin;
                    ans_b = b;
                    break;
                }
            }
        }

        if (ans_a == -1) cout << -1 << "\n";
        else cout << ans_a << " " << ans_b << "\n";
    }

    return 0;
}