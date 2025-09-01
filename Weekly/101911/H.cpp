#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    i64 x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    // is it possible to paviment if i break m tiles ?
    // solve around theather
    int lenx = x2 - x1 + 1;
    int leny = y2 - y1 + 1;
    
    int sq = 0;

    int up = x1 - 1;
    int down = n - x2;
    int right = m - y2;
    int left = y1 - 1;

    int rem = 0;
    if (up > 0 and (m & 1)) {
        sq += up;
    }

    if (down > 0 and (m & 1)) {
        sq += down;
    }

    if (right > 0 and right & 1) {
        sq += (lenx);
    }

    if (left > 0 and left & 1) {
        sq += (lenx);
    }

    cout << (sq + 1) / 2 << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}