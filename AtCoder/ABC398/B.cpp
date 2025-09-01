#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    vector<int> v(7);
    for (int i = 0; i < 7; i++) cin >> v[i];
    do {
        map<int, int> mp;
        for (int i = 0; i < 5; i++) {
            mp[v[i]]++;
        }
        bool three = false, two = false;
            for (auto [_, cnt]: mp) {
                if(cnt == 3) three = true;
                if (cnt == 2) two = true;
            }
        if (mp.size() == 2 and three and two) {
            cout << "Yes\n";
            exit(0);
        }
    } while(next_permutation(begin(v), end(v)));
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}