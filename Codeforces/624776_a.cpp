#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> delta(n);
    for (int i = 0; i < n; i++) delta[i] = a[i] - c[i];
    for (int i = 1; i < n; i++) delta[i] += delta[i - 1];
    for (int x: delta) cout << x << ' ';
}