#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<ll> sub1, sub2;
    vector<ll> v(n); loop(i, 0, n) cin >> v[i];

    int s1 = n / 2;
    int s2 = n - s1;
    for (ll i = 0; i < (1 << s1); i++) {
        ll sum = 0;
        for (int j = 0; j < s1; j++) {
            if (i & (1 << j)) {
                sum += v[j];
            }
        }
        sub1.push_back(sum);
    }

    for (ll i = 0; i < (1 << s2); i++) {
        ll sum = 0;
        for (int j = s1; j < n; j++) {
            if (i & (1 << (j - s1))) {
                sum += v[j];
            }
        }
        sub2.push_back(sum);
    }

    sort(begin(sub2), end(sub2));

    ll total = 0;
    for (auto p: sub1) {
        auto it = lower_bound(begin(sub2), end(sub2), x - p);
        auto it2 = upper_bound(begin(sub2), end(sub2), x - p);
        total += it2 - it;
    }
    cout << total;
}