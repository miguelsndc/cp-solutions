#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    string res = string(g[0].size(), '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] != '.') res[j] = g[i][j];
        }
    }
    cout << res;
}