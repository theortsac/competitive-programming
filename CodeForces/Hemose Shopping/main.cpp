#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n+1), vpos(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        vpos = v;
        sort(vpos.begin(), vpos.end());
        string ans = "YES\n";
        for (int i = 1; i <= n; i++) {
            if (vpos[i] == v[i]) continue;
            if ((abs(1 - i) >= x) or (abs(n - i) >= x)) continue;
            ans = "NO\n";
            break;
        }
        cout << ans;
    }
}