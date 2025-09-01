#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5, alpha = 26;

vector<int> pos[alpha][alpha];
int pref[alpha][maxn];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(pref, 0, sizeof pref);

    for (int i = 0; i < n; i++) {
        for (int c = 0; c < alpha; c++) {
            pref[c][i + 1] = pref[c][i];
        }
        pref[s[i] - 'a'][i + 1]++;
    }

    for (int i = 0; i < n - 1; i++) {
        int a = s[i] - 'a';
        int b = s[i + 1] - 'a';
        if (a != b) {
            pos[a][b].push_back(i);
        }
    }

    int q;
    cin >> q;
    int freq[alpha];
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        memset(freq, 0, sizeof freq);
        for (int c = 0; c < alpha; c++) {
            freq[c] = pref[c][r + 1] - pref[c][l];
        }

        bool can = false;
        for (int a = 0; a < alpha and !can; a++) {
            for (int b = 0; b < alpha and !can; b++) {
                if (a != b and freq[a] > freq[b]) {
                    if (pos[a][b].size()) {
                        auto it = lower_bound(all(pos[a][b]), l);
                        if (it != pos[a][b].end() and *it <= r - 1) {
                            can = true;
                        }
                    }
                }
            }
        }
        cout << (can ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}