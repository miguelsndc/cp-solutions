#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int diff = 0;
    int l = 0, r = n - 1;
    while(l < r) {
        if (s[l++] != s[r--]) diff++;
    }
    cout << (diff <= 1 ? "YES\n" : "NO\n");
}