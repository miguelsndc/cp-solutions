#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    i64 t1 = inf, t2 = inf, cnt = 0;
    for (int i = 0; i < n; i++){
        if (t1 > t2) swap(t1, t2); // t1 is the back of the smallest array
        if (v[i] <= t1) { // smaller or equal the smallest then add there, no penalty
            t1 = v[i];
        } else if (v[i] <= t2) { // if greater than the sammlest but smaller then the other jsut add there, no penalty
            t2 = v[i];
        } else {
            t1 = v[i]; // otherwise it is larger than both and theres nothing we can do, put it in t1 to increase smallest element.
            cnt++;
        }
    }
    cout << cnt << '\n';
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