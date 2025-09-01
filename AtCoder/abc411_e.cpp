#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> g(n + 1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v, w});
    }
    vector<vector<int>> vis(n+1, vector<int>(1025));
    vis[1][0] = true;
    queue<pair<int,int>> q;
    q.push({1, 0});
    while(!q.empty()){
        auto[u, X]= q.front();q.pop();
        for (auto [v, w]: g[u]) {
            int newxor = X ^ w;
            if(!vis[v][newxor]) {
                vis[v][newxor]=true;
                q.push({v,newxor});
            }
        }
    }
    for (int i=0;i<=1024;i++){
        if(vis[n][i]){
            cout<<i<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}