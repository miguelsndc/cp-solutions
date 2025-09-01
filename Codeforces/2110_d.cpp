#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;
namespace rg = std::ranges;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
void solve() {
    int n, m;
    cin >> n >> m;
    vc<int> a(n);

    for (int &x : a) cin >> x;

    vc<pair<int, int>> g[n];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[--a].emplace_back(--b, w);
    }

    /*
        maior numero de baterias que da pra ter no vertice v
        o que bb facilita ?
        suponha que resposta é x
        tenho que:
            1 - pegar x baterias o quanto antes
            2 - passar por arestas que somente tem peso <= baterias tenho
    */

    const int INF = 1e9 + 1;
    auto check = [&](int m) -> bool {
        vc<int> best(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && best[i] == 0) {
                continue;
            }
            best[i] += a[i];
            best[i] = min(best[i], m);
            for (auto [v, w] : g[i]) {
                if (w <= best[i]) {
                    best[v] = max(best[v], best[i]);
                }
            }
        }
        return (best.back() > 0);
    };

    if (!check(INF)) {
        cout << -1 << '\n';
        return;
    }

    int l = 1, r = 1e9, ans = 1e9 + 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << (ans == (1e9 + 1) ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}