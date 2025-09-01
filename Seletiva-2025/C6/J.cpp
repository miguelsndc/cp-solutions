#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n, k; cin >> n >> k;
    vi v(n);
    map<int, int> freq;
    for(int i =0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    vi good;
    for (const auto&[key, v]: freq) {
        if (v >= k) good.push_back(key);
    }

    if (good.empty()) {
        cout << -1 << '\n';
        return;
    }

    sort(begin(good), end(good));

    int mx = 0, lans = good[0], rans = good[0];
    int l = good[0];
    for (int i = 1; i < good.size(); i++) {
        if (good[i] - 1 == good[i - 1]) {
            if (good[i] - l > mx) {
                mx = good[i] - l;
                lans = l;
                rans = good[i];
            }
        }else {
            l = good[i];
        }
    }
    cout << lans << ' ' << rans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while(tt--) {
         solve();
    }
}