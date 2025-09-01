#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int N, D; cin >> N >> D;
    vector<int> limite(N);
    vector<pair<int,int>> aux;
    for (int &i: limite) cin >> i;
    for (int i = 0; i < N; i++) {
        if (limite[i] > 0) {
            aux.push_back({limite[i], i + 1});
        }
    }
    if (aux.empty() or (aux.size() == 1 and aux.back().first < D)) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    int i = 0, ok = true;
    while(ans.size() < D) {
        for (int j = 0; j < aux[i].first; j++) {
            if (ans.size() < D) {
                ans.push_back(aux[i].second);
            } else {
                break;
            }
        }
        if (ans.size() == D) break;
        i = (i + 1) % (aux.size());
    }
    for (int x: ans) cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}