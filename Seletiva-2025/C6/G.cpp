#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') u++;
    }

    if (u % 2 != 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while(tt--) {
         solve();
    }
}