#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 1;; i++)
    {
        if (stoll(to_string(i) + to_string(i)) > n)
        {
            cout << i - 1;
            return 0;
        }
    }

    return 0;
}