#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n+1), g(n+1), m(n+1), z;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        g[p[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!g[i]) z.push_back(i);
    }
    for (auto x : z) {
        if (k == 1) {
            cout << "NO\n";
            return;
        }
        int u = x;
        while (!g[u]) {
            m[u] = 1;
            g[p[u]]--;
            u = p[u];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (m[i]) continue;
        int s = 1;
        m[i] = 1;
        int x = p[i];
        while (x != i) {
            s++;
            m[x] = 1;
            x = p[x];
        }
        if (s != k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}