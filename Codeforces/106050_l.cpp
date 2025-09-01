#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, K, G; cin >> N >> K >> G;
    --G;
    int sum = 0;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    for (int i = 0; i < N; i++) {
        if (i != G) sum += A[i];
    }
    cout << max(K - sum, 0) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}