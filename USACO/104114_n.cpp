#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    int psmax = 0, sufmax = 0;
    for (int i = 0; i< n; i++) {
        psmax = max(psmax - m, a[i]);
        a[i] = psmax;
    }
    for (int i = n - 1; i >= 0; i--) {
        sufmax = max(sufmax - m, a[i]);
        a[i] = sufmax;
    }

    for (int x: a) cout << x << ' ';
}
