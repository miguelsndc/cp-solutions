#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] -= x;
    }

    int mx = *max_element(all(v));
    vc<int> ans;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx) {
            ans.push_back(i + 1);
        }
    }
    sort(all(v));
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
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