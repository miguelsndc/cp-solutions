#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
ll M = (1LL << 61);
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(0, M - 1);
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), p(n);
    vector<ll> random_n(n + 1);
    for (int i = 1; i <= n; i++) {
        random_n[i] = dist(rng);
    }
    for (int i = 0; i < n; i++) {
        a[i] = random_n[a[i]];
        cin >> a[i];
        p[i] = random_n[i + 1];
    }
    vector<ll> pxor_a(n + 1), pxor_p(n + 1);
    for (int i = 0; i < n; i++) pxor_a[i + 1] = pxor_a[i] ^ a[i];
    for (int i = 0; i < n; i++) pxor_p[i + 1] = pxor_p[i] ^ p[i];
    while(q--) {
        int l, r; cin >> l >> r;
        ll a = pxor_a[r] ^ pxor_a[l - 1];
        ll b = pxor_p[r] ^ pxor_p[l - 1];
        if (a == b) {
            cout << "YES\n";
            cout << "NO\n";
        } else {
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}
