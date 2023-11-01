#include <bits/stdc++.h>

using namespace std;

long long pow12 = 1e12;

void solve() {
    string s;
    cin >> s;
    long long ans = 1e18, amnt1 = 0, amnt0 = 0;
    int inv = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') amnt0++;
        if ((i != (s.size()-1)) and (s[i] > s[i+1])) inv++;
    }
    if (!inv or (s.size() == 1)) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') amnt1++;
        else amnt0--;
        long long del = amnt0 + amnt1 - (s[i] == '1');
        long long curr = (pow12 + 1)*(del);
        if ((i != (s.size()-1)) and (s[i] > s[i+1])) {
            curr -= 1;
        }
        ans = min(ans, curr);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}