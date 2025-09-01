#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> u;
    vector<int> strength(n), students(n);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
        students[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> strength[i];
    }
    for (int i = 0; i < n; i++) {
        u[students[i]].push_back(strength[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(rall(u[i]));
    }

    for (auto [tag, v] : u) {
        vector<ll> ps(v.size() + 1);
        for (int j = 0; j < v.size(); j++) {
            ps[j + 1] = ps[j] + 1LL * v[j];
        }

        for (int j = 0; j < v.size(); j++) {
            ans[j] += ps[v.size() - (v.size() % (j + 1))];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}