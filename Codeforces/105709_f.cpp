#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> b(n), w(n), v(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    const int mxn = 1e5 + 10;
    vector<ll> sweep(mxn);
    for (int i = 0; i < n; i++) {
        if (b[i] > (k - w[i])) continue;
        sweep[b[i]] += v[i]; sweep[k - w[i] + 1] -= v[i];
    } 
    for (int i = 1; i < mxn; i++) {
        sweep[i] += sweep[i - 1];
    }
    cout << *max_element(sweep.begin(), sweep.end());
}