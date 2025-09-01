#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int mul = ceil(b / c);
    if (c * mul >= a && c * mul <= b)
        cout << c * mul;
    else
        cout << -1;

    return 0;
}