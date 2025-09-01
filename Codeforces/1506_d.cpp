#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    priority_queue<int> pq;
    for (auto [x, y] : freq) {
        pq.push(y);
    }
    int sz = n;
    while (pq.size() > 1) {
        int cnt1 = pq.top();
        pq.pop();
        int cnt2 = pq.top();
        pq.pop();
        cnt1--;
        cnt2--;
        sz -= 2;
        if (cnt1) pq.push(cnt1);
        if (cnt2) pq.push(cnt2);
    }
    cout << sz << '\n';
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