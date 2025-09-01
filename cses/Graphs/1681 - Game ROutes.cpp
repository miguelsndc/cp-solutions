#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
#define MOD 1000000007

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // setIO("1681");
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> g(n);
    vector<vi> back(n);
    vi in_degree(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[--a].push_back(--b);
        back[b].push_back(a);
        in_degree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    vi dp(n);
    dp[0] = 1;

    while (!q.empty()) {
        int j = q.front();
        q.pop();
        for (auto edge : g[j]) {
            in_degree[edge]--;
            if (in_degree[edge] == 0)
                q.push(edge);
        }

        for (auto prev : back[j]) {
            dp[j] = (dp[j] % MOD + dp[prev] % MOD) % MOD;
        }
    }

    cout << dp[n - 1];

    return 0;
}