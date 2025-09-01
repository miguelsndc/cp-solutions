#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

void solve() {
    ll n, k;
    cin >> n >> k;

    auto binary_print = [&](ll x) {
        string s;
        for (int i = 0; i <= 40; i++) {
            if (x & (1LL << i)) {
                s += '1';
            } else {
                s += '0';
            }
        }

        cout << s << "\n\n";
    };

    binary_print(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}