#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cost_f(vector<ll> &a, vector<ll> &b) {
    ll c1 = 0, c2 = 0;
    for (int x : a) {
    }
}
void solve() {
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int,int>> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i].first;
        r[i].second = i + 1;
    }
    sort(r.rbegin(), r.rend());
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int j = r[i].first;
        if ((a.size() + 1) * s1 < (b.size() + 1) * s2) {
            a.push_back(r[i].second);
        } else {
            b.push_back(r[i].second);
        }
    }

    cout << a.size() << ' ';
    for (int x : a) cout << x << ' ';
    cout << '\n';
    cout << b.size() << ' ';
    for (int x : b) cout << x << ' ';
    cout << "\n\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}