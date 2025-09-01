#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    sort(A.begin(), A.end());
    vector<int> B;
    B = A;
    B.resize(unique(B.begin(), B.end()) - B.begin());
    if (B.size() == 1) {
        int x = 1e9 - 1;
        cout << 1 << ' ' << x;
        return;
    }
    vector<int> diff = {0};
    for (int i = 1; i < N; i++) {
        diff.push_back(A[i] - A[i - 1]);
    }
    int g = 0;
    for (int x: diff) {
        g = __gcd(x, g);
    }
    vector<int> d;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            if (i != 1) {
                d.push_back(i);
            }
            if (g / i != i) d.push_back(g / i);
        }
    }

    cout << 1 << ' ' << d.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}