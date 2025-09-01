#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> trans(n);
    for (int i = 0; i < n; i++) {
        ll x, t;
        cin >> x >> t;
        trans[i] = {t - x, t + x};
    }
    sort(trans.begin(), trans.end());
    vector<ll> q(n);
    for (int i = 0; i < n; i++) q[i] = trans[i].second;
    vector<ll> tail;
    for (ll val : q) {
        auto it = upper_bound(tail.begin(), tail.end(), val);
        if (it == tail.end())
            tail.push_back(val);
        else
            *it = val;
    }
    cout << tail.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}