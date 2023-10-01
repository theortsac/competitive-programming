#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fr first
#define se second

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pii> r(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> r[i].fr >> r[i].se;
    }
    int current_mile = 0;
    int road_end = r[0].fr, road_index = 0;
    for (int i = 0; i < m; i++) {
        int len, speed;
        cin >> len >> speed;
        current_mile += len;
        // while the current mile already passed that road
        while (road_end < current_mile) {
            ans = max(ans, speed - r[road_index].se);
            road_index++; // go to the next road
            road_end += r[road_index].fr; // update the end of this road
        }
        ans = max(ans, speed - r[road_index].se);
        if (road_end == current_mile) {
            road_index++;
            road_end += r[road_index].fr;
        }
    }
    cout << ans << "\n";
}