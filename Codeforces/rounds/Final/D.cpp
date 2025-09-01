#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

constexpr int MAXN = 2e5 + 5;
constexpr int MOD = 1e9 + 7;

i64 fexp(i64 a, i64 b){
    i64 ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

i64 inv(i64 a){ 
    return fexp(a, MOD - 2);
}

const int MAXK = 1005;
i64 invmod[MAXK], C[MAXK][MAXK];
void precompute() {
    for (int i = 1; i <= MAXK; i++) {
        invmod[i] = inv(i);
    }

    for (int n = 1; n < MAXK; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 or k == n) {
                C[n][k] = 1;
            } else {
                C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
            }
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    i64 s[MAXK];
    for (i64 i = 1; i <= k; i++) {
        i64 left = 1 * invmod[i + 1] % MOD;
        i64 mid = (fexp(1 + n, i + 1) - n - 1 + MOD) % MOD;
        i64 sum = 0;
        for (i64 j = 1; j < i; j++) {
            sum += (C[i + 1][j] * s[j]) % MOD;
            sum %= MOD;
        }
        s[i] = (left * ((mid - sum) % MOD + MOD) % MOD) % MOD;
    }
    cout << s[k] % MOD << '\n';
}

int main() 
{
    precompute();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}