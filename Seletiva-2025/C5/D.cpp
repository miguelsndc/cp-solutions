#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<string, int>> g;
    string s; cin >> s;
    int idx = 0;
    for (int i = 0; i < n;) {
        string comp;
        int j = i;
        while (j < n && s[j] == s[i]) {
            comp += s[j];
            j++;
        }
        if (comp[0] == '1') {
            idx++;
        }
        
        g.push_back({comp, (comp[0] == '1' ? idx : 0)});
        i = j;
    }

    int k1 = 0, k2 = 0;
    for (int i = 0; i < g.size(); i++) {
        if (g[i].second == k - 1) {
            k1 = i;
        }
        if (g[i].second == k) {
            k2 = i;
        }
    }

    while(k2 - k1 > 1) {
        auto tmp = g[k2 - 1];
        g[k2 - 1] = g[k2];
        g[k2] = tmp;
        k2--;
    }

    string ans;
    for (auto c: g) {
        ans += c.first;
    }
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