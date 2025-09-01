#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define writeln(x) cout << x << '\n';

void solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<vi> dp(a.size() + 1, vi(b.size() + 1));

    dp[0][0] = 0;
    for (int i = 1; i < b.size() + 1; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < a.size() + 1; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < a.size() + 1; i++) {
        for (int j = 1; j < b.size() + 1; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    cin.ignore();
    while(tt--) {
         solve();
    }
}