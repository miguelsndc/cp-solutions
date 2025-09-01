#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve(int n, int m) {
    vector<int> g[n];
    vector<int> in(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        in[b]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    
    int idx = 0;
    vector<int> order(n);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        order[idx++] = node;
        for (int v: g[node]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (idx == n) {
        for (int c: order) {
            cout << c + 1 << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while((cin >> n >> m) && n && m) {
        solve(n, m);
    }
}