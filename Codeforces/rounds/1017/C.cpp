#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    vector<int> perm(2 * n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            perm[(i + j)] = x;
        }
    }

    set<int> seen;
    for (int i = 1; i <= 2 * n; i++) seen.insert(i);
    for (int x: perm) {
        seen.erase(x);
    }
    perm[1] = *seen.begin();
    for (int i = 1; i <= 2 * n; i++) {
        cout << perm[i] << ' ';
    }
    cout << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}