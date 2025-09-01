#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

ll solve(ll b, ll p, ll m) {
    ll r = 1;
    while (p) {
        if (p & 1) {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc, i = 1, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        ll ans;
        if (n == 1 || n == 2)
            ans = 1;
        else
            ans = solve(n, n - 2, 2000000011);
        cout << "Case #" << i << ": " << ans << "\n";
        i++;
    }

    return 0;
}