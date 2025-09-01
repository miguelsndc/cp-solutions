#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long int;

void solve() {
    ll n, k;
    cin >> n >> k;

    auto cmp = [](ll l, ll r) {
        int posl = 64, posr = 64;
        for (ll i = 0; i < 64; i++) {
            if ((l & (1LL << i)) == 0) {
                posl = i;
                break;
            }
        }
        for (ll i = 0; i < 64; i++) {
            if ((r & (1LL << i)) == 0) {
                posr = i;
                break;
            }
        }
        return posl > posr;
    };

    priority_queue<ll, vector<ll>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    bool run = true;
    while (run and pq.size() > 0) {
        ll x = pq.top();
        for (ll i = 0; i < 64; i++) {
            ll bit = (1LL << i);
            if (!(x & bit)) {
                x += bit;
                if (k >= bit) {
                    k -= bit;
                    pq.pop();
                    pq.push(x);
                    break;
                } else {
                    run = false;
                    break;
                }
            }
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        ll x = pq.top();
        pq.pop();
        ans += __builtin_popcountll(x);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}