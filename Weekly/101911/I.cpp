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
    vector<int> v(n);
    for(int &x: v) cin >> x;
    sort(all(v));
    int k = v[0], cnt = 0;
    for (int i = 1; i < n; i++) {
        int diff = v[i] - k;
        if (v[i] - k != 1) {
            cnt += v[i] - k - 1;
        }
        k = v[i];
    }
    cout << cnt << '\n';
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