#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> total(4), curr(4);
    curr[1] = 1;
    curr[2] = 2;
    curr[3] = 3;
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swap(curr[a], curr[b]);
        total[curr[g]]++;
    }
    cout << *max_element(total.begin(), total.end()) << "\n";
}