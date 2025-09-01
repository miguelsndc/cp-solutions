#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a = {0}, b = {0};
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        b.emplace_back(x);
    }
    while (q--) {
        int d;
        cin >> d;
        int x = lower_bound(a.begin(), a.end(), d) - a.begin();
        if (a[x] == d) {
            cout << b[x] << ' ';
            continue;
        }
        x--;
        ll delta_a = a[x + 1] - a[x];
        ll delta_b = b[x + 1] - b[x];
        ll delta_d = d - a[x];
        ll time = b[x] + (delta_d * delta_b) / delta_a;
        cout << time << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}