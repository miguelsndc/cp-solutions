#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

struct Project {
    int start, end, pay;
    Project() {};
    Project(int _a, int _b, int _c): start(_a), end(_b), pay(_c) {}
    bool operator<(Project &p) { return end < p.end; };
};

void solve() {
    int n; cin >> n;
    vector<Project> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b, c; cin >> a >> b >> c;
        p[i] = {a, b, c};
    }
    sort(begin(p), end(p));

    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    // f(0) = 0
    // ans = pagamento do interv. mais proximo a esquerda // end_i-1 < start_i
    // f(i) = max(f(i - 1) (nao pega o atual), val atual + ans (se der, o mais a esquerda))

    for (int i = 1; i <= n; i++) {
        // pegar o maior fim q nao intersecta com o comeco de i ?
        int l = 1, r = i - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (p[m].end < p[i].start) {
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }
        ll v = p[i].pay;
        if (ans != -1) {
            v += dp[ans];
        }
        dp[i] = max(dp[i - 1], v);
    }
    cout << dp[n];
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