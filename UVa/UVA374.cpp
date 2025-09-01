#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll B, P, M;
    while (cin >> B >> P >> M)
    {
        ll x = 1;
        int power = B % M;
        int k = log2(P);
        for (int i = 0; i <= k; i++)
        {
            int a = (P >> i) & 1;
            if (a == 1)
                x = (x * power) % M;
            power = (power * power) % M;
        }
        cout << x << '\n';
    }

    return 0;
}