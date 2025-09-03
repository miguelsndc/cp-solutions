#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const ll neginf = -1e18; 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll mx = neginf, fav = neginf, ans = neginf;
    for (int i = 0; i < n; ++i) {
        if (mx == neginf) {
            mx = a[i];
        } else {
            mx = max(a[i], mx + a[i]);
        }
        if (b[i] == 1) {
            fav = mx;
        } else if (fav != neginf) {
            fav = fav + a[i];
        }
        if (fav != neginf) {
            ans = max(ans, fav);
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; 
    while(T--) solve();
    return 0;
}