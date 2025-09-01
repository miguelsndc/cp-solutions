#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = (1 << 19);
int n;
vector<ll> tree[4 * maxn], a;
void build(ll l = 0, ll r = n - 1, ll v = 0) {
    if (l == r) {
        tree[v].push_back(a[l]);
    } else {
        ll m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        ll i = 0, j = 0;
        while (i < tree[v * 2 + 1].size() and j < tree[v * 2 + 2].size()) {
            if (tree[v * 2 + 1][i] < tree[v * 2 + 2][j])
                tree[v].push_back(tree[v * 2 + 1][i++]);
            else
                tree[v].push_back(tree[v * 2 + 2][j++]);
        }
        while (i < tree[v * 2 + 1].size())
            tree[v].push_back(tree[v * 2 + 1][i++]);
        while (j < tree[v * 2 + 2].size())
            tree[v].push_back(tree[v * 2 + 2][j++]);
    }
}

ll query(ll a, ll b, ll y1, ll y2, ll l = 0, ll r = n - 1, ll v = 0) {
    if (b < l || a > r) return 0;
    if (l >= a and r <= b) {
        auto low = lower_bound(tree[v].begin(), tree[v].end(), y1);
        auto high = upper_bound(tree[v].begin(), tree[v].end(), y2);
        return high - low;
    }
    ll m = (l + r) / 2;
    ll half1 = query(a, b, y1, y2, l, m, v * 2 + 1);
    ll half2 = query(a, b, y1, y2, m + 1, r, v * 2 + 2);
    return half1 + half2;
}

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    ll A1, D1, A2, D2;
    cin >> A1 >> D1 >> A2 >> D2;

    ll k = (N / 2);
    vector<pair<ll, ll>> left, right;
    for (ll i = 0; i < N; i++) {
        if (i < k)
            left.push_back(A[i]);
        else
            right.push_back(A[i]);
    }

    auto gen = [&](vector<pair<ll, ll>> &v) -> vector<pair<ll, ll>> {
        vector<pair<ll, ll>> subsets;
        ll n = v.size();
        for (ll mask = 0; mask < (1 << n); mask++) {
            pair<ll, ll> sum = {0, 0};
            for (ll i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum.first += v[i].first;
                    sum.second += v[i].second;
                }
            }
            subsets.push_back(sum);
        }
        return subsets;
    };

    vector<pair<ll, ll>> sub_left = gen(left);
    vector<pair<ll, ll>> sub_right = gen(right);

    sort(sub_left.begin(), sub_left.end());
    sort(sub_right.begin(), sub_right.end());

    n = sub_right.size();
    a.assign(sub_right.size(), 0);
    for (ll i = 0; i < a.size(); i++) {
        a[i] = sub_right[i].second;
    }
    build();

    ll ans = 0;
    for (auto [a_sum, d_sum] : sub_left) {
        ll l = A1 - a_sum;
        ll r = A2 - a_sum;
        ll ql = lower_bound(sub_right.begin(), sub_right.end(), make_pair(l, LLONG_MIN)) - sub_right.begin();
        ll qr = upper_bound(sub_right.begin(), sub_right.end(), make_pair(r, LLONG_MAX)) - sub_right.begin() - 1;
        if (ql <= qr)
            ans += query(ql, qr, D1 - d_sum, D2 - d_sum);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;  // cin >> T;
    while (T--) solve();
}
