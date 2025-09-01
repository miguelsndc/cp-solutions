#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
ll pega(multiset<int> &ms) {
    ll s = 0;
    vector<int> cur;
    if (ms.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            int x = *ms.rbegin();
            cur.push_back(x);
            s += x;
            ms.erase(ms.find(x));
        }
    }
    for (int x: cur) ms.insert(x);
    return s;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> a(n);
        multiset<int> ms;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ms.insert(x);
            a[i] = x;
        }
        ll ans = pega(ms) - (n - 1);
        int i = 0, j = n - 1;
        while ((j - i) >= 2) {
            if (a[i] > a[j]) {
                ms.erase(ms.find(a[j--]));
            } else {
                ms.erase(ms.find(a[i++]));
            }
            ans = max(ans, pega(ms) - (j - i));
        }
        cout << ans << '\n';
    }
}
