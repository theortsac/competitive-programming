#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2) cout << -1 << "\n"; 
    else if (n%2) {
        int curr = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << curr << " ";
                curr++;
            }
            cout << "\n";
        }
    } else {
        vector<int> b(n);
        for (int i = 0; i < n-1; i++) {
            b[i] = i+1;
        }
        int f = (((n-1)*(n))/2)%n;
        b[n-1] = n + f;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n; j++) {
                cout << b[j]+((n+f)*i) << " ";
            }
            cout << "\n";
        }
        int tot = 0;
        for (int i = 0; i < n-1; i++) {
            tot += b[0]+((n+f)*i);
        }
        int newf = (b[0]+((n+f)*(n/2)))*n - tot;
        for (int i = 0; i < n; i++) {
            if (i==(n-1)) {
                cout << newf + (n-2) + f + 1 << "\n";
                continue;
            }
            cout << newf + i << " ";
        }
    }
}