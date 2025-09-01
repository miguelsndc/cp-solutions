#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector
const int maxn = 100100;

vector<vector<int>> f(maxn);
int resp = 0;
vector<int> pi;
string b, s;
int t[maxn][26];

// kmp online
int pega(int j, int ch) {
    if (t[j][ch] != -1) return t[j][ch];
    if (j == 0) return t[j][ch] = 0;
    if (ch == (s[j] - 'a')) return t[j][ch] = j;
    return t[j][ch] = pega(pi[j - 1], ch);
}

void dfs(int u, int len) {
    for (int v : f[u]) {
        char c = b[v - 2];
        for (int i = 0; i < 26; i++)
            t[len][i] = -1;
        s.push_back(c);
        if (len == 0) {
            pi.push_back(0);
        } else {
            int j = pega(pi[len - 1], c - 'a');
            if (c == s[j]) {
                j++;
            }
            pi.push_back(j);
        }
        int periodo = (pi[len] > 0 and (len + 1) % (len + 1 - pi[len]) == 0 ? len + 1 - pi[len] : 0);
        resp = max(resp, periodo);
        dfs(v, len + 1);
        s.pop_back();
        pi.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    int p;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        f[p].push_back(i);
    }
    cin >> b;
    dfs(1, 0);
    cout << resp << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}