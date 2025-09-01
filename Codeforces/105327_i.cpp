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
    map<pair<int,int>,vector<int>>cache;
    int q;
    cin >> q;
    int timestamp = -1;
    vector<int> vis(total, 0);
    vector<int> pai(total, -1), path;
    while (q--) {
        path.clear();

        ++timestamp;
        int x, y;
        cin >> x >> y;

        if(cache[{x,y}].size()>0){
            cout<<(cache[{x,y}].size()+1)/2<<'\n';
            for (int i = 0; i < (int)cache[{x,y}].size(); i++) {
                if (cache[{x,y}][i] < m)
                    cout << cache[{x,y}][i] + 1;
                else
                    cout << " " << cache[{x,y}][i] - m + 1 << " ";
            }
            cout<<'\n';
            continue;
        }
        --x, --y;
        queue<int> q;
        q.push(x);
        vis[x] = timestamp;

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

        for (int cur = y; cur != -1; cur = pai[cur])
            path.push_back(cur);

        reverse(all(path));

        cache[{x+1,y+1}]=path;

        cout << (path.size() + 1) / 2 << "\n";

        assert(path.size()<300);

        for (int i = 0; i < (int)path.size(); i++) {
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