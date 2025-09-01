#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // 2 3 4 5
    // 1 3 4 5
    // 1 3 4 4
    // 0 1 4 2
    // 0 0 4 0
    // 0 0 4 0
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll k;
        cin >> n >> k;
        deque<ll> dq(n);
        for (int i = 0; i < n; ++i) {
            cin >> dq[i];
        }
        while (dq.size() > 1 && k) {
            ll mn = min(dq.front(), dq.back());
            if (k < 2 * mn) {
                dq.front() -= k / 2 + k % 2;
                dq.back() -= k / 2;
                k = 0;
            } else {
                dq.front() -= mn;
                dq.back() -= mn;
                k -= 2 * mn;
            }
            if (dq.front() == 0) {
                dq.pop_front();
            }
            if (dq.back() == 0) {
                dq.pop_back();
            }
        }
        int ans = n - dq.size();
        cout << ans + (dq.size() && dq.front() <= k) << '\n';
    }
}