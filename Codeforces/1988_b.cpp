#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string k;
    char prev = '\0';
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') k += s[i];
        else if (prev != '0') k += s[i];
        prev = s[i];
    }
    int c1 = count(k.begin(), k.end(), '1');
    int c0 = count(k.begin(), k.end(), '0');
    if (c1 > c0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}