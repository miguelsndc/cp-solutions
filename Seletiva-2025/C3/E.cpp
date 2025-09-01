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
    int n, x; cin >> n >> x;
    vector<pii> v(n); loop(i, 0, n) {
        cin >> v[i].first;
        v[i].second = i + 1;    
    }

    sort(begin(v), end(v));

    auto cmp = [](const pii& a, const int i) {
        return i > a.first;
    };
    auto cmp2 = [](const int i, const pii& a) {
        return i < a.first;
    };

    for (int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int target = x - (v[i].fi + v[j].fi);

            if (target <= 0) continue;

            auto lb = lower_bound(begin(v), end(v), target, cmp);
            auto ub = upper_bound(begin(v), end(v), target, cmp2);

            for(auto it = lb; it != ub; ++it) {
                int b = it - begin(v);
                if (v[i].se != v[j].se && v[j].se != v[b].se && v[i].se != v[b].se) {
                    cout << v[i].se << ' ' << v[j].se << ' ' << v[b].se;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}