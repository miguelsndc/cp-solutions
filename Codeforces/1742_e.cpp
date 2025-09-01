#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n], qu[q], suf[n];
    ll pref[n + 1] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i < q; i++) cin >> qu[i];

    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        t.push_back({a[i], i});
    }
    sort(all(t));

    suf[n - 1] = t[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = min(suf[i + 1], t[i].second);
    }

    for (int i = 0; i < q; i++) {
        auto pos = lower_bound(all(t), qu[i], [](pair<int, int> a, int val) {
            return a.first <= val;
        });

        if (pos == end(t)) {
            cout << pref[n] << ' ';
        } else if (pos == begin(t)) {
            cout << 0 << ' ';
        } else {
            cout << pref[suf[pos - begin(t)]] << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}