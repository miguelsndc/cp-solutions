#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n; cin >> n;
    deque<int> a(n+1); vi b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vi dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            a.pop_back();
            a.push_front(0);
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n] << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
         solve();
    }
}