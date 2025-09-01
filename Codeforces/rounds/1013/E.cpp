#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
const int maxn = 1e7 + 5;
bool is_prime[maxn];
void sieve() {
    fill(is_prime, is_prime + maxn, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < maxn; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < maxn; j += i) {
            is_prime[j] = 0;
        }
    }
}

void solve() {
    int n; cin >> n;
    i64 ans = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) ans += n / i;
    }
    cout << ans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}