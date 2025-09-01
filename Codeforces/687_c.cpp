#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int f[2][505][505];
    memset(f,0,sizeof f);
    f[0][0][0]=1;
    for (int i = 1; i <= n; i++) {
        int now = i % 2;
        int last = 1 - now;
        int x = a[i];
        for (int j = 0; j <= k; j++) {
            for (int y = 0; y <= j; y++) {
                f[now][j][y] = f[last][j][y];
                if (j >= x) {
                    f[now][j][y] |= f[last][j - x][y];
                    if (y >= x)
                        f[now][j][y] |= f[last][j - x][y - x];
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; i++) {
        if (f[n % 2][k][i]) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}