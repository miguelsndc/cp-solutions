#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int w; cin >> w;
    vector<int> gorillas(w);
    for (int i = 0; i < w; i++) {
        cin >> gorillas[i];
    }

    vector<int> appears;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            appears.push_back((min(i, n - k) - max(-1, i - k)) * (min(j, m - k) - max(-1, j - k)));
        }
    }

    sort(rbegin(appears), rend(appears));
    sort(rbegin(gorillas), rend(gorillas));

    ll ans = 0;    
    for (int i = 0; i < w; i++) {
        ans += 1LL * appears[i] * gorillas[i];
    }
    cout << ans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
         solve();
    }
}