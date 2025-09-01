#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e6 + 5;

void solve() {
    vector<int> A(maxn);
    for (int i = 2; i < maxn; i++) {
        if (A[i] == 0)
            for (int j = i; j < maxn; j += i) A[j]++;
    }
    vector<i64> v;
    for (i64 i = 2; i < maxn; i++)
        if (A[i] == 2) v.push_back(i * i);
    int q;
    cin >> q;
    while (q--) {
        i64 x;
        cin >> x;
        cout << *prev(upper_bound(all(v), x)) << '\n';
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