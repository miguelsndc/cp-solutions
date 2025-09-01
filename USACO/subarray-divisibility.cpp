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
    vector<ll> v(n); ll ps = 0;
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ps += a;
        v[(ps % n + n) % n]++;
    }

    ll res = 0;
    for (auto a: v) { 
        res += a * (a - 1) / 2; 
    }
    cout << res;
}