#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    if (N & 1) {
        cout << A[(N + 1) / 2] << '\n';
    } else {
        cout << fixed << setprecision(1)<< (long double)(1ll * A[N / 2] + A[N / 2 + 1] + .0) * 0.5;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}