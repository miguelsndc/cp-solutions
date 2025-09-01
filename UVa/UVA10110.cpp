#include <bits/stdc++.h>

using namespace std;

void solve(unsigned int n)
{
    unsigned int sq = (int)sqrt(n);
    cout << (sq * sq == n ? "yes\n" : "no\n");
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;
    while (cin >> n && n != 0)
    {
        solve(n);
    }

    return 0;
}