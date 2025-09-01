#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int t; cin >> t;
    int c; cin >> c;
    int n; cin >> n;
    vector<int> stick_pat(n);
    for (int &x: stick_pat) cin >> x;
    int b, m; cin >> b >> m;
    vector<int> brick_inc(m);
    for(int &x: brick_inc) cin >> x;

    // pega tijolo ate q o custo do tijolo seja maior q 3 * custo do straw
    // se nao é melhor só pegar 3 straw
    vector<pair<int, int>> combined;
    int brick_cost = b;
    int brick_idx = 0;
    while(brick_cost < 3 * c and combined.size() <= t) {
        combined.emplace_back(brick_cost, 3);
        brick_cost += brick_inc[brick_idx++];
        brick_idx %= m;
    }
    combined.emplace_back(c, 1);

    // prefix sum dos sticks 
    vector<int> stick_costs;
    int stick_idx = 0; int sum = 0;
    while (sum <= t and stick_costs.size() <= t) {
        int cost = stick_pat[stick_idx];
        if (sum + cost > t) break;
        stick_costs.push_back(cost);
        sum += cost;
        stick_idx++; stick_idx %= n;
    }
    int stick_len = stick_costs.size();
    vector<int> stick_sum(stick_len + 1, 0);
    vector<int> stick_def(stick_len + 1, 0);
    for (int i = 0; i < stick_len; i++) {
        stick_sum[i + 1] = stick_sum[i] + stick_costs[i];
        stick_def[i + 1] = stick_def[i] + 2;
    }

    // prefix sum dos combined
    int comb_len = combined.size();
    vector<int> comb_sum(comb_len + 1, 0);
    vector<int> comb_def(comb_len + 1, 0);
    for (int j = 0; j < comb_len; j++) {
        comb_sum[j + 1] = comb_sum[j] + combined[j].first;
        comb_def[j + 1] = comb_def[j] + combined[j].second;
    }

    // testa pra cada stick a melho rcombinação de straw/brick
    int ans = 0;
    int j_max = comb_len;
    for (int i = 0; i <= stick_len; i++) {
        int time_used = stick_sum[i];
        int def = stick_def[i];
        if (time_used > t) break;
        int time_left = t - time_used;
        int j = 0;
        // pega de combined ate n dar mais
        while(j < j_max && comb_sum[j + 1] <= time_left) j++;
        def += comb_def[j];
        time_left -= comb_sum[j];
        // maximo entre ans e def
        if (time_left >= 0) {
            def += time_left/ c;
            ans = max(ans, def);
        }
    }

    cout << ans;
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