#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    --pb, --ps;
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) cin >> p[i], --p[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    auto get_score = [&](int pos) {
        vector<int> vis(n), x;
        while (!vis[pos]) {
            if (!vis[pos]) {
                vis[pos] = true;
                x.push_back(a[pos]);
                pos = p[pos];
            }
        }
        vector<int> psmax(x.size());
        psmax[0] = x[0];
        for (int i = 1; i < x.size(); i++) {
            psmax[i] = max(psmax[i - 1], x[i]);
        }
        ll score = 0, target = psmax[min(k - 1, (int)x.size() - 1)];
        ll mxscore = 0;
        int cnt = 0;
        for (int i = 0; i < min(k - 1, (int)x.size()); i++) {
            mxscore = max(mxscore, score + 1ll*(k - cnt) * x[i]);
            score += x[i];
            cnt++;
            if (x[i] == target) {
                break;
            }
        }
        score += (k - cnt) * target;
        return max(mxscore, score);
    };

    ll b = get_score(pb);
    ll s = get_score(ps);

    if (b > s) {
        cout << "Bodya\n";
    } else if (b == s) {
        cout << "Draw\n";
    } else {
        cout << "Sasha\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}