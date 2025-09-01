#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int q; cin >> q;
    vector<set<int>> tree(q + 1);
    vector<int> type2, morto(q + 1, true);
    morto[1] = false;
    int cnt = 2;
    while(q--) {
        int tipo, no; cin >> tipo >> no;
        if (tipo == 1) {
            morto[cnt] = false;
            tree[no].insert(cnt++);
        } else {
            type2.push_back(no);
        }
    }

    vector<int> pre;
    auto dfs = [&] (auto &&dfs2, int u, int p = 0) -> void {
        pre.push_back(u);
        for (int x: tree[u]) {
            if (x != p) {
                dfs2(dfs2, x, u);
            }
        }
    };
    dfs(dfs, 1, 0);
    int cur = 0;
    for (int morreu: type2) {
        morto[morreu] = true;
        while(morto[pre[cur]]) {
            cur++;
        }
        cout << pre[cur] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}