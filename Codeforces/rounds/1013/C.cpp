#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}