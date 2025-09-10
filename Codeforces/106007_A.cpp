#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<ll> a(n - 1), multiples(31);
    iota(a.begin(), a.end(), 1LL);
    for (ll x: a) {
        for (ll i = 2; i < n; i++) {
            if (x % i == 0)multiples[i]++;
        }
    }
    ll prod = 1;
    for (ll i = 2; i < n; i++) {
        if (multiples[i] < 2 and prod % i != 0) {
            prod *= i;
        }
    }
    a.push_back(prod);
    cout << a.size() << '\n';
    for (ll x: a) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}