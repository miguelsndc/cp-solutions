#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    ll x = 0;
    ll attacks = 0;

    while (i <= j) {
        if (i < j) {
            ll v = min(a[j] - x, a[i]);
            x += v;
            attacks += v;
            a[i] -= v;
            if (x >= a[j]) {
                attacks++;
                x = 0;
                a[j] = 0;
                j--;
            }
            if (a[i] == 0) i++;
        } else {
            if (x >= a[j] or a[j] == 1) {
                attacks++;
                break;
            }
            ll need = (a[i] - x + 1) / 2;
            x += need;
            a[i] -= need;
            attacks += need;
            if (a[i] > 0) {
                attacks++;
                x = 0;
            }
            break;
        }
    }

    cout << attacks << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}
