#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int N; cin >> N;
    int A, B; cin >> A >> B;
    vector<int> dislike(A + 1);
    for (int i = 0; i < B; i++) {
        int x; cin >> x;
        dislike[x] = true;
    }
    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        int ausente = 0;
        vector<int> etapa(M), mark(M);
        for (int &i: etapa) {
            cin >> i;
            if (dislike[i]) ausente++;
        }
        if (ausente > ((M / 3))) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}