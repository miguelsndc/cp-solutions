#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define int ll
void solve() {
    vector<int> freq_a(26), freq_b(26);
    freq_a[0]++;
    freq_b[0]++;
    int q;
    cin >> q;

    struct Query {
        int op, k;
        vector<int> freq;
        Query() {
            freq.assign(26, 0);
        }
        void inc(int x, int y) {
            freq[x] += y;
        }
    };

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int op, k;
        string s;
        cin >> op;
        cin >> s;
        cin >> k;
        Query qu;
        for (char c : s) {
            qu.inc((int)(c - 'a'), k);
        }
        qu.op = op;
        qu.k = k;
        queries[i] = qu;
    }

    ll sz_a = 1, sz_b = 1;
    for (auto qu : queries) {
        if (qu.op == 1) {
            for (int i = 0; i < 26; i++) {
                freq_a[i] += qu.freq[i];
                sz_a += qu.freq[i];
            }

        } else {
            for (int i = 0; i < 26; i++) {
                freq_b[i] += qu.freq[i];
                sz_b += qu.freq[i];
            }
        }

        int result = 0, psa = 0, psb = 0;
        for (int i = 0; i < 26; i++) {
            psa += freq_a[i];
            psb += freq_b[i];
            if (freq_a[i] == freq_b[i]) {
                continue;
            } else if (freq_a[i] > freq_b[i] and sz_b == psb) {
                result = 2;
                break;
            } else if (freq_a[i] > freq_b[i] and sz_b > psb) {
                result = 1;
                break;
            }  else if (freq_b[i] > freq_a[i] and sz_a == psa) {
                result = 1;
                break;
            } else if (freq_b[i] > freq_a[i] and sz_a > psa) {
                result = 2;
                break;
            } else {
                assert(false);
            }
        }

        if (result == 0) {
            cout << "Tie\n";
        } else if (result == 1) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}