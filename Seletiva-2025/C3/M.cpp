#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, m = 0; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }
    vector<string> T(m, string(n, '*'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            T[j][n - i - 1] = s[i][j];
        }
    }
      for (int i = 0; i < m; ++i) {
        while (T[i].back() == '*') T[i].pop_back();
        cout << T[i] << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}