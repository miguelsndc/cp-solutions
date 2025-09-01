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
    set<int> powers;
    for (int i = 2; i * i <= 1000000; i++) {
        int power = i * i;
        while (power <= 1000000) {
            powers.insert(power);
            power *= i;
        }
    }

    int n; cin >> n;
    vi v(n);
    for (int &x: v) cin >> x;
    vector<vi> dv(n);
    for (int i = 0; i < n; i++) {
        int k = v[i];
        for (int j = 2; j * j <= v[i]; j++) {
            if (k % j == 0) {
                dv[i].push_back(j);
                if (j != k / j) dv[i].push_back(v[i] / j);
            }
        }
        dv[i].push_back(k);
    }
    set<int> s{begin(dv[0]), end(dv[0])};
    for (int i = 1; i < n; i++) {
        set<int> curr{begin(dv[i]), end(dv[i])};
        set<int> tmp;
        set_intersection(begin(s), end(s), begin(curr), end(curr), inserter(tmp, begin(tmp)));
        s = move(tmp);
    }
    int mx = -1;
    for (int x: s) {
        if (powers.find(x) != powers.end()) {
            mx = max(mx, x);
        }
    }
    if (mx == -1) {
        cout << "NO CIVIL WAR";
    } else {
        cout << mx;
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