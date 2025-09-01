#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    string s; cin >> s;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        ll k; cin >> k; --k;
        ll b = k / s.size();
        ll p = k % s.size();
        if (__builtin_parityll(b)) {
            if ('a' <= s[p] && s[p] <= 'z') {
                cout << char((s[p] - 'a') + 'A');
            } else {
                cout << char((s[p] - 'A') + 'a');
            }
        } else {
            cout << s[p];
        }
        cout << " ";
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}