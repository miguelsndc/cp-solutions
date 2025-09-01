#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

// lower bound given f(x) = whether x has distinct digits

int f(int x) {
    int seen[10] = {0};
    while(x) {
        int digit = x % 10;
        x /= 10;
        if (seen[digit]) {
            return 0;
        }
        seen[digit]++;
    }
    return 1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int y;
    cin >> y;
    int i = y + 1;
    while (1) {
        if (f(i)) {
            cout << i;
            return 0;
        }
        i++;
    }
}