#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

int dfs(int i, vi & v, int a, int b) {
    cout << abs(b - a) << '\n';
    if (i == v.size()) return abs(b - a);
    int left = dfs(i + 1, v, a + v[i], b);
    int right = dfs(i + 1, v, a, b + v[i]);
    return min(left, right);
}

void solve() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    dfs(0, v, 0, 0);
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