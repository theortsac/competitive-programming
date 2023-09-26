#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> v(m), ans(m*k);
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < (m*k); i+=k) {
        int org = i/k;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) ans[i] += v[org][j];
        }
        for (int j = i+1; j < (i+k); j++) {
            ans[j] = ans[i];
        }
     }
     for (auto u : ans) cout << u << "\n";
}