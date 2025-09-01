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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        for (int ans = 1, cur = 1;; ans++, cur = cur * 2 + 2) {
            if (cur >= n) {
                cout << ans << '\n';
                break;
            };
        }
    }
}