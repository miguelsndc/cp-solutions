#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, len; cin >> n >> len;
    vector<int> v(n);
    for (int&x: v) cin>>x;
    sort(begin(v), end(v));
    int maxd = -1;
    for (int i=0; i <n-1;i++) {
        maxd = max(maxd, abs(v[i] - v[i + 1]));
    }
    cout << setprecision(12) << fixed << max(maxd / 2.0, 1.0 *max(v[0] - 0, len - v[n-1]));
}