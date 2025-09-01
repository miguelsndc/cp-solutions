#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    string s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (count(all(s), '?')) {
            for (int i = 0; i < 3; i++) {
                if (s[i] == 'A') a = 1;
                if (s[i] == 'B') b = 1;
                if (s[i] == 'C') c = 1;
            }
        }
    }
    if (a and b) {
        cout << "C\n";
    } else if (b and c) {
        cout << "A\n";
    } else {
        cout << "B\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}