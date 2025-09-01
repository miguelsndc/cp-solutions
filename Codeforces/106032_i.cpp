#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#include <bits/stdc++.h>
using namespace std;
void solve() {
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    for (ll &i: A) cin >> i; 
    const int mxn = *max_element(all(A));
    vector<int> freq(X);
    for (ll x: A) {
        freq[x % X]++;
    }
    ll ans = 0;
    for (int i = 0; i < X; i++) {
        if (freq[i] == 0) continue;
        ll r = i;
        ll count_r = freq[r];
        ll s = (X - r) % X;
        if (freq[s] > 0 and r * s % X == 0) {
            ll count_s = freq[s];
            if (r == s) {
                ans += count_r * (count_r - 1) / 2;
            } else if (r < s) {
                ans += count_r * count_s;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}