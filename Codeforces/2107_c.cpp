#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

/*
negativos nas pontas apenas diminuem a resposta
max subarray sum apenas aumenta dado o array não diminui

para cada zero pego o maior soma de sufixo e maior soma de prefixo
se as duas forem menor do que k eu aumento pra virar k, somo e aumento o maximo
faço da esquerda pra direita
 */
void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);

    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s[i] == '0') {
            pos = i;
            a[i] = -1e13;
        }
    }

    ll cur = 0, best = 0;
    for (int i = 0; i < n; i++) {
        cur = max(cur + a[i], a[i]);
        best = max(cur, best);
    }

    if (best > k or (best != k and pos == -1)) {
        cout << "No\n";
        return;
    } else if (pos == -1 and best == k) {
        cout << "Yes\n";
        for (int x : a) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    if (pos == -1) {
        cout << "No\n";
        return;
    }

    cur = 0, best = 0;
    ll prefmax, sufmax;
    for (int i = pos - 1; i >= 0; i--) {
        cur += a[i];
        best = max(best, cur);
    }
    prefmax = best;
    best = 0;
    cur = 0;

    for (int i = pos + 1; i < n; i++) {
        cur += a[i];
        best = max(best, cur);
    }

    sufmax = best;

    a[pos] = k - prefmax - sufmax;

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}