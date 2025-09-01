#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    set<pair<int, int>> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert({x, i});
    }

    int cur = 1, val = 0;
    while (!s.empty()) {                            // n
        auto x = s.lower_bound(make_pair(val, 0));  // log n
        while (x != end(s) and x->first <= m) {     // n
            ans[x->second] = cur;
            val = x->first + d + 1;
            s.erase(x);                            // log n
            x = s.lower_bound(make_pair(val, 0));  // log n
        }
        val = 0;
        cur++;
    }
    cout << cur - 1 << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}