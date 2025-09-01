#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g[n];
    vector<int> visited(n);
    for (int i = 0; i < m; i++)  {
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int minn = INF, number = INF;
    for (int i = 0; i < n; i++) {
        if (g[i].size() < minn) {
            minn = g[i].size();
            number = i;
        }
    }

    visited[number] = true;
    for (int i = 0; i < minn; i++) {
        visited[g[number][i]] = true;
    }

    for (int v: visited) {
        cout << !v << ' ';
    }
}