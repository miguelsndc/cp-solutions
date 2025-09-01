#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    vector<ll> S;
    for (int i = 0; i < n; i++) {
        S.push_back(a[i] + b[i]);
    }
    sort(S.begin(), S.end());
    vector<ll> ps(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + S[i];
    }
    ll s = ps[n];

    set<ll> cs;
    cs.insert(0);
    cs.insert(suma);
    cs.insert(sumb);
    for (int i = 0; i < n; i++) {
        cs.insert(S[i]);
    }
    vector<ll> candidates;
    for (ll x : cs) {
        candidates.push_back(x);
    }
    sort(candidates.begin(), candidates.end());

    ll best = 1e18;
    for (ll T : candidates) {
        if (T < 0) continue;

        ll cost1 = abs(T - suma) + abs(T - sumb);

        ll r = 0;
        if (suma > T) r += suma - T;
        if (sumb > T) r += sumb - T;

        auto it = upper_bound(S.begin(), S.end(), T);
        int idx = it - S.begin();
        ll count = n - idx;
        ll sum_val = s - ps[idx];
        ll x = (count > 0) ? (sum_val - T * count) : 0;
        if (x < 0) x = 0;

        ll extra = 0;
        if (x > r) {
            extra = (x - r) * 2;
        }

        ll total_cost = cost1 + extra;
        if (total_cost < best) {
            best = total_cost;
        }
    }

    cout << best << endl;
    return 0;
}