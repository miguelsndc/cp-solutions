#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;
namespace rg = std::ranges;

void solve() {
    int n, x;
    cin >> n;
    cout << "digit" << endl;
    cin >> x;
    cout << "digit" << endl;
    cin >> x;
    for (int i = 8; i >= 1; i /= 2) {
        cout << "add " << -i << endl;
        cin >> x;
    }
    cout << "mul " << n << endl;
    cin >> x;
    cout << "!" << endl;
    cin >> x;
    assert(x == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}