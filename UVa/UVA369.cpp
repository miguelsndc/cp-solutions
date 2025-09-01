#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll C(int n, int k)
{
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    n = m = -1;
    cin >> n >> m;
    do
    {
        cout << n << " things taken " << m << " at a time is " << C(n, m) << " exactly." << '\n';
        cin >> n >> m;
    } while (n != 0 && m != 0);
    return 0;
}