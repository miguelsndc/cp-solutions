#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define se second
#define int long long
const int maxn = 2e5 + 5;

// tamanho/digit anterior/zero a esquerda?/liberdade?
int dp[20][10][2][2];
int f(string &num, int n, int prev, int i, int leading_zero, int tight) {
    if (i == n) return 1;
    if (prev != -1 and dp[i][prev][leading_zero][tight] != -1) {
        return dp[i][prev][leading_zero][tight];
    }
    int low = 0;
    int high = tight ? (num[i] - '0') : 9;
    int ans = 0;
    rep(dig, low, high+1) {
        if (dig == prev and dig != 0) continue;
        if (dig == prev and dig == 0 and not leading_zero) continue;
        ans += f(num, n, dig, i+1, leading_zero&dig==0, tight&(dig==high));
    }
    return dp[i][prev][leading_zero][tight] = ans;
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;cin>>a>>b;
    memset(dp, -1, sizeof dp);
    int ans = f(b,b.size(),-1,0,1,1);
    memset(dp, -1, sizeof dp);
    ans -= f(a,a.size(),-1,0,1,1);
    bool valid=true;
    rep(i,1,a.size()){
        if (a[i-1]==a[i]) {
            valid=false;break;
        }
    }
    ans+=valid;
    cout << ans << '\n';
}