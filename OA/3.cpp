#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long r, b;
    cin >> r >> b;

    long long tot = r + b;
    long long h = 0;
    while ((h+1)*(h+2)/2 <= tot) h++;

    long long need = h*(h+1)/2;
    long long lo = need - b, hi = r;
    if (lo < 0) lo = 0;

    // dp[s] = number of subsets of {1..h} with red-sum = s
    vector<long long> dp(hi + 1, 0);
    dp[0] = 1;

    for (int k = 1; k <= h; k++) {
        // iterate backwards (0/1 knapsack)
        for (int s = hi; s >= 0; s--) {
            if (dp[s] == 0) continue;
            if (s + k <= hi) {
                dp[s + k] = (dp[s + k] + dp[s]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (long long s = lo; s <= hi; s++) {
        ans = (ans + dp[s]) % MOD;
    }

    cout << ans << "\n";
}