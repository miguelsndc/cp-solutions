#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
const int mod = 1e9 + 7;


typedef vector<vector<i64>> matrix;

matrix init(int size) {
    matrix mat(size, vector<i64>(size));
    return mat;
}

vector<i64> vecmul(matrix m, vector<i64> vec, i64 sz, i64 mod) {
    assert(vec.size() == sz);
    vector<i64> ans(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            ans[i] += (vec[j] * (m[i][j]));
            ans[i] %= mod;
        }
    }
    return ans;
}

matrix matmul(matrix m1, matrix m2, i64 mod, i64 sz) {
    matrix ans = init(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                ans[i][j] = (ans[i][j] + 1LL * (m1[i][k] % mod) * (m2[k][j] % mod)) % mod;
            }
        }
    }
    return ans;
}

// O(log(b))
matrix fexp(matrix p, i64 b, i64 mod, i64 sz) {
    matrix ans = init(sz);
    for(int i = 0; i < sz; i++) ans[i][i] = 1;
    while(b){
        if(b & 1) ans = matmul(ans, p, mod, sz);
        p = matmul(p, p, mod, sz);
        b >>= 1;
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    int x, y; cin >> x >> y;
    matrix m = {{0, 1}, {1, 1}};
    matrix ans = fexp(m, max(n - 2, 0LL), mod, 2);
    vector<i64> v = vecmul(ans, {x, y}, 2, mod);
    if (n & 1) {
        cout << "Samuell\n";
    } else {
        cout << "Lleumas\n";
    }
    if (n <= 2) {
        cout << v[n - 1] % mod;
    } else {
        cout << v[1] % mod << '\n';
    }
}