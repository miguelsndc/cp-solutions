#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {cout << "Yes\n";return;}
    vector<i64> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    vector<i64> diff(k - 1);
    for (int i = 0; i + 1 < k; i++) {
        diff[i] = v[i + 1] - v[i];
    }
    if (!diff.empty() and !is_sorted(all(diff))) {
        cout << "No\n";
        return;
    }
    if (v[0] > (diff[0] * (n - k + 1))) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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