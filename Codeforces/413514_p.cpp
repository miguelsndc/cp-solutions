#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n); 
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (g[j][i] == '*') {
                int k = j;
                while(k + 1 < n and g[k + 1][i] == '.') {
                    g[k][i] = '.';
                    g[k + 1][i] = '*';
                    k++;
                }
            }
        }
    }
    for (string s: g) {
        cout << s << '\n';
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}