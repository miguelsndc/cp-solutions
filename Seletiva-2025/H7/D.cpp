#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second
int m = 2;
class Matrix{
    public:
        vector<vector<ll>> mat = vector(m, vector<ll>(m, 0));
        void setSize(int s) {
            mat.assign(s, vector<ll>(s, 0)); 
        }
        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k] % MOD) * (p.mat[k][j] % MOD)) % MOD;
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0; i < m; i++)
        ans.mat[i][i] = 1;
    
    while(b){
        if(b & 1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    int edges, p; cin >> edges >> p;
    Matrix matrix;
    matrix.setSize(m);
    fori(edges) {
        int r,c; cin>>r>>c;
        r--, c--;
        matrix.mat[r][c] = 1;
    }
    auto ans = fexp(matrix, p);
    ll sum = 0;
    fori(m) {
        forj(m) {
            sum += (ans.mat[i][j]);
            sum %= MOD;
        }
    }
    writeln(sum);
}