#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (k >= 3) {
        cout << 0 << '\n';
        return;
    }
    sort(begin(v), end(v));
    i64 curr_min = v[0];

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                curr_min = min(curr_min, abs(v[i] - v[j]));
            }
        }
        cout << curr_min << '\n';
        return;
    }

    /*
        k = 2 escolhe um par e adiciona a diferença dps escolho outro par e adiciona a diferença
        testar todos os primeiros pares e pegar a diferença, dps testa com os elements do array
    */

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            i64 diff = abs(v[i] - v[j]);
            i64 p = lower_bound(begin(v), end(v), diff) - begin(v);
            if (p >= v.size()) p--;
            i64 sec = (p > 0) ? p - 1: p;
            i64 m1 = min(abs(diff - v[p]), abs(diff - v[sec]));
            curr_min = min(curr_min, min(diff, m1));
        }    
    }
    
    cout << curr_min << "\n";
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