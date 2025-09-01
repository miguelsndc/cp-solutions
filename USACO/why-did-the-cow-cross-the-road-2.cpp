#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("maxcross.in", "r", stdin); freopen("maxcross.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, b; cin >> n >> k >> b;
    vector<int> ps(n + 1), v(n + 1);
    for (int i = 0; i < b; i++) {
        int x; cin >> x;
        v[x]++;
    }

    for (int i = 0; i < n; i++) {
        ps[i + 1] = v[i + 1] + ps[i];
    }

    int ans = INT32_MAX;
    for (int i = 1; i <= n - k; i++) {
        ans = min(ans, ps[i + k] - ps[i]);
    }
    cout << ans;
}