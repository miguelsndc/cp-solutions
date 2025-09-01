#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 20 + 5;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(N));
    vector<int> pw(2 * N - 1);
    pw[0] = 1;
    for (int i = 1; i < 2 * N - 1; i++) {
        pw[i] = 10LL * pw[i - 1] % M;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] = 1LL * A[i][j] * pw[2 * N - 2 - i - j] % M;
        }
    }

    vector<vector<int>> L(N), R(N);

    auto dfs1 = [&](auto&& self, int x, int y, int v) {
        v = (v + A[x][y]) % M;
        if (x + y == N - 1) {
            L[x].push_back(v);
            return;
        }
        self(self, x, y + 1, v);
        self(self, x + 1, y, v);
    };
    dfs1(dfs1, 0, 0, 0);

    auto dfs2 = [&](auto&& self, int x, int y, int v) {
        if (x + y == N - 1) {
            R[x].push_back(v);
            return;
        }
        v = (v + A[x][y]) % M;
        self(self, x, y - 1, v);
        self(self, x - 1, y, v);
    };
    dfs2(dfs2, N - 1, N - 1, 0);

    int ans = 0;
    for (int x = 0; x < N; x++) {
        sort(all(L[x]));
        sort(all(R[x]));
        ans = max(ans, (L[x].back() + R[x].back()) % M);
        for (int i = L[x].size() - 1, j = 0; i >= 0; i--) {
            while (j < R[x].size() && L[x][i] + R[x][j] < M) {
                ans = max(ans, L[x][i] + R[x][j]);
                j++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}