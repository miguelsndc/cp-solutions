#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

// Assign each node a team where adjacent nodes must be in different teams
// when it doesn't have a solution ?
// 1---2
//  \ /
//   3
// when there's a cycle, we can't assign teams to the nodes.
// bipartite problem
// O(V + E) Complexity

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vi color(n + 1, -1);
    queue<int> q;
    color[1] = 1;
    q.push(1);
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;

        if (q.empty()) {
            q.push(i);
            color[i] = 1;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : graph[v]) {
                if (color[u] == -1) {
                    color[u] = color[v] == 1 ? 2 : 1;
                    q.push(u);
                } else if (color[u] == color[v]) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) color[i] = 1;  // isolated node (i guess)
        cout << color[i] spe;
    }

    return 0;
}
