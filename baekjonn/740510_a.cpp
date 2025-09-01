#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, K, C; cin >> N >> K >> C;
    vector<int> t(N), s(N), p(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> s[i];
    }
    vector<int> cnt(N + 1), goes(N + 1);
    int m = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[s[i]] < C and m < K) {
            goes[t[i]] = 1;
            cnt[s[i]]++;
            m++;
        }
    }
    for (int i = 0; i < N and m < K; i++) {
        if (!goes[t[i]]) {
            goes[t[i]] = 1;
            m++;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (goes[t[i]]) {
            cout << t[i] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}