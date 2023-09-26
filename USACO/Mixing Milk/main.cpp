#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<int> c(3), m(3);
    for (int i = 0; i < 3; i++) {
        cin >> c[i] >> m[i];
    }
    int from = 0, to = 1;
    for (int i = 0; i < 100; i++) {
        int amount = min(m[from], c[to] - m[to]);
        m[from] -= amount;
        m[to] += amount;
        from = (from + 1) % 3;
        to = (to + 1) % 3;
    }
    for (auto u : m) cout << u << "\n";
}