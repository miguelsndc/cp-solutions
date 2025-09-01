#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pal;
void generatePalindromes(int d, int i, int j, vector<int>& v) {
    if (i > j) {
        ll num = 0;
        for (int k = 0; k < d; k++) {
            num = num * 10 + v[k];
        }
        pal.push_back(num);
        return;
    }
    int start = 0, end = 9;
    if (i == 0) start = 1;
    for (int digit = start; digit <= end; digit++) {
        v[i] = digit;
        v[j] = digit;
        generatePalindromes(d, i + 1, j - 1, v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<ll> ans;
    for (int d = 1; d <= 12; d++) {
        vector<int> v(d);
        generatePalindromes(d, 0, d - 1, v);
        for (ll x: pal) ans.push_back(x);
        pal.clear();
    }
    auto f = [&] (ll x, ll b) -> bool {
        string s;
        while(x) {
            ll k = x / b;
            ll m = x % b;
            s.push_back(m + '0');
            x = k;
        }
        string k = s;
        reverse(k.begin(), k.end());
        return k == s;
    };
    ll a, n; cin >> a >> n;
    ll sum = 0;
    for (ll x: ans) {
        if (x > n) break;
        if (f(x, a)) {
            sum += x;
        }
    }
    cout << sum << '\n';
}