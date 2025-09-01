#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    sort(all(a));
    set<ll> s;
    do {
        ll num = 0, pw = 1;
        for (int i = n - 1; i >= 0; i--) {
            num += a[i] * pw;
            pw *= 10;
        }
        if (a[0] == 0) continue;
        if (num % 12 == 9) s.insert(num);
    } while(next_permutation(all(a)));
    cout << s.size() << '\n';
}
