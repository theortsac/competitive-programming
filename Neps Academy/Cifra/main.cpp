#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a[0] < b[0]) swap(a, b);
    int d = a[0]-b[0];
    char ans = 'S';
    for (int i = 1; i < a.length(); i++) {
        int valb = b[i] - 'A';
        valb = (valb + d)%27;
        if ((valb+'A')!=a[i]) {
            ans = 'N';
            break;
        }
    }
    cout << ans << "\n";
}