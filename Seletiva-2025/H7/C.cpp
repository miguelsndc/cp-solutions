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

const int m = 2;
class Matrix {
    public: 
        ll mat[m][m] = {{0, 0}, {0, 0}};
        Matrix operator*(const Matrix& p) {
            Matrix ans;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = ans.mat[i][j] = 0; k < m; k++) {
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k] % MOD) * (p.mat[k][j] % MOD)) % MOD;
                    }
                }
            }
            return ans;
        }
};

Matrix fexp(Matrix a, ll b) {
    Matrix ans;
    for (int i = 0; i < m; i++) {
        ans.mat[i][i] = 1;
    }
    while(b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }

    return ans;
}

void solve() {
    ll n; cin >> n;
    Matrix m;
    m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
    auto ans = fexp(m, n);
    cout << (ans.mat[0][0] * 0 + ans.mat[0][1] * 1) % MOD;
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