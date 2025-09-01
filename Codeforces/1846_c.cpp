#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<pair<ll, ll>> p;

    ll rcnt = 0, rpen = 0;
    for (int i = 0; i < n; i++) {
        ll ps = 0, pen = 0, cnt = 0;
        for (int j = 0; j < m; j++) {
            if (ps + a[i][j] <= h) {
                ps += a[i][j];
                pen += ps;
                cnt++;
            } else {
                break;
            }
        }
        if (i == 0) {
            rcnt = cnt;
            rpen = pen;
        }
        p.push_back({cnt, pen});
    }

    stable_sort(p.begin(), p.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    stable_sort(p.begin(), p.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].first == rcnt and p[i].second == rpen) {
            pos = i + 1;
            break;
        }
    }
    cout << pos << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}