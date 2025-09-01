#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = (i + 1) * (s[i] - '0');
    }
    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
    ll i = 0, carry = 0;
    string ans;
    while(i < n || carry > 0) {
        if (i < n) {
            carry += v[n - i - 1];
        }
        ans += to_string((carry % 10));
        carry /= 10;
        i++;
    }
    reverse(begin(ans), end(ans));
    cout << ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}