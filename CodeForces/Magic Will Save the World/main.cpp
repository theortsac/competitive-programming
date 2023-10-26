#include <bits/stdc++.h>

using namespace std;

int w, f, n, mv;
vector<int> v;

bool check(int x) {
    int testw = (mv + w - 1)/w;
    if (x >= testw) return true;
    const int tw = w*x, tf = f*x;
    if ((tf >= mv) or (tw >= mv)) return true;
    vector<int> curr(tf+1), last(tf+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= tf; j++) {
            // se eu posso comprar ele
            if (v[i] <= j) {
                curr[j] = max(curr[j], last[j - v[i]] + v[i]);
            }
        }
        last = curr;
    }
    if ((mv - curr[tf]) <= tw) return true;
    return false;
}

void solve() {
    cin >> w >> f >> n;
    mv = 0;
    if (w < f) swap(w, f);
    // w is bigger
    v.clear();
    v.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mv += v[i];
    }
    sort(v.begin(), v.end());
    int l = 1, r = mv, ans = 0x3f3f3f3f;
    while (l <= r) {
        int m = (l+r)/2;
        if (check(m)) {
            ans = min(ans, m);
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}