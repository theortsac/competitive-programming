#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n%2) {
        cout << -1 << "\n";
        return;
    }
    deque<bool> l, r;
    for (int i = 0; i < n/2; i++) {
        bool b = (s[i] - '0');
        l.push_back(b);
    }
    for (int i = n/2; i < n; i++) {
        bool b = (s[i] - '0');
        r.push_back(b);
    }
    vector<int> op;
    while (op.size() <= 300) {
        auto itl = l.begin();
        auto itr = r.rbegin();
        bool done = 0;
        while (true) {
            int pol = itl - l.begin(), por = -1 + r.size() - (itr - r.rbegin());
            cout << pol << " " << por << "\n";
            if (l[pol] == r[por]) {
                if (l[pol] == 1) {
                    l.insert(l.begin() + (pol-1), 0);
                    l.insert(l.begin() + pol, 1);
                    op.push_back(pol);
                    r.push_front(*l.end());
                    l.pop_back();
                } else {
                    r.insert(r.begin() + (por+1), 0);
                    r.insert(r.begin() + (por+2), 1);
                    op.push_back(por + 2 + l.size());
                    l.push_front(*r.begin());
                    r.pop_front();
                }
                break;
            } else if (itl == l.end()) {
                done = 1;
                break;
            } else {
                itl++;
                itr++;
            }
        }
        if (done) break;
    }
    if (op.size() > 300) {
        cout << -1 << "\n";
    } else {
        cout << op.size() << "\n";
        for (auto u : op) cout << u << " ";
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}