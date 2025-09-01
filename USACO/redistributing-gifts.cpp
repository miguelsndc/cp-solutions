#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 500 + 5;

bitset<maxn> reachable[maxn];
vector<int> g[maxn];

void dfs(int src, int cur) {
    if (reachable[src][cur]) return;
    reachable[src][cur] = true;
    for (int v: g[cur]) {
        dfs(src, v);
    }
}

/*
    o grafo contem a aresta i -> j se i = j ou
    se a vaca i prefere o presente j ao presente i

    dai se o grafo tiver um ciclo simples a -> b e b -> a a gnt troca essas vacas
  
    no dfs a gente quer saber aonde a vaca `src` consegue chegar, todos os presentes
    dai a gnt itera e pega o primeiro presente q a vaca chega, pq ou é o q ela ja tem ou é um melhor
*/

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            g[i].push_back(x);
        }
        while(g[i].back() != i) {
            g[i].pop_back();
        }
    }

    for (int i = 1; i <= n; i++) dfs(i, i);

    for (int i = 1; i <= n; i++) {
        for (int x: g[i]) {
            if (reachable[x][i]) {
                cout << x << '\n';
                break;
            }
        }
    }
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