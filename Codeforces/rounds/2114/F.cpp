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
    ll x, y, k; 
    cin >> x >> y >> k;
    
    if (x == y){
        cout << 0 << "\n";
    return;
    }
    queue<pair<ll, ll>> q;
    set<ll> visited; 
    q.push({x, 0});
    visited.insert(x);
    while (!q.empty()) {
        auto [curr, ops] = q.front(); q.pop();
        for (ll a = 2; a <= k; a++) {
            if (curr % a != 0) continue;
            ll next = curr / a;
            if (next == y) {
                cout << ops + 1 << '\n';
                return;
            }
            if (next > 0 && !visited.count(next)) {
                visited.insert(next);
                q.push({next, ops + 1});
            }
        }
        for (ll a = 2; a <= k; a++) {
            ll next = curr * a;
            if (next == y) {
                cout << ops + 1 << '\n';
                return;
            }
            // limitar pra nao dar bosta
            if (next <= 2e6 && !visited.count(next)) {
                visited.insert(next);
                q.push({next, ops + 1});
            }
        }
    }

    cout << -1 << '\n';
}

int main() 
{
    fast;
    int tt = 1;  cin >> tt;
    while(tt--) solve();
}