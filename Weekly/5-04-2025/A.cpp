/*
assumindo q eu consigo saber quem ganha em complexidade <= O(log(vida))
da pra fazer em O(k)
pra i = 1..k a gente ve
se eu gastar i em vida e k - i em ataque eu consigo derrotar ? 
seria tipo
se derrota(hc + i, dc + k - i, hm, dc) sim() exit
nao() exit
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

bool defeats(i64 hc, i64 dc, i64 hm, i64 dm) {
    i64 dmg_m = (i64) ceil(1.0 * hc / dm);
    i64 dmg_c = (i64) ceil(1.0 * hm / dc);
    return dmg_c <= dmg_m;
}

void solve() {
    i64 hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (int i = 0; i <= k; i++) {
        if (defeats(hc + i * a, dc + (k - i) * w, hm, dm)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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