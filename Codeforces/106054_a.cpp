#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    string S; cin >> S;
    string target = "TAP";
    int i = 0;
    for (char c : S) {
        if (i < 3 and c == target[i]) {
            i++;
        }
    }

    if (i == 3) {
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