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
    vi digitsum(200005);
    for (int i = 1; i <= 200005; i++) {
        int k = i;
        int sum = 0;
        while (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        digitsum[i] = sum;
    }

    vi ps(200006);
    ps[0] = 0;
    for (int i = 1; i <= 200005; i++) {
        ps[i] = ps[i - 1] + digitsum[i];
    }

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        cout << ps[n] << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}