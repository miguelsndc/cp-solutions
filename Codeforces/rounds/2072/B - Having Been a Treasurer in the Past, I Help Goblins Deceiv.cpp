#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll qtdtraco = 0, qtdseta = 0;
    for (char c: s) {
        if (c == '_') qtdtraco++;
        else if (c == '-') qtdseta++;
    }
    if (qtdtraco < 1 || qtdseta < 2 || n < 3) {
        cout << 0 << '\n';
        return;
    }
    cout << ((qtdseta + 1) / 2) * qtdtraco * (qtdseta / 2) << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}