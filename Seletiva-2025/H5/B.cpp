#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
const int INF = 1e9 + 1;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> dp(1e6 + 5, INF);

int f(int n) {
    if (n <= 0) return 0;
    else if (n <= 9) return dp[n] = 1;
    else if (dp[n] != INF) return dp[n];
    int tmp = n;
    while (tmp != 0) {
        int d = tmp % 10;
        tmp /= 10;
        if (d != 0) {
            dp[n] = min(dp[n], 1 + f(n - d));
        }
    }
    return dp[n];
}

void solve() {
    int n; cin >> n;
    f(n);
    cout << dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}