#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.rbegin(), a.rend());
    ll cost = 0;
    for (int i = 0; i + 1 < n; i+=2) {
        cost += max(a[i], a[i + 1]);
        ll m = min(a[i], a[i + 1]);
        a[i] -= m;
        a[i + 1] -= m;
    }
    if (n & 1) {
        cost += a.back();
    }

    cout << cost << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}