#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define fi first
#define se second
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> intervals(n);
    vector<pii> times;
    // ideia extremamente interessante
    loop(i, 0, n) {
        int l, r; cin >> l >> r;
        times.push_back({l, 1});
        times.push_back({r, -1});
    }

    sort(all(times));

    int curr = 0;
    int maxc = 0;
    for (auto [s, x]: times) {
        curr += x;
        maxc = max(maxc, curr);
    }
    cout << maxc;
}
