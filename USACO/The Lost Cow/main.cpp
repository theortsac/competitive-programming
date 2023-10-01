#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    cin >> x >> y;
    if (x == y) cout << 0 << "\n";
    int fac = 1, lastPo = x, dist = 0;
    while (true) {
        if (x < y) {
            if ((x+fac) >= y) {
                dist += abs(y - lastPo);
                break;
            }
            dist += abs((x+fac)-lastPo);
            lastPo = (x+fac);
        } else {
            if ((x+fac) <= y) {
                dist += abs(y - lastPo);
                break;
            }
            dist += abs((x+fac)-lastPo);
            lastPo = (x+fac);
        }
        fac *= -2;
    }
    cout << dist << "\n";
}