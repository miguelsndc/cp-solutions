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
    vc<ii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        char y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second = (y == 'A') ? 10 : (y - '0');
    }
    reverse(all(a));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i].first, y = a[i].second;
        sum += 1LL * x * y;
    }
    if (sum % 5 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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