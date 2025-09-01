#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    for (int j = n - 1; j >= 0; j--) {
        ans[n - j - 1][j] = 1;
    }

    if (n % 2 != 0) {
        ans[n/2][(n+1)/2] = 1;
        ans[(n + 1)/2][((n)/2)] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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