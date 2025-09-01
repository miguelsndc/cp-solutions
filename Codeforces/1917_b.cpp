#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    ll ans = 0;
    for (int i = 0;i < n; i++)  {
        st.insert(s[i]);
        ans += st.size();
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}