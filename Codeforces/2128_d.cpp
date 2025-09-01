#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        vector<ll> dp(n + 1);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (p[i] > p[i + 1]) {
                dp[i] = dp[i + 1] + n - i;  // numero de lds começando em i + 1 + numero de vezes que pi aparece na lds
            } else {
                dp[i] = dp[i + 2] + n - i;
            }
        }
        cout << accumulate(all(dp), 0LL) << '\n';
    }
}