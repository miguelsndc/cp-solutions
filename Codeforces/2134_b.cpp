#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for (ll &i: A) {
        cin >> i;
    }

    if (N == 1) {
        cout << A.back() + K << '\n';
        return;
    }

    if (K & 1) {
        for (ll &x: A) {
            if (x & 1) x += K;
            cout << x << ' ';
        }
    } else {
        int mod = K + 1;
        for (ll x: A) {
            x += (x % mod) * K;
            cout << x << ' ';
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}