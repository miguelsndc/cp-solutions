#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool dfs(int i, vector<int> *g, vector<int> &color, int curr_color) {
    color[i] = curr_color;

    for (int neighbour: g[i]) {
        int c = 3 - curr_color;
        if (color[neighbour] == -1) {
            if (!dfs(neighbour, g, color, c)) {
                return false;
            }
        } else if (color[neighbour] == color[i]) {
            return false;
        }
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> color(n + 1, -1);
    bool possible = true;
    for (int i = 1;i <= n; i++) {
        if (color[i] == -1) {
            possible = dfs(i, g, color, 1);
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << ' ';
        }
    }
}