#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    string s;
    cin >> s;
    for (char &c : s) {
        if (c == 'F') c = 'E';
    }

    int n = s.size();
    int steps = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'H') {
            steps += n - i;
        }
    }

    if (steps & 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}