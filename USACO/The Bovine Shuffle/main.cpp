#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> s(n+1);
    vector<string> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int k = 0; k < 3; k++) {
        vector<string> t(n+1);
        for (int i = 1; i <= n; i++) {
            t[i] = v[s[i]];
        }
        v = t;
    }
    for (int i = 1; i <= n; i++) cout << v[i] << "\n";
}