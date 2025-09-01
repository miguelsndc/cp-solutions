#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pos;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos.push_back(x);
        a[x]++;
    }
      vector<int> pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + a[i];
    
    int escape = 1e9;
    for (int p: pos) {
        escape = min(escape, max(p, n - p));
    }
    while(q--) {
        int t; cin >> t;
        int x = pre[min(t,n)];  
        int y = suf[max(n - t,1)];
        if (t >= escape) {
            cout << -1 << '\n';
        } else {
            cout << x + y << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}