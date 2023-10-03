#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> v;
        int curr = 0, sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'B') {
                v.push_back(curr);
                sum += curr;
                curr = 0;
            } else curr++;
        }
        int n = v.size();
        if (!n) {
            cout << "0\n";
            continue;
        }
        v.push_back(curr);
        sum += curr;
        cout << sum - *min_element(v.begin(), v.end()) << "\n";
    }
}
