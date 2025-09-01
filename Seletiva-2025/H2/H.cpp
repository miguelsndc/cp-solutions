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
    int tt; cin >> tt;
    while(tt--) {
        int n, q; cin >> n >> q;
        vi sugar(n); loop(i, 0, n) cin >> sugar[i];
        sort(rbegin(sugar), rend(sugar));

        vi ps(n + 1);
        loop(i, 0, n) {
            ps[i + 1] = sugar[i] + ps[i];
        }

        loop(i, 0, q) {
            int x; cin >> x;
            auto it = lower_bound(begin(ps), end(ps), x);
            if (it == end(ps)) {
                cout << -1 << '\n';
            } else {
                cout << (it - begin(ps)) << '\n';
            }
        }
    }
}