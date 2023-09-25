#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;

int check(int x) {
    if (x==1) return 0;
    else return check(x/2)+1;
}

int binpow(int x, int n) {
    if (n==0) return 1;
    if (n%2) return ((binpow(x, n/2) * binpow(x, n/2))%MOD * x)%MOD;
    return (binpow(x, n/2) * binpow(x, n/2))%MOD;
}

int32_t main() {
    int f;
    cin >> f;
    int exp = 0;
    vector<int> pf(f);
    for (int i = 0; i < f; i++) {
        int n, d;
        cin >> n >> d;
        n = check(n);
        d = check(d);
        exp += (n-d);
        pf[i] = exp;
    }
    int m = 0;
    exp = 0;
    for (int i = 0; i < f; i++) {
        exp = max(exp, pf[i] - m);
        m = min(m, pf[i]);
    }
    cout << binpow(2, exp) << "\n";
}