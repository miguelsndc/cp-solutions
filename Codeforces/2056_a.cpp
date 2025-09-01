#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    pair<int, int> a[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }

    ll perim = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            perim += 4 * M;
            continue;
        }

        int x = a[i].first;
        int y = a[i].second;

        perim += 4 * M;
        perim = perim - (2 * (M - x) + 2 * (M - y));
    }
    cout << perim << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}