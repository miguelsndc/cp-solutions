#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

int f(int m, int n, vector<int> &v, int k) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x += (v[i] / m) + (v[i] % m > 0) - 1;
    }

    return x <= k;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    int l = 1, r = mx + 1;
    int ans = 0;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if (f(m, n, v, k)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }

    cout << ans;
}