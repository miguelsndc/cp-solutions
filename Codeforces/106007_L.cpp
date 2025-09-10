#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    bool equal = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 ) equal &= (a[i] == a[i - 1]); 
    }
    int mx = *max_element(a.begin(), a.end());
    int freq[31]={0};

    for (int i = 0; i < n; i++) {
        for (int b = 0; b < 31; b++) {
            if (a[i] & (1 << b)) {
                freq[b]++;
            }
        }
    }

    int sem = (n + m - 1) / m;
    int com = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) continue;
        com++;
        i += m - 1;
    }
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;

        if (equal) {
            cout << 0 << '\n';
            goto done;
        }

        for (int i = 0; i < 31; i++) {
            if (!(x & (1 << i)) and freq[i] > 0 and freq[i] < n) {
                cout << -1 << '\n';
                goto done;
            }
        }

        if ((x | mx) == mx) {
            cout << com << '\n';
        } else {
            cout << sem << '\n';
        }

        done:
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}