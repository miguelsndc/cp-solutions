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
#define pb push_back
#define eb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n; cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++) {
        double x; cin >> x;
        v[i] = round(x * 100);
    }

    ll cost = 0;
    vll m3,m4;
    for (int c: v) {
        if (c % 5 == 0) cost += c; 
        else if (c % 5 == 1) cost += c - 1; 
        else if (c % 5 == 2) cost += c - 2;
        else if (c % 5 == 3) m3.pb(c);
        else if (c % 5 == 4) m4.pb(c);
    }
    ll m = min(sz(m3), sz(m4));
    for (int i = 0; i < m; i++) {
        cost += (m3[sz(m3) - 1] + m4[sz(m4) - 1]) - 2;
        m3.pop_back();
        m4.pop_back();
    }

    ll c = 0;
    while(m3.size() > 0) {
        int a = m3.back(), b=0;
        m3.pop_back();
        if (m3.size() > 0) {
            b = m3.back();
            m3.pop_back();
        } 
        if (b != 0) {
            c -= (a + b) % 5;
        }
        int s = (a + b);
        c += s;
    }
    cost += c;

    c = 0;
    while(m4.size() > 0) {
        int a = m4.back(), b=0, d=0;
        m4.pop_back();
        if (m4.size() > 0) {
            b = m4.back();
            m4.pop_back();
        } 
        if (m4.size() > 0) {
            d = m4.back();
            m4.pop_back();
        } 
        if (b != 0 && d != 0) {
            c -= (a + b + d) % 5;
        }
        ll s = (a + b + d);
        c += s;
    }

    cost += c;
    cout << setprecision(2) << fixed <<  ((1.0 * cost)/100.0);
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