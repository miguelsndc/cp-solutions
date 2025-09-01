#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    ld eps = 1e-9;
    ld l = 0, r = 1.0 * *max_element(all(x));
    auto f = [&](ld m) -> ld {
        ld time = 0;
        for (int i = 0; i < n; i++) {
            time = max(time, fabsl(1.0 * x[i] - m) + 1.0 * t[i]);
        }
        return time;
    };
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;
        ld v1 = f(m1);
        ld v2 = f(m2);
        if (v1 < v2)
            r = m2;  
        else
            l = m1;  
    }
    cout << setprecision(20) << fixed << l << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}