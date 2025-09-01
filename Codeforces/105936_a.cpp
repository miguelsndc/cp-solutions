#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void minha(int N) {
    vector<int> res(N + 1, 0);
    priority_queue<tuple<int, int, int, int>> pq;  // {D, -P, L, R}

    res[1] = 1;
    if (N > 1) {
        res[N] = 2;
        int L = 1, R = N, P = (L + R) / 2, D = min(P - L, R - P);
        pq.push({D, -P, L, R});
    }

    for (int fan = 3; fan <= N; fan++) {
        auto [D, neg_P, L, R] = pq.top();
        pq.pop();
        int P = -neg_P;
        res[P] = fan;

        if (P - L > 1) {
            int new_L = L, new_R = P, new_P = (new_L + new_R) / 2, new_D = min(new_P - new_L, new_R - new_P);
            pq.push({new_D, -new_P, new_L, new_R});
        }

        if (R - P > 1) {
            int new_L = P, new_R = R, new_P = (new_L + new_R) / 2, new_D = min(new_P - new_L, new_R - new_P);
            pq.push({new_D, -new_P, new_L, new_R});
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << (i < N ? " " : "\n");
    }
}

void solve() {
    int n;
    cin >> n;
    minha(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}