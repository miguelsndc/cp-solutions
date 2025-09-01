#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n, k1, k2;
    cin >> n;
    cin >> k1;
    deque<int> a(k1);
    for (int i = 0; i < k1; i++) cin >> a[i];
    cin >> k2;
    deque<int> b(k2);
    for (int i = 0; i < k2; i++) cin >> b[i];

    map<pair<deque<int>, deque<int>>, int> mp;

    mp[{a, b}] = true;
    int cnt = 0;
    while (1) {
        int atop = a.front();
        int btop = b.front();

        cnt++;
        if (atop > btop) {
            a.push_back(btop);
            a.push_back(atop);
            a.pop_front();
            b.pop_front();
        } else {
            b.push_back(atop);
            b.push_back(btop);
            b.pop_front();
            a.pop_front();
        }

        if (a.size() == 0) {
            cout << cnt << ' ' << 2 << '\n';
            return;
        } else if (b.size() == 0) {
            cout << cnt << ' ' << 1 << '\n';
            return;
        }

        if (mp.count({a, b})) {
            cout << -1 << '\n';
            return;
        }

        mp[{a, b}] = true;
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