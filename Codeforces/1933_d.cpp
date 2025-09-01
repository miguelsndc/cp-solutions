#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    /*
        se possivel colocar em ordem crescente pro mod n fazer nada
        sorta
        se tiver duplicatas
        1 2 2 3 4 6
        se freq[1] > 1 ent n tem como, em algum momento vai ter x mod 1 = 0
        se freq[gcd(a)] > 1 n tem como
    */

    map<int, int> freq;
    int g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
        freq[a[i]]++;
    }
    if (freq[g] > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}