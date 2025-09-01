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

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    /*
        1 and N ganha
        só o N e não tiver 1 perde
        N e algum > 1 ganha
        */

    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            a.insert(i + 1);
        else
            b.insert(i + 1);
    }

    if (a.count(n) and a.count(n - 1)) {
        cout << "Alice\n";
    } else if (a.count(n) and a.count(1)) {
        cout << "Alice\n";
    } else if (a.count(1) and b.size() == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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