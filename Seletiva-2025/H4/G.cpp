#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009


void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    int cc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                cc++;
                queue<array<int, 2>> q;
                q.push({i, j});
                s[i][j] = '.';
                while(!q.empty()) {
                    auto [row, col] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nrow = row + dy[i];
                        int ncol = col + dx[i];
                        if (nrow >= 0 && nrow < n && ncol < m && ncol >= 0 && s[nrow][ncol] == '#') {
                            s[nrow][ncol] = '.';
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }
    cout << cc;
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