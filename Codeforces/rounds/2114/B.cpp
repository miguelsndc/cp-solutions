#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template<typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p+strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',')+1 : p+strlen(p)), ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int m = n / 2;
    if (k > m) {
        cout << "NO\n";
        return;
    }
    int c0 = 0;
    for (char c : s) {
        if (c == '0') c0++;
    }
    int c1 = n - c0, diff = m -k;
    bool can = (c0 >= diff and (c0 - diff) % 2 == 0) and 
                (c1 >= diff and (c1 - diff) % 2 == 0);
    cout << (can ? "YES\n" : "NO\n");
}

int main() 
{
    fast;
    int tt = 1;  cin >> tt;
    while(tt--) solve();
}