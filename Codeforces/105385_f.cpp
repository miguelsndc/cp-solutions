#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll soma = accumulate(all(a), 0LL);

    vector<ll> somasuf;
    ll atual = 0;
    for (int i = n - 1; i >= 1; i--) {
        atual += a[i];
        somasuf.push_back(atual);
    }

    sort(rall(somasuf));

    vector<ll> ans(n);
    ans[0] = soma;
    ll ps = 0;
    for (int k = 2; k <= n; k++) {
        ps += somasuf[k - 2];
        ans[k - 1] = soma + ps;
    }
    for (int k = 0; k < n; k++) cout << ans[k] << ' ';
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