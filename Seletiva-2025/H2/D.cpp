#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)


bool possible(ll s, ll k, vector<ll> &v) {
    ll curr = 0;
    ll amount = 0;
    for (ll i = 0; i < v.size(); i++) {
        if (v[i] > s) return false;
        if (curr + v[i] > s) {
            curr = 0;
            amount++;
        }
        curr += v[i];
    }
    amount++;
    return amount <= k;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    ll sum = 0;
    vector<ll> v(n);
    loop(i, 0, n) {
        cin >> v[i];
        sum += v[i];
    }

    ll l = 0, r = sum;
    while(r - l > 1) {
        ll m = l + (r - l) / 2;
        if (possible(m, k, v)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r;
}