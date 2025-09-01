#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for (int l = 0; l < N; l++) {
        vector<int> z = z_function(S.substr(l));
        int mx = 0;
        for (int i = 0; i < z.size(); i++) {
            mx = max(mx, min(z[i], i));
        }
        ans = max(ans, mx);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}