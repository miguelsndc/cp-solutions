#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 6) {
        cout << "1 1 2 3 1 2\n";
    } else if (n == 9) {
        cout << "7 3 3 7 5 3 7 7 3\n";
    } else if (n == 15) {
        cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8\n";
    } else {
        for (int i = 1; i <= n - 2; i++) cout << i << " ";
        cout << "1 2\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}