#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = (S[i] - '0') * (i + 1);
    }
    for (int i = 1; i < N; i++) A[i] += A[i - 1];
    ll c = 0;
    vector<ll> ans;
    for (int i = 0; (i < N or c > 0); i++) {
        if (i < N) {
            c += A[N - i - 1];
        }
        ans.push_back(c % 10);
        c /= 10;
    }
    reverse(all(ans));
    for (int x: ans) cout << x;
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}