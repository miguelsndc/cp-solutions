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

vc<ll> path, ans;
ll a, b;
bool found = false;
void dfs(ll x) {
    if (found) return;
    if (x > b) return;
    if (x == b) {
        found = true;
        ans = path;
        return;
    }
    if (!found) {
        path.push_back(x * 2);
        dfs(x * 2);
        path.pop_back();
        path.push_back(x * 10 + 1);
        dfs(x * 10 + 1);
        path.pop_back();
    }
}

void solve() {
    cin >> a >> b;
    dfs(a);
    path.assign(1, a);

    if (!found) {
        cout << "NO\n";
        return;
    }

    dfs(a);

    cout << "YES\n";
    cout << ans.size() + 1 << '\n'
         << a << ' ';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}