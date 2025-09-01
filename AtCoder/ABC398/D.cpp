#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int n, r, c; cin >> n >> r >> c;
    pair<int, int> tak_pos = {r, c};
    pair<int, int> fire_pos = {0, 0};
    string s; cin >> s;
    set<pair<int, int>> st;
    st.insert(fire_pos);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            tak_pos.first += 1;
            fire_pos.first += 1;
        }
        if (s[i] == 'S') {
            tak_pos.first -= 1;
            fire_pos.first -= 1;
        }
        if (s[i] == 'E') {
            tak_pos.second -= 1;
            fire_pos.second -= 1;
        }
        if (s[i] == 'W') {
            tak_pos.second += 1;
            fire_pos.second += 1;
        }

        st.insert(fire_pos);
        if (st.count(tak_pos) > 0) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}