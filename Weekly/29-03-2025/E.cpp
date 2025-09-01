#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, queries; cin >> n >> queries;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    queue<pair<int, int>> q;
    vector<vector<i64>> dist(n, vector<i64>(n, inf));
    int dots = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 1;
            }
            else if (g[i][j] == '.') {
                dots++;
            }
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    auto valid = [&](int r, int c) {
        return r >= 0 and r < n and c >= 0 and c < n and g[r][c] != '#';
    };
    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newrow = row + dy[i];
            int newcol = col + dx[i];
            if (valid(newrow, newcol) and dist[newrow][newcol] > dist[row][col] + 1) {
                dist[newrow][newcol] = dist[row][col] + 1;
                q.push({newrow, newcol});
            }
        }
    }
    vector<i64> ans;
    int unreachable = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '.') {
                ans.push_back(dist[i][j]);
            }
        }
    }
    sort(begin(ans), end(ans));
    // qi = 3
    // 1 2 3 3 3 3 3 3 3 4
    while(queries--) {
        int x; cin >> x;
        int cnt = upper_bound(begin(ans), end(ans), x) - begin(ans);
        double res = max((1.0 * cnt) / (dots * 1.0), 0.0);
        cout << setprecision(20) << fixed << res << '\n';
    }
}