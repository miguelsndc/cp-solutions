#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool connected(int n, vector<int> *g, vector<bool> &marked, int m) {
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (!marked[i]) {
            start = i; break;
        }
    }

    vector<bool> visited(n);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int vis = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour: g[node]) {
            if (!marked[neighbour] && !visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                vis++;
            }
        }
    }
    return vis == (n - m);
}

int main() 
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    vector<bool> marked(n);
    if (connected(n, g, marked, 0)) {
        cout << "YES\n";
    }  else {
        cout << "NO\n";
    }
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        marked[--x] = true;
        if (connected(n, g, marked, i + 1)) {
            cout << "YES\n";
        }  else {
            cout << "NO\n";
        }
    }
}