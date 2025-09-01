#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

// divide a set s into two subsets a and b where |sum(a) - sum(b)| is minimal.
// s1 = 1, 2, 3, 4, 5, 6
// s2 = 0

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi A(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        total += A[i];
    }
    
    ll ans = INT32_MAX;
    for (ll x = 0; x < (1 << n);x++) {
        ll s = 0;
        for (int i = 0; i < n; i++) {
            if (x & (1 << i)) s += A[i];
        }
        // let total - s = x sum of the complementary subset
        // x - s = difference of sums
        ans = min(ans, abs((total - s) - s));
    }
    cout << ans;
}