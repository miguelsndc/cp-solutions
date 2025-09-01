#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    ll n;
    cin >> n;
    vector<ll> intervals = {1};
    while (true) {
        ll next = intervals.back() * 4 + 1;
        if (next > n) break;
        intervals.push_back(next);
    }
    int k = intervals.size() - 1;
    int l = 0, r = k;
    while (l < r) {
        int m = (l + r) / 2;
        cout << "? " << intervals[m + 1] << "\n";
        cout.flush();
        int res;
        cin >> res;
        if (res == 1) {  // x < intervals[m + 1]
            r = m;
        } else {  // x >= intervals[m + 1]
            l = m + 1;
        }
    }
    if (l < k) {
        cout << "! " << 2 * intervals[l] << "\n";
    } else {
        cout << "! " << min(2 * intervals[k], n) << "\n";
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}