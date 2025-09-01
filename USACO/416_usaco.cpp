#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {

            cout << "at cell: " << r << ' ' << c << '\n';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((abs(r - i) + abs(c - j)) <= k) {
                        a[i][j] = 1;
                    }
                    cout << a[i][j];
                }
                cout << '\n';
            }
            cout << '\n';

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = 0;
                }
            }
        }
    }
}
