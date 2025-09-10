#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    string sep = "";
    for (const auto &x : v) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &a) {
    os << "{";
    string sep = "";
    for (const auto &x : a) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    string sep = "";
    for (const auto &x : s) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
    os << "{";
    string sep = "";
    for (const auto &x : m) os << sep << "(" << x.first << ": " << x.second << ")", sep = ", ";
    return os << "}";
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << " " << H;
    dbg_out(T...);
}

#ifdef MIGUEL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MAXN = 1e5;

const int MOD1 = 188'888'881;
const int MOD2 = 1e9 + 7;
const int base = 137;

ll pow1[MAXN];
ll pow2[MAXN];
// O(n) - Chamar antes
void calc_pow() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = (pow1[i - 1] * base) % MOD1,
        pow2[i] = (pow2[i - 1] * base) % MOD2;
}
struct Hashing {
    vector<pair<ll, ll>> pref;
    // O(1)
    Hashing(string &s) {
        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
                     pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }

    // O(1)
    ll operator()(int a, int b) {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return (h1 << 32) | h2;
    }
};

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum [0..pos] (0-based)
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

struct Interval {
    int l, r, i, query;
    Interval(int _l, int _r, int _i, int _query) : l(_l), r(_r), i(_i), query(_query) {};
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<int> sizes;
    set<ll> hashes;
    for (int i = 0; i < m; i++) {
        string ss;
        cin >> ss;
        sizes.push_back(ss.size());
        Hashing h(ss);
        hashes.insert(h(0, ss.size() - 1));
    }
    vector<Interval> L;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        L.push_back({--l, --r, i, true});
    }

    sort(sizes.begin(), sizes.end());
    sizes.erase((unique(sizes.begin(), sizes.end())), sizes.end());
    Hashing full_hash(s);
    for (int wd : sizes) {
        for (int i = 0; i + wd <= n; i++) {
            dbg(i, i + wd - 1, wd);
            ll val = full_hash(i, i + wd - 1);
            if (hashes.count(val)) {
                L.push_back({i, i + wd - 1, -1, false});
            }
        }
    }
    vector<ll> ans(q);
    sort(L.begin(), L.end(), [](const Interval &A, const Interval &B) {
        if (A.l != B.l) return A.l < B.l;
        if (A.r != B.r) return A.r > B.r;             
        if (A.query != B.query) return A.query > B.query;  
        return A.i < B.i;
    });
    Fenwick bit(n + 5);
    for (int i = L.size() - 1; i >= 0; i--) {
        if (L[i].query) {
            ans[L[i].i] = bit.sum(L[i].r);
        } else {
            bit.add(L[i].r, 1);
        }
    }
    for (ll x : ans) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc_pow();
    int T = 1;  // cin>>T;
    while (T--) solve();
}