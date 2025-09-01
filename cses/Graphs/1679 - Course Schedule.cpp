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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, from, to;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        adj[--from].push_back(--to);
    }

    vi ordering(n);
    vi in_degree(n);
    // calculate in-degrees of each node
    for (int i = 0; i < n; i++) {
        for (int to : adj[i]) {
            in_degree[to]++;
        }
    }

    // queue of nodes with degree zero
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int index = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ordering[index++] = node;
        for (auto to : adj[node]) {
            in_degree[to]--;
            if (in_degree[to] == 0) {
                q.push(to);
            }
        }
    }

    if (index != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int p : ordering) {
        cout << p + 1 spe;
    }

    return 0;
}