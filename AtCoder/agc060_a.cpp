#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int mod = 998244353;
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    auto ok = [&] (int i, int v) {
        if (S[i] == '?') return true;
        else return (S[i] - 'a') == v;
    };
    vector ways(26, vector<ll>(26));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != j and ok(0, i) and ok(1, j)) {
                ways[i][j] = 1;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        vector next(26, vector<ll>(26));
        for (int x = 0; x < 26; x++) {
            for (int y = 0; y < 26; y++) {
                for (int z = 0; z < 26; z++) {
                    if (x != z and y != z and ok(i, z)) {
                        (next[y][z] += ways[x][y]) %= mod;
                    }
                }
            }
        }
        swap(ways, next);
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) 
            (ans += ways[i][j]) %= mod;

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}