#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<ll>> dist(26, vector<ll>(26));
    rep(i,0,26) {
        rep(j,0,26) {
            cin >> dist[i][j];
            if (i == j) dist[i][j] = 0;
        }
    }

    rep(k,0,26) {
        rep(i,0,26) {
            rep(j,0,26) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    string s; cin >> s;
    int i = 0, j = s.size() - 1;
    ll cost = 0;
    while(i < j) {
        if (s[i] == s[j]) {
            i++, j--;
            continue;
        }

        ll w = min(dist[s[i] - 'a'][s[j] - 'a'], dist[s[j] - 'a'][s[i] - 'a']);
        rep(k,0,26) {
            w = min(w, dist[s[i] - 'a'][k] + dist[s[j] - 'a'][k]);
        }
        cost += w;
        i++, j--;
    }
    cout << cost;
}