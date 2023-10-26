#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int> c(n+5), v(n+5);
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cin >> k;
    int curr_min = 0x3f3f3f3f;
    for (int i = n; i >= 1; i--) {
        if (c[i] < curr_min) {
            curr_min = c[i];
            s.push(i);
        }
    }
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (c[x] > k) break;
        int amnt = k/c[x];
        if (!s.empty()) {
            amnt -= min(k/c[x], (k%c[x])/(c[s.top()] - c[x]));
        }
        v[1] += amnt;
        v[x+1] -= amnt;
        k -= amnt*c[x];
    }
    for (int i = 1; i <= n; i++) {
        v[i] += v[i-1];
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}