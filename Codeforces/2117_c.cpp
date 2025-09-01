#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n], pref[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> seen;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (seen.count(a[i]) == 0);
        seen.insert(a[i]);
    }

    set<int> s;
    int ans = 0;
    for (int i = n - 1; i >= 0;) {
        int j = i, in = false;
        while (j >= 0 and s.size() != pref[i + 1]) {
            s.insert(a[j--]);
            in = true;
        }
        if (in) {
            i = j;
            ans++;
            s.clear();
        } else {
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}