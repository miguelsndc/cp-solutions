#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

#define all(x) begin((x)), end((x))

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> seq(n), freq(3, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') seq[i] = 0;
        if (s[i] == 'I') seq[i] = 1;
        if (s[i] == 'T') seq[i] = 2;
        freq[seq[i]]++;
    }
    if (count(all(freq), 0) > 1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ops;
    while(freq[1] != freq[2] || freq[0] != freq[1]) {
        vector<int> ord = {0, 1, 2};
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (freq[ord[i]] > freq[ord[j]]) {
                    swap(ord[i], ord[j]);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            int nxt = ord[i], pos = -1;
            for (int j = 0; j + 1 < seq.size(); j++) {
                if (seq[j] != seq[j + 1] and seq[j] != nxt and seq[j + 1] != nxt) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) continue;
            seq.insert(seq.begin() + pos + 1, nxt);
            freq[nxt]++;
            ops.push_back(pos + 1);
            break;
        }
    }
    cout << ops.size() << "\n";
    for (int x: ops) cout << x << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}