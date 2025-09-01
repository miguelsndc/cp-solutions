#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    string s; cin >> s;
    bool ok = true;
    for (auto [c, l]: a) {
        if (s.size() + l > 100) {
            ok = false; break;
        }
        for (int i = 0; i < l; i++) s += c;
    }

    if (ok) {
        cout << s << '\n';
    } else {
        cout << "Too Long";
    }
}