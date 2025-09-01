#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
gp_hash_table<pair<int,int>, ll, pair_hash> mp2;
gp_hash_table<pair<int,int>,ll, pair_hash> mp;
void solve() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int vx = x[j] - x[i];
            int vy = y[j] - y[i];
            int g = __gcd(vx, vy);
            vx /= g;
            vy /= g;
            if (vx < 0 or (vx == 0 and vy < 0)) {
                vx = -vx;
                vy = -vy;
            }
            mp[{vx,vy}]++;
            mp2[{x[i]+x[j], y[i]+y[j]}]++;
        }
    }
    ll ans = 0;
    for (auto [v, freq] : mp) {
        ans += freq * (freq - 1) / 2;
    }
    for (auto [v, freq]: mp2) {
        ans -= freq * (freq - 1) / 2;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}