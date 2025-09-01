#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N, Q;
    cin >> N >> Q;
    string a, b;
    cin >> a >> b;
    int freq_a[N + 1][26], freq_b[N + 1][26];
    memset(freq_a, 0, sizeof freq_a);
    memset(freq_b, 0, sizeof freq_b);
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < N; i++) {
            int cur = (int)(c - 'a');
            freq_a[i + 1][cur] = freq_a[i][cur] + (a[i] == c);
            freq_b[i + 1][cur] = freq_b[i][cur] + (b[i] == c);
        }
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int x = freq_a[r][i] - freq_a[l - 1][i];
            int y = freq_b[r][i] - freq_b[l - 1][i];
            ans += abs(x - y);
        }
        cout << ans / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}