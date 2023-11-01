#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1), amnt(10);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        amnt[v[i]]++;
    }
    cout << "- 0\n";
    int tp = 0;
    while (true) {
        vector<int> tamnt(10), tv(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> tv[i];
            tamnt[tv[i]]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (tamnt[i] == (amnt[i]+1)) {
                tp = i;
                break;
            }
        }
        if (!tp) {
            cout << "- 0\n";
            cout.flush();
            continue;
        }
        cout << "- " << n - tamnt[tp] << " ";
        for (int i = 1; i <= n; i++) {
            if (tv[i] != tp) {
                cout << i << " ";
            }
        }
        cout << "\n";
        cout.flush();
        break;
    }
    while (true) {
        int po = 0;
        for (int i = 1; i <= (amnt[tp] + 1); i++) {
            int j;
            cin >> j;
            if (j != tp) po = i;
        }
        if (!po) {
            cout << "- 0\n";
            cout.flush();
            continue;
        }
        cout << "! " << po << "\n";
        cout.flush();
        break;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}