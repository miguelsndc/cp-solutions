#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    vector<ll> pre(N + 1);
    for (int i = 0; i < N; i++) pre[i + 1] = pre[i] + A[i];
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        int index = lower_bound(pre.begin(), pre.end(), q) - pre.begin();
        if (index == pre.size()) {
            cout << -1 << '\n';
        } else {
            cout << index << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}