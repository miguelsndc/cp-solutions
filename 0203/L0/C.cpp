#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int target_a = *min_element(all(a));
        int target_b = *min_element(all(b));

        ll op = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == target_a && b[i] == target_b) {
                continue;
            } else if(a[i]==target_a && b[i] != target_b) {
                op += b[i] - target_b;
            } else if (a[i] != target_a && b[i] == target_b) {
                op += a[i] - target_a;
            } else {
                ll x = a[i] - target_a, y = b[i] - target_b;
                ll common = min(x, y);
                op += common;
                op += max(0LL, max(x - common, y - common));
            }
        }
        cout << op << '\n';
    }
}
