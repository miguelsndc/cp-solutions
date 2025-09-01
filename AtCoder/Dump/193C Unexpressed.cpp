#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    set<ll> powers;

    for (int j = 2; j * j <= n; ++j)
    {
        for (int p = j * j; p <= n; p *= j)
        {
            powers.insert(p);
        }
    }

    cout << n - (int)powers.size() << '\n';

    return 0;
}