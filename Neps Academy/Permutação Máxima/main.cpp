#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i =1; i <= n; i++) {
        ans += abs(i - (n-i+1));
    }
    cout << ans << "\n";
}