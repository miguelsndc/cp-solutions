#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        A[i] = (s[i] == '2');
    }
    int j = 0, cur = A[0], ans = cur <= K;
    for (int i = 0; i < N; i++) {
        while(j + 1 < N and cur + A[j + 1] <= K) {
            cur += A[++j];
            ans = max(ans, j - i + 1);
        }
        cur -= A[i];
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}