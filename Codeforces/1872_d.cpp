#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    /*

    vao se encontrar em lcm(x, y)
    botar os maiores nos multiplos de x que nao sao multiplos de y
    botar os menores nos multiplos de y que nao sao multiplos de x
    o resto nos multiplos do lcm
     */

    ll l = lcm(X, Y);

    ll div_por_x = N / X;
    ll div_por_y = N / Y;
    ll div_por_x_e_y = N / l;

    ll div_por_somente_x = div_por_x - div_por_x_e_y;
    ll div_por_somente_y = div_por_y - div_por_x_e_y;

    // pega os divx maiores
    ll cnt_x = N * (N + 1) / 2;
    cnt_x -= (N - div_por_somente_x) * (N - div_por_somente_x + 1) / 2;
    // começa de 1
    ll cnt_y = div_por_somente_y * (div_por_somente_y + 1) / 2;

    cout << cnt_x - cnt_y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}