#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<char> v(n+2);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (v[i-2] != v[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}