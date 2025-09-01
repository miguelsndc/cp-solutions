#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> g[n];
    for (int i = 0; i < n - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[--a].push_back({--b, w});
        g[b].push_back({a, w});
    }

    vector<int> visited(n);
    vector<int> coloring(n);

    coloring[0] = 0;
    visited[0] = true;
    queue<array<int, 2>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [to, acc_dist] = q.front();
        q.pop();
        coloring[to] = (acc_dist% 2) == 0;
        for (auto neighbour: g[to]) {
            auto [to2, weight] = neighbour;
            if (!visited[to2]) {
                visited[to2] = true;
                q.push({to2, acc_dist + weight});
            }
        }
    }
    for (int i: coloring) {
        cout << i << '\n';
    }
}