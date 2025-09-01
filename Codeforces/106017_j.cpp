#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes "Nooo, la polizzia"
#define no "Sargento Camelas, Gracias!"
void solve() {
    string s;
    cin >> s;
    vector<string> a(5);
    for (int i = 0; i < 5; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool ok = false;
    do {
        string f;
        for (auto &x: a) f += x;
        if (s.contains(f)) ok = true;
    } while (next_permutation(a.begin(), a.end()) and !ok);

    if (ok) {
        cout << yes;
    } else {
        cout << no;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}