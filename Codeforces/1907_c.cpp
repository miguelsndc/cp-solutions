#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[(int)(s[i] - 'a')]++;
    }
    int mx = *max_element(all(cnt));
    /*
        se um cara aparecer mais de n/2 vezes n tem o q fazer, vai sobrar
        se tiver <= n / 2 vezes ent sempre da pra deixar a string vazia com
        alguma ordem de operações
        nesse caso

        max(string normal maxfreq <= n / 2, se aparecer mais de n/2 vzes oq sobra);
    */
    cout << max(n % 2, 2 * mx - n) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
