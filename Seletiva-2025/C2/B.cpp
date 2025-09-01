#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const ll KMAX = 1e18;

void solve() {
    int q; cin >> q;

    vector<ll> a;
    a.push_back(0);
    a.push_back(9);
    while(1) {
        ll n = (a.back() / (a.size() - 1)) * 10 * a.size();
        a.push_back(n);
        if (n > KMAX) break;
    }

    for (int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }

    while(q--) {
        ll k; cin >> k;
        ll i = lower_bound(begin(a), end(a), k) - begin(a);
        k -= a[i - 1];

        ll x = 0, y = i - 1;
        while(y--) {
            x = (x * 10) + 9;
        }
        ll offset = k / i, pos = k % i;
        if (pos == 0) {
            cout << (offset + x) % 10;
        } else {
            ll dec = i - pos;
            offset++;
            offset += x;
            while(dec--) {
                offset /= 10;
            }
            cout << offset % 10;
        }
        cout << '\n';
    }
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