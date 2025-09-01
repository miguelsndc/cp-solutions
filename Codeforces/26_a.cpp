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
    int n;
    cin >> n;

    vc<int> a(4000, 0), prime(4000, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < 4000; i++) {
        if (prime[i]) {
            a[i] = 1;
            for (int j = i + i; j < 4000; j += i) {
                prime[j] = false;
                a[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 2) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}