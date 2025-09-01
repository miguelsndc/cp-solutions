#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int n; cin >> n;
    map<int ,vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        if ((*it).second.size() == 1) {
            cout << (*it).second[0];
            exit(0);
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}