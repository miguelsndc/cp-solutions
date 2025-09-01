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
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
       int a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int a, g, c, t, qm;
    a = g = c = t = qm = 0;
    for (char ch: s) {
        if (ch == 'A') a++;
        else if (ch == 'G') g++;
        else if (ch == 'C') c++;
        else if (ch == 'T') t++;
        else qm++;
    }
    bool can = true;
    if (n % 4 != 0) {
        can = false;
    }
    int should = n / 4;
    int na = should - a;
    int ng = should - g;
    int nc = should - c;
    int nt = should - t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (na > 0) na--,  qm--, s[i] = 'A';
            else if (ng > 0) ng--,  qm--, s[i] = 'G';
            else if (nc > 0) nc--, qm--,  s[i] = 'C';
            else if (nt > 0) nt--,  qm--, s[i] = 'T';
        }
    }
    if (na > 0 || qm > 0 || nc > 0 || nt > 0 || ng > 0) can = false;
    if (can) {
        cout << s;
    } else {
        cout << "===";
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