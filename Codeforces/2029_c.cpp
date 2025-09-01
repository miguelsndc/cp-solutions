#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<i64> v(n);
    int ev = 0, od = 0;
    for (i64 &x: v) {
        cin >> x;
        if (x & 1) od++;
        else ev++;
    }
    if (od == 0 || ev == 0) {
        cout << *max_element(all(v)) << '\n';
        return;
    } 

    i64 sum = 0;
    for (i64 x: v) {
        sum += x;
    }
    cout << sum - od + 1 << '\n';
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