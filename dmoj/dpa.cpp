#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<int> h(N);
    for (int &i: h) cin >> i;
    const int inf = 1e9 + 1;
    vector<int> dp(N, inf);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 < N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        } 
        if (i + 2 < N) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }
    cout << dp[N - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}