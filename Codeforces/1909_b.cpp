#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    /*
        se par/impar trivial k =2
        se nao ?

        olhando repr binaria

        * ideia central: modulo 2^k é equivalente a pegar os ultimos k bits do numero
        tem que haver uma posicao distinta pelo menos ja que todos os numeros sao distintos
    */

    for (ll k = 2; k <= (1LL << 59); k *= 2) {
        vector<ll> cp = a;
        for (int i = 0; i < n; i++) cp[i] %= k;
        sort(all(cp));
        cp.resize(unique(all(cp)) - begin(cp));
        if (cp.size() == 2) {
            cout << k << '\n';
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}