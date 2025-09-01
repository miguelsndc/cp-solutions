#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<ii>
#define vd vector<double>
#define si set<int>
#define mii map<int, int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n; cin >> n;
    int cost[(1 << 3)];
    for (int i = 0; i < 8; i++) cost[i] = INF;
    for (int i = 0; i < n; i++) {
        int p; string s; cin >> p >> s;
        int a = (s.find('A') < s.size()) ? (1 << 0): 0;
        int b = (s.find('B') < s.size()) ? (1 << 1): 0;
        int c = (s.find('C') < s.size()) ? (1 << 2): 0;
        int v = a | b | c;
        cost[v] = min(cost[v], p);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cost[i] == INF && cost[j] == INF) continue;
            cost[(i | j)] = min(cost[(i | j)], cost[i] + cost[j]);
        }
    }
    if (cost[7] == INF) {
        cout << -1 << '\n';
    } else {
        cout << cost[7] << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}