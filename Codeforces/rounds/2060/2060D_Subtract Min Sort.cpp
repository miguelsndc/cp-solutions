#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    /*
    se ai > ai + 1 continua desordenado independente
    so adianta tentar qnd ai <= ai + 1

    se o array ou tiver sortado ou tiver um numero de pares (ai, ai + 1)
    */
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
        int k = min(v[i], v[i + 1]);
        v[i] -= k, v[i + 1] -= k;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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