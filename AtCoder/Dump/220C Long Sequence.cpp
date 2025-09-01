#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll seq[n];
    ll x;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
        sum += seq[i];
    }
    cin >> x;

    ll P = x / sum;       // number of full copies of seq
    ll aux_sum = P * sum; // current sum
    ll ans = P * n;       // number of elements
    for (int i = 0; i < n; i++)
    {
        aux_sum += seq[i];
        ans++;
        if (aux_sum > x)
        {
            cout << ans;
            return 0;
        }
    }

    return 0;
}