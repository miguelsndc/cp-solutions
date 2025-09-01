#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 3e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - begin(b));

    if (n == 1 || b.size() == 1) {
        cout << 1 << '\n';
        return;
    }

    int sz = 1;
    for (int i = 0;;) {
        int r1 = -1, r2 = -1;
        if (i + 1 < n and a[i] >= a[i + 1]) {
            int j = i;
            while (j + 1 < n and a[j] >= a[j + 1]) j++;
            r1 = j;
        }
        if (i == n - 1) break;

        if (i + 1 < n and a[i] <= a[i + 1]) {
            int j = i;
            while (j + 1 < n and a[j] <= a[j + 1]) j++;
            r2 = j;
        }

        int k = max(r1, r2);
        if (k - i > 0) sz++;
        i = k;
        if (i == n - 1) break;
    }
    cout << sz << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}