#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

vector<int> g[100];
vector<bool> visited(100);
vector<vector<bool>> dom(100, vector<bool>(100));

void print_div(int n) {
    cout << '+';
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << '-';
    }
    cout << "+\n";
}

void bfs(int u, vector<int> & reachable, int x = -1) {
    queue<int> q; q.push(u);
    reachable[u] = true;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if (node != x) {
            for (int v: g[node]) {
                if (!reachable[v]) {
                    reachable[v] = true;
                    q.push(v);
                }
            }
        }   
    }
}

void solve() {
    for (int i = 0; i < 100; i++) {
        g[i].clear();
        visited[i] = false;
        for (int j = 0; j < 100; j++) {
            dom[i][j] = false;
        }
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) {
                g[i].push_back(j);
            }
        }
    }

    vector<int> reachable_start(100);
    bfs(0, reachable_start);

    for (int i = 0; i < n; i++) {
        vector<int> reachable(100);
        bfs(0, reachable, i);
        for (int j = 0; j < n; j++) {
            if (reachable_start[j] && (i == j || !reachable[j])) {
                dom[i][j] = true;
            }
        }
    }

    print_div(n);
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            if (dom[i][j]) cout << "Y";
            else cout << "N";
            cout << "|";
        }
        cout << '\n';
        print_div(n);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}