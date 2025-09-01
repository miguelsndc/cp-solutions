#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int grid[105][105], visited[105][105];
int n, m, rh, ch, rw, cw;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<int> subset;

int bfs() {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    q.push({rh, ch});
    visited[rh][ch] = true;

    if (find(begin(subset), end(subset), grid[rh][ch]) == end(subset)) {
        return false;
    }

    bool found = false;

    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == rw && x == cw) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > m || visited[ny][nx]) continue;

            if (find(begin(subset), end(subset), grid[ny][nx]) != end(subset)) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    return found;
}

void solve() {
    cin >> n >> m;
    cin >> rh >> ch >> rw >> cw;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 10;
    for (int i = 1; i <= (1 << 10); i++) {
        for (int j = 0; j < 10; j++) {
            int bit = i & (1 << j);
            if (bit) subset.push_back(j + 1);
        }
        if (bfs()) ans = min(ans, (int)subset.size());
        subset.clear();
    }
    cout << ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}