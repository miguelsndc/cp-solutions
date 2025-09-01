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

const int MAX_DIGITS = 103;
const int MAX_K = 4;
ll dp[MAX_DIGITS][MAX_K][2];
vector<int> number; int k;
ll f(int pos, ll cnt, int smaller) {
    if (cnt > k) return 0;
    if (pos == number.size()) return (cnt == k);
    ll &ans = dp[pos][cnt][smaller];
    if (~ans) return ans;
    ans = 0;
    for (int i=0; i <= (smaller ? 9: number[pos]); i++) {
        bool smaller_now = (smaller || i < number[pos]);
        ll new_cnt = cnt + (i > 0);
        ans += f(pos + 1, new_cnt, smaller_now);
    }
    return dp[pos][cnt][smaller] = ans;
}
void solve() {
    string n; cin >> n; cin >> k;
    for (char c: n) {
        int i = c - '0';
        number.push_back(i);
    }
    memset(dp, -1, sizeof dp);
    ll ans = f(0, 0, false);
    cout << ans;
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