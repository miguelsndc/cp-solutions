#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

ll f (ll x) {
    return (x % 2 == 0) ? (x / 2) : (3 * x + 1);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n > 1) {
        cout << n << " ";
        n = f(n);
    } 
    cout << 1;
}