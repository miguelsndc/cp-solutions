#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m; cin >> n >> m;
    set<string> old;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        old.insert(x);
        mp[x] = i;
    }
    vector<string> s;
    string cur;
    while((cin >> cur)) {
        if (cur.back() == '.') cur.pop_back();
        if (!old.count(cur)) continue;
        if (s.size() > 0 and s.back() == cur) continue;
        s.push_back(cur);
    }
    int total = s.size();
    vector<int> ans(n, total);
    for (int i = 0; i < s.size(); i++) {
        ans[mp[s[i]]]--;
        if (i - 1 >= 0 and i + 1 < s.size() and s[i - 1] == s[i + 1]) {
            ans[mp[s[i]]]--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}