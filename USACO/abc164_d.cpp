#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    map<int,int> mp;
    int n = s.size();
    mp[0] = 1; 
    int pw = 1;
    ll ans = 0;
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = (cur + (int)(s[i] - '0') * pw % 2019) % 2019; 
        ans += mp[cur];
        pw = (pw * 10) % 2019;
        mp[cur]++;
    }
    cout << ans << '\n';
}
