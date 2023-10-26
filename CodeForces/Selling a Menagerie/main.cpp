#include <bits/stdc++.h>

using namespace std;
 
vector<int> a, c, g;
vector<bool> v;
priority_queue<pair<int, int>> pq;
int n, indexofans;

void put(int x) {
    cout << x << " ";
}

void solve() {
    cin >> n;
    a.clear();
    c.clear();
    g.clear();
    v.clear();
    a.resize(n+1);
    c.resize(n+1);
    g.resize(n+1);
    v.resize(n+1);
    indexofans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (g[i] >= 1) continue;
        int x = i;
        while ((g[x] == 1) || (x == i)) {
            put(x);
            v[x] = 1;
            x = a[x];
        }
        g[x]--;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (!v[i]) pq.push({-c[i], i});
    }
    while (!pq.empty()) {
        while (!pq.empty() and v[pq.top().second]) pq.pop();
        if (pq.empty()) break;
        int x = pq.top().second;
        v[x] = 1;
        x = a[x];
        while (x != pq.top().second) {
            put(x);
            v[x] = 1;
            x = a[x];
        }
        put(x);
        pq.pop();
    }
    cout << "\n";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}