#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second
const int maxn = 105;
int n, m, l[maxn], r[maxn], col[maxn];
bool visited[maxn];

void dfs(int u, int c) {
    visited[u] = true;
    col[u] = c;
    fori(m) {
        if(u == i) continue;
        if ((r[i] > r[u] && l[i] < r[u] && l[i] > l[u]) || (l[i] < l[u] && r[i] < r[u] && r[i] > l[u])) {
            if (!visited[i]) dfs(i, c ^ 1);
            else if (col[i] == c) {
                cout << "Impossible\n";
                exit(0);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(visited, false, sizeof visited);
    cin >> n >> m;
    fori(m) {
        cin >> l[i] >> r[i];
        if (r[i] < l[i]) swap(l[i], r[i]);
    }
    fori(m) if (!visited[i]) dfs(i, 0);
    fori(m) cout << "oi"[col[i]];
}