#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    string p, s; cin >> p >> s;
    p += "0";
    s += "0";
    int n = p.size(), m = s.size();
    vector<string> bp, bs;

    string block = ""; char cur = p[0];
    for (int i = 0; i < n; i++) {
        if (p[i] == cur) {
            block += p[i];
        } else {
            bp.push_back(block);
            cur = p[i];
            block = "";
            block += p[i];
        }
    }

    block = ""; cur = s[0];
    for (int i = 0; i < m; i++) {
        if (s[i] == cur) {
            block += s[i];
        } else {
            bs.push_back(block);
            cur = s[i];
            block = "";
            block += s[i];
        }
    }

    if (bp.size() != bs.size()) {
        cout << "NO\n";
        return;
    }

    vector<int> cnt(256);
    for (int i = 0; i < bp.size(); i++) {
        if (bp[i].size() > bs[i].size() || bs[i].size() > 2 * bp[i].size()) {
            cout << "NO\n";
            return;
        }

        cnt['L'] = 0;
        cnt['R'] = 0;

        for (int j = 0; j < bp[i].size(); j++) {
            cnt[bp[i][j]]++;
        }

        for (int j = 0; j < bs[i].size(); j++) {
            cnt[bs[i][j]]++;
        }

        if (cnt['L'] > 0 and cnt['R'] > 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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