#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mdc(int a, int b)
{
    if (b == 0)
        return a;

    return mdc(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    while (cin >> a >> b)
    {
        string choice = (mdc(a, b) == 1) ? "Good Choice" : "Bad Choice";

        int temp = 10 - to_string(a).size();
        cout << string(temp, ' ');
        cout << a;
        temp = 10 - to_string(b).size();
        cout << string(temp, ' ');
        cout << b << string(4, ' ');
        cout << choice;
        cout << "\n\n";
    }

    return 0;
}