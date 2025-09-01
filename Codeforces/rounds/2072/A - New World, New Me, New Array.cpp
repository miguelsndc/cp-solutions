#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n, k, p; cin >> n >> k >> p;
    if (k > n * p || k < (-1 * n * p)) {
        cout << -1 << "\n";
        return;
    }
    cout << abs(k) / p + (k % p != 0) << '\n'; 
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}