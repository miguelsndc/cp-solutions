#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int wins(int c, int d) {
    if (c == 0) return d == 2;
    if (c == 2) return d == 1;
    return d == 0;
}

int solve() {
    int n; cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int pre[n+1][3], suf[n+1][3];
    memset(pre, 0, sizeof pre);
    memset(suf, 0, sizeof suf);
    vector<int> p(256); 
    p['H'] = 0;
    p['P'] = 1;
    p['S'] = 2;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            pre[i + 1][j] = pre[i][j] + wins(j, p[a[i]]);
        }
    }
    for (int j = 0; j < 3; j++) {
        for (int i = n - 1; i >= 0; i--) {
            suf[i][j] = suf[i + 1][j] + wins(j, p[a[i]]);
        }
    }

    int ans = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i <= n; i++) {
                int qntd = pre[i][j] + suf[i][k];
                ans = max(ans, qntd);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef DEBUG
        freopen("hps.in", "r", stdin);
        freopen("hps.out", "w", stdout);
    #endif
    int tt = 1; // cin >> tt;
    for (int i = 1; i <= tt; i++) {
        if(solve()) break;
        #ifdef DEBUG
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef DEBUG
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
