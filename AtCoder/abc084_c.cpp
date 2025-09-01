#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n - 1; i++) {
        int t = s[i] + c[i];
        for (int j = i + 1; j < n - 1; j++) {
            /*
                cheguei aqui no t
                se sj >= t saimos em sj
                se nao espera o proximo trem q sai em
            */
            if (s[j] >= t) t = s[j];
            else if (t % f[j] == 0) {}
            else t += f[j] - t % f[j];
            t += c[j];
        }
        ans[i] = t;
    }
    for (int x: ans) {
        cout << x << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}