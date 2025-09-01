#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        string s; cin >> s;
        sort(s.rbegin(), s.rend());
        cout << s << '\n';
    }
}