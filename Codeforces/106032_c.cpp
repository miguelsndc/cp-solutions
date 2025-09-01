#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    string s; cin >> s;
    auto get = [&] (int i) { return int(s[i] - 'a') + 1; };
    vector<int> ps(N + 1);
    for (int i = 0; i < N; i++) ps[i + 1] = ps[i] + get(i); 
    auto faz = [&] (int mx) -> int {
        int l = 0, ans = 0;
        for (int r = 0; r < N; r++) {
            if (get(r) > mx) {
                l = r + 1;
                continue;
            }

            while(l <= r and ps[r + 1] - ps[l] < (r - l + 1) * mx) l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    };
    int ans = 0;
    for (int i = 1; i <= 26; i++) {
        ans = max(ans, faz(i));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}