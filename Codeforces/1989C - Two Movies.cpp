#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // maximize the min - bs
    int m1 = 0, m2 = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {m1 += a[i]; continue;}
        else if (b[i] > a[i]) {m2 += b[i]; continue;}
        else if((a[i] == b[i]) and a[i] == 1) x++;
        else if ((a[i] == b[i]) and a[i] == -1) y++;
    }
    while(x--) {
        if (m1 < m2) m1++;
        else m2++;
    }

    while(y--) {
        if (m1 > m2) m1--;
        else m2--;
    }

    cout << min(m1, m2) << '\n';
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