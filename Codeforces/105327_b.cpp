#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n, m;
    cin >> n >> m;
    int total = n + m;
    vector<vector<int>> g(total);
    for (int i = 0; i < n; i++) {
        int qtd;
        cin >> qtd;
        vector<int> actor(qtd);
        for (int j = 0; j < qtd; j++) cin >> actor[j], actor[j]--;
        for (int j = 0; j < qtd; j++) {
            g[actor[j]].push_back(m + i);     
            g[m + i].push_back(actor[j]);     
        }
    }

    int q;
    cin >> q;
    int timestamp = 0;
    vector<int> vis(total, 0);
    vector<int> pai(total, -1);
    vector<int> path(total);
    map<pair<int,int>,vector<int>> cache;

    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        pair<int,int> key = {x, y};
        if (cache.count(key)) {
            const auto& cacheado = cache[key];
            cout << (cacheado.size() + 1) / 2 << '\n';
            for (int i = 0; i < cacheado.size(); i++) {
                if (cacheado[i] < m)
                    cout << cacheado[i] + 1;
                else
                    cout << " " << cacheado[i] - m + 1 << " ";
            }
            cout << '\n';
            continue;
        }

        timestamp++;
        queue<int> q;
        q.push(x);
        vis[x] = timestamp;
        pai[x] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == y) break;

            for (int v : g[u]) {
                if (vis[v] != timestamp) {
                    vis[v] = timestamp;
                    pai[v] = u;
                    q.push(v);
                }
            }
        }

        if (vis[y] != timestamp) {
            cout << -1 << '\n';
            continue;
        }

        int len = 0, cur = y;
        while (cur != -1) {
            path[len++] = cur;
            cur = pai[cur];
        }

        reverse(path.begin(), path.begin() + len);
        vector<int> path_vec(path.begin(), path.begin() + len);
        cache[key] = path_vec;

        cout << (len + 1) / 2 << "\n";
        for (int i = 0; i < len; i++) {
            if (path[i] < m)
                cout << path[i] + 1;
            else
                cout << " " << path[i] - m + 1 << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) solve();
}
