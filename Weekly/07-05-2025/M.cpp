#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int test = min(10, k);
        int mx = 0;
        for (int i = 0; i <= k; i++) {
            int op;
            if ((n - i) % 3 == 0) {
                mx = max(mx, ((n - i) / 3) + i);
                op = (n / 3) + i;
            } else if ((n - i) % 2 == 0) {
                mx = max(mx, ((n - i) / 2) + i);
                op = (n / 2) + i;
            } else
                mx = max(mx, n);
            if (mx == n) break;
        }
        cout << mx << "\n";
    }
}