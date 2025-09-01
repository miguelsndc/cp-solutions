#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    map<int, int> m;
    int ans = 0;
    for (int i = 0, j = 0; i < N; i++) {
        // ultima ocorrencia de cada cara
        // maior valor da ultima ocorrencia
        j = max(m[A[i]], j);
        // tamanho
        ans = max(ans, i - j + 1);
        // atualiza
        m[A[i]] = i + 1;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}