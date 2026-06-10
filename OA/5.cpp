#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long w;
    cin >> n >> w;

    vector<pair<double,double>> a(n);
    for (int i = 0; i < n; i++) {
        double v, wt;
        cin >> v >> wt;
        a[i] = {v, wt};
    }

    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        return x.first/x.second > y.first/y.second;
    });

    double ans = 0;
    double rem = w;

    for (int i = 0; i < n && rem > 0; i++) {
        double take = min(rem, a[i].second);
        ans += take * (a[i].first / a[i].second);
        rem -= take;
    }

    cout << fixed << setprecision(6) << ans << "\n";
}