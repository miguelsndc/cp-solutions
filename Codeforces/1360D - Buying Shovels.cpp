#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        /*
        escolher um x <= k e comprar varios pacotes de tamanho x pra dar extaente n
        x <= n / 2 pq 2 é minimo de pacotes q da pra comrpar se k < n
        maior divisor de n menor <= k
        */
        if (k >= n)
        {
            cout << 1 << '\n';
        }
        else
        {
            int mx = 1;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0 && i <= k) {
                    if (i != n / i && n / i <= k) mx = max(mx, n / i);
                    mx = max(mx, i);
                }
            }
            cout << n / mx << '\n';
        }
    }
}