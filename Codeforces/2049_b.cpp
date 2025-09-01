#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool can = true, ss = false, p = false;
    if (s[0] == 's') s[0] = '.';
    if (s[n - 1] == 'p') s[n - 1] = '.';
    for (int i = 0; i < n; i++)
        if (s[i] == 's') {
            ss = true;
        } else if (s[i] == 'p') {
            p = true;
        }

    if (ss and p) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}