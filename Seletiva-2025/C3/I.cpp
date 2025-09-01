#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
     if (n & 1) {
        if (n < 27) cout << -1 << '\n';
        else {
            cout <<"1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
            for (int i = 14 ; i <= n/2 ; i++) cout<< i << ' ' << i << ' ';
            cout << '\n';
        } 
    }
    else {
        for (int i = 1; i <= n/2; i++) cout << i << ' ' << i << ' ';
        cout << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}