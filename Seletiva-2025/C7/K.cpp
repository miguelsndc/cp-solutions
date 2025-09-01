#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    vector<string> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    // check rows, columns, main diag, second diag
    map<char, bool> mp;
    if (v[0][0] == v[0][1] && v[0][1] == v[0][2]) mp[v[0][0]] = true;
    if (v[1][0] == v[1][1] && v[1][1] == v[1][2]) mp[v[1][0]] = true;
    if (v[2][0] == v[2][1] && v[2][1] == v[2][2]) mp[v[2][0]] = true;

    if (v[0][0] == v[1][1] && v[1][1] == v[2][2]) mp [v[0][0]] = true;

    if (v[0][0] == v[1][0] && v[1][0] == v[2][0]) mp[v[0][0]] = true;
    if (v[0][1] == v[1][1] && v[1][1] == v[2][1]) mp[v[0][1]] = true;
    if (v[0][2] == v[1][2] && v[1][2] == v[2][2]) mp[v[0][2]] = true;

    if (v[0][2] == v[1][1] && v[1][1] == v[2][0]) mp[v[0][2]] = true;

    for (const auto &[p, r]: mp) {
        if (r && p != '.') {
            cout << p << '\n';
            return;
        }
    }
    cout << "DRAW\n";
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