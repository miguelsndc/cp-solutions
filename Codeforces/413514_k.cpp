#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (count(all(v), 1) < s) {
        cout << -1 << "\n";
        return;
    }

    map<int,int> mp;
    mp[0] = -1;
    int cur = 0, maxs = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        if (mp.count(cur - s)) {
            maxs = max(maxs, i - mp[cur - s]);
        } 
        if (!mp.count(cur)) {
            mp[cur] = i;
        }
    }
    cout << n - maxs << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}