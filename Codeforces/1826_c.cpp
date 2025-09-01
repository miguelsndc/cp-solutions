#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

/*
    entre todos os divisores de n <= m entro nele na recursao
*/

int n, ok = true;
void dfs(int m) {
    if (n % m == 0 and m != 1) {
        ok = false;
        return;
    }
    if (m == 1) return;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 and i <= m) {
            dfs(i);
            if ((n / i) != i and (n / i) <= m) dfs(n / i);
        }
    }
}

void solve() {
    ok = true;
    int m;
    cin >> n >> m;
    dfs(m);
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}