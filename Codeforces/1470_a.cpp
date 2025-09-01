#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> f(n), p(m);
        for (int &x:f)cin>>x, --x;
        for (int &x:p)cin>>x;
        sort(f.begin(), f.end());
        multiset<int> ms;
        for (int x: p) ms.insert(x);
        ll cost = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = *ms.begin();
            if (x < p[f[i]]) {
                cost += x;
                ms.erase(ms.begin());
            } else {
                cost += p[f[i]];
            }
        }
        cout << cost << '\n';
    }
}