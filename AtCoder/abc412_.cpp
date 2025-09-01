#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector
int n, m;
vector<pair<int, int>> edges;
vector<multiset<int>> g(9);

int f(int i) {
    /*
        - deixa como ta
        - escolhe 2 arestas pra adicionar
        dado que o grafo é simples e todos tem grau 2
        checa a diferença entre as arestas iniciais e essas arestas de agora
    */

    int ans = 1e9;
    if (i >= n) {
        // checa
        return;
    }

    ans = min(ans, f(i + 1));

    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (i == k or i == j) continue;
        }
    }
}

void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges.push_back(minmax(a, b));
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}