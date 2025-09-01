#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int P; cin >> P;
    if (P >= 18) {
        int T; cin >> T;
        if (P + T >= 60) {
            cout << "Passed";
        } else {
            cout << "Failed";
        }
    } else {
        cout << "Failed";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}