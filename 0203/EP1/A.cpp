#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vi prices(n);
    loop(i, 0, n) cin >> prices[i];
    sort(prices.begin(), prices.end());
    int q; cin >> q;
    loop(i, 0, q) {
        int x; cin >> x;
        int j = upper_bound(prices.begin(), prices.end(), x) - prices.begin();
        cout << (j) << '\n';
    }
}