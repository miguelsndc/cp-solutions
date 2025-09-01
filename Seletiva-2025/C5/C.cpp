#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 2e5 + 1;

vector<int> g[MAXN];
vector<int> in(MAXN);
vector<int> out(MAXN);
vector<bool> visited(MAXN);

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a>> b;
        g[a].push_back(b);
        g[b].push_back(a);
        in[a]++;
        in[b]++;
        out[a]++;
        out[b]++;
    }

    int idx = 0, count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        vector<int> comp;
        queue<int> q;
        visited[i] = true;
        q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            comp.push_back(u);
            for (int v: g[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        bool cycle = true;
        for (int c: comp) {
            if (in[c] != 2 || out[c] != 2) {
                cycle = false;
            }
        }
        if(cycle) count++;
        idx++;
    }


    cout << count;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}