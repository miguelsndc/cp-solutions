#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N;
    cin >> N;

    string mat[N];
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }

    int p[N];
    iota(p, p + N, 0);
    sort(p, p + N, [&](int x, int y) {
        if (mat[x][y] == '1')
            return x < y;
        else
            return x > y;
    });

    for (auto i : p) cout << i + 1 << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}