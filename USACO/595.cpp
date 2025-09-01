#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n; cin >> n;
    vector<int> first(7, -1);
    first[0] = 0;
    int sum = 0, ans = 0;
    for (int i =0; i < n; i++) {
        int x; cin >> x;
        sum = (sum + x) % 7;
        if (first[sum] == -1) first[sum] = i;
        else {
            ans = max(ans, i - first[sum]);
        }
    }
    cout << ans << '\n';
}
