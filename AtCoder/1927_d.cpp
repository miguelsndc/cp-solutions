#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    vector<int> P(N, -1);
    for (int i = 0; i < N; i++) {
        P[i] = P[i - 1];
        if (A[i] != A[i - 1]) {
            P[i] = i - 1;
        }
    }
    int Q; cin >> Q;
    while(Q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        if (P[r] < l) {
            printf("%d %d\n", -1, -1);
        } else {
            printf("%d %d\n", P[r] + 1, r + 1);
        }
    }
}
int main() {
    int T = 1; cin >> T;
    while(T--) solve();
}