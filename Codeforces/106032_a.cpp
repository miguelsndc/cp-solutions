#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int &i: A) {
        cin >> i;
        i = (i % K == 0);
    }
    vector<int> ps(N + 1);
    map<int,int> mp;
    for (int i = 0; i < N; i++) ps[i + 1] = ps[i] + A[i];
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        ll k = ps[i] % K;
        ans += mp[k];
        mp[k]++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}