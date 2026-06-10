#include <bits/stdc++.h>
using namespace std;

int p[1005];

int find(int a) {
    return p[a] == a ? a : p[a] = find(p[a]);
}

void unite(int a, int b) {
    p[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        p[i] = i;
    }

    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            if (dx*dx + dy*dy <= (r[i]+r[j])*(r[i]+r[j]))
                unite(i, j);
        }

    for (int i = 0; i < n; i++) {
        double dxs = x[i]-xs, dys = y[i]-ys;
        if (dxs*dxs + dys*dys > r[i]*r[i]) continue;
        for (int j = 0; j < n; j++) {
            double dxt = x[j]-xt, dyt = y[j]-yt;
            if (dxt*dxt + dyt*dyt > r[j]*r[j]) continue;
            if (find(i) == find(j)) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
}