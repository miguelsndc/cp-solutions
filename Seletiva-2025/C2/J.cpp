#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<ll> ac(n, INT32_MAX), minleft(n, INT32_MAX), minright(n, INT32_MAX), idx(k);
        for (int i = 0; i < k; i++) cin >> idx[i];
        for (int i = 0; i < k; i++) {
            int temp; cin >> temp;
            ac[idx[i] - 1] = temp;
        }

        ll xx = INT32_MAX;
        for (int i = 0; i < n; i++) {
            xx = min(xx + 1, ac[i]);
            minright[i] = xx;

        }

        xx = INT32_MAX;
        for (int i = n - 1; i >= 0; i--) {
            xx = min(xx + 1, ac[i]);
            minleft[i] = xx;
        }

        for (int i = 0; i < n; i++) {
            cout << min(minleft[i], minright[i]) << " \n"[i == n -1];
        }
    }
}