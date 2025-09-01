#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nos(n);
    vector<int> perms(n);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        nos[i - 1] = t;
        perms[i - 1] = i;
    }

    sort(nos.begin(), nos.end());
    sort(perms.begin(), perms.end());

    for (int i = 0; i < n; i++)
    {
        if (nos[i] != perms[i])
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}