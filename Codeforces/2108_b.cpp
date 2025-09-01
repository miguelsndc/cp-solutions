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
    int n, x;
    cin >> n >> x;
    /*
     */
    int bits = __builtin_popcount(x);
    if (n <= bits) {
        cout << x << '\n';
        return;
    }
    if ((n - bits) % 2 == 0) {
        cout << x + n - bits << '\n';
    } else {
        if (x > 1) {
            cout << x + n - bits + 1 << "\n";
            return;
        }
        if (x == 1) {
            cout << n + 3 << '\n';
            return;
        } else {
            if (n == 1) {
                cout << -1 << '\n';
                return;
            } else {
                cout << n + 3 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}