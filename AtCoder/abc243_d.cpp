#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    ll N, X; cin >> N >> X;
    string moves; cin >> moves;
    string compressed;
    for (int i = 0; i < N; i++) {
        compressed.push_back(moves[i]);
        if (compressed.size() > 1) {
            char last = compressed.back();
            char second_last = compressed[compressed.size() - 2];
            while(compressed.size() > 1 and (second_last == 'L' or second_last == 'R') and last == 'U') {
                compressed.pop_back();
                compressed.pop_back();
                last = compressed.back();
                second_last = compressed[compressed.size() - 2];
            }
        }
    }
    for (char move: compressed) {
        if (move == 'U') X /= 2;
        if (move == 'L') X *= 2;
        if (move == 'R') X = X * 2 + 1;
    }
    cout << X << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}