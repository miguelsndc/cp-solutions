#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vc<vc<int>> at(26);
    // posicoes de cada caracter
    for (int i = 0; i < n; i++) {
        at[(int)(s[i] - 'a')].push_back(i);
    }
    vc<int> order(26);
    iota(all(order), 0);
    // ordena pelos caracters que mais aparecem
    sort(all(order), [&](int i, int j) {
        return at[i].size() > at[j].size();
    });
    string res = "";
    int best = -1;
    for (int cnt = 1; cnt <= 26; cnt++) {
        if (n % cnt != 0) continue;

        int cur = 0;
        // para cnt fixado consigo colocar minimo n / cnt e freq[caracter]
        for (int i = 0; i < cnt; i++) {
            cur += min(n / cnt, (int)at[order[i]].size());
        }
        // se isso é melhor do q eu ja tinha reconstruo a string
        if (cur > best) {
            best = cur;
            res = string(n, ' ');
            vc<char> extra;
            for (int it = 0; it < cnt; it++) {
                // a q mais apareceu
                int i = order[it];
                // vou colocar min (n / cnt, at[i])
                // se faltar eu salvo as posiçoes vazias em extra pra usar em outro lugar
                // (desse mesmo caracter mesmo, n importa, testar outros so torna a coisa mais dificil a toa)
                for (int j = 0; j < n / cnt; j++) {
                    if (j < (int)at[i].size()) {
                        res[at[i][j]] = (char)('a' + i);
                    } else {
                        extra.push_back((char)('a' + i));
                    }
                }
            }
            for (char& c : res) {
                if (c == ' ') {
                    c = extra.back();
                    extra.pop_back();
                }
            }
        }
    }

    cout << n - best << '\n';
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}