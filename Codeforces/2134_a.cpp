#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    if (N & 1) {
        if ((A % 2 == 1 and B % 2 == 1) or (A % 2 == 0 and B % 2 == 1 and B >= A)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if ((A % 2 == 0 and B % 2 == 0) or (A % 2 == 1 and B % 2 == 0 and B >= A)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}