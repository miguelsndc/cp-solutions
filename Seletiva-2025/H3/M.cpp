#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int dist_a[200005], dist_b[200005];
vector<int> g[200005];

int dfs(int u, int p, int d, int *distp) {
    int maxn = -1;
    distp[u] = d;
    for (int adj: g[u]) {
        if (adj != p) {
            int n = dfs(adj, u, d + 1, distp);
            if (maxn == -1 || distp[n] > distp[maxn]) maxn = n;
        }
    }
    return maxn == -1 ? u : maxn;
}

// diametro de arvore 
// pegar o mais distante de um no arbitrario e dps o mais distante desse nó
// a maior distancia de um no temq ue ser a distancia de um desses dois

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int max_a = dfs(0, 0, 0, dist_a);
    int max_b = dfs(max_a, max_a, 0, dist_a);
    dfs(max_b, max_b, 0, dist_b);

    for (int i = 0; i < n; i++) {
        cout << max(dist_a[i], dist_b[i]) << " \n"[i == n - 1];
    }
}