#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> got(n + 2, 0);  // até n+1 por segurança
    for (int &x : a) {
        cin >> x;
        got[x] = 1;
    }

    int m = 0;
    while (got[m]) m++;

    sort(all(a));
    vector<int> b = a;
    b.erase(unique(all(b)), b.end());

    vector<int> sweep(n + 2);
    sweep[0] = 1;
    for (int mex = n; mex >= 0; mex--) {
        int qntdmaior = n - (lower_bound(all(a), mex) - a.begin());
        int dist = lower_bound(all(b), mex) - b.begin();
        int repmenor = n - qntdmaior - dist;

        sweep[qntdmaior]++;
        sweep[qntdmaior + repmenor + 1]--;
    }

    for (int i = 0; i <= n; i++) {
        sweep[i + 1] += sweep[i];
    }

    for (int i = 0; i <= n; ++i) cout << sweep[i] << ' ';
    cout << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}