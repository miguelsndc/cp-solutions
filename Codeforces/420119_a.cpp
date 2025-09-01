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
    vc<vc<int>> v(n);
    vc<int> a;
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
            a.push_back(x);
        }
    }
    sort(all(a));

    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            v[i][j] = lower_bound(all(a), v[i][j]) - begin(a);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j + 1 < v[i].size() and v[i][j + 1] != v[i][j] + 1) {
                s++;
            }
        }
    }

    cout << s << ' ' << n + s - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}