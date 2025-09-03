#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<int> a(n), freq(105);
    bool ok = false;
    for (int &i: a) {
        cin >> i;
        freq[i]++;
        ok |= freq[i] >= 2;
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}