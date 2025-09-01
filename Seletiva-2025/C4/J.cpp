#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll sum = 0, maxn = -1;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        sum += x;
        maxn = max(maxn, x);
    }
    cout << (sum - (maxn / 2));
}