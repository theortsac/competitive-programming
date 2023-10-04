#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1), pf(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pf[i] = (pf[i-1] ^ a[i]);
        }
        int zero = 0, one = 0;
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            if (c == '1') one = (one ^ a[i]);
            else zero = (zero ^ a[i]);
        }
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 2) {
                int c;
                cin >> c;
                if (c) cout << one << " ";
                else cout << zero << " ";
            } else {
                int l, r;
                cin >> l >> r;
                int x = (pf[l-1] ^ pf[r]);
                one = (one ^ x);
                zero = (zero ^ x);
            }
        }
        cout << "\n";
    }
}