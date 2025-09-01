#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    string S; cin >> S;
    for (int i = 0; i < A; i++) S.erase(S.begin());
    for (int i = 0; i < B; i++) S.pop_back();
    cout << S << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}