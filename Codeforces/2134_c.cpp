#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    ll ops = 0;
    if (A[1] > A[2]) {
        ops += (A[1] - A[2]);
        A[1] = A[2];
    }
    for (int i = 2; i <= N; i += 2) {
        ll dif = (A[i] - A[i - 1]);
        if (i + 1 <= N) dif -= A[i + 1];
        if (dif < 0) {
            ops -= dif;
            if (i + 1 <= N) {
                A[i + 1] = max(A[i + 1] + dif, 0ll);
            }
        }
    }
    cout << ops << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}