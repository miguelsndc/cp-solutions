#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ll w = a.back(), b = a[n - 2];
    priority_queue<ll> pq;
    for (int i = 0; i < n - 2; i++) {
        pq.push(a[i]);
    }
    while(!pq.empty()) {
        ll big = pq.top();
        b -= big;
        pq.pop();
    }

    cout << w - b << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}