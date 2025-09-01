#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n,m;
bool isvalid(int r,int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

vector<string> grid(1001);

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while((cin>>n>>m)) {
        rep(i,0,n) cin >> grid[i];
        rep(i,0,n){
            rep(j,0,m){
                ll cnt =0;
                if (grid[i][j] == 'S') {
                    queue<ii> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [r,c]=q.front();q.pop();
                        bool trap = false;
                        rep(k,0,4) {
                            int nr = r + dy[k];
                            int nc = c + dx[k];
                            if (isvalid(nr,nc) && grid[nr][nc] == 'T') {
                                trap =true;break;
                            }
                        }
                        if (trap)continue;
                        rep(k,0,4) {
                            int nr = r + dy[k];
                            int nc = c + dx[k];
                            if (isvalid(nr,nc) && grid[nr][nc] != '#'){
                                if(grid[nr][nc] >= '0' && grid[nr][nc] <= '9') {
                                    cnt += grid[nr][nc] - '0';
                                }
                                grid[nr][nc] = '#';
                                q.push({nr,nc});
                            }
                        }
                    }
                    cout << cnt << '\n';
                }
            }
        }
    }
}