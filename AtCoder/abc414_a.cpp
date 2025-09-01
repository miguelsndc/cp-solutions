#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l, r; cin >> n >> l >> r;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x <= l and y >= r) cnt++;
    }
    cout << cnt << '\n';
}