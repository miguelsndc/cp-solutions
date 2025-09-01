#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    ll N, K, P; cin >> N >> K >> P;
    vector<ll> div;
    auto can = [&] (ll x) {
        return ((x <= K) and (N / x) <= P);
    };
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            div.push_back(i);
            if (N / i != i) div.push_back(N / i);
        }
    }

    vector<ll> ans;
    for (ll x: div) if(can(x)) ans.push_back(x);
    sort(all(ans));
    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}