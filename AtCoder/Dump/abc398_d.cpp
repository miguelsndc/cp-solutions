#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

void solve() {
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;

    vc<vc<int>> dirs(256);
    dirs['N'] = {1, 0};
    dirs['S'] = {-1, 0};
    dirs['W'] = {0, 1};
    dirs['E'] = {0, -1};

    set<pair<int, int>> smokes;

    pair<int, int> fire = {0, 0};
    pair<int, int> takahashi = {r, c};
    vc<int> ans(n);
    smokes.insert(fire);
    for (int i = 0; i < n; i++) {
        vc<int> &d = dirs[s[i]];

        fire.first += d[0];
        fire.second += d[1];
        takahashi.first += d[0];
        takahashi.second += d[1];

        smokes.insert(fire);

        if (smokes.count(takahashi)) {
            ans[i] = 1;
        }
    }

    for (int x : ans) cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}