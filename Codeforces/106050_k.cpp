#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
const int MOD1 = 188'888'881;
const int MOD2 = 1e9 + 7;
const int base = 137;

const int MAXN = 25;

ll pow1[MAXN];
ll pow2[MAXN];

// O(n) - Chamar antes
void calc_pow() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = (pow1[i - 1] * base) % MOD1,
        pow2[i] = (pow2[i - 1] * base) % MOD2;
}

struct Hashing {
    vector<pair<ll, ll>> pref;
    // O(1)
    Hashing() {}
    Hashing(string &s) {
        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
                     pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }

    // O(1)
    ll operator()(int a, int b) {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return (h1 << 32) | h2;
    }
};
void solve() {
    calc_pow();
    int N, L, K;
    cin >> N >> L >> K;
    /*
        K <= L <= 20
        210 substrings
        passa por todas substrings s |s| >= k
        bfs nas substrings
        hash se tle ?
    */

    vector<string> A(N);
    for (string &s : A) cin >> s;
    map<ll, vector<int>> mp;
    vector<vector<ll>> hashes(N);
    for (int i = 0; i < N; i++) {
        Hashing h(A[i]);
        int M = A[i].size();
        for (int j = 0; j + K - 1 < M; j++) {
            ll hsh = h(j, j + K - 1);
            mp[hsh].push_back(i);
            hashes[i].push_back(hsh);
        }
    }

    const int inf = 1e9 + 1;
    vector<int> dist(N, inf);
    unordered_set<ll> used;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (ll h : hashes[u]) {
            if (used.count(h)) continue;
            used.insert(h);
            for (int x : mp[h]) {
                if (x != u and chmin(dist[x], dist[u] + 1)) {
                    q.push(x);
                }
            }
        }
    }
    if (N == 1) {
        cout << 0 << '\n';
    } else {
        cout << (dist[N - 1] == inf ? -1 : dist[N - 1] - 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}