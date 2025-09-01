#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

// basically check whether the sum of all ai is a perfect square

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,a;
    cin >> t;
    while(t--) {
        cin >> n;
        ll k = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a;
            k += a;
        }
        ll sqr = sqrt(k); // log time
        if (sqr * sqr == k) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}