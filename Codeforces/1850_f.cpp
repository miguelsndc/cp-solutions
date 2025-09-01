#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    vc<int> a, cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) {
            a.push_back(x);
            cnt[x]++;
        }
    }
    vc<int> pos(n + 1);
    sort(all(a));
    a.resize(unique(all(a)) - begin(a));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= n; j += a[i]) {
            if (j == 0) continue;
            pos[j] += cnt[a[i]];
        }
    }

    cout << *max_element(all(pos)) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}