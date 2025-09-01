#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> g[n];
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
        }

        vector<int> dist(n, 1e9 + 1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbour: g[node]) {
                if (dist[neighbour] == 1e9 + 1) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            if (dist[i] & 1) odd.push_back(i + 1);
            else even.push_back(i + 1);
        }

        if (even.size() < odd.size()) {
            cout << even.size() << '\n';
            for (auto i: even) {
                cout << i << ' ';
            }
        } else {
            cout << odd.size() << '\n';
            for (auto i: odd) {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }
}