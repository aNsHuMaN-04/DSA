#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ph[5];

bool consistent(vector<int>& a, vector<int>& b) {
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (l == -1) return true;
    
    bool ok1 = true, ok2 = true;
    for (int i = l; i < r && (ok1||ok2); i++) {
        if (ok1 && b[i] != a[i+1]) ok1 = false;
        if (ok2 && b[i+1] != a[i]) ok2 = false;
    }
    if (ok1 && b[r] == a[l]) return true;
    if (ok2 && b[l] == a[r]) return true;
    return false;
}

bool checkAll(vector<int>& a) {
    for (int i = 0; i < 5; i++)
        if (!consistent(a, ph[i])) return false;
    return true;
}

vector<int> applyMove(vector<int>& a, int from, int to) {
    vector<int> t = a;
    int val = t[from];
    t.erase(t.begin() + from);
    t.insert(t.begin() + to, val);
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < 5; i++) {
        ph[i].resize(n);
        for (int j = 0; j < n; j++) cin >> ph[i][j];
    }

    if (checkAll(ph[0])) {
        for (int i = 0; i < n; i++) cout << ph[0][i] << " \n"[i==n-1];
        return 0;
    }

    for (int p = 1; p < 5; p++) {
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (ph[0][i] != ph[p][i]) {
                if (l == -1) l = i;
                r = i;
            }
        }
        if (l == -1) continue;

        vector<vector<int>> tries = {
            applyMove(ph[0], l, r),
            applyMove(ph[0], r, l),
            applyMove(ph[p], l, r),
            applyMove(ph[p], r, l),
            ph[p]
        };

        for (auto& c : tries) {
            if (checkAll(c)) {
                for (int i = 0; i < n; i++) cout << c[i] << " \n"[i==n-1];
                return 0;
            }
        }
    }
}