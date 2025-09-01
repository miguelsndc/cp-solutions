#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {	
    int n; cin >> n;
    string s; cin >> s;
    string k = s;
    sort(all(k));
    int i = 0, j = 0;
    while(i < n and j < n) {
        if (s[i] == k[j]) {
            i++;
        } else {
            j++;
        }
    }
    if (i == n) {
        cout << s << '\n';
        return;
    }

    for (int j = 0; j < i; j++) {
        cout << s[j];
    }
    char c = ' ';
    for (int x = i; x + 1 < n; x++) {
        if (s[x] > s[x + 1]) {
            c = s[x];

            for (int k = x + 1; k < n; k++) {
                cout << s[k];
            }
            cout << s[x];

            break;
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}