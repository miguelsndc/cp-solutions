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

const int m = 4;
class Matrix {
    public: 
        ll mat[m][m] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        Matrix mul(const Matrix& p, int mod) {
            Matrix ans;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = ans.mat[i][j] = 0; k < m; k++) {
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k] % mod) * (p.mat[k][j] % mod)) % mod;
                    }
                }
            }
            return ans;
        }
};

Matrix fexp(Matrix a, ll b, int mod) {
    Matrix ans;
    for (int i = 0; i < m; i++) {
        ans.mat[i][i] = 1;
    }
    while(b) {
        if (b & 1) ans = ans.mul(a, mod);
        a = a.mul(a, mod);
        b >>= 1;
    }

    return ans;
}

void solve() {
    ll n, mod; cin >> n >> mod;
    Matrix m;
    m.mat[0][0] = m.mat[0][1] = m.mat[0][2] = 1;
    m.mat[1][0] = 1;
    m.mat[2][2] = m.mat[2][3] = 1;
    m.mat[3][3] = 1;
    // 1 1 1 0
    // 1 0 0 0 
    // 0 0 1 1
    // 0 0 0 1
    if (n == 0) {
        cout << 0 << '\n';
    } else if (n == 1) {
        cout << 1 << '\n';
    } else {
        m = fexp(m, n - 1, mod);
        cout << (m.mat[0][0] + m.mat[0][2] + m.mat[0][3]) % mod << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}