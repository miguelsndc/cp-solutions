#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<ii>
#define vd vector<double>
#define si set<int>
#define mii map<int, int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vs grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<pair<ii, int>> cops;
    enum pos {
        up, down, left, right
    };
    ii start, end;
    map<ii, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char v = grid[i][j];

            if (v == 'F') start = {i ,j};
            else if (v == 'H') end = {i, j};
            else if (v == '>') {
                cops.push_back({{i, j}, right});
                mp[{i ,j}] = true;
                }
            else if (v == '<') {
                cops.push_back({{i, j}, left});
                mp[{i ,j}] = true;
                }
            else if (v == '^') {
                cops.push_back({{i, j}, up});
                mp[{i ,j}] = true;
                }
            else if (v == 'v') {
                cops.push_back({{i, j}, down});
                mp[{i ,j}] = true;
                }
        }
    }

    auto iscop = [&grid, &mp](int i, int j) {
        return (grid[i][j] == '>' || grid[i][j] == '<' || grid[i][j] == '>' || grid[i][j] == 'v' || mp[{i, j}]);
    };

    for (const auto& [pos, dir]: cops) {
        auto [r, c] = pos;
        if (dir == down) {
            for (int cnt = 0; cnt <= d; cnt++) {
                if (r + cnt >= n || grid[r + cnt][c] == '#' || (iscop(r + cnt, c) && r + cnt != r)) {
                    break;
                }
                grid[r + cnt][c] = '$';
            }
        }
        if (dir == left) {
            for (int cnt = 0; cnt <= d; cnt++) {
                if (c - cnt < 0 || grid[r][c - cnt] == '#' || (iscop(r, c - cnt) && c - cnt != c)) {
                    break;
                }
                grid[r][c - cnt] = '$';
            }
        }
        if (dir == right) {
            for (int cnt = 0; cnt <= d; cnt++) {
                if (c + cnt >= m || grid[r][c + cnt] == '#' || (iscop(r, c + cnt) && c + cnt != c)) {
                    break;
                }
                grid[r][c + cnt] = '$';
            }
        }
        if (dir == up) {
            for (int cnt = 0; cnt <= d; cnt++) {
                if (r - cnt < 0 || grid[r - cnt][c] == '#' || (iscop(r - cnt, c) && r - cnt != r)) {
                    break;
                }
                grid[r - cnt][c] = '$';
            }
        }
    }

    auto is_valid = [&grid, &n, &m](int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '$' && grid[r][c] != '#');
    };

    if (grid[start.fi][start.se] == '$' || grid[end.fi][end.se] == '$') {
        cout << "NO\n";
        return;
    }

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    queue<ii> q;
    q.push({start.fi, start.se});
    grid[start.fi][start.se] = '$';
    bool can = false;
    while(!q.empty()) {
        if (can) break;
        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = row + dy[i];
            int nc = col + dx[i];
            if (is_valid(nr, nc)) {
                q.push({nr, nc});
                if (grid[nr][nc] == 'H') {
                    can = true;
                }
                grid[nr][nc] = '#';
            }
        }
    }
    cout << (can ? "YES\n" : "NO\n");
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}

