#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxsize = 1e3 + 5;
const int maxn = 1e5 + 5;

int grid[maxsize][maxsize], ans[maxn], x[maxn], y[maxn], query[maxn], cnt = 0, mark[maxn];
vector<int> versions[maxn];

int n, m, q; 
void dfs(int index) {
    if (query[index] == 1) {
        if (!grid[x[index]][y[index]]) {
            mark[index] = 1;
            grid[x[index]][y[index]] = 1;
            cnt++;
        }
        ans[index] = cnt;
    }
    else if (query[index] == 2) {
        if (grid[x[index]][y[index]]) {
            mark[index] = 1,
            grid[x[index]][y[index]] = 0;
            cnt--;
        }
        ans[index] = cnt;
    }
    else if (query[index] == 3) {
        for (int i = 1; i <= m; i++) {
            if (grid[x[index]][i]) {
                grid[x[index]][i] = 0, cnt--;
            } else {
                grid[x[index]][i] = 1, cnt++;
            }
        }
        ans[index] = cnt;
    }
    else if (query[index] == 4) {
        ans[index] = ans[x[index]];
    }
    for (int i = 0; i < versions[index].size(); i++) {
        dfs(versions[index][i]);
    }

    if (query[index] == 1) {
        if (grid[x[index]][y[index]] && mark[index]) {
            grid[x[index]][y[index]] = 0;
            cnt--;
        }
    }
    else if (query[index] == 2) {
        if (!grid[x[index]][y[index]] && mark[index]) {
            grid[x[index]][y[index]] = 1;
            cnt++;
        }
    }
    else if (query[index] == 3) {
        for (int i = 1; i <= m; i++) {
            if (grid[x[index]][i]) {
                grid[x[index]][i] = 0, cnt--;
            } else {
                grid[x[index]][i] = 1, cnt++;
            }
        }
    }
}

void solve() {
    memset(grid, 0, sizeof grid);
    cin >> n >> m >> q;
    query[0] = 0;
    for (int i = 1; i <= q; i++) {
        cin >> query[i] >> x[i];
        if (query[i] == 4) {
            versions[x[i]].push_back(i);
            continue;
        } 
        else if (query[i] == 1 || query[i] == 2) {
            cin >> y[i];
        }
        versions[i - 1].push_back(i);
    }

    dfs(0);
    for(int i = 1;i <= q;i++) cout << (ans[i]) << '\n';
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