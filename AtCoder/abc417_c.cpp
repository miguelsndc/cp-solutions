#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    map<int, ll> mp;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (mp.count(A[i] - i)) {
            ans += mp[A[i] - i];
        }
        mp[-A[i] - i]++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}