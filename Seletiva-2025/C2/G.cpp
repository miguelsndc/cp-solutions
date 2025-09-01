#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> s(m + 1, 1);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        s[r] = max(s[r], l + 1);
    }
    for (int i = 1; i <= m; i++) {
        s[i] = max(s[i], s[i - 1]);
    }
    ll k = 0;
    for (int i = 1; i <= m; i++) k += i - s[i] + 1;
    cout << k;
}