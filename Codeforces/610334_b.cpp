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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, char>> uc, lc;

    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' and s[i] <= 'z') {
            if (s[i] == 'b') {
                if (lc.size()) lc.pop_back();
            } else {
                lc.push_back({i, s[i]});
            }
        } else {
            if (s[i] == 'B') {
                if (uc.size()) uc.pop_back();
            } else {
                uc.push_back({i, s[i]});
            }
        }
    }
    vector<pair<int, char>> ans;
    for (auto v : lc) {
        ans.push_back(v);
    }
    for (auto v : uc) {
        ans.push_back(v);
    }
    sort(all(ans));
    for (auto [_, ch] : ans) {
        cout << ch;
    }
    cout << '\n';
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