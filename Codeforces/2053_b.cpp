#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ii pair<int, int>
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    vector<int> ps(2 * n + 1);
    for (ii &x : a) cin >> x.first >> x.second;
    map<int, int> mp;
    for (ii &x : a) {
        if (x.first == x.second) {
            mp[x.first]++;
            ps[x.first] = 1;
        }
    }
    for (int i = 0; i < 2 * n; i++) ps[i + 1] += ps[i];
    for (ii &x : a) {
        if (x.first == x.second) {
            if (mp[x.first] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            if (ps[x.second] - ps[x.first - 1] >= (x.second - x.first + 1)) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
    cout << '\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}