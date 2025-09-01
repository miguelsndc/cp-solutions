#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, M; cin >> N >> M;
    ll K; cin >> K;
    vector<ll> products(N);
    for (ll &i: products) cin >> i;
    vector pares_ruins(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        pares_ruins[x][y] = pares_ruins[y][x] = true;
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> tem;
        ll sum = 0;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                tem.push_back(i);
                sum += products[i];
            }
            if (sum > K) {
                ok = false;
                break;
            }
        }
        for (int i = 0; i < tem.size() and ok; i++) 
            for (int j = i + 1; j < tem.size() and ok; j++) 
                ok &= !(pares_ruins[tem[i]][tem[j]]);

        if (ok) ans++;
    }

    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}