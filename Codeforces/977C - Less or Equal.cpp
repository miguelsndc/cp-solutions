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
    int n,k; cin >> n >> k;
    // pick a integer such that there are exactly k elements <= than that integer
    // sort and choose position k
    vi v(n); rep(i,0,n) cin >> v[i];
    sort(v.begin(), v.end());
    if (k == 0) {
        if (v[0] - 1 >= 1) {
            cout << v[0] - 1;
        } else {
            cout << -1;
        }
    } else {
        int pos = k - 1, val = v[k - 1];
        if (pos + 1 < n && v[pos + 1] == v[pos]) {
            cout << -1;
        } else {
            cout << v[pos];
        }
    }
}