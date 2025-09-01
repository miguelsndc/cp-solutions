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

const int MAX_DIGITS = 10;
ll dp[MAX_DIGITS][180][2];
vi number;
ll f(int pos, ll sum, int smaller) {
    if (pos == number.size()) return sum;
    ll &ans = dp[pos][sum][smaller];
    if (~ans) return ans;
    ans = 0;
    for (int i=0; i <= (smaller ? 9: number[pos]); i++) {
        bool smaller_now = (smaller || i < number[pos]);
        ans += f(pos + 1, sum + i, smaller_now);
    }
    return dp[pos][sum][smaller] = ans;
}

vi ntovec(int num)  {
    if (num == 0) return {0};
    vi v;
    for (; num >0; num /= 10) v.push_back(num % 10);
    reverse(begin(v), end(v));
    return v;
}

ll solve(int n) {
    if (n < 0) return 0;
    number = ntovec(n);
    memset(dp, -1, sizeof dp);
    return f(0, 0, false);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    while((cin >> a >> b) && a != -1 && b != -1) {
        cout << solve(b) - solve(a - 1) << '\n';
    }
}