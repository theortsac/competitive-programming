#include <bits/stdc++.h>

using namespace std;

int buckets[1010];

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        int x, y, b;
        cin >> x >> y >> b;
        buckets[x] += b;
        buckets[y+1] -= b;
    }
    int ans = 0;
    for (int i = 1; i < 1010; i++) {
        buckets[i] += buckets[i-1];
        ans = max(ans, buckets[i]);
    }
    cout << ans << "\n";
}