#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    ll sum_squared = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sum += t;
        sum_squared += t * t;
    }
    cout << (n * sum_squared) - sum * sum;

    return 0;
}