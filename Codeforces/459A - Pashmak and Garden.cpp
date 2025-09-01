#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

double dist(ll x1,ll y1, ll x2, ll y2) {
    return sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1,y1,x2,y2;
    cin >>x1>>y1>>x2>>y2;

    if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2)) {
        cout << -1;
    } else if (x1 == x2) {
        cout << x1 + abs(y1 - y2) <<  ' ' << y1 << ' ' << x2 + abs(y1 - y2) << ' ' << y2 << '\n';
    } else if (y1 == y2) {
        cout << x1 << ' ' << y1 + abs(x1 - x2) << ' ' << x2 << ' ' << y2 + abs(x1 - x2) << '\n';
    } else {
        cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
    }
}