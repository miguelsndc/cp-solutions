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

ll f(ll n, ll k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n)
            return (2 * k) % n;
        else
            return 2 * k;
    }
    ll temp = f(n / 2, k - (n + 1) / 2);
    if (n % 2 == 1) return 2 * temp + 1;
    return 2 * temp - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        cout << f(n, k) << '\n';
    }

    return 0;
}