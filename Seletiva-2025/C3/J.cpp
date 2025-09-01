#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v), end(v));
    int l = -1 , r = 1e9;
    // checa se da pra fazer em `mid` tempo se der tenta fazer mais rapido
    // cara 1 pega um prefixo cara 2 pega um sufixo e cara 3 pega oq sobra
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        int i = 0;
        // prefixo maximo
        while(i + 1 < v.size() && v[i + 1] - v[0] <= 2 * m) {
            i++;
        }
        int j = n - 1;
        // sufixo maximo
        while(j - 1 >= 0 && v.back() - v[j - 1] <= 2 * m) {
            j--;
        }
        i++, j--;
        if (i > j || v[j] - v[i] <= 2 * m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
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