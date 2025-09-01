#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

const int maxn = 1e6 + 10;
vector<int> is_prime(maxn, 1), big(maxn, 1);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < maxn; i++) {
        if (is_prime[i]) {
            big[i] = i;
            for (int j = 2 * i; j < maxn; j += i) {
                big[j] = i;
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    if (s.size() == 1) {
        cout << "YES\n";
        return;
    }

    map<int, int> freq;

    for (int x : a) {
        while (x > 1) {
            int fac = big[x];
            x /= fac;
            if (fac > 1) {
                freq[fac]++;
            }
        }
    }

    bool can = true;
    for (auto [x, cnt] : freq) {
        if ((cnt % n) != 0) {
            can = false;
            break;
        }
    }

    if (can) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    sieve();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}