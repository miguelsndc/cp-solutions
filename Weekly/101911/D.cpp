#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7;

#ifdef CARNEDESOOOL
#define maxn 300
#else
#define maxn 10000005
#endif

vector<int> freq(maxn), m[maxn], computed(maxn);

void divisors(int x) {
    computed[x] = true;
    for (int i = 1; i * i <= x; i++) {
        if (m[x].size() >= freq[x]) {
            break;
        }
        if (x % i == 0) {
            m[x].push_back(i);
            if (i != (x / i) and m[x].size() < freq[x]) {
                m[x].push_back(x / i);
            }
            if (m[x].size() >= freq[x]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    vector<pair<int, int>> ans;
    ans.reserve(n);
    for (int x : v) {
        if (!computed[x]) divisors(x);
        if (m[x].size() <= 0) {
            cout << "NO\n";
            return;
        } else {
            ans.push_back({x / m[x].back(), m[x].back()});
            m[x].pop_back();
        }
    }
    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}