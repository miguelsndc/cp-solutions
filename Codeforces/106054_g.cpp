#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int A, B, C; cin >> A >> B >> C;
    if ((B - A) % C == 0) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}