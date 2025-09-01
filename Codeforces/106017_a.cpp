#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), order;
    for (int &x: a) cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            order.push_back(a[i] + a[j]);
        }
    } 
    sort(order.begin(), order.end());
    cout << order[k - 1] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}