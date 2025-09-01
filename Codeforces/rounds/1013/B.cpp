#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int n, x; cin >> n >> x;
    vector<i64> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(rbegin(v), rend(v));
    i64 ps = 0, sz = 0, cnt = 0, mint = INT64_MAX;
    for (i64 i: v) {
        sz += 1;
        mint = min(mint, i);
        if (sz * mint >= x) {
            cnt ++;
            sz = 0;
            mint = INT64_MAX;
        }
    }
    cout << cnt << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    sort and the minimum is always the leftmost element
    */

   int tt; cin >> tt;
   while(tt--) {
    solve();
   }
}