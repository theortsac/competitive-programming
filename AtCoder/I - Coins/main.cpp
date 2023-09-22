// Written by João Pedro Castro
// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i
// Status: Accepted

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3+10;
int n;
double dp[MAXN][MAXN]; // dp[i][j] = get i heads until coin j
double v[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // chance of getting tails
            dp[i][j] = dp[i][j-1]*(1.0-v[j]);
            // if I don't want to calculate getting 0 coins, chance of getting heads
            if (i > 0) dp[i][j] += dp[i-1][j-1]*(v[j]);
        }
    }
    double ans = 0;
    for (int i = (n/2)+1; i <= n; i++) {
        ans += dp[i][n];
    }
    cout << setprecision(10) << ans << "\n";
}