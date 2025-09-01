#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int &i: A) cin >> i;
    int M = *max_element(all(A));
    vector<int> s(M + 1), t(M + 1), u(M + 1);
    for (int i: A) s[i]++;
    for (int d = 1; d <= M; d++) {
        for (int n = d; n <= M; n += d) {
            // t[d] = numero de ocorrencias de multiplos de d
            t[d] += s[n];
        }
    }
    for (int d = 1; d <= M; d++) {
        // pelo menos k multiplos de d
        if (t[d] < k) continue;
        // passo pelos multiplos de d e vejo qual o maior (vai ser o gcd)
        for (int n = d; n <= M; n += d) {
            u[n] = max(u[n], d);
        }
    }
    for (int &i: A) cout << u[i] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}