#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e2 + 5;

void solve() {
    int n; cin >> n;
    string s = "2";
    string m; cin >> m;
    s += m;

    vector<i64> cost(n + 1, INT_MAX);
    cost[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            for (int j = i; j <= n; j += i) {
                if (s[j] == '0') {
                    cost[j] = min(cost[j], i*1LL);
                } else {
                    break;
                }
            }
        } else {
            cost[i] = 0;
        }
    }
    cout << accumulate(all(cost), 0LL) << '\n';
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