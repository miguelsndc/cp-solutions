#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int cycle = false;

void answer(int node, stack<int> &path) {
    cycle = true;
    vi p = {node};
    while (!path.empty()) {
        p.push_back(path.top());
        if (path.top() == node) {
            break;
        }
        path.pop();
    }
    reverse(p.begin(), p.end());
    cout << p.size() << '\n';
    for (int c : p) {
        cout << c + 1 spe;
    }
};

void dfs(int node, int parent, stack<int> &path, vector<vi> &g, vs &colors) {
    if (cycle) return;
    path.push(node);
    colors[node] = "gray";
    for (auto adj : g[node]) {
        if (colors[adj] == "white") {
            dfs(adj, node, path, g, colors);
        } else if (colors[adj] == "gray") {
            if (!cycle) {
                return answer(adj, path);
            }
        }
    }
    path.pop();
    colors[node] = "black";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, from, to;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        g[--from].push_back(--to);
    }

    vs colors(n);
    stack<int> path;

    for (int i = 0; i < n; i++) {
        colors[i] = "white";
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == "white") {
            dfs(i, -1, path, g, colors);
        }
    }

    if (!cycle) {
        cout << "IMPOSSIBLE";
    }

    return 0;
}