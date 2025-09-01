#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 8;
const int MAXM = 64;
void mat_mul(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < m; k++) {
                sum ^= (A[i][k] & B[k][j]);
            }
            C[i][j] = sum;
        }
    }
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    vector pos_idx(N, vector<int>(N, -1));
    vector<pair<int, int>> cells;
    int M = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '#') {
                pos_idx[i][j] = M++;
                cells.push_back({i, j});
            }
        }
    }
    if (M == 0 || K == 0) {
        for (int i = 0; i < N; i++) cout << grid[i] << '\n';
        return;
    }
    vector<vector<int>> transformacao(M, vector<int>(M, 0));
    vector<int> di = {-1, -1, -1, 0, 0, 1, 1, 1}, dj = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int p = 0; p < M; p++) {
        auto [x, y] = cells[p];
        transformacao[p][p] = 1;
        for (int d = 0; d < 8; d++) {
            int nx = x + di[d], ny = y + dj[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int q = pos_idx[nx][ny];
                if (q != -1) transformacao[p][q] = 1;
            }
        }
    }
    vector<int> current(M, 0);
    for (int p = 0; p < M; p++) {
        auto [x, y] = cells[p];
        current[p] = (grid[x][y] == '1') ? 1 : 0;
    }
    vector agora(M, vector<int>(M, 0)), temp(M, vector<int>(M, 0)), base = transformacao;
    for (int i = 0; i < M; i++) agora[i][i] = 1;
    while (K > 0) {
        if (K & 1) {
            mat_mul(agora, base, temp, M);
            agora = temp;
        }
        mat_mul(base, base, temp, M);
        base = temp;
        K >>= 1;
    }
    vector<int> ans1(M, 0);
    for (int p = 0; p < M; p++) {
        int val = 0;
        for (int j = 0; j < M; j++) {
            val ^= (agora[p][j] & current[j]);
        }
        ans1[p] = val;
    }
    vector<string> ans_agora = grid;
    for (int p = 0; p < M; p++) {
        auto [x, y] = cells[p];
        ans_agora[x][y] = ans1[p] ? '1' : '0';
    }
    for (int i = 0; i < N; i++) cout << ans_agora[i] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}