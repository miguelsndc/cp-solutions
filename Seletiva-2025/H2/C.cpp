#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;

    vi v(n); loop(i, 0, n) cin >> v[i];

    multimap<int, pii> mp;

    for(int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - (v[i] + v[j]);

            if (mp.find(target) != mp.end()) {
                for (auto [itr, range] = mp.equal_range(target); itr != range; ++itr) {
                    auto [ni, nj] = (*itr).second;

                    set<int> s;

                    s.insert(i);
                    s.insert(j);
                    s.insert(ni);
                    s.insert(nj);

                    if (s.size() == 4) {
                        cout << i + 1 << ' ' << j + 1 << ' ' << 
                        ni + 1 << ' ' << nj + 1;
                        return 0;
                    }
                }
            } 
            mp.insert({v[i] + v[j], {i, j}});
        }
    }

    cout << "IMPOSSIBLE";
}