#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) {
        par.assign(n, 0);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
        sz[x_root] += sz[y_root];
        par[y_root] = x_root;
        return true;  // (some condition met for component);
    }
};
void solve() {
    int N;
    cin >> N;
    vector A(N, vector<int>(N)), B(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ok &= (B[i][j] == A[i][j]);
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    vector include(N, vector<int>(N, true));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool precisa = true;
            for (int k = 0; k < N; k++) {
                if (k == i || k == j) continue;
                if (B[i][j] == B[i][k] + B[k][j]) {
                    precisa = false;
                    break;
                }
            }
            if (!precisa) include[i][j] = include[j][i] = false;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (include[i][j]) {
                ans += B[i][j];
                include[i][j] = include[j][i] = false;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    int T = 1;  // cin >> T;
    while (T--) solve();
}