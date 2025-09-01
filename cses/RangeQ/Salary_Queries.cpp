#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e6 + 5;

vi bit(maxn);

int query(int pos) {
    int val = 0;
    for (int i = pos + 1; i > 0; i -= (i & (-i))) val += bit[i];
    return val;
}

void add(int pos, int val) {
    for (int i = pos + 1; i < maxn; i += (i & (-i))) bit[i] += val;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> values = v;
    vector<array<int, 3>> queries;
    while (q--) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        queries.push_back({(c == '!'), a, b});

        if (c == '?') {
            values.push_back(a);
        }
        values.push_back(b);
    }

    sort(all(values));
    values.resize(unique(all(values)) - begin(values));

    map<int, int> mp;

    for (int i = 0; i < values.size(); i++) {
        mp[values[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        add(mp[v[i]], 1);
    }

    for (auto [t, a, b] : queries) {
        if (t) {
            add(mp[v[a - 1]], -1);
            add(mp[b], 1);
            v[a - 1] = b;
        } else {
            cout << query(mp[b]) - query(mp[a] - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}