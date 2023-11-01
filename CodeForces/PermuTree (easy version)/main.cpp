#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> adj;
vector<int> children;
int total;

void dfs(int node, int dad) {
    children[node] = 1;
    for (auto u : adj[node]) {
        if (u == dad) continue;
        dfs(u, node);
        children[node] += children[u];
    }
}

void solve(int node, int dad) {
    vector<int> ch;
    ch.push_back(0);
    int sum = 0;
    for (auto u : adj[node]) {
        if (u == dad) continue;
        solve(u, node);
        ch.push_back(children[u]);
        sum += children[u];
    }
    if (ch.size() == 1) return;
    sort(ch.begin(), ch.end());
    int n = ch.size() - 1;
    int goal = sum/2;
    int dp[n+5][goal+5];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= goal; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= ch[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - ch[i]] + ch[i]);
            }
        }
    }
    total += (dp[n][goal] * (sum - dp[n][goal]));
}

int32_t main() {
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i = 2; i <= n; i++) {
        int dad;
        cin >> dad;
        adj[dad].push_back(i);
        adj[i].push_back(dad);
    }
    children.resize(n+1);
    dfs(1, 0);
    solve(1, 0);
    cout << total << "\n";
}