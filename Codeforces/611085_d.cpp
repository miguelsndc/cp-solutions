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
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            pair<int, int> x = {i, n - 1};
            int j = i + 1;
            while (x.first > 1 and s[j] == '0') {
                x.first--;
                x.second--;
                j++;
            }
            cout << 1 << ' ' << n << ' ' << x.first << ' ' << x.second << '\n';
            return;
        }
    }

    cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}