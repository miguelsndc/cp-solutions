#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    // maximal odd sum
    int n;
    cin >> n;
    vector<int> a(n);
    int minodd = 1e9, sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1) minodd = min(minodd, x);
        sum += x;
    }
    if (sum % 2 == 0) {
        cout << max(sum - minodd, 0) << '\n';
    } else {
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}