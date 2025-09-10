#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int edit_distance(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> dp(m + 1), prev(m + 1);
    iota(prev.begin(), prev.end(), 0);
    for (int i = 1; i <= n; i++) {
        dp[0] = i;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[j] = prev[j - 1];
            else
                dp[j] = 1 + min({dp[j - 1], prev[j], prev[j - 1]});
        }
        swap(dp, prev);
    }
    return prev[m];
}

void solve() {
    string s, t; cin >> s >> t;
    int n; cin >> n;

    vector<string> w;
    w.push_back(s);
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        w.push_back(x);
    }
    w.push_back(t);

    int N = n + 2;
    int S = 0, T = N - 1;
    vector dist(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j)
                dist[i][j] = edit_distance(w[i], w[j]);
        }
    }
    vector dag(N, vector<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (dist[S][i] + dist[i][j] + dist[j][T] == dist[S][T]) {
                dag[i].push_back(j);
            }
        }
    }
    vector<int> dp(N, 0), vis(N, 0), nxt(N, -1);
    function<int(int)> dfs = [&](int u) -> int {
        if (u == T) return 0;
        if (vis[u]) return dp[u];
        vis[u] = 1;
        for (int v : dag[u]) {
            int cand = dfs(v) + (v != T && v != S);
            if (cand > dp[u]) {
                dp[u] = cand;
                nxt[u] = v;
            }
        }
        return dp[u];
    };
    dfs(S);
    cout << dist[S][T] << " " << dp[S] << "\n";
    int cur = nxt[S];
    while (cur != -1 && cur != T) {
        cout << w[cur] << "\n";
        cur = nxt[cur];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
