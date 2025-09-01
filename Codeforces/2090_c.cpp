#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

i64 d(int x, int y) {
    int a = (x%3) == (y%3);
    return x + y + 2 * (a == 2);
}

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    min_heap<array<i64,3>> pq;
    i64 x = 1, y = 1, dis = 2;
    int n; cin >> n;
    vector<pair<i64, i64>> ans(n);
    for (i64 i = 0, xx; i < n; i++) {
        cin >> xx;
        if (xx && pq.size() and (pq.top()[0]) < dis) {
            auto [a, b, c] = pq.top(); pq.pop();
            ans[i] = {b, c};
        } else {
            ans[i] = {x, y};
            pq.push({x + y + 1, x + 1, y});
            pq.push({x + y + 1, x, y + 1});
            pq.push({x + y + 4, x + 1, y + 1});
            if (y == 1) swap(x, y), y += 3;
            else x += 3, y -= 3;
            dis = x + y;
        }
    }
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n'; 
    }
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