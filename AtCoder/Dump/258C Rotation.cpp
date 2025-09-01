#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int start = 0;
    for (int j = 0; j < q; j++)
    {
        int query, arg;
        cin >> query >> arg;
        if (query == 1)
            for (int i = 0; i < query; i++)
                start = (start - arg + n) % n;
        else
        {
            int curr = (start - 1 + arg) % n;
            cout << s[curr] << '\n';
        }
    }

    return 0;
}